#include "Paint.h"
#include "Shape.h"

int main(){
	std::string fileName="SaveData.txt";
		
	Shape *shape= new Shape();
	Paint *paint= new Paint(shape);

	shape->loadData(fileName);	
	paint->drawPath();

	shape->setPosition(50, 50);
	paint->drawFill();
	
	try{
		shape->setSize(100, 30);
	} 
	catch(int error){
		if (error == 0) printf("To little size!");
	}
	
	shape->setPosition(250, 30);
	

	paint->drawInsert();
	shape->setSize(100, 100);

	//try{ 
		shape->setPosition(30, 30);
	/*} 
	catch(int error){if (error == 0) printf("Incorrect data");}
*/
	shape->saveToFile(fileName);

	delete shape;
	delete paint;

	getch();
	return 0;
}