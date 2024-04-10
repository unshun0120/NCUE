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
	
	cout << "�п�J�n���檺�ƧǪk�ΰʧ@\n" << endl;
	cout << "1->����ֳt�ƧǪk 2->���洡�J�ƧǪk 3->�{������ : ";
	cin >> choose;
	
	if( choose == 1 )
	{
		quickSort( arr, 0, index-1 );
		cout << endl;
		cout << "�Ѥp��j�Ƨǵ��G: ";
		for( i = 0; i < index; i++ )
			cout << arr[i] << " ";
		cout << endl;
		cout << "(1) �Ҧ��ƪ��Ӽ�: " << index << endl;
		cout << "(2) �̤j����: " << arr[index-1] << endl;
		cout << "(3) �̤p����: " << arr[0] << endl;		
	}
	else if( choose == 2 )
	{
		insertionSort( arr );
		cout << endl;
		cout << "�Ѥp��j�Ƨǵ��G: ";
		for( i = 0; i < index; i++ )
			cout << arr[i] << " ";
		cout << endl;
		cout << "(1) �Ҧ��ƪ��Ӽ�: " << index << endl;
		cout << "(2) �̤j����: " << arr[index-1] << endl;
		cout << "(3) �̤p����: " << arr[0] << endl;	
	}
	else if( choose == 3 )
	{
		return 0;
	}
    
	return 0;
} 
