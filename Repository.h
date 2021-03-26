#pragma once
#include "Domain.h"
#include <vector>
#include <iostream>

class Repository
{
public:
	/*
	checks if the turret exists in our list
	input: a turret
	output: true if the turret exists
			false otherwise
	*/
	virtual bool isTurret(const Turret& turret) = 0;
	/*
	adds a turret to our main list
	input: a turret
	output: -
	*/
	virtual void AddTurret(const Turret& turret) = 0;
	/*
	adds a turret to the watchman list
	input: a turret
	output: -
	*/
	virtual void DeleteTurret(const Turret& turret) = 0;
	/*
	updates the fields of a turret that has the same location as the one we are passing
	input: the new turret
	output: -
	*/
	virtual void UpdateTurret(const Turret& old_turret) = 0;
	/*
	returns all turrets from our main list
	input: -
	output: a vector containing all our turrets
	*/
	virtual std::vector<Turret> GetTurrets() = 0;
	/*
	returns all turrets from our watchman list
	input: -
	output: a vector containing all our turrets
	*/
	virtual void open() = 0;
	virtual Turret next() = 0;
	virtual Turret findTurret(Turret& turret) = 0;
protected:
	virtual void writeToFile(std::vector<Turret> Turrets) = 0;
	virtual std::vector<Turret> ReadFromFile() = 0;
};

