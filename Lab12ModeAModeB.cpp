#include "Lab12ModeAModeB.h"
#include <vector>
#include <qmessagebox.h>
#include <sstream>
using namespace std;
Lab12ModeAModeB::Lab12ModeAModeB(Service& service,QWidget *parent)
    : QMainWindow(parent), service{ service }
{
    ui.setupUi(this);
    this->populateList();
    this->populateWatchmanList();
    this->makeConnections();
    this->ui.SavepushButton->setEnabled(false);
    this->ui.FilterpushButton->setEnabled(false);
    this->ui.OpenpushButton->setEnabled(false);
    this->ui.NextpushButton->setEnabled(false);
}

void Lab12ModeAModeB::populateList()
{
    this->ui.TurretslistWidget->clear();
    vector<Turret> AllTurrets = this->service.getTurretsFromRepo();
    for (auto turret : AllTurrets)
        this->ui.TurretslistWidget->addItem(QString::fromStdString(turret.getLocation() + "-" + turret.getSize() + "-" + to_string(turret.getAuraLevel()) + "-" + to_string(turret.getSeparateParts()) + "-" + turret.getVision()));
}

void Lab12ModeAModeB::populateWatchmanList()
{
    this->ui.WatchmanTurretslistWidget->clear();
    vector<Turret> AllTurrets = this->service.getWatchmanTurretsFromRepo();
    for (auto turret : AllTurrets)
        this->ui.WatchmanTurretslistWidget->addItem(QString::fromStdString(turret.getLocation() + "-" + turret.getSize() + "-" + to_string(turret.getAuraLevel()) + "-" + to_string(turret.getSeparateParts()) + "-" + turret.getVision()));
}

void Lab12ModeAModeB::makeConnections()
{
    QObject::connect(this->ui.TurretslistWidget, &QListWidget::itemSelectionChanged, [this]() {
        int selectedIndex = this->getSelectedIndex();
        if (selectedIndex < 0)
            return;
        Turret turret = this->service.getTurretsFromRepo()[selectedIndex];
        this->ui.VisionlineEdit->setText((QString::fromStdString(turret.getVision())));
        this->ui.SizelineEdit->setText((QString::fromStdString(turret.getSize())));
        this->ui.AuraLevellineEdit->setText((QString::fromStdString(to_string(turret.getAuraLevel()))));
        this->ui.SeparatePartslineEdit->setText((QString::fromStdString(to_string(turret.getSeparateParts()))));
        this->ui.LocationlineEdit->setText((QString::fromStdString(turret.getLocation())));
        }
    );
    QObject::connect(this->ui.AddpushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::addTurret);
    QObject::connect(this->ui.DeletepushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::deleteTurret);
    QObject::connect(this->ui.UpdatepushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::updateTurret);
    QObject::connect(this->ui.OpenpushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::open);
    QObject::connect(this->ui.FilterpushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::filter);
    QObject::connect(this->ui.NextpushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::next);
    QObject::connect(this->ui.ChangeModepushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::switchMode);
    QObject::connect(this->ui.SavepushButton, &QPushButton::clicked, this, &Lab12ModeAModeB::addTurretWatchmanList);
}

int Lab12ModeAModeB::getSelectedIndex()
{
    QModelIndexList selectedIndexes = this->ui.TurretslistWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.size() == 0)
    {
        this->ui.LocationlineEdit->clear();
        this->ui.SizelineEdit->clear();
        this->ui.SeparatePartslineEdit->clear();
        this->ui.VisionlineEdit->clear();
        this->ui.AuraLevellineEdit->clear();
        return -1;
    }
    int SelectedIndex = selectedIndexes.at(0).row();
    return SelectedIndex;
}

void Lab12ModeAModeB::deleteTurret()
{
    string location = this->ui.LocationlineEdit->text().toStdString();
    if (location == "")
    {
        QMessageBox::critical(this, "Error", "The location cannot be empty");
        return;
    }
    try
    {
        this->service.deleteTurretService(location);
        this->populateList();
    }
    catch (RepoException& ex)
    {
        string message = ex.what();
        QMessageBox::critical(this, "Error", QString::fromStdString(message));
    }
}

