#include<iostream>
#include<string>
using namespace std;

void sort(int ,string * ,int * );		//�ƧǨ禡 

void average(int ,int * );		//�����禡 

typedef struct _Student		//�ŧistruct 
{
	string name;
	int score;
}Student;

Student student[1000];		//��struct�ŧi�}�C 


int main()
{
	int i,n;		//�ŧi n=>�`�ǥͼƶq 
	int *student_score;
	string *student_name; 
	
	cout<<"How many students and scores : ";		//��J�X����� 
	cin>>n;
	while(n<=0)		//����ϥΪ̿�J�p�󵥩�s���ǥͼƶq 
	{
		cout<<"Please enter positive and nonzero number : ";
		cin>>n;		//���s��J�ǥͼƶq 
	}
	cout<<endl;
	
	student_score=new int[n];		//dynamically allocated array
	student_name=new string[n];		//dynamically allocated array
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter the student's name and score : ";		//��J�ǥͦW�r,���Z 
		cin>>student[i].name>>student[i].score;
		while(student[i].score<0)		//�����J���ǥͤ��Ƥp��s 
		{
			cout<<"Do not enter negative score "<<endl;
			cout<<"Please enter positive score : ";
			cin>>student[i].score;		//���s��J���T���Z 
		}
		student_name[i]=student[i].name;		//�N�ǥͦW�r�ǤJ�}�C 
		student_score[i]=student[i].score;		//�N�ǥͦ��Z�ǤJ�}�C 
	}
	cout<<endl;
	
	sort(n,student_name,student_score);		//�I�s�ƧǨ禡 �ǤJ�`�ǥͼƶq&�ǥͦW�r&�ǥͦ��Z 
	average(n,student_score);			//�I�s�����禡 �ǤJ�`�ǥͼƶq&�ǥͦ��Z 
	
	delete []student_score;		//delete array 
	delete []student_name;		//delete array
	
} 


void sort(int n,string *student_name,int *student_score)		//�Ƨ�(bubble sort) 
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(*(student_score+j)>*(student_score+j+1))		//�Ѥp�ƨ�j 
			{
				swap(*(student_score+j),*(student_score+j+1));		//�洫�ǥͦ��Z 
				swap(*(student_name+j),*(student_name+j+1));		//�洫�ǥͦW�r 
			}
		}
	}
	cout<<"�Ҧ��ǥͦ��Z�q�p��j�Ƨǫ᪺���G"<<endl;
	for(i=0;i<n;i++)		//�Ѥp��j��X�ǥͦW�r,���Z 
		cout<<" "<<*(student_name+i)<<" "<<*(student_score+i)<<endl;
	cout<<endl;
}

void average(int n,int *student_score)
{
	int i;
	float sum=0;		//sum=>���Z�`�M 
	
	for(i=0;i<n;i++)		//�Ҧ��ǥͦ��Z���`�M 
		sum+=*(student_score+i);

	cout<<"Average = "<<sum/n;	//��X���� 
}












