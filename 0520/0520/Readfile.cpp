#include "Readfile.h"
#include <algorithm>

int characterType;//角色種類
int monsterType;
int monsterNum;
int MODE;
Board map;
CharacterData* CharacterList;
MonsterData* MonsterList;

bool compareRow(Position& first, Position& last);
bool compareCol(Position& first, Position& last);

void preInput() {
	//read Character Data
	string filename; cin >> filename;
	ifstream ifs(filename);
	if (!ifs) cout << "Fail to open the file.";
	else {
		ifs >> characterType;
		CharacterList = new CharacterData[characterType];
		for (int i = 0; i < characterType; i++) {
			ifs >> CharacterList[i].name >> CharacterList[i].hp >>
				CharacterList[i].cardNum >> CharacterList[i].totalcard;
			for (int j = 0; j < CharacterList[i].totalcard; j++) {
				struct CharacterCardData temp;
				ifs >> temp.numero >> temp.dexterity;
				string str; ifs.ignore(); getline(ifs, str);
				size_t pos = str.find('-');
				temp.topHalf = str.substr(0, pos - 1);
				temp.lowHalf = str.substr(pos + 1);
				temp.cardStatus = 2;
				CharacterList[i].card.push_back(temp);
			}
		}

		//check
		/*for (int i = 0; i < characterType; i++) {
			cout << CharacterList[i].name << ' ' << CharacterList[i].hp <<
				' ' << CharacterList[i].cardNum << ' ' << CharacterList[i].totalcard << endl;
			for (int j = 0; j < CharacterList[i].totalcard; j++) {
				cout << CharacterList[i].card[j].numero << ' ' <<
					CharacterList[i].card[j].dexterity << ' ' <<
					CharacterList[i].card[j].topHalf << ' ' <<
					CharacterList[i].card[j].lowHalf << ' ' <<
					CharacterList[i].card[j].cardStatus << endl;
			}
		}*/
		//check end
	}
	ifs.close();
	//read Character Data End

	//read Monster Data
	cin >> filename;
	ifs.open(filename);
	if (!ifs) cout << "Fail to open the file.";
	else {
		ifs >> monsterType;
		MonsterList = new MonsterData[monsterType];
		for (int i = 0; i < monsterType; i++) {
			if (i == 0) ifs >> MonsterList[0].name;
			ifs >> MonsterList[i].normal[0] >> MonsterList[i].normal[1]
				>> MonsterList[i].normal[2] >> MonsterList[i].elite[0] >>
				MonsterList[i].elite[1] >> MonsterList[i].elite[2];
			string name; ifs >> name;
			do {
				struct MonsterCardData temp;
				if (name != MonsterList[i].name) {
					MonsterList[i + 1].name = name;
					break;
				}
				else {
					ifs >> temp.numero >> temp.dexterity;
					ifs.ignore(); getline(ifs, temp.skill);
					if (temp.skill.back() == 'd') temp.canShuffle = false;
					else temp.canShuffle = true;
					temp.skill.pop_back();
					temp.cardStatus = 1;
					MonsterList[i].card.push_back(temp);
				}
			} while (ifs >> name);
		}

		//check
		/*for (int i = 0; i < monsterType; i++) {
			cout << MonsterList[i].name << ' ' << MonsterList[i].normal[0] << ' '
				<< MonsterList[i].normal[1] << ' ' << MonsterList[i].normal[2] << ' '
				<< MonsterList[i].elite[0] << ' ' << MonsterList[i].elite[1] << ' '
				<< MonsterList[i].elite[2] << endl;
			for (int j = 0; j < MonsterList[i].card.size(); j++) {
				cout << MonsterList[i].card[j].numero << ' '
					<< MonsterList[i].card[j].dexterity << ' '
					<< MonsterList[i].card[j].skill << ' '
					<< MonsterList[i].card[j].canShuffle << ' '
					<< MonsterList[i].card[j].cardStatus << endl;
			}
		}*/
		//check end
	}
	ifs.close();
	//read Monster Data end
	
	cin >> MODE;//read MODE
}
void setUpBoard() {//read Map Data
	string filename; cin >> filename;
	ifstream ifs(filename);
	if (!ifs) cout << "Fail to open the file.";
	else {
		ifs >> map.rowSize >> map.colSize; // read in row and column
		map.initBoard = new char*[map.rowSize]; // allocate space for map
		for (int i = 0; i < map.rowSize; i++) {
			map.initBoard[i] = new char[map.colSize];
		}
		for (int i = 0; i < map.rowSize; i++) { // store map in initBoard
			for (int j = 0; j < map.colSize; j++) {
				ifs >> map.initBoard[i][j];
			}
		}

		//check
		/*for (int i = 0; i < map.rowSize; i++) { // store map in initBoard
			for (int j = 0; j < map.colSize; j++) {
				cout << map.initBoard[i][j];
			}
			cout << endl;
		}*/
		//check end

		//set spawn
		for (int i = 0; i < 4; i++) { // store 4 spawns of character 
			Position spawnPoint;
			ifs >> spawnPoint.col >> spawnPoint.row;
			map.spawn.push_back(spawnPoint);
		}
		//sort spawn order
		std::sort(map.spawn.begin(), map.spawn.end(), compareRow);
		std::sort(map.spawn.begin(), map.spawn.end(), compareCol);
		//sort spawn order end

		//check
		/*for (int i = 0; i < 4; i++) {
			std::cout << map.spawn[i].row << ' ' << map.spawn[i].col << std::endl;
		}*/
		//check end

		//set spawn end

		//set monsterplace
		monsterNum = 0;
		ifs >> monsterNum; // number of monsters in the map
		for (int i = 0; i < monsterNum; i++) { // store monsters' deploy
			struct MonsterPlace temp;
			ifs >> temp.name >> temp.place.col >> temp.place.row;
			int peoTemp[3];
			ifs >> peoTemp[0] >> peoTemp[1] >> peoTemp[2];
			if (characterNum == 2) temp.peoNum = peoTemp[0]; // Remi: chaNum要改名稱
			else if (characterNum == 3) temp.peoNum = peoTemp[1];
			else temp.peoNum = peoTemp[2];
			map.deploy.push_back(temp);
		}

		//check
		/*for (int i = 0; i < map.deploy.size(); i++) { // store monsters' deploy
			std::cout << map.deploy[i].name << ' '
				<< map.deploy[i].place.row << ' '
				<< map.deploy[i].place.col << ' '
				<< map.deploy[i].peoNum << std::endl;
		}*/
		//check end

		//set monsterplace end

	}
}
bool compareRow(Position& first, Position& last) {
	return first.row < last.row;
}
bool compareCol(Position& first, Position& last) {
	if (first.row == last.row) {
		return first.col < last.col;
	}
	else {
		return first.row < last.row;
	}
}