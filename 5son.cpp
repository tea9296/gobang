
#include<iostream> 
#include<string> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std; 
/*short board[17][17]; 
bool endtry; 
int white=0;
void default_board();//��l�ƴѽL15x15 
void show_board();//��ܴѽL15x15 
void put_chess(short,short,short);//�U��+�P�_���L�Ѥl 
bool winner(short i,short j,short whosturn);//�ӭt win = 1 �ӧQ 
void go(int n) ; // �C���}�l 
void multiplayer();//��Ӫ��a, �´ѥ��U 

*/

//class of  computer
int white=0;

class Gobang{  
        
      public:   
                
             short board[17][17];          //�ѽL  
           	 bool endtry;
             int computernum,humannum;         //�Ѥl   
             int p1,p2;                       //�Ѥl   
             int last1,last2;                    //�����W�@�B    
             int comresults[15][15];             //�s����  
             int humresults[15][15];  
             int temp[15][15];             //15x15�{�ɴ� �L 
             int max_com,max_hum,max_com_i,max_com_j,max_hum_i,max_hum_j;             
             int total_com,total_hum;              //�q���M���a�`��   
           
     
     		 
              void default_board();//��l�ƴѽL15x15 
			  void show_board();//��ܴѽL15x15 
			  void put_chess(short,short,short);//�U��+�P�_���L�Ѥl 
			  bool winner(short i,short j,short whosturn);//�ӭt win = 1 �ӧQ 
			  void go(int n) ; // �C���}�l 
			  void multiplayer();//��Ӫ��a, �´ѥ��U 	
              Gobang();  
              void setboard(int ,int,int);     //���ܴѤl   
              void count();                         //�O�ơA�Ѥl��   
              void count_total();                //���`��   

 
				 void getfive(int i,int j);             // Ū���ƾڡA�s�J5*5 ���ѽL��   
            
              void getsix(int,int);  
              int ifwin();                     //�P�_�ӭt        
              void think();  
              void getresults();          //�����U�l   
              void r_four();  
              void r_three();             
              void r_two();  
              int returngoback();  
                
   
};  








int main()//�� �D�{�� �� 
{ 	string bw2,bw3;
    string who_first;
    int COMI2,COMI3,COMJ2,COMJ3; //�����q���H���� 
	cout<<"������(1)�ΰ����(0)?\n";
    getline(cin,who_first);
    string choose; 
    int I2,J2,I3,J3;
    char tem1,tem2;
    Gobang g;
    do{ 
       g.default_board(); 
       //FIRST STEP
       g.put_chess(8,8,1);
       g.show_board();
       
       
       
       //������ 
      if(who_first=="1"){
	  
       //SECOND STEP
       
      
    step2:   
		cout<<"���դl�Achoose between 7-9 and G-I\n";    
    	getline(cin,bw2);
       for(int n=0 ;n<bw2.length() ;n++){
       if(bw2[n]>='g' && bw2[n]<='i'){ 
           J2 = bw2[n] - 'a' + 1; 
        }else if(bw2[n]>='G' && bw2[n]<='I'){ 
           J2 = bw2[n] - 'A' + 1; 
        }else if(bw2[n]>='7' && bw2[n]<='9'){ 
           I2 = I2*10 + bw2[n] - '0'; 
        }else if(bw2[n] == ' '){ 
           continue; 
        }else{ 
           cout <<"��J�F���X�k���r���I"<< endl; 
           system("pause"); 
           goto step2; 
        } 
     } 
       
       g.put_chess(I2,J2,2);
       system("cls"); 
       g.show_board();
       
       
       //THIRD STEP
       
      
       
       
    step3:   
    	cout<<"���¤l�Achoose between 6-10 and F-J\n";
	   getline(cin,bw3);
	   
       for(int n=0 ;n<bw3.length() ;n++){
       if(bw3[n]>='f' && bw3[n]<='j'){ 
           J3 = bw3[n] - 'a' + 1; 
        }else if(bw3[n]>='F' && bw3[n]<='J'){ 
           J3 = bw3[n] - 'A' + 1; 
        }else if(bw3[n]>='6' && bw3[n]<='9'){ 
           I3 = I3*10 + bw3[n] - '0'; 
        }else if(n<bw3.length()-1 && bw3[n]=='1' && bw3[n+1]=='0'){
		 	I3=I3*10 + bw3[n] - '0';
	    }else if(n>0 && bw3[n-1]=='1' && bw3[n]=='0'){
			I3=I3*10 + bw3[n] - '0';
	   		
        }else if(bw3[n] == ' '){ 
           continue; 
        }else{ 
           cout <<"��J�F���X�k���r���I"<< endl; 
           system("pause"); 
           goto step3; 
        } 
     } 
      g.put_chess(I3,J3,1);
      g.show_board();
 }	  
    
	  
	 
       //����� 
       else if(who_first=="0")
       {
       	// �H�����l 
       	srand( (unsigned)time(NULL) );
       	COMI2=rand() % 3 +7;
       	Sleep(1000);
       	COMJ2=rand() % 3 + 7;
       	g.put_chess(COMI2,COMJ2,2);
       	system("cls"); 
       g.show_board();
       	Sleep(3000);
       	COMI3=rand() % 5 +6;
       	COMJ3=rand() % 5 + 6;
       	
       	 g.put_chess(COMI3,COMJ3,1);
       system("cls"); 
       g.show_board();
	   }  
	  
	  
	  
       
       
       
       
      
       g.go(white);
       //multiplayer(); 
       cout <<"��J y �A���@���H�G"; 
       getline(cin,choose); 
    }while(choose == "y" || choose == "Y"); 
    return 0; 
} 


//�}�l�C��//

void Gobang::go(int white){  
       
       
       
             cout<<"�n�´ѩΥմ�?�G"<<endl;  
             cout<<"     1.�´�"<<endl;  
             cout<<"     2.�մ�"<<endl;  
             int n;cin>>n;  
             if(n==2)  white=1;  
     while(1){  
              if(ifwin()==1) {  
                                 show_board();  
                                cout<<"�q���ӧQ�I"<<endl;   
                              break;  
                              }  
              if(ifwin()==2){  
                              show_board(); 
                              cout<<"���a�ӧQ�I"<<endl;  
                              break;  
                              }   
             show_board(); 
             multiplayer();   
              if(returngoback()==1) {cout<<"�C�������I"<<endl;return;}  
              if(ifwin()==1) {  
                               show_board();  
                              cout<<"�q���ӧQ�I"<<endl;  
                              break;  
                              }  
              if(ifwin()==2){  
                              show_board();  
                              cout<<"���a�ӧQ�I"<<endl;  
                              break;  
                              }   
              think();  
              }  
              
             
              
     }
	   



Gobang::Gobang(){  
                 
                                  
                 for(int i=0;i<5;i++)  
                         for(int j=0;j<5;j++)  
                                {five[i][j]=0;}  
                 computernum=0;  
                 humannum=0;  
                 p1=0;p2=0;  
                 last1=-1;last2=-1;       //-1��ܩ|���l   
                 max_com=0;max_hum=0;max_com_i=0;  
                 max_com_j=0;max_hum_i=0;max_hum_j=0;  
                 total_com=0;total_hum=0;  
                 goback=0;  
}  



void Gobang::count(){  
     computernum=0;  
     humannum=0;  
     for(int i=1;i<16;i++)  
         for(int j=1;j<16;j++){  
                 if(board[i][j]==1) computernum++;  
                 if(board[i][j]==2) humannum++;  
                 p1=computernum;p2=humannum;  
                 }  
}  







  
//�p��q���M���a�o��   
   
void Gobang::count_total(){  
       
     total_com=0;total_hum=0;  
     for(int i=1;i<15;i++)  
            for(int j=0;j<15;j++){  
                    comresults[i][j]=0;  
                    humresults[i][j]=0;}                //�C�����m�s   
       
       
       //�}�l����   
       r_four();  
       r_three();  
       r_two();  
         
       //���}�p��U�۪��o��   
       for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    total_com+=comresults[i][j];  
                    total_hum+=humresults[i][j];  
                    }  
                      
       //��F�A�[1000  
         
       //�P�_�O�_�i�H�U�@�l�N�ߧY����   
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]!=0) continue;       //��Ŧ�   
                  board[i+1][j+1]=1;  
                  if(ifwin()==1) {total_com+=1000;}                  //�q��  
                  board[i+1][j+1]=0;                      //�Ϊ���m���U�l   
                  }  
         }  
           
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]!=0) continue;       //��Ŧ�   
                  board[i+1][j+1]=2;  
                  if(ifwin()==2) {total_hum+=1000;}                  //���a   
                  board[i+1][j+1]=0;                      //�Ϊ���m���U�l   
                  }  
         }   
         
}  










  
void Gobang::getfive(int i,int j){  
     for(int m=0;m<5;m++)  
         for(int n=0;n<5;n++)  
                 five[m][n]=board[m+i+1][n+j+1];  
}  
  
  
  
