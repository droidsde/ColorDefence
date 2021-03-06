﻿#include "CannonTypeShadow.h"
#include "BulletTypeShadow.h"
#include "NumericalManager.h"

USING_NS_CC;

bool CannonTypeShadow::init()
{

	if ( !Cannon::init() )
	{
		return false;
	}

	_cannonType = 0;
	setTexture("cannons/CannonCover_Shadow.png");


	return true;
}




void CannonTypeShadow::attackOnce()
{



	BulletTypeShadow* bullet = BulletTypeShadow::create();
	bullet->setPosition(getPosition());
	bullet->setRotation(getRotation());
	getParent()->addChild(bullet);
	bullet->setDamage(_damage, attackRange);
	bullet->setDamageContributerID(_damageContributerID);

	bullet->setTarget(_target);
	

	//
	bullet->setColor(NumericalManager::getInstance()->getBulletColor(getColorInfo()));
	//


	SoundManager::getInstance()->playSoundEffect("sound/cannon_shot_shadow.mp3");


}

void CannonTypeShadow::setDirection()
{
	setRotation(getRotation()-2);
	return;
}

