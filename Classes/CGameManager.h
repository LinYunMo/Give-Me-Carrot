#pragma once
///������Ҫ���صĳ�����ͷ�ļ�
#include "CGameIntroduce.h"
#include "CGameMenu.h"
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "CGamePlayer.h"
#include "CGameInfo.h"
#include "CGameLevel.h"
//#include "SimpleAudioEngine.h"//������
#include <bass.h>


using namespace cocos2d;
using namespace cocostudio;
//using namespace CocosDenshion;//���������ռ�

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

	///��ǰ�ĳ���
	Layer* m_currentScene = nullptr;
	///���ܳ���
	CGameIntroduce* m_introduceScene = nullptr;
	CGameMenu* m_menuScene = nullptr;
	CGamePlayer* m_player = nullptr;
	CGameInfo* m_info = nullptr;
	CGameLevel* m_dead = nullptr;
	CGameLevel* m_level1 = nullptr;
	CGameLevel* m_level2 = nullptr;
	CGameLevel* m_level3 = nullptr;

	///������Դ
	void LoadScene();

	void intoIntroduceScene();

	void intoGameMenu();

	void intoGameInfo();

	void intoGameDead();

	void intoGameLevel1();

	void intoGameLevel2();

	void intoGameLevel3();

	//�۲���
	//CGamePlayer m_gameplayer;
	//CGameMenu m_menu;

	//��ʼ��������
	HRESULT hResult = ::BASS_Init(-1, 44100, 0, NULL, NULL);
	//װ��һ�������ļ����ɹ�����һ��HSTREA�� ����
	HSTREAM bgmMeun = ::BASS_StreamCreateFile(FALSE, "res/music/menuback.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmLevel_1 = ::BASS_StreamCreateFile(FALSE, "res/music/levelback_1.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmLevel_2 = ::BASS_StreamCreateFile(FALSE, "res/music/levelback_2.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmLevel_3 = ::BASS_StreamCreateFile(FALSE, "res/music/levelback_3.mp3", 0, 0, BASS_SAMPLE_LOOP);
	HSTREAM bgmDead = ::BASS_StreamCreateFile(FALSE, "res/music/hellback.mp3", 0, 0, BASS_SAMPLE_LOOP);

	//�Ƿ������ֲ���״̬
	HSTREAM m_currentBackgourndMusic = 0;


};