void Gobang::getsix(int i,int j){  
     for(int m=0;m<6;m++)  
         for(int n=0;n<6;n++)  
                 six[m][n]=board[m+i+1][n+j+1];  
}  





                        
//�q�����   
void Gobang::think(){  
       
     total_com=0;total_hum=0;  
       
     //�����P�_�O�_�i�H�U�@�l�N�ߧY����   
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]!=0) continue;       //��Ŧ�   
                  board[i+1][j+1]=1;  
                  if(ifwin()==1) {last1=i;last2=j;return;}                  //???   
                  board[i+1][j+1]=0;                      //�Ϊ���m���U�l   
                  }  
         }  
           
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]!=0) continue;       //��Ŧ�   
                  board[i+1][j+1]=2;  
                  if(ifwin()==2) {board[i+1][j+1]=1;last1=i;last2=j;return;}                  //����a   
                  board[i+1][j+1]=0;                      //�Ϊ���m���U�l   
                  }  
         }      
           
  
   /*        
           
      //??�����Ĥ@�B�A��l�A��??��   
      if(computernum==0) {  
                         if(last1<=2&&board[last1+1][last2]==0)   
                            {board[last1+1][last2]=1;last1++;return; }  
                               else if(last1>=12&&board[last1-1][last2]==0)   
                                     {board[last1-1][last2]=1;last1--;return;}  
                                        else if(last2<=2&&board[last1][last2+1]==0)   
                                            {board[last1][last2+1]=1;last2++;return;}  
                                                else if(last2>=12&&board[last1][last2-1]==0)   
                                                     {board[last1][last2-1]=1;last2--;return;}   
                                                        else if(board[last1+1][last2]==0)   
                                                           {board[last1+1][last2]=1;last1++;return;}  
                                                                  else if(board[last1-1][last2]==0)   
                                                                        {board[last1-1][last2]=1;last1--;return;}  
                                                                          else if(board[last1][last2+1]==0)   
                                                                                  {board[last1][last2+1]=1;last2++;return;}  
                                                                                       else if(board[last1][last2-1]==0)   
                                                                                                {board[last1][last2-1]=1;last2--;return;}  
                         }  
       
                        */ 
           
   //�H�W�����ŦX�A�}�l�l����  
   getresults();   
       
              
          
    
}     














  
void Gobang::getresults(){  
       
          for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    comresults[i][j]=0;  
                    humresults[i][j]=0;}                //�C�����m�s   
       max_com=0;max_hum=0;max_com_i=0;  
       max_com_j=0;max_hum_i=0;max_hum_j=0;  
         
         
       //�}�l����   
       r_four();  
       r_three();  
       r_two();  
         
       //���q���M���a���̰����A�}�O�s�䧤?   
       for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    if(comresults[i][j]>max_com){  
                                                 max_com=comresults[i][j];  
                                                 max_com_i=i;  
                                                 max_com_j=j;  
                                                 }  
                    if(humresults[i][j]>max_hum){  
                                                 max_hum=humresults[i][j];  
                                                 max_hum_i=i;  
                                                 max_hum_j=j;  
                                                 }  
                    }   
                      
       //���R�̰����A�M�w��άO��  
         
       if(max_com>=1000) {                                      //�q���ন�|   
                       board[max_com_i+1][max_com_j+1]=1;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=1000) {                                      //����a�|   
                       board[max_hum_i+1][max_hum_j+1]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
       if(max_com>=18) {                                      //�q���ন���T �]�Χ�h�^   
                       board[max_com_i+1][max_com_j]+1=1;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=18) {                                      //����a���T �]�Χ�h�^   
                       board[max_hum_i+1][max_hum_j+1]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
         
       if(max_com==17||max_com==16) {                                      //�t�@��������`?�T  
                       board[max_com_i+1][max_com_j+1]=1;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum==17||max_hum==16) {                                        
                       board[max_hum_i+1][max_hum_j+1]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
                         
                         
       if(max_com<16&&max_com>=10) {                                      //3,3+1 ,3+2�A?4   
                       board[max_com_i+1][max_com_j+1]=1;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum<16&&max_hum>=10) {                                        
                       board[max_hum_i+1][max_hum_j+1]=1;   
                       last1=max_hum_i;last2=max_hum_j;         
                       return;  
                       }                                        
  
       //��L��?���ު��a�A??���̦n��  
       board[max_com_i+1][max_com_j+1]=1;  
       last1=max_com_i;last2=max_com_j;   
       return;  
}   
  
  
  
  
void Gobang::r_four(){  
       
     for(int i=1;i<14;i++)  
         for(int j=1;j<14;j++){  
                   
                 if(board[i+1][j+1]!=0) continue;  
                   
                   
                 //�Ĥ@����?    xooo@x  
                   
                 if(board[i+1][j+2]==0&&board[i+1][j]==1&&board[i+1][j-1]==1&&board[i+1][j-2]==1&&board[i+1][j-3]==0) comresults[i][j]+=100;  
                 if(board[i+2][j+2]==0&&board[i][j]==1&&board[i-1][j-1]==1&&board[i-2][j-2]==1&&board[i-3][j-3]==0) comresults[i][j]+=100;   
                 if(board[i+2][j+1]==0&&board[i][j+1]==1&&board[i-1][j+1]==1&&board[i-2][j+1]==1&&board[i-3][j+1]==0) comresults[i][j]+=100;  
                 if(board[i+2][j]==0&&board[i][j+2]==1&&board[i-1][j+3]==1&&board[i-2][j+4]==1&&board[i-3][j+5]==0) comresults[i][j]+=100;  
                 if(board[i+1][j]==0&&board[i+1][j+2]==1&&board[i+1][j+3]==1&&board[i+1][j+4]==1&&board[i+1][j+5]==0) comresults[i][j]+=100;  
                 if(board[i][j]==0&&board[i+2][j+2]==1&&board[i+3][j+3]==1&&board[i+4][j+4]==1&&board[i+5][j+5]==0) comresults[i][j]+=100;  
                 if(board[i][j+1]==0&&board[i+2][j+1]==1&&board[i+3][j+1]==1&&board[i+4][j+1]==1&&board[i+5][j+1]==0) comresults[i][j]+=100;  
                 if(board[i][j+2]==0&&board[i+2][j]==1&&board[i+3][j-1]==1&&board[i+4][j-2]==1&&board[i+5][j-3]==0) comresults[i][j]+=100;  
                   
                 if(board[i+1][j+2]==0&&board[i+1][j]==2&&board[i+1][j-1]==2&&board[i+1][j-2]==2&&board[i+1][j-3]==0) humresults[i][j]+=100;  
                 if(board[i+2][j+2]==0&&board[i][j]==2&&board[i-1][j-1]==2&&board[i-2][j-2]==2&&board[i-3][j-3]==0) humresults[i][j]+=100;   
                 if(board[i+2][j+1]==0&&board[i][j+1]==2&&board[i-1][j+1]==2&&board[i-2][j+1]==2&&board[i-3][j+1]==0) humresults[i][j]+=100;  
                 if(board[i+2][j]==0&&board[i][j+2]==2&&board[i-1][j+3]==2&&board[i-2][j+4]==2&&board[i-3][j+5]==0) humresults[i][j]+=100;  
                 if(board[i+1][j]==0&&board[i+1][j+2]==2&&board[i+1][j+3]==2&&board[i+1][j+4]==2&&board[i+1][j+5]==0) humresults[i][j]+=100;  
                 if(board[i][j]==0&&board[i+2][j+2]==2&&board[i+3][j+3]==2&&board[i+4][j+4]==2&&board[i+5][j+5]==0) humresults[i][j]+=100;  
                 if(board[i][j+1]==0&&board[i+2][j+1]==2&&board[i+3][j+1]==2&&board[i+4][j+1]==2&&board[i+5][j+1]==0) humresults[i][j]+=100;  
                 if(board[i][j+2]==0&&board[i+2][j]==2&&board[i+3][j-1]==2&&board[i+4][j-2]==2&&board[i+5][j-3]==0) humresults[i][j]+=100;  
                   
                   
                 //�ĤG����?   xoo@ox  
                   
                 if(board[i+1][j+3]==0&&board[i+1][j+2]==1&&board[i+1][j]==1&&board[i+1][j-1]==1&&board[i+1][j-2]==0) comresults[i][j]+=100;  
                 if(board[i+3][j+3]==0&&board[i+2][j+2]==1&&board[i][j]==1&&board[i-1][j-1]==1&&board[i-2][j-2]==0) comresults[i][j]+=100;   
                 if(board[i+3][j+1]==0&&board[i+2][j+1]==1&&board[i][j+1]==1&&board[i-1][j+1]==1&&board[i-2][j+1]==0) comresults[i][j]+=100;  
                 if(board[i+3][j-1]==0&&board[i+2][j]==1&&board[i][j+2]==1&&board[i-1][j+3]==1&&board[i-2][j+4]==0) comresults[i][j]+=100;  
                 if(board[i+1][j-1]==0&&board[i+1][j]==1&&board[i+1][j+2]==1&&board[i+1][j+3]==1&&board[i+1][j+4]==0) comresults[i][j]+=100;  
                 if(board[i-1][j-1]==0&&board[i][j]==1&&board[i+2][j+2]==1&&board[i+3][j+3]==1&&board[i+4][j+4]==0) comresults[i][j]+=100;  
                 if(board[i-1][j+1]==0&&board[i][j+1]==1&&board[i][j+1]==1&&board[i+3][j+1]==1&&board[i+4][j+1]==0) comresults[i][j]+=100;  
                 if(board[i-1][j+3]==0&&board[i][j+2]==1&&board[i+2][j]==1&&board[i+3][j-1]==1&&board[i+4][j-2]==0) comresults[i][j]+=100;  
                   
                 if(board[i+1][j+3]==0&&board[i+1][j+2]==2&&board[i+1][j]==2&&board[i+1][j-1]==2&&board[i+1][j-2]==0) humresults[i][j]+=100;  
                 if(board[i+3][j+3]==0&&board[i+2][j+2]==2&&board[i][j]==2&&board[i-1][j-1]==2&&board[i-2][j-2]==0) humresults[i][j]+=100;   
                 if(board[i+3][j+1]==0&&board[i+2][j+1]==2&&board[i][j+1]==2&&board[i-1][j+1]==2&&board[i-2][j+1]==0) humresults[i][j]+=100;  
                 if(board[i+3][j-1]==0&&board[i+2][j]==2&&board[i][j+2]==2&&board[i-1][j+3]==2&&board[i-2][j+4]==0) humresults[i][j]+=100;  
                 if(board[i+1][j-1]==0&&board[i+1][j]==2&&board[i+1][j+2]==2&&board[i+1][j+3]==2&&board[i+1][j+4]==0) humresults[i][j]+=100;  
                 if(board[i-1][j-1]==0&&board[i][j]==2&&board[i+2][j+2]==2&&board[i+3][j+3]==2&&board[i+4][j+4]==0) humresults[i][j]+=100;  
                 if(board[i-1][j+1]==0&&board[i][j+1]==2&&board[i+2][j+1]==2&&board[i+3][j+1]==2&&board[i+4][j+1]==0) humresults[i][j]+=100;  
                 if(board[i-1][j+3]==0&&board[i][j+2]==2&&board[i+2][j]==2&&board[i+3][j-1]==2&&board[i+4][j-2]==0) humresults[i][j]+=100;  
                   
                   
                   
                   
                   
                 //�ĤT����?     *ooo@x   
                   
                 if(board[i+1][j+2]==0&&board[i+1][j]==1&&board[i+1][j-1]==1&&board[i+1][j-2]==1&&board[i+1][j-3]==2) comresults[i][j]+=11;  
                 if(board[i+2][j+2]==0&&board[i][j]==1&&board[i-1][j-1]==1&&board[i-2][j-2]==1&&board[i-3][j-3]==2) comresults[i][j]+=11;  
                 if(board[i+2][j+1]==0&&board[i][j+1]==1&&board[i-1][j+1]==1&&board[i-2][j+1]==1&&board[i-3][j+1]==2) comresults[i][j]+=11;  
                 if(board[i+2][j-2]==0&&board[i][j+2]==1&&board[i-1][j+3]==1&&board[i-2][j+4]==1&&board[i-3][j+5]==2) comresults[i][j]+=11;  
                 if(board[i+1][j]==0&&board[i+1][j+2]==1&&board[i+1][j+3]==1&&board[i+1][j+4]==1&&board[i+1][j+5]==2) comresults[i][j]+=11;  
                 if(board[i][j]==0&&board[i+2][j+2]==1&&board[i+2][j+3]==1&&board[i+4][j+4]==1&&board[i+5][j+5]==2) comresults[i][j]+=11;  
                 if(board[i][j+1]==0&&board[i+2][j+1]==1&&board[i+3][j+1]==1&&board[i+4][j+1]==1&&board[i+5][j+1]==2) comresults[i][j]+=11;  
                 if(board[i][j+2]==0&&board[i+2][j]==1&&board[i+3][j-1]==1&&board[i+4][j-2]==1&&board[i+5][j-3]==2) comresults[i][j]+=11;  
                   
               
                 if(board[i+1][j+2]==0&&board[i+1][j]==1&&board[i+1][j-1]==1&&board[i+1][j-2]==1&&board[i+1][j-3]==2) humresults[i][j]+=11;   
                 if(board[i+2][j+2]==0&&board[i][j]==1&&board[i-1][j-1]==1&&board[i-2][j-2]==1&&board[i-3][j-3]==2) humresults[i][j]+=11; 
                 if(board[i+2][j+1]==0&&board[i][j+1]==1&&board[i-1][j+1]==1&&board[i-2][j+1]==1&&board[i-3][j+1]==2) humresults[i][j]+=11;   
                 if(board[i+2][j-2]==0&&board[i][j+2]==1&&board[i-1][j+3]==1&&board[i-2][j+4]==1&&board[i-3][j+5]==2) humresults[i][j]+=11; 
                 if(board[i+1][j]==0&&board[i+1][j+2]==1&&board[i+1][j+3]==1&&board[i+1][j+4]==1&&board[i+1][j+5]==2) humresults[i][j]+=11;  
                 if(board[i][j]==0&&board[i+2][j+2]==1&&board[i+2][j+3]==1&&board[i+4][j+4]==1&&board[i+5][j+5]==2) humresults[i][j]+=11;   
                 if(board[i][j+1]==0&&board[i+2][j+1]==1&&board[i+3][j+1]==1&&board[i+4][j+1]==1&&board[i+5][j+1]==2) humresults[i][j]+=11;  
                 if(board[i][j+2]==0&&board[i+2][j]==1&&board[i+3][j-1]==1&&board[i+4][j-2]==1&&board[i+5][j-3]==2) humresults[i][j]+=11;    
                   
                 //�ĥ|����?   *oo@ox                from_here_0607_1700
                   
                 if(board[i][j+2]==0&&board[i][j+1]==1&&board[i][j-1]==1&&board[i][j-2]==1&&board[i][j-3]==2) comresults[i][j]+=11;  
                 if(board[i+2][j+2]==0&&board[i+1][j+1]==1&&board[i-1][j-1]==1&&board[i-2][j-2]==1&&board[i-3][j-3]==2) comresults[i][j]+=11;   
                 if(board[i+2][j]==0&&board[i+1][j]==1&&board[i-1][j]==1&&board[i-2][j]==1&&board[i-3][j]==2) comresults[i][j]+=11;  
                 if(board[i+2][j-2]==0&&board[i+1][j-1]==1&&board[i-1][j+1]==1&&board[i-2][j+2]==1&&board[i-3][j+3]==2) comresults[i][j]+=11;  
                 if(board[i][j-2]==0&&board[i][j-1]==1&&board[i][j+1]==1&&board[i][j+2]==1&&board[i][j+3]==2) comresults[i][j]+=11;  
                 if(board[i-2][j-2]==0&&board[i-1][j-1]==1&&board[i+1][j+1]==1&&board[i+2][j+2]==1&&board[i+3][j+3]==2) comresults[i][j]+=11;  
                 if(board[i-2][j]==0&&board[i-1][j]==1&&board[i+1][j]==1&&board[i+2][j]==1&&board[i+3][j]==2) comresults[i][j]+=11;  
                 if(board[i-2][j+2]==0&&board[i-1][j+1]==1&&board[i+1][j-1]==1&&board[i+2][j-2]==1&&board[i+3][j-3]==2) comresults[i][j]+=11;  
                   
                 if(board[i][j+2]==0&&board[i][j+1]==2&&board[i][j-1]==2&&board[i][j-2]==2&&board[i][j-3]==1) humresults[i][j]+=11;  
                 if(board[i+2][j+2]==0&&board[i+1][j+1]==2&&board[i-1][j-1]==2&&board[i-2][j-2]==2&&board[i-3][j-3]==1) humresults[i][j]+=11;   
                 if(board[i+2][j]==0&&board[i+1][j]==2&&board[i-1][j]==2&&board[i-2][j]==2&&board[i-3][j]==1) humresults[i][j]+=11;  
                 if(board[i+2][j-2]==0&&board[i+1][j-1]==2&&board[i-1][j+1]==2&&board[i-2][j+2]==2&&board[i-3][j+3]==1) humresults[i][j]+=11;  
                 if(board[i][j-2]==0&&board[i][j-1]==2&&board[i][j+1]==2&&board[i][j+2]==2&&board[i][j+3]==1) humresults[i][j]+=11;  
                 if(board[i-2][j-2]==0&&board[i-1][j-1]==2&&board[i+1][j+1]==2&&board[i+2][j+2]==2&&board[i+3][j+3]==1) humresults[i][j]+=11;  
                 if(board[i-2][j]==0&&board[i-1][j]==2&&board[i+1][j]==2&&board[i+2][j]==2&&board[i+3][j]==1) humresults[i][j]+=11;  
                 if(board[i-2][j+2]==0&&board[i-1][j+1]==2&&board[i+1][j-1]==2&&board[i+2][j-2]==2&&board[i+3][j-3]==1) humresults[i][j]+=11;  
                   
                 //�Ĥ�����?   *o@oox  
                   
                 if(board[i][j+2]==2&&board[i][j+1]==1&&board[i][j-1]==1&&board[i][j-2]==1&&board[i][j-3]==0) comresults[i][j]+=11;  
                 if(board[i+2][j+2]==2&&board[i+1][j+1]==1&&board[i-1][j-1]==1&&board[i-2][j-2]==1&&board[i-3][j-3]==0) comresults[i][j]+=11;   
                 if(board[i+2][j]==2&&board[i+1][j]==1&&board[i-1][j]==1&&board[i-2][j]==1&&board[i-3][j]==0) comresults[i][j]+=11;  
                 if(board[i+2][j-2]==2&&board[i+1][j-1]==1&&board[i-1][j+1]==1&&board[i-2][j+2]==1&&board[i-3][j+3]==0) comresults[i][j]+=11;  
                 if(board[i][j-2]==2&&board[i][j-1]==1&&board[i][j+1]==1&&board[i][j+2]==1&&board[i][j+3]==0) comresults[i][j]+=11;  
                 if(board[i-2][j-2]==2&&board[i-1][j-1]==1&&board[i+1][j+1]==1&&board[i+2][j+2]==1&&board[i+3][j+3]==0) comresults[i][j]+=11;  
                 if(board[i-2][j]==2&&board[i-1][j]==1&&board[i+1][j]==1&&board[i+2][j]==1&&board[i+3][j]==0) comresults[i][j]+=11;  
                 if(board[i-2][j+2]==2&&board[i-1][j+1]==1&&board[i+1][j-1]==1&&board[i+2][j-2]==1&&board[i+3][j-3]==0) comresults[i][j]+=11;  
                   
                 if(board[i][j+2]==1&&board[i][j+1]==2&&board[i][j-1]==2&&board[i][j-2]==2&&board[i][j-3]==0) humresults[i][j]+=11;  
                 if(board[i+2][j+2]==1&&board[i+1][j+1]==2&&board[i-1][j-1]==2&&board[i-2][j-2]==2&&board[i-3][j-3]==0) humresults[i][j]+=11;   
                 if(board[i+2][j]==1&&board[i+1][j]==2&&board[i-1][j]==2&&board[i-2][j]==2&&board[i-3][j]==0) humresults[i][j]+=11;  
                 if(board[i+2][j-2]==1&&board[i+1][j-1]==2&&board[i-1][j+1]==2&&board[i-2][j+2]==2&&board[i-3][j+3]==0) humresults[i][j]+=11;  
                 if(board[i][j-2]==1&&board[i][j-1]==2&&board[i][j+1]==2&&board[i][j+2]==2&&board[i][j+3]==0) humresults[i][j]+=11;  
                 if(board[i-2][j-2]==1&&board[i-1][j-1]==2&&board[i+1][j+1]==2&&board[i+2][j+2]==2&&board[i+3][j+3]==0) humresults[i][j]+=11;  
                 if(board[i-2][j]==1&&board[i-1][j]==2&&board[i+1][j]==2&&board[i+2][j]==2&&board[i+3][j]==0) humresults[i][j]+=11;  
                 if(board[i-2][j+2]==1&&board[i-1][j+1]==2&&board[i+1][j-1]==2&&board[i+2][j-2]==2&&board[i+3][j-3]==0) humresults[i][j]+=11;  
                   
                 //�Ĥ�����?  *@ooox  
                   
                 if(board[i][j+1]==2&&board[i][j-1]==1&&board[i][j-2]==1&&board[i][j-3]==1&&board[i][j-4]==0) comresults[i][j]+=11;  
                 if(board[i+1][j+1]==2&&board[i-1][j-1]==1&&board[i-2][j-2]==1&&board[i-3][j-3]==1&&board[i-4][j-4]==0) comresults[i][j]+=11;  
                 if(board[i+1][j]==2&&board[i-1][j]==1&&board[i-2][j]==1&&board[i-3][j]==1&&board[i-4][j]==0) comresults[i][j]+=11;  
                 if(board[i+1][j-1]==2&&board[i-1][j+1]==1&&board[i-2][j+2]==1&&board[i-3][j+3]==1&&board[i-4][j+4]==0) comresults[i][j]+=11;  
                 if(board[i][j-1]==2&&board[i][j+1]==1&&board[i][j+2]==1&&board[i][j+3]==1&&board[i][j+4]==0) comresults[i][j]+=11;  
                 if(board[i-1][j-1]==2&&board[i+1][j+1]==1&&board[i+1][j+2]==1&&board[i+3][j+3]==1&&board[i+4][j+4]==0) comresults[i][j]+=11;  
                 if(board[i-1][j]==2&&board[i+1][j]==1&&board[i+2][j]==1&&board[i+3][j]==1&&board[i+4][j]==0) comresults[i][j]+=11;  
                 if(board[i-1][j+1]==2&&board[i+1][j-1]==1&&board[i+2][j-2]==1&&board[i+3][j-3]==1&&board[i+4][j-4]==0) comresults[i][j]+=11;  
                   
                 if(board[i][j+1]==1&&board[i][j-1]==2&&board[i][j-2]==2&&board[i][j-3]==2&&board[i][j-4]==0) humresults[i][j]+=11;  
                 if(board[i+1][j+1]==1&&board[i-1][j-1]==2&&board[i-2][j-2]==2&&board[i-3][j-3]==2&&board[i-4][j-4]==0) humresults[i][j]+=11;  
                 if(board[i+1][j]==1&&board[i-1][j]==2&&board[i-2][j]==2&&board[i-3][j]==2&&board[i-4][j]==0) humresults[i][j]+=11;  
                 if(board[i+1][j-1]==1&&board[i-1][j+1]==2&&board[i-2][j+2]==2&&board[i-3][j+3]==2&&board[i-4][j+4]==0) humresults[i][j]+=11;  
                 if(board[i][j-1]==1&&board[i][j+1]==2&&board[i][j+2]==2&&board[i][j+3]==2&&board[i][j+4]==0) humresults[i][j]+=11;  
                 if(board[i-1][j-1]==1&&board[i+1][j+1]==2&&board[i+1][j+2]==2&&board[i+3][j+3]==2&&board[i+4][j+4]==0) humresults[i][j]+=11;  
                 if(board[i-1][j]==1&&board[i+1][j]==2&&board[i+2][j]==2&&board[i+3][j]==2&&board[i+4][j]==0) humresults[i][j]+=11;  
                 if(board[i-1][j+1]==1&&board[i+1][j-1]==2&&board[i+2][j-2]==2&&board[i+3][j-3]==2&&board[i+4][j-4]==0) humresults[i][j]+=11;    
                   
                 //�ĤC����?   @xooo*    
                   
                 if(board[i][j+1]==0&&board[i][j+2]==1&&board[i][j+3]==1&&board[i][j+4]==1) comresults[i][j]+=9;  
                 if(board[i+1][j+1]==0&&board[i+2][j+2]==1&&board[i+3][j+3]==1&&board[i+4][j+4]==1) comresults[i][j]+=9;  
                 if(board[i+1][j]==0&&board[i+2][j]==1&&board[i+3][j]==1&&board[i+4][j]==1) comresults[i][j]+=9;  
                 if(board[i+1][j-1]==0&&board[i+2][j-2]==1&&board[i+3][j-3]==1&&board[i+4][j-4]==1) comresults[i][j]+=9;  
                 if(board[i][j-1]==0&&board[i][j-2]==1&&board[i][j-3]==1&&board[i][j-4]==1) comresults[i][j]+=9;  
                 if(board[i-1][j-1]==0&&board[i-2][j-2]==1&&board[i-3][j-3]==1&&board[i-4][j-4]==1) comresults[i][j]+=9;  
                 if(board[i-1][j]==0&&board[i-2][j]==1&&board[i-3][j]==1&&board[i-4][j]==1) comresults[i][j]+=9;  
                 if(board[i-1][j+1]==0&&board[i-2][j+2]==1&&board[i-3][j+3]==1&&board[i-4][j+4]==1) comresults[i][j]+=9;  
                   
                 if(board[i][j+1]==0&&board[i][j+2]==2&&board[i][j+3]==2&&board[i][j+4]==2) humresults[i][j]+=9;  
                 if(board[i+1][j+1]==0&&board[i+2][j+2]==2&&board[i+3][j+3]==2&&board[i+4][j+4]==2) humresults[i][j]+=9;  
                 if(board[i+1][j]==0&&board[i+2][j]==2&&board[i+3][j]==2&&board[i+4][j]==2) humresults[i][j]+=9;  
                 if(board[i+1][j-1]==0&&board[i+2][j-2]==2&&board[i+3][j-3]==2&&board[i+4][j-4]==2) humresults[i][j]+=9;  
                 if(board[i][j-1]==0&&board[i][j-2]==2&&board[i][j-3]==2&&board[i][j-4]==2) humresults[i][j]+=9;  
                 if(board[i-1][j-1]==0&&board[i-2][j-2]==2&&board[i-3][j-3]==2&&board[i-4][j-4]==2) humresults[i][j]+=9;  
                 if(board[i-1][j]==0&&board[i-2][j]==2&&board[i-3][j]==2&&board[i-4][j]==2) humresults[i][j]+=9;  
                 if(board[i-1][j+1]==0&&board[i-2][j+2]==2&&board[i-3][j+3]==2&&board[i-4][j+4]==2) humresults[i][j]+=9;  
                   
                 //�ĤK����?  ox@oo*     *�O?�F���M���T���`�[��   
                   
                 if(board[i][j+3]==2&&board[i][j+2]==1&&board[i][j+1]==1&&board[i][j-1]==0&&board[i][j-2]==1) comresults[i][j]+=9;  
                 if(board[i+3][j+3]==2&&board[i+2][j+2]==1&&board[i+1][j+1]==1&&board[i-1][j-1]==0&&board[i-2][j-2]==1) comresults[i][j]+=9;   
                 if(board[i+3][j]==2&&board[i+2][j]==1&&board[i+1][j]==1&&board[i-1][j]==0&&board[i-2][j]==1) comresults[i][j]+=9;  
                 if(board[i+3][j-3]==2&&board[i+2][j-2]==1&&board[i+1][j-1]==1&&board[i-1][j+1]==0&&board[i-2][j+2]==1) comresults[i][j]+=9;  
                 if(board[i][j-3]==2&&board[i][j-2]==1&&board[i][j-1]==1&&board[i][j+1]==0&&board[i][j+2]==1) comresults[i][j]+=9;  
                 if(board[i-3][j-3]==2&&board[i-2][j-2]==1&&board[i-1][j-1]==1&&board[i+1][j+1]==0&&board[i+2][j+2]==12) comresults[i][j]+=9;  
                 if(board[i-3][j]==2&&board[i-2][j]==1&&board[i-1][j]==1&&board[i+1][j]==0&&board[i+2][j]==1) comresults[i][j]+=9;  
                 if(board[i-3][j+3]==2&&board[i-2][j+2]==1&&board[i-1][j+1]==1&&board[i+1][j-1]==0&&board[i+2][j-2]==1) comresults[i][j]+=9;  
                   
                 if(board[i][j+3]==1&&board[i][j+2]==2&&board[i][j+1]==2&&board[i][j-1]==0&&board[i][j-2]==2) humresults[i][j]+=9;  
                 if(board[i+3][j+3]==1&&board[i+2][j+2]==2&&board[i+1][j+1]==2&&board[i-1][j-1]==0&&board[i-2][j-2]==2) humresults[i][j]+=9;   
                 if(board[i+3][j]==1&&board[i+2][j]==2&&board[i+1][j]==2&&board[i-1][j]==0&&board[i-2][j]==2) humresults[i][j]+=9;  
                 if(board[i+3][j-3]==1&&board[i+2][j-2]==2&&board[i+1][j-1]==2&&board[i-1][j+1]==0&&board[i-2][j+2]==2) humresults[i][j]+=9;  
                 if(board[i][j-3]==1&&board[i][j-2]==2&&board[i][j-1]==2&&board[i][j+1]==0&&board[i][j+2]==2) humresults[i][j]+=9;  
                 if(board[i-3][j-3]==1&&board[i-2][j-2]==2&&board[i-1][j-1]==2&&board[i+1][j+1]==0&&board[i+2][j+2]==2) humresults[i][j]+=9;  
                 if(board[i-3][j]==1&&board[i-2][j]==2&&board[i-1][j]==2&&board[i+1][j]==0&&board[i+2][j]==2) humresults[i][j]+=9;  
                 if(board[i-3][j+3]==1&&board[i-2][j+2]==2&&board[i-1][j+1]==2&&board[i+1][j-1]==0&&board[i+2][j-2]==2) humresults[i][j]+=9;   
                   
                 //�ĤE����?   oxo@o*  
                   
                 if(board[i][j+2]==2&&board[i][j+1]==1&&board[i][j-1]==1&&board[i][j-2]==0&&board[i][j-3]==1) comresults[i][j]+=9;  
                 if(board[i+2][j+2]==2&&board[i+1][j+1]==1&&board[i-1][j-1]==1&&board[i-2][j-2]==0&&board[i-3][j-3]==1) comresults[i][j]+=9;  
                 if(board[i+2][j]==2&&board[i+1][j]==1&&board[i-1][j]==1&&board[i-2][j]==0&&board[i-3][j]==1) comresults[i][j]+=9;  
                 if(board[i+2][j-2]==2&&board[i+1][j-1]==1&&board[i-1][j+1]==1&&board[i-2][j+2]==0&&board[i-3][j+3]==1) comresults[i][j]+=9;  
                 if(board[i][j-2]==2&&board[i][j-1]==1&&board[i][j+1]==1&&board[i][j+2]==0&&board[i][j+3]==1) comresults[i][j]+=9;  
                 if(board[i-2][j-2]==2&&board[i-1][j-1]==1&&board[i+1][j+1]==1&&board[i+2][j+2]==0&&board[i+3][j+3]==1) comresults[i][j]+=9;  
                 if(board[i-2][j]==2&&board[i-1][j]==1&&board[i+1][j]==1&&board[i+2][j]==0&&board[i+3][j]==1) comresults[i][j]+=9;  
                 if(board[i-2][j+2]==2&&board[i-1][j+1]==1&&board[i+1][j-1]==1&&board[i+2][j-2]==0&&board[i+3][j-3]==1) comresults[i][j]+=9;  
                   
                 if(board[i][j+2]==2&&board[i][j+1]==2&&board[i][j-1]==2&&board[i][j-2]==0&&board[i][j-3]==2) humresults[i][j]+=9;  
                 if(board[i+2][j+2]==2&&board[i+1][j+1]==2&&board[i-1][j-1]==2&&board[i-2][j-2]==0&&board[i-3][j-3]==2) humresults[i][j]+=9;  
                 if(board[i+2][j]==2&&board[i+1][j]==2&&board[i-1][j]==2&&board[i-2][j]==0&&board[i-3][j]==2) humresults[i][j]+=9;  
                 if(board[i+2][j-2]==2&&board[i+1][j-1]==2&&board[i-1][j+1]==2&&board[i-2][j+2]==0&&board[i-3][j+3]==2) humresults[i][j]+=9;  
                 if(board[i][j-2]==2&&board[i][j-1]==2&&board[i][j+1]==2&&board[i][j+2]==0&&board[i][j+3]==2) humresults[i][j]+=9;  
                 if(board[i-2][j-2]==2&&board[i-1][j-1]==2&&board[i+1][j+1]==2&&board[i+2][j+2]==0&&board[i+3][j+3]==2) humresults[i][j]+=9;  
                 if(board[i-2][j]==2&&board[i-1][j]==2&&board[i+1][j]==2&&board[i+2][j]==0&&board[i+3][j]==2) humresults[i][j]+=9;  
                 if(board[i-2][j+2]==2&&board[i-1][j+1]==2&&board[i+1][j-1]==2&&board[i+2][j-2]==0&&board[i+3][j-3]==2) humresults[i][j]+=9;   
                   
                 //�ĤQ����?   oxoo@*   
                   
                 if(board[i][j+1]==2&&board[i][j-1]==1&&board[i][j-2]==1&&board[i][j-3]==0&&board[i][j-4]==1) comresults[i][j]+=9;  
                 if(board[i+1][j+1]==2&&board[i-1][j-1]==1&&board[i-2][j-2]==1&&board[i-3][j-3]==0&&board[i-4][j-4]==1) comresults[i][j]+=9;  
                 if(board[i+1][j]==2&&board[i-1][j]==1&&board[i-2][j]==1&&board[i-3][j]==0&&board[i-4][j]==1) comresults[i][j]+=9;  
                 if(board[i+1][j-1]==2&&board[i-1][j+1]==1&&board[i-2][j+2]==1&&board[i-3][j+3]==0&&board[i-4][j+4]==1) comresults[i][j]+=9;  
                 if(board[i][j-1]==2&&board[i][j+1]==1&&board[i][j+2]==1&&board[i][j+3]==0&&board[i][j+4]==1) comresults[i][j]+=9;  
                 if(board[i-1][j-1]==2&&board[i+1][j+1]==1&&board[i+1][j+2]==1&&board[i+3][j+3]==0&&board[i+4][j+4]==1) comresults[i][j]+=9;  
                 if(board[i-1][j]==2&&board[i+1][j]==1&&board[i+2][j]==1&&board[i+3][j]==0&&board[i+4][j]==1) comresults[i][j]+=9;  
                 if(board[i-1][j+1]==2&&board[i+1][j-1]==1&&board[i+2][j-2]==1&&board[i+3][j-3]==0&&board[i+4][j-4]==1) comresults[i][j]+=9;  
                   
                 if(board[i][j+1]==1&&board[i][j-1]==2&&board[i][j-2]==2&&board[i][j-3]==0&&board[i][j-4]==2) humresults[i][j]+=9;  
                 if(board[i+1][j+1]==1&&board[i-1][j-1]==2&&board[i-2][j-2]==2&&board[i-3][j-3]==0&&board[i-4][j-4]==2) humresults[i][j]+=9;  
                 if(board[i+1][j]==1&&board[i-1][j]==2&&board[i-2][j]==2&&board[i-3][j]==0&&board[i-4][j]==2) humresults[i][j]+=9;  
                 if(board[i+1][j-1]==1&&board[i-1][j+1]==2&&board[i-2][j+2]==2&&board[i-3][j+3]==0&&board[i-4][j+4]==2) humresults[i][j]+=9;  
                 if(board[i][j-1]==1&&board[i][j+1]==2&&board[i][j+2]==2&&board[i][j+3]==0&&board[i][j+4]==2) humresults[i][j]+=9;  
                 if(board[i-1][j-1]==1&&board[i+1][j+1]==2&&board[i+1][j+2]==2&&board[i+3][j+3]==0&&board[i+4][j+4]==2) humresults[i][j]+=9;  
                 if(board[i-1][j]==1&&board[i+1][j]==2&&board[i+2][j]==2&&board[i+3][j]==0&&board[i+4][j]==2) humresults[i][j]+=9;  
                 if(board[i-1][j+1]==1&&board[i+1][j-1]==2&&board[i+2][j-2]==2&&board[i+3][j-3]==0&&board[i+4][j-4]==2) humresults[i][j]+=9;   
                   
                 //�ĤQ�@����?   @oxoo  
                   
                 if(board[i][j+1]==1&&board[i][j+2]==0&&board[i][j+3]==1&&board[i][j+4]==1) comresults[i][j]+=9;  
                 if(board[i+1][j+1]==1&&board[i+2][j+2]==0&&board[i+3][j+3]==1&&board[i+4][j+4]==1) comresults[i][j]+=9;  
                 if(board[i+1][j]==1&&board[i+2][j]==0&&board[i+3][j]==1&&board[i+4][j]==1) comresults[i][j]+=9;  
                 if(board[i+1][j-1]==1&&board[i+2][j-2]==0&&board[i+3][j-3]==1&&board[i+4][j-4]==1) comresults[i][j]+=9;  
                 if(board[i][j-1]==1&&board[i][j-2]==0&&board[i][j-3]==1&&board[i][j-4]==1) comresults[i][j]+=9;  
                 if(board[i-1][j-1]==1&&board[i-2][j-2]==0&&board[i-3][j-3]==1&&board[i-4][j-4]==1) comresults[i][j]+=9;  
                 if(board[i-1][j]==1&&board[i-2][j]==0&&board[i-3][j]==1&&board[i-4][j]==1) comresults[i][j]+=9;  
                 if(board[i-1][j+1]==1&&board[i-2][j+2]==0&&board[i-3][j+3]==1&&board[i-4][j+4]==1) comresults[i][j]+=9;  
                   
                 if(board[i][j+1]==2&&board[i][j+2]==0&&board[i][j+3]==2&&board[i][j+4]==2) humresults[i][j]+=9;  
                 if(board[i+1][j+1]==2&&board[i+2][j+2]==0&&board[i+3][j+3]==2&&board[i+4][j+4]==2) humresults[i][j]+=9;  
                 if(board[i+1][j]==2&&board[i+2][j]==0&&board[i+3][j]==2&&board[i+4][j]==2) humresults[i][j]+=9;  
                 if(board[i+1][j-1]==2&&board[i+2][j-2]==0&&board[i+3][j-3]==2&&board[i+4][j-4]==2) humresults[i][j]+=9;  
                 if(board[i][j-1]==2&&board[i][j-2]==0&&board[i][j-3]==2&&board[i][j-4]==2) humresults[i][j]+=9;  
                 if(board[i-1][j-1]==2&&board[i-2][j-2]==0&&board[i-3][j-3]==2&&board[i-4][j-4]==2) humresults[i][j]+=9;  
                 if(board[i-1][j]==2&&board[i-2][j]==0&&board[i-3][j]==2&&board[i-4][j]==2) humresults[i][j]+=9;  
                 if(board[i-1][j+1]==2&&board[i-2][j+2]==0&&board[i-3][j+3]==2&&board[i-4][j+4]==2) humresults[i][j]+=9;  
                   
                 //�ĤQ�G����?   o@xoo   
                   
                 if(board[i][j-1]==1&&board[i][j+1]==0&&board[i][j+2]==0&&board[i][j+3]==1) comresults[i][j]+=9;  
                 if(board[i-1][j-1]==1&&board[i+1][j+1]==0&&board[i+2][j+2]==0&&board[i+3][j+3]==1) comresults[i][j]+=9;  
                 if(board[i-1][j]==1&&board[i+1][j]==0&&board[i+2][j]==0&&board[i+3][j]==1) comresults[i][j]+=9;  
                 if(board[i-1][j+1]==1&&board[i+1][j-1]==0&&board[i+2][j-2]==0&&board[i+3][j-3]==1) comresults[i][j]+=9;  
                 if(board[i][j+1]==1&&board[i][j-1]==0&&board[i][j-2]==0&&board[i][j-3]==1) comresults[i][j]+=9;  
                 if(board[i+1][j+1]==1&&board[i-1][j-1]==0&&board[i-2][j-2]==0&&board[i-3][j-3]==1) comresults[i][j]+=9;  
                 if(board[i+1][j]==1&&board[i-1][j]==0&&board[i-2][j]==0&&board[i-3][j]==1) comresults[i][j]+=9;  
                 if(board[i+1][j-1]==1&&board[i-1][j+1]==0&&board[i-2][j+2]==0&&board[i-3][j+3]==1) comresults[i][j]+=9;  
                   
                 if(board[i][j-1]==2&&board[i][j+1]==0&&board[i][j+2]==0&&board[i][j+3]==1) humresults[i][j]+=9;  
                 if(board[i-1][j-1]==2&&board[i+1][j+1]==0&&board[i+2][j+2]==0&&board[i+3][j+3]==1) humresults[i][j]+=9;  
                 if(board[i-1][j]==2&&board[i+1][j]==0&&board[i+2][j]==0&&board[i+3][j]==1) humresults[i][j]+=9;  
                 if(board[i-1][j+1]==2&&board[i+1][j-1]==0&&board[i+2][j-2]==0&&board[i+3][j-3]==1) humresults[i][j]+=9;  
                 if(board[i][j+1]==2&&board[i][j-1]==0&&board[i][j-2]==0&&board[i][j-3]==1) humresults[i][j]+=9;  
                 if(board[i+1][j+1]==2&&board[i-1][j-1]==0&&board[i-2][j-2]==0&&board[i-3][j-3]==1) humresults[i][j]+=9;  
                 if(board[i+1][j]==2&&board[i-1][j]==0&&board[i-2][j]==0&&board[i-3][j]==1) humresults[i][j]+=9;  
                 if(board[i+1][j-1]==2&&board[i-1][j+1]==0&&board[i-2][j+2]==0&&board[i-3][j+3]==1) humresults[i][j]+=9;  
                   
  
     }   
}  
       
       
void Gobang::r_three(){  
      
     for(int i=1;i<14;i++)  
         for(int j=1;j<14;j++){  
                   
                 if(board[i+1][j+1]!=0) continue;  
                   
                 //�Ĥ@����?    x@oox  
                   
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) comresults[i][j]+=10;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) comresults[i][j]+=10;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) comresults[i][j]+=10;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) comresults[i][j]+=10;  
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) comresults[i][j]+=10;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) comresults[i][j]+=10;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) comresults[i][j]+=10;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) comresults[i][j]+=10;  
                   
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==0) humresults[i][j]+=10;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==0) humresults[i][j]+=10;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==0) humresults[i][j]+=10;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==0) humresults[i][j]+=10;  
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==0) humresults[i][j]+=10;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==0) humresults[i][j]+=10;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==0) humresults[i][j]+=10;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==0) humresults[i][j]+=10;  
                   
                   
                 //�ĤG����?   xo@ox  
                 if(chessboard[i][j+1]==1&&chessboard[i][j-1]==1&&chessboard[i][j-2]==0&&chessboard[i][j+2]==0) comresults[i][j]+=10;   
                 if(chessboard[i-1][j]==1&&chessboard[i+1][j]==1&&chessboard[i-2][j]==0&&chessboard[i+2][j]==0) comresults[i][j]+=10;  
                 if(chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==0&&chessboard[i+2][j+2]==0) comresults[i][j]+=10;  
                 if(chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==0&&chessboard[i+2][j-2]==0) comresults[i][j]+=10;  
                   
                 if(chessboard[i][j+1]==2&&chessboard[i][j-1]==2&&chessboard[i][j-2]==0&&chessboard[i][j+2]==0) humresults[i][j]+=10;   
                 if(chessboard[i-1][j]==2&&chessboard[i+1][j]==2&&chessboard[i-2][j]==0&&chessboard[i+2][j]==0) humresults[i][j]+=10;  
                 if(chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==0&&chessboard[i+2][j+2]==0) humresults[i][j]+=10;  
                 if(chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==0&&chessboard[i+2][j-2]==0) humresults[i][j]+=10;  
                   
                 //�ĤT����?  x@xoox   
                   
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==1&&chessboard[i][j+4]==0) comresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==1&&chessboard[i+4][j+4]==0) comresults[i][j]+=9;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==1&&chessboard[i+4][j]==0) comresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==1&&chessboard[i+4][j-4]==0) comresults[i][j]+=9;  
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==1&&chessboard[i][j-4]==0) comresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==1&&chessboard[i-4][j-4]==0) comresults[i][j]+=9;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==1&&chessboard[i-4][j]==0) comresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==1&&chessboard[i-4][j+4]==0) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==2&&chessboard[i][j+3]==2&&chessboard[i][j+4]==0) humresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==2&&chessboard[i+4][j+4]==0) humresults[i][j]+=9;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==2&&chessboard[i+3][j]==2&&chessboard[i+4][j]==0) humresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==2&&chessboard[i+4][j-4]==0) humresults[i][j]+=9;  
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==2&&chessboard[i][j-3]==2&&chessboard[i][j-4]==0) humresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==2&&chessboard[i-4][j-4]==0) humresults[i][j]+=9;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==2&&chessboard[i-3][j]==2&&chessboard[i-4][j]==0) humresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==2&&chessboard[i-4][j+4]==0) humresults[i][j]+=9;  
                   
                 //�ĥ|����?    xox@ox  
                   
                 if(chessboard[i][j+2]==0&&chessboard[i][j+1]==1&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) comresults[i][j]+=9;  
                 if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) comresults[i][j]+=9;  
                 if(chessboard[i+2][j]==0&&chessboard[i+1][j]==1&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) comresults[i][j]+=9;  
                 if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) comresults[i][j]+=9;  
                 if(chessboard[i][j-2]==0&&chessboard[i][j-1]==1&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) comresults[i][j]+=9;  
                 if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) comresults[i][j]+=9;  
                 if(chessboard[i-2][j]==0&&chessboard[i-1][j]==1&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) comresults[i][j]+=9;  
                 if(chessboard[i-2][j+2]==0&&chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j+2]==0&&chessboard[i][j+1]==2&&chessboard[i][j-1]==0&&chessboard[i][j-2]==2&&chessboard[i][j-3]==0) humresults[i][j]+=9;  
                 if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==0) humresults[i][j]+=9;  
                 if(chessboard[i+2][j]==0&&chessboard[i+1][j]==2&&chessboard[i-1][j]==0&&chessboard[i-2][j]==2&&chessboard[i-3][j]==0) humresults[i][j]+=9;  
                 if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==0) humresults[i][j]+=9;  
                 if(chessboard[i][j-2]==0&&chessboard[i][j-1]==2&&chessboard[i][j+1]==0&&chessboard[i][j+2]==2&&chessboard[i][j+3]==0) humresults[i][j]+=9;  
                 if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==0) humresults[i][j]+=9;  
                 if(chessboard[i-2][j]==0&&chessboard[i-1][j]==2&&chessboard[i+1][j]==0&&chessboard[i+2][j]==2&&chessboard[i+3][j]==0) humresults[i][j]+=9;  
                 if(chessboard[i-2][j+2]==0&&chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==0) humresults[i][j]+=9;  
                   
                 //�Ĥ�����?     xoxo@x  
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==1&&chessboard[i][j-2]==0&&chessboard[i][j-3]==1&&chessboard[i][j-4]==0) comresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==1&&chessboard[i-4][j-4]==0) comresults[i][j]+=9;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==1&&chessboard[i-2][j]==0&&chessboard[i-3][j]==1&&chessboard[i-4][j]==0) comresults[i][j]+=9;   
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==1&&chessboard[i-4][j+4]==0) comresults[i][j]+=9;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==1&&chessboard[i][j+2]==0&&chessboard[i][j+3]==1&&chessboard[i][j+4]==0) comresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==1&&chessboard[i+4][j+4]==0) comresults[i][j]+=9;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==1&&chessboard[i+2][j]==0&&chessboard[i+3][j]==1&&chessboard[i+4][j]==0) comresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==1&&chessboard[i+4][j-4]==0) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==2&&chessboard[i][j-2]==0&&chessboard[i][j-3]==2&&chessboard[i][j-4]==0) humresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==2&&chessboard[i-4][j-4]==0) humresults[i][j]+=9;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==2&&chessboard[i-2][j]==0&&chessboard[i-3][j]==2&&chessboard[i-4][j]==0) humresults[i][j]+=9;   
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==2&&chessboard[i-4][j+4]==0) humresults[i][j]+=9;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==2&&chessboard[i][j+2]==0&&chessboard[i][j+3]==2&&chessboard[i][j+4]==0) humresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==2&&chessboard[i+4][j+4]==0) humresults[i][j]+=9;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==2&&chessboard[i+2][j]==0&&chessboard[i+3][j]==2&&chessboard[i+4][j]==0) humresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==2&&chessboard[i+4][j-4]==0) humresults[i][j]+=9;  
                   
                 //�Ĥ�����?    x@xoxox  
                   
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0&&chessboard[i][j+4]==1&&chessboard[i][j+5]==0) comresults[i][j]+=8;   
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0&&chessboard[i+4][j+4]==1&&chessboard[i+5][j+5]==0) comresults[i][j]+=8;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0&&chessboard[i+4][j]==1&&chessboard[i+5][j]==0) comresults[i][j]+=8;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0&&chessboard[i+4][j-4]==1&&chessboard[i+5][j-5]==0) comresults[i][j]+=8;  
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0&&chessboard[i][j-4]==1&&chessboard[i][j-5]==0) comresults[i][j]+=8;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0&&chessboard[i-4][j-4]==1&&chessboard[i-5][j-5]==0) comresults[i][j]+=8;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0&&chessboard[i-4][j]==1&&chessboard[i-5][j]==0) comresults[i][j]+=8;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0&&chessboard[i-4][j+4]==1&&chessboard[i-5][j+5]==0) comresults[i][j]+=8;  
                   
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==2&&chessboard[i][j+3]==0&&chessboard[i][j+4]==2&&chessboard[i][j+5]==0) humresults[i][j]+=8;   
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==0&&chessboard[i+4][j+4]==2&&chessboard[i+5][j+5]==0) humresults[i][j]+=8;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==2&&chessboard[i+3][j]==0&&chessboard[i+4][j]==2&&chessboard[i+5][j]==0) humresults[i][j]+=8;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==0&&chessboard[i+4][j-4]==2&&chessboard[i+5][j-5]==0) humresults[i][j]+=8;  
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==2&&chessboard[i][j-3]==0&&chessboard[i][j-4]==2&&chessboard[i][j-5]==0) humresults[i][j]+=8;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==0&&chessboard[i-4][j-4]==2&&chessboard[i-5][j-5]==0) humresults[i][j]+=8;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==2&&chessboard[i-3][j]==0&&chessboard[i-4][j]==2&&chessboard[i-5][j]==0) humresults[i][j]+=8;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==0&&chessboard[i-4][j+4]==2&&chessboard[i-5][j+5]==0) humresults[i][j]+=8;  
                   
                 //�ĤK����?   xox@xox  
                   
                 //??���G����?�A����?            
                   
                 }       
                   
}  
  
  
  
