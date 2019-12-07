#include<iostream>
#include<fstream>
using namespace std;
class user
{
	protected:
		int acno,balance;
		char name[50];
		public:
			void create();
			void search(int);
			void deposit(int);
			void withdraw(int);
};
void user::create()
{
	cout<<"Enter account number:";
	cin>>acno;
	cout<<"Enter user name:";
	cin>>name;
	cout<<"Enter the opening balance:";
	cin>>balance;
	cout<<"You have successfully created your bank account"<<endl<<endl;
}
void user::search(int s)
{
	if(acno==s)
	{
		cout<<"Details are-------------"<<endl;
	    cout<<"Account number:"<<acno<<endl;
    	cout<<"User name:"<<name<<endl;
    	cout<<"Remaining balance:"<<balance<<endl<<endl;
	}
	else
	{
		cout<<"account number does not exist"<<endl<<endl;
	}
}
void user::deposit(int d)
{
	if(acno==d)
	{
	    cout<<"Enter the amount you want to deposit:";
		int amount;
		cin>>amount;
		balance+=amount;
		cout<<"Account was successfully updated........"<<endl<<endl;
	}
	else
	{
		cout<<"please enter correct account number"<<endl<<endl;
	}
}
void user::withdraw(int w)
{
	if(acno==w)
	{
	    cout<<"Enter the amount you want to withdraw:";
		int amount;
		cin>>amount;
		balance-=amount;
		cout<<"Account was successfully updated........"<<endl<<endl;
	}
	else
	{
		cout<<"please enter correct account number"<<endl<<endl;
	}
}
void create1();
void search1(int);
void deposit1(int);
void withdraw1(int);
main()
{
	cout<<"MY PROJECT ONLINE BANKING TRANSECTION"<<endl<<endl;
	int choice;
	while(choice!=5){
	cout<<"Press 1:TO CREATE A NEW ACCOUNT"<<endl<<"Press 2:TO SEARCH YOUR ACCOUNT DETAILS"<<endl;
	cout<<"Press 3:TO DEPOSIT MONEY"<<endl<<"Press 4:TO WITHDRAW MONEY"<<endl;
	cout<<"Press 5:EXIST"<<endl<<endl;
	cout<<"Enter your choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			create1();
			break;
		case 2:
			cout<<"Enter account number to search:";
			int a;
			cin>>a;
			search1(a);
			break;
		case 3:
			cout<<"Enter the account number where you want to deposit money:";
			int b;
			cin>>b;
			deposit1(b);
			break;
		case 4:
			cout<<"Enter the account number from where you want to withdraw money:";
			int c;
			cin>>c;
			withdraw1(c);
			break;
		case 5:
		    cout<<"Try next time"<<endl;
			break;			
	}
}
}
void create1()
{
	user obj;
	fstream file1;
	file1.open("abc.txt",ios::binary|ios::out);
	obj.create();
	file1.write((char*)&obj,sizeof(obj));
	file1.close();
}
void search1(int a)
{
	user obj;
	fstream file2;
	file2.open("abc.txt",ios::binary|ios::in);
	file2.read((char*)&obj,sizeof(obj));
	obj.search(a);
	file2.close();
}
void deposit1(int b)
{
	user obj;
	fstream file3;
	file3.open("abc.txt",ios::binary|ios::in);
	file3.read((char*)&obj,sizeof(obj));
	obj.deposit(b);
	file3.close();
	file3.open("abc.txt",ios::binary|ios::out);
	file3.write((char*)&obj,sizeof(obj));
	file3.close();
}
void withdraw1(int c)
{
	user obj;
	fstream file4;
	file4.open("abc.txt",ios::binary|ios::in);
	file4.read((char*)&obj,sizeof(obj));
	obj.withdraw(c);
	file4.close();
	file4.open("abc.txt",ios::binary|ios::out);
	file4.write((char*)&obj,sizeof(obj));
	file4.close();
}
