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


class CGameLevel:public Layer
{
public:
	//CGameLevel();
	CGameLevel(int _num);

	//virtual bool init();
	virtual bool init(int _num);

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
	//void loadCollision();
	void loadCollision(int _num);

	//地图位置变化后重加载碰撞信息
	//void ReloadCollision();

	//对象
	Node* rootNode;
	cocostudio::timeline::ActionTimeline* animate;

	void update(float dt);


	//临时，怪物移动方向
	int dir = 1;
	int m_dir[50] = {1,1,-1,-1};
};