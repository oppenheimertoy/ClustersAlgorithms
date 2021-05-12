#pragma once

class Point {
private:
	double x; // ��������� �� (x,y)
	double y; 
	int fclast; // �������������� � ��������
public:
	Point(); // ����������� ��� ����������
	Point(double xparam, double yparam); // ����������� � ������������
	Point(double xparam, double yparam, int cparam); // ������������ �� ����� ������
	~Point(); // ���������� 
	Point(const Point& ppoint); // ���������� �����������
	void Setlable(int cparam); // ����� ��������� �������������� � ��������
	double RVector(); // ����� ����������� ���������� �� ������ ���������� �������� �� �����
	double Distance(const Point& ppoint); // ���������� �� ������ �����
	double Givexcord(); // ������� ���������� X
	double Giveycord(); // ������� ���������� Y
	int GiveLable(); // ������� ����� ��������
	void Accure(double pog1, double pog2); // ������ ���������� �� ����� �����
	void Accurex(double pog1);
	void Accurey(double pog2);
	void SetPoint(Point& ppoint);
	//void operator = (const Point& ppoint); // ���������������� ��������
};
