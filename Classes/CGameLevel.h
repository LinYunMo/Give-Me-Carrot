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
	//void loadCollision();
	void loadCollision(int _num);

	//��ͼλ�ñ仯���ؼ�����ײ��Ϣ
	//void ReloadCollision();

	//����
	Node* rootNode;
	cocostudio::timeline::ActionTimeline* animate;

	void update(float dt);


	//��ʱ�������ƶ�����
	int dir = 1;
	int m_dir[50] = {1,1,-1,-1};
};