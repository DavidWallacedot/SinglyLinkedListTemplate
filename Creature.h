
/*
Author: David Wallace
Date: 02/15/2018
name: Creatures.h
purpose:provides an interface for creature object
*/
#ifndef CREATURES_H
#define CREATURES_H

# include <iostream>
# include <fstream>
# include <cmath>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <iomanip>
# include <string>
# include <cstring>

using namespace std;

class Creature{

//creature attributes
	private:
		string name ;
		string description ;
		bool dangerous;
		float cost;

		public:

//constructor
		Creature();
		Creature(string,string,bool,float);	
			
//getters 
		string  getName(){return name;}
		string getDescription(){return description;}
		bool getDangerous(){return dangerous;}
		float getCost(){return cost;}

// setters
		void setName(string n){name  = n;}
		void setDescription(string des)	{ description = des;}
		void setDangerous();
		void setCost();

//object methods 
		void printCreature( );
		void printCreatureToFile(string);
};
#endif