#include "FileRepo.h"
#include <sstream>
#include <fstream>
#include "Exceptions.h"
using namespace std;
FileRepository::FileRepository()
{
    this->filename =  "C:\\Users\\PC\\source\\repos\\Lab8\\turret list.txt";
    this->current_position = 0;
}

bool FileRepository::isTurret(const Turret& turret)
{
    vector<Turret> AllTurrets;
    AllTurrets = this->ReadFromFile();
    vector<Turret>::iterator it = find(AllTurrets.begin(), AllTurrets.end(), turret);
    if (it != AllTurrets.end())
        return true;
    return false;
}

Turret FileRepository::findTurret(Turret& turret)
{
    vector<Turret> AllTurrets = ReadFromFile();
    vector<Turret>::iterator it = find(AllTurrets.begin(), AllTurrets.end(), turret);
    if (it != AllTurrets.end())
        return *it;
    throw RepoException("the turret does not exist");
}
void FileRepository::AddTurret(const Turret& turret)
{
    vector<Turret> AllTurrets;
    AllTurrets = this->ReadFromFile();
    AllTurrets.push_back(turret);
    this->writeToFile(AllTurrets);
}

void FileRepository::DeleteTurret(const Turret& turret)
{
    vector<Turret> AllTurrets;
    AllTurrets = this->ReadFromFile();
    vector<Turret>::iterator it = find(AllTurrets.begin(), AllTurrets.end(), turret);
    if (it != AllTurrets.end())
    {
        AllTurrets.erase(it);
    }
    this->writeToFile(AllTurrets);
}


void FileRepository::UpdateTurret(const Turret& old_turret)
{
    vector<Turret> AllTurrets;
    AllTurrets = this->ReadFromFile();
    vector<Turret>::iterator it = find(AllTurrets.begin(), AllTurrets.end(), old_turret);
    if (it != AllTurrets.end())
    {
        *it = old_turret;
    }
    this->writeToFile(AllTurrets);
}

vector<Turret> FileRepository::GetTurrets()
{
    vector<Turret> AllTurrets = ReadFromFile();
    return AllTurrets;
}

Turret FileRepository::next()
{
    vector<Turret> AllTurrets = ReadFromFile();
    if (this->current_position == AllTurrets.size())
        this->current_position = 0;
    Turret turret = AllTurrets[this->current_position];
    this->current_position++;
    return turret;
}

void FileRepository::open()
{
}

std::vector<std::string> FileRepository::SplitLine(std::string line, char delimiter)
{
    vector<string> result;
    stringstream string_stream(line);
    string substring;
    while (getline(string_stream, substring, delimiter))
        result.push_back(substring);
    return result;
}

std::vector<Turret> FileRepository::ReadFromFile()
{
    string line;
    Turret turret;
    vector<string> TurretString;
    vector<Turret> AllTurrets;

    ifstream fin;
    fin.open(this->filename);
    string location{ " " }, size{ " " }, vision{ " " };
    int auraLevel{ 0 }, separateParts{ 0 };

    while (getline(fin, line))
    {
        TurretString = SplitLine(line, ',');
        if (TurretString.size() == 5)
        {
            location = TurretString[0];
            size = TurretString[1];
            auraLevel = stoi(TurretString[2]);
            separateParts = stoi(TurretString[3]);
            vision = TurretString[4];
            turret = Turret(location, size, auraLevel, separateParts, vision);
            AllTurrets.push_back(turret);
        }
    }
    fin.close();
    return AllTurrets;
}

void FileRepository::writeToFile(std::vector<Turret> turrets)
{
    ofstream fout(this->filename);
    for (auto turret : turrets)
    {
        fout << turret.getLocation() << "," << turret.getSize() << "," << turret.getAuraLevel() << "," << turret.getSeparateParts() << "," << turret.getVision() << "\n";
    }
}
