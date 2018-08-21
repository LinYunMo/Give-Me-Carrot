#include "CGameIntroduce.h"
#include "CGameManager.h"//ÒÔÃâ½»²æ°üº¬





CGameIntroduce::CGameIntroduce()
{
	init();
}


bool CGameIntroduce::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("GameIntroduce/GameIntroduce.csb");
	auto animate = CSLoader::createTimeline("GameIntroduce/GameIntroduce.csb");
	animate->gotoFrameAndPlay(0);
	rootNode->runAction(animate);

	addChild(rootNode);

	scheduleUpdate();

	return true;
}

void CGameIntroduce::update(float dt)
{
	m_currentTime += dt;
	if (m_currentTime>=5)
	{
		CGameManager::Instance()->intoGameMenu();
	}
}
