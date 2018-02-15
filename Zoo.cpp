#include "Creature.h"
#include "LinkedList.h"
#include <string>
# include <cstring>
# include <fstream>
# include <sstream>
# include <iostream>

using namespace std;
//declaration of static methods
float convertToFloat(string);
int enterCreature();
void enterMagicalCreatureFromFile(LinkedList<Creature>* linkedList);
void enterCreaturesManually(LinkedList<Creature>* linkedList);
void printCreatures(LinkedList<Creature>* linkedList);
void deleteCreature(LinkedList<Creature>* linkedList);
void saveCreaturesToFile(LinkedList<Creature>* linkedList);

int main(){
	
	 LinkedList<Creature> linkedList;
	 char userInput = 'y';
	 
	 while (tolower(userInput) == 'y' ){
		 cout<<"What would you like to do?\n";
		 cout<<"1. Enter Magical Creature \n";
		 cout<<"2. Delete Magical Creature\n";
		 cout<<"3. List/Print Creatures.\n";
		 cout<<"4. End program.\n";
		 cout<<"Enter 1, 2, 3, or 4.\n"; 
		 cout<<"CHOICE: ";
		 int input =0;
		 cin>>input;
		 while(input<0 || input>4){//validates userInput
			cout<<"Your choice was invalid. Choose a number 1 - 4\nCHOICE: ";
			cin>>input;	
	 }
		 int k ;
		 switch(input){//determines which function to call
			 case 1:
				 k =  enterCreature();
				 if (k == 1){
					enterCreaturesManually(&linkedList); //determines which method of entry
			 }
				else{
				
					enterMagicalCreatureFromFile(&linkedList);
			 }
				 break;
			 case 2:
				deleteCreature(&linkedList);
				break;
			 case 3:
				 printCreatures(&linkedList);
				 break;
			 case 4:
				 saveCreaturesToFile(&linkedList);
				 userInput = 'n';
				 break;
			 
			} 
		 
	 }
		cout<<"Goodbye"<<endl;
		return 0;
}

void enterMagicalCreatureFromFile(LinkedList<Creature>* linkedList){
	 
	 ifstream file; 
	 string fileName="";
	 string tempName="";
	 string tempDes="";
	 string tempDanger;
	 bool tempDan;
	 string tempCost="";
	 cout<<endl;
	 
	 cout<<"What is the name of the file with your list of creatures?(ex: filename)"<<endl;
	 cout<<"FILENAME:"; 
	 cin.ignore();
	 getline(cin,fileName);
	 file.open(fileName.c_str());	
	 if(!file.is_open()){
		 cout<<file<<" does not exist or is corrupt. Sorry. Can't load creatures.";
	 }
	 else{ 
		while(getline(file,tempName)){
			getline(file,tempDes);
			getline(file,tempDanger);
			getline(file,tempCost);
			
			float tempCostFloat = convertToFloat(tempCost);
			if(atoi(tempDanger.c_str())){//converts allows userInput char to be stored as int
		    tempDan = true;
	 }
	 
	 else
	 {
		 tempDan = false;
	 }
			Creature creatureFromFile(tempName,tempDes,tempDan,tempCostFloat);					
			linkedList->appendNode(creatureFromFile);						
		}
			
				
			}
			file.close();
		cout<<endl;
	 }
	 
	



	void enterCreaturesManually(LinkedList<Creature>* linkedList){
		
		char anotherCreature ='y';
		string tempName="";
		string tempDes="";
		char tempDanger;
		bool tempDan;
		string tempCost="";
		 
		while(tolower(anotherCreature)=='y'){
		
			cout<<"\nWhat is the name of your creature?\n";
			cin.ignore();
			getline(cin,tempName);
			cout<<"What is the description of your creature?\n";
			cin.ignore();
			getline(cin,tempDes);
			cout<<"Is this creature dangerous?(y or n)\n";
			cin>>tempDanger;
		
			 if(tolower(tempDanger)=='y'){//converts allows userInput char to be stored as int
				 tempDan = true;
			 }
			 else
			 {
				 tempDan = false;
			 }
			cout<<"What is the cost per month to take care of this creature?"<<endl;
			cout<<"COST: ";
			cin>>tempCost;
			float tempCostFloat = convertToFloat(tempCost);
			Creature creatureFromFile(tempName,tempDes,tempDan,tempCostFloat);
			linkedList->appendNode(creatureFromFile);	
			cout<<"\nWould you like to add another creature enter (y or n)";
			cin>>anotherCreature;
			
	}
			
	 
}
	 
int enterCreature(){//function was created to decluter main function
	
	 int userChoice;
	 cout<<endl;
	 cout<<"What do you want to do?\n";
	 cout<<"     1.   Enter one creature manually.\n";
	 cout<<"     2.   Load my creatures from a file.\n";
	 cout<<"CHOICE: ";
	 cin>>userChoice;
	 while(userChoice>2 || userChoice<0){
		 cout<<"\nPlease enter a valid choice of 1(to load from file) or 2(manual insertion of creature)"<<endl;
		 cin>>userChoice;
	 }
	 if(userChoice == 1){
		 return 1;//function could end here
		}
		 else{
			return 2;//function could end here by returning 1 
			}
 }

	 
void printCreatures(LinkedList<Creature>* linkedList){
	
	int numNodes = linkedList->getNumNodes(); 
	
	if( numNodes== 0){
		cout<<"THERE ARE NO CREATURES AT YOUR ZOO!"<<endl;
		return;
	}
	else{
		cout<<endl;
		for(int i = 0; i<numNodes ; i++){
			linkedList->getNodeValue(i).printCreature();
		}
		
	}
	
	
}

void deleteCreature(LinkedList<Creature>* linkedList){
	
	int numNodes = linkedList->getNumNodes();
	int choice ;
	cout<<endl;
	for(int i = 0; i<numNodes;i++)
	{
		cout<<i+1<<" "<<linkedList->getNodeValue(i).getName()<<endl;

	}
	cout<<"Please select the creature you wish to delete"<<endl;
	cin>>choice;
	choice--;
	linkedList->deleteNode(choice);
	cout<<"The creature you selected was removed"<<endl;
}

void saveCreaturesToFile(LinkedList<Creature>* linkedList){
	 
	 int counter = 0;
	 string fileName;
	 char userInput; 
	 
	 cout<<"\nWould you like to save your creatures to a file?Select 'Y' or 'y' if so."<<endl;
	 cin>>userInput;
	 if(tolower(userInput)=='y'){
		cout<<"Please enter the name of the file you wish to save your creatures to."<<endl;
		cin>>fileName;
		while(counter < linkedList->getNumNodes()){
			Creature* creatureToBeAddedToFile;
			for(counter = 0; counter< linkedList->getNumNodes();counter++){
			linkedList->getNodeValue(counter).printCreatureToFile(fileName);
		} 
	 }
	 }
	 cout<<"Your creature(s) were successfully saved to "<<fileName<<".\n\n";
	 }
	
 float convertToFloat(string s)
{
	istringstream mystring(s);
	float myfloat;
	if (!(mystring >> myfloat))
	myfloat = 0;
	return myfloat;
}