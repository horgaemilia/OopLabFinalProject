#pragma once
#include "Repository.h"
class HtmlRepository : public Repository
{
private:
	std::string filepath;
public:
	HtmlRepository();
	bool isTurret(const Turret& turret);
	void AddTurret(const Turret& turret);
	void DeleteTurret(const Turret& turret);
	void UpdateTurret(const Turret& old_turret);
	std::vector<Turret> GetTurrets();
	void open();
	Turret next();
	Turret findTurret(Turret& turret);
private:
	std::vector<Turret> ReadFromFile();
	void writeToFile(std::vector<Turret> turrets);
};
