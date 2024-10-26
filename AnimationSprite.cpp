#include "AnimationSprite.h"

AnimationSprite::AnimationSprite(const char* pathInfo, const char* pathPNG):Sprite(pathPNG)
{
	_infoAnim = new InfoSprite(pathInfo);
	scale = D3DXVECTOR2(1, 1);
	position = D3DXVECTOR2(0, 0);
	FlipFlag = false;
	angle = 0;
}

AnimationSprite::AnimationSprite()
{
	scale = D3DXVECTOR2(1, 1);
	position = D3DXVECTOR2(0, 0);
	FlipFlag = false;
	angle = 0;
}

AnimationSprite::~AnimationSprite()
{
	delete _infoAnim;
}

void AnimationSprite::SetDataAnimation(DataAnimMap data)
{
	_dataAnim = data;
}