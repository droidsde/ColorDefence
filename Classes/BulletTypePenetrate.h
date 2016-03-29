﻿#pragma once

#include "Bullet.h"
#include "EnemyManager.h"


class BulletTypePenetrate : public Bullet
{
public:

	//初始化
	virtual bool init();  

	//create函数
	CREATE_FUNC(BulletTypePenetrate);

	float _damageWidth;

	void setDamage(float damage , float damageWidth);

	virtual void setTarget(Enemy* enemy);

protected:


	virtual void explode();


	void update(float delta);


	EnemyManager* em;
	cocos2d::Vector<Enemy*> enemiesDamaged;

};

