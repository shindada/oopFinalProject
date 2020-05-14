#include "Readfile.h"

void preInput() {
	string filename; cin >> filename;
	ifstream ifs(filename);
	if (!ifs) cout << "Fail to open the file.";
	else {
		int characterNum;
		ifs >> characterNum;
		CharacterList = new CharacterData[characterNum];
		for (int i = 0; i < characterNum; i++) {
			ifs >> CharacterList[i].name >> CharacterList[i].hp >>
				CharacterList[i].cardNum >> CharacterList[i].totalcard;
			//for (int j = 0; j < CharacterList[i].totalcard; j++) {
			//	struct CharacterCardData temp;
			//	ifs >> temp.numero >> temp.dexterity;
			//	string str; ifs.ignore(); getline(ifs, str);
			//	size_t pos = str.find('-');
			//	temp.topHalf = str.substr(0, pos - 1);
			//	temp.lowHalf = str.substr(pos + 1);
			//	temp.cardStatus = 2;
			//	CharacterList[i].card.push_back(temp);
			//}
		}
		for (int i = 0; i < characterNum; i++) {
			cout << CharacterList[i].name << ' ' << CharacterList[i].hp <<
				' ' << CharacterList[i].cardNum << ' ' << CharacterList[i].totalcard << endl;
			for (int j = 0; j < CharacterList[i].totalcard; j++) {
				cout << CharacterList[i].card[j].numero << ' ' <<
					CharacterList[i].card[j].dexterity << ' ' <<
					CharacterList[i].card[j].topHalf << ' ' <<
					CharacterList[i].card[j].lowHalf << ' ' <<
					CharacterList[i].card[j].cardStatus << endl;
			}
		}
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
		//for (int i = 0; i < monsterNum; i++) {
		//	cout << MonsterList[i].name << ' ' << MonsterList[i].normal[0] << ' '
		//		<< MonsterList[i].normal[1] << ' ' << MonsterList[i].normal[2] << ' '
		//		<< MonsterList[i].elite[0] << ' ' << MonsterList[i].elite[1] << ' '
		//		<< MonsterList[i].elite[2] << endl;
		//	for (int j = 0; j < MonsterList[i].card.size(); j++) {
		//		cout << MonsterList[i].card[j].numero << ' '
		//			<< MonsterList[i].card[j].dexterity << ' '
		//			<< MonsterList[i].card[j].skill << ' '
		//			<< MonsterList[i].card[j].canShuffle << ' '
		//			<< MonsterList[i].card[j].cardStatus << endl;
		//	}
		//}
	}
	ifs.close();
	cin >> MODE;
}

