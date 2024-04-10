#include<iostream>
#include<string>
using namespace std;

void sort(int ,string * ,int * );		//排序函式 

void average(int ,int * );		//平均函式 

typedef struct _Student		//宣告struct 
{
	string name;
	int score;
}Student;

Student student[1000];		//用struct宣告陣列 


int main()
{
	int i,n;		//宣告 n=>總學生數量 
	int *student_score;
	string *student_name; 
	
	cout<<"How many students and scores : ";		//輸入幾筆資料 
	cin>>n;
	while(n<=0)		//防止使用者輸入小於等於零的學生數量 
	{
		cout<<"Please enter positive and nonzero number : ";
		cin>>n;		//重新輸入學生數量 
	}
	cout<<endl;
	
	student_score=new int[n];		//dynamically allocated array
	student_name=new string[n];		//dynamically allocated array
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter the student's name and score : ";		//輸入學生名字,成績 
		cin>>student[i].name>>student[i].score;
		while(student[i].score<0)		//防止輸入的學生分數小於零 
		{
			cout<<"Do not enter negative score "<<endl;
			cout<<"Please enter positive score : ";
			cin>>student[i].score;		//重新輸入正確成績 
		}
		student_name[i]=student[i].name;		//將學生名字傳入陣列 
		student_score[i]=student[i].score;		//將學生成績傳入陣列 
	}
	cout<<endl;
	
	sort(n,student_name,student_score);		//呼叫排序函式 傳入總學生數量&學生名字&學生成績 
	average(n,student_score);			//呼叫平均函式 傳入總學生數量&學生成績 
	
	delete []student_score;		//delete array 
	delete []student_name;		//delete array
	
} 


void sort(int n,string *student_name,int *student_score)		//排序(bubble sort) 
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(*(student_score+j)>*(student_score+j+1))		//由小排到大 
			{
				swap(*(student_score+j),*(student_score+j+1));		//交換學生成績 
				swap(*(student_name+j),*(student_name+j+1));		//交換學生名字 
			}
		}
	}
	cout<<"所有學生成績從小到大排序後的結果"<<endl;
	for(i=0;i<n;i++)		//由小到大輸出學生名字,成績 
		cout<<" "<<*(student_name+i)<<" "<<*(student_score+i)<<endl;
	cout<<endl;
}

void average(int n,int *student_score)
{
	int i;
	float sum=0;		//sum=>成績總和 
	
	for(i=0;i<n;i++)		//所有學生成績的總和 
		sum+=*(student_score+i);

	cout<<"Average = "<<sum/n;	//輸出平均 
}












