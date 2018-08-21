#include "CGameManager.h"



CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
	removeChild(m_currentScene, true);
	////如果是new的需要delete
	removeChild(m_player, true);
	//if (m_introduceScene)
	//{
	//	delete m_introduceScene;
	//	m_introduceScene = nullptr;
	//}
	//if (m_menuScene)
	//{
	//	delete m_menuScene;
	//	m_menuScene = nullptr;
	//}
	//if (m_info)
	//{
	//	delete m_info;
	//	m_info = nullptr;
	//}
	//if (m_dead)
	//{
	//	delete m_dead;
	//	m_dead = nullptr;
	//}
	//if (m_level1)
	//{
	//	delete m_level1;
	//	m_level1 = nullptr;
	//}
	//if (m_level2)
	//{
	//	delete m_level2;
	//	m_level2 = nullptr;
	//}
	//if (m_player)
	//{
	//	delete m_player;
	//	m_player = nullptr;
	//}
	

	//SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	//SimpleAudioEngine::getInstance()->stopAllEffects();//停止所有音效
	//释放声音库
	::BASS_Free();
}


void CGameManager::LoadScene()
{
	m_introduceScene = new CGameIntroduce();//需要在析构中删除
	addChild(m_introduceScene);
	m_menuScene = new CGameMenu();
	m_player = new CGamePlayer();
	m_info = new CGameInfo();
	m_level1 = new CGameLevel(1);
	m_level2 = new CGameLevel(2);
	m_dead = new CGameLevel(0);

	m_level3 = new CGameLevel(3);

	//观察者
	//m_player->m_menuPlayer = m_menuScene;
	//m_player->m_infoPlayer = m_info;
	//m_player->m_levelPlayer_1 = m_level1;
	//m_player->m_levelPlayer_2 = m_level2;

	//m_startScene = new FindGameScene();


	m_currentScene = m_introduceScene;

	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("res/music/menuback.mp3");
	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/levelback_1.mp3");
	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/levelback_2.mp3");
	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/hellback.mp3");

	
}

void CGameManager::intoIntroduceScene()
{
	///实现进入游戏介绍的类

}

void CGameManager::intoGameMenu()
{
	//removeChild(m_player, true);
	m_player->m_collision.clear();
	for (unsigned int i=0;i<m_menuScene->m_array_collision.size();i++)
	{
		CGamePlayer::area door;
		door.collision = m_menuScene->m_array_collision[i].collision;
		door.id = m_menuScene->m_array_collision[i].id;
		door.type = m_menuScene->m_array_collision[i].type;
		m_player->m_collision.push_back(door);
	}
	///实现菜单场景的类
	removeChild(m_currentScene, true);                                             
	m_menuScene->animate = CSLoader::createTimeline("GameMenu/GameMenu.csb");
	m_menuScene->animate->gotoFrameAndPlay(0);
	m_menuScene->rootNode->runAction(m_menuScene->animate);
	addChild(m_menuScene);
	addChild(m_player);
	m_player->m_ui->setVisible(false);
	m_player->player.m_player->setPosition(100, 200);
	m_currentScene = m_menuScene;

	//if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())    //判断当前是否播放背景音乐  
	//{
	//	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//先停
	//	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/menuback.mp3", true);//再放
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/menuback.mp3", true);
	//}
	//else
	//{
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/menuback.mp3", true);//直接放
	//}

	if (m_currentBackgourndMusic == 0)//是否为设定初值，即未播放任何背景音乐
	{
		m_currentBackgourndMusic = bgmMeun;//将现在播放的内容赋给此对象
		BASS_ChannelPlay(bgmMeun, true);//播放
	}
	else
	{
		BASS_ChannelStop(m_currentBackgourndMusic);//将存储在此内容的音乐停掉
		BASS_ChannelPlay(bgmMeun, true);//播放新音乐
		m_currentBackgourndMusic = bgmMeun;//存储播放的新的内容
	}
}


