#include "Creature.h"
//Creature::Creature(const int& hpTemp)
//	:totalHp(hpTemp), hp(hpTemp), shield(0) {
//}
void Creature::initialHp(const int& hpTemp) {
	totalHp = hp = hpTemp;
}
void Creature::setPosition(const Position& posTemp) {
	position = posTemp;
}
void Creature::heal(const int& bloodTemp) {
	if (hp + bloodTemp < totalHp) {
		totalHp = hp + bloodTemp;
	}
}
void Creature::shieldPlus(const int& shieldTemp) {
	shield += shieldTemp;
}
const int& Creature::getTotalHp() const {
	return totalHp;
}
const int& Creature::getHp() const {
	return hp;
}
const int& Creature::getShield() const {
	return shield;
}
void Creature::shieldToZero() {
	shield = 0;
}
const Position& Creature::getPosition() const {
	return position;
}
