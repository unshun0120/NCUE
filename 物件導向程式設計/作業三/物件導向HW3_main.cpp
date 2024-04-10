/* 
	�t�d����:
			main function / Pharmacy class : made by S0954037������ 
			Surgery class / PatientAccount class : made by S0954029���ò� 

	�}�o���J�쪺���D&�ѨM���:
	
			���D(1) : �@�}�l�N PatientAccount (�x�s�f�H�`��O)�ŧi�b Surgery �M Pharmacy ��class��,�|�ɭP�C���I�sclass�ɳ��|���f�H�`��O�k�s�@��
					�@�ϱo�`��O���|�ܦ� 0 �L�k�O�d���e�Ҧs�U�����B
			�ѨM���D(1) :�N PatientAccount�]�m�������ܼƨϨ�Q	Suregry �� Pharmacy�I�s�ɤ��|�]���غc��ܨϨ��k�s�@ 
			
			���D(2) : �@�}�l�s�@ Surgery class��,�N�Ҧ�����N�����}�g�F�@�Ө禡�ɭP�{����²��B�I�s�·� 
			�ѨM���D(2) : �N�Ҧ���N�k���bcheckSurgery�A�A�U�h�P�_��N���� 
					
					 
*/ 

#include <iostream>								//Made by S0954037������ 
#include<iomanip>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h" 

using namespace std;

int main(){
	int surgery,medicine;							//�ŧi 
	char inpatient,buymedicine,checkout;						
	Surgery mysurgery;
	Pharmacy pharmacy;
	
	
	cout<<"�w��Ө�n�w����|"<<endl;
	
	do{
		cout<<"�аݱz�ݭn�����ƻ��N< 1.�G���ˬd(10000��) | 2.�������(150000��) | 3.����(8000��) | 4.�Ҫ�������(120000��) | 5.�Ǥ���(200000��) >";
		cin>>surgery;
		mysurgery.checkSurgery(surgery);						//�Ǥ�N������Surgery class 
		if(surgery==1){
			cout<<"���߱z�����G���ˬd��N�A�z���G�ܰ��d!"<<endl;
			break;
		} 	
		else if(surgery==2){
			cout<<"���߱z�A��N�ܦ����Q�A�z������w����!"<<endl;
			break;
		}	
		else if(surgery==3){
			cout<<"���߱z�A��N�ܦ����Q�A�z�����A���h���ҭW!"<<endl;
			break;
		}	
		else if(surgery==4){
			cout<<"���߱z�A��N�ܦ����Q�A�z���Ҫ����w�Q����!"<<endl;
			break;
		}	
		else if(surgery==5){
			cout<<"���߱z�A��N�ܦ����Q�A�z���Ǥw��������!"<<endl;
			break;
		}	
		else
			cout<<"��J���~�A�Э��s��J"<<endl;					//���b���� 
						 
	}while(1);
	
	do{
		cout<<"�аݬO�_�ݤJ�|�[����R�i(870.69��/��)?<Y/N>";	//�d�ݯf�H�O�_��| 
		cin>>inpatient;
		
		if(inpatient=='Y'||inpatient=='y'){						
			while(1){											//�p�G�O�A�ΰj��l�ܦ�|�ѼơA�ñN�ȳ]�m�bPatientAccount 
				Patient.setDays(1);								
				cout<<"��|��"<<Patient.getDays()<<"��"<<endl;			//�ϥ���ܦ�|�Ѽƪ�function 
				cout<<"�аݬO�_�ݭn�K�ʷs���Ī�?<Y/N>";					//�߰ݯf�H�O�_�R�� 
				cin>>buymedicine;
				do{													//�O���ܴN�i�J�j��A����f�H���Q�A�R�� 
					if(buymedicine=='Y'||buymedicine=='y'){
						cout<<"�аݻݭn�ʶR����Ī�?<1.��h��(10��)|2.�h�N��(15��)|3.�y�¿}��(20��)|4.���T�J(30��)|5.�ܥͯ�(50��)>";
						cin>>medicine;
						pharmacy.checkMedicine(medicine);
						cout<<"�аݬO�_�A���K���Ī�<Y/N>";			//�߰ݯf�H�O�_�A���R�� 
						cin>>buymedicine;
					}
				}while(buymedicine=='Y'||buymedicine=='y'); 
				cout<<"�аݱz�O�_�n�X�|?<Y/N>";						//�߰ݯf�H�O�_�X�|
				cin>>checkout;
				if(checkout=='Y'||checkout=='y'){					//�O���ܡA�N�p���`��O����ܥX�� 
					Patient.updateCharges();
					Patient.showCharges();
					break;
				}
				else
					continue;	
			}
			break;
		}
		else if(inpatient=='N'||inpatient=='n'){					//�p����|�@�˸߰ݬO�_�R�ġA�íp���O 
			cout<<"�аݬO�_�ݭn�K�ʷs���Ī�?<Y/N>";
			cin>>buymedicine;
			do{
				if(buymedicine=='Y'||buymedicine=='y'){
					cout<<"�аݻݭn�ʶR����Ī�?<1.��h��(10��)|2.�h�N��(15��)|3.�y�¿}��(20��)|4.���T�J(30��)|5.�ܥͯ�(50��)>";
					cin>>medicine;
					pharmacy.checkMedicine(medicine);
					cout<<"�аݬO�_�A���K���Ī�<Y/N>";
					cin>>buymedicine;
				}
			}while(buymedicine=='Y'||buymedicine=='y'); 
			Patient.updateCharges();
			Patient.showCharges();
			break;
		}
		else
			cout<<"��J���~�A�Э��s��J"<<endl; 					//���b���� 
	}while(1);	
	
	cout<<"���±z���f�U�A�w��A�����{"<<endl;
	
	return 0; 
}
