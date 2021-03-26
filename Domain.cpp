#include "Domain.h"
#include <string>

Turret::Turret() : location(""), size(""), auraLevel(0), separateParts(0), vision("") {}

using namespace std;
Turret::Turret(const std::string& location, const std::string& size, const int auraLevel, const int separateParts, const std::string& vision)
{
	this->location = location;
	this->size = size;
	this->auraLevel = auraLevel;
	this->separateParts = separateParts;
	this->vision = vision;
}

std::string Turret::toString()
{
	return this->getLocation() + "," + this->getSize() + "," + std::to_string(this->getAuraLevel()) + "," + std::to_string(this->getSeparateParts()) + "," + this->getVision()+"\n";
}

bool Turret::operator==(const Turret& turret)
{
	if (this->location == turret.getLocation())
		return true;
	return false;
}

