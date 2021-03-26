#include "InMemoryRepo.h"
#include "Exceptions.h"
using namespace std;

InMemoryRepo::InMemoryRepo()
{
	this->current_position = 0;
}

bool InMemoryRepo::isTurret(const Turret& turret)
{
	vector<Turret>::iterator it = find(this->AllTurrets.begin(), this->AllTurrets.end(), turret);
	if (it != AllTurrets.end())
		return true;
	return false;
}

Turret InMemoryRepo::findTurret(Turret& turret)
{
	vector<Turret>::iterator it = find(AllTurrets.begin(), AllTurrets.end(), turret);
	if (it != AllTurrets.end())
		return *it;
	throw RepoException("the turret does not exist");
}

void InMemoryRepo::AddTurret(const Turret& turret)
{
	this->AllTurrets.push_back(turret);
}

void InMemoryRepo::DeleteTurret(const Turret& turret)
{
	vector<Turret>::iterator it = find(this->AllTurrets.begin(), this->AllTurrets.end(), turret);
	if (it != this->AllTurrets.end())
	{
		this->AllTurrets.erase(it);
	}
}

void InMemoryRepo::UpdateTurret(const Turret& old_turret)
{
	vector<Turret>::iterator it = find(this->AllTurrets.begin(), this->AllTurrets.end(), old_turret);
	if (it != this->AllTurrets.end())
	{
		*it = old_turret;
	}
}

std::vector<Turret> InMemoryRepo::GetTurrets()
{
	return this->AllTurrets;
}

Turret InMemoryRepo::next()
{
	if (this->current_position == this->AllTurrets.size())
		this->current_position = 0;
	Turret turret = this->AllTurrets[this->current_position];
	this->current_position++;
	return turret;
}

void InMemoryRepo::open()
{
	return;
}

std::vector<Turret> InMemoryRepo::ReadFromFile()
{
	return std::vector<Turret>();
}

void InMemoryRepo::writeToFile(std::vector<Turret> turrets)
{
	return;
}
