#pragma once
#//include "Header.h"
#include "Board.h"
#include "Creature.h"
#include <iostream>
#include <sstream>
#include "Monster.h"
#include "Readfile.h"

class Monster;

class Character :public Creature {
private:
	char name;
	std::vector <CharacterCardData> holdCard;
	std::vector <std::string> command;
	std::vector <int> point;
	static char Halpha;
public:
	Character(void);//OK
	void initial(const CharacterData& chaDataTemp);//OK
	void die(void);
	const char& getName(void);//OK
	void visible(void) const;//OK

	static void initialHalpha(void);
	void getHoldCard(void);//OK

	void draw(int first, int last);//抽牌//OK
	void turn(Monster *enemy);//出牌//OK
	int attack(int atkTemp, int rangeTemp, Monster *enemy);
	void spawn(void);//OK
	void move(int step);//OK
	void shuffle();//洗牌//OK``
	void rest();//OK
	void check(); // check hp and shield;
	friend class Monster;
};