void CGameManager::intoGameInfo()//动画加载有问题，有时会出现不按W也执行
{
	m_player->m_collision.clear();
	for (unsigned int i = 0; i < m_info->m_array_collision.size(); i++)
	{
		CGamePlayer::area door;
		door.collision = m_info->m_array_collision[i].collision;
		door.id = m_info->m_array_collision[i].id;
		door.type = m_info->m_array_collision[i].type;
		m_player->m_collision.push_back(door);
	}
	//游戏信息场景的类
	//removeChild(m_player, true);
	removeChild(m_currentScene, true);

	m_info->animate = CSLoader::createTimeline("GameInfo/GameInfo.csb");
	m_info->animate->gotoFrameAndPlay(0);
	m_info->rootNode->runAction(m_info->animate);
	addChild(m_info);
	addChild(m_player);
	m_player->player.m_player->setPosition(100, 200);
	m_currentScene = m_info;
}

void CGameManager::intoGameDead()//复活场景
{
	if (m_dead) { delete m_dead; m_dead = nullptr; }
	m_dead = new CGameLevel(0);

	m_player->m_collision.clear();
	for (unsigned int i = 0; i < m_dead->m_array_collision.size(); i++)
	{
		CGamePlayer::area door;
		door.collision = m_dead->m_array_collision[i].collision;
		door.id = m_dead->m_array_collision[i].id;
		door.type = m_dead->m_array_collision[i].type;
		m_player->m_collision.push_back(door);
	}
	//游戏信息场景的类
	//removeChild(m_player, true);
	removeChild(m_currentScene, true);

	m_dead->animate = CSLoader::createTimeline("GameStart/level_0.csb");
	m_dead->animate->gotoFrameAndPlay(0);
	m_dead->rootNode->runAction(m_dead->animate);
	addChild(m_dead);
	addChild(m_player);
	m_player->player.m_player->setPosition(640, 700);
	m_currentScene = m_dead;

	//if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())    //判断当前是否播放背景音乐  
	//{
	//	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//先停
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/hellback.mp3", true);//再放
	//}
	//else
	//{
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/hellback.mp3", true);//直接放
	//}

	if (m_currentBackgourndMusic == 0)//是否为设定初值，即未播放任何背景音乐
	{
		m_currentBackgourndMusic = bgmDead;//将现在播放的内容赋给此对象
		BASS_ChannelPlay(bgmDead, true);//播放
	}
	else
	{
		BASS_ChannelStop(m_currentBackgourndMusic);//将存储在此内容的音乐停掉
		BASS_ChannelPlay(bgmDead, true);//播放新音乐
		m_currentBackgourndMusic = bgmDead;//存储播放的新的内容
	}
}

void CGameManager::intoGameLevel1()
{
	//重置场景
	if (m_level1) { delete m_level1; m_level1 = nullptr; }
	m_level1 = new CGameLevel(1);
	m_player->m_levelPlayer_1 = m_level1;
	
	m_player->whichScene(1);
	m_player->m_collision.clear();
	for (unsigned int i = 0; i < m_level1->m_array_collision.size(); i++)
	{
		CGamePlayer::area door;
		door.collision = m_level1->m_array_collision[i].collision;
		door.id = m_level1->m_array_collision[i].id;
		door.type = m_level1->m_array_collision[i].type;
		m_player->m_collision.push_back(door);
	}
	//游戏信息场景的类
	//removeChild(m_player, true);
	removeChild(m_currentScene, true);

	m_level1->animate = CSLoader::createTimeline("GameStart/level_1.csb");
	m_level1->animate->gotoFrameAndPlay(0);
	m_level1->rootNode->runAction(m_level1->animate);
	addChild(m_level1);
	addChild(m_player);
	m_player->m_ui->setVisible(true);
	m_player->player.m_player->setPosition(100, 200);
	m_currentScene = m_level1;

	//if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())    //判断当前是否播放背景音乐  
	//{
	//	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//先停
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/levelback_1.mp3", true);//再放
	//}
	//else
	//{
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/levelback_1.mp3", true);//直接放
	//}

	if (m_currentBackgourndMusic == 0)//是否为设定初值，即未播放任何背景音乐
	{
		m_currentBackgourndMusic = bgmLevel_1;//将现在播放的内容赋给此对象
		BASS_ChannelPlay(bgmLevel_1, true);//播放
	}
	else
	{
		BASS_ChannelStop(m_currentBackgourndMusic);//将存储在此内容的音乐停掉
		BASS_ChannelPlay(bgmLevel_1, true);//播放新音乐
		m_currentBackgourndMusic = bgmLevel_1;//存储播放的新的内容
	}
}


