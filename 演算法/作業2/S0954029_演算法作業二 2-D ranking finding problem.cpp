#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

double arr[2000][3], tempArr[2000][3]; //x, y, rank
int rank[2000];
int index=0;
bool before2D=true;

void heapConstruct( double arr[][3], int root )
{
	int left, right, max;
	double temp;
	
	max = root;
	left = root*2 + 1;
	right = root*2 + 2;
	
	if( before2D )
	{
		if( left < index && arr[left][0] > arr[max][0] )
		{
			max = left;
		}
		
		if( right < index && arr[right][0] > arr[max][0] )
		{
			max = right;
		}
		
		if( max != root )
		{
			temp = arr[max][0];
			arr[max][0] = arr[root][0];
			arr[root][0] = temp;
			
			temp = arr[max][1];
			arr[max][1] = arr[root][1];
			arr[root][1] = temp;
			
			temp = arr[max][2];
			arr[max][2] = arr[root][2];
			arr[root][2] = temp;
			
			heapConstruct( arr, max );
		}
	}
	else
	{
		if( left < index && arr[left][2] > arr[max][2] )
		{
			max = left;
		}
		
		if( right < index && arr[right][2] > arr[max][2] )
		{
			max = right;
		}
		
		if( max != root )
		{
			temp = arr[max][0];
			arr[max][0] = arr[root][0];
			arr[root][0] = temp;
			
			temp = arr[max][1];
			arr[max][1] = arr[root][1];
			arr[root][1] = temp;
			
			temp = arr[max][2];
			arr[max][2] = arr[root][2];
			arr[root][2] = temp;
			
			heapConstruct( arr, max );
		}
	}
	
}

void heapSort( double arr[][3] )
{
	int i, length;
	double temp;
	
	length = index;
	if( before2D )
	{
		for( i = length-1; i >= 1; i-- )
		{
			temp = arr[i][0];
			arr[i][0] = arr[0][0];
			arr[0][0] = temp;
			
			temp = arr[i][1];
			arr[i][1] = arr[0][1];
			arr[0][1] = temp;
			
			temp = arr[i][2];
			arr[i][2] = arr[0][2];
			arr[0][2] = temp;
			
			index = i;
			
			heapConstruct( arr, 0 );
		}
	}
	else
	{
		for( i = length-1; i >= 1; i-- )
		{
			temp = arr[i][0];
			arr[i][0] = arr[0][0];
			arr[0][0] = temp;
			
			temp = arr[i][1];
			arr[i][1] = arr[0][1];
			arr[0][1] = temp;
			
			temp = arr[i][2];
			arr[i][2] = arr[0][2];
			arr[0][2] = temp;
			
			index = i;
			
			heapConstruct( arr, 0 );
		}
	}
	
}

void rankFind( int left, int right )
{
	int i, mid, L, leftP, rightP, tempP, count=0;
	
	if( (right - left) <= 1 )
		return;
	
	mid = ( left + right ) / 2;
	leftP = left;
	rightP = mid;
	tempP = left;
	
	rankFind( left, mid );
	rankFind( mid, right );
	
	while( leftP < mid || rightP < right )
	{
		if( leftP == mid )
		{
			tempArr[tempP][0] = arr[rightP][0];
			tempArr[tempP][1] = arr[rightP][1];
			tempArr[tempP][2] = arr[rightP][2];
			tempArr[tempP][2] += count;
			tempP++;
			rightP++;
		}
		else if( rightP == right )
		{
			tempArr[tempP][0] = arr[leftP][0];
			tempArr[tempP][1] = arr[leftP][1];
			tempArr[tempP][2] = arr[leftP][2];
			tempP++;
			leftP++;
		}
		else if( arr[leftP][1] < arr[rightP][1] )
		{
			tempArr[tempP][0] = arr[leftP][0];
			tempArr[tempP][1] = arr[leftP][1];
			tempArr[tempP][2] = arr[leftP][2];
			count++;
			tempP++;
			leftP++;
		}
		else
		{
			tempArr[tempP][0] = arr[rightP][0];
			tempArr[tempP][1] = arr[rightP][1];
			tempArr[tempP][2] = arr[rightP][2];
			tempArr[tempP][2] += count;
			tempP++;
			rightP++;
		}
	}
	
	for( i = left; i < right; i++ )
	{
		arr[i][0] = tempArr[i][0];
		arr[i][1] = tempArr[i][1];
		arr[i][2] = tempArr[i][2];
	}
}

int main()
{
	int i;
	ifstream file;
	file.open("test2.txt");
	
	while( !file.eof() )
	{
		file >> arr[index][0] >> arr[index][1];
		arr[index][2] = 0;
		index++;
	}	
	
	int length = index;
	
	for( i = index/2-1; i >= 0; i-- )
	{
		heapConstruct( arr, i );
	}
	
	heapSort( arr );
		
	rankFind(0, length);
	
	before2D = false;
	index = length;
	for( i = index/2-1; i >= 0; i-- )
	{
		heapConstruct( arr, i );
	}
	heapSort( arr );
	
	cout << "–翴ぇrank : \n";
	for( i = 0; i < length; i++ )
	{
		cout << "    ( " << arr[i][0] << ", " << arr[i][1] << " ) : " << arr[i][2] << "\n";
	}
	cout << "(1) 郎い┮Τ翴计 : " << length << "\n";
	int max=0, min;
	double sum=0;
	for( i = 0; i < length; i++ )
	{
		if( i == 0 )
			min = arr[i][2];
		else if( arr[i][2] < min )
			min = arr[i][2];
		if( arr[i][2] > max )
			max = arr[i][2];
		sum += arr[i][2];
	}
	cout << "(2) 程rank : " << max << "\n";
	cout << "(3) 程rank : " << min << "\n";
	cout << "(4) キАrank(计翴ㄢ) : " << fixed << setprecision(2) << sum/length << "\n";
	
}

