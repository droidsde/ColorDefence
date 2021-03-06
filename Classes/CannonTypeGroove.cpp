﻿#include "CannonTypeGroove.h"
#include "BulletTypeGroove.h"
#include "NumericalManager.h"

USING_NS_CC;
const int color_tag = 111;

bool CannonTypeGroove::init()
{

	if ( !Cannon::init() )
	{
		return false;
	}

	float dis = 17.9;
	_cannonType = 0;
	setTexture("cannons/CannonCover_Groove_base.png");
	Vec2 v = getContentSize()/2;
	for (int i=0 ; i<12 ; i++)
	{
		_outter[i] = Sprite::create("cannons/CannonCover_Groove_outter.png");
		addChild(_outter[i]);
		_outter[i]->setAnchorPoint(Point(0.5,0));
		_outter[i]->setPosition(v.x + dis*cos(i * CC_DEGREES_TO_RADIANS(30)+CC_DEGREES_TO_RADIANS(90)), v.y + dis*sin(i* CC_DEGREES_TO_RADIANS(30)+CC_DEGREES_TO_RADIANS(90)));
		_outter[i]->setRotation(i*(-30));

	}

	_r_timer = 0 ;

	//(this->getChildByTag(color_tag))->setOpacity(0);


	return true;
}




void CannonTypeGroove::attackOnce()
{



	BulletTypeGroove* bullet = BulletTypeGroove::create();
	bullet->setPosition(getPosition());
	bullet->setRotation(getRotation());
	bullet->setDamage(_damage, 0.9 + 0.9* (float)_color.r/255.0 ,155);

	bullet->setTarget(_target);
	bullet->setDamageContributerID(_damageContributerID);
	getParent()->addChild(bullet,10086);

	//
	bullet->setColor(NumericalManager::getInstance()->getBulletColor(getColorInfo()));
	//

	SoundManager::getInstance()->playSoundEffect("sound/cannon_shot_groove.wav");



}

void CannonTypeGroove::setDirection()
{

	_r_timer ++ ;

	if (_r_timer / 2 >11)
	{
		_r_timer = 0;
	}

	Point normalized = ccpNormalize(ccp(_target->getPosition().x - getPosition().x,	_target->getPosition().y - getPosition().y));
	float rot = CC_RADIANS_TO_DEGREES(atan2(normalized.y, - normalized.x)) - 90;
	_outter[_r_timer / 2 ]->setRotation(rot);




	

}

void CannonTypeGroove::setColorInfo( cocos2d::Color3B c3b )
{
	Cannon::setColorInfo(c3b);
	auto nm = NumericalManager::getInstance();

	for (int i =0 ; i <12 ; i++)
	{
		_outter[i]->setColor(nm->getBulletColor(c3b));
	}



}

