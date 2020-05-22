#include "Readfile.h"
#include "Character.h"
#include "Monster.h"
#include "Board.h"
int characterNum;//遊戲角色個數
void iniCharacter(Character *roleTemp);
void iniMonster(Monster *enemyTemp, const int& num);
int main() {
	preInput();//read character & monster data
	//access legal command
	std::string command;
	std::cout << "please enter command: ";
	while (std::cin >> command) {
		while ((command != "play") && (command != "exit")) {
			std::cout << "don't have this command, please enter other command: ";
			std::cin >> command;
		}
		//access legal command end

		if (command == "play") {
			std::vector <Position> door;//存room開始的row值//方便丟資料
			//access legal characterNum
			std::cout << "character number:";
			std::cin >> characterNum;
			while ((characterNum < 2) || (characterNum > 4)) {
				std::cout << "out of range! " << "character number:";
				std::cin >> characterNum;
			}
			//access legal characterNum end

			//initiale role
			Character *role = new Character[characterNum];
			iniCharacter(role);//initiale role
			//initiale role end
			

			setUpBoard();//read map

			iniGamerBoard();//initiale gamer board

			findRoom(1, door);//findRoom

			//initiale monster
			//std::cout << map.deploy.size() << ' ' << characterType << std::endl;
			Monster *enemy = new Monster[map.deploy.size()];
			iniMonster(enemy, map.deploy.size());//initiale monster end
			//initiale monster end

			//set role spawn location
			for (int i = 0; i < map.spawn.size(); i++) {
				std::cout << map.spawn[i].row << ' ' << map.spawn[i].col << " - ";
			}
			std::cout << std::endl;
			outputGamerBoard();
			for (int i = 0; i < characterNum; i++) {
				role[i].spawn();
				if (i == characterNum - 1) {
					for (int j = 0; j < map.spawn.size(); j++) {
						board[map.spawn[j].row][map.spawn[j].col] = '1';
					}
				}
				outputGamerBoard();
			}
			//set role spawn location end

			//role draw
			/*for (int i = 0; i < 2; i++) {
				role[0].move(i+1);
				outputGamerBoard();
			}*/
			//role draw end
			//enemy draw
			/*for (int i = 0; i < 10; i++) {
				enemy[4].draw();
				enemy[4].turn();
				outputGamerBoard();
			}*/
			//enemy draw end
			for (int i = 0; i < door.size(); i++) {
				std::cout << door[i].row << ' ' << door[i].col << " - ";
			}
			std::cout << std::endl;
			findRoom(2, door);
			for (int i = 0; i < door.size(); i++) {
				std::cout << door[i].row << ' ' << door[i].col << " - ";
			}
			std::cout << std::endl;
			for (int i = 0; i < characterNum; i++) {
				role[i].visible();
			}
			for (int i = 0; i < map.deploy.size(); i++) {
				enemy[i].visible();
			}
			outputGamerBoard();

			delGamerBoard();//delete gamer board
			delete[] role;
			delete[] enemy;
			door.clear();
			Character::initialHalpha();
			Monster::initialMalpha();
			std::cout << "please enter command: ";
		}
		else {
			exit(0);
		}
	}
}
void iniCharacter(Character *roleTemp) {
	for (int i = 0; i < characterNum; i++) {
		bool flagExist;
		int countTemp = 0;
		CharacterData ListTemp;
		std::string name;
		do {//whether name is in character data
			if (countTemp > 0) {
				std::string temp;
				std::getline(std::cin, temp);
				temp.clear();
				std::cout << "don't in character data, please enter other name: ";
			}
			else {
				countTemp = 1;
			}
			std::cin >> name;
			flagExist = false;
			for (int j = 0; j < characterType; j++) {
				if (name == CharacterList[j].name) {
					ListTemp = CharacterList[j];
					flagExist = true;
				}
			}
		} while (flagExist == false);//name isn't in character data
		roleTemp[i].initial(ListTemp);
	}
	for (int i = 0; i < characterNum; i++) {
		std::cout << roleTemp[i].getName() << ' ';
	}
	std::cout << std::endl;
}
void iniMonster(Monster *enemyTemp, const int& num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < monsterType; j++) {
			if (map.deploy[i].name == MonsterList[j].name) {
				enemyTemp[i].initial(MonsterList[j], map.deploy[i], MODE);
			}
		}
	}
	for (int i = 0; i < num; i++) {
		std::cout << enemyTemp[i].getName() << ' ';
	}
	std::cout << std::endl;
}