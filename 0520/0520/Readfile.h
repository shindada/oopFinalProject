#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//Character &　Monster Card Data
struct CharacterCardData {
	int numero;//編號
	int dexterity;//敏捷
	string topHalf;//上半
	string lowHalf;//下半
	int cardStatus;//卡的狀態0:手上/1:棄卡區/2:真的放棄
};

struct MonsterCardData {
	int numero;//編號
	int dexterity;//敏捷
	string skill;//技能
	int cardStatus;//0:手上, 1:棄卡區
	bool canShuffle;//洗牌，char改為bool是因為想說存為布林值比較容易判斷
};
//Character &　Monster Card Data End

//Character &　Monster Type
struct CharacterData {
	string name;
	int hp;
	int cardNum;
	int totalcard;
	vector <struct CharacterCardData> card;
};

struct MonsterData {
	string name;
	int normal[3]; //hp atk range
	int elite[3]; //菁英hp atk range
	vector <struct MonsterCardData> card;
};
//Character &　Monster Type End

//Board Data
struct Position {
	int col;
	int row;
};

struct MonsterPlace {
	string name;
	Position place;
	int peoNum;
};

struct Board {
	int rowSize;
	int colSize;
	char** initBoard;//0:wall 1:space 2:obstacle 3:door 4:spawn other 5:spawn point
	vector <Position> spawn;
	vector <MonsterPlace> deploy; // monster配置
};
//Board Data End

//read data function
void preInput();
void setUpBoard();
//read data function end

//global variable
extern int characterType;//角色種類
extern int monsterType;
extern int characterNum;//遊戲角色個數
extern int monsterNum;
extern int MODE;
extern CharacterData* CharacterList;
extern MonsterData* MonsterList;
extern Board map;
extern char** board;
//global variable end