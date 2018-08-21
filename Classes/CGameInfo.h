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


class CGameInfo:public Layer
{
public:
	CGameInfo();
	~CGameInfo();

	virtual bool init();
	
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

	//����
	Node* rootNode;
	cocostudio::timeline::ActionTimeline* animate;
};

