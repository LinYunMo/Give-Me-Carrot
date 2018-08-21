#pragma once

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
#include <vector>
#include "tinyxml2/tinyxml2.h"
//#include "SimpleAudioEngine.h"//声音库

//#include "CGameMenu.h"
//#include "CGameInfo.h"
#include "CGameLevel.h"
#include <bass.h>


using namespace std;
USING_NS_CC;
using namespace ui;
//using namespace CocosDenshion;//声音命名空间

class CGamePlayer:public Layer
{
public:
	CGamePlayer();
	~CGamePlayer();

	//单件，方便类间的碰撞
	//static CGamePlayer * Instance()
	//{
	//	static CGamePlayer RU;
	//	return &RU;
	//}

	void creatPlayer();


	

	virtual bool init();
	void updateAnimation(float dt);
	void update(float dt);

	//玩家动画
	int m_animationIndex = 0;//动画帧数（2）
	vector<SpriteFrame*> m_array_left;
	vector<SpriteFrame*> m_array_right;
	vector<SpriteFrame*> m_array_jump;
	vector<SpriteFrame*> m_array_climb;
	vector<SpriteFrame*> m_array_hurt;
	vector<SpriteFrame*> m_array_stand;

	//玩家状态机
	enum directType
	{
		Stand,
		Left,
		Right,
		Jump,
		Climb,
		Hurt
	};
	directType m_directType = Stand;

	//玩家属性
	
	struct tagPlayer
	{
		Sprite* m_player;
		Vec2 pos;
		Vec2 speed, velocity;//前者为恒定速度，后者为会跟随碰撞的实际速度
		int hp;
	};

	tagPlayer player;




	//备份玩家走之前的坐标
	Vec2 m_perviousPosition;


	//分析能碰撞的信息
	//struct tagCollision
	//{
	//	Sprite* collision;
	//	int id;
	//	int type;
	//	string name;
	//};
	//vector<CGameManager::tagCollision> m_collision;
	////加载碰撞信息的函数
	//void loadCollision(string add1,char* add2);

	//碰撞信息结构体
	struct area
	{
		Sprite* collision;
		int id;
		int type;
		string name;
	};
	vector<area> m_collision;

	//碰撞分析函数	参数如何确定？对场景编号？外部如何传入，创建时将场景编号传入？
	void collisions(float dt);

	//伤害免疫时间
	float godtime = 0;

	//门事件函数
	void door(int id);
	float cooltime = 0;//门冷却间隔

	//图移动的速度
	float speedCollision = 100.f;

	//Label *m_scoreText = nullptr;//记分板
	int m_coin = 0;
	int m_carrots = 0;
	Text* m_cointext;
	Text* m_carrotstext;


	//UI层
	Node* m_ui;

	//观察者  改为观察者数组 ??
	//CGameMenu *m_menuPlayer = nullptr;
	//CGameInfo *m_infoPlayer = nullptr;
	CGameLevel *m_levelPlayer_1 = nullptr;
	CGameLevel *m_levelPlayer_2 = nullptr;
	CGameLevel *m_levelPlayer = nullptr;
	CGameLevel *m_levelPlayer_3 = nullptr;

	//选择观察者函数
	void whichScene(int _num);
	int levelflag = 0;


	//弹跳版事件函数
	void boardUp(int _num);
	float board = 0;


	//初始化声音库
	HRESULT hResult = ::BASS_Init(-1, 44100, 0, NULL, NULL);
	//装载一个声音文件，成功返回一个HSTREA的 变量
	HSTREAM coinmusic = ::BASS_StreamCreateFile(FALSE, "res/music/coin.wav", 0, 0, 0);
	HSTREAM hintmusic = ::BASS_StreamCreateFile(FALSE, "res/music/hint.wav", 0, 0, 0);
	HSTREAM jumpmusic = ::BASS_StreamCreateFile(FALSE, "res/music/jump.wav", 0, 0, 0);
	HSTREAM winmusic = ::BASS_StreamCreateFile(FALSE, "res/music/win.wav", 0, 0, 0);
	HSTREAM doormusic = ::BASS_StreamCreateFile(FALSE, "res/music/door.wav", 0, 0, 0);

	//是否有音乐播放状态
	HSTREAM m_currentBackgourndMusic = 0;


};

