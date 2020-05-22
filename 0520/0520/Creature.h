#pragma once
//Name: 徐瑞憫
//Date:　May, 9, 2020
//Last Update: May, 9, 2020
//Project: final project(Gloom Heaven)
//Problem statement: Creature Class
#include "Readfile.h"
class Creature {
private:
	int totalHp;
	int hp;
	int shield;
	Position position;
public:
	bool nowTurn;
	bool alive;
	int dexterity[2];
	//void move(std::string commandTemp);
	void initialHp(const int& hpTemp);
	void setPostion(const Position& posTemp);
	void dexterityToZero(void);
	void shieldToZero(void);
	const int& getTotalHp(void) const;
	const int& getHp(void) const;
	const int& getShield(void) const;
	const Position& getPosition(void) const;
	void heal(const int& bloodTemp);
	void shieldPlus(const int& shieldTemp);
};
