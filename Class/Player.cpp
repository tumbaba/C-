#include "pch.h"
#include "Player.h"

Player::Player()
{
	cout << "Player의 기본 생성자" << endl;
	_hp = 0;
	_mp = 0;
	_attack = 0;
}

Player::Player(int hp, int mp, int attack)
{
	cout << "Player의 타입변환 생성자" << endl;
	_hp = hp;
	_mp = mp;
	_attack = attack;
}

Player::~Player()
{
	cout << "Player의 소멸자" << endl;
}

void Player::PrintPlayer()
{
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "ATTACK : " << _attack << endl;
}

void Player::Attack(Player* p)
{
	if (IsDead() || p->IsDead()) return;

	cout << "Player의 공격!!!" << endl;

	p->TakeDamage(_attack);
}

void Player::TakeDamage(int amount)
{
	_hp -= amount;

	if (_hp <= 0)
		_hp = 0;
}

void Player::SetStat(int hp, int mp, int attack)
{
	_hp = hp;
	_mp = mp;
	_attack = attack;
}
