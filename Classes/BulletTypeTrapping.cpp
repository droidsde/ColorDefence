﻿#include "BulletTypeTrapping.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "BuffTypeStun.h"

USING_NS_CC;

bool BulletTypeTrapping::init()
{

	if ( !Bullet::init() )
	{
		return false;
	}

	//BulletManager::getInstance()->bullets.pushBack(this);

	setTexture("effects/Bullet_Trapping.png");
	_isTrapping = false;


	return true;
}



void BulletTypeTrapping::explode()
{

	float damageContributed = _target->onPhysicalDamaged(_damage);
	DamageContributionManager::getInstance()->recordContribution(_damageContributerID , damageContributed);
	if (_isTrapping)
	{
		float stunTime = 5.5;
		_target->setBuff(BuffTypeStun::create(_target,stunTime));
// 		Point p = getPosition() - _target->getPosition();
// 		removeFromParent();
// 		_target->addChild(this); 
//		setPosition(p);
		auto act1 = DelayTime::create(stunTime);
		auto act2 = FadeOut::create(0.4);
		auto act3 = CallFunc::create([&](){

			removeFromParent();
			BulletManager::getInstance()->bullets.eraseObject(this);

		});
		auto seq = Sequence::create(act1,act2,act3,NULL);
		runAction(seq);
	}
	else
	{
		removeFromParent();
		BulletManager::getInstance()->bullets.eraseObject(this);
	}


}

void BulletTypeTrapping::setDamage(float damage , bool trapping)
{
	
	_isTrapping = trapping;
	if (_isTrapping)
	{
		_damage = damage*0.5;
		setTexture("effects/Bullet_Trapping_trap.png");
		setOpacity(190);
	}
	else
	{
		_damage = damage;
		setScale(2);
	}
}


