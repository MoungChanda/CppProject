#include<iostream>
#include<stdlib.h>
using namespace std;
class person{
	public:
		int id;
		char name[20];
		char sex[10];
	
	public:
		void input(){
			cout<<"input id : ";
			cin>>id;
			cout<<"input name : ";
			cin>>name;
			cout<<"input sex : ";
			cin>>sex;
		}	
		void output(){
			cout<<"\t"<<id<<"\t"<<name<<"\t"<<sex<<endl;
		}
};

int main()
{
	person *per;
	
	int n;
	int i;
	cout<<"input n : ";
	cin>>n;
	per=(person*)malloc(n*sizeof(person));
	 
	int op;
	do{
		cout<<"choose one : ";
		cin>>op;
		switch(op)
		{
			case 1:{
				for(i=0;i<n;i++)
				{
					(per+i)->input();
				}
				break;
			}
			case 2:{
				for(i=0;i<n;i++)
				{
					(per+i)->output();
				}
				break;
			}
			case 3:{
				int svalue,b=0;
				cout<<"input id to update :";
				cin>>svalue;
				for(i=0;i<n;i++)
				{
					if(svalue==(per+i)->id){
						cout<<"search found \n";
						(per+i)->output();
						b=1;
					}
				}
				if(!b){
					cout<<"search not found\n";
				}
				break;
			}
			case 4:{
				int svalue,b=0;
				cout<<"input id to update :";
				cin>>svalue;
				for(i=0;i<n;i++)
				{
					if(svalue==(per+i)->id){
						cout<<"input new name :";
						cin>>(per+i)->name;
						b=1;
					}
				}
				if(!b){
					cout<<"Invalid to update \n";
				}
				break;
			}
			case 5:{
				person temp;
				int j;
				for(i=0;i<n;i++)
				{
					for(j=i+1;j<n;j++)
					{
						if((per+i)->id>(per+j)->id)
						{
							temp=*(per+i);
							*(per+i)=*(per+j);
							*(per+j)=temp;
						}
					}
				}
				break;
			}
			case 6:{
				int deleted,j;
				int b=0;
				cout<<"input id to delete : ";
				cin>>deleted;
				for(i=0;i<n;i++)
				{
					if(deleted==(per+i)->id)
					{
						for(j=i;j<n;j++)
						{
							*(per+j)=*(per+j+1);
							
						}
						b=1;
						n--;
						cout<<"delete success\n";
						
					}
				}
				if(!b)
				{
					cout<<"Invalid to delete!\n";
				}
				break;
			}
		}
	}while(op!=0); 
}






