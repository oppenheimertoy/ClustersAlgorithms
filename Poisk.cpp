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
}

void Poisk::S_HIERARCHICAL(int p_num) {
	HIERARCHICAL search(p_num, arrpoint);
	search.H_Search();
	search.PrintToFile_H();
}

void Poisk::S_WAVE(double p_eps) {
	WAVE search(arrpoint, p_eps);
	search.Init_WAVE();
	search.PrintToFile_W();
}

void Poisk::CleanLables() {
	for (int i = 0; i < arrpoint.size(); ++i) {
		arrpoint[i].Setlable(0);
	}
}

void Poisk::OpenGNUplot() {
	string command;
	FILE* pipe = _popen("C:\\gnuplot\\bin\\gnuplot.exe", "w");
	if (pipe != NULL)
	{
		fprintf(pipe, "cd 'D:\\First need\\Desktop\\C++ projects\\clasterscurs'\n");
		//fprintf(pipe, "set terminal wxt persist\n");
		fprintf(pipe, "plot(\"field.txt\") with points palette pointsize 2 pointtype 7\n");
		fflush(pipe);
		fprintf(pipe, "pause 10\n");
		//system("pause");
		fprintf(pipe, "exit\n");
	
	}
	else puts("Could not open the file\n");
	_pclose(pipe);
	

}

void Poisk::Main_Func() {
	int action;
	bool flag = true;
	cout << "Finish clustering(0)" << endl;
	cout << "Start DBSCAN search(1)" << endl;
	cout << "Start Hierarchical search(2)" << endl;
	cout << "Start Wave search(3)" << endl;
	cout << "Show result(4)" << endl;

	while (flag) {
		cout << "Choose an action:" << endl;
		cin >> action;
		switch (action) {
		case 0:
			flag = false;
			break;
		case 1:
			cout << "Input Minpts(int): " << endl;
			cin >> p_Minpts;
			cout << "Input eps(double): " << endl;
			cin >> p_eps;
			S_DBSCAN(p_Minpts, p_eps);
			OpenGNUplot();
			break;
		case 2:
			cout << "Input final amount of clusters(int)" << endl;
			cin >> p_num;
			S_HIERARCHICAL(p_num);
			break;
		case 3:
			cout << "Input eps(int)" << endl;
			cin >> p_eps;
			S_WAVE(p_eps);
			break;
		default:
			cout << "Sorry, wrong input" << endl;
			break;
		}
		CleanLables();
	}
}
