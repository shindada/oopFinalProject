#pragma once
#//include "Header.h"
#include "Func.h"
#include "Creature.h"
#include <iostream>
class Charecter :public Creature {
private:
	char name;
	std::vector <CharecterCardData> holdCard;
	static char Halpa;
public:
	Charecter(const std::vector <CharecterData>& cD, std::string nameTemp);
	const char& getName(void);
	const std::vector <CharecterCardData>& getHoldCard(void);
	void draw();//抽牌
	int attack(int atkTemp);
	int attack(int atkTemp, int rangeTemp);
	void move(int pace);
	void shuffle();//洗牌
	void rest();
};
