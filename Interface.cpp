#include "Interface.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <conio.h>
#include <string>
using namespace std;

void Interface::Change_Parse(string p_parse) {
	parse = p_parse;
}

void Interface::Main_Func() {
	cout << ".............................................." << endl;
	cout << "   ........................................   " << endl;
	cout << "      ..................................      " << endl;
	cout << "Select command" << endl;
	bool flag = true;
	int command;
	while (flag){
		cout << "1) New Field - create new field(not from file) press(1)" << endl;
		cout << "2) Load Field - create new field(from file) press(2)" << endl;
		cout << "3) Add Cloud - add new cloud press(3) " << endl;
		cout << "4)Search - start clustering press(4)" << endl;
		cout << "5)Finish work - press(0)" << endl;
		cout << "Command: ";
		cin >> command;
		string filename = "D:\\First need\\Desktop\\C++ projects\\clasterscurs\\";
		string ans_F;
		switch (command) {
		case 1:
			pole.Clean();
			cout << "Input amount of clouds" << endl;
			int amount;
			cin >> amount; 
			for (int i = 0; i < amount; ++i) {
				AddCluster();

			}
			break;
		case 2:
			pole.Clean();
			cout << "Input filename in project's directory(*.txt)" << endl;
			cin >> ans_F;
			filename = filename + ans_F;
			cout << filename;
			pole.FillFromFile(filename);
			break;
		case 3:
			AddCluster();
			break;

		case 4:
			if (!pole.Get_Points().empty()) {
				search.ChangeArrpoint(pole.Get_Points());
				search.Main_Func();
			}
			break;
		case 0:
			flag=false;
			cout << "      ..................................      " << endl;
			cout << "   ........................................   " << endl;
			cout << ".............................................." << endl;
			break;
		default:
			cout << "Wrong Command" << endl;
		}
	}
}
void Interface::AddCluster() {
	int n_points;
	string ans;
	double xcent, ycent, despx, despy;
	cout << "................................" << endl;
	cout << "Input number of points in cloud" << endl;
	cin >> n_points; // +
	cout << "Input coordinates of center(x y)" << endl;
	cin >> xcent >> ycent; //+
	cout << "Input dispersion (disx dis y)" << endl;
	cin >> despx >> despy; //+
	Oval cloud(n_points, xcent, ycent, despx, despy);
	cout << "Do you wan to rotate or move this cloud(y/n)" << endl;
	bool flag1 = true;
	cout << "Command: ";
	cin >> ans;
	while (flag1) {
		if (ans == "Y" || ans == "y") {
			vector<Point> points_rot;
			cout << "..................................." << endl;
			cout << "Cloud rotation and moving menu" << endl;
			cout << "1) Rotate Cloud Dec - rotate oval around origin press(1)" << endl;
			cout << "2) Rotate Cloud Center - rotate cloud around it's own center press(2)" << endl;
			cout << "3) Move Cloud X - move cloud by x-cord press(3)" << endl;
			cout << "4) Rotate Cloud Dec - rotate oval around origin press(4)" << endl;
			cout << "5) Close menu - press(0)" << endl;
			int command1;
			double degree, offset;
			cout << "Command: ";
			cin >> command1;
			switch (command1) {
			case 0:
				flag1 = false;
				break;
			case 1:
				cout << "Input degree of rotation around origin" << endl;
				cin >> degree;
				cloud.Rotatedecartcenter(degree);
				pole.AddOval(cloud);
				break;
			case 2:
				cout << "Input degree of rotation around center" << endl;
				cin >> degree;
				cloud.Rotatecenter(degree);
				pole.AddOval(cloud);
				break;
			case 3:
				cout << "Input axis X offset" << endl;
				cin >> offset;
				cloud.MoveX(offset);
				pole.AddOval(cloud);
				break;
			case 4:
				cout << "Input axis Y offset" << endl;
				cin >> offset;
				cloud.MoveY(offset);
				pole.AddOval(cloud);
				break;

			default:
				cout << "Wrong Command" << endl;
				break;
			}


		}
		else if (ans == "N" || ans == "n") {
			pole.AddOval(cloud);
			flag1 = false;
		}
		else {
			cout << "Wrong Command!" << endl;
			pole.AddOval(cloud);
			flag1 = false;
		}
	}
}