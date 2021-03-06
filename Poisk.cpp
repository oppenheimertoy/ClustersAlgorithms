#include "Poisk.h"
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

void Poisk::ChangeNum(int c_num) {
	p_num = c_num;
}

void Poisk::ChangeEps(double c_eps) {
	p_eps = c_eps;
}

void Poisk::ChangeMinpts(int c_Minpts) {
	p_Minpts = c_Minpts;
}

void Poisk::S_DBSCAN(int Minpts, double eps) {
	DBSCAN search(arrpoint, Minpts, eps);
	search.Init_DBSCAN();
	search.PrintToFile_D();
	arrpoint = search.Get_DBS();
}

void Poisk::S_HIERARCHICAL(int p_num) {
	HIERARCHICAL search(p_num, arrpoint);
	search.H_Search();
	search.PrintToFile_H();
	arrpoint = search.Get_Hierarc();
}

void Poisk::S_WAVE(double p_eps) {
	WAVET search(arrpoint, p_eps);
	search.Init_WAVE();
	search.PrintToFile_W();
	arrpoint = search.Get_WAVE();
}

void Poisk::CleanLables() {
	for (int i = 0; i < arrpoint.size(); ++i) {
		arrpoint[i].Setlable(0);
	}
}

void Poisk::OpenGNUplot() {
	string amclust = to_string(AmountOFClusters());
	string ampoints = to_string(arrpoint.size());
	string command_str = "set title \"Amount of clusters = ";
	string command_str1 = "\" font \"Times New Roman, 10\"\n";
	string command_str2 = "; Amount of points = ";
	amclust = command_str + amclust + command_str2 + ampoints + command_str1;
	FILE* pipe = _popen("C:\\gnuplot\\bin\\gnuplot.exe", "w");
	if (pipe != NULL)
	{
		fprintf(pipe, "cd 'D:\\First need\\Desktop\\C++ projects\\clasterscurs'\n");
		fprintf(pipe, "set style line 1 lc rgb 'red'\n");
		fprintf(pipe, "set style line 2 lc rgb 'blue'\n");
		fprintf(pipe, "set style line 3 lc rgb 'green'\n");
		fprintf(pipe, "set style line 4 lc rgb 'magenta'\n");
		fprintf(pipe, "set style line 5 lc rgb 'yellow'\n");
		fprintf(pipe, "set style line 6 lc rgb 'cyan'\n");
		fprintf(pipe, "set style line 7 lc rgb '#80ff80'\n");
		fprintf(pipe, "set style line 8 lc rgb '#00ffff'\n");
		fprintf(pipe, "set style line 9 lc rgb '#0080ff'\n");
		fprintf(pipe, "set style line 10 lc rgb '#0000ff'\n");
		fprintf(pipe, "set style line 11 lc rgb '#000080'\n");
		fprintf(pipe, "set style line 12 lc rgb '#bf00bf'\n");
		fprintf(pipe, "%s\n", amclust.c_str());
		fprintf(pipe, "%s\n", amclust.c_str());
		fprintf(pipe, "set style data points\n");
		fprintf(pipe, "plot 'field.txt' using 1:2:3 linecolor variable pt 7 ps 2 t ''\n");
		fflush(pipe);
		fprintf(pipe, "pause 15\n");
		fprintf(pipe, "exit\n");
	}
	else puts("Could not open the file\n");
	_pclose(pipe);
}

void Poisk::Main_Func() {
	int action;
	bool flag = true;
	string ans;
	cout << "Finish clustering(0)" << endl;
	cout << "Start DBSCAN search(1)" << endl;
	cout << "Start Hierarchical search(2)" << endl;
	cout << "Start Wave search(3)" << endl;
	cout << "Show result(4)" << endl;

	while (flag) {
		cout << "Choose an action:" << endl;
		cin >> ans;
		while (!try_stoi(action, ans)) {
			cout << "Wrong Command!" << endl;
			cin >> ans;
		}
		switch (action) {
		case 0:
			flag = false;
			break;
		case 1:
			cout << "Input Minpts(int): " << endl;
			cin >> ans;
			while (!try_stoi(p_Minpts, ans)) {
				cout << "Wrong Command!" << endl;
				cin >> ans;
			}
			if (p_Minpts < 0) {
				p_Minpts *= (-1);
			}
			cout << "Input eps(double): " << endl;
			cin >> ans;
			while (!try_stod(p_eps, ans)) {
				cout << "Wrong Command!" << endl;
				cin >> ans;
			}
			if (p_eps < 0) {
				p_eps = p_eps*(-1);
			}
			S_DBSCAN(p_Minpts, p_eps);
			OpenGNUplot();

			break;
		case 2:
			cout << "Input final amount of clusters(int)" << endl;
			cin >> ans;
			while (!try_stoi(p_num, ans)) {
				cout << "Wrong Command!" << endl;
				cin >> ans;
			}
			if (p_num < 0) {
				p_num *= (-1);
			}
			S_HIERARCHICAL(p_num);
			OpenGNUplot();
			break;
		case 3:
			cout << "Input eps(int)" << endl;
			cin >> ans;
			while (!try_stod(p_eps, ans)) {
				cout << "Wrong Command!" << endl;
				cin >> ans;
			}
			if (p_eps < 0) {
				p_eps = p_eps * (-1);
			}
			S_WAVE(p_eps);
			OpenGNUplot();
			break;
		default:
			cout << "Sorry, wrong input" << endl;
			break;
		}
		CleanLables();
	}
}

int Poisk::AmountOFClusters() {
	int counter = 0;
	std::vector<int> ppoints;
	for (int i = 0; i < arrpoint.size(); ++i) {
		ppoints.push_back(arrpoint[i].GiveLable());
	}
	std::sort(ppoints.begin(), ppoints.end());
	ppoints.erase(unique(ppoints.begin(), ppoints.end()), ppoints.end());
	counter = ppoints.size();
	return counter;
}

void Poisk::ChangeArrpoint(std::vector<Point> c_arrpoint) {
	arrpoint = c_arrpoint;
}

bool Poisk::try_stod(double& i, const string& s) {
	try {
		size_t pos;
		i = stod(s, &pos);
		return pos == s.size();
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

bool Poisk::try_stoi(int& i, const string& s) {
	try {
		size_t pos;
		i = stoi(s, &pos);
		return pos == s.size();
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}