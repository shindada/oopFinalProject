#pragma once
#//include "Header.h"
#include "Readfile.h"
#include "Func.h"
#include "Creature.h"
#include <iostream>
#include <sstream>
class Character :public Creature {
private:
	char name;
	std::vector <CharacterCardData> holdCard;
	static char Halpa;
public:
	Character(void);
	void initial(const CharacterData& chaDataTemp);
	const char& getName(void);
	void getHoldCard(void);
	void draw();//抽牌
	int attack(int atkTemp);
	int attack(int atkTemp, int rangeTemp);
	void spawn(void);
	void move(int step);
	void shuffle();//洗牌
	void rest();
};
