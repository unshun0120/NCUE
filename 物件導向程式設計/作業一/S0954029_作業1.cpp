#include<iostream>
using namespace std;

int charge(int ,float ,int ,int );		//inpatient
int charge(int ,int );		//outpatient
int check(int );	//���b���� 

int main()
{
	int day,hospitalservice,medication,total,ex;		//�ŧi 
	float rate;
	char choose;
	cout<<"a => inpatient , b => outpatient : ";		//inpatient(��|) or outpatient(���E) 
	cin>>choose;
	if(choose!='a'&&choose!='b')		//�����J���Oa��b 
	{
		do
		{
			cout<<"The choice is a or b"<<endl;
			cout<<"Please reenter the choice"<<endl;
			cout<<"a => inpatient , b => outpatient : ";
			cin>>choose;
		}while(choose!='a'&&choose!='b');
	}
	
	if(choose=='a')		//�p�G�Oinpatient 
	{
		cout<<"The number of days spent in the hospital : ";		//��J��|���Ѽ� 
		cin>>day;
		ex=check(day);		//���b���� 
		if(ex<0)		//�p�G�����~ 
		{
			do		//���s��J 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter the number of days spent in the hospital : ";
				cin>>day;
				ex=check(day);
			}while(ex<0);
		} 
		
		cout<<"The daily rate : ";		//��J��Q�v 
		cin>>rate;	
		ex=check(rate);		//���b���� 
		if(ex<0)		//�p�G�����~ 
		{
			do		//���s��J 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter the daily rate :�@";
				cin>>rate;
				ex=check(rate);
			}while(ex<0);
		} 
		
		cout<<"Charges for hospital services : ";		//��|�]��/�A�Ȫ���O 
		cin>>hospitalservice;
		ex=check(hospitalservice);		//���b���� 
		if(ex<0)		//�p�G�����~ 
		{
			do		//���s��J 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter�@charges for hospital services : ";
				cin>>hospitalservice;
				ex=check(hospitalservice);
			}while(ex<0);
		} 
		
		cout<<"Hospital medication charges : ";		//��|�v���O�� 
		cin>>medication;
		ex=check(medication);		//���b���� 
		if(ex<0)		//�p�G�����~ 
		{	
			do		//���s��J 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter hospital medication charges : ";
				cin>>medication;
				ex=check(medication);
			}while(ex<0);
		} 
		
		total=charge(day,rate,hospitalservice,medication);		//inpatient�`��O 
	}
	else if(choose=='b')		//�p�G�Ooutpatient 
	{
		cout<<"Charges for hospital services : ";		//��|�]��/�A�Ȫ���O 
		cin>>hospitalservice;
		ex=check(hospitalservice);		//���b���� 
		if(ex<0)		//�p�G�����~ 
		{
			do		//���s��J 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter charges for hospital services : ";
				cin>>hospitalservice;
				ex=check(hospitalservice);
			}while(ex<0);
		} 
		
		cout<<"Hospital medication charges : ";		//��|�v���O�� 
		cin>>medication;
		ex=check(medication);		//���b���� 
		if(ex<0)		//�p�G�����~ 
		{
			do		//���s��J 
			{
				cout<<"No input less than zero"<<endl;
				cout<<"Please reenter hospital medication charges : ";
				cin>>medication;
				ex=check(medication);
			}while(ex<0);
		} 
		
		total=charge(hospitalservice,medication);		//outpatient�`��O 
	}
	
	cout<<"Total charges : "<<total;		//��Xinpatient or outpatient���`��O 
} 

int charge(int day,float rate,int hospitalservice,int medication)		//�p��inpatient���`��O 
{
	int sum=0;
	sum+=day*rate+hospitalservice+medication;		//�`�M=�Ѽ�*��Q�v+��|�]��/�A�Ȫ���O+��|�v���O��		
	return sum;		//�^���`��O 
}


int charge(int hospitalservice,int medication)		//�p��outpatient���`��O 
{
	int sum=0;
	sum+=hospitalservice+medication;		//�`�M=��|�]��/�A�Ȫ���O+��|�v���O��	
	return sum;		//�^���`��O 
}

int check(int money)		//���b���� 
{
	if(money<0)
		return -1;		//�p�G�O�ΩΤѼƬO�t���^��-1 
	else
		return 1;		//�p�G�O�ΩΤѼƬO�����άO0�^��1 
}





























