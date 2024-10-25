#include "SceneManager.h"

SceneManager* SceneManager::_sceneManager;
SceneManager* SceneManager::GetInstance()
{
	if (nullptr == _sceneManager) {
		_sceneManager = new SceneManager();
	}
	return _sceneManager;
}

SceneManager::SceneManager()
{
	isEnd = false;
	endTime = 0;
}
SceneManager::~SceneManager()
{
	delete sprite;
}

//Load Data Game
void SceneManager::InitDT()
{
	sceneType = Intro;
	sprite = new Sprite("./Resource Files/intro.png");
}
void SceneManager::Map(int level)
{
	isEnd = true;
	sceneType = Wait;
	timedelay = 0;
	this->level = level;
}
//Update các scene game Update lớn nhất
void SceneManager::Update()
{
	if (Keyboard::GetInstance()->IsKeyDown(DIK_1))
	{
		Map();
	}

	RECT rect;
	rect.left = sceneType * GameWidth;
	rect.top = 0;
	rect.right = rect.left + GameWidth;
	rect.bottom = GameHeight;
	sprite->SetRect(rect);
	sprite->SetPosition(D3DXVECTOR2(0, 0));

	timedelay += GameTime;
	float posx = GameWidth;
	switch (sceneType)
	{
	case SceneManager::Intro:
		isEnd = false;
		//Reset
		if (timedelay > 5 && timedelay < 10)
		{
			timedelay = 0.0f;
		}
		//chạy từ phải qua
		if (Keyboard::GetInstance()->IsKeyDown(Dik_START) && timedelay > 0.2 && timedelay < 2.1)
		{
			timedelay = 2.1f;
		}

		posx -= timedelay*(GameWidth/2);
		posx = posx <= 0 ? 0 : posx;
		sprite->SetPosition(D3DXVECTOR2(posx, 0));
		//
		if (Keyboard::GetInstance()->IsKeyDown(Dik_START) && timedelay > 2.2)
		{
			timedelay = 10.0f;
		}

		if (timedelay > 11)
		{
			Map();
		}

		if (timedelay > 10 && timedelay < 11 && (timedelay/2) && (((int)(timedelay / 0.05)) % 2 == 1))
		{
			rect.top = GameHeight;
			rect.bottom = GameHeight*2;
			sprite->SetRect(rect);
		}
		break;
	case SceneManager::Wait:
		if (isEnd)
		{
			isEnd = false;
			ObjectManager::GetInstance()->InitDT(level);
		}
		if (((int)(timedelay / 0.2)) % 2 == 1)
		{
			rect.top = GameHeight;
			rect.bottom = GameHeight * 2;
			sprite->SetRect(rect);
		}
		if (timedelay > 3)
		{
			sceneType = Play;
			Player::GetInstance()->_life = StartLive;
			//Player::GetInstance()->Init();
		}
		break;
	case SceneManager::Play:
		ObjectManager::GetInstance()->Update();
		if (Player::GetInstance()->_life <= 0 && timedelay > 3)
		{
			timedelay = 0.0f;
		}
		else
		{
			rect.right = rect.left + 8 + Player::GetInstance()->_life * 13;
			rect.bottom = 25;
			sprite->SetRect(rect);
		}
		if (timedelay > 2 && timedelay < 3)
		{
			sceneType = End;
		}
		break;
	case SceneManager::End:
		if (((int)(timedelay / 0.2)) % 2 == 1)
		{
			rect.top = GameHeight;
			rect.bottom = GameHeight * 2;
			sprite->SetRect(rect);
		}
		if (Keyboard::GetInstance()->IsKeyDown(Dik_START) && timedelay > 1)
		{
			sceneType = Intro;
			timedelay = 0.0f;
		}
		break;
	default:
		break;
	}
}

void SceneManager::StartEnd(float time)
{
	ObjectManager::GetInstance()->StartPause(time);
	isEnd = true;
	endTime = time;
}

//Vẽ Object lên màn hình
void SceneManager::Render()
{
	if (sceneType == Play)
	{
		ObjectManager::GetInstance()->Render();
	}
	sprite->Render();
}