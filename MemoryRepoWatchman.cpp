#include "MemoryRepoWatchman.h"
#include <vector>
#include "Exceptions.h"
using namespace std;

MemoryRepoWatchman::MemoryRepoWatchman()
{
}

bool MemoryRepoWatchman::isTurret(const Turret& turret)
{
	vector<Turret>::iterator it = find(this->AllTurrets.begin(), this->AllTurrets.end(), turret);
	if (it != AllTurrets.end())
		return true;
	return false;
}

Turret MemoryRepoWatchman::findTurret(Turret& turret)
{
	vector<Turret>::iterator it = find(AllTurrets.begin(), AllTurrets.end(), turret);
	if (it != AllTurrets.end())
		return *it;
	throw RepoException("the turret does not exist");
}

void MemoryRepoWatchman::AddTurret(const Turret& turret)
{
	this->AllTurrets.push_back(turret);
}

void MemoryRepoWatchman::DeleteTurret(const Turret& turret)
{
	vector<Turret>::iterator it = find(this->AllTurrets.begin(), this->AllTurrets.end(), turret);
	if (it != this->AllTurrets.end())
	{
		this->AllTurrets.erase(it);
	}
}

void MemoryRepoWatchman::UpdateTurret(const Turret& old_turret)
{
}

std::vector<Turret> MemoryRepoWatchman::GetTurrets()
{
	return this->AllTurrets;
}

Turret MemoryRepoWatchman::next()
{
	return Turret();
}

void MemoryRepoWatchman::open()
{
	return;
}

std::vector<Turret> MemoryRepoWatchman::ReadFromFile()
{
	return std::vector<Turret>();
}

void MemoryRepoWatchman::writeToFile(std::vector<Turret> turrets)
{
	return;
}