void Lab12ModeAModeB::addTurret()
{
    string location = this->ui.LocationlineEdit->text().toStdString();
    string size = this->ui.SizelineEdit->text().toStdString();
    string vision = this->ui.VisionlineEdit->text().toStdString();
    string separate_parts = this->ui.SeparatePartslineEdit->text().toStdString();
    string aura_level = this->ui.AuraLevellineEdit->text().toStdString();
    if (location == "" || size == "" || vision=="" || separate_parts == "" || aura_level == "")
    {
        QMessageBox::critical(this, "Error", "The fields cannot be empty");
        return;
    }
    try
    {
        this->service.addTurretService(location,size,stoi(aura_level),stoi(separate_parts),vision);
        this->populateList();
    }
    catch (RepoException& ex)
    {
        string message = ex.what();
        QMessageBox::critical(this, "Error", QString::fromStdString(message));
    }
}

void Lab12ModeAModeB::updateTurret()
{
    string location = this->ui.LocationlineEdit->text().toStdString();
    string size = this->ui.SizelineEdit->text().toStdString();
    string vision = this->ui.VisionlineEdit->text().toStdString();
    string separate_parts = this->ui.SeparatePartslineEdit->text().toStdString();
    string aura_level = this->ui.AuraLevellineEdit->text().toStdString();
    if (location == "" || size == "" || vision == "" || separate_parts == "" || aura_level == "")
    {
        QMessageBox::critical(this, "Error", "The fields cannot be empty");
        return;
    }
    try
    {
        this->service.UpdateTurretService(location, size, stoi(aura_level), stoi(separate_parts), vision);
        this->populateList();
    }
    catch (RepoException& ex)
    {
        string message = ex.what();
        QMessageBox::critical(this, "Error", QString::fromStdString(message));
    }
}

void Lab12ModeAModeB::addTurretWatchmanList()
{
    string location = this->ui.LocationlineEdit->text().toStdString();
    if (location == "")
    {
        QMessageBox::critical(this, "Error", "The location cannot be empty");
        return;
    }
    try
    {
        this->service.addTurretWatchmanService(location);
        this->populateWatchmanList();
    }
    catch (RepoException& ex)
    {
        string message = ex.what();
        QMessageBox::critical(this, "Error", QString::fromStdString(message));
    }
}

void Lab12ModeAModeB::switchMode()
{
    if (this->ui.OpenpushButton->isEnabled() == true)
    {
        this->ui.SavepushButton->setEnabled(false);
        this->ui.FilterpushButton->setEnabled(false);
        this->ui.OpenpushButton->setEnabled(false);
        this->ui.NextpushButton->setEnabled(false);
        this->ui.AddpushButton->setEnabled(true);
        this->ui.DeletepushButton->setEnabled(true);
        this->ui.UpdatepushButton->setEnabled(true);
    }
    else
    {
        this->ui.SavepushButton->setEnabled(true);
        this->ui.FilterpushButton->setEnabled(true);
        this->ui.OpenpushButton->setEnabled(true);
        this->ui.NextpushButton->setEnabled(true);
        this->ui.AddpushButton->setEnabled(false);
        this->ui.DeletepushButton->setEnabled(false);
        this->ui.UpdatepushButton->setEnabled(false);
    }
}

void Lab12ModeAModeB::open()
{
    this->service.open();
}

void Lab12ModeAModeB::filter()
{
    string size = this->ui.SizelineEdit->text().toStdString();
    string separate_parts = this->ui.SeparatePartslineEdit->text().toStdString();
    if (size == "" || separate_parts == "")
    {
        QMessageBox::critical(this, "Error", "The size field or the separate parts field cannot be empty");
        return;
    }
    vector<Turret> turrets = this->service.Filter(size, separate_parts);
    stringstream filteredList;
    for (auto turret : turrets)
        filteredList << turret.toString();
    QMessageBox::information(this, "filtered list", QString::fromStdString(filteredList.str()));
}

void Lab12ModeAModeB::next()
{
    Turret turret = this->service.next();
    this->ui.NextlineEdit->clear();
    this->ui.NextlineEdit->setText(QString::fromStdString(turret.getLocation() + "-" + turret.getSize() + "-" + to_string(turret.getAuraLevel()) + "-" + to_string(turret.getSeparateParts()) + "-" + turret.getVision()));
}