void Gobang::r_two(){  
         
       
     for(int i=1;i<14;i++)  
            for(int j=1;j<14;j++){  
                      
                    if(chessboard[i][j]!=0) continue;  
                      
                    //�Ĥ@����?  xx@oxx  
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==1&&chessboard[i][j+2]==0&&chessboard[i][j+3]==0) comresults[i][j]+=2;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-2][j-1]==0&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==0) comresults[i][j]+=2;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==1&&chessboard[i+2][j]==0&&chessboard[i+3][j]==0) comresults[i][j]+=2;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==0) comresults[i][j]+=2;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==1&&chessboard[i][j-2]==0&&chessboard[i][j-3]==0) comresults[i][j]+=2;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==0) comresults[i][j]+=2;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==1&&chessboard[i-2][j]==0&&chessboard[i-3][j]==0) comresults[i][j]+=2;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==0) comresults[i][j]+=2;  
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==2&&chessboard[i][j+2]==0&&chessboard[i][j+3]==0) humresults[i][j]+=2;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-2][j-1]==0&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==0) humresults[i][j]+=2;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==2&&chessboard[i+2][j]==0&&chessboard[i+3][j]==0) humresults[i][j]+=2;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==0) humresults[i][j]+=2;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==2&&chessboard[i][j-2]==0&&chessboard[i][j-3]==0) humresults[i][j]+=2;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==0) humresults[i][j]+=2;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==2&&chessboard[i-2][j]==0&&chessboard[i-3][j]==0) humresults[i][j]+=2;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==0) humresults[i][j]+=2;   
                      
                    //�ĤG����?   xx@xox   
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) comresults[i][j]+=1;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-2][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) comresults[i][j]+=1;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) comresults[i][j]+=1;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) comresults[i][j]+=1;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) comresults[i][j]+=1;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) comresults[i][j]+=1;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) comresults[i][j]+=1;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) comresults[i][j]+=1;  
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) humresults[i][j]+=1;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-2][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) humresults[i][j]+=1;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) humresults[i][j]+=1;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) humresults[i][j]+=1;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) humresults[i][j]+=1;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) humresults[i][j]+=1;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) humresults[i][j]+=1;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) humresults[i][j]+=1;  
                      
                      
                    }  
}  
       
       


















