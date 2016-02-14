#pragma once

#include "cocos2d.h"

class RotatorOnPrebuilt : public cocos2d::Node
{
public:

	//��ʼ��
	virtual bool init();  

	//create����
	CREATE_FUNC(RotatorOnPrebuilt);

	void setRadius(float r);

	void setSpeed(float v);

	void setSize(float s);

private:

	float _radius;

	float _speed;

	float _size;

	//cocos2d::MotionStreak* ms;
	cocos2d::DrawNode* ms;

	void update(float delta);

	float it;
	float _dit;

};

