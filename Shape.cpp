#include "Shape.h"

Shape::Shape(){
	p1.x=10;
	p1.y=10;
	p2.x=100;
	p2.y=100;
	border=20;
}
void Shape::loadData(std::string fileName){
	std::ifstream file(fileName); 
    	file >> p1.x;
		file >> p1.y;
		file >> p2.x;
		file >> p2.y;
    file.close(); // ��������� ����
}
int Shape::getBorder(){
	return border;
}
void Shape::setPosition(int x, int y){
	p2.x=p2.x-p1.x+x;
	p2.y=p2.y-p1.y+y;
	p1.x=x;
	p1.y=y;
}
void Shape::setSize(int dx, int dy){
	if (dx<2*border || dy<2*border) throw 0;
	p2.x=p1.x+dx;
	p2.y=p1.y+dy;
}
POINT Shape::getP1(){
	return p1;
}	
POINT Shape::getP2(){
	return p2;
}
POINT Shape::getSize(){
	size.x=p2.x - p1.x;
	size.y=p2.y - p1.y;
	return size;
}
void Shape::saveToFile(std::string fileName){
	std::ofstream file(fileName); 
		file << p1.x << " " << p1.y << " ";
		file << p2.x << " " << p2.y;
    file.close(); // ��������� ����
}
Shape::~Shape(){}