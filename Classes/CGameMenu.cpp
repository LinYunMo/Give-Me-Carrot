#include "CGameMenu.h"
//#include "CGameManager.h"//以免交叉包含



//层类
CGameMenu::CGameMenu()
{
	init();
}


bool CGameMenu::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}



	loadCollision();//加载碰撞资源
	rootNode = CSLoader::createNode("GameMenu/GameMenu.csb");
	//animate = CSLoader::createTimeline("GameMenu/GameMenu.csb");
	//animate->gotoFrameAndPlay(0);
	//rootNode->runAction(animate);


	addChild(rootNode);

	

	//按钮事件，用UI实现//由于返回值为一个节点node，所以要转成widget* 类型(为所有控件的基类，里面有鼠标点击事件函数)
	//auto button = (Widget*)rootNode->getChildByName("BottonNode");
	//auto exitbutton = (Widget*)rootNode->getChildByName("ExitButton");
	//exitbutton->addClickEventListener(CC_CALLBACK_1(CGameMenu::exitgame, this));

	//auto startbutton = (Widget*)rootNode->getChildByName("StartButton");
	//startbutton->addClickEventListener(CC_CALLBACK_1(CGameMenu::startGame, this));

	return true;
}

void CGameMenu::exitgame(Ref * ref)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}



//类型都归为manger里的结构体
//vector<CGameManager::tagCollision> m_array_collision;

void CGameMenu::loadCollision()
{
	auto rootNode = CSLoader::createNode("GameMenu/GameMenu.csb");
	addChild(rootNode);

	//分析xml
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("res/GameMenu/collision.xml"))
	{
		MessageBox("WARNING", "GameMenu Collision XML");
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

