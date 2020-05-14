#pragma once
//Name: 徐瑞憫
//Date:　May, 9, 2020
//Last Update: May, 9, 2020
//Project: final project(Gloom Heaven)
//Problem statement: Creature Class
#include "Header.h"
class Creature {
public:
	int totalHp;
	int hp;
	int def;
	int shield;
	Pos position;
public:
	//Creature(const int& hpTemp, const int& defTemp);
	//void move(std::string commandTemp);
	void heal(const int& bloodTemp);
	void shieldPlus(const int& shieldTemp);
	const int& getTotalHp() const;
	const int& getHp() const;
	const int& getDef() const;
	const int& getShield() const;
	void shieldToZero();
	const Pos& getPosition() const;
};
