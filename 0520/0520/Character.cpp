#include "Character.h"

char Character::Halpha = 'A';
Character::Character(void) {//OK
	name = Halpha;
	Halpha++;
	holdCard.clear();
	this->alive = true;
}
void Character::initial(const CharacterData& chaDataTemp) {//OK
	Creature::initialHp(chaDataTemp.hp);
	Creature::shieldToZero();
	Creature::dexterityToZero();
	holdCard.clear();
	command.clear();
	point.clear();

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
void Character::die(void) {

}

const char& Character::getName(void) {//OK
	return this->name;
}
void Character::visible(void) const{//OK
	Position temp = Creature::getPosition();
	if ((temp.row > 0) && (temp.col > 0)) {
		if ((board[temp.row][temp.col] == '1') && (this->alive)) {
			board[temp.row][temp.col] = name;
		}
	}
}
void Character::initialHalpha(void) {
	Halpha = 'A';
}
void Character::getHoldCard(void) {//OK
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
void Character::draw(int first, int last) {//抽牌//OK
	int cardRemain = 0;
	int cardDiscard = 0;
	for (int i = 0; i < holdCard.size(); i++) {
		if (holdCard[i].cardStatus == 0) {
			cardRemain++;
		}
		else if (holdCard[i].cardStatus == 1) {
			cardDiscard++;
		}
	}
	if (cardRemain < 2) {
		if (cardDiscard < 2) {
			this->alive = false;
		}
		else {
			std::cout << "card are not enough, need to rest!" << std::endl;
		}
	}
	else {
		nowTurn = false;
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
			if ((first < holdCard.size()) && (last < holdCard.size())) {
				if ((holdCard[first].cardStatus != 0)
					|| (holdCard[last].cardStatus != 0)
					|| (first == last)) {
					flag = false;
				}
			}
			else {
				flag = false;
			}
		} while (flag == false);
		while ((holdCard[first].cardStatus != 0) || (holdCard[last].cardStatus != 0)
			|| (first == last)) {
			std::cout << "card discard, please enter other numero:";
			std::cin >> first >> last;
		}
		dexterity[0] = holdCard[first].dexterity;
		dexterity[1] = holdCard[last].dexterity;
		int partInt, otherInt;
		char partChar;
		std::stringstream chooseCard[2];
		std::cin >> partInt >> partChar;
		if (partInt == first) {
			otherInt = last;
		}
		else {
			otherInt = first;
		}
		if (partChar == 'd') {
			chooseCard[0] << holdCard[partInt].lowHalf;
			chooseCard[1] << holdCard[otherInt].topHalf;
		}
		else {
			chooseCard[0] << holdCard[partInt].topHalf;
			chooseCard[1] << holdCard[otherInt].lowHalf;
		}
		holdCard[partInt].cardStatus = 1;
		holdCard[otherInt].cardStatus = 1;
		std::string cTemp;
		int pTemp;
		for (int i = 0; i < 2; i++) {
			while (chooseCard[i] >> cTemp >> pTemp) {
				command.push_back(cTemp);
				point.push_back(pTemp);
			}
		}
	}
}
void Character::turn(Monster *enemy) {//出牌
	std::cout << name << "'s turn: ";
	for (int i = 0; i < 2; i++) {
		int count = 0;
		while (count < command.size()) {
			if (command[count] == "attack") {
				if (count + 1 < command.size()) {
					if (command[count + 1] == "range") {
						attack(point[count], point[count + 1], enemy);
						count++;
					}
					else {
						attack(point[count], 1, enemy);
					}
				}
				else {
					attack(point[count], 1, enemy);
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
	}
	command.clear();
	point.clear();
}

int Character::attack(int atkTemp, int rangeTemp, Monster *enemy) {
	// std::cout << "attack, range: " << atkTemp << ' ' << rangeTemp << std::endl;
	char target;
	bool isFind = false; 
	do {
		cin >> target;
		if (isupper(target) == true) { // can't attack its friend
			cout << "error target!!!" << endl;
			continue;
		}
		for (int i = 0; i < monsterNum; i++) {
			if (target == enemy[i].name) {
				isFind = true;
				if (inRange() && canSee()) {//紅字
					int atkReal = atkTemp - enemy[i].shield;
					if (atkReal < 0) atkReal = 0;
					enemy[i].hp = enemy[i].hp - atkTemp + enemy[i].shield;
				}
				else {
					isFind = false; // can't see or reach the target
			        break;
				}
			}
		}
		if (isFind == false) cout << "error target!!!" << endl; // invalid monster name
	} while(isFind == false);

	return atkTemp;
	return 0;
}
void Character::spawn(void) {//OK
	std::cout << "please enter steps: ";
	string steps; cin >> steps;
	Position *movement = new Position[steps.length()]; // space for movements according to keys
	for (int i = 0; i < steps.length(); i++) {
		switch (steps[i]) { // translates keys to movements
		case 'W': case 'w':
			movement[i].row = -1;
			movement[i].col = 0;
			break;
		case 'S': case 's':
			movement[i].row = 1;
			movement[i].col = 0;
			break;
		case 'A': case 'a':
			movement[i].row = 0;
			movement[i].col = -1;
			break;
		case 'D': case 'd':
			movement[i].row = 0;
			movement[i].col = 1;
			break;
		case 'E': case 'e':
			movement[i].row = 0;
			movement[i].col = 0;
			break;
		}
	}
	setPostion(map.spawn[0]);
	for (int i = 0; i < steps.length(); i++) {
		Position temp = getPosition();
		temp.row = temp.row + movement[i].row;
		temp.col = temp.col + movement[i].col;
		if ((board[temp.row][temp.col] == '4') || (board[temp.row][temp.col] == '5')) {
			setPostion(temp);
		}
		else continue;
	}
	Position now = getPosition();
	if (board[now.row][now.col] == '4') { 
		board[now.row][now.col] = getName();
		for (int i = 1; i < map.spawn.size();i++) {
			if ((map.spawn[i].row == now.row) && (map.spawn[i].col == now.col)) {
				map.spawn.erase(map.spawn.begin() + i);
			}
		}
	}
	else { // move '*' to the next position
		board[now.row][now.col] = getName();
		map.spawn.erase(map.spawn.begin());
		board[map.spawn[0].row][map.spawn[0].col] = '5';
	}
}
void Character::move(int step) {//OK
	std::cout << "move: " << step << std::endl;
	std::string commandTemp;
	bool isValid = true;
	std::cout << "please enter steps: ";
	do {
		isValid = true;
		std::cin >> commandTemp;
		if (commandTemp.length() <= step) {
			std::vector <Position> movement;
			movement.push_back(Creature::getPosition());
			//Position* movement = new Position[commandTemp.length()]; // allocate space for movements depend on keys
			for (int i = 0; i < commandTemp.length(); i++) {
				Position temp = movement[movement.size() - 1];
				if ((board[temp.row][temp.col] == '0') || (board[temp.row][temp.col] == '2') || (islower(board[temp.row][temp.col]))) {
					isValid = false;
					break;
				}
				else {
					switch (commandTemp[i]) { // translates keys to movements
					case 'W': case 'w':
						temp.row -= 1;
						break;
					case 'S': case 's':
						temp.row += 1;
						break;
					case 'A': case 'a':
						temp.col -= 1;
						break;
					case 'D': case 'd':
						temp.col += 1;
						break;
					case 'E': case 'e':
						break;
					default:
						isValid = false;
						break;
					}
					if (isValid) {
						movement.push_back(temp);
					}
				}
			}
			Position temp = movement[movement.size() - 1];
			if ((board[temp.row][temp.col] == '2') || (islower(board[temp.row][temp.col]))) {
				isValid = false;
				movement.pop_back();
			}
			temp = movement[movement.size() - 1];
			while ((board[temp.row][temp.col] != '1') && (board[temp.row][temp.col] != '3') && (movement.size() > 1)) {
				isValid = false;
				movement.pop_back();
				temp = movement[movement.size() - 1];
			}
			temp = movement[movement.size() - 1];
			//check
			/*for (int i = 0; i < movement.size(); i++) {
				std::cout << movement[i].row << ' ' << movement[i].col << " - ";
			}*/
			//check end
			if (isValid) {
				Position restore = getPosition(); // restore 1 to original position
					board[restore.row][restore.col] = map.initBoard[restore.row][restore.col];
					setPostion(temp); // update character position
					board[temp.row][temp.col] = getName(); // update board with character's new position
			}
			else {
				cout << "error move!!! Please input again: ";
				isValid = false;
			}
			movement.clear();
		}
		else {
			cout << "error move!!! Please input again: ";
			isValid = false;
		}
	} while (isValid == false);
}
void Character::shuffle() {//洗牌//OK
	std::cout << "shuffle" << std::endl;
	int flagCanShuffle = 0;
	for (int i = 0; i < holdCard.size(); i++) {
		if (holdCard[i].cardStatus == 1) {//dicard zone is not empty
			flagCanShuffle++;
		}
	}
	if (flagCanShuffle >= 2) {//dicard zone is not empty
		nowTurn = false;
		std::cout << "remove card: ";
		int choose;
		int countTemp = 0;
		bool flag;
		do {
			flag = true;
			if (countTemp > 0) {
				std::cout << "not in dicard zone, please enter other numero:";
			}
			else {
				countTemp = 1;
			}
			std::cin >> choose;
			if (choose < holdCard.size()) {
				if (holdCard[choose].cardStatus != 1) {
					flag = false;
				}
			}
			else {
				flag = false;
			}
		} while (flag == false);

		holdCard[choose].cardStatus = 2;//put one card in destroy
		for (int i = 0; i < holdCard.size(); i++) {
			if (holdCard[i].cardStatus == 1) {//other cards return in hand
				holdCard[i].cardStatus = 0;
			}
		}
		this->dexterity[0] = this->dexterity[1] = 99;
	}
	else {//dicard zone is empty
		std::cout << "no card in dicard zone, can't shuffle" << std::endl;
	}
}
void Character::rest() {//OK
	Creature::heal(2);
	shuffle();
}

void Character::check() {
	// A-hp: 12, shield: 1
	cout << name << "-hp: " << hp << ", shield: " << shield << endl;
}