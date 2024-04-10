/* 
	負責部分:
			main function / Pharmacy class : made by S0954037莊明憲 
			Surgery class / PatientAccount class : made by S0954029李永紳 

	開發中遇到的問題&解決方案:
	
			問題(1) : 一開始將 PatientAccount (儲存病人總花費)宣告在 Surgery 和 Pharmacy 的class中,會導致每次呼叫class時都會讓病人總花費歸零一次
					　使得總花費都會變成 0 無法保留之前所存下的金額
			解決問題(1) :將 PatientAccount設置成全域變數使其被	Suregry 或 Pharmacy呼叫時不會因為建構函示使其歸零　 
			
			問題(2) : 一開始製作 Surgery class時,將所有的手術都分開寫了一個函式導致程式不簡潔且呼叫麻煩 
			解決問題(2) : 將所有手術歸類在checkSurgery，再下去判斷手術種類 
					
					 
*/ 

#include <iostream>								//Made by S0954037莊明憲 
#include<iomanip>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h" 

using namespace std;

int main(){
	int surgery,medicine;							//宣告 
	char inpatient,buymedicine,checkout;						
	Surgery mysurgery;
	Pharmacy pharmacy;
	
	
	cout<<"歡迎來到好安全醫院"<<endl;
	
	do{
		cout<<"請問您需要接受甚麼手術< 1.胃鏡檢查(10000元) | 2.闌尾切除(150000元) | 3.結紮(8000元) | 4.甲狀腺切除(120000元) | 5.腎切除(200000元) >";
		cin>>surgery;
		mysurgery.checkSurgery(surgery);						//傳手術種類給Surgery class 
		if(surgery==1){
			cout<<"恭喜您完成胃鏡檢查手術，您的胃很健康!"<<endl;
			break;
		} 	
		else if(surgery==2){
			cout<<"恭喜您，手術很成順利，您的闌尾已切除!"<<endl;
			break;
		}	
		else if(surgery==3){
			cout<<"恭喜您，手術很成順利，您不必再為懷孕所苦!"<<endl;
			break;
		}	
		else if(surgery==4){
			cout<<"恭喜您，手術很成順利，您的甲狀腺已被切除!"<<endl;
			break;
		}	
		else if(surgery==5){
			cout<<"恭喜您，手術很成順利，您的腎已完美切除!"<<endl;
			break;
		}	
		else
			cout<<"輸入錯誤，請重新輸入"<<endl;					//防呆機制 
						 
	}while(1);
	
	do{
		cout<<"請問是否需入院觀察或靜養(870.69元/日)?<Y/N>";	//查看病人是否住院 
		cin>>inpatient;
		
		if(inpatient=='Y'||inpatient=='y'){						
			while(1){											//如果是，用迴圈追蹤住院天數，並將值設置在PatientAccount 
				Patient.setDays(1);								
				cout<<"住院第"<<Patient.getDays()<<"天"<<endl;			//使用顯示住院天數的function 
				cout<<"請問是否需要添購新的藥物?<Y/N>";					//詢問病人是否買藥 
				cin>>buymedicine;
				do{													//是的話就進入迴圈，直到病人不想再買藥 
					if(buymedicine=='Y'||buymedicine=='y'){
						cout<<"請問需要購買何種藥物?<1.止痛藥(10元)|2.退燒藥(15元)|3.咳嗽糖漿(20元)|4.類固醇(30元)|5.抗生素(50元)>";
						cin>>medicine;
						pharmacy.checkMedicine(medicine);
						cout<<"請問是否再次添購藥物<Y/N>";			//詢問病人是否再次買藥 
						cin>>buymedicine;
					}
				}while(buymedicine=='Y'||buymedicine=='y'); 
				cout<<"請問您是否要出院?<Y/N>";						//詢問病人是否出院
				cin>>checkout;
				if(checkout=='Y'||checkout=='y'){					//是的話，就計算總花費並顯示出來 
					Patient.updateCharges();
					Patient.showCharges();
					break;
				}
				else
					continue;	
			}
			break;
		}
		else if(inpatient=='N'||inpatient=='n'){					//如不住院一樣詢問是否買藥，並計算花費 
			cout<<"請問是否需要添購新的藥物?<Y/N>";
			cin>>buymedicine;
			do{
				if(buymedicine=='Y'||buymedicine=='y'){
					cout<<"請問需要購買何種藥物?<1.止痛藥(10元)|2.退燒藥(15元)|3.咳嗽糖漿(20元)|4.類固醇(30元)|5.抗生素(50元)>";
					cin>>medicine;
					pharmacy.checkMedicine(medicine);
					cout<<"請問是否再次添購藥物<Y/N>";
					cin>>buymedicine;
				}
			}while(buymedicine=='Y'||buymedicine=='y'); 
			Patient.updateCharges();
			Patient.showCharges();
			break;
		}
		else
			cout<<"輸入錯誤，請重新輸入"<<endl; 					//防呆機制 
	}while(1);	
	
	cout<<"謝謝您的惠顧，歡迎再次光臨"<<endl;
	
	return 0; 
}
