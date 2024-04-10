#include<iostream>
using namespace std;

int charge(int ,float ,int ,int );		//inpatient
int charge(int ,int );		//outpatient
int check(int );	//防呆機制 

int main()
{
	int day,hospitalservice,medication,total,ex;		//宣告 
	float rate;
	char choose;
	cout<<"a => inpatient , b => outpatient : ";		//inpatient(住院) or outpatient(門診) 
	cin>>choose;
	if(choose!='a'&&choose!='b')		//防止輸入不是a或b 
	{
		do
		{
			cout<<"The choice is a or b"<<endl;
			cout<<"Please reenter the choice"<<endl;
			cout<<"a => inpatient , b => outpatient : ";
			cin>>choose;
		}while(choose!='a'&&choose!='b');
	}
	
	if(choose=='a')		//如果是inpatient 
	{
		cout<<"The number of days spent in the hospital : ";		//輸入住院的天數 
		cin>>day;
		ex=check(day);		//防呆機制 
		if(ex<0)		//如果有錯誤 
		{
			do		//重新輸入 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter the number of days spent in the hospital : ";
				cin>>day;
				ex=check(day);
			}while(ex<0);
		} 
		
		cout<<"The daily rate : ";		//輸入日利率 
		cin>>rate;	
		ex=check(rate);		//防呆機制 
		if(ex<0)		//如果有錯誤 
		{
			do		//重新輸入 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter the daily rate :　";
				cin>>rate;
				ex=check(rate);
			}while(ex<0);
		} 
		
		cout<<"Charges for hospital services : ";		//住院設備/服務的花費 
		cin>>hospitalservice;
		ex=check(hospitalservice);		//防呆機制 
		if(ex<0)		//如果有錯誤 
		{
			do		//重新輸入 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter　charges for hospital services : ";
				cin>>hospitalservice;
				ex=check(hospitalservice);
			}while(ex<0);
		} 
		
		cout<<"Hospital medication charges : ";		//醫院治療費用 
		cin>>medication;
		ex=check(medication);		//防呆機制 
		if(ex<0)		//如果有錯誤 
		{	
			do		//重新輸入 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter hospital medication charges : ";
				cin>>medication;
				ex=check(medication);
			}while(ex<0);
		} 
		
		total=charge(day,rate,hospitalservice,medication);		//inpatient總花費 
	}
	else if(choose=='b')		//如果是outpatient 
	{
		cout<<"Charges for hospital services : ";		//住院設備/服務的花費 
		cin>>hospitalservice;
		ex=check(hospitalservice);		//防呆機制 
		if(ex<0)		//如果有錯誤 
		{
			do		//重新輸入 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter charges for hospital services : ";
				cin>>hospitalservice;
				ex=check(hospitalservice);
			}while(ex<0);
		} 
		
		cout<<"Hospital medication charges : ";		//醫院治療費用 
		cin>>medication;
		ex=check(medication);		//防呆機制 
		if(ex<0)		//如果有錯誤 
		{
			do		//重新輸入 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter hospital medication charges : ";
				cin>>medication;
				ex=check(medication);
			}while(ex<0);
		} 
		
		total=charge(hospitalservice,medication);		//outpatient總花費 
	}
	
	cout<<"Total charges : "<<total;		//輸出inpatient or outpatient的總花費 
} 

int charge(int day,float rate,int hospitalservice,int medication)		//計算inpatient的總花費 
{
	int sum=0;
	sum+=day*rate+hospitalservice+medication;		//總和=天數*日利率+住院設備/服務的花費+醫院治療費用		
	return sum;		//回傳總花費 
}


int charge(int hospitalservice,int medication)		//計算outpatient的總花費 
{
	int sum=0;
	sum+=hospitalservice+medication;		//總和=住院設備/服務的花費+醫院治療費用	
	return sum;		//回傳總花費 
}

int check(int money)		//防呆機制 
{
	if(money<0)
		return -1;		//如果費用或天數是負的回傳-1 
	else
		return 1;		//如果費用或天數是正的或是0回傳1 
}





