void Gobang::default_board()//��l�ƴѽL15x15 
{ 
     for(int i=0 ;i<=16 ;i++){ 
        for(int j=0 ;j<=16 ;j++){ 
            if(i==0 && j==0){ 
                 board[i][j] = 0; 
            }else if(i==16 || j==16){ 
                 board[i][j] = 0; 
            }else if(i==0){ 
                 board[i][j] = j+30; 
            }else if(j==0){ 
                 board[i][j] = i+10; 
            }else if(i==1 && j==1){ 
                 board[i][j] = -7; 
            }else if(i==1 && j==15){ 
                 board[i][j] = -9; 
            }else if(i==15 && j==1){ 
                 board[i][j] = -1; 
            }else if(i==15 && j==15){ 
                 board[i][j] = -3; 
            }else if(i==1){ 
                 board[i][j] = -8; 
            }else if(j==1){ 
                 board[i][j] = -4; 
            }else if(j==15){ 
                 board[i][j] = -6; 
            }else if(i==15){ 
                 board[i][j] = -2; 
            }else{ 
                 board[i][j] = -5; 
            } 
        } 
     } 
} 
void Gobang::show_board()//��ܴѽL15x15 
{ 	int b=2,w=1,i1=0,j1=0,con=0;
	if(white==1)
	{
		b=1;
		w=2;
		for(i1=0 ;i1<=16 ;i1++){ 
           for(j1=0 ;j1<=16 ;j1++){
		   	 if(board[i1][j1]==1 || board[i1][j1]==2)
		   	 con++;
		   }
		}
		if(con==4){
			for(i1=0 ;i1<=16 ;i1++){ 
           for(j1=0 ;j1<=16 ;j1++){
           	if(board[i1][j1]==1)
           	board[i1][j1]=2;
           	else if(board[i1][j1]==2)
           	board[i1][j1]=1;
           		}
       		}
		}
	}
	if(white==0){
	
     for(int i=0 ;i<=16 ;i++){ 
           for(int j=0 ;j<=16 ;j++){ 
                 switch(board[i][j]){ 
                    case -1: 
                      cout << "�|"; 
                      break; 
                    case -2: 
                      cout << "�r"; 
                      break; 
                    case -3: 
                      cout << "�}"; 
                      break; 
                    case -4: 
                      cout << "�u"; 
                      break; 
                    case -5: 
                      cout << "�q"; 
                      break; 
                    case -6: 
                      cout << "�t"; 
                      break; 
                    case -7: 
                      cout << "�z"; 
                      break; 
                    case -8: 
                      cout << "�s"; 
                      break; 
                    case -9: 
                      cout << "�{"; 
                      break; 
                    case 0: 
                      cout << "�@"; 
                      break; 
                    case 1: 
                      cout << "��"; 
                      break; 
                    case 2: 
                      cout << "��"; 
                      break; 
                    /*case 3: 
                      cout << "��"; 
                      break; 
                    case 4: 
                      cout << "��"; 
                      break;*/ 
                    case 11: 
                      cout << "��"; 
                      break; 
                    case 12: 
                      cout << "��"; 
                      break; 
                    case 13: 
                      cout << "��"; 
                      break; 
                    case 14: 
                      cout << "��"; 
                      break; 
                    case 15: 
                      cout << "��"; 
                      break; 
                    case 16: 
                      cout << "��"; 
                      break; 
                    case 17: 
                      cout << "��"; 
                      break; 
                    case 18: 
                      cout << "��"; 
                      break; 
                    case 19: 
                      cout << "��"; 
                      break; 
                    case 20: 
                      cout << "10"; 
                      break; 
                    case 21: 
                      cout << "11"; 
                      break; 
                    case 22: 
                      cout << "12"; 
                      break; 
                    case 23: 
                      cout << "13"; 
                      break; 
                    case 24: 
                      cout << "14"; 
                      break; 
                    case 25: 
                      cout << "15"; 
                      break; 
                    case 31: 
                      cout << "��"; 
                      break; 
                    case 32: 
                      cout << "��"; 
                      break; 
                    case 33: 
                      cout << "��"; 
                      break; 
                    case 34: 
                      cout << "��"; 
                      break; 
                    case 35: 
                      cout << "��"; 
                      break; 
                    case 36: 
                      cout << "��"; 
                      break; 
                    case 37: 
                      cout << "��"; 
                      break; 
                    case 38: 
                      cout << "��"; 
                      break; 
                    case 39: 
                      cout << "��"; 
                      break; 
                    case 40: 
                      cout << "��"; 
                      break; 
                    case 41: 
                      cout << "��"; 
                      break; 
                    case 42: 
                      cout << "��"; 
                      break; 
                    case 43: 
                      cout << "��"; 
                      break; 
                    case 44: 
                      cout << "��"; 
                      break; 
                    case 45: 
                      cout << "��"; 
                      break; 
                    
                 } 
           } 
           cout << endl; 
     } 
   }
   else if (white==1){
   	
   	for(int i=0 ;i<=16 ;i++){ 
           for(int j=0 ;j<=16 ;j++){ 
                 switch(board[i][j]){ 
                    case -1: 
                      cout << "�|"; 
                      break; 
                    case -2: 
                      cout << "�r"; 
                      break; 
                    case -3: 
                      cout << "�}"; 
                      break; 
                    case -4: 
                      cout << "�u"; 
                      break; 
                    case -5: 
                      cout << "�q"; 
                      break; 
                    case -6: 
                      cout << "�t"; 
                      break; 
                    case -7: 
                      cout << "�z"; 
                      break; 
                    case -8: 
                      cout << "�s"; 
                      break; 
                    case -9: 
                      cout << "�{"; 
                      break; 
                    case 0: 
                      cout << "�@"; 
                      break; 
                    case 1: 
                      cout << "��"; 
                      break; 
                    case 2: 
                      cout << "��"; 
                      break; 
                    /*case 3: 
                      cout << "��"; 
                      break; 
                    case 4: 
                      cout << "��"; 
                      break;*/ 
                    case 11: 
                      cout << "��"; 
                      break; 
                    case 12: 
                      cout << "��"; 
                      break; 
                    case 13: 
                      cout << "��"; 
                      break; 
                    case 14: 
                      cout << "��"; 
                      break; 
                    case 15: 
                      cout << "��"; 
                      break; 
                    case 16: 
                      cout << "��"; 
                      break; 
                    case 17: 
                      cout << "��"; 
                      break; 
                    case 18: 
                      cout << "��"; 
                      break; 
                    case 19: 
                      cout << "��"; 
                      break; 
                    case 20: 
                      cout << "10"; 
                      break; 
                    case 21: 
                      cout << "11"; 
                      break; 
                    case 22: 
                      cout << "12"; 
                      break; 
                    case 23: 
                      cout << "13"; 
                      break; 
                    case 24: 
                      cout << "14"; 
                      break; 
                    case 25: 
                      cout << "15"; 
                      break; 
                    case 31: 
                      cout << "��"; 
                      break; 
                    case 32: 
                      cout << "��"; 
                      break; 
                    case 33: 
                      cout << "��"; 
                      break; 
                    case 34: 
                      cout << "��"; 
                      break; 
                    case 35: 
                      cout << "��"; 
                      break; 
                    case 36: 
                      cout << "��"; 
                      break; 
                    case 37: 
                      cout << "��"; 
                      break; 
                    case 38: 
                      cout << "��"; 
                      break; 
                    case 39: 
                      cout << "��"; 
                      break; 
                    case 40: 
                      cout << "��"; 
                      break; 
                    case 41: 
                      cout << "��"; 
                      break; 
                    case 42: 
                      cout << "��"; 
                      break; 
                    case 43: 
                      cout << "��"; 
                      break; 
                    case 44: 
                      cout << "��"; 
                      break; 
                    case 45: 
                      cout << "��"; 
                      break; 
                    
                 } 
           } 
           cout << endl; 
     } 
   }
} 
void Gobang::put_chess(short i,short j,short whosturn){//�U��+�P�_���L�Ѥl 
     if(i == 0 || i >= 16 || j == 0 || j >= 16){ 
        cout <<"�U�Ѫ��d��W�X��l�~�I"<< endl; 
        endtry = 0; 
        system("pause"); 
     }else if(board[i][j] == 1 || board[i][j] == 2){ 
        cout <<"����m�w�g���Ѥl�F�I"<< endl; 
        endtry = 0; 
        system("pause"); 
     }else{ 
        board[i][j] = whosturn; 
     } 
} 

