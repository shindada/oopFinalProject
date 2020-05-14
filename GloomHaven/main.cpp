#include "Readfile.h"

int main() {
	preInput();
	std::string command;
	std::cin >> command;
	if(command == "play"){
		std::cout << "character number:";
		int characternum;
		std::cin >> characternum;
		while((characternum < 2) && (characternum > 4)){
			std::cout << "out of range! " << "character number:";
			std::cin >> characternum;
		}
		for (int i = 0; i < characternum; i++) {
			std::string name, holdcard;
			
		}
		//setupBoard();
	}
	else {
		exit(0);
	}
}