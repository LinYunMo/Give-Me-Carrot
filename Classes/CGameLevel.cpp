#include "CGameLevel.h"



//CGameLevel::CGameLevel()
//{
//	init();
//}

CGameLevel::CGameLevel(int _num)
{
	init(_num);
}

//bool CGameLevel::init()
//{
//
//	if (!Layer::init())
//	{
//		return false;
//	}
//
//	loadCollision();//加载碰撞资源
//	//rootNode = CSLoader::createNode("GameStart/level_1.csb");
//
//	//addChild(rootNode);
//	scheduleUpdate();
//	return true;
//}

bool CGameLevel::init(int _num)
{

	if (!Layer::init())
	{
		return false;
	}

	loadCollision(_num);//加载碰撞资源
					//rootNode = CSLoader::createNode("GameStart/level_1.csb");

					//addChild(rootNode);
	scheduleUpdate();
	return true;
}

//void CGameLevel::loadCollision()
//{
//	rootNode = CSLoader::createNode("GameStart/level_1.csb");
//	addChild(rootNode);
//
//	//分析xml
//	tinyxml2::XMLDocument doc;
//	if (doc.LoadFile("res/GameStart/collision_1.xml"))
//	{
//		MessageBox("WARNING", "Level_1 Collision XML");
//	}
//	
//	tinyxml2::XMLElement *root = doc.FirstChildElement("COLLISION");
//	tinyxml2::XMLElement *ele = root->FirstChildElement("ELEMENTS");
//
//	for (; ele != nullptr; ele = ele->NextSiblingElement())
//	{
//		tagCollision collision;
//		collision.collision = (Sprite*)rootNode->getChildByName(ele->Attribute("name"));
//		collision.type = atoi(ele->Attribute("type"));
//		collision.id = atoi(ele->Attribute("id"));
//		collision.name = ele->Attribute("name");
//		m_array_collision.push_back(collision);
//	}
//}

void CGameLevel::loadCollision(int _num)
{
	char temp1[128] = "";
	sprintf(temp1, "GameStart/level_%d.csb", _num);
	rootNode = CSLoader::createNode(temp1);
	addChild(rootNode);

	//分析xml
	char temp2[128] = "";
	sprintf(temp2, "res/GameStart/collision_%d.xml", _num);
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(temp2))
	{
		MessageBox("WARNING", "Level Collision XML");
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

void CGameLevel::update(float dt)
{
	for (unsigned int i = 0; i < m_array_collision.size(); i++)
	{
		if (m_array_collision[i].type == 4)
		{
			
			switch (m_array_collision[i].id)
			{
			case 411:
				{
				auto enempos = m_array_collision[i].collision->getPositionX();
				if (enempos > 780)  m_dir[0] = -1;
				if (enempos < 480)  m_dir[0] = 1;
				enempos += 30 * dt * m_dir[0];
				m_array_collision[i].collision->setPositionX(enempos); }
				break;
			case 421:
				{
				auto enempos = m_array_collision[i].collision->getPositionX();
				if (enempos > 1150)	m_dir[1] = -1;
				if (enempos < 32)	m_dir[1] = 1;
				enempos += 70 * dt * m_dir[1];
				m_array_collision[i].collision->setPositionX(enempos);}
				break;
			case 422:
				{
				auto enempos = m_array_collision[i].collision->getPositionX();
				if (enempos > 1150)	m_dir[2] = -1;
				if (enempos < 32)	m_dir[2] = 1;
				enempos += 70 * dt * m_dir[2];
				m_array_collision[i].collision->setPositionX(enempos); }
				break;
			case 423:
				{
				auto enempos = m_array_collision[i].collision->getPositionX();
				if (enempos > 1175)	m_dir[3] = -1;
				if (enempos < 870)	m_dir[3] = 1;
				enempos += 50 * dt * m_dir[3];
				m_array_collision[i].collision->setPositionX(enempos); }
				break;
			default:
				break;
			}
		}
	}
}




