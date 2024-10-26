#pragma once
#include "Sprite.h"
#include "InfoSprite.h"
#include "map"
#include "debug.h"


class AnimationSprite : public Sprite
{
public:
	struct DataAnim{
		int start, end, delay = 100 , state;
	};
	typedef map<int, DataAnim> DataAnimMap;

public:
	InfoSprite* _infoAnim;
	DataAnimMap _dataAnim;

public:
	AnimationSprite(const char* pathInfo, const char* pathPNG);
	AnimationSprite();
	~AnimationSprite();

	void SetDataAnimation(DataAnimMap dataAnim);
};
