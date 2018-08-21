#include "CGameInfo.h"
#include "CGameManager.h"//以免交叉包含


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



	loadCollision();//加载碰撞资源
	//rootNode = CSLoader::createNode("GameInfo/GameInfo.csb");
	//animate = CSLoader::createTimeline("GameInfo/GameInfo.csb");//由于这里只加载一次，添加到转换地图处
	//animate->gotoFrameAndPlay(0);
	//rootNode->runAction(animate);


	//addChild(rootNode);

	return true;
}


void CGameInfo::loadCollision()
{
	rootNode = CSLoader::createNode("GameInfo/GameInfo.csb");
	addChild(rootNode);

	//分析xml
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