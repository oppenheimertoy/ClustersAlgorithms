#include "WAVE.h"
#include <fstream>
#include <iostream>

void WAVET::FireNeighbours(int p_lable, int p_index) {
	int lable = p_lable;
	int index = p_index;
	if (w_arrpoints[p_index].GiveLable() == 0) {
		w_arrpoints[p_index].Setlable(lable);
		for (int j = 0; j < w_arrpoints.size(); ++j) {
			if (w_arrpoints[p_lable].Distance(w_arrpoints[j]) < w_eps && w_arrpoints[j].GiveLable() == 0) {
				p_index = j;
				FireNeighbours(lable, p_index);
			}
		}
	}
}
void WAVET::Init_WAVE() {
	int c_lab = 1;
	int index = 0;
	for (int i = 0; i < w_arrpoints.size(); ++i) {
		index = i;
		FireNeighbours(c_lab, index);
		c_lab++;
	}
	PrintToFile_W();
}
void WAVET::PrintToFile_W() {
	std::ofstream f;
	f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\wave.txt", std::ios::out);
	for (int i = 0; i < w_arrpoints.size(); ++i) {
		f << w_arrpoints[i].Givexcord() << '\t' << w_arrpoints[i].Giveycord() << '\t' << w_arrpoints[i].GiveLable() << std::endl;
	}
	f.close();
}

std::vector<Point> WAVET::Get_WAVE() {
	return w_arrpoints;
}

bool WAVET::CheckAllClusters() {
	int cnt = 0;
	for (int i = 0; i < w_arrpoints.size(); ++i) {
		if (w_arrpoints[i].GiveLable() == 0) {
			cnt++;
		}
	}
	if (cnt == 0) {
		return false;
	}
	else {
		return true;
	}
}