void CGameManager::intoGameLevel2()
{
	//重置场景
	if (m_level2) { delete m_level2; m_level2 = nullptr; }
	m_level2 = new CGameLevel(2);
	m_player->m_levelPlayer_2 = m_level2;

	m_player->whichScene(2);
	m_player->m_collision.clear();
	for (unsigned int i = 0; i < m_level2->m_array_collision.size(); i++)
	{
		CGamePlayer::area door;
		door.collision = m_level2->m_array_collision[i].collision;
		door.id = m_level2->m_array_collision[i].id;
		door.type = m_level2->m_array_collision[i].type;
		m_player->m_collision.push_back(door);
	}
	//游戏信息场景的类
	//removeChild(m_player, true);
	removeChild(m_currentScene, true);

	m_level2->animate = CSLoader::createTimeline("GameStart/level_2.csb");
	m_level2->animate->gotoFrameAndPlay(0);
	m_level2->rootNode->runAction(m_level2->animate);
	addChild(m_level2);
	addChild(m_player);
	m_player->m_ui->setVisible(true);
	m_player->player.m_player->setPosition(200, 200);
	m_currentScene = m_level2;

	//if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())    //判断当前是否播放背景音乐  
	//{
	//	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//先停
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/levelback_2.mp3", true);//再放
	//}
	//else
	//{
	//	SimpleAudioEngine::getInstance()->playBackgroundMusic("music/levelback_2.mp3", true);//直接放
	//}

	if (m_currentBackgourndMusic == 0)//是否为设定初值，即未播放任何背景音乐
	{
		m_currentBackgourndMusic = bgmLevel_2;//将现在播放的内容赋给此对象
		BASS_ChannelPlay(bgmLevel_2, true);//播放
	}
	else
	{
		BASS_ChannelStop(m_currentBackgourndMusic);//将存储在此内容的音乐停掉
		BASS_ChannelPlay(bgmLevel_2, true);//播放新音乐
		m_currentBackgourndMusic = bgmLevel_2;//存储播放的新的内容
	}
}

void CGameManager::intoGameLevel3()
{
	//重置场景
	if (m_level3) { delete m_level3; m_level3 = nullptr; }
	m_level3 = new CGameLevel(3);
	m_player->m_levelPlayer_3 = m_level3;

	m_player->whichScene(3);
	m_player->m_collision.clear();
	for (unsigned int i = 0; i < m_level3->m_array_collision.size(); i++)
	{
		CGamePlayer::area door;
		door.collision = m_level3->m_array_collision[i].collision;
		door.id = m_level3->m_array_collision[i].id;
		door.type = m_level3->m_array_collision[i].type;
		m_player->m_collision.push_back(door);
	}
	//游戏信息场景的类
	//removeChild(m_player, true);
	removeChild(m_currentScene, true);

	m_level3->animate = CSLoader::createTimeline("GameStart/level_3.csb");
	m_level3->animate->gotoFrameAndPlay(0);
	m_level3->rootNode->runAction(m_level3->animate);
	addChild(m_level3);
	addChild(m_player);
	m_player->m_ui->setVisible(true);
	m_player->player.m_player->setPosition(200, 200);
	m_currentScene = m_level3;

	if (m_currentBackgourndMusic == 0)//是否为设定初值，即未播放任何背景音乐
	{
		m_currentBackgourndMusic = bgmLevel_3;//将现在播放的内容赋给此对象
		BASS_ChannelPlay(bgmLevel_3, true);//播放
	}
	else
	{
		BASS_ChannelStop(m_currentBackgourndMusic);//将存储在此内容的音乐停掉
		BASS_ChannelPlay(bgmLevel_3, true);//播放新音乐
		m_currentBackgourndMusic = bgmLevel_3;//存储播放的新的内容
	}
}
