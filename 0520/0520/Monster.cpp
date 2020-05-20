#include "Monster.h"
char Monster::alpha = 'a';
Monster::Monster(const std::vector <MonsterData>& mD, int people) {
	//holdCard.resize(mD.size());
	chooseCard = 0;
}
void Monster::draw() {//抽牌
	if (1) {/*MODE == 1*/
		std::srand(time(NULL));
		chooseNow = rand() % holdCard.size();
	}
	else {
		chooseNow = chooseCard;
	}
}
void Monster::turn() {
	std::cout << name << "'s turn: ";
	std::vector <std::string> command;
	std::vector <int> point;
	std::string cTemp;
	int pTemp;
	/*while (holdCard[chooseNow].skill >> cTemp) {
		if (cTemp == "move") {
			command.push_back(cTemp);
			point.push_back(0);
			holdCard[chooseNow].skill >> cTemp;
			command.push_back(cTemp);
			point.push_back(0);
		}
		else {
			command.push_back(cTemp);
			point.push_back(pTemp);
		}
	}
	int count = 0;
	while (count < command.size()) {
		if (command[count] == "attack") {
			if (count + 1 < command.size()) {
				if (command[count + 1] == "range") {
					attack(point[count], point[count + 1]);
					count++;
				}
				else {
					attack(point[count]);
				}
			}
			else {
				attack(point[count]);
			}
		}
		else if (command[count] == "shield") {
			Creature::shieldPlus(point[count]);
		}
		else if (command[count] == "heal") {
			Creature::heal(point[count]);
		}
		else if (command[count] == "move") {
			move(command[count + 1]);
			count++;
		}
	}
	count++;
	shuffle();*/
}
int Monster::attack(int atkTemp) {
	return atkTemp;
}
int Monster::attack(int atkTemp, int rangeTemp) {
	return atkTemp;
}
void Monster::move(std::string commandTemp) {
	//Position *dir = new Position[commandTemp.length()];//代表第n步後的位置
	//int *canMove = new int[commandTemp.length()];//第n步是不是valid
	//int maxIndex = commandTemp.length() - 1;
	//for (int i = 0; i < commandTemp.length(); i++) {
	//	dir[i] = direction(commandTemp[i]);
	//	if (i == 0) {
	//		dir[i].col += position.col;
	//		dir[i].row += position.row;
	//	}
	//	else {
	//		dir[i].col += dir[i - 1].col;
	//		dir[i].row += dir[i - 1].row;
	//	}
	//	canMove[i] = isvalid(dir[i].row,dir[i].col);
	//	if (canMove[i] == 2) {//maxIndex=第一個2 - 1
	//		maxIndex = i - 1;
	//	}
	//}
	//while ((maxIndex > 0) && (canMove[maxIndex] != 0)) {//最後一格要是0//非0->maxIndex--;
	//	maxIndex--;
	//}
	//if (maxIndex != 0) {
	//	position = dir[maxIndex];
	//}
	//delete[] dir;
	//delete[] canMove;
}
void Monster::shuffle() {//洗牌
	if (holdCard[chooseNow].canShuffle) {
		for (int i = 0; i < holdCard.size(); i++) {
			if (holdCard[i].cardStatus == 1) {
				holdCard[i].cardStatus = 0;
			}
		}
	}
}