bool Gobang::winner(short i,short j,short whosturn){//�ӭt win = 1 �ӧQ 
   short count,tempi,tempj; 
   bool win = 0; 
   //���� 
   count = 1; 
   tempi = i; 
   while(board[--tempi][j] == whosturn){count++;} 
   tempi = i; 
   while(board[++tempi][j] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //���� 
   count = 1; 
   tempj = j; 
   while(board[i][--tempj] == whosturn){count++;} 
   tempj = j; 
   while(board[i][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //���� 
   count = 1; 
   tempi = i,tempj = j; 
   while(board[--tempi][--tempj] == whosturn){count++;} 
   tempi = i,tempj = j; 
   while(board[++tempi][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //���� 
   count = 1; 
   tempi = i,tempj = j; 
   while(board[++tempi][--tempj] == whosturn){count++;} 
   tempi = i,tempj = j; 
   while(board[--tempi][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
winner_check_end: 
   return win; 
} 
void Gobang::multiplayer(){//��Ӫ��a, �´ѥ��U 
     string keyin; 
     short whosturn = 2,I,J; 
     system("cls"); 
     show_board(); 
nextstep: 
     I = 0; 
     J = 0; 
     endtry = 1; 
     system("cls"); 
     show_board(); 
     if(whosturn == 1){ 
          cout <<"�����¤l�U�G"; 
     }else{ 
          cout <<"�����դl�U�G"; 
     } 
     getline(cin,keyin); 
     for(int n=0 ;n<keyin.length() ;n++){//�B�z�r��keyin 
        if(keyin[n]>='a' && keyin[n]<='o'){ 
           J = keyin[n] - 'a' + 1; 
        }else if(keyin[n]>='A' && keyin[n]<='O'){ 
           J = keyin[n] - 'A' + 1; 
        }else if(keyin[n]>='0' && keyin[n]<='9'){ 
           I = I*10 + keyin[n] - '0'; 
        }else if(keyin[n] == ' '){ 
           continue; 
        }else{ 
           cout <<"��J�F���X�k���r���I"<< endl; 
           system("pause"); 
           goto nextstep; 
        } 
     } 
     put_chess(I,J,whosturn); 
     if(endtry == 0){goto nextstep;} 
     endtry = winner(I,J,whosturn); 
     whosturn = (whosturn == 1? 2:1); 
     if(endtry == 0){goto nextstep;} 
     else{ 
        whosturn = (whosturn == 1? 2:1); 
        system("cls"); 
        show_board(); 
        if(whosturn == 1){cout <<"�´�Ĺ�F�I"<< endl;}else{cout <<"�մ�Ĺ�F�I"<< endl;} 
     } 
      
} 
