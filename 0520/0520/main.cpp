#include "Readfile.h"
#include "Character.h"
int characterNum;//遊戲角色個數
int main() {
	preInput();
	std::string command;
	std::cin >> command;
	if(command == "play"){
		std::cout << "character number:";
		std::cin >> characterNum;//孟耘 改這裡
		while((characterNum < 2) || (characterNum > 4)){
			std::cout << "out of range! " << "character number:";
			std::cin >> characterNum;
		}
		Character *role = new Character[characterNum];
		for (int i = 0; i < characterNum; i++) {
			std::string name;
			std::cin >> name;
			for (int j = 0; j < characterType; j++) {
				if (name == CharacterList[j].name) {
					role[i].initial(CharacterList[j]);
				}
			}
		}
		for (int i = 0; i < characterNum; i++) {
			role[i].draw();
			role[i].getHoldCard();
		}
		//setupBoard();
	}
	else {
		exit(0);
	}
}