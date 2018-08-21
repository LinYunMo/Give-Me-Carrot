#include "CGamePlayer.h"
#include "CGameManager.h"

#include <string>


CGamePlayer::CGamePlayer()
{
	init();
}


CGamePlayer::~CGamePlayer()
{
	//�ͷ�������
	::BASS_Free();
}


bool CGamePlayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	/*CGamePlayer::Instance()->*///loadCollision("GameMenu/GameMenu.csb", "res/GameMenu/collision.xml");
	creatPlayer();
	//createwatch();
	player.hp = 3;
	player.speed.x = 200.f;
	player.speed.y = 250.f;//�㶨�������ٶ�
	player.velocity.x = 0;
	player.velocity.y = 0;
	player.m_player = Sprite::create("GamePlayer/stand0.png");
	addChild(player.m_player);
	//player.m_player->setPosition(100, 600);

	//m_scoreText = Label::createWithTTF(":","fonts/Kenney Future.ttf", 40);
	//m_scoreText->setPosition(0, 650);
	//addChild(m_scoreText);
	////m_scoreText->setAnchorPoint(Vec2(0, 0));//���ı�ê��
	//char temp[20] = "";
	//sprintf(temp, ":%d",m_coin);
	//m_scoreText->setString(temp);
	//m_scoreText->setVisible(false);

	m_ui = CSLoader::createNode("GameStart/UI.csb");
	//addChild(m_ui);

	m_cointext = (Text*)m_ui->getChildByName("cointext");
	m_carrotstext = (Text*)m_ui->getChildByName("carrotstext");
	char temp[20] = "";
	sprintf(temp, ":%d", m_coin);
	m_cointext->setString(temp);
	char temp1[20] = "";
	sprintf(temp1, ":%d", m_carrots);
	m_carrotstext->setString(temp1);

	addChild(m_ui);
	m_ui->setVisible(false);

	//SimpleAudioEngine::getInstance()->preloadEffect("music/coin.wav");
	//SimpleAudioEngine::getInstance()->preloadEffect("music/hint.wav");
	//SimpleAudioEngine::getInstance()->preloadEffect("music/jump.wav");
	//SimpleAudioEngine::getInstance()->preloadEffect("music/win.wav");
	//SimpleAudioEngine::getInstance()->preloadEffect("music/door.wav");

	scheduleUpdate();
	schedule(schedule_selector(CGamePlayer::updateAnimation), 0.2f, kRepeatForever, 0.2f);

	return true;

}

//ѡ��۲��߶���
void CGamePlayer::whichScene(int _num)
{
	switch (_num)
	{
	case 1:
		m_levelPlayer = m_levelPlayer_1;
		levelflag = 1;
		break;
	case 2:
		m_levelPlayer = m_levelPlayer_2;
		levelflag = 2;
		break;
	case 3:
		m_levelPlayer = m_levelPlayer_3;
		levelflag = 3;
		break;
	}
}

//����֡����
void CGamePlayer::updateAnimation(float dt)
{
	switch (m_directType)
	{
	case Stand:
		player.m_player->setSpriteFrame(m_array_stand[m_animationIndex]);
		break;
	case Jump:
		player.m_player->setSpriteFrame(m_array_jump[m_animationIndex]);
		break;
	case Climb:
		player.m_player->setSpriteFrame(m_array_climb[m_animationIndex]);
		break;
	case Right:
		player.m_player->setSpriteFrame(m_array_right[m_animationIndex]);
		break;
	case Left:
		player.m_player->setSpriteFrame(m_array_left[m_animationIndex]);
		break;
	case Hurt:
		player.m_player->setSpriteFrame(m_array_hurt[m_animationIndex]);
		break;
	}
	if (m_animationIndex == 1)
	{
		m_animationIndex = -1;
	}
	m_animationIndex++;
}

