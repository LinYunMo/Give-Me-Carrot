#include "CGamePlayer.h"
#include "CGameManager.h"

#include <string>


CGamePlayer::CGamePlayer()
{
	init();
}


CGamePlayer::~CGamePlayer()
{
	//释放声音库
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
	player.speed.y = 250.f;//恒定的重力速度
	player.velocity.x = 0;
	player.velocity.y = 0;
	player.m_player = Sprite::create("GamePlayer/stand0.png");
	addChild(player.m_player);
	//player.m_player->setPosition(100, 600);

	//m_scoreText = Label::createWithTTF(":","fonts/Kenney Future.ttf", 40);
	//m_scoreText->setPosition(0, 650);
	//addChild(m_scoreText);
	////m_scoreText->setAnchorPoint(Vec2(0, 0));//改文本锚点
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

//选择观察者对象
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

//精灵帧动画
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

//精灵帧加载动画
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

//门函数
void CGamePlayer::door(int id)
{
	if (cooltime>1.f)
	{
		//门音效
		//SimpleAudioEngine::getInstance()->playEffect("music/door.wav");
		BASS_ChannelPlay(doormusic, true);
		cooltime = 0;
		switch (id)
		{
		case 101://退出
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
		case 111://第一对 第一个门
			//测试用切换关卡
			//CGameManager::Instance()->intoGameLevel2();
			player.m_player->setPositionX(m_collision[1].collision->getPositionX());
			player.m_player->setPositionY(m_collision[1].collision->getPositionY());
			break;
		case 112://第一对 第二个门
			player.m_player->setPositionX(m_collision[0].collision->getPositionX());
			player.m_player->setPositionY(m_collision[0].collision->getPositionY());
			break;
		case 113://level2
			CGameManager::Instance()->intoGameLevel2();
			break;
		case 121://第二对 第一个门
			player.m_player->setPositionX(m_collision[3].collision->getPositionX());
			player.m_player->setPositionY(m_collision[3].collision->getPositionY());
			break;
		case 122://第二对 第二个门
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


//弹跳版函数
void CGamePlayer::boardUp(int _num)
{
	board = 0;
	m_collision[_num].collision->getPositionX();
	player.m_player->setPositionX(m_collision[_num].collision->getPositionX());
	player.m_player->setPositionY(m_collision[_num].collision->getPositionY() + 80);
	float x = 0, y = 0;
	switch (m_collision[_num].id)
	{
	case 621://第二关跳板一
		x = m_collision[_num].collision->getPositionX() + 450;
		y = player.m_player->getPositionY() + 230; 
		break;
	case 622://第二关跳板二
		x = m_collision[_num].collision->getPositionX() - 300;
		y = player.m_player->getPositionY() + 210;
		break;
	case 623://第二关跳板三
		x = m_collision[_num].collision->getPositionX() + 355;
		y = player.m_player->getPositionY() + 250;
		break;
	case 624://第二关跳板四
		x = m_collision[_num].collision->getPositionX() - 300;
		y = player.m_player->getPositionY() + 210;
		break;
	case 631://第三关跳板一
		x = m_collision[_num].collision->getPositionX() - 200;
		y = player.m_player->getPositionY() + 260;
		break;
	default:
		break;
	}
	auto Jump = JumpTo::create(0.5f, Vec2(x,y), 150, 1);
	player.m_player->runAction(Jump);
	//弹跳音效
	//SimpleAudioEngine::getInstance()->playEffect("music/jump.wav");
	BASS_ChannelPlay(jumpmusic, true);
}


//vector<CGameManager::tagCollision> m_collision;

void CGamePlayer::update(float dt)
{
	if (dt > 0.05f) dt = 0.05f;
	m_perviousPosition = player.m_player->getPosition();
	auto posy = player.m_player->getPositionY();
	//重力模拟//重力影响向下的实际速度
	player.velocity.y = -player.speed.y;

	if (GetAsyncKeyState('W') && posy > 120 && posy < 600)//同步调用键盘按键，括号中为按键，一定为大写
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

					//此处不可用下面的方法，会导致移动两次，本身障碍数组中就是精灵对象
					//scenePos -= player.velocity.y*dt;
					//m_levelPlayer->rootNode->setPositionY(scenePos);

					//更新了，坐标不对//越向上误差越大？？？难道是障碍物信息和根节点信息不同步？
					//可行
					//但背景由于不是障碍数组成员，会成为静态，需解决//如果移动到上限则该正常
					for (unsigned int i = 0; i < m_levelPlayer->m_array_collision.size(); i++)
					{
						auto collPos = m_levelPlayer->m_array_collision[i].collision->getPositionY();
						collPos -= speedCollision * dt;
						m_levelPlayer->m_array_collision[i].collision->setPositionY(collPos);
					}
					//如何更新碰撞信息
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

		//更新了，坐标不对//越向上误差越大？？？难道是障碍物信息和根节点信息不同步？
		//可行
		//但背景由于不是障碍数组成员，会成为静态，需解决//如果移动到上限则该正常
		for (unsigned int i = 0; i < m_levelPlayer->m_array_collision.size(); i++)
		{
			auto collPos = m_levelPlayer->m_array_collision[i].collision->getPositionY();
			collPos += player.velocity.y*dt;
			m_levelPlayer->m_array_collision[i].collision->setPositionY(collPos);
		}
		//如何更新碰撞信息
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
	if (GetAsyncKeyState('A'))//同步调用键盘按键，括号中为按键，一定为大写
	{
		//输入影响的是实际的速度，不决定位移
		player.velocity.x = -player.speed.x;
		m_directType = Left;
	}
	else if (GetAsyncKeyState('D'))//同步调用键盘按键，括号中为按键，一定为大写
	{
		player.velocity.x = player.speed.x;
		m_directType = Right;
	}
	else
	{
		player.velocity.x = 0;
		m_directType = Stand;
	}



	godtime += dt;//造成伤害后的无敌时间
	cooltime += dt;//门的冷却时间
	board += dt;//弹跳板时间

	collisions(dt);

	//最终决定玩家位移的操作
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
	//菜单场景
	rx.origin.x += player.velocity.x * dt;//改变坐标，以实际速度
	ry.origin.y += player.velocity.y * dt;
	for (unsigned int i = 0; i < m_collision.size(); i++)
	{
		bool cx = m_collision[i].collision->getBoundingBox().intersectsRect(rx);//识别与玩家是否碰撞X方向
		bool cy = m_collision[i].collision->getBoundingBox().intersectsRect(ry);//识别与玩家是否碰撞Y方向
		if (cx || cy)//只要有碰撞，则开始判断
		{
			switch (m_collision[i].type)
			{
			case 0://碰撞
				if (cx) player.velocity.x = 0;//X方向存在碰撞，则x方向速度置为0
				if (cy) player.velocity.y = 0;//Y方向存在碰撞，则y方向速度置为0
				break;
			case 1:
				break;
			case 2:
				m_directType = Climb;
				break;
			case 3://碰撞到伤害物//短时间内无敌
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


						//无敌，测试用
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
				//受伤音效
				//SimpleAudioEngine::getInstance()->playEffect("music/hint.wav");
				BASS_ChannelPlay(hintmusic, true);
			}
			break;
			case 4://怪物采取相同的伤害模式
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
					//受伤音效
					//SimpleAudioEngine::getInstance()->playEffect("music/hint.wav");
					BASS_ChannelPlay(hintmusic, true);
					if (player.hp == 0)
					{
						player.hp = 3;
						//死亡音效
						//SimpleAudioEngine::getInstance()->playEffect("music/death.wav");
						//无敌，测试用
						CGameManager::Instance()->intoGameDead();
						break;
					}
				}
			}
				break;
			//case 4://怪物事件，待完善
			//	cocos2d::log("peng");
			//	break;
			case 5://拾取事件
				if (m_levelPlayer->m_array_collision[i].collision->isVisible())
				{
					//金币音效
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
			case 6://弹跳版事件
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
//	//分析xml
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