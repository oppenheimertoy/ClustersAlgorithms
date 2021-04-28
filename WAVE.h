#pragma once
#include <vector>
#include <cmath>
#include "Point.h"
#include "Field.h"

class WAVE {
private:
	std::vector<Point> w_arrpoints;
	std::vector<Point> w_ans;
	std::vector<std::vector<int>> w_matrix;
	double w_eps;
public:
	~WAVE(){
		w_arrpoints.resize(0);
		w_matrix.resize(0);
		w_ans.resize(0);
	};
	WAVE(std::vector<Point> p_arrpoints, double p_eps) {
		w_arrpoints = p_arrpoints;
		w_matrix.resize(0);
		w_ans.resize(0);
		w_eps = p_eps;
	}
	void MatrixFill();
	void AddCluster();
	void FireNeighbours(int index, int lable);
	void Changelb(Point ppoint, int lab);
	void Init_WAVE();
	void PrintToFile_W();
	std::vector<Point> Get_WAVE();
	void Delete(Point ppoint);


};