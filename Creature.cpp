
/*
Author: David Wallace
Date: 02/15/2018
name: Creatures.cpp
purpose: implementation of functions belonging to Creature object
*/
#include "Creature.h"


 Creature::Creature(){
 }


Creature::Creature(string n,string des, bool dan, float c){
	
	name = n;
	description = des;
	dangerous = dan;
	cost = c;
}


void Creature::setDangerous(){
	 
	 char danger ='y';
	 cout<<endl<<"IS IT A DANGEROUS CREATURE(y or n): ";
	 cin>>danger;
	 if(tolower(danger)=='y'){//converts allows userInput char to be stored as int
		 dangerous = 1;
	 }
	 else
	 {
		 dangerous = 0;
	 }
}

void Creature::setCost(){
	cout<<"How much does your creature cost to take care of ?"<<endl;
	cin>>cost;
}

void Creature::printCreature(){
		char danger;
		if(dangerous == true){
			danger = 'y';
		}
		else{
			danger = 'n';
		}
		cout<<"Name: "<<name<<endl;
		cout<<"Description: "<<description<<endl;
		cout<<"DANGEROUS: "<<danger<<endl;
		cout<<"Cost: "<<setw(50)<<right<<"$"<<cost<<endl;
}
	
void Creature::printCreatureToFile(string fileName){

			int danger;
			if(dangerous == true){
				danger = 1;
		}
			else{
				danger = 0;
		}
			
			ofstream outFile;
	
			outFile.open(fileName.c_str(), ios::app);
			outFile<<name<<endl;
			outFile<<description<<endl;
			outFile<<danger<<endl;
			outFile<<cost<<endl;
 
			outFile.close();
			
 }