#include "HtmlRepo.h"
#include <vector>
#include <fstream>
#include <Windows.h>
using namespace std;

HtmlRepository::HtmlRepository()
{
	this->filepath = "C:\\Users\\PC\\source\\repos\\Lab8\\watchman_turrets.html";
}

bool HtmlRepository::isTurret(const Turret& turret)
{
	vector<Turret> allTurrets = this->ReadFromFile();
	auto it = find(allTurrets.begin(), allTurrets.end(), turret);
	if (it != allTurrets.end())
		return true;
	return false;
}



void HtmlRepository::AddTurret(const Turret& turret)
{
	vector<Turret> allTurrets = this->ReadFromFile();
	allTurrets.push_back(turret);
	this->writeToFile(allTurrets);
}

void HtmlRepository::DeleteTurret(const Turret& turret)
{
}

void HtmlRepository::UpdateTurret(const Turret& old_turret)
{
}

std::vector<Turret> HtmlRepository::GetTurrets()
{
	vector<Turret> allTurrets = this->ReadFromFile();
	return allTurrets;
}

void HtmlRepository::open()
{
	string program_path = "\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\" " + this->filepath;
	system(program_path.c_str());
}

Turret HtmlRepository::next()
{
	return Turret();
}

Turret HtmlRepository::findTurret(Turret& turret)
{
	return Turret();
}


std::vector<Turret> HtmlRepository::ReadFromFile()
{
	string line;
	Turret turret;
	vector<string> TurretString;
	vector<Turret> AllTurrets;

	ifstream fin;
	fin.open(this->filepath);
	string location{ " " }, size{ " " }, vision{ " " };
	int auraLevel{ 0 }, separateParts{ 0 };

	int unuseful_lines = 5;
	while (getline(fin, line))
	{
		if (line.substr(0, 7) == "\t\t\t<td>")
		{
			if (unuseful_lines)
				unuseful_lines--;
			else
			{
				int startposition = line.find(">") + 1;
				int endposition = line.rfind("<") - startposition;
				location = line.substr(startposition, endposition);
				getline(fin, line);
				endposition = line.rfind("<") - startposition;
				size = line.substr(startposition, endposition);
				getline(fin, line);
				endposition = line.rfind("<") - startposition;
				auraLevel = stoi(line.substr(startposition, endposition));
				getline(fin, line);
				endposition = line.rfind("<") - startposition;
				separateParts = stoi(line.substr(startposition, endposition));
				getline(fin, line);
				endposition = line.rfind("<") - startposition;
				vision = line.substr(startposition, endposition);
				turret = Turret(location,size,auraLevel,separateParts,vision);
				AllTurrets.push_back(turret);
			}
		}
	}
	fin.close();
	return AllTurrets;
}

void HtmlRepository::writeToFile(std::vector<Turret> turrets)
{
	string filecontent;
	filecontent += "<!DOCTYPE html>\n";
	filecontent += "<html>\n";
	filecontent += "\t<head>\n";
	filecontent += "\t\t<title>Watchman list</title>\n";
	filecontent += "\t</head>\n";
	filecontent += "\t<body>\n";
	filecontent += "\t\t<table border=\"1\">\n";
	filecontent += "\t\t<tr>\n";
	filecontent += "\t\t\t<td>Location</td>\n";
	filecontent += "\t\t\t<td>Size</td>\n";
	filecontent += "\t\t\t<td>Aura Level</td>\n";
	filecontent += "\t\t\t<td>Separate Parts</td>\n";
	filecontent += "\t\t\t<td>Vision</td>\n";
	filecontent += "\t\t</tr>\n";
	for (auto turret : turrets)
	{
		filecontent += "\t\t<tr>\n";
		filecontent += "\t\t\t<td>" + turret.getLocation() + "</td>\n";
		filecontent += "\t\t\t<td>" + turret.getSize() + "</td>\n";
		filecontent += "\t\t\t<td>" + to_string(turret.getAuraLevel()) + "</td>\n";
		filecontent += "\t\t\t<td>" + to_string(turret.getSeparateParts()) + "</td>\n";
		filecontent += "\t\t\t<td>" + turret.getVision() + "</td>\n";
		filecontent += "\t\t</tr>\n";
	}
	filecontent += "\t\t</table>\n";
	filecontent += "\t</body>\n";
	filecontent += "</html>";

	ofstream fout(this->filepath);
	fout << filecontent;
	fout.close();
}
