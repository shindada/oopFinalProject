#include "Character.h"
char Character::Halpa = 'A';
Character::Character(void) {
	name = Halpa;
	Halpa++;
	holdCard.clear();
}
void Character::initial(const CharacterData& chaDataTemp) {
	Creature::initialHp(chaDataTemp.hp);
	Creature::shieldToZero();
	holdCard.clear();
	for (int i = 0; i < chaDataTemp.totalcard; i++) {
		holdCard.push_back(chaDataTemp.card[i]);
	}
	for (int i = 0; i < chaDataTemp.cardNum; i++) {
		int cardNumero;
		std::cin >> cardNumero;
		holdCard[cardNumero].cardStatus = 0;//在手上
	}
	//check
	/*std::cout << name << ' ' << Creature::getHp() << std::endl;
	for (int i = 0; i < chaDataTemp.totalcard; i++) {
		std::cout << holdCard[i].numero << ' ' <<
			holdCard[i].dexterity << ' ' <<
			holdCard[i].topHalf << ' ' <<
			holdCard[i].lowHalf << ' ' <<
			holdCard[i].cardStatus << endl;
	}*/
	//check end
}
const char& Character::getName(void) {
	return this->name;
}
void Character::getHoldCard(void) {
	std::vector <int> hand;
	std::vector <int> discard;
	hand.clear();
	discard.clear();
	for (int i = 0; i < holdCard.size(); i++) {
		if (holdCard[i].cardStatus == 0) {//in hand
			hand.push_back(holdCard[i].numero);
		}
		else if (holdCard[i].cardStatus == 1) {//dicard zone
			discard.push_back(holdCard[i].numero);
		}
	}
	std::cout << "hand: ";
	for (int i = 0; i < hand.size() - 1; i++) {
		std::cout << hand[i] << ", ";
	}
	std::cout << hand[hand.size() - 1] << "; discard: ";
	if (discard.size() > 0) {
		for (int i = 0; i < discard.size() - 1; i++) {
			std::cout << discard[i] << ", ";
		}
		std::cout << discard[discard.size() - 1];
	}
	else {
		std::cout << "none";
	}
	std::cout << std::endl;
	hand.clear();
	discard.clear();
}
void Character::draw() {//抽牌
	std::cout << name << "'s turn: ";
	int chooseCardInt[2];
	int countTemp = 0;
	bool flag;
	do {
		flag = true;
		if (countTemp > 0) {
			std::cout << "card discard, please enter other numero:";
		}
		else {
			countTemp = 1;
		}
		std::cin >> chooseCardInt[0] >> chooseCardInt[1];
		if ((chooseCardInt[0] < holdCard.size()) || (chooseCardInt[0] < holdCard.size())) {
			if ((holdCard[chooseCardInt[0]].cardStatus != 0)
				|| (holdCard[chooseCardInt[1]].cardStatus != 0)
				|| (chooseCardInt[0] == chooseCardInt[1])) {
				flag = false;
			}
		}
		else {
			flag = false;
		}
	} while (flag == false);
	while ((holdCard[chooseCardInt[0]].cardStatus != 0) || (holdCard[chooseCardInt[1]].cardStatus != 0)
		|| (chooseCardInt[0] == chooseCardInt[1])) {
		std::cout << "card discard, please enter other numero:";
		std::cin >> chooseCardInt[0] >> chooseCardInt[1];
	}
	int partInt, otherInt;
	char partChar;
	std::cin >> partInt >> partChar;
	if (partInt == chooseCardInt[0]) {
		otherInt = chooseCardInt[1];
	}
	else {
		otherInt = chooseCardInt[0];
	}
	if (partChar == 'd') {
		int swap = otherInt;
		otherInt = partInt;
		partInt = swap;
	}
	std::stringstream chooseCard[2];
	chooseCard[0] << holdCard[partInt].topHalf;
	chooseCard[1] << holdCard[otherInt].lowHalf;
	holdCard[partInt].cardStatus = 1;
	holdCard[otherInt].cardStatus = 1;
	std::vector <std::string> command;
	std::vector <int> point;
	std::string cTemp;
	int pTemp;
	for (int i = 0; i < 2; i++) {
		while (chooseCard[i] >> cTemp >> pTemp) {
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
			count++;
		}
		command.clear();
		point.clear();
	}
}
int Character::attack(int atkTemp) {
	std::cout << "attack: " << atkTemp << std::endl;
	return atkTemp;
}
int Character::attack(int atkTemp, int rangeTemp) {
	std::cout << "attack, range: " << atkTemp << ' ' << rangeTemp << std::endl;
	return atkTemp;
	return 0;
}
void Character::move(int step) {
	std::cout << "move: " << step << std::endl;
	//	std::string commandTemp;
	//	std::cin >> commandTemp;
	//	Positionition *dir = new Positionition[pace];//代表第n步後的位置
	//	int *canMove = new int[pace];//第n步是不是valid
	//	int maxIndex = pace;
	//	for (int i = 0; i <= pace; i++) {
	//		dir[i] = direction(commandTemp[i]);
	//		if (i == 0) {
	//			dir[i].col += Positionition.col;
	//			dir[i].row += Positionition.row;
	//		}
	//		else {
	//			dir[i].col += dir[i - 1].col;
	//			dir[i].row += dir[i - 1].row;
	//		}
	//		canMove[i] = isvalid(dir[i].row,dir[i].col);
	//		if (canMove[i] == 2) {//maxIndex=第一個2 - 1
	//			maxIndex = i - 1;
	//		}
	//	}
	//	while ((maxIndex > 0) && (canMove[maxIndex] != 0)) {//最後一格要是0//非0->maxIndex--;
	//		maxIndex--;
	//	}
	//	if (maxIndex != 0) {
	//		Positionition = dir[maxIndex];
	//	}
	//	delete[] dir;
	//	delete[] canMove;
}
void Character::shuffle() {//洗牌
	std::cout << "shuffle" << std::endl;
	//	std::cout << "remove card: ";
	//	int choose;
	//	std::cin >> choose;
	//	holdCard[choose].cardStatus == 2;
	//	for (int i = 0; i < holdCard.size(); i++) {
	//		if (holdCard[i].cardStatus == 1) {
	//			holdCard[i].cardStatus = 0;
	//		}
	//	}
}
void Character::rest() {
	Creature::heal(2);
	shuffle();
}