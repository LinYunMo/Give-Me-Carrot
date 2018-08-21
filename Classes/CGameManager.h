#pragma once
///包含你要加载的场景的头文件
#include "CGameIntroduce.h"
#include "CGameMenu.h"
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "CGamePlayer.h"
#include "CGameInfo.h"
#include "CGameLevel.h"
//#include "SimpleAudioEngine.h"//声音库
#include <bass.h>


using namespace cocos2d;
using namespace cocostudio;
//using namespace CocosDenshion;//声音命名空间

class CGameManager :public Scene
{
private:
	CGameManager();
public:

	~CGameManager();
	
	static CGameManager * Instance()
	{
		static CGameManager gm;
		return &gm;
	}

	///当前的场景
	Layer* m_currentScene = nullptr;
	///介绍场景
	CGameIntroduce* m_introduceScene = nullptr;
	CGameMenu* m_menuScene = nullptr;
	CGamePlayer* m_player = nullptr;
	CGameInfo* m_info = nullptr;
	CGameLevel* m_dead = nullptr;
	CGameLevel* m_level1 = nullptr;
	CGameLevel* m_level2 = nullptr;
	CGameLevel* m_level3 = nullptr;

	///加载资源
	void LoadScene();

	void intoIntroduceScene();

	void intoGameMenu();

	void intoGameInfo();

	void intoGameDead();

	void intoGameLevel1();

	void intoGameLevel2();

	void intoGameLevel3();

	//观察者
	//CGamePlayer m_gameplayer;
	//CGameMenu m_menu;

	//初始化声音库
	HRESULT hResult = ::BASS_Init(-1, 44100, 0, NULL, NULL);
	//装载一个声音文件，成功返回一个HSTREA的 变量
	HSTREAM bgmMeun = ::BASS_StreamCreateFile(FALSE, "res/music/menuback.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmLevel_1 = ::BASS_StreamCreateFile(FALSE, "res/music/levelback_1.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmLevel_2 = ::BASS_StreamCreateFile(FALSE, "res/music/levelback_2.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmLevel_3 = ::BASS_StreamCreateFile(FALSE, "res/music/levelback_3.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmDead = ::BASS_StreamCreateFile(FALSE, "res/music/hellback.mp3", 0, 0, BASS_SAMPLE_LOOP);

	//是否有音乐播放状态
	HSTREAM m_currentBackgourndMusic = 0;


};

