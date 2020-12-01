#pragma once

#include <string>

class Printable
{
public:
	virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
	std::string m_Name;

public:
	Player(const std::string& name);

	std::string GetName() override;
	std::string GetClassName() override { return "Player"; }
};
