#pragma once

#include <vector>
#include "Database.h"

class Organism
{
	// Organism status
	enum STATUS { ALIVE, DEAD, HUNGRY, FULL, SLEEPY, FEARED, HIBERNATION, HIDING };
	enum ACTION { SLEEPING, EATING, MOVING, HUNTING, MATING, STOPED };
	enum SEX { NONE, MALE, FEMALE };

	// Position data struct
	typedef struct Position
	{
		float fLatitude , fLongitude , fDepth ; 
	} Position;

private:
	int m_Age;					   
	SEX m_Sex;
	
	STATUS m_Status;
	ACTION m_Action;
	
	Position m_Position;
	std::vector<Organism> m_Prey;  // Prey List which organism can eat.
	
	Database m_Data;
	
	
public:
	
	// Setup Func
	void SetAge(int age) { m_Age = age; }
	void SetSex(SEX sex) { m_Sex = sex; }
	void SetStatus(STATUS status) { m_Status = status; }
	void SetAction(ACTION action) { m_Action = action; }
	void SetPosition(Position pos) { m_Position = pos; }
	void SetDatabase(const Database& data) { m_Data = data; }
	void SetPreyList(const std::vector<Organism>& preylist) { /* ±¸»ó Áß */  }
	void AddPrey(const Organism& prey) { m_Prey.push_back(prey); }
	
	// Get Func
	int GetAge() const { return m_Age; }
	int GetSex() const { return m_Sex; }
	STATUS GetStatus() const { return m_Status; }
	ACTION GetAction() const { return m_Action; }
	Position GetPosition() const { return m_Position; }
	std::vector<Organism> GetPreyList() const { return m_Prey; }
	Database& GetDataBase() { return m_Data; }
};