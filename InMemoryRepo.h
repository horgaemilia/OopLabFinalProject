#pragma once
#include "Repository.h"
#include <vector>
#include "Domain.h"

class InMemoryRepo :
    public Repository
{
private:
	std::vector<Turret> AllTurrets;
	int current_position;
public:
	InMemoryRepo();
	bool isTurret(const Turret& turret);
	Turret findTurret(Turret& turret);
	void AddTurret(const Turret& turret);
	void DeleteTurret(const Turret& turret);
	void UpdateTurret(const Turret& old_turret);
	std::vector<Turret> GetTurrets();
	Turret next();
	void open();
private:
	std::vector<Turret> ReadFromFile();
	void writeToFile(std::vector<Turret> turrets);
};

