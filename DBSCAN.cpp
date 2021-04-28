#include "DBSCAN.h"
#include <fstream>


std::vector<Point> DBSCAN::regionQuery(Point ppoint) {
	std::vector<Point>::iterator it;
	std::vector<Point> clust;
	for (it = d_arrpoint.begin(); it != d_arrpoint.end(); ++it) {
		if (it->Distance(ppoint) <= d_eps) {
			clust.push_back(*it);
		}
	}
	return clust;
}

int DBSCAN::ExpandCluster(Point ppoint,int p_lable) {
	std::vector<Point> Corepoints = regionQuery(ppoint);
	if (Corepoints.size() < d_Minpts) {
		Changelb(ppoint, Noise);
		return Failure;
	}
	else {
		int ind=0;
		int indcore = 0;
		std::vector<Point>::iterator it_core;
		for (it_core = Corepoints.begin(); it_core != Corepoints.end(); ++it_core) {
			Changelb(*it_core, p_lable);
		}
		Delete(ppoint, Corepoints);
		while (!Corepoints.empty()) {
			Point currentpoint = Corepoints[0];
			std::vector<Point> neighbours = regionQuery(currentpoint);
			if (neighbours.size() >= d_Minpts) {
				for (int i=0; i<neighbours.size(); ++i) {
					if (neighbours[i].GiveLable() == Unclassified || neighbours[i].GiveLable() == Noise) {
						if (neighbours[i].GiveLable() == Unclassified) {
							Corepoints.push_back(neighbours[i]);
						}
						Changelb(neighbours[i], p_lable);
					}
				}
			}
			Delete(currentpoint, Corepoints);
		}
		return Success;
	}
}

int DBSCAN::Init_DBSCAN() {
	int label = 1;
	std::vector<Point>::iterator it;
	for (it = d_arrpoint.begin(); it != d_arrpoint.end(); ++it) {
		if (it->GiveLable() == Unclassified) {
			if(ExpandCluster(*it,label)!=Failure){
				label++;
			}
		}
	}
	return 0;
}

std::vector<Point> DBSCAN::Get_DBS() {
	return d_arrpoint;
}
void DBSCAN::PrintToFile_D() {
	std::ofstream f;
	f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\dbscan.txt", std::ios::out);
	for (int i = 0; i < d_arrpoint.size(); ++i) {
		f << d_arrpoint[i].Givexcord() << '\t' << d_arrpoint[i].Giveycord() << '\t' << d_arrpoint[i].GiveLable() << std::endl;
	}
	f.close();
}

void DBSCAN::Changelb(Point ppoint, int lab) {
	int ind2 = 0;
	int indcore2 = 0;
	std::vector<Point>::iterator it_core2;
	for (it_core2 = d_arrpoint.begin(); it_core2 != d_arrpoint.end(); ++it_core2) {
		if (it_core2->Givexcord() == ppoint.Givexcord() && it_core2->Giveycord() == ppoint.Giveycord())
		{
			indcore2 = ind2;
		}
		++ind2;
	}
	d_arrpoint[indcore2].Setlable(lab);
}

void DBSCAN::Delete(Point ppoint, std::vector<Point> &pointsparam) {
	int ind2 = 0;
	int indcore2 = 0;
	std::vector<Point>::iterator it_core2;
	for (it_core2 = pointsparam.begin(); it_core2 != pointsparam.end(); ++it_core2) {
		if (it_core2->Givexcord() == ppoint.Givexcord() && it_core2->Giveycord() == ppoint.Giveycord())
		{
			indcore2 = ind2;
		}
		++ind2;
	}
	pointsparam.erase(pointsparam.begin() + indcore2);
	
}