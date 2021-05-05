#include "WAVE.h"
#include <fstream>
#include <iostream>

void WAVE::Changelb(Point ppoint, int lab) {
	int ind2 = 0;
	int indcore2 = 0;
	std::vector<Point>::iterator it_core2;
	for (it_core2 = w_arrpoints.begin(); it_core2 != w_arrpoints.end(); ++it_core2) {
		if (it_core2->Givexcord() == ppoint.Givexcord() && it_core2->Giveycord() == ppoint.Giveycord())
		{
			indcore2 = ind2;
		}
		++ind2;
		w_arrpoints[indcore2].Setlable(lab);
	}
}

void WAVE::MatrixFill() {
	for (int i = 0; i < w_arrpoints.size(); ++i) {
		w_matrix.push_back(std::vector<int>());
		for (int j = 0; j < w_arrpoints.size(); ++j) {
			if (w_arrpoints[i].Distance(w_arrpoints[j])<=w_eps){
				w_matrix[i].push_back(1);
			}
			else {
				w_matrix[i].push_back(0);
			}
		}
	}
}

void WAVE::Delete(Point ppoint) {
	int ind2 = 0;
	int indcore2 = 0;
	std::vector<Point>::iterator it_core2;
	for (it_core2 = w_arrpoints.begin(); it_core2 != w_arrpoints.end(); ++it_core2) {
		if (it_core2->Givexcord() == ppoint.Givexcord() && it_core2->Giveycord() == ppoint.Giveycord())
		{
			indcore2 = ind2;
		}
		++ind2;
	}
	w_arrpoints.erase(w_arrpoints.begin() + indcore2);

}

void WAVE::AddCluster() {
	static int Lable = 1;
	std::vector<Point> perem = w_arrpoints;
	for (int i = 0; i < w_arrpoints.size(); ++i) {
		if (perem[i].GiveLable() != 0) {
			perem[i].Setlable(Lable);
			w_ans.push_back(perem[i]);
			Delete(perem[i]);
			
		}
	}
	Lable++;
}

void WAVE::FireNeighbours(int index, int p_lable) {
	int lable = p_lable;
	int p_index = index;
	w_arrpoints[index].Setlable(lable);
	lable += 1;
	for (int j = 0; j < w_arrpoints.size(); ++j) {
		if (w_matrix[index][j] == 1) {
			if (w_arrpoints[j].GiveLable() == 0) {
				FireNeighbours(j,lable);
			}
		}
	}
}
void WAVE::Init_WAVE() {
	while (!w_arrpoints.empty()) {// нужна функция для определения пустоты вектора, удалять элементы из него нельзя, поэтому будем считать количество элементов с меткой -1
		w_matrix.resize(0);
		MatrixFill();
		for (int i = 0; i < w_arrpoints.size(); ++i) {
			w_arrpoints[i].Setlable(0);
		}
		FireNeighbours(0, 1);
		AddCluster();
	}
}
void WAVE::PrintToFile_W() {
	std::ofstream f;
	f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\field.txt", std::ios::out);
	for (int i = 0; i < w_ans.size(); ++i) {
		f << w_ans[i].Givexcord() << '\t' << w_ans[i].Giveycord() << '\t' << w_ans[i].GiveLable() << std::endl;
	}
	f.close();
}

std::vector<Point> WAVE::Get_WAVE() {
	return w_ans;
}
