#include <iostream>							//Made by S0954029���æ�
#include<iomanip>
#ifndef PATIENTACCOUNT_H
#define	PATIENTACCOUNT_H
using namespace std;

class PatientAccount							//�f�Hclass�A�i�]�m���ĶO�B��|�ѼơB�`��O�A����ܥX�`��O �B��|�Ѽ�  
{
	private :
			int serviceCharges;			//���ĶO 
			double totalCharges;		//�`��O
			int totalDays;				//��|�Ѽ� 
			double dailyRate; 			//��Q�v 
				
	public : 
			PatientAccount()				//�غc��ܡA�]��� 
			{
				serviceCharges = 0;	
				totalCharges = 0;			
				totalDays = 0;				 
				dailyRate = 870.69; 
				
			}
			void updateService(int money)		//��s���ĶO(��N�O+�ĶO)		
			{
				serviceCharges += money;
			}
			
			void setDays(int day)				//�l�ܦ�|�Ѽ� 
			{
				totalDays += day;
			}
			int getDays(){						//��ܦ�|�Ѽ� 
				return totalDays;
			}
			void showCharges(){																//����`��O 
				cout<<"�`��O�� "<<fixed<<setprecision(2)<<totalCharges<<" ��"<<endl; 
			}			
			void updateCharges(){				//��s�`��O 
				totalCharges = dailyRate*totalDays+serviceCharges;
			}
			
};
PatientAccount Patient;			//�ŧiPatientAccount,�n�Υ����ܼƤ~�i�H�QSurgery�MPharmacy�ϥΥB���|�Q�k�s 

#endif
