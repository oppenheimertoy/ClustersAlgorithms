#pragma once

#include "Point.h"
#include <vector>

class Oval {
private:
	double xc; //���������� ������ ������
	double yc;
	int amount; //���������� �����
	double dspx;
	double dspy;
	std::vector <Point> vecp; // ��������� �����, ���������� ������
public:
	Oval(); // ��������� �����������
	Oval(int aparam, double xparam, double yparam, double dxparam, double dyparam); //  ����������� � �����������
	~Oval(); // ����������� 
	void operator = (const Oval& poval);
	void AddtoPointlist(std::vector<Point>& pvec);
	void Show(); // ����� ������ � �������
	

	// ..........................�������� �������������� ������ �����

	void Rotatecenter(double phix);// �������� ������ ������ ������ �����
	void Rotatedecartcenter(double phix); // �������� ������ ����� ������� ���������
	void MoveX(double dx); // ����� �� OX
	void MoveY(double dy); // ����� �� OY
	void PrittoFile();// ������ ������ ����� � ����(���������� �����, ����������� ���� ����� ������ � ������ ������)
	void AddToFile(); // ���������� ����� � �����
};
