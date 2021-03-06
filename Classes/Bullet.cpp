﻿#include "Bullet.h"
//#include "EnemyPath.h"
#include "BulletManager.h"



USING_NS_CC;

bool Bullet::init()
{

	if ( !Sprite::init() )
	{
		return false;
	}

	BulletManager::getInstance()->bullets.pushBack(this);

	setTexture("effects/Bullet.png");


	_damage = 0;
	_target = nullptr;


	_damageContributerID = 0;

	return true;
}

void Bullet::setTarget( Enemy* enemy )
{
	_target = enemy;
	
	MoveTo* move = MoveTo::create(0.1f, _target->getPosition());
	ActionInstant* explode = CallFunc::create(CC_CALLBACK_0(Bullet::explode,this));

	Sequence* seq = Sequence::create(move,explode,NULL);

	runAction(seq);



}

Enemy* Bullet::getTarget()
{
	return _target;
}

void Bullet::explode()
{
	
	float damageContributed = _target->onPhysicalDamaged(_damage);
	DamageContributionManager::getInstance()->recordContribution(_damageContributerID , damageContributed);

	removeFromParent();
	BulletManager::getInstance()->bullets.eraseObject(this);

}

void Bullet::setDamage( float d )
{
	_damage = d;
}

void Bullet::pause()
{
	Sprite::pause();
}

void Bullet::resume()
{
	Sprite::resume();
}

void Bullet::setDamageContributerID( int ID )
{
	_damageContributerID = ID;
}



