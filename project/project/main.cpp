#include "Readfile.h"
#include "charecter.h"
int main() {
	preInput();
	std::string command;
	std::cin >> command;
	if(command == "play"){
		std::cout << "character number:";
		std::cin >> characterNum;
		while((characterNum < 2) && (characterNum > 4)){
			std::cout << "out of range! " << "character number:";
			std::cin >> characterNum;
		}
		Charecter role1;
		Charecter role2;
		Charecter role3;
		Charecter role4;
		cout << CharacterList[0].name << ' ' << CharacterList[0].hp <<
			' ' << CharacterList[0].cardNum << ' ' << CharacterList[0].totalcard << endl;
		for (int j = 0; j < CharacterList[0].totalcard; j++) {
			cout << CharacterList[0].card[j].numero << ' ' <<
				CharacterList[0].card[j].dexterity << ' ' <<
				CharacterList[0].card[j].topHalf << ' ' <<
				CharacterList[0].card[j].lowHalf << ' ' <<
				CharacterList[0].card[j].cardStatus << endl;
		}
		for (int i = 0; i < characterNum; i++) {
			std::string name;
			std::cin >> name;
			role1.initial(CharacterList[0]);
			role2.initial(CharacterList[0]);
			for (int j = 0; j < characterType; j++) {
				system("pause");
				if (name == CharacterList[j].name) {
					if (i == 0) {
						role1.initial(CharacterList[j]);
					}
					else if (i == 1) {
						role2.initial(CharacterList[j]);
					}
					else if (i == 2) {
						role3.initial(CharacterList[j]);
					}
					else if (i == 3) {
						role4.initial(CharacterList[j]);
					}
				}
			}
		}
		//setupBoard();
	}
	else {
		exit(0);
	}
}