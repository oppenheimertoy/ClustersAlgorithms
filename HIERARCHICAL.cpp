#include "HIERARCHICAL.h"
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iostream>

void HIERARCHICAL::PrintToFile_H() {
	std::ofstream f;
	f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\field.txt", std::ios::out);
	for (int i = 0; i < h_arrpoints.size(); ++i) {
		f << h_arrpoints[i].Givexcord() << '\t' << h_arrpoints[i].Giveycord() << '\t' << h_arrpoints[i].GiveLable() << std::endl;
	}
	f.close();
}

void HIERARCHICAL::MatrixFill() {
	for (int i = 0; i < h_arrpoints.size(); ++i) {
		h_matrix.push_back(std::vector<double>());
		for (int j = 0; j < h_arrpoints.size(); ++j) {
			h_matrix[i].push_back(h_arrpoints[i].Distance(h_arrpoints[j]));
		}
	}
}

void HIERARCHICAL::H_Init() {
	int lable = 1;
	for (int i = 0; i < h_arrpoints.size(); ++i) {
		h_arrpoints[i].Setlable(lable);
		lable++;
	}
}

void HIERARCHICAL::H_Search() {
	MatrixFill();
	H_Init();
	int clusters = h_arrpoints.size();
	while (clusters > num) {
		int min_d = 1000000;
		int minind1 = 0, minind2 = 0;
		for (int i = 0; i < h_arrpoints.size(); ++i) {
			for (int j = 0; j < h_arrpoints.size(); ++j) {
				if ((h_matrix[i][j] < min_d) && (h_matrix[i][j] > 0)) {
					min_d = h_matrix[i][j];
					minind1 = i;
					minind2 = j;
				}
			}
		}
		int actlable = std::min(h_arrpoints[minind1].GiveLable(), h_arrpoints[minind2].GiveLable());
		int oldlable = std::max(h_arrpoints[minind1].GiveLable(), h_arrpoints[minind2].GiveLable());
		for (int i = 0; i < h_arrpoints.size(); ++i) {
			if (h_arrpoints[i].GiveLable() == oldlable) {
				h_arrpoints[i].Setlable(actlable);
			}
		}
		DeleteClusters(actlable);
		clusters = AmountOfClusters();
	}
}

int HIERARCHICAL::AmountOfClusters() {
	int cnt = 0;
	std::vector<int> ppoints;
	for (int i = 0; i < h_arrpoints.size(); ++i) {
		ppoints.push_back(h_arrpoints[i].GiveLable());
	}
	std::sort(ppoints.begin(), ppoints.end());
	ppoints.erase(unique(ppoints.begin(), ppoints.end()), ppoints.end());
	cnt = ppoints.size();
	return cnt;
}

void HIERARCHICAL::DeleteClusters(int p_lable) {
	for (int i = 0; i < h_arrpoints.size(); ++i) {
		for (int j = 0; j < h_arrpoints.size(); ++j) {
			if (h_arrpoints[i].GiveLable() == p_lable && h_arrpoints[j].GiveLable() == p_lable) {
				h_matrix[i][j] = -1;
			}
		}
	}
}