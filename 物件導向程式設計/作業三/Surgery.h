#include <iostream>									//Made by S0954029���æ�
#include<iomanip>
#ifndef SURGERY_H
#define	SURGERY_H
using namespace std;

class Surgery
{
	private : 
			int gastroscopy,		//�G���ˬd 
				appendectomy,		//������� 
				ligation,			//����
				thyroidectomy,		//�Ҫ�������
				nephrectomy;		//�Ǥ��� 		
	public : 
			Surgery(){						//�غc��ܡA�]��� 
				gastroscopy = 10000,		//�G���ˬd��O 
				appendectomy = 150000,		//���������O 
				ligation = 8000,			//���Ϫ�O 
				thyroidectomy = 120000,		//�Ҫ���������O 
				nephrectomy = 200000;		//�Ǥ�����O 
			}
			void checkSurgery(int typeSerial)							//�ˬd��N�����B�ñN��O�ǵ�PatientAccount 
			{
					switch(typeSerial){
					case 1:Patient.updateService(gastroscopy);
							break;
					case 2:Patient.updateService(appendectomy);
							break;
					case 3:Patient.updateService(ligation);
							break;
					case 4:Patient.updateService(thyroidectomy);
							break;
					case 5:Patient.updateService(nephrectomy);
							break;
				}
				
			}		
};

#endif
