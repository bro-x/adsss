/*Title_
Roll_No_75
Batch_A4
*/
#include<iostream>
#define MAX 10
using namespace std;
class Hash
{
	private:
			struct node
			{
				int ID;
				char name[50],mobile[12];
				node *next;
			}*temp,*head[MAX];
	public:
			Hash()
			{
				for(int i=0;i<MAX;i++)
					head[i]=NULL;
			}
			void create();
			void display();
			void search();
};
void Hash::create()
{
	char ch;
	int key;
	node *New;
	do
	{
		New = new node();
		cout<<"\nEnter client ID : ";
		cin>>New->ID;
		cout<<"\nEnter client name : ";
		cin>>New->name;
		cout<<"\nEnter client mobile number : ";
		cin>>New->mobile;
		New->next=NULL;
		key = (New->ID % MAX);
		if(head[key] == NULL)
		{
			head[key]=New;
		}else
		{
			temp = head[key];
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = New;	
		}
		cout<<"\nDo you want to enter next entry (y/n) : ";
		cin>>ch;	
	}while(ch=='y' || ch=='Y');
}
void Hash::display()
{
	int i,j;	
	cout<<"*****************  Entries in Hash table  *****************";
	for(i=0 ; i<MAX ; i++)
	{		
		cout<<"\n Hash["<<i<<"] --> ";
		temp = head[i];
		while(temp != NULL)
		{
			cout<<"{"<<temp->ID<<","<<temp->name<<","<<temp->mobile<<"} --> ";
			temp=temp->next;
		}
		cout<<"NULL";
	}	
}
void Hash::search()
{
	int ID,key,flag=0;
	cout<<"\nEnter client ID :: ";
	cin>>ID;
	key = (ID % MAX);
	if(head[key] != NULL)
	{
		temp = head[key];
		while(temp != NULL)
		{
			if(temp->ID == ID)
			{
				cout<<"\nClient info ::\nName ->>> "<<temp->name;	
				cout<<"\nMobile No. ->>> "<<temp->mobile<<"\n";
				flag=1;
				break;	
			}
			temp = temp->next;
		}
	}
	if(flag==0)
	{
		cout<<"\n->>> Info for client ID "<<ID<<" is not found...\n";
	}
}
int main()
{
	Hash hash;
	int ch;		
	do
	{
		cout<<"\n####### MENU #######";
		cout<<"\n1.Create / Insert \n2.Display \n3.Search \n0.Exit \n Enter your choice :: ";
		cin>>ch;
		switch(ch)
		{
			case 0:
					break;
			case 1:
					hash.create();
					break;
			case 2:
					hash.display();
					break;
			case 3:
					hash.search();
					break;
			default:
					cout<<"\nInvalid choice...";			
		}
	
	}while(ch != 0);
}
/******************* OUTPUT *******************
sitrc@sitrc-OptiPlex-380:~$ cd Desktop/Assignment
sitrc@sitrc-OptiPlex-380:~/Desktop/Assignment$ g++ 6.cpp
sitrc@sitrc-OptiPlex-380:~/Desktop/Assignment$ ./a.out

####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit
 Enter your choice :: 1
Enter client ID : 1
Enter client name : Sudhir
Enter client mobile number : 8806814676
Do you want to enter next entry (y/n) : y
Enter client ID : 2
Enter client name : kalpesh
Enter client mobile number : 9960362770
Do you want to enter next entry (y/n) : y
Enter client ID : 3
Enter client name : anil
Enter client mobile number : 7709105526
Do you want to enter next entry (y/n) : y
Enter client ID : 4
Enter client name : harish
Enter client mobile number : 7841054425
Do you want to enter next entry (y/n) : y
Enter client ID : 5
Enter client name : kushal
Enter client mobile number : 9876543210
Do you want to enter next entry (y/n) : n
####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 2
*****************  Entries in Hash table  *****************
 Hash[0] --> NULL
 Hash[1] --> {1,Sudhir,8806814676} --> NULL
 Hash[2] --> {2,kalpesh,9960362770} --> NULL
 Hash[3] --> {3,anil,7709105526} --> NULL
 Hash[4] --> {4,harish,7841054425} --> NULL
 Hash[5] --> {5,kushal,9876543210} --> NULL
 Hash[6] --> NULL
 Hash[7] --> NULL
 Hash[8] --> NULL
 Hash[9] --> NULL
####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 3
Enter client ID :: 5
Client info ::
Name ->>> kushal
Mobile No. ->>> 9876543210
####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 3
Enter client ID :: 3
Client info ::
Name ->>> anil
Mobile No. ->>> 7709105526
####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 3
Enter client ID :: 0
->>> Info for client ID 0 is not found...
####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 3
Enter client ID :: 1
Client info ::
Name ->>> Sudhir
Mobile No. ->>> 8806814676
####### MENU #######
1.Create / Insert 
2.Display 
3.Search 
0.Exit 
 Enter your choice :: 0
sitrc@sitrc-OptiPlex-380:~/Desktop/Assignment$ 
*///////////////////////////////////////////////////
