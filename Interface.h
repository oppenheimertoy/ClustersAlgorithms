#pragma once
#include "Oval.h"
#include "Point.h"
#include "Field.h"
#include "DBSCAN.h"
#include "WAVE.h"
#include "HIERARCHICAL.h"
#include "Poisk.h"
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

class Interface {
private:
	Field pole;
	Poisk search;
	string parse;
public:
	Interface(): parse("Init") {
	};
	~Interface() {};
	void Change_Parse(string p_parse);
	void Main_Func();
};

