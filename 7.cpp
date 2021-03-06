/*Title_
Roll_No_75
Batch_A4
*/
#include<iostream>
#include<string.h>
using namespace std;
class Dictionary
{
	struct node
	{
		char word[50],mean[50];
		node *next;		
	}*head[26],*temp,*prev;
	public:
		Dictionary()
		{	
			for(int i=0;i<26;i++)
				head[i]=NULL;
		}
		void create();
		void find();
		void deleter();
		void display();
		int hash(char);
};
int Dictionary::hash(char ch)
{
	if((int)ch <= 90)
		return (int)ch-65;
	else
		return (int)ch-97;
}
void Dictionary::create()
{
	char ch;
	int key;
	node *New;
	do
	{
		New = new node;
		cout<<"\nEnter word :: ";
		cin>>New->word;
		cout<<"\nEnter meaning :: ";
		cin>>New->mean;
		New->next = NULL;
		key = hash(New->word[0]);
		if(head[key] == NULL)
		{
			head[key]=New;
		}
		else
		{
			temp = head[key];
			while(temp->next != NULL)
			temp = temp->next;
			temp->next = New;	
		}
		cout<<"\nDo you want to enter next entry (y/n) : ";
		cin>>ch;			
	}while(ch == 'y' || ch == 'Y');
}
void Dictionary::display()
{
	for(int i=0;i<26;i++)
	{
		cout<<"\nhead["<<(char)(i+65)<<"]";
		temp = head[i];
		while(temp != NULL)
		{
			cout<<"-->[ "<<temp->word<<", "<<temp->mean<<" ]";
			temp = temp->next;
		}
		cout<<"--> NULL";
	}
}
void Dictionary::find()
{
	char word[50];
	int key,flag=0;		
	cout<<"\nEnter word to be find :: ";
	cin>>word;
	key = hash(word[0]);
	if(head[key] != NULL)
	{
		temp = head[key];
		while(temp != NULL)
		{
			if(strcmp(temp->word,word)==0)
			{
				cout<<"\nWord : "<<temp->word<<"\nMean : "<<temp->mean;
				flag=1;
				break;
			}
			temp=temp->next;
		}
	}
	if(flag == 0)
	{
		cout<<"\n--->> Word to be search not found ...";
	}
}
void Dictionary::deleter()
{
	char word[50];
	int key,flag=0;
	cout<<"\nEnter word to be delete from dictionary :: ";
	cin>>word;
	key = hash(word[0]);
	if(head[key] != NULL)
	{
		temp = head[key];
		while(temp != NULL)
		{
			if(strcmp(temp->word,word) == 0)
			{
				if(temp == head[key])
				{
					head[key] = head[key]->next;
				}
				else if(temp->next != NULL)
				{
					prev->next = temp->next;					
				}
				else
				{
					prev->next = NULL;
				}				
				delete temp;
				cout<<"\n--->> Word is deleted form dictionay...";
				flag=1;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	if(flag == 0)
		cout<<"\n--->> Word to be delete from dictionary not found...";
		
}
int main()
{
	Dictionary dict;
	int ch;
	do
	{	
		cout<<"\n========DICTIONARY USING HASH FUNCTION========";
		cout<<"\n1.Create/Insert \n2.Display \n3.Find \n4.Delete \n5.Exit";
		cout<<"\n==============================================";			
		cout<<"\nEnter your choice ::";
		cin>>ch;
		switch(ch)
		{
			
			case 1:
				dict.create();
				break;
			case 2:
				dict.display();
				break;
			case 3:
				dict.find();
				break;
			case 4:
				dict.deleter();
				break;
			case 5:
				exit(0);				
				break;		
			default:
				cout<<"\n--->> Invalid choice...";
		}
	}while(ch != 0);
}

/* OUTPUT:-
sitrc@sitrc-OptiPlex-380:~/Desktop$ clear
sitrc@sitrc-OptiPlex-380:~/Desktop$ g++ 7.cpp
sitrc@sitrc-OptiPlex-380:~/Desktop$ ./a.out

========DICTIONARY USING HASH FUNCTION========
1.Create/Insert 
2.Display 
3.Find 
4.Delete 
5.Exit
==============================================
Enter your choice ::1

Enter word :: Addition

Enter meaning :: Summation

Do you want to enter next entry (y/n) : y

Enter word :: Ban

Enter meaning :: Prohibit

Do you want to enter next entry (y/n) : y

Enter word :: Dashing

Enter meaning :: Handsome

Do you want to enter next entry (y/n) : y

Enter word :: Shame

Enter meaning :: Guilt

Do you want to enter next entry (y/n) : y

Enter word :: Host

Enter meaning :: Anchor

Do you want to enter next entry (y/n) : n

========DICTIONARY USING HASH FUNCTION========
1.Create/Insert 
2.Display 
3.Find 
4.Delete 
5.Exit
==============================================
Enter your choice ::2

head[A]-->[ Addition, Summation ]--> NULL
head[B]-->[ Ban, Prohibit ]--> NULL
head[C]--> NULL
head[D]-->[ Dashing, Handsome ]--> NULL
head[E]--> NULL
head[F]--> NULL
head[G]--> NULL
head[H]-->[ Host, Anchor ]--> NULL
head[I]--> NULL
head[J]--> NULL
head[K]--> NULL
head[L]--> NULL
head[M]--> NULL
head[N]--> NULL
head[O]--> NULL
head[P]--> NULL
head[Q]--> NULL
head[R]--> NULL
head[S]-->[ Shame, Guilt ]--> NULL
head[T]--> NULL
head[U]--> NULL
head[V]--> NULL
head[W]--> NULL
head[X]--> NULL
head[Y]--> NULL
head[Z]--> NULL
========DICTIONARY USING HASH FUNCTION========
1.Create/Insert 
2.Display 
3.Find 
4.Delete 
5.Exit
==============================================
Enter your choice ::3

Enter word to be find :: Shame

Word : Shame
Mean : Guilt
========DICTIONARY USING HASH FUNCTION========
1.Create/Insert 
2.Display 
3.Find 
4.Delete 
5.Exit
==============================================
Enter your choice ::4

Enter word to be delete from dictionary :: Host

--->> Word is deleted form dictionay...
========DICTIONARY USING HASH FUNCTION========
1.Create/Insert 
2.Display 
3.Find 
4.Delete 
5.Exit
==============================================
Enter your choice ::2

head[A]-->[ Addition, Summation ]--> NULL
head[B]-->[ Ban, Prohibit ]--> NULL
head[C]--> NULL
head[D]-->[ Dashing, Handsome ]--> NULL
head[E]--> NULL
head[F]--> NULL
head[G]--> NULL
head[H]--> NULL
head[I]--> NULL
head[J]--> NULL
head[K]--> NULL
head[L]--> NULL
head[M]--> NULL
head[N]--> NULL
head[O]--> NULL
head[P]--> NULL
head[Q]--> NULL
head[R]--> NULL
head[S]-->[ Shame, Guilt ]--> NULL
head[T]--> NULL
head[U]--> NULL
head[V]--> NULL
head[W]--> NULL
head[X]--> NULL
head[Y]--> NULL
head[Z]--> NULL
========DICTIONARY USING HASH FUNCTION========
1.Create/Insert 
2.Display 
3.Find 
4.Delete 
5.Exit
==============================================
Enter your choice ::5
sitrc@sitrc-OptiPlex-380:~/Desktop$
*/

