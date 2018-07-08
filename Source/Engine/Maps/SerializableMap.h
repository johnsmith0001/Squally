#pragma once
#include <tinyxml2/tinyxml2.h>
#include <fstream>
#include <iostream>
#include "cocos2d.h"

#include "Resources.h"
#include "Engine/Maps/IObjectDeserializer.h"
#include "Engine/Maps/ILayerDeserializer.h"
#include "Engine/Maps/SerializableLayer.h"
#include "Engine/Maps/SerializableTileLayer.h"

using namespace cocos2d;

class SerializableMap : public Node
{
public:
	static SerializableMap* deserialize(std::string mapFileName, std::vector<ILayerDeserializer*>* layerDeserializers, std::vector<IObjectDeserializer*>* objectDeserializers);
	bool serialize();

	void appendLayer(SerializableLayer* layer);

	Size getMapSize();
	Size getMapUnitSize();
	Size getMapTileSize();

	bool isIsometric();
	bool isPlatformer();

	void hackerModeEnable();
	void hackerModeDisable();
	std::string getMapFileName();

protected:
	SerializableMap(std::string mapFileName, std::vector<SerializableLayer*>* layers, Size unitSize, Size tileSize, int orientation);
	~SerializableMap();

private:

	std::vector<SerializableLayer*>* serializableLayers;
	std::string levelMapFileName;
	int orientation;
	Size mapUnitSize;
	Size mapTileSize;

	static const int PLATFORMER_MAP_TYPE;
	static const int ISOMETRIC_MAP_TYPE;
};
