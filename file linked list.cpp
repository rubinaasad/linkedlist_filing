// file linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

struct student
{
	int id;
	string name;
	double marks;
	char grade;
	student()
	{
		id=0;
		name="";
		marks=0.0;
		grade=' ';
	}

};
char filename[30]="D:\\linked list.txt";
struct linkedlist
{
	struct node
	{
		student info;
		node* next;
		node()
		{
			next=0;
		}
	};
	typedef node* ndptr;
	ndptr pfirst;
	linkedlist()
	{
		pfirst=0;
	}
 
void write_list()
{
	fstream f;
	f.open(filename,ios::out | ios::app);
	if(f.is_open()==false)
	{
		cout<<"unable to open file" <<endl;
		return;
	}
	
		ndptr ptr=pfirst;
		while(ptr!=0)
		{
			f<<ptr->info.id <<" " <<ptr->info.name <<" " <<ptr->info.marks<<" " <<ptr->info.grade <<endl;
			ptr=ptr->next;
		}



	f.close();
}

void read_list()
{
	
	fstream f;
	f.open(filename,ios::out | ios::app);
	if(f.is_open()==false)
	{
		cout<<"unable to open file" <<endl;
		return;
	}
	
		ndptr ptr=pfirst;
		while(ptr!=0)
		{
			if(f>>ptr->info.id >>ptr->info.name>>ptr->info.marks >>ptr->info.grade)
				ptr=ptr->next;
		}
}


	

void add_head()
{
	
	ndptr snew=new node;
	snew->info.id=1;
	snew->info.name="rubina ali";
	snew->info.marks=89.0;
	snew->info.grade='A';
	 snew->next=0;
	 if(pfirst==0)
	 {
		 pfirst=snew;
	 }
	 else
	 {
		 snew->next=pfirst;
		 snew=pfirst;

	 }
	 write_list();
}

void add_afterhead()
{
	if(pfirst==0)
	{
		return;
	}
	else
	{
	ndptr snew=new node;
	snew->info.id=2;
	snew->info.name="samina ali";
	snew->info.marks=78;
	snew->info.grade='B';
	snew->next=pfirst->next;
	pfirst->next=snew;
	write_list();
	}
	
}

void traverse()
{
	ndptr temp=pfirst;
	while(temp!=0)
	{
		cout<<temp->info.id <<endl;
		cout<<temp->info.name <<endl;
		cout<<temp->info.marks <<endl;
		cout<<temp->info.grade <<endl;
		temp=temp->next;
	}
	read_list();
	system("pause");
}

bool delete_specific(int n)
{
	ndptr temp=pfirst->next;
	ndptr prev=pfirst;
	if(pfirst==0)
	{
		return 0;
	}
	else if(pfirst->info.id==n)
	{
		delete pfirst;
		return true;
	}
	else
	{
		while(temp!=0)
		{
			if(temp->info.id==n)
			{
				prev->next=temp->next;
				delete temp;
			}
			
		}
		prev=temp;
		temp=temp->next;
	}
	return false;
	read_list();
	write_list();
}
};


int _tmain(int argc, _TCHAR* argv[])
{
	linkedlist ll;
	ll.add_head();
	ll.add_afterhead();
	ll.traverse();
	ll.delete_specific(1);
	return 0;
}

