#pragma once
#include "Exceptions.h"
#include "Repository.h"
#include "FileRepo.h"
#include "CSVRepo.h"
#include "HtmlRepo.h"
#include "InMemoryRepo.h"
#include "MemoryRepoWatchman.h"
class Service {
private:
	Repository* repository;
	Repository* mylist;
public:
	Service(Repository* repository, Repository* mylist) : repository{ repository }, mylist{ mylist } {}
	~Service();
	/*
	calls the next function from the repository
	input: -
	output: the turret on which we are currently
	*/
	Turret next();
	/*
	calls the function GetTurrets() from repository
	input: -
	output: a vector containing all the turrets from our main list
	*/
	std::vector<Turret> getTurretsFromRepo();
	/*
	calls the function GetWatchmanTurrets() from the repository
	input: -
	output: a vector containing all the watchman turrets
	*/
	std::vector<Turret> getWatchmanTurretsFromRepo();
	/*
	receives the location of a turret from the main list
	finds the whole turret that has that location
	adds that turret to the watchmanlist
	throws an error if the turret does not exist
	input: a string representing the location
	output: -
	*/
	int addTurretWatchmanService(std::string& location);
	/*
	receives the characteristics of a turret
	creates a turret with those specifications
	if the turret already exists throws an error
	calls the function AddTurret from the repository
	input: a string for location
		   a string for size
		   an integer for the auraLevel
		   an integer for the Separate parts
		   a string for the vision
	output: -
	*/
	int addTurretService(std::string& location, std::string& size, int auraLevel, int separateParts, std::string& vision);
	/*
	receives the location of a turret
	creates a turret with that location
	if the turret does not exist throws an error
	calls the function DeleteTurret from the repository
	input: a string for location
	output: -
	*/
	int deleteTurretService(std::string& location);
	/*
	receives the characteristics of a new turret
	creates a turret with those specifications
	if the turret with that location does not exist throws an error
	calls the function UpdateTurret from the repository
	input: a string for location
		   a string for size
		   an integer for the auraLevel
		   an integer for the Separate parts
		   a string for the vision
	output: -
	*/
	int UpdateTurretService(std::string& location, std::string& size, int auraLevel, int separateParts, std::string& vision);
	std::vector<Turret> Filter(std::string& size, std::string& separate_parts);
	void open();
};