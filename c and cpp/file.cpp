#include<iostream>
#include<fstream>
#include <cstring>
#include <stdio.h>
using namespace std;
class person{
	public :
		int id;
		char name[30];
		char sex[10];
	public:
		void input(){
			cout<<"input id : ";
			cin>>id;
			cout<<"input name : ";
			cin.ignore();
			cin.getline(name,30);
			cout<<"input sex : ";
			cin>>sex;
		}	
		void output(){
			cout<<id<<"\t"<<name<<"\t"<<sex<<endl;
		}
};

void write(){
	ofstream file;
	person p;
	file.open("update.dat",ios::out| ios::app | ios::binary);
	p.input();
	file.write((char *)&p,sizeof(p));
	file.close();
	
}
void read(){
	ifstream file;
	person p;
	file.open("update.dat",ios::in | ios::binary);
	if(!file){
		cout<<"error"<<endl;
	}
	file.read((char *)&p, sizeof(p));
	while (!file.eof()){
		p.output();
		file.read((char *)&p, sizeof(p));
	}
	
}
void update(){
	int pos,size;
	fstream file;
	person p;
	char  search[20];
	file.open("update.dat", ios::in | ios::out | ios::binary);
//	file.seekg(0); // read data from the begining of file
	file.read((char *)&p, sizeof(p));
	cout<<"input id to update : ";
	cin>>search;
	while (!file.eof()) // it return 1 so i use not operator to break while loop
	{
	    if (strcmp(p.name,search)==0)
	    {
	        p.input();
	    	size=sizeof(p);
	        pos=file.tellg();
	        file.seekp( pos- size);
	        file.write((char *)&p, sizeof(p));
	    }
	    file.read((char *)&p, sizeof(p));
	}
	file.close();
}
void Sort()
{
	 fstream f1("update.dat",ios::binary|ios::ate|ios::in|ios::out);
	 int i=0;
	 person obj1,obj2;
	 long size=f1.tellg()/sizeof(person);
	
	 for(i=0;i<size-1;++i)
	 {
	  for(int j=i+1;j<size-1-i;++j)
	  {
	    f1.read((char*)&obj1,sizeof(obj1));
	    f1.read((char*)&obj2,sizeof(obj2));
	    if(obj1.id > obj2.id)
	    {
	      f1.seekp(-2*sizeof(person),ios::cur);
	      f1.write((char*)&obj2,sizeof(obj2));
	      f1.write((char*)&obj1,sizeof(obj1));
	      f1.seekp(-sizeof(person),ios::cur);
	    }
	  }
	 }
	 f1.close();
}

int main(){
	
	read();
//	write();
//	read();
	update();
	read();
	

	return 0;
}