//����֡���ض���
void CGamePlayer::creatPlayer()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GamePlayer/gameplayer.plist");
	for (int i = 0; i < 2; i++)
	{
		char temp[128] = "";
		sprintf(temp, "stand%d.png", i);
		SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);
		m_array_stand.push_back(sf);
	}
	for (int i = 0; i < 2; i++)
	{
		char temp[128] = "";
		sprintf(temp, "jump%d.png", i);
		SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);
		m_array_jump.push_back(sf);
	}
	for (int i = 0; i < 2; i++)
	{
		char temp[128] = "";
		sprintf(temp, "climb%d.png", i);
		SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);
		m_array_climb.push_back(sf);
	}
	for (int i = 0; i < 2; i++)
	{
		char temp[128] = "";
		sprintf(temp, "walkright%d.png", i);
		SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);
		m_array_right.push_back(sf);
	}
	for (int i = 0; i < 2; i++)
	{
		char temp[128] = "";
		sprintf(temp, "walkleft%d.png", i);
		SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);
		m_array_left.push_back(sf);
	}
	for (int i = 0; i < 2; i++)
	{
		char temp[128] = "";
		sprintf(temp, "hurt%d.png", i);
		SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);
		m_array_hurt.push_back(sf);
	}
}

//�ź���
void CGamePlayer::door(int id)
{
	if (cooltime>1.f)
	{
		//����Ч
		//SimpleAudioEngine::getInstance()->playEffect("music/door.wav");
		BASS_ChannelPlay(doormusic, true);
		cooltime = 0;
		switch (id)
		{
		case 101://�˳�
			exit(1);
			break;
		case 102://Info
			CGameManager::Instance()->intoGameInfo();
			break;
		case 103://Start
			CGameManager::Instance()->intoGameLevel1();
			break;
		case 104://Menu
			CGameManager::Instance()->intoGameMenu();
			break;
		case 105://Restart
			switch (levelflag)
			{
			case 1:
				//CGameManager::Instance()->removeChild(CGameManager::Instance()->m_level1);
				CGameManager::Instance()->intoGameLevel1();
				break;
			case 2:
				//CGameManager::Instance()->removeChild(CGameManager::Instance()->m_level2);
				CGameManager::Instance()->intoGameLevel2();
				break;
			case 3:
				//CGameManager::Instance()->removeChild(CGameManager::Instance()->m_level2);
				CGameManager::Instance()->intoGameLevel3();
				break;
			default:
				break;
			}
			((Sprite*)m_ui->getChildByName("lifes_1"))->setVisible(true);
			((Sprite*)m_ui->getChildByName("lifes_2"))->setVisible(true);
			((Sprite*)m_ui->getChildByName("lifes_3"))->setVisible(true);
			break;
		case 111://��һ�� ��һ����
			//�������л��ؿ�
			//CGameManager::Instance()->intoGameLevel2();
			player.m_player->setPositionX(m_collision[1].collision->getPositionX());
			player.m_player->setPositionY(m_collision[1].collision->getPositionY());
			break;
		case 112://��һ�� �ڶ�����
			player.m_player->setPositionX(m_collision[0].collision->getPositionX());
			player.m_player->setPositionY(m_collision[0].collision->getPositionY());
			break;
		case 113://level2
			CGameManager::Instance()->intoGameLevel2();
			break;
		case 121://�ڶ��� ��һ����
			player.m_player->setPositionX(m_collision[3].collision->getPositionX());
			player.m_player->setPositionY(m_collision[3].collision->getPositionY());
			break;
		case 122://�ڶ��� �ڶ�����
			player.m_player->setPositionX(m_collision[2].collision->getPositionX());
			player.m_player->setPositionY(m_collision[2].collision->getPositionY());
			break;
		case 123://level3
			CGameManager::Instance()->intoGameLevel3();
			break;
		default:
			break;
		}
	}
}


//�����溯��
void CGamePlayer::boardUp(int _num)
{
	board = 0;
	m_collision[_num].collision->getPositionX();
	player.m_player->setPositionX(m_collision[_num].collision->getPositionX());
	player.m_player->setPositionY(m_collision[_num].collision->getPositionY() + 80);
	float x = 0, y = 0;
	switch (m_collision[_num].id)
	{
	case 621://�ڶ�������һ
		x = m_collision[_num].collision->getPositionX() + 450;
		y = player.m_player->getPositionY() + 230; 
		break;
	case 622://�ڶ��������
		x = m_collision[_num].collision->getPositionX() - 300;
		y = player.m_player->getPositionY() + 210;
		break;
	case 623://�ڶ���������
		x = m_collision[_num].collision->getPositionX() + 355;
		y = player.m_player->getPositionY() + 250;
		break;
	case 624://�ڶ���������
		x = m_collision[_num].collision->getPositionX() - 300;
		y = player.m_player->getPositionY() + 210;
		break;
	case 631://����������һ
		x = m_collision[_num].collision->getPositionX() - 200;
		y = player.m_player->getPositionY() + 260;
		break;
	default:
		break;
	}
	auto Jump = JumpTo::create(0.5f, Vec2(x,y), 150, 1);
	player.m_player->runAction(Jump);
	//������Ч
	//SimpleAudioEngine::getInstance()->playEffect("music/jump.wav");
	BASS_ChannelPlay(jumpmusic, true);
}


