//Study the inheritance and its types and methods of inheritance by creating a class of accounts and
//derived class are saving account and current account.

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

//Base class for accounts
class accounts
{
	protected:
	int accountNo;
	char name[20];
	
	public:
	accounts()
	{
		accountNo=0;
		strcpy(name, "NULL");
	}
	accounts(int n, char *s)
	{
		accountNo=n;
		strcpy(name, s);
	}
	void getdata()
	{
		cout<<"\nEnter the account number: ";
		cin>>accountNo;
		cout<<"\nEnter the name: ";
		cin>>name;
	}
	void showdata()
	{
		cout<<"\n\nAccount number: "<<accountNo;
		cout<<"\nName: "<<name;
	}
};

//Derived from accounts
class curr_acct: public accounts
{
	private:
	
	long double balance;
	float security;
	
	public:
	
	curr_acct()
	{
		security=1000;
		balance=0;
	}
	curr_acct(int accountNo, char* name, float balance): accounts(accountNo, name)
	{
		security=1000;
		this->balance=balance;
	}
	void deposit()
	{
		float d;
		cout<<"\nEnter the amount you want to deposit: ";
		cin>>d;
		balance+= d;
	}
	void withdraw()
	{
		float withdrawAmount;
		cout<<"\nEnter the amount to be withdrawn: ";
		cin>>withdrawAmount;
		if(withdrawAmount>(balance+security))
		{
			cout<<"\nThe request can't be completed due to low balance";
		}
		else
			balance = balance - withdrawAmount;
		
	}
	void getBalance()
	{
		printf("\nBalance: %.2LF", balance);
	}
	void display()
	{
		cout<<"A/C No.: "<<accountNo
			<<"\nName: "<<name	
			<<"\nBalance: "<<balance
			<<"\nSecurity: "<<security;
	}
};

//Derived from accounts
class sav_acct:public accounts
{
	private:
		long double balance;
		float rate;
		double interest;
		float penalty;
		float minBalance;
	public:
		sav_acct()
		{
			balance=interest=penalty=0.0;
			minBalance=1000;
			rate=2.5;
		}
		sav_acct(int accountNo, char* name, float balance): accounts(accountNo, name)
		{
			this->balance=balance;
			interest=penalty=0.0;
			minBalance=1000;
			rate=2.5;
		}
		void calc_interest()
		{
			interest = balance*rate/100.00;
			cout<<"\nInterest (annual): "<<interest;
		}
		void deposit()
		{
			float d;
			cout<<"\nEnter the amount you want to deposit: ";
			cin>>d;
			balance+= d;
		}
		void withdraw()
		{			
			float withdrawAmount;
			cout<<"\nEnter the amount to be withdrawn: ";
			cin>>withdrawAmount;
			if(withdrawAmount>balance)
			{
				cout<<"\nThe request can't be completed due to low balance";
			}
			else
				balance = balance - withdrawAmount;
			if(balance<minBalance)
			{
				penalty=(10.0/100)*(minBalance-balance);
			}
			
		}
		void getBalance()
		{
			printf("\nBalance: %.2LF", balance);
		}
		void display()
		{
			cout<<"\nA/C No.: "<<accountNo
				<<"\nName: "<<name	
				<<"\nBalance: "<<balance
				<<"\nRate: "<<rate
				<<"\nInterest: "<<interest
				<<"\nPenalty: "<<penalty
				<<"\nMinimum Balance: "<<minBalance<<endl;
		}
};

int main()
{
	short choice;
	sav_acct savingBank(140215, "Sidhant Goel", 10000);
	curr_acct currAccount(240102, "Tushar Gupta", 10000);
	do
	{
		cout<<"\nMENU FOR SAVING ACCOUNT"
			<<"\n1.Deposit"
			<<"\n2.Withdraw"
			<<"\n3.Display data"
			<<"\n4.Exit"
			<<"\n\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: savingBank.deposit();
					savingBank.getBalance();
					savingBank.calc_interest();
					break;
			case 2: savingBank.withdraw();
					savingBank.getBalance();
					savingBank.calc_interest();
					break;
			case 3: savingBank.display();
					break;
			case 4: break;
			default: cout<<"\nEnter a valid choice:";
		}
	} while(choice!=4);
	do
	{
		cout<<"\nMENU FOR CURRENT ACCOUNT"
			<<"\n1.Deposit"
			<<"\n2.Withdraw"
			<<"\n3.Display data"
			<<"\n4.Exit"
			<<"\n\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: currAccount.deposit();
					currAccount.getBalance();
					break;
			case 2: currAccount.withdraw();
					currAccount.getBalance();
					break;
			case 3: currAccount.display();
					break;
			case 4: break;
			default: cout<<"\nEnter a valid choice:";
		}
	} while(choice!=4);
	return 0;
}
