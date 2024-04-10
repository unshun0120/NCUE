#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main(int argc,char *argv[])
{
    int i,j;

    FILE *fp;
    char newline[10],*tempch=" ";
    int nodenum,edgenum,cost,begin,end;

	fp=fopen("cost239","r");
	fgets(newline,10,fp);

	sscanf(newline,"%i %i",&nodenum,&edgenum);

    int A[nodenum][nodenum];//�x�s�s�u���I
    for(i=0;i<nodenum;i++)
        for(j=0;j<nodenum;j++)
            A[i][j]=0;
    while(fgets(newline,10,fp) != NULL)
	{
	   sscanf(newline,"%i %i %i",&begin,&end,&cost);
	   A[begin][end]=1;
	   A[end][begin]=1;
	}
	fclose(fp);

            int r,f;
   /*         for(r=0;r<nodenum;r++)
               {
                    for(f=0;f<nodenum;f++)
                        printf("%d ",A[r][f]);
                    printf("\n");
               }printf("\n");
*/


    int k,c,pre,no;//��no��
    int b=0;//��b��temp(�h�X�Ӫ��ƦC�զX)
    int s=0,e=nodenum,cycle=0;
    int temp[nodenum];
    int order[20000][nodenum];//�w�]��-1
    int check_re[20000];
    int check_cycle[nodenum];
    for(i=0;i<20000;i++)
        for(j=0;j<nodenum;j++)
            order[i][j]=-1;
    for(i=0;i<nodenum;i++)
        order[i][0]=i;
    int adde;
    int t;//��j�p�ɪ�temp
    int smallest,compare;
    int m,n;
    int bascount=0, basis_edge_cnt=0, check_edge_cnt=0, cycle_basis_size=0;
    int basis[100][100], basis_edge[1000][2], check_edge[100][2];
    bool find_same=false;

    for(no=1;no<nodenum;no++)//�]�wno
    {
        adde=0;
        s=0;
        for(k=0;k<e;k++)//��e���[���s�u(e�w�]��nodenum)
        {
           s=s+b;
           b=0;
           pre=order[s][no-1];//pre�O�e�@�ӳ��I
           for((i=order[s][0]+1);i<nodenum;i++)//i=pre+1�ק�ק�ק�ק�ק�ק�ק�ק�ק�ק�ק�
           {
              if(A[pre][i]==1)
              {
                for(j=1;j<(no-1);j++)//for�j�� �ˬd���S�����ƪ����I
                {
                    if(order[s][j]==i)
                    {
                        j=-1;
                        break;
                    }
                }
                if(j!=-1)
                    temp[b++]=i;//b�p��h�X�Ӫ��ƦC�զX
              }
           }
           c=0;

           if(b>0)
           {
               adde=adde+b-1;
               for(i=e+adde;i>s;i--)//���Ჾ (���:e->e+adde)
               {
                  for(j=0;j<no;j++)
                      order[i+b-1][j]=order[i][j];
               }
               for(i=s;i<(s+b);i++)//�ɤW&�s�s�u
               {
                   order[i][no]=temp[c++];
                   for(j=0;j<no;j++)
                       order[i][j]=order[s][j];

                   //�ˬdcycle
                   if(no>1&&A[order[i][no]][order[i][0]]==1)
                   {

                       for(m=0;m<=no;m++)
                           check_cycle[m]=order[i][m];

                       compare=0;//�ˬd�O�_���ϧ�

                       for(m=1;m<=no;m++)
                           compare=compare*10+check_cycle[m];
                       compare=compare*10+check_cycle[0];

                       check_re[i]=0;
                       for(m=no;m>=0;m--)
                           check_re[i]=check_re[i]*10+check_cycle[m];

                       for(m=0;m<i;m++)
                       {
                           if(check_re[m]==compare)
                           {
                               m=-1;
                               break;
                           }
                       }
                       if(m!=-1)
                       {
                            /*fp=fopen("cycle.txt","w");
 for(j=0;j<=no;j++)
fprintf("%d->",order[i][j]);
fprintf("%d",order[i][0]);
fprintf("\n");
fclose(fp);*/
                            for(j=0;j<=no;j++)
                                printf("%d->",order[i][j]);
                            printf("%d",order[i][0]);
                            printf("\n");
                            
                            if( bascount < 2 )	//add �e���cycle 
                            {
                            	for( j = 0; j <= no; j++ )
                            	{
                            		basis[bascount][j] = order[i][j];
								}
								/*for( j = 0; j <= no; j++ )
								{
									cout << basis[bascount][j] << "->";
								}
								cout << basis[bascount][0] << endl;*/
								for( j = 0; j <= no; j++ )
                            	{
                            		find_same = false;
                            		if( j == no )
                            		{
                            			if( bascount == 0 )
                            			{
                            				if( order[i][j] < order[i][0] )
	                            			{
	                            				basis_edge[basis_edge_cnt][0] = order[i][j];
	                            				basis_edge[basis_edge_cnt][1] = order[i][0];
											}
											else
											{
												basis_edge[basis_edge_cnt][1] = order[i][j];
	                            				basis_edge[basis_edge_cnt][0] = order[i][0];
											}
										}
										else
										{
											if( order[i][j] < order[i][0] )	// remove same edge
	                            			{
	                            				for( m = 0; m < basis_edge_cnt; m++ )
	                            				{
	                            					if( basis_edge[m][0] == order[i][j] && basis_edge[m][1] == order[i][0] )
	                            					{
	                            						find_same = true;
	                            						break;
													}
												}
												if( m == basis_edge_cnt )
												{
													basis_edge[basis_edge_cnt][0] = order[i][j];
	                            					basis_edge[basis_edge_cnt][1] = order[i][0];
												}
											}
											else
											{
												for( m = 0; m < basis_edge_cnt; m++ )
	                            				{
	                            					if( basis_edge[m][0] == order[i][0] && basis_edge[m][1] == order[i][j] )
	                            					{
	                            						find_same = true;
	                            						break;
													}
												}
												if( m == basis_edge_cnt )
												{
													basis_edge[basis_edge_cnt][1] = order[i][j];
	                            					basis_edge[basis_edge_cnt][0] = order[i][0];
												}
											}
										}
									}
									else
									{
										if( bascount == 0 )
                            			{
                            				if( order[i][j] < order[i][j+1] )
	                            			{
	                            				basis_edge[basis_edge_cnt][0] = order[i][j];
	                            				basis_edge[basis_edge_cnt][1] = order[i][j+1];
											}
											else
											{
												basis_edge[basis_edge_cnt][1] = order[i][j];
	                            				basis_edge[basis_edge_cnt][0] = order[i][j+1];
											}
										}
										else
										{
											if( order[i][j] < order[i][j+1] )	// remove same edge
	                            			{
	                            				for( m = 0; m < basis_edge_cnt; m++ )
	                            				{
	                            					if( basis_edge[m][0] == order[i][j] && basis_edge[m][1] == order[i][j+1] )
	                            					{
	                            						find_same = true;
	                            						break;
													}
												}
												if( m == basis_edge_cnt )
												{
													basis_edge[basis_edge_cnt][0] = order[i][j];
	                            					basis_edge[basis_edge_cnt][1] = order[i][j+1];
												}
											}
											else
											{
												for( m = 0; m < basis_edge_cnt; m++ )
	                            				{
	                            					if( basis_edge[m][0] == order[i][j+1] && basis_edge[m][1] == order[i][j] )
	                            					{
	                            						find_same = true;
	                            						break;
													}
												}
												if( m == basis_edge_cnt )
												{
													basis_edge[basis_edge_cnt][1] = order[i][j];
	                            					basis_edge[basis_edge_cnt][0] = order[i][j+1];
												}
											}
										}
									}
									if( find_same == false )
                            			basis_edge_cnt++;
								}
								/*for( j = 0; j <= no; j++ )
									cout << order[i][j] << " ";
								cout << endl;
								for( j= 0; j < basis_edge_cnt; j++ )
								{
									cout << basis_edge[j][0] << " ";
									cout << basis_edge[j][1] << "\n";
								}
								cout << endl;*/
								
								/*for( j = 0; j <= no; j++ )
								{
									cout << basis[bascount][j] << "->";
								}
								cout << basis[bascount][0];
								cout << endl;*/
								
								bascount++;
							}
							else	//check�s�[��edge�O�_�P�w�bbasis�̪�edge���ۦP 
							{
								for( j = 0; j <= no; j++ )
								{	
									find_same = false; 
									if( j == no )
									{
										if( order[i][j] < order[i][0] )
										{
											for( m = 0; m < basis_edge_cnt; m++ )
											{
												if( order[i][j] == basis_edge[m][0] && order[i][0] == basis_edge[m][1] )
												{
													find_same = true;
													break;
												}
												else
												{
													find_same = false;
												}
											}
										}
										else
										{
											for( m = 0; m < basis_edge_cnt; m++ )
											{
												if( order[i][0] == basis_edge[m][0] && order[i][j] == basis_edge[m][1] )
												{
													find_same = true;
													break;
												}
												else
												{
													find_same = false;
												}
											}
										}
									}
									else
									{
										if( order[i][j] < order[i][j+1] )
										{
											for( m = 0; m < basis_edge_cnt; m++ )
											{
												if( order[i][j] == basis_edge[m][0] && order[i][j+1] == basis_edge[m][1] )
												{
													find_same = true;
													break;
												}
												else
												{
													find_same = false;
												}
											}
										}
										else
										{
											for( m = 0; m < basis_edge_cnt; m++ )
											{
												if( order[i][j+1] == basis_edge[m][0] && order[i][j] == basis_edge[m][1] )
												{
													find_same = true;
													break;
												}
												else
												{
													find_same = false;
												}
											}
										}
									}
									/*if( find_same == true)
										cout << "gg" << endl;*/
									if( find_same == false )	//�bbasis�̪�cycle�L�kspan�n�[�i�Ӫ�cycle 
									{
										for( m = 0; m <= no; m++ )	//��s�[��cycle���cycle basis�� 
		                            	{
		                            		basis[bascount][m] = order[i][m];
										}
										
										/*for( j = 0; j <= no; j++ )
										{
											cout << basis[bascount][j] << "->";
										}
										cout << basis[bascount][0];
										cout << endl;*/ 
										bascount++;
											
										for( n = 0; n <= no; n++ )	//��s�[�i��cycle��edge�[�ibasis_edge�� 
										{
											if( n == no )
											{
												if( order[i][n] < order[i][0] )	// remove same edge
		                            			{
		                            				for( m = 0; m < basis_edge_cnt; m++ )
		                            				{
		                            					if( basis_edge[m][0] == order[i][n] && basis_edge[m][1] == order[i][0] )
		                            					{
		                            						break;
														}
													}
													if( m == basis_edge_cnt )
													{
														basis_edge[basis_edge_cnt][0] = order[i][n];
		                            					basis_edge[basis_edge_cnt][1] = order[i][0];
		                            					basis_edge_cnt++; 
													}
												}
												else
												{
													for( m = 0; m < basis_edge_cnt; m++ )
		                            				{
		                            					if( basis_edge[m][0] == order[i][0] && basis_edge[m][1] == order[i][n] )
		                            					{
		                            						break;
														}
													}
													if( m == basis_edge_cnt )
													{
														basis_edge[basis_edge_cnt][1] = order[i][n];
		                            					basis_edge[basis_edge_cnt][0] = order[i][0];
		                            					basis_edge_cnt++; 
													}
												}
											}
											else
											{
												if( order[i][n] < order[i][n+1] )	// remove same edge
		                            			{
		                            				for( m = 0; m < basis_edge_cnt; m++ )
		                            				{
		                            					if( basis_edge[m][0] == order[i][n] && basis_edge[m][1] == order[i][n+1] )
		                            					{
		                            						break;
														}
													}
													if( m == basis_edge_cnt )
													{
														basis_edge[basis_edge_cnt][0] = order[i][n];
		                            					basis_edge[basis_edge_cnt][1] = order[i][n+1];
		                            					basis_edge_cnt++; 
													}
												}
												else
												{
													for( m = 0; m < basis_edge_cnt; m++ )
		                            				{
		                            					if( basis_edge[m][0] == order[i][n+1] && basis_edge[m][1] == order[i][n] )
		                            					{
		                            						break;
														}
													}
													if( m == basis_edge_cnt )
													{
														basis_edge[basis_edge_cnt][1] = order[i][n];
		                            					basis_edge[basis_edge_cnt][0] = order[i][n+1];
		                            					basis_edge_cnt++; 
													}
												}
											} 
										}
									}
								} 
								
								
							}
							
                            
                            cycle++;
                       }

                   }
               }
           }
           else//b==0
           {
               for(i=s;i<e+adde;i++)//���e��1��
               {
                  for(j=0;j<=no;j++)
                      order[i][j]=order[i+1][j];
               }
               adde--;
           }
        }
        e=e+adde;

    }
    
    cout << bascount << endl;
    //printf("%d cycles",cycle);
    getchar();

}
