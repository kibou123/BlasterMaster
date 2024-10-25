﻿#pragma once
#include "Object.h"
#include "PlayerCollision.h"
#include "PlayerController.h"
using namespace Define;

class OBullet;
class Player : public Object
{
private:
	static Player* _player;
public:
	enum PlayerType
	{
		Blue = 100,
		Red = 200,
	} _playerType;

	PlayerController* _playerController;
	PlayerCollision* _playerCollision;
	int _life;
	bool isImmortal = false;
	float immortalTime = 0;

public:
	Player(); 
	~Player();
	void SetHP(int hp);

	void Init();
	void BeforeUpdate();
	void Update();
	void UpdateAnimation();
	D3DXVECTOR2 OnCollision(Object* obj, D3DXVECTOR2 side);
	void OnCollision(Object* obj);
	void SetImmortal(float time);
	void SetBound(float width, float height);
	void Render(Viewport* viewport);
	static Player* GetInstance();

	int GetIndexGun();
};