//vector<CGameManager::tagCollision> m_collision;

void CGamePlayer::update(float dt)
{
	if (dt > 0.05f) dt = 0.05f;
	m_perviousPosition = player.m_player->getPosition();
	auto posy = player.m_player->getPositionY();
	//����ģ��//����Ӱ�����µ�ʵ���ٶ�
	player.velocity.y = -player.speed.y;

	if (GetAsyncKeyState('W') && posy > 120 && posy < 600)//ͬ�����ü��̰�����������Ϊ������һ��Ϊ��д
	{
		for (unsigned int i = 0; i < m_collision.size(); i++)
		{
			if (m_collision[i].collision->getBoundingBox().intersectsRect(player.m_player->getBoundingBox())) {
				if (m_collision[i].type == 2)
				{
					player.velocity.y = 100.f;
					Rect ry = player.m_player->getBoundingBox(); ry.origin.y += player.velocity.y * dt;
				}
				if (m_collision[i].type == 1)
				{
					door(m_collision[i].id);
				}
			}
		}
	}
	else if (GetAsyncKeyState('W') && posy >= 600)
	{
		for (unsigned int i = 0; i < m_collision.size(); i++)
		{
			if (m_collision[i].collision->getBoundingBox().intersectsRect(player.m_player->getBoundingBox())) {
				if (m_collision[i].type == 2)
				{
					player.velocity.y = 0;
					speedCollision = 100.f;
					//Rect ry = player.m_player->getBoundingBox(); ry.origin.y += player.velocity.y * dt;
					//auto scenePos = m_levelPlayer->rootNode->getPositionY();

					//�˴�����������ķ������ᵼ���ƶ����Σ������ϰ������о��Ǿ������
					//scenePos -= player.velocity.y*dt;
					//m_levelPlayer->rootNode->setPositionY(scenePos);

					//�����ˣ����겻��//Խ�������Խ�󣿣����ѵ����ϰ�����Ϣ�͸��ڵ���Ϣ��ͬ����
					//����
					//���������ڲ����ϰ������Ա�����Ϊ��̬������//����ƶ��������������
					for (unsigned int i = 0; i < m_levelPlayer->m_array_collision.size(); i++)
					{
						auto collPos = m_levelPlayer->m_array_collision[i].collision->getPositionY();
						collPos -= speedCollision * dt;
						m_levelPlayer->m_array_collision[i].collision->setPositionY(collPos);
					}
					//��θ�����ײ��Ϣ
					//m_levelPlayer->ReloadCollision();
					m_collision.clear();
					for (unsigned int i = 0; i < m_levelPlayer->m_array_collision.size(); i++)
					{
						CGamePlayer::area door;
						door.collision = m_levelPlayer->m_array_collision[i].collision;
						door.id = m_levelPlayer->m_array_collision[i].id;
						door.type = m_levelPlayer->m_array_collision[i].type;
						m_collision.push_back(door);
					}
				}
			}
		}
	}
	if (posy < 120)
	{
		player.velocity.y = 250.f;
		//speedCollision = 250.f;

		//�����ˣ����겻��//Խ�������Խ�󣿣����ѵ����ϰ�����Ϣ�͸��ڵ���Ϣ��ͬ����
		//����
		//���������ڲ����ϰ������Ա�����Ϊ��̬������//����ƶ��������������
		for (unsigned int i = 0; i < m_levelPlayer->m_array_collision.size(); i++)
		{
			auto collPos = m_levelPlayer->m_array_collision[i].collision->getPositionY();
			collPos += player.velocity.y*dt;
			m_levelPlayer->m_array_collision[i].collision->setPositionY(collPos);
		}
		//��θ�����ײ��Ϣ
		//m_levelPlayer->ReloadCollision();
		m_collision.clear();
		for (unsigned int i = 0; i < m_levelPlayer->m_array_collision.size(); i++)
		{
			CGamePlayer::area door;
			door.collision = m_levelPlayer->m_array_collision[i].collision;
			door.id = m_levelPlayer->m_array_collision[i].id;
			door.type = m_levelPlayer->m_array_collision[i].type;
			m_collision.push_back(door);
		}

	}
	if (GetAsyncKeyState(0x20))
	{
		cocos2d::log("kongge");
		//auto Jump = JumpTo::create(5, Vec2(120,200), 50, 1);
		//player.m_player->runAction(Jump);
	}
	if (GetAsyncKeyState('A'))//ͬ�����ü��̰�����������Ϊ������һ��Ϊ��д
	{
		//����Ӱ�����ʵ�ʵ��ٶȣ�������λ��
		player.velocity.x = -player.speed.x;
		m_directType = Left;
	}
	else if (GetAsyncKeyState('D'))//ͬ�����ü��̰�����������Ϊ������һ��Ϊ��д
	{
		player.velocity.x = player.speed.x;
		m_directType = Right;
	}
	else
	{
		player.velocity.x = 0;
		m_directType = Stand;
	}



	godtime += dt;//����˺�����޵�ʱ��
	cooltime += dt;//�ŵ���ȴʱ��
	board += dt;//������ʱ��

	collisions(dt);

	//���վ������λ�ƵĲ���
	player.m_player->setPosition(player.m_player->getPosition() + player.velocity * dt);



	if ((player.m_player->getPositionX() + player.m_player->getContentSize().width / 2) >= 1280 ||
		(player.m_player->getPositionX() - player.m_player->getContentSize().width / 2) <= 0)
	{
		player.m_player->setPosition(m_perviousPosition);
	}

}


