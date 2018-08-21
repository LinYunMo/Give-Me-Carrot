#pragma once

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
#include "ui\CocosGUI.h"
#include <vector>
#include "tinyxml2/tinyxml2.h"
//#include "SimpleAudioEngine.h"//������

//#include "CGameMenu.h"
//#include "CGameInfo.h"
#include "CGameLevel.h"
#include <bass.h>


using namespace std;
USING_NS_CC;
using namespace ui;
//using namespace CocosDenshion;//���������ռ�

class CGamePlayer:public Layer
{
public:
	CGamePlayer();
	~CGamePlayer();

	//����������������ײ
	//static CGamePlayer * Instance()
	//{
	//	static CGamePlayer RU;
	//	return &RU;
	//}

	void creatPlayer();


	

	virtual bool init();
	void updateAnimation(float dt);
	void update(float dt);

	//��Ҷ���
	int m_animationIndex = 0;//����֡����2��
	vector<SpriteFrame*> m_array_left;
	vector<SpriteFrame*> m_array_right;
	vector<SpriteFrame*> m_array_jump;
	vector<SpriteFrame*> m_array_climb;
	vector<SpriteFrame*> m_array_hurt;
	vector<SpriteFrame*> m_array_stand;

	//���״̬��
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

	//�������
	
	struct tagPlayer
	{
		Sprite* m_player;
		Vec2 pos;
		Vec2 speed, velocity;//ǰ��Ϊ�㶨�ٶȣ�����Ϊ�������ײ��ʵ���ٶ�
		int hp;
	};

	tagPlayer player;




	//���������֮ǰ������
	Vec2 m_perviousPosition;


	//��������ײ����Ϣ
	//struct tagCollision
	//{
	//	Sprite* collision;
	//	int id;
	//	int type;
	//	string name;
	//};
	//vector<CGameManager::tagCollision> m_collision;
	////������ײ��Ϣ�ĺ���
	//void loadCollision(string add1,char* add2);

	//��ײ��Ϣ�ṹ��
	struct area
	{
		Sprite* collision;
		int id;
		int type;
		string name;
	};
	vector<area> m_collision;

	//��ײ��������	�������ȷ�����Գ�����ţ��ⲿ��δ��룬����ʱ��������Ŵ��룿
	void collisions(float dt);

	//�˺�����ʱ��
	float godtime = 0;

	//���¼�����
	void door(int id);
	float cooltime = 0;//����ȴ���

	//ͼ�ƶ����ٶ�
	float speedCollision = 100.f;

	//Label *m_scoreText = nullptr;//�Ƿְ�
	int m_coin = 0;
	int m_carrots = 0;
	Text* m_cointext;
	Text* m_carrotstext;


	//UI��
	Node* m_ui;

	//�۲���  ��Ϊ�۲������� ??
	//CGameMenu *m_menuPlayer = nullptr;
	//CGameInfo *m_infoPlayer = nullptr;
	CGameLevel *m_levelPlayer_1 = nullptr;
	CGameLevel *m_levelPlayer_2 = nullptr;
	CGameLevel *m_levelPlayer = nullptr;
	CGameLevel *m_levelPlayer_3 = nullptr;

	//ѡ��۲��ߺ���
	void whichScene(int _num);
	int levelflag = 0;


	//�������¼�����
	void boardUp(int _num);
	float board = 0;


	//��ʼ��������
	HRESULT hResult = ::BASS_Init(-1, 44100, 0, NULL, NULL);
	//װ��һ�������ļ����ɹ�����һ��HSTREA�� ����
	HSTREAM coinmusic = ::BASS_StreamCreateFile(FALSE, "res/music/coin.wav", 0, 0, 0);
	HSTREAM hintmusic = ::BASS_StreamCreateFile(FALSE, "res/music/hint.wav", 0, 0, 0);
	HSTREAM jumpmusic = ::BASS_StreamCreateFile(FALSE, "res/music/jump.wav", 0, 0, 0);
	HSTREAM winmusic = ::BASS_StreamCreateFile(FALSE, "res/music/win.wav", 0, 0, 0);
	HSTREAM doormusic = ::BASS_StreamCreateFile(FALSE, "res/music/door.wav", 0, 0, 0);

	//�Ƿ������ֲ���״̬
	HSTREAM m_currentBackgourndMusic = 0;


};

