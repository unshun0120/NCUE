#include<iostream>
#include<string>
using namespace std;

int dp[60][60];
string res[1000];
int lcsNum=0;

void allLCS(string n1, string n2, int len1, int len2, int LCSlens, char lcs[], int curn1, int curn2, int curlens)
{
	char ch, i, j;
	
	if( curlens == LCSlens ){
		lcs[curlens] = '\0';
		res[lcsNum] = lcs;
		lcsNum++;
		return ;
	}
	if( curn1 == len1 || curn2 == len2 )
		return ;
	for( ch = '0'; ch <= '9'; ch++ ){
		bool find = false;
		for( i = curn1; i < len1; i++ ){
			if( ch == n1[i] ){
				for( j = curn2 ; j < len2 ; j++ ){
					if(n1[i] == n2[j] && dp[i][j] == curlens){
						lcs[curlens] = n1[i];
						allLCS(n1, n2, len1, len2, LCSlens, lcs, i + 1, j + 1, curlens + 1);
						find = true;
						break;
					}
				}
			}
			if( find )
				break;
		}
	}
}

int main(){
	
	string n1, n2;
	int i, j, len1, len2, LCSlens, maxlens, index;
	
	while( cin >> n1 >> n2 ){
		len1 = n1.length();
		len2 = n2.length();
		lcsNum = 0;
			
		for( i = 0; i <= 50; i++ ){	//initial 
			for( j = 0; j <= 50; j++ ){
				dp[i][j] = 0;
			}
		}
		for( i = 0; i < 1000; i++ )
			res[i] = "";
		
		for( j = 0; j <= len2; j++ ){	//dp
			for( i = 0; i <= len1; i++ ){
				if( i != 0 && j != 0 ){
					if( n2[j-1] == n1[i-1] ){
						dp[i][j] = dp[i-1][j-1] + 1;
					}
					else{
						if( dp[i-1][j] > dp[i][j-1] ){
							dp[i][j] = dp[i-1][j];		
						}
						else{
							dp[i][j] = dp[i][j-1];
						}	
					} 
				} 
			}
		}
		
		LCSlens = dp[len1][len2];
		char lcs[LCSlens]="";
		allLCS( n1, n2, len1, len2, LCSlens, lcs, 0, 0, 0 );
		
		maxlens = 0;
		string max;
		for( i = 0; i < lcsNum; i++ ){
			if( res[i].length() >= maxlens ){
				if( res[i].length() == maxlens ){
					for( j = 0; j < maxlens; j++ ){
						if( res[i][j] > max[j] ){
							max = res[i];
							break;
						}
					}
    			}
				else{
			     	maxlens = res[i].length();
			     	max = res[i];
			    }
			}
			
		}
		if( max == "" ){
			cout << "0" << endl;
		}
		else{
			bool start0 = true;
			for( i = 0; i < maxlens; i++ ){
				if( max[i] == '0' && start0 == true )
					continue;
				else
					start0 = false;
				cout << max[i];
			}
			cout << endl; 
		}
		
	}
	
	
} 





 
