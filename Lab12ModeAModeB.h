#pragma once
#include "Service.h"
#include <QtWidgets/QMainWindow>
#include "ui_Lab12ModeAModeB.h"

class Lab12ModeAModeB : public QMainWindow
{
    Q_OBJECT

public:
    Lab12ModeAModeB(Service& service,QWidget *parent = Q_NULLPTR);

private:
    Ui::Lab12ModeAModeBClass ui;
    Service& service;
    void populateList();
    void populateWatchmanList();
    void makeConnections();
    int getSelectedIndex();
	void deleteTurret();
	void addTurret();
	void updateTurret();
	void addTurretWatchmanList();
	void switchMode();
	void open();
	void filter();
	void next();
};
