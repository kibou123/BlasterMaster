#pragma once
#include "AnimationSprite.h"

class Animation
{
public:
	float TimeCurrent;
	int delay, start, end, IndexPause;
	bool Pause;
	int Index = 0;

	AnimationSprite* animation;

	bool FlipFlag;  //Cờ lật

	RECT rect;//Hình cần vẽ
	D3DXVECTOR2 position; //vị trí vẽ
	D3DXVECTOR2 center; //vĩ trí vẽ trong rect
	D3DXVECTOR2 scale; // Vector tùy chỉnh kích thước
	D3DXVECTOR2 transform;
	float angle;	//góc quay theo độ

public:
	Animation(AnimationSprite* animation);
	~Animation();

	int GetIndex();
	void SetIndex(int index);

	int GetDelay();
	int GetStart();
	int GetEnd();

	void SetPause(bool pause);
	void SetPause(bool, int);

	D3DXVECTOR2 GetPosition();
	void SetPosition(D3DXVECTOR2 Position);

	void SetFlipFlag(bool flag);
	void Flip(bool flag);

	void Update();
	void NewAnimationByIndex(int index);
	void SetFrame(D3DXVECTOR2 Position, bool Flip, int Delay, int Start, int End);

	RECT GetRectByIndex(int index);
	InfoSprite::Infoframe GetCurrentFrameInfo();
	bool GetFlipFlag();
	D3DXVECTOR2 GunPos(int index);

	void Render(Viewport* viewport);
	void Render();
};
