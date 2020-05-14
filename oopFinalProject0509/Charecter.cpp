#include "charecter.h"
char Charecter::Halpa = 'A';
Charecter::Charecter(const std::vector <CharecterData>& cD, std::string nameTemp) {
	name = Halpa;
	Halpa++;
	for (int i = 0; i < cD.size(); i++) {
		if (cD[i].name == nameTemp) {
			//holdCard.resize(cD[i].totalcard);
			//holdCard = cD[i].card;
			totalHp = hp = cD[i].hp;
			def = shield = 0;
			for (int j = 0; j < cD[i].cardNum; j++) {
				int num;
				std::cin >> num;
				holdCard[num].cardStatus = 0;
			}
		}
	}
}
const char& Charecter::getName(void) {
	return this->name;
}
const std::vector <CharecterCardData>& Charecter::getHoldCard(void) {
	std::vector <int> hand;
	std::vector <int> discard;
	for (int i = 0; i < holdCard.size(); i++) {
		if (holdCard[i].cardStatus == 0) {
			hand.push_back(i);
		}
		else if (holdCard[i].cardStatus == 1) {
			discard.push_back(i);
		}
	}
	std::cout << "hand: ";
	for (int i = 0; i < hand.size() - 1; i++) {
		std::cout << hand[i] << ", ";
	}
	std::cout << hand[hand.size() - 1] << "; discard: ";
	for (int i = 0; i < discard.size() - 1; i++) {
		std::cout << discard[i] << ", ";
	}
	std::cout << hand[hand.size() - 1] << std::endl;
	return holdCard;
}
void Charecter::draw() {//抽牌
	std::cout << name << "'s turn: ";
	int chooseCard[2];
	std::cin >> chooseCard[0] >> chooseCard[1];
	int partInt,other;
	char partChar;
	std::cin >> partInt >> partChar;
	if (partInt == chooseCard[0]) {
		other = chooseCard[1];
	}
	else {
		other = chooseCard[0];
	}
	if (partChar == 'd') {
		int swap = other;
		other = partInt;
		partInt = swap;
	}
	std::vector <std::string> command;
	std::vector <int> point;
	std::string cTemp;
	int pTemp;
	while (holdCard[partInt].topHalf >> cTemp >> pTemp) {
		command.push_back(cTemp);
		point.push_back(pTemp);
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
			move(point[count]);
		}
	}
	count++;
	command.clear();
	point.clear();
	while (holdCard[other].lowHalf >> cTemp >> pTemp) {
		command.push_back(cTemp);
		point.push_back(pTemp);
	}
	count = 0;
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
			move(point[count]);
		}
	}
}
int Charecter::attack(int atkTemp) {
	return atkTemp;
}
int Charecter::attack(int atkTemp, int rangeTemp) {//
	return atkTemp;
	return 0;
}
void Charecter::move(int pace) {
	std::string commandTemp;
	std::cin >> commandTemp;
	Pos *dir = new Pos[pace];//代表第n步後的位置
	int *canMove = new int[pace];//第n步是不是valid
	int maxIndex = pace;
	for (int i = 0; i <= pace; i++) {
		dir[i] = direction(commandTemp[i]);
		if (i == 0) {
			dir[i].col += position.col;
			dir[i].row += position.row;
		}
		else {
			dir[i].col += dir[i - 1].col;
			dir[i].row += dir[i - 1].row;
		}
		canMove[i] = isvalid(dir[i].row,dir[i].col);
		if (canMove[i] == 2) {//maxIndex=第一個2 - 1
			maxIndex = i - 1;
		}
	}
	while ((maxIndex > 0) && (canMove[maxIndex] != 0)) {//最後一格要是0//非0->maxIndex--;
		maxIndex--;
	}
	if (maxIndex != 0) {
		position = dir[maxIndex];
	}
	delete[] dir;
	delete[] canMove;
}
void Charecter::shuffle() {//洗牌
	std::cout << "remove card: ";
	int choose;
	std::cin >> choose;
	holdCard[choose].cardStatus == 2;
	for (int i = 0; i < holdCard.size(); i++) {
		if (holdCard[i].cardStatus == 1) {
			holdCard[i].cardStatus = 0;
		}
	}
}
void Charecter::rest() {
	Creature::heal(2);
	shuffle();
}