#pragma once
#//include "Header.h"
#include "Board.h"
#include "Creature.h"
#include <iostream>
#include <sstream>
class Character :public Creature {
private:
	char name;
	std::vector <CharacterCardData> holdCard;
	static char Halpha;
public:
	Character(void);//OK
	void initial(const CharacterData& chaDataTemp);//OK
	const char& getName(void);//OK
	void getHoldCard(void);//OK
	void draw();//抽牌//OK
	int attack(int atkTemp);
	int attack(int atkTemp, int rangeTemp);
	void spawn(void);//OK
	void move(int step);//OK
	void shuffle();//洗牌//OK``
	void rest();//OK
};
