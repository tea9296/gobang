
#include<iostream> 
#include<string> 
using namespace std; 
short board[17][17]; 
bool endtry; 

void default_board();//��l�ƴѽL15x15 
void show_board();//��ܴѽL15x15 
void put_chess(short,short,short);//�U��+�P�_���L�Ѥl 
bool winner(short i,short j,short whosturn);//�ӭt win = 1 �ӧQ 
void multiplayer();//��Ӫ��a, �´ѥ��U 
int main()//�� �D�{�� �� 
{ 	string bw,bw2,bw3;
    cout<<"BLACK OR WHILE?\n";
    getline(cin,bw);
    string choose; 
    int I2,J2,I3,J3;
    do{ 
       default_board(); 
       //FIRST STEP
       put_chess(8,8,1);
       show_board();
       
       
       //SECOND STEP
       cout<<"���դl�Achoose between 7-9 and G-I\n";
      
    step2:   
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
       
       put_chess(I2,J2,2);
       system("cls"); 
       show_board();
       
       
       //THIRD STEP
       
       cout<<"���¤l�Achoose between 6-10 and F-J\n";
       
       
    step3:   
	   getline(cin,bw3);
       for(int n=0 ;n<bw3.length() ;n++){
       if(bw3[n]>='f' && bw3[n]<='j'){ 
           J3 = bw3[n] - 'a' + 1; 
        }else if(bw3[n]>='F' && bw3[n]<='J'){ 
           J3 = bw3[n] - 'A' + 1; 
        }else if(bw3[n]>='6' && bw3[n]<='10'){ 
           I3 = I3*10 + bw3[n] - '0'; 
        }else if(bw3[n] == ' '){ 
           continue; 
        }else{ 
           cout <<"��J�F���X�k���r���I"<< endl; 
           system("pause"); 
           goto step3; 
        } 
     } 
       
       put_chess(I3,J3,1);
       
       
       
       
       
       
       multiplayer(); 
       cout <<"��J y �A���@���H�G"; 
       getline(cin,choose); 
    }while(choose == "y" || choose == "Y"); 
    return 0; 
} 
/* 
�i�סG 
20120417�ѽL��l�Ƨ� 
20120418�i�H�U�ѤF, ���}���ɦ�bug�G�h�l��ܡu�U�Ѫ��d��W�X��l�~�I�v 
20120419�ץ� 
*/ 
void default_board()//��l�ƴѽL15x15 
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
void show_board()//��ܴѽL15x15 
{ 
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
void put_chess(short i,short j,short whosturn){//�U��+�P�_���L�Ѥl 
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

bool winner(short i,short j,short whosturn){//�ӭt win = 1 �ӧQ 
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
void multiplayer(){//��Ӫ��a, �´ѥ��U 
     string keyin; 
     short whosturn = 1,I,J; 
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
