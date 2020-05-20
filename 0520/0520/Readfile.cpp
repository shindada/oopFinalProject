#include "Readfile.h"
CharacterData* CharacterList;
MonsterData* MonsterList;
int characterType;//角色種類
int MODE;
void preInput() {
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
	cin >> filename;
	ifs.open(filename);
	if (!ifs) cout << "Fail to open the file.";
	else {
		int monsterNum;
		ifs >> monsterNum;
		MonsterList = new MonsterData[monsterNum];
		for (int i = 0; i < monsterNum; i++) {
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
		/*for (int i = 0; i < monsterNum; i++) {
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
	cin >> MODE;
}
void setUpBoard() {
	string filename; cin >> filename;
	ifstream ifs(filename);
	if (!ifs) cout << "Fail to open the file.";
	else {
		struct Board map;
		int row; int col;
		ifs >> row >> col; // read in row and column
		map.initBoard = new int*[row]; // allocate space for map
		for (int i = 0; i < row; i++) {
			map.initBoard[i] = new int[col];
		}
		for (int i = 0; i < row; i++) { // store map in initBoard
			for (int j = 0; j < col; j++) {
				ifs >> map.initBoard[i][j];
			}
		}
		for (int i = 0; i < 4; i++) { // store 4 spawns of character 
			for (int j = 1; j >= 0; j--) {
				ifs >> map.spawn[i][j];
			}
		}
		int monsterNum = 0; ifs >> monsterNum; // number of monsters in the map
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
	}
}
