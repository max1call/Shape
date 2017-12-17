#pragma once
#include "Lib.h"
#include "Shape.h"
 
struct StractList{
     Shape *cShape;     
     StractList *next,*prev; 
};
 
 class Container{
		StractList *Begin,*End, *Temp, *Temp2;
	public:
		Container():Begin(NULL),End(NULL){}; 
		void Show(); 
		void Add(Shape *shape); 
		Shape* find(int dx, int dy);
		void exclude(Shape *shape);
		void saveToFile(std::string fileName);
		~Container();
 };
 
