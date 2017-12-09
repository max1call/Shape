#pragma once//Поля в класс, никаких стр-р, передавать экз-р shap в paint
#include "Lib.h"
#include "Shape.h"

	class Paint{
	private:
		HWND hwnd;
		HDC hdc;
		HPEN whitePen, oldPen;
		HBRUSH oldBrush, blackBrush, blueBrush;
		Shape *pShape;
		POINT p1, p2;
	public:	
		Paint(Shape *shape);
		void getShapeP();
		void drawPath();
		void drawFill();
		void drawInsert();
		~Paint();
	};
