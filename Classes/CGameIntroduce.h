#pragma once

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
using namespace cocos2d;
using namespace cocostudio;


//���������Դ�д�����ò�ʵ��
class CGameIntroduce :public Layer
{
public:
	CGameIntroduce();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();


	void update(float dt);

	float m_currentTime = 0;
};

