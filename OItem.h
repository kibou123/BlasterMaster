﻿#include "Object.h"
#include "GameDefine.h"
#include "Collision.h"

using namespace Define;

class OItem : public Object
{
public:
	bool isImmortal = false;
	float immortalTime = 0;
public:
	enum ItemType
	{
		R = 100,
		M = 200,
		S = 300,
		F = 400,
		L = 500,
		BulletBoss = 700,
	} _itemType = ItemType::M;

	OItem();
	~OItem();

	void Init(D3DXVECTOR2 pos, int type = ItemType::M, int kind = 0);
	void BeforeUpdate();
	void Update();
	void UpdateAnimation();
	void Controller();
	D3DXVECTOR2 OnCollision(Object* obj, D3DXVECTOR2 side);
	void OnCollision(Object* obj);
	void SetBound(float width, float height);
	void Render(Viewport* viewport);

	static AnimationSprite* _animationItem;
	static AnimationSprite* AnimationItem();
};
