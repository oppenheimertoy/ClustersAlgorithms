#include "Oval.h"

#include<random>
#include<ctime>
#include<iostream>
#include<fstream>

const double pi = 3.141592653589793;

Oval::Oval() :xc(0), yc(0), dspx(0), dspy(0), amount(0) {

}

Oval::~Oval() {
    vecp.resize(0);
}

Oval::Oval(int aparam, double xparam, double yparam, double dxparam, double dyparam)
    : xc(xparam), yc(yparam), dspx(dxparam), dspy(dyparam), amount(aparam)
{
    double sumx = 0, sumy = 0, accurx = 0, accury = 0, xpog = 0, ypog = 0;
    if (amount)
    {
        srand(time(NULL));
        for (int i = 0; i < amount; ++i)
        {
            for (int j = 0; j < 1001; ++j)
            {
                sumx += (rand() % 10001 - 5000) * 0.0001;
                sumy += (rand() % 10001 - 5000) * 0.0001;
            }
            vecp.push_back(Point(xc + dspx * sumx / 1001, yc + dspy * sumy / 1001));
            sumx = sumy = 0;
            accurx += vecp[i].Givexcord();
            accury += vecp[i].Giveycord();
        }
        accurx = accurx / amount;
        accury = accury / amount;
        xpog = xc - accurx;
        ypog = yc - accury;
        for (int i = 0; i < amount; ++i) {
            vecp[i].Accure(xpog, ypog);
        }
    }
}

void Oval::Show() {
    for (int i = 0; i < vecp.size(); ++i) {
        std::cout << vecp[i].Givexcord() << " " << vecp[i].Giveycord() << vecp[i].GiveLable()<< std::endl;
    }
}
void Oval::operator = (const Oval& poval) {
    xc = poval.xc;
    yc = poval.yc;
    dspx = poval.dspx;
    dspy = poval.dspy;
    vecp = poval.vecp;
}

void Oval::Rotatecenter(double phix) {
    phix = phix * (180 / pi);
    double x1, y1, x2, y2;
    for (int i = 0; i < vecp.size(); ++i) {
        x1 = vecp[i].Givexcord();
        y1 = vecp[i].Giveycord();
        x2 = ((x1 - xc) * cos(phix)) + ((y1 - yc) * sin(phix)) + xc;
        y2 = ((x1 - xc) * sin(phix)) - ((y1 - yc) * cos(phix)) + yc;
        vecp[i] = Point(x2, y2);
    }
}

void Oval::Rotatedecartcenter(double phix) {
    phix = phix * (180 / pi);
    double x1, y1, x2, y2;
    for (int i = 0; i < vecp.size(); ++i) {
        x1 = vecp[i].Givexcord();
        y1 = vecp[i].Giveycord();
        x2 = ((x1) * cos(phix)) + ((y1) * sin(phix))+xc;
        y2 = ((x1) * sin(phix)) - ((y1) * cos(phix))+yc;
        vecp[i] = Point(x2, y2);
    }
}

void Oval::MoveX(double dx) {
    for (int i = 0; i < vecp.size(); ++i) {
        vecp[i].Accurex(dx);
    }
}

void Oval::MoveY(double dx) {
    for (int i = 0; i < vecp.size(); ++i) {
        vecp[i].Accurey(dx);
    }
}

void Oval::PrittoFile() {
    std::ofstream f;
    f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\field.txt", std::ios::out);
    for (int i = 0; i < vecp.size(); ++i) {
        f << vecp[i].Givexcord() << '\t' << vecp[i].Giveycord() << '\t' << vecp[i].GiveLable() << std::endl;
    }
    f.close();
}

void Oval::AddToFile() {
    std::ofstream f;
    f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\field.txt", std::ios::app);
    for (int i = 0; i < vecp.size(); ++i) {
        f << vecp[i].Givexcord() << '\t' << vecp[i].Giveycord() << '\t' << vecp[i].GiveLable() << std::endl;
    }
    f.close();
}

void Oval::AddtoPointlist(std::vector<Point>& pvec) {
    for (int i = 0; i < vecp.size(); ++i) {
        pvec.push_back(vecp[i]);
    }
}

std::vector<Point> Oval::Get_Oval() {
    return vecp;
}
