#include<iostream>
#ifndef INDEX_H
#define INDEX_H

class Index		//�� class �Ψӿ�J�ȤH�b�ɮפ����ĴX�ӫȤH 
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
