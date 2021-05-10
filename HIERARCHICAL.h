#pragma once

#include <vector>
#include <cmath>
#include "Point.h"
#include "Field.h"

class HIERARCHICAL {
private:
	int num; // final amount of clusters
	std::vector<Point> h_arrpoints;
	std::vector<std::vector<double>> h_matrix;
public:
	HIERARCHICAL(int p_num, std::vector<Point> p_arrpoints) {
		num = p_num;
		h_arrpoints = p_arrpoints;
		h_matrix.resize(0);
	}
	~HIERARCHICAL() {
		h_arrpoints.resize(0);
		h_matrix.resize(0);
	}
	void MatrixFill();
	void PrintToFile_H();
	void H_Init();
	void H_Search();
	int AmountOfClusters();
	void DeleteClusters(int p_lable);
	std::vector<Point> Get_Hierarc();
};