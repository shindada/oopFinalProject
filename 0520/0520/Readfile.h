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
	int** initBoard; // Remi: 我有改名子喔
	//int room[] = { 0,6 };//存room開始的row值//方便丟資料
	int spawn[4][2];
	vector <MonsterPlace> deploy; // monster配置
};
//Board Data End

//read data function
void preInput();
void setUpBoard();
//read data function end

//global variable
extern CharacterData* CharacterList;
extern MonsterData* MonsterList;
extern int characterType;//角色種類
extern int characterNum;//遊戲角色個數
extern int MODE;
//global variable end