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
	cout << ".................................................." << endl;
	cout << "Please enter \"Help\" to get help or enter command" << endl;
	while (parse != "Finish work"){
		getline(cin, parse);// здесь должна быть проверка ввода
		if (parse == "Help") {
			Print_Help();
		}
		else if (parse == "New Field") {
			cout << "Input amount of clouds" << endl;
			string ans = "Finish work";
			int amount;
			cin >> amount; // проверка
			for (int i = 0; i < amount; ++i) {
				int n_points;
				double xcent, ycent, despx, despy;
				cout << "................................" << endl;
				cout << "Input number of points in cloud" << endl;
				cin >> n_points; // +
				cout << "Input coordinates of center(x y)" << endl;
				cin >> xcent >> ycent; //+
				cout << "Input dispersion (disx dis y)" << endl;
				cin >> despx >> despy; //+
				pole.AddOval(n_points, xcent, ycent, despx, despy);
				cout << "Do you wan to rotate or move this cloud(y/n)" << endl;
				bool flag = true;
				while (flag) {
					getline(cin, ans);
					if (ans == "Y" || ans=="y") {
						cout << "..................................." << endl;
						cout << "Cloud rotation and moving menu" << endl;
						cout << "Please input command(Rotate Cloud Dec and etc.)" << endl;
						Rotation_and_Move(n_points, xcent, ycent, despx, despy);
						flag=false;
						parse = "Finish rm";

					}
					else if (ans == "N" || ans == "n") {
						flag = false;
						parse = "Finish rm";
					}
					else {
						cout << "Wrong Command!" << endl;
					}
				}

			}
		}
		else if (parse == "Load Field") {
			string filename;
			cout << "Input filename";
			getline(cin, parse);
			pole.FillFromFile(filename);
		}
		else if (parse == "Search") {
			if (!pole.Get_Points().empty() != 0) {
				search.ChangeArrpoint(pole.Get_Points());
				search.Main_Func();
				parse == "Finish Search";
			}
		}
		else if (parse == "Finish rm") {
			cout << "You finished configured clouds" << endl;
		}
		else if (parse == "Finish work"){
			cout << "Goodbye" << endl;
		}
		else {
			cout << "Wrong Command!" << endl;
		}
	}
}

void Interface::Print_Help() {
	std::ifstream f;
	string line;
	f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\help.txt", std::ios::out);
	while (getline(f,line)) {
		cout<<line<<endl;
	}
	f.close();
}

void Interface::Rotation_and_Move(int aparam, double xparam, double yparam, double dxparam, double dyparam) {
	string command;
	vector<Point> points_rot;
	while (command != "Finish rm") {
		getline(cin, command);// здесь должна быть проверка ввода
		if (command == "Help") {
			Print_Help();
		}
		else if (command == "Rotate Cloud Dec") {
			cout << "Input degree of rotation around origin" << endl;
			string ans;
			double degree;
			cin >> degree; // проверка
			Oval cloud(aparam, xparam, yparam, dxparam, dyparam);
			cloud.Rotatedecartcenter(degree);
			points_rot = cloud.Get_Oval();
		}
		else if (command == "Rotate Cloud Center") {
			cout << "Input degree of rotation around center" << endl;
			string ans;
			double degree;
			cin >> degree; // проверка
			Oval cloud(aparam, xparam, yparam, dxparam, dyparam);
			cloud.Rotatecenter(degree);
			points_rot = cloud.Get_Oval();
		}
		else if (command == "Move Cloud X") {
			cout << "Input axis X offset" << endl;
			string ans;
			double offset;
			cin >> offset; // проверка
			Oval cloud(aparam, xparam, yparam, dxparam, dyparam);
			cloud.MoveX(offset);
			points_rot = cloud.Get_Oval();
		}
		else if (command == "Move Cloud Y") {
			cout << "Input axis Y offset" << endl;
			string ans;
			double offset;
			cin >> offset; // проверка
			Oval cloud(aparam, xparam, yparam, dxparam, dyparam);
			cloud.MoveY(offset);
			points_rot = cloud.Get_Oval();
		}
		else {
			cout << "Wrong Command!" << endl;
		}
	}
	pole.Changeend(points_rot, aparam);
}
