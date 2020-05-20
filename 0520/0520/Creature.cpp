#include "Creature.h"
void Creature::initialHp(const int& hpTemp) {
	totalHp = hp = hpTemp;
}
void Creature::setPostion(const Position& posTemp) {
	position = posTemp;
}
void Creature::shieldToZero() {
	shield = 0;
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
const Position& Creature::getPosition() const {
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