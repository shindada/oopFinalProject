#pragma once
#include "Creature.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
//#include "Creature.h"
#include "Func.h"
class Monster :public Creature {
private:
	int chooseCard;
	static char alpha;
	char name;
	int status[3];//hp atk range
	int chooseNow;
	std::vector <MonsterCardData> holdCard;
public:
	Monster(const std::vector <MonsterData>& mD,int people);
	void draw();//抽牌
	void turn();
	int attack(int atkTemp);
	int attack(int atkTemp, int rangeTemp);
	void move(std::string commandTemp);
	void shuffle();//洗牌
};