﻿#pragma once
#include "Viewport.h"
#include "TileSet.h"
#include "GameDefine.h"
#include "InfoMap.h"
#include "OEnemy.h"
#include "OItem.h"
#include "OWall.h"


using namespace Define;

class Map
{
public:
	//tính theo tile
	int WidthMap, HeightMap;
	TileSet* tileset;
	D3DXVECTOR2 position;
	InfoMap *info;
	map<string, int> objectTag;
	vector <Object*> ListObject;

public:
	Map(int level = 1);
	~Map();

	Object* CreateObject(MapObject* _mapobject);

	void Render(Viewport * view);
};

