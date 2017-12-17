#include "Container.h"

void Container::Add(Shape *shape){
	Temp=new StractList;	
	Temp->next=NULL;	
	Temp->cShape=shape;	
	if (Begin!=NULL){
		Temp->prev=End;	
		End->next=Temp;	
		End=Temp;	
	}
	else{
		Temp->prev=NULL;
		Begin=End=Temp;
	}
}
	Shape* Container::find(int dx, int dy){
		Temp=Begin;
		while(Temp){
			if(dx!=Temp->cShape->getSize().x || dy!=Temp->cShape->getSize().y)
				Temp=Temp->next;
			else return Temp->cShape;
		}
		return NULL;
	}
	void Container::exclude(Shape *shape){
		Temp=Begin;
		while(Temp){
			if(shape!=Temp->cShape) 
				Temp=Temp->next;
			else{
				Temp2=Temp->next;
				Temp=Temp->prev;
				Temp->next = Temp2;
				Temp2->prev=Temp;
			}
		}
	}
void Container::Show(){
	int i;
	Temp=Begin;
	for(i=1; Temp!=NULL; i++){
		std::cout << "Coordinates " << i << " shape = ";
		std::cout<< "(" << Temp->cShape->getP1().x <<", " << Temp->cShape->getP1().y <<", ";
		std::cout<< Temp->cShape->getP2().x <<", " << Temp->cShape->getP2().y <<")"<<"\n";
		Temp=Temp->next;
	}
	std::cout<<"\n";

	Temp=End; 
	for(i--; Temp!=NULL; i--){
		std::cout << "Coordinates " << i << " shape = ";
		std::cout<< "(" << Temp->cShape->getP1().x <<", " << Temp->cShape->getP1().y <<", ";
		std::cout<< Temp->cShape->getP2().x <<", " << Temp->cShape->getP2().y <<")"<<"\n";
		Temp=Temp->prev;
	}
	std::cout<<"\n";
}
void Container::saveToFile(std::string fileName){ 
	std::ofstream file(fileName);//, ios_base::out
	Temp=Begin;
	for(int i=1; Temp!=NULL; i++){
		file<<Temp->cShape->getP1().x<<" ";
		file<<Temp->cShape->getP1().y<<" ";
		file<<Temp->cShape->getP2().x<<" ";
		file<<Temp->cShape->getP2().y<<" \n";
		Temp=Temp->next;
	}
    file.close(); // закрываем файл
}
Container::~Container(){   
    while (Begin){
        End=Begin->next;
        delete Begin; 
        Begin=End;
    }
}
 