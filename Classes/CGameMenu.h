#pragma once


#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
//#include "ui\CocosGUI.h"

#include <vector>
#include "tinyxml2/tinyxml2.h"

using namespace cocos2d;
using namespace cocostudio;
//using namespace ui;
using namespace std;

//�ӳ�����Ϊ��
class CGameMenu :public Layer
{
public:
	CGameMenu();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();



	void exitgame(Ref* ref);//�������Ϳ�������



	//��������ײ����Ϣ
	struct tagCollision
	{
		Sprite* collision;
		int id;
		int type;
		string name;
	};
	vector<tagCollision> m_array_collision;
	
	//������ײ��Ϣ�ĺ���
	void loadCollision();


	//�۲���
	//CGamePlayer *m_playerMenu = nullptr;

	//����
	Node* rootNode;
	cocostudio::timeline::ActionTimeline* animate;
};
