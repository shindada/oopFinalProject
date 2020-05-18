#pragma once
//Name: 徐瑞憫
//Date:　May, 9, 2020
//Last Update: May, 9, 2020
//Project: final project(Gloom Heaven)
//Problem statement: Creature Class
#include "Readfile.h"
class Creature {
public:
	int totalHp;
	int hp;
	int shield;
	Position position;
public:
	//Creature(const int& hpTemp);
	//void move(std::string commandTemp);
	void initialHp(const int& hpTemp);
	void setPosition(const Position& posTemp);
	void heal(const int& bloodTemp);
	void shieldPlus(const int& shieldTemp);
	const int& getTotalHp() const;
	const int& getHp() const;
	const int& getShield() const;
	void shieldToZero();
	const Position& getPosition() const;
};
