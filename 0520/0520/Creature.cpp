#include "Creature.h"
void Creature::initialHp(const int& hpTemp) {
	totalHp = hp = hpTemp;
}
void Creature::setPostion(const Position& posTemp) {
	position = posTemp;
}
void Creature::dexterityToZero(void) {
	dexterity = 0;
}
void Creature::shieldToZero(void) {
	shield = 0;
}
const int& Creature::getTotalHp(void) const {
	return totalHp;
}
const int& Creature::getHp(void) const {
	return hp;
}
const int& Creature::getShield(void) const {
	return shield;
}
const Position& Creature::getPosition(void) const {
	return position;
}
void Creature::heal(const int& bloodTemp) {
	std::cout << "heal: " << bloodTemp << std::endl;
	if (hp + bloodTemp < totalHp) {
		hp += bloodTemp;
	}
	else {
		hp = totalHp;
	}
}
void Creature::shieldPlus(const int& shieldTemp) {
	std::cout << "shield: " << shieldTemp << std::endl;
	shield += shieldTemp;
}