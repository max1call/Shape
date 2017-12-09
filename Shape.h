#pragma once
#include "Lib.h"

	class Shape{
		POINT p1, p2;
		int border;
	public:
		Shape();
		int getBorder();
		void loadData(std::string fileName);
		void setPosition(int x, int y);
		void setSize(int dx, int dy);
		POINT getP1();
		POINT getP2();
		void saveToFile(std::string fileName);
		~Shape();
	};
