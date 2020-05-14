#pragma once
//丟在這裡僅因為我測試比較容易//不要照用，記得要改喔
//Name: 徐瑞憫
//Date:　May, 9, 2020
//Last Update: May, 9, 2020
//Project: final project(Gloom Heaven)
//Problem statement: all data structure & variable & function
#include <string>
#include <sstream>
#include <vector>
static int MODE = 1;
struct Pos {
	int col;
	int row;
};
class CharecterCardData {
public://設public僅我因為比較好丟資料//記得要改喔
	int numero;//編號
	int dexterity;//敏捷
	std::stringstream topHalf;//上半
	std::stringstream lowHalf;//下半
	int cardStatus;//0:手上/1:棄卡區/2:真的放棄
	//void init(std::string file);//註解掉僅我因為比較好丟資料//記得要改喔
	void operator=(CharecterCardData& a) {
		numero = a.numero;
		dexterity = a.dexterity;
		std::string b;
		std::getline(a.topHalf, b);
		topHalf.str(b);
		std::getline(a.lowHalf, b);
		lowHalf.str(b);
		cardStatus = a.cardStatus;
	}
};
class MonsterCardData {
public:
	int numero;//編號
	int dexterity;//敏捷
	std::stringstream skill;//技能
	int cardStatus;//0:手上/1:棄卡區
	bool canShuffle;//洗牌
	void operator=(MonsterCardData& a) {
		numero = a.numero;
		dexterity = a.dexterity;
		std::string b;
		std::getline(a.skill, b);
		skill.str(b);
		cardStatus = a.cardStatus;
		canShuffle = a.canShuffle;
	}
};
class CharecterData {
public://設public僅我因為比較好丟資料//記得要改喔
	std::string name;
	int hp;
	int cardNum;
	int totalcard;
	std::vector <struct CharecterCardData> card;
	//void init(std::string file);//註解掉僅我因為比較好丟資料//記得要改喔
};
class MonsterData {
public://設public僅我因為比較好丟資料//記得要改喔
	std::string name;
	int totalcard;
	int normal[3];//hp atk range
	int elite[3];//hp atk range
	std::vector <struct MonsterCardData> card;
	//void init(std::string file);//註解掉僅我因為比較好丟資料//記得要改喔
};
struct MonsterPLace {
	std::string name;
	Pos place;
	int peoNum[3];
};
class Board {
public://設public僅我因為比較好丟資料//記得要改喔
	int map[12][9] = {  0,0,0,0,0,0,0,0,0,
						0,0,0,1,1,1,0,0,0,
						0,0,0,1,1,1,0,0,0,
						0,0,0,1,1,1,0,0,0,
						0,0,0,1,1,1,0,0,0,
						0,0,0,1,1,1,0,0,0,
						0,0,0,0,3,0,0,0,0,
						0,1,1,1,1,1,1,1,0,
						0,1,1,1,1,1,1,1,0,
						0,1,1,1,1,1,1,1,0,
						0,1,1,1,1,1,1,1,0,
						0,0,0,0,0,0,0,0,0,};//方便丟資料
	int room[2] = {0,6};//存room開始的row值//方便丟資料
	int spawn[4][2] = { {3,10},{4,10},{5,10},{4,9} };
	std::vector <MonsterPLace> deploy;
	//void setBoard();//註解掉僅我因為比較好丟資料//記得要改喔
};
static Pos direction(char turn) {
	Pos position;
	position.col = 0;
	position.row = 0;
	switch (turn)
	{
	case 'W':
	case 'w':
		position.row = -1;
		break;
	case 'S':
	case 's':
		position.row = 1;
		break;
	case 'A':
	case 'a':
		position.col = -1;
		break;
	case 'D':
	case 'd':
		position.col = 1;
		break;
	default:
		break;
	}
	return position;
}
