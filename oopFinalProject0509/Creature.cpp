#include "Creature.h"
//Creature::Creature(const int& hpTemp, const int& defTemp)
//	:totalHp(hpTemp), hp(hpTemp), def(defTemp), shield(0) {
//}
void Creature::heal(const int& bloodTemp) {
	if (hp + bloodTemp < totalHp) {
		totalHp = hp + bloodTemp;
	}
}
void Creature::shieldPlus(const int& shieldTemp) {
	shield = shieldTemp;
	def += shield;
}
const int& Creature::getTotalHp() const {
	return totalHp;
}
const int& Creature::getHp() const {
	return hp;
}
const int& Creature::getDef() const {
	return def;
}
const int& Creature::getShield() const {
	return shield;
}
void Creature::shieldToZero() {
	def -= shield;
	shield = 0;
}
const Pos& Creature::getPosition() const {
	return position;
}
