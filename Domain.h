#pragma once
#include <string>
class Turret
{
private:
	std::string location;
	std::string size;
	int auraLevel;
	int separateParts;
	std::string vision;
public:
	//domain default constructor
	Turret();
	/*
	constructor for turret
	input : string location, size, vision
			integer auraLevel,separateParts
	output: -
	*/
	Turret(const std::string& location, const std::string& size, const int auraLevel, const int separateParts, const std::string& vision);
	/*
	returns the location of a turret
	input : -
	output: returns a string representing the location
	*/
	std::string getLocation() const { return location; }
	/*
	returns the size of a turret
	input : -
	output: returns a string representing the size
	*/
	std::string getSize() const { return size; }
	/*
	returns the AuraLevel of a turret
	input : -
	output: returns an integer representing the AuraLevel
	*/
	int getAuraLevel() const { return auraLevel; }
	/*
	returns the separateParts of a turret
	input : -
	output: returns an integer representing the separateParts
	*/
	int getSeparateParts() const { return separateParts; }
	/*
	returns the vision of a turret
	input : -
	output: returns a string representing the vision
	*/
	std::string getVision() const { return vision; }
	/*
	sets the location of a turret
	input: a string representing the location we want
	output: -
	*/
	void setLocation(std::string& location) { this->location = location; }
	/*
	sets the size of a turret
	input: a string representing the size we want
	output: -
	*/
	void setSize(std::string& size) { this->size = size; }
	/*
	sets the auraLevel of a turret
	input: an integer representing the auraLevel we want
	output: -
	*/
	void setAuraLevel(int auraLevel) { this->auraLevel = auraLevel; }
	/*
	sets the SeparateParts of a turret
	input: an integer representing the separateParts we want
	output: -
	*/
	void setSeparateParts(int separateParts) { this->separateParts = separateParts; }
	/*
	sets the vision of a turret
	input: a string representing the vision we want
	output: -
	*/
	void setVision(std::string& vision) { this->vision = vision; }
	/*
	creates a string so we can print the turret
	input: a turret
	output: returns a string which contains all the characteristics of the turret
	*/
	std::string toString();
	/*
	we overload the equality operator between two turrets
	input: a turret
	output: true if the turrets have the same location
			false otherwise
	*/
	bool operator==(const Turret& turret);
};
