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

//从场景变为层
class CGameMenu :public Layer
{
public:
	CGameMenu();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();



	void exitgame(Ref* ref);//函数类型看定义中



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


	//观察者
	//CGamePlayer *m_playerMenu = nullptr;

	//对象
	Node* rootNode;
	cocostudio::timeline::ActionTimeline* animate;
};
