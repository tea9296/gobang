
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
              void setchessboard(int ,int,int);     //���ܴѤl   
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
