#include "Paint.h"
//#include "shape2.h"

Paint::Paint(Shape *shape){
	pShape = shape;
	hwnd = GetConsoleWindow();
	hdc = GetDC (hwnd);
	//SetBkColor (hdc, RGB(150, 150, 220));
	whitePen = GetStockPen (WHITE_PEN);
	blackBrush = CreateSolidBrush (RGB(0,0,0));
	blueBrush = CreateSolidBrush (RGB(150, 150, 220));
	oldPen = SelectPen (hdc, whitePen);
	oldBrush = SelectBrush (hdc, blackBrush);	
}
void Paint::getShapeP(){
	p1=pShape->getP1();
	p2=pShape->getP2();
}
void Paint::drawPath(){
	SelectBrush (hdc, blackBrush);
	getShapeP();
	Rectangle (hdc, p1.x, p1.y, p2.x, p2.y);
}
void Paint::drawFill(){	
	SelectBrush (hdc, blueBrush);
	getShapeP();
	Rectangle (hdc, p1.x, p1.y, p2.x, p2.y);
}
void Paint::drawInsert(){
	int border=pShape->getBorder();
	getShapeP();
	drawFill();
	pShape->setPosition(p1.x+border, p1.y+border);
	pShape->setSize(p2.x-p1.x-2*border, p2.y-p1.y-2*border);
	drawPath();
}
Paint::~Paint(){
	ReleaseDC (hwnd, hdc);
	SelectPen (hdc, oldPen);
	DeletePen (whitePen);
	SelectBrush (hdc, oldBrush);
	DeleteBrush (blueBrush);
	DeleteBrush (blackBrush);
}