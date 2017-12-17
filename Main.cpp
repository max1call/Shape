#include "Paint.h"
#include "Shape.h"
#include "Container.h"

int main(){
	std::string fileName="SaveData.txt";
	std::string fileNameCont="SaveContainer.txt";
	
	Container *container = new Container();	
	/*for(int i=0; i<5; i++){	
		std::string name = "shape"+i;
		Shape* name= new Shape();
		list->Add(name);
	}*/
	Shape* s1= new Shape();
	container->Add(s1);
	Shape* s2= new Shape();
	container->Add(s2);
	Shape* s3= new Shape();
	container->Add(s3);

	s1->setPosition(10,120);
	s2->setPosition(150,120);
	s3->setPosition(300,120);

	container->Show();

	//Shape *shape= new Shape();
	Paint *p1= new Paint(s1);
	Paint *p2= new Paint(s2);
	Paint *p3= new Paint(s3);

//	shape->loadData(fileName);	
	p1->drawPath();
	p2->drawInsert();
	p3->drawFill();

	//container->saveToFile(fileNameCont);
	//Shape *s4=new Shape();
	//s4=container->find(90, 90);
	//Paint *p4= new Paint(s4);
	//p4->drawFill();
//
//	
//	try{
//		shape->setSize(100, 30);
//	} 
//	catch(int error){
//		if (error == 0) printf("To little size!");
//	}

//	shape->setSize(100, 100);
//
//	//try{ 
//		shape->setPosition(30, 30);
//	/*} 
//	catch(int error){if (error == 0) printf("Incorrect data");}
//*/
//	shape->saveToFile(fileName);

	/*delete shape;
	delete paint;*/
	delete s1;
	delete s2;
	delete s3;

	delete p1;
	delete p2;
	delete p3;

	delete container;

	getch();
	return 0;
}