#include "Oval.h"
#include "Point.h"
#include "Field.h"
#include "DBSCAN.h"
#include "WAVE.h"
#include<iostream>
#include <fstream>

//#define eps 1e-15

using namespace std;

int main() {
	Field pole(0);
	pole.AddOval(500, -6, 4, 5, 12);
	pole.AddOval(600, 10, 10, 1, 3);
	pole.AddOval(100, 0.3, 0, 10, 3); 
	//pole.FillFromFile( "D:\\First need\\Desktop\\C++ projects\\clasterscurs\\ovaltest.txt");
	WAVE search(pole.Get_Points(),0.03); //5, 0.1
	//DBSCAN serch1(pole.Get_Points(),4, 0.00);

	//cout<<test[14].Givexcord();
	search.Init_WAVE();
	search.PrintToFile_W();
	return 0;
}