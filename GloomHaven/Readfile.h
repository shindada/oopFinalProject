#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void preInput();

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
	int elite[3]; //�׭^hp atk range
	vector <struct MonsterCardData> card;
};

struct CharacterCardData {
	int numero;//�s��
	int dexterity;//�ӱ�
	string topHalf;//�W�b
	string lowHalf;//�U�b
	int cardStatus;//�d�����A0:��W/1:��d��/2:�u�����
};

struct MonsterCardData {
	int numero;//�s��
	int dexterity;//�ӱ�
	string skill;//�ޯ�
	int cardStatus;//0:��W, 1:��d��
	bool canShuffle;//�~�P�Achar�אּbool�O�]���Q���s�����L�Ȥ���e���P�_
};

static CharacterData* CharacterList;
static MonsterData* MonsterList;
static int MODE;