void CGamePlayer::collisions(float dt)
{
	Rect rx = player.m_player->getBoundingBox(), ry = rx;
	//�˵�����
	rx.origin.x += player.velocity.x * dt;//�ı����꣬��ʵ���ٶ�
	ry.origin.y += player.velocity.y * dt;
	for (unsigned int i = 0; i < m_collision.size(); i++)
	{
		bool cx = m_collision[i].collision->getBoundingBox().intersectsRect(rx);//ʶ��������Ƿ���ײX����
		bool cy = m_collision[i].collision->getBoundingBox().intersectsRect(ry);//ʶ��������Ƿ���ײY����
		if (cx || cy)//ֻҪ����ײ����ʼ�ж�
		{
			switch (m_collision[i].type)
			{
			case 0://��ײ
				if (cx) player.velocity.x = 0;//X���������ײ����x�����ٶ���Ϊ0
				if (cy) player.velocity.y = 0;//Y���������ײ����y�����ٶ���Ϊ0
				break;
			case 1:
				break;
			case 2:
				m_directType = Climb;
				break;
			case 3://��ײ���˺���//��ʱ�����޵�
			{
				int where = 1;
				if (m_directType == Left)	where = 1;
				if (m_directType == Right)	where = -1;
				if (godtime>=3.f)
				{
					m_directType = Hurt;
					char templife[20] = "";
					sprintf(templife, "lifes_%d", player.hp);
					((Sprite*)m_ui->getChildByName(templife))->setVisible(false);
					player.hp--;
					godtime = 0;
					if (player.hp == 0)
					{
						player.hp = 3;
						/*switch (levelflag)
						{
						case 1:
							CGameManager::Instance()->removeChild(CGameManager::Instance()->m_level1);
							CGameManager::Instance()->intoGameLevel1();
							break;
						case 2:
							CGameManager::Instance()->removeChild(CGameManager::Instance()->m_level2);
							CGameManager::Instance()->intoGameLevel2();
							break;
						default:
							break;
						}*/


						//�޵У�������
						CGameManager::Instance()->intoGameDead();


						//((Sprite*)m_ui->getChildByName("lifes_1"))->setVisible(true);
						//((Sprite*)m_ui->getChildByName("lifes_2"))->setVisible(true);
						//((Sprite*)m_ui->getChildByName("lifes_3"))->setVisible(true);
						//player.m_player->setPosition(100, 200);
						break;
						//CGameManager::Instance()->intoGameLevel();
					}
				}
				//auto Jump = JumpTo::create(2, Vec2(player.m_player->getPositionX() - 20,
				//	player.m_player->getPositionY() + 20), 20, 1);
				//player.m_player->runAction(Jump);
				//player.velocity.x = 0;
				//player.velocity.y = 0;
				player.m_player->setPositionX(m_perviousPosition.x + 5 * where);
				player.m_player->setPositionY(m_perviousPosition.y + 5);
				auto Jump = JumpTo::create(0.5f, Vec2(player.m_player->getPositionX() + 30 * where,
					player.m_player->getPositionY() + 70), 20, 1);
				player.m_player->runAction(Jump);
				//������Ч
				//SimpleAudioEngine::getInstance()->playEffect("music/hint.wav");
				BASS_ChannelPlay(hintmusic, true);
			}
			break;
			case 4://�����ȡ��ͬ���˺�ģʽ
			{	int where = 1;
				if (m_directType == Left)	where = 1;
				if (m_directType == Right)	where = -1;
				if (godtime >= 3.f)
				{
					m_directType = Hurt;
					char templife[20] = "";
					sprintf(templife, "lifes_%d", player.hp);
					((Sprite*)m_ui->getChildByName(templife))->setVisible(false);
					player.hp--;
					godtime = 0;
					player.m_player->setPositionX(m_perviousPosition.x + 5 * where);
					player.m_player->setPositionY(m_perviousPosition.y + 5);
					auto Jump = JumpTo::create(0.5f, Vec2(player.m_player->getPositionX() + 30 * where,
						player.m_player->getPositionY() + 70), 20, 1);
					player.m_player->runAction(Jump);
					//������Ч
					//SimpleAudioEngine::getInstance()->playEffect("music/hint.wav");
					BASS_ChannelPlay(hintmusic, true);
					if (player.hp == 0)
					{
						player.hp = 3;
						//������Ч
						//SimpleAudioEngine::getInstance()->playEffect("music/death.wav");
						//�޵У�������
						CGameManager::Instance()->intoGameDead();
						break;
					}
				}
			}
				break;
			//case 4://�����¼���������
			//	cocos2d::log("peng");
			//	break;
			case 5://ʰȡ�¼�
				if (m_levelPlayer->m_array_collision[i].collision->isVisible())
				{
					//�����Ч
					//SimpleAudioEngine::getInstance()->playEffect("music/coin.wav");					
					
					BASS_ChannelPlay(coinmusic, true);
					
					m_levelPlayer->m_array_collision[i].collision->setVisible(false);
					m_collision[i].collision->setVisible(false);
					switch (m_levelPlayer->m_array_collision[i].id)
					{
					case 501:
						{m_coin++;
						char temp[20] = "";
						sprintf(temp, ":%d", m_coin);
						m_cointext->setString(temp); }
					break;
					case 502:
						{m_carrots++;
						char temp1[20] = "";
						sprintf(temp1, ":%d", m_carrots);
						m_carrotstext->setString(temp1);
						if (m_carrots >= 5)
							{/*SimpleAudioEngine::getInstance()->playEffect("music/win.wav");*/
								BASS_ChannelPlay(winmusic, true);
							}
						}
					break;
					default:
						break;
					}
				}
				break;
			case 6://�������¼�
				m_directType = Jump;
				if (board>1)
				{
					boardUp(i);
				}
				break;
			default:
				break;
			}
		}
	}
}

//void CGamePlayer::loadCollision(string add1, char* add2)
//{
//	auto rootNode = CSLoader::createNode(add1);
//	auto animate = CSLoader::createTimeline(add1);
//	animate->gotoFrameAndPlay(0);
//	rootNode->runAction(animate);
//	addChild(rootNode);
//
//	//����xml
//	tinyxml2::XMLDocument doc;
//	if (doc.LoadFile(add2))
//	{
//		MessageBox("WARNING", "Collision XML");
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
//
//	/*creatPlayer();
//	player.hp = 3;
//	player.speed.x = 100.f;
//	player.speed.y = 0.f;
//	player.dir = -1;
//	player.m_player = Sprite::create("GamePlayer/stand0.png");
//	addChild(player.m_player);
//	player.m_player->setPosition(100, 200);
//
//	scheduleUpdate();
//	schedule(schedule_selector(CGamePlayer::updateAnimation), 0.2f, kRepeatForever, 0.2f);*/
//
//}