#pragma once
#include "Repository.h"
#include <vector>
class FileRepository : public Repository
{
private:
	std::string filename;
	int current_position;
public:
	FileRepository();
	bool isTurret(const Turret& turret);
	Turret findTurret(Turret& turret);
	void AddTurret(const Turret& turret);
	void DeleteTurret(const Turret& turret);
	void UpdateTurret(const Turret& old_turret);
	std::vector<Turret> GetTurrets();
	Turret next();
	void open();
private:
	std::vector<std::string> SplitLine(std::string line, char delimiter);
	std::vector<Turret> ReadFromFile();
	void writeToFile(std::vector<Turret> turrets);
};