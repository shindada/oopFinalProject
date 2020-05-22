#pragma once
#include "Creature.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Board.h"
class Monster :public Creature {
private:
	int drawCount;
	char name;
	int chooseCard;
	int gameMode;
	int status[3];//hp atk range
	std::vector <MonsterCardData> holdCard;
	static char Malpha;
public:
	Monster(void);//OK
	void initial(const MonsterData& monstDataTemp, const MonsterPlace& monstPlaceTemp, const int &gameModeTemp);//OK
	const char& getName(void);//OK
	void visible(void);//whether display in board//OK
	void draw();//抽牌//OK
	void turn();//OK
	int attack(int atkTemp);
	int attack(int atkTemp, int rangeTemp);
	void move(std::string commandTemp);//OK
	void shuffle();//洗牌//OK
};