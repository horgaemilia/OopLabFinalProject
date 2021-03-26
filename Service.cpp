#include "Service.h"

using namespace std;

Service::~Service()
{
	delete mylist;
}

Turret Service::next()
{
	return this->repository->next();
}

std::vector<Turret> Service::getTurretsFromRepo()
{
	return this->repository->GetTurrets();
}

std::vector<Turret> Service::getWatchmanTurretsFromRepo()
{
	return this->mylist->GetTurrets();
}

int Service::addTurretWatchmanService(std::string& location)
{
	Turret turret = Turret(location, "", 0, 0, "");
	Turret full_turret = this->repository->findTurret(turret);
	if (this->mylist->isTurret(full_turret) == true)
		throw RepoException("the turret already exists in mylist\n");
	this->mylist->AddTurret(full_turret);
}

int Service::addTurretService(std::string& location, std::string& size, int auraLevel, int separateParts, std::string& vision)
{
	Turret turret = Turret(location, size, auraLevel, separateParts, vision);
	if (this->repository->isTurret(turret) == true)
		throw RepoException("the turret already exists in the list\n");
	this->repository->AddTurret(turret);
}

int Service::deleteTurretService(std::string& location)
{
	Turret turret = Turret(location, "", 0, 0, "");
	if (this->repository->isTurret(turret) == false)
		throw RepoException("The turret you wish to delete does not exist!\n");
	this->repository->DeleteTurret(turret);
}

int Service::UpdateTurretService(std::string& location, std::string& size, int auraLevel, int separateParts, std::string& vision)
{
	Turret turret = Turret(location, size, auraLevel, separateParts, vision);
	if (this->repository->isTurret(turret) == false)
		throw RepoException("The turret you wish to update does not exist!\n");
	this->repository->UpdateTurret(turret);
}

vector<Turret> Service::Filter(std::string& size, std::string& separate_parts)
{
	vector<Turret> filtered;
	vector<Turret> allTurrets = repository->GetTurrets();
	int separateParts = stoi(separate_parts);
	for (auto turret : allTurrets)
	{
		if (turret.getSize() == size && turret.getSeparateParts() >= separateParts)
			filtered.push_back(turret);
	}
	return filtered;
}

void Service::open()
{
	this->mylist->open();
}
