#pragma once
#include "HashObject.h"
class ScatterObject :
	public HashObject
{
	
public:
	int status; //0-slobodan, 1-obrisan, 2-zauzet
	ScatterObject();
	ScatterObject(char* k, char* bK, char* bS, char* dat, unsigned int bV);
	ScatterObject(ScatterObject const& obj);
	ScatterObject& operator = (ScatterObject const& obj);
};

