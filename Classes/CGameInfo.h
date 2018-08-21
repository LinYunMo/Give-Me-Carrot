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
	
	//分析能碰撞的信息
	struct tagCollision
	{
		Sprite* collision;
		int id;
		int type;
		string name;
	};
	vector<tagCollision> m_array_collision;

	//加载碰撞信息的函数
	void loadCollision();

	//对象
	Node* rootNode;
	cocostudio::timeline::ActionTimeline* animate;
};

