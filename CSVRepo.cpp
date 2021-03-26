#include "CSVRepo.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "Domain.h"
using namespace std;

CsvRepository::CsvRepository() 
{
    this->filepath = "C:\\Users\\PC\\source\\repos\\Lab8\\watchman_list_turrets.csv";
}

bool CsvRepository::isTurret(const Turret& turret)
{
    vector<Turret> allTurrets = this->ReadFromFile();
	auto it = find(allTurrets.begin(), allTurrets.end(), turret);
	if (it != allTurrets.end())
		return true;
	return false;
}


void CsvRepository::AddTurret(const Turret& turret)
{
    vector<Turret> allTurrets = this->ReadFromFile();
    allTurrets.push_back(turret);
    this->writeToFile(allTurrets);
}

void CsvRepository::DeleteTurret(const Turret& turret)
{
}

void CsvRepository::UpdateTurret(const Turret& old_turret)
{
}

std::vector<Turret> CsvRepository::GetTurrets()
{
    vector<Turret> allTurrets = this->ReadFromFile();
    return allTurrets;
}

void CsvRepository::open()
{
    string program_path = "\"C:\\Program Files(x86)\\Microsoft Office\\root\\Office16\\EXCEL.EXE\" " + this->filepath;
    system(program_path.c_str());
}

Turret CsvRepository::next()
{
    return Turret();
}

Turret CsvRepository::findTurret(Turret& turret)
{
    return Turret();
}

std::vector<std::string> CsvRepository::SplitLine(std::string line, char delimiter)
{
	vector<string> result;
	stringstream string_stream(line);
	string substring;
	while (getline(string_stream, substring, delimiter))
		result.push_back(substring);
	return result;
}

std::vector<Turret> CsvRepository::ReadFromFile()
{
    string line;
    Turret turret;
    vector<string> TurretString;
    vector<Turret> AllTurrets;

    ifstream fin;
    fin.open(this->filepath);
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

void CsvRepository::writeToFile(std::vector<Turret> turrets)
{
	ofstream fout(this->filepath);
	for (auto turret : turrets)
	{
		fout << turret.getLocation() << "," << turret.getSize() << "," << turret.getAuraLevel() << "," << turret.getSeparateParts() << "," << turret.getVision() << "\n";
	}
}
