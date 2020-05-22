#include "Monster.h"
char Monster::Malpha = 'a';
Monster::Monster(void) {//OK
	name = Malpha;
	Malpha++;
	this->alive = true;
	isVisible = true;
	drawCount = 0;
}
void Monster::initial(const MonsterData& monstDataTemp, const MonsterPlace& monstPlaceTemp, const int &gameModeTemp) {//OK
	isVisible = true;
	Creature::shieldToZero();
	Creature::dexterityToZero();
	chooseCard = 0;
	gameMode = gameModeTemp;
	Position temp;

	//set status & position
	if (monstPlaceTemp.peoNum == 0) {
		Creature::initialHp(0);
		this->alive = false;
		isVisible = false;
		status[0] = status[1] = status[2] = 0;
		temp.col = temp.row = -1;
	}
	else {
		if (monstPlaceTemp.peoNum == 1) {//normal
			Creature::initialHp(monstDataTemp.normal[0]);
			for (int i = 0; i < 3; i++) {
				status[i] = monstDataTemp.normal[i];
			}
		}
		else {//2:elite
			Creature::initialHp(monstDataTemp.elite[0]);
			for (int i = 0; i < 3; i++) {
				status[i] = monstDataTemp.elite[i];
			}
		}
		temp = monstPlaceTemp.place;
		for (int i = 0; i < monstDataTemp.card.size(); i++) {
			holdCard.push_back(monstDataTemp.card[i]);
			holdCard[i].cardStatus = 0;
		}
	}
	Creature::setPostion(temp);
	//set status & position end;

	visible();

	//check
	/*std::cout << name << ' ' << Creature::getHp() << ' '
		<< status[1] << ' ' << status[2] << ' '
		<< Creature::getPosition().row << ' '
		<< Creature::getPosition().col << std::endl;
	for (int i = 0; i < holdCard.size(); i++) {
		std::cout << holdCard[i].numero << ' ' <<
			holdCard[i].dexterity << ' ' <<
			holdCard[i].skill << ' ' <<
			holdCard[i].cardStatus << ' ' << 
			holdCard[i].canShuffle << endl;
	}*/
	//check end
}
const char& Monster::getName(void) {//OK
	return this->name;
}
void Monster::visible(void) {//OK
	Position temp = Creature::getPosition();
	if ((temp.row > 0) && (temp.col > 0)) {
		if ((board[temp.row][temp.col] == '1') && (this->alive)) {
			board[temp.row][temp.col] = name;
		}
		else {
			isVisible = false;
		}
	}
}
void Monster::initialMalpha(void) {
	Malpha = 'a';
}
void Monster::draw() {//抽牌//OK
	if (gameMode == 0) {/*MODE == 0*/
		std::srand(time(NULL) * 379 * drawCount);
		drawCount += 11;
		chooseCard = rand() % holdCard.size();
		while (holdCard[chooseCard].cardStatus != 0) {
			chooseCard = rand() % holdCard.size();
		}
	}
	else {
		while (holdCard[chooseCard].cardStatus != 0) {
			chooseCard++;
			if (chooseCard >= holdCard.size()) {
				chooseCard = 0;
			}
		}
	}
	this->dexterity[0] = holdCard[chooseCard].dexterity;
	this->dexterity[1] = 99;
}
void Monster::turn(Character *role) {//OK
	std::cout << name << "'s turn: " << std::endl;
	std::stringstream chooseCardSStr;
	chooseCardSStr << holdCard[chooseCard].skill;
	std::vector <std::string> command;
	std::vector <int> point;
	std::string cTemp;
	int pTemp;
	holdCard[chooseCard].cardStatus = 1;
	while (chooseCardSStr >> cTemp) {
		if (cTemp == "move") {
			command.push_back(cTemp);
			point.push_back(0);
			chooseCardSStr >> cTemp;
			command.push_back(cTemp);
			point.push_back(0);
		}
		else {
			chooseCardSStr >> pTemp;
			command.push_back(cTemp);
			point.push_back(pTemp);
		}
	}
	//check
	/*for (int i = 0; i < command.size(); i++) {
		std::cout << command[i] << ' ' << point[i] << " - ";
	}
	std::cout << std::endl;*/
	//check end
	int count = 0;
	while (count < command.size()) {
		if (command[count] == "attack") {
			if (count + 1 < command.size()) {
				if (command[count + 1] == "range") {
					attack(point[count], point[count + 1]);
					count++;
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
		count++;
	}
	shuffle();
}
int Monster::attack(int atkTemp) {
	std::cout << "attack: " << atkTemp << std::endl;
	return atkTemp;
}
int Monster::attack(int atkTemp, int rangeTemp) {
	std::cout << "attack, range: " << atkTemp << ' ' << rangeTemp << std::endl;
	return atkTemp;
}
void Monster::move(std::string commandTemp) {//OK
	std::cout << "move: " << commandTemp << std::endl;
	std::cout << "please enter steps: ";
	bool isValid = true;
	std::vector <Position> movement;
	movement.push_back(Creature::getPosition());
	for (int i = 0; i < commandTemp.length(); i++) {
		Position temp = movement[movement.size() - 1];
		if ((board[temp.row][temp.col] == '0') || (board[temp.row][temp.col] == '2') || (isupper(board[temp.row][temp.col]))) {
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
		movement.pop_back();
	}
	temp = movement[movement.size() - 1];
	while ((board[temp.row][temp.col] != '1') && (board[temp.row][temp.col] != '3') && (movement.size() > 1)) {
		movement.pop_back();
		temp = movement[movement.size() - 1];
	}
	temp = movement[movement.size() - 1];
	//check
	/*for (int i = 0; i < movement.size(); i++) {
	std::cout << movement[i].row << ' ' << movement[i].col << " - ";
	}*/
	//check end
	Position restore = getPosition(); // restore 1 to original position
	board[restore.row][restore.col] = map.initBoard[restore.row][restore.col];
	setPostion(temp); // update character position
	board[temp.row][temp.col] = getName(); // update board with character's new position
}
void Monster::shuffle() {//洗牌//OK
	if (holdCard[chooseCard].canShuffle) {
		std::cout << "shuffle" << std::endl;
		for (int i = 0; i < holdCard.size(); i++) {
			if (holdCard[i].cardStatus == 1) {
				holdCard[i].cardStatus = 0;
			}
		}
		chooseCard++;
	}
}

void Monster::check() {
	// A-hp: 12, shield: 1
	cout << name << "-hp: " << hp << ", shield: " << shield << endl;
}