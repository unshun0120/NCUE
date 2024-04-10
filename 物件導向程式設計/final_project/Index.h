#include<iostream>
#ifndef INDEX_H
#define INDEX_H

class Index		//此 class 用來輸入客人在檔案中為第幾個客人 
{
	private :
		int index;
	public :
		Index()
		{
			index = -1;
		}
		Index( int dataIndex )
		{
			index = dataIndex;
		}
		int getIndex()
		{
			return index;
		}
};

#endif
