#include "CGameInfo.h"
#include "CGameManager.h"//���⽻�����


CGameInfo::CGameInfo()
{
	init();
}


CGameInfo::~CGameInfo()
{
}


bool CGameInfo::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}



	loadCollision();//������ײ��Դ
	//rootNode = CSLoader::createNode("GameInfo/GameInfo.csb");
	//animate = CSLoader::createTimeline("GameInfo/GameInfo.csb");//��������ֻ����һ�Σ���ӵ�ת����ͼ��
	//animate->gotoFrameAndPlay(0);
	//rootNode->runAction(animate);


	//addChild(rootNode);

	return true;
}


void CGameInfo::loadCollision()
{
	rootNode = CSLoader::createNode("GameInfo/GameInfo.csb");
	addChild(rootNode);

	//����xml
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("res/GameInfo/collision.xml"))
	{
		MessageBox("WARNING", "GameInfo Collision XML");
	}

	tinyxml2::XMLElement *root = doc.FirstChildElement("COLLISION");
	tinyxml2::XMLElement *ele = root->FirstChildElement("ELEMENTS");

	for (; ele != nullptr; ele = ele->NextSiblingElement())
	{
		tagCollision collision;
		collision.collision = (Sprite*)rootNode->getChildByName(ele->Attribute("name"));
		collision.type = atoi(ele->Attribute("type"));
		collision.id = atoi(ele->Attribute("id"));
		collision.name = ele->Attribute("name");
		m_array_collision.push_back(collision);
	}
}