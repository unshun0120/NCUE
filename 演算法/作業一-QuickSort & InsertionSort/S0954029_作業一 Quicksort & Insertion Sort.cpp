#include<iostream>
#include<fstream>
using namespace std;

double arr[2000];
int index = 0;

void quickSort( double arr[], int start, int end )
{
	int i, j;
	double pivot, temp;
	
	if( start < end )
	{
		i = start;
		j = end;
		pivot = arr[start];
		
		while( i < j )
		{
			while( arr[j] >= pivot && j > i )
			{
				j--;
			}
			
			while( arr[i] <= pivot && i < j )
			{
				i++;
			}
			
			if( i < j )
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
		
		arr[start] = arr[i];
		arr[i] = pivot;                    	
		
		quickSort( arr, start, i-1 );
		quickSort( arr, i+1, end);
	}
}

void insertionSort( double arr[] )
{
	int i, j;
	double temp;
	
	for( i = 0; i < index; i++ )
	{
		for( j = 0; j < i; j++ )
		{
			if( arr[i] < arr[j] )
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
}

int main()
{
	int i, choose;
	
	ifstream file;
    file.open("test1.txt");
    
    while( !file.eof() )
    {
    	file >> arr[index];
		index++;
	}
	
	cout << "請輸入要執行的排序法或動作\n" << endl;
	cout << "1->執行快速排序法 2->執行插入排序法 3->程式結束 : ";
	cin >> choose;
	
	if( choose == 1 )
	{
		quickSort( arr, 0, index-1 );
		cout << endl;
		cout << "由小到大排序結果: ";
		for( i = 0; i < index; i++ )
			cout << arr[i] << " ";
		cout << endl;
		cout << "(1) 所有數的個數: " << index << endl;
		cout << "(2) 最大的數: " << arr[index-1] << endl;
		cout << "(3) 最小的數: " << arr[0] << endl;		
	}
	else if( choose == 2 )
	{
		insertionSort( arr );
		cout << endl;
		cout << "由小到大排序結果: ";
		for( i = 0; i < index; i++ )
			cout << arr[i] << " ";
		cout << endl;
		cout << "(1) 所有數的個數: " << index << endl;
		cout << "(2) 最大的數: " << arr[index-1] << endl;
		cout << "(3) 最小的數: " << arr[0] << endl;	
	}
	else if( choose == 3 )
	{
		return 0;
	}
    
	return 0;
} 
