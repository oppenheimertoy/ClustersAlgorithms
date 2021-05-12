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
	bool flag = true;
	string command;
	while (flag){
		cout << "Select command" << endl;
		cout << "1) New Field - create new field(not from file) press(1)" << endl;
		cout << "2) Load Field - create new field(from file) press(2)" << endl;
		cout << "3) Add Cloud - add new cloud press(3) " << endl;
		cout << "4) Search - start clustering press(4)" << endl;
		cout << "5) Finish work - press(0)" << endl;
		cout << "Command: ";
		int action;
		cin >> command;
		while (!try_stoi(action, command)) {
			cout << "Wrong Command!" << endl;
			cin >> command;
		}
		string filename = "D:\\First need\\Desktop\\C++ projects\\clasterscurs\\";
		string ans_F;
		switch (action) {
		case 1:
			pole.Clean();
			cout << "Input amount of clouds" << endl;
			int amount;
			cin >> ans_F;
			while (!try_stoi(amount, ans_F)) {
				cout << "Wrong Command!" << endl;
				cin >> ans_F;
			}
			if (amount < 0) {
				amount *= (-1);
			}
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
	cin >> ans;
	while (!try_stoi(n_points, ans)) {
		cout << "Wrong Command!" << endl;
		cin >> ans;
	}
	if (n_points < 0) {
		n_points *= (-1);
	}
	cout << "Input coordinates of center(x y)" << endl;
	cout << "Input x" << endl;
	cin >> ans;
	while (!try_stod(xcent, ans)) {
		cout << "Wrong Command!" << endl;
		cin >> ans;
	}
	cout << "Input y" << endl;
	cin >> ans;
	while (!try_stod(ycent, ans)) {
		cout << "Wrong Command!" << endl;
		cin >> ans;
	}
	cout << "Input disx" << endl;
	cin >> ans;
	while (!try_stod(despx, ans)) {
		cout << "Wrong Command!" << endl;
		cin >> ans;
	}
	if (despx < 0) {
		despx *= (-1);
	}
	cout << "Input disy" << endl;
	cin >> ans;
	while (!try_stod(despy, ans)) {
		cout << "Wrong Command!" << endl;
		cin >> ans;
	}
	if (despy < 0) {
		despy *= (-1);
	}
	Oval cloud(n_points, xcent, ycent, despx, despy);
	cout << "Do you want to rotate or move this cloud(y/n)" << endl;
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
			string ans1;
			cout << "Command: ";
			cin >> ans1;
			while (!try_stoi(command1, ans1)) {
				cout << "Wrong Command!" << endl;
				cin >> ans1;
			}
			switch (command1) {
			case 0:
				flag1 = false;
				break;
			case 1:
				cout << "Input degree of rotation around origin" << endl;
				cin >> ans1;
				while (!try_stod(degree, ans1)) {
					cout << "Wrong Command!" << endl;
					cin >> ans1;
				}
				cloud.Rotatedecartcenter(degree);
				pole.AddOval(cloud);
				break;
			case 2:
				cout << "Input degree of rotation around center" << endl;
				cin >> ans1;
				while (!try_stod(degree, ans1)) {
					cout << "Wrong Command!" << endl;
					cin >> ans1;
				}
				cloud.Rotatecenter(degree);
				pole.AddOval(cloud);
				break;
			case 3:
				cout << "Input axis X offset" << endl;
				cin >> ans1;
				while (!try_stod(offset, ans1)) {
					cout << "Wrong Command!" << endl;
					cin >> ans1;
				}
				cloud.MoveX(offset);
				pole.AddOval(cloud);
				break;
			case 4:
				cout << "Input axis Y offset" << endl;
				cin >> ans1;
				while (!try_stod(offset, ans1)) {
					cout << "Wrong Command!" << endl;
					cin >> ans1;
				}
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

bool Interface::try_stoi(int& i, const string& s) {
	try {
		size_t pos;
		i = stoi(s, &pos);
		return pos == s.size();
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

bool Interface::try_stod(double& i, const string& s) {
	try {
		size_t pos;
		i = stod(s, &pos);
		return pos == s.size();
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}