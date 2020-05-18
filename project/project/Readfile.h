#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void preInput();
struct Position{
	int col;
	int row;
};

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
static CharacterData* CharacterList;
static MonsterData* MonsterList;
static int MODE;
static int characterType;//角色種類
static int characterNum;//遊戲內實際角色數量