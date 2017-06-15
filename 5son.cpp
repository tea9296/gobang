
#include<iostream> 
#include<string> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std; 
/*short board[17][17]; 
bool endtry; 
int white=0;
void default_board();//初始化棋盤15x15 
void show_board();//顯示棋盤15x15 
void put_chess(short,short,short);//下棋+判斷有無棋子 
bool winner(short i,short j,short whosturn);//勝負 win = 1 勝利 
void go(int n) ; // 遊戲開始 
void multiplayer();//兩個玩家, 黑棋先下 

*/

//class of  computer
int com_choose=100;  //電腦選先手後手 
int I2,J2,I3,J3;
class Gobang{  
        
      public:   
                
             short board[17][17];          //棋盤  
              int five[5][5];                  //5*5小棋?   
             int six[6][6];
           	 bool endtry;
             int computernum,humannum;         //棋子   
             int p1,p2;                       //棋子   
             int last1,last2;                    //紀錄上一步    
             int comresults[15][15];             //存分數  
             int humresults[15][15];  
             int temp[15][15];             //15x15臨時棋 盤 
             int max_com,max_hum,max_com_i,max_com_j,max_hum_i,max_hum_j;             
             int total_com,total_hum;              //電腦和玩家總分   
           
     
     		 
              void default_board();//初始化棋盤15x15 
			  void show_board();//顯示棋盤15x15 
			  void put_chess(short,short,short);//下棋+判斷有無棋子 
			  bool winner(short i,short j,short whosturn);//勝負 win = 1 勝利 
			  void go(int COMI2,int COMJ2,int COMI3,int COMJ3) ; // 遊戲開始 
			  void multiplayer(int pla);//兩個玩家, 黑棋先下 	
              Gobang();  
              void setboard(int ,int,int);     //改變棋子   
              void count(int com,int pla);                         //記數，棋子數   
              void count_total();                //算總分   
			  bool generator(int com,int pla,int I,int J); 
 
				 void getfive(int i,int j);             // 讀取數據，存入5*5 的棋盤中   
            
              void getsix(int,int);  
              int ifwin(int com,int pla);                     //判斷勝負        
              void think(int com,int pla);  
              void getresults(int com,int pla);          //打分下子   
              void r_four(int com,int pla);  
              void r_three(int com,int pla);             
              void r_two(int com,int pla);  
      //        int returngoback();  
                
   
};  








int main()//※ 主程式 ※ 
{ 	string bw2,bw3;
    string who_first;
    int COMI2,COMI3,COMJ2,COMJ3; //假後手電腦隨機選 
	cout<<"假先手(1)或假後手(0)?\n";
    getline(cin,who_first);
    string choose; 
    
    
    char tem1,tem2;
    Gobang g;
    do{ 
       g.default_board(); 
       //FIRST STEP
       g.put_chess(8,8,1);
       g.show_board();
       
       
       
       //假先手 
      if(who_first=="1"){
	  
       //SECOND STEP
       
      
    step2:   
		cout<<"換白子，choose between 7-9 and G-I\n";    
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
           cout <<"輸入了不合法的字元！"<< endl; 
           system("pause"); 
           goto step2; 
        } 
     } 
       
       g.put_chess(I2,J2,2);
       system("cls"); 
       g.show_board();
       
       
       //THIRD STEP
       
      
       
       
    step3:   
    	cout<<"換黑子，choose between 6-10 and F-J\n";
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
           cout <<"輸入了不合法的字元！"<< endl; 
           system("pause"); 
           goto step3; 
        } 
     } 
      g.put_chess(I3,J3,1);
      system("cls");
      g.show_board();
      srand((unsigned)time(NULL));
      com_choose=rand()%2;
 }	  
    
	  
	 
       //假後手 
       else if(who_first=="0")
       {
       	// 隨機取子 
    step5:
	   	srand( (unsigned)time(NULL) );
      	COMI2=rand() % 3 +7;
       	Sleep(1000);
       	COMJ2=rand() % 3 + 7;
       	cout<<COMI2<<COMJ2;
       	cout<<g.board[COMI2][COMJ2];
       	if(g.board[COMI2][COMJ2]>0) goto step5;
       	g.put_chess(COMI2,COMJ2,2);
       	system("cls"); 
       g.show_board();
   /*    for(int w=0;w<=16;w++){
       	for(int n=0;n<=16;n++){
       		cout<<g.board[w][n];
		   }
		   cout<<"\n";
	   }
	   system("pause");
     */
	   	Sleep(3000);
    step6:
       	COMI3=rand() % 5 +6;
       	COMJ3=rand() % 5 + 6;
       	if(g.board[COMI3][COMJ3]>0) goto step6;
       	 g.put_chess(COMI3,COMJ3,1);
       system("cls"); 
       g.show_board();
	   }  
	  
	  
	  
       
       
       
       
      
       g.go(COMI2,COMJ2,COMI3,COMJ3);
       //multiplayer(); 
       cout <<"輸入 y 再玩一次？："; 
       getline(cin,choose); 
    }while(choose == "y" || choose == "Y"); 
    return 0; 
} 


//開始遊戲//

void Gobang::go(int COMI2,int COMJ2,int COMI3,int COMJ3){  
       
       char n;
            if(com_choose==100){
			
             cout<<"玩家要黑棋或白棋?："<<endl;  
             cout<<"     1.黑棋"<<endl;  
             cout<<"     2.白棋"<<endl;  
              n= getchar();
			cout<<"\n";
		    }
		
             int computer=0,player=0;
             if(com_choose==0){
             	cout<<"電腦選了黑子\n"; 
             	player=2;
             	computer=1;
             	last1=I3-1;
				last2=J3-1;
             	system("pause");
			 }
			 else if(com_choose==1){
			 	cout<<"電腦選了白子\n"; 
			 	player=1;
			 	computer=2;
             	
             	last1=I2-1;
				last2=J2-1;
			
				
             	system("pause");
             	think(computer,player);
			 }
             else if(n=='2'){
             	
             	player=2;
             	computer=1;
             	last1=COMI3-1;
				last2=COMJ3-1;
			//	cout<<last1<<last2;
			 }  
             else if(n=='1'){
			 	player=1;
			 	computer=2;
             	
             	last1=COMI2-1;
				last2=COMJ2-1;
			
				think(computer,player);
			}
     while(1){  
              if(ifwin(computer,player)==computer) {  
                                 show_board();  
                                cout<<"電腦勝利！"<<endl;   
                              break;  
                              }  
              if(ifwin(computer,player)==2){  
                              show_board(); 
                              cout<<"玩家勝利！"<<endl;  
                              break;  
                              }   
              
             system("cls");
             show_board();
            cout<<"電腦下了 "<<last1+1<<" "<<last2+1<<"\n"; 
             system("pause");
             multiplayer(player);   
       //       if(returngoback()==1) {cout<<"遊戲結束！"<<endl;return;}  
              if(ifwin(computer,player)==computer) {  
                               show_board();  
                              cout<<"電腦勝利！"<<endl;  
                              break;  
                              }  
              if(ifwin(computer,player)==player){  
                              show_board();  
                              cout<<"玩家勝利！"<<endl;  
                              break;  
                              }   
              think(computer,player);  
              }  
              
             
              
     }
	   



Gobang::Gobang(){  
                 
                                  
                 for(int i=0;i<5;i++)  
                         for(int j=0;j<5;j++)  
                                {five[i][j]=0;}  
                 computernum=0;  
                 humannum=0;  
                 p1=0;p2=0;  
                 last1=-1;last2=-1;       //-1表示尚未始   
                 max_com=0;max_hum=0;max_com_i=0;  
                 max_com_j=0;max_hum_i=0;max_hum_j=0;  
                 total_com=0;total_hum=0;  
            //     goback=0;  
}  



void Gobang::count(int com,int pla){  
     computernum=0;  
     humannum=0;  
     for(int i=1;i<16;i++)  
         for(int j=1;j<16;j++){  
                 if(board[i][j]==com) computernum++;  
                 if(board[i][j]==pla) humannum++;  
                 p1=computernum+3;p2=humannum+3;  
                 }  
}  



//判斷該子附近有沒有子，是否要評估 
bool Gobang::generator(int com,int pla,int I,int J){
	
	
			if(board[I][J]==com||board[I][J]==pla)  return false;
			else if(board[I][J+1]==com||board[I][J+1]==pla) return true;
			else if(board[I][J+2]==com||board[I][J+2]==pla) return true;
			else if(board[I][J-1]==com||board[I][J-1]==pla) return true;
			else if(board[I][J-2]==com||board[I][J-2]==pla) return true;
			
			else if(board[I+1][J]==com||board[I+1][J]==pla) return true;
			else if(board[I+1][J+1]==com||board[I+1][J+1]==pla) return true;
			else if(board[I+1][J+2]==com||board[I+1][J+2]==pla) return true;
			else if(board[I+1][J-1]==com||board[I+1][J-1]==pla) return true;
			else if(board[I+1][J-2]==com||board[I+1][J-2]==pla) return true;
			
			else if(board[I+2][J]==com||board[I+2][J]==pla) return true;
			else if(board[I+2][J+1]==com||board[I+2][J+1]==pla) return true;
			else if(board[I+2][J+2]==com||board[I+2][J+2]==pla) return true;
			else if(board[I+2][J-1]==com||board[I+2][J-1]==pla) return true;
			else if(board[I+2][J-2]==com||board[I+2][J-2]==pla) return true;
			
			else if(board[I-1][J]==com||board[I-1][J]==pla) return true;
			else if(board[I-1][J+1]==com||board[I-1][J+1]==pla) return true;
			else if(board[I-1][J+2]==com||board[I-1][J+2]==pla) return true;
			else if(board[I-1][J-1]==com||board[I-1][J-1]==pla) return true;
			else if(board[I-1][J-2]==com||board[I-1][J-2]==pla) return true;
			
			else if(board[I-2][J]==com||board[I-2][J]==pla) return true;
			else if(board[I-2][J+1]==com||board[I-2][J+1]==pla) return true;
			else if(board[I-2][J+2]==com||board[I-2][J+2]==pla) return true;
			else if(board[I-2][J-1]==com||board[I-2][J-1]==pla) return true;
			else if(board[I-2][J-2]==com||board[I-2][J-2]==pla) return true;
			
			else{
				return false;
			}
	
	
}

  
//判是否有人獲勝  
int Gobang::ifwin(int com,int pla){  
    for(int i=0;i<=10;i++)  
        for(int j=0;j<=10;j++){  
              getfive(i,j);  
              for(int m=0;m<5;m++){  
                      if(five[m][0]==com&&five[m][1]==com&&five[m][2]==com&&five[m][3]==com&&five[m][4]==com)  
                          return (com);  
                      if(five[0][m]==com&&five[1][m]==com&&five[2][m]==com&&five[3][m]==com&&five[4][m]==com)  
                          return (com);}  
              if(five[0][0]==com&&five[1][1]==com&&five[2][2]==com&&five[3][3]==com&&five[4][4]==com)  
                   return (com);  
              if(five[0][4]==com&&five[1][3]==com&&five[2][2]==com&&five[3][1]==com&&five[4][0]==com)  
                   return (com);  
              }  
                
    for(int i=0;i<=10;i++)  
        for(int j=0;j<=10;j++){  
              getfive(i,j);  
              for(int m=0;m<5;m++){  
                      if(five[m][0]==pla&&five[m][1]==pla&&five[m][2]==pla&&five[m][3]==pla&&five[m][4]==pla)  
                          return pla;  
                      if(five[0][m]==pla&&five[1][m]==pla&&five[2][m]==pla&&five[3][m]==pla&&five[4][m]==pla)  
                          return pla;}  
              if(five[0][0]==pla&&five[1][1]==pla&&five[2][2]==pla&&five[3][3]==pla&&five[4][4]==pla)  
                   return pla;  
              if(five[0][4]==pla&&five[1][3]==pla&&five[2][2]==pla&&five[3][1]==pla&&five[4][0]==pla)  
                   return pla;  
              }  
      
    return 0;  
}  




  
//計算電腦和玩家得分   
   








  
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





                        
//電腦思考   
void Gobang::think(int com,int pla){  
       
     total_com=0;total_hum=0;  
       int temp=0;
     //首先判斷是否可以下一子就立即成五   
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]>0) continue;       //找空位   
                  temp=board[i+1][j+1];
                  board[i+1][j+1]=com;  
                  if(ifwin(com,pla)==com) {last1=i;last2=j;return;}                  //???   
                  board[i+1][j+1]=temp;                      //用的位置不下子 
				    
                  }  
         }  
           
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]>0) continue;       //找空位   
                  temp=board[i+1][j+1];
                  board[i+1][j+1]=pla;  
                  if(ifwin(com,pla)==pla) {board[i+1][j+1]=com;last1=i;last2=j;return;}                  //阻止玩家   
                  board[i+1][j+1]=temp;                      //用的位置不下子   
                  }  
         }      
           
  
           
         /*  
      //??走的第一步，跟子，避??界   
      if(computernum==0) {  
                         if(last1<=2&&board[last1+2][last2+1]==0)   
                            {board[last1+2][last2+1]=com;last1++;return; }  
                               else if(last1>=12&&board[last1][last2+1]==0)   
                                     {board[last1][last2+1]=com;last1--;return;}  
                                        else if(last2<=2&&board[last1+1][last2+2]==0)   
                                            {board[last1+1][last2+2]=com;last2++;return;}  
                                                else if(last2>=12&&board[last1+1][last2]==0)   
                                                     {board[last1+1][last2]=com;last2--;return;}   
                                                        else if(board[last1+2][last2+1]==0)   
                                                           {board[last1+2][last2+1]=com;last1++;return;}  
                                                                  else if(board[last1][last2+1]==0)   
                                                                        {board[last1][last2+1]=com;last1--;return;}  
                                                                          else if(board[last1+1][last2+2]==0)   
                                                                                  {board[last1+1][last2+2]=com;last2++;return;}  
                                                                                       else if(board[last1+1][last2]==0)   
                                                                                                {board[last1+1][last2]=com;last2--;return;}  
                         }  
       
      */                  
           
   //以上都不符合，開始始打分  
   getresults(com,pla);   
       
              
          
    
}     


/*

void Gobang::countall(int com,int pla){
	
	 for(int k=0;k<15;k++)  
            for(int n=0;n<15;j++){  
                    comresults[k][n]=0;  
                    humresults[k][n]=0;}                //每次先置零   
       max_com=0;max_hum=0;max_com_i=0;  
       max_com_j=0;max_hum_i=0;max_hum_j=0;  
	
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			 if(!generator(com,pla,i+1,j+1)) continue;
		}
	}
	
}


*/






  
void Gobang::getresults(int com,int pla){  
       
          for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    comresults[i][j]=0;  
                    humresults[i][j]=0;}                //每次先置零   
       max_com=0;max_hum=0;max_com_i=0;  
       max_com_j=0;max_hum_i=0;max_hum_j=0;  
         
         
       //開始打分   
       r_four(com,pla);  
       r_three(com,pla);  
       r_two(com,pla);  
         
       //分電腦和玩家的最高分，并保存其坐?   
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
                      
       //分析最高分，決定攻或是防  
         
       if(max_com>=1000) {                                      //電腦能成四   
                       board[max_com_i+1][max_com_j+1]=com;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=1000) {                                      //阻止玩家四   
                       board[max_hum_i+1][max_hum_j+1]=com;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
       if(max_com>=18) {                                      //電腦能成雙三 （或更多）   
                       board[max_com_i+1][max_com_j+1]=com;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=18) {                                      //阻止玩家雙三 （或更多）   
                       board[max_hum_i+1][max_hum_j+1]=com;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
         
       if(max_com==17||max_com==16) {                                      //另一种不能取胜?三  
                       board[max_com_i+1][max_com_j+1]=com;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum==17||max_hum==16) {                                        
                       board[max_hum_i+1][max_hum_j+1]=com;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
                         
                         
       if(max_com<16&&max_com>=10) {                                      //3,3+1 ,3+2，?4   
                       board[max_com_i+1][max_com_j+1]=com;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum<16&&max_hum>=10) {                                        
                       board[max_hum_i+1][max_hum_j+1]=com;   
                       last1=max_hum_i;last2=max_hum_j;         
                       return;  
                       }                                        
  
       //其他情?不管玩家，??走最好的  
       board[max_com_i+1][max_com_j+1]=com;  
       last1=max_com_i;last2=max_com_j;   
       return;  
}   
  
  
  
  
void Gobang::r_four(int com,int pla){  
       
     for(int i=1;i<14;i++)  
         for(int j=1;j<14;j++){  
                   
                 if(board[i+1][j+1]>0) continue;  
                
                 if(!generator(com,pla,i+1,j+1)) continue;
				 
			
                 //第一种情?    xooo@x  
                   
                 if(board[i+1][j+2]<0&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]==com&&board[i+1][j-3]<0) comresults[i][j]+=100;  
                 if(board[i+2][j+2]<0&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]==com&&board[i-3][j-3]<0) comresults[i][j]+=100;   
                 if(board[i+2][j+1]<0&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]==com&&board[i-3][j+1]<0) comresults[i][j]+=100;  
                 if(board[i+2][j]<0&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]==com&&board[i-3][j+5]<0) comresults[i][j]+=100;  
                 if(board[i+1][j]<0&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]==com&&board[i+1][j+5]<0) comresults[i][j]+=100;  
                 if(board[i][j]<0&&board[i+2][j+2]==com&&board[i+3][j+3]==com&&board[i+4][j+4]==com&&board[i+5][j+5]<0) comresults[i][j]+=100;  
                 if(board[i][j+1]<0&&board[i+2][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]==com&&board[i+5][j+1]<0) comresults[i][j]+=100;  
                 if(board[i][j+2]<0&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]==com&&board[i+5][j-3]<0) comresults[i][j]+=100;  
                   
                 if(board[i+1][j+2]<0&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]==pla&&board[i+1][j-3]<0) humresults[i][j]+=100;  
                 if(board[i+2][j+2]<0&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]==pla&&board[i-3][j-3]<0) humresults[i][j]+=100;   
                 if(board[i+2][j+1]<0&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]==pla&&board[i-3][j+1]<0) humresults[i][j]+=100;  
                 if(board[i+2][j]<0&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]==pla&&board[i-3][j+5]<0) humresults[i][j]+=100;  
                 if(board[i+1][j]<0&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]==pla&&board[i+1][j+5]<0) humresults[i][j]+=100;  
                 if(board[i][j]<0&&board[i+2][j+2]==pla&&board[i+3][j+3]==pla&&board[i+4][j+4]==pla&&board[i+5][j+5]<0) humresults[i][j]+=100;  
                 if(board[i][j+1]<0&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]==pla&&board[i+5][j+1]<0) humresults[i][j]+=100;  
                 if(board[i][j+2]<0&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]==pla&&board[i+5][j-3]<0) humresults[i][j]+=100;  
                   
                   
                 //第二种情?   xoo@ox  
                   
                 if(board[i+1][j+3]<0&&board[i+1][j+2]==com&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]<0) comresults[i][j]+=100;  
                 if(board[i+3][j+3]<0&&board[i+2][j+2]==com&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]<0) comresults[i][j]+=100;   
                 if(board[i+3][j+1]<0&&board[i+2][j+1]==com&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]<0) comresults[i][j]+=100;  
                 if(board[i+3][j-1]<0&&board[i+2][j]==com&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]<0) comresults[i][j]+=100;  
                 if(board[i+1][j-1]<0&&board[i+1][j]==com&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]<0) comresults[i][j]+=100;  
                 if(board[i-1][j-1]<0&&board[i][j]==com&&board[i+2][j+2]==com&&board[i+3][j+3]==com&&board[i+4][j+4]<0) comresults[i][j]+=100;  
                 if(board[i-1][j+1]<0&&board[i][j+1]==com&&board[i][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]<0) comresults[i][j]+=100;  
                 if(board[i-1][j+3]<0&&board[i][j+2]==com&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]<0) comresults[i][j]+=100;  
                   
                 if(board[i+1][j+3]<0&&board[i+1][j+2]==pla&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]<0) humresults[i][j]+=100;  
                 if(board[i+3][j+3]<0&&board[i+2][j+2]==pla&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]<0) humresults[i][j]+=100;   
                 if(board[i+3][j+1]<0&&board[i+2][j+1]==pla&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]<0) humresults[i][j]+=100;  
                 if(board[i+3][j-1]<0&&board[i+2][j]==pla&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]<0) humresults[i][j]+=100;  
                 if(board[i+1][j-1]<0&&board[i+1][j]==pla&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]<0) humresults[i][j]+=100;  
                 if(board[i-1][j-1]<0&&board[i][j]==pla&&board[i+2][j+2]==pla&&board[i+3][j+3]==pla&&board[i+4][j+4]<0) humresults[i][j]+=100;  
                 if(board[i-1][j+1]<0&&board[i][j+1]==pla&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]<0) humresults[i][j]+=100;  
                 if(board[i-1][j+3]<0&&board[i][j+2]==pla&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]<0) humresults[i][j]+=100;  
                   
                   
                   
                   
                   
                 //第三种情?     *ooo@x   
                   
                 if(board[i+1][j+2]<0&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]==com&&board[i+1][j-3]==pla) comresults[i][j]+=11;  
                 if(board[i+2][j+2]<0&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]==com&&board[i-3][j-3]==pla) comresults[i][j]+=11;  
                 if(board[i+2][j+1]<0&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]==com&&board[i-3][j+1]==pla) comresults[i][j]+=11;  
                 if(board[i+2][j-2]<0&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]==com&&board[i-3][j+5]==pla) comresults[i][j]+=11;  
                 if(board[i+1][j]<0&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]==com&&board[i+1][j+5]==pla) comresults[i][j]+=11;  
                 if(board[i][j]<0&&board[i+2][j+2]==com&&board[i+2][j+3]==com&&board[i+4][j+4]==com&&board[i+5][j+5]==pla) comresults[i][j]+=11;  
                 if(board[i][j+1]<0&&board[i+2][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]==com&&board[i+5][j+1]==pla) comresults[i][j]+=11;  
                 if(board[i][j+2]<0&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]==com&&board[i+5][j-3]==pla) comresults[i][j]+=11;  
                   
               //  
                 if(board[i+1][j+2]<0&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]==pla&&board[i+1][j-3]==com) humresults[i][j]+=11;   
                 if(board[i+2][j+2]<0&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]==pla&&board[i-3][j-3]==com) humresults[i][j]+=11; 
                 if(board[i+2][j+1]<0&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]==pla&&board[i-3][j+1]==com) humresults[i][j]+=11;   
                 if(board[i+2][j-2]<0&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]==pla&&board[i-3][j+5]==com) humresults[i][j]+=11; 
                 if(board[i+1][j]<0&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]==pla&&board[i+1][j+5]==com) humresults[i][j]+=11;  
                 if(board[i][j]<0&&board[i+2][j+2]==pla&&board[i+2][j+3]==pla&&board[i+4][j+4]==pla&&board[i+5][j+5]==com) humresults[i][j]+=11;   
                 if(board[i][j+1]<0&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]==pla&&board[i+5][j+1]==com) humresults[i][j]+=11;  
                 if(board[i][j+2]<0&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]==pla&&board[i+5][j-3]==com) humresults[i][j]+=11;    
                   
                 //第四种情?   *oo@ox                from_here_0607_1700       
                   
                 if(board[i+1][j+3]<0&&board[i+1][j+2]==com&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]==pla) comresults[i][j]+=11;  
                 if(board[i+3][j+3]<0&&board[i+2][j+2]==com&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]==pla) comresults[i][j]+=11;   
                 if(board[i+3][j+1]<0&&board[i+2][j+1]==com&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]==pla) comresults[i][j]+=11;  
                 if(board[i+3][j-1]<0&&board[i+2][j]==com&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]==pla) comresults[i][j]+=11;  
                 if(board[i+1][j-1]<0&&board[i+1][j]==com&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]==pla) comresults[i][j]+=11;  
                 if(board[i-1][j-1]<0&&board[i][j]==com&&board[i+2][j+2]==com&&board[i+3][j+3]==com&&board[i+4][j+4]==pla) comresults[i][j]+=11;  
                 if(board[i-1][j+1]<0&&board[i][j+1]==com&&board[i+2][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]==pla) comresults[i][j]+=11;  
                 if(board[i-1][j+3]<0&&board[i][j+2]==com&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]==pla) comresults[i][j]+=11;  
                   
                 if(board[i+1][j+3]<0&&board[i+1][j+2]==pla&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]==com) humresults[i][j]+=11;  
                 if(board[i+3][j+3]<0&&board[i+2][j+2]==pla&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]==com) humresults[i][j]+=11;   
                 if(board[i+3][j+1]<0&&board[i+2][j+1]==pla&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]==com) humresults[i][j]+=11;  
                 if(board[i+3][j-1]<0&&board[i+2][j]==pla&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]==com) humresults[i][j]+=11;  
                 if(board[i+1][j-1]<0&&board[i+1][j]==pla&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]==com) humresults[i][j]+=11;  
                 if(board[i-1][j-1]<0&&board[i][j]==pla&&board[i+2][j+2]==pla&&board[i+3][j+3]==pla&&board[i+4][j+4]==com) humresults[i][j]+=11;  
                 if(board[i-1][j+1]<0&&board[i][j+1]==pla&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]==com) humresults[i][j]+=11;  
                 if(board[i-1][j+3]<0&&board[i][j+2]==pla&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]==com) humresults[i][j]+=11;  
                   
                 //第五种情?   *o@oox  
                   
                 if(board[i+1][j+3]==pla&&board[i+1][j+2]==com&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]<0) comresults[i][j]+=11;  
                 if(board[i+3][j+3]==pla&&board[i+2][j+2]==com&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]<0) comresults[i][j]+=11;   
                 if(board[i+3][j+1]==pla&&board[i+2][j+1]==com&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]<0) comresults[i][j]+=11;  
                 if(board[i+3][j-1]==pla&&board[i+2][j]==com&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]<0) comresults[i][j]+=11;  
                 if(board[i+1][j-1]==pla&&board[i+1][j]==com&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]<0) comresults[i][j]+=11;  
                 if(board[i-1][j-1]==pla&&board[i][j]==com&&board[i+2][j+2]==com&&board[i+3][j+3]==com&&board[i+4][j+4]<0) comresults[i][j]+=11;  
                 if(board[i-1][j+1]==pla&&board[i][j+1]==com&&board[i+2][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]<0) comresults[i][j]+=11;  
                 if(board[i-1][j+3]==pla&&board[i][j+2]==com&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]<0) comresults[i][j]+=11;  
                   
                 if(board[i+1][j+3]==com&&board[i+1][j+2]==pla&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]<0) humresults[i][j]+=11;  
                 if(board[i+3][j+3]==com&&board[i+2][j+2]==pla&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]<0) humresults[i][j]+=11;   
                 if(board[i+3][j+1]==com&&board[i+2][j+1]==pla&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]<0) humresults[i][j]+=11;  
                 if(board[i+3][j-1]==com&&board[i+2][j]==pla&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]<0) humresults[i][j]+=11;  
                 if(board[i+1][j-1]==com&&board[i+1][j]==pla&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]<0) humresults[i][j]+=11;  
                 if(board[i-1][j-1]==com&&board[i][j]==pla&&board[i+2][j+2]==pla&&board[i+3][j+3]==pla&&board[i+4][j+4]<0) humresults[i][j]+=11;  
                 if(board[i-1][j+1]==com&&board[i][j+1]==pla&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]<0) humresults[i][j]+=11;  
                 if(board[i-1][j+3]==com&&board[i][j+2]==pla&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]<0) humresults[i][j]+=11;  
                   
                 //第六种情?  *@ooox  
                   
                 if(board[i+1][j+2]==pla&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]==com&&board[i+1][j-3]<0) comresults[i][j]+=11;  
                 if(board[i+2][j+2]==pla&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]==com&&board[i-3][j-3]<0) comresults[i][j]+=11;  
                 if(board[i+2][j+1]==pla&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]==com&&board[i-3][j+1]<0) comresults[i][j]+=11;  
                 if(board[i+2][j]==pla&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]==com&&board[i-3][j+5]<0) comresults[i][j]+=11;  
                 if(board[i+1][j]==pla&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]==com&&board[i+1][j+5]<0) comresults[i][j]+=11;  
                 if(board[i][j]==pla&&board[i+2][j+2]==com&&board[i+2][j+3]==com&&board[i+4][j+4]==com&&board[i+5][j+5]<0) comresults[i][j]+=11;  
                 if(board[i][j+1]==pla&&board[i+2][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]==com&&board[i+5][j+1]<0) comresults[i][j]+=11;  
                 if(board[i][j+2]==pla&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]==com&&board[i+5][j-3]<0) comresults[i][j]+=11;  
                   
                 if(board[i+1][j+2]==com&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]==pla&&board[i+1][j-3]<0) humresults[i][j]+=11;  
                 if(board[i+2][j+2]==com&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]==pla&&board[i-3][j-3]<0) humresults[i][j]+=11;  
                 if(board[i+2][j+1]==com&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]==pla&&board[i-3][j+1]<0) humresults[i][j]+=11;  
                 if(board[i+2][j]==com&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]==pla&&board[i-3][j+5]<0) humresults[i][j]+=11;  
                 if(board[i+1][j]==com&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]==pla&&board[i+1][j+5]<0) humresults[i][j]+=11;  
                 if(board[i][j]==com&&board[i+2][j+2]==pla&&board[i+2][j+3]==pla&&board[i+4][j+4]==pla&&board[i+5][j+5]<0) humresults[i][j]+=11;  
                 if(board[i][j+1]==com&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]==pla&&board[i+5][j+1]<0) humresults[i][j]+=11;  
                 if(board[i][j+2]==com&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]==pla&&board[i+5][j-3]<0) humresults[i][j]+=11;    
                   
                 //第七种情?   @xooo*          0611
                   
                 if(board[i+1][j+2]<0&&board[i+1][j+3]==com&&board[i+1][j+4]==com&&board[i+1][j+5]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+2]<0&&board[i+3][j+3]==com&&board[i+4][j+4]==com&&board[i+5][j+5]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+1]<0&&board[i+3][j+1]==com&&board[i+4][j+1]==com&&board[i+5][j+1]==com) comresults[i][j]+=9;  
                 if(board[i+2][j]<0&&board[i+3][j-1]==com&&board[i+4][j-2]==com&&board[i+5][j-3]==com) comresults[i][j]+=9;  
                 if(board[i+1][j]<0&&board[i+1][j-1]==com&&board[i+1][j-2]==com&&board[i+1][j-3]==com) comresults[i][j]+=9;  
                 if(board[i][j]<0&&board[i-1][j-1]==com&&board[i-2][j-2]==com&&board[i-3][j-3]==com) comresults[i][j]+=9;  
                 if(board[i][j+1]<0&&board[i-1][j+1]==com&&board[i-2][j+1]==com&&board[i-3][j+1]==com) comresults[i][j]+=9;  
                 if(board[i][j+2]<0&&board[i-1][j+3]==com&&board[i-2][j+4]==com&&board[i-3][j+5]==com) comresults[i][j]+=9;  
                   
                 if(board[i+1][j+2]<0&&board[i+1][j+3]==pla&&board[i+1][j+4]==pla&&board[i+1][j+5]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+2]<0&&board[i+3][j+3]==pla&&board[i+4][j+4]==pla&&board[i+5][j+5]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+1]<0&&board[i+3][j+1]==pla&&board[i+4][j+1]==pla&&board[i+5][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j]<0&&board[i+3][j-1]==pla&&board[i+4][j-2]==pla&&board[i+5][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i+1][j]<0&&board[i+1][j-1]==pla&&board[i+1][j-2]==pla&&board[i+1][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i][j]<0&&board[i-1][j-1]==pla&&board[i-2][j-2]==pla&&board[i-3][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i][j+1]<0&&board[i-1][j+1]==pla&&board[i-2][j+1]==pla&&board[i-3][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i][j+2]<0&&board[i-1][j+3]==pla&&board[i-2][j+4]==pla&&board[i-3][j+5]==pla) humresults[i][j]+=9;  
                   
                 //第八种情?  ox@oo*     *是?了不和活三重复加分   
                   
                 if(board[i+1][j+4]==pla&&board[i+1][j+3]==com&&board[i+1][j+2]==com&&board[i+1][j]<0&&board[i+1][j-1]==com) comresults[i][j]+=9;  
                 if(board[i+4][j+4]==pla&&board[i+3][j+3]==com&&board[i+2][j+2]==com&&board[i][j]<0&&board[i-1][j-1]==com) comresults[i][j]+=9;   
                 if(board[i+4][j+1]==pla&&board[i+3][j+1]==com&&board[i+2][j+1]==com&&board[i][j+1]<0&&board[i-1][j+1]==com) comresults[i][j]+=9;  
                 if(board[i+4][j-2]==pla&&board[i+3][j-1]==com&&board[i+2][j]==com&&board[i][j+2]<0&&board[i-1][j+3]==com) comresults[i][j]+=9;  
                 if(board[i+1][j-2]==pla&&board[i+1][j-1]==com&&board[i+1][j]==com&&board[i+1][j+2]<0&&board[i+1][j+3]==com) comresults[i][j]+=9;  
                 if(board[i-2][j-2]==pla&&board[i-1][j-1]==com&&board[i][j]==com&&board[i+2][j+2]<0&&board[i+3][j+3]==com) comresults[i][j]+=9;  
                 if(board[i-2][j+1]==pla&&board[i-1][j+1]==com&&board[i][j+1]==com&&board[i+2][j+1]<0&&board[i+3][j+1]==com) comresults[i][j]+=9;  
                 if(board[i-2][j+4]==pla&&board[i-1][j+3]==com&&board[i][j+2]==com&&board[i+2][j]<0&&board[i+3][j-1]==com) comresults[i][j]+=9;  
                   
                 if(board[i+1][j+4]==com&&board[i+1][j+3]==pla&&board[i+1][j+2]==pla&&board[i+1][j]<0&&board[i+1][j-1]==pla) humresults[i][j]+=9;  
                 if(board[i+4][j+4]==com&&board[i+3][j+3]==pla&&board[i+2][j+2]==pla&&board[i][j]<0&&board[i-1][j-1]==pla) humresults[i][j]+=9;   
                 if(board[i+4][j+1]==com&&board[i+3][j+1]==pla&&board[i+2][j+1]==pla&&board[i][j+1]<0&&board[i-1][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i+4][j-2]==com&&board[i+3][j-1]==pla&&board[i+2][j]==pla&&board[i][j+2]<0&&board[i-1][j+3]==pla) humresults[i][j]+=9;  
                 if(board[i+1][j-2]==com&&board[i+1][j-1]==pla&&board[i+1][j]==pla&&board[i+1][j+2]<0&&board[i+1][j+3]==pla) humresults[i][j]+=9;  
                 if(board[i-2][j-2]==com&&board[i-1][j-1]==pla&&board[i][j]==pla&&board[i+2][j+2]<0&&board[i+3][j+3]==pla) humresults[i][j]+=9;  
                 if(board[i-2][j+1]==com&&board[i-1][j+1]==pla&&board[i][j+1]==pla&&board[i+2][j+1]<0&&board[i+3][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i-2][j+4]==com&&board[i-1][j+3]==pla&&board[i][j+2]==pla&&board[i+2][j]<0&&board[i+3][j-1]==pla) humresults[i][j]+=9;   
                   
                 //第九种情?   oxo@o*     0906
                   
                 if(board[i+1][j+3]==pla&&board[i+1][j+2]==com&&board[i+1][j]==com&&board[i+1][j-1]<0&&board[i+1][j-2]==com) comresults[i][j]+=9;  
                 if(board[i+3][j+3]==pla&&board[i+2][j+2]==com&&board[i][j]==com&&board[i-1][j-1]<0&&board[i-2][j-2]==com) comresults[i][j]+=9;  
                 if(board[i+3][j+1]==pla&&board[i+2][j+1]==com&&board[i][j+1]==com&&board[i-1][j+1]<0&&board[i-2][j+1]==com) comresults[i][j]+=9;  
                 if(board[i+3][j-1]==pla&&board[i+2][j]==com&&board[i][j+2]==com&&board[i-1][j+3]<0&&board[i-2][j+4]==com) comresults[i][j]+=9;  
                 if(board[i+1][j-1]==pla&&board[i+1][j]==com&&board[i+1][j+2]==com&&board[i+1][j+3]<0&&board[i+1][j+4]==com) comresults[i][j]+=9;  
                 if(board[i-1][j-1]==pla&&board[i][j]==com&&board[i+2][j+2]==com&&board[i+3][j+3]<0&&board[i+4][j+4]==com) comresults[i][j]+=9;  
                 if(board[i-1][j+1]==pla&&board[i][j+1]==com&&board[i+2][j+1]==com&&board[i+3][j+1]<0&&board[i+4][j+1]==com) comresults[i][j]+=9;  
                 if(board[i-1][j+3]==pla&&board[i][j+2]==com&&board[i+2][j]==com&&board[i+3][j-1]<0&&board[i+4][j-2]==com) comresults[i][j]+=9;  
                   
                 if(board[i+1][j+3]==pla&&board[i+1][j+2]==pla&&board[i+1][j]==pla&&board[i+1][j-1]<0&&board[i+1][j-2]==pla) humresults[i][j]+=9;  
                 if(board[i+3][j+3]==pla&&board[i+2][j+2]==pla&&board[i][j]==pla&&board[i-1][j-1]<0&&board[i-2][j-2]==pla) humresults[i][j]+=9;  
                 if(board[i+3][j+1]==pla&&board[i+2][j+1]==pla&&board[i][j+1]==pla&&board[i-1][j+1]<0&&board[i-2][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i+3][j-1]==pla&&board[i+2][j]==pla&&board[i][j+2]==pla&&board[i-1][j+3]<0&&board[i-2][j+4]==pla) humresults[i][j]+=9;  
                 if(board[i+1][j-1]==pla&&board[i+1][j]==pla&&board[i+1][j+2]==pla&&board[i+1][j+3]<0&&board[i+1][j+4]==pla) humresults[i][j]+=9;  
                 if(board[i-1][j-1]==pla&&board[i][j]==pla&&board[i+2][j+2]==pla&&board[i+3][j+3]<0&&board[i+4][j+4]==pla) humresults[i][j]+=9;  
                 if(board[i-1][j+1]==pla&&board[i][j+1]==pla&&board[i+2][j+1]==pla&&board[i+3][j+1]<0&&board[i+4][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i-1][j+3]==pla&&board[i][j+2]==pla&&board[i+2][j]==pla&&board[i+3][j-1]<0&&board[i+4][j-2]==pla) humresults[i][j]+=9;   
                   
                 //第十种情?   oxoo@*   
                   
                 if(board[i+1][j+2]==pla&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]<0&&board[i+1][j-3]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+2]==2&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]<0&&board[i-3][j-3]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+1]==2&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]<0&&board[i-3][j+1]==com) comresults[i][j]+=9;  
                 if(board[i+2][j]==pla&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]<0&&board[i-3][j+5]==com) comresults[i][j]+=9;  
                 if(board[i+1][j]==pla&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]<0&&board[i+1][j+5]==com) comresults[i][j]+=9;  
                 if(board[i][j]==pla&&board[i+2][j+2]==com&&board[i+2][j+3]==com&&board[i+4][j+4]<0&&board[i+5][j+5]==com) comresults[i][j]+=9;  
                 if(board[i][j+1]==pla&&board[i+2][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]<0&&board[i+5][j+1]==com) comresults[i][j]+=9;  
                 if(board[i][j+2]==pla&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]<0&&board[i+5][j-3]==com) comresults[i][j]+=9;  
                   
                 if(board[i+1][j+2]==com&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]<0&&board[i+1][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+2]==com&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]<0&&board[i-3][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+1]==com&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]<0&&board[i-3][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j]==com&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]<0&&board[i-3][j+5]==pla) humresults[i][j]+=9;  
                 if(board[i+1][j]==com&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]<0&&board[i+1][j+5]==pla) humresults[i][j]+=9;  
                 if(board[i][j]==com&&board[i+2][j+2]==pla&&board[i+2][j+3]==pla&&board[i+4][j+4]<0&&board[i+5][j+5]==pla) humresults[i][j]+=9;  
                 if(board[i][j+1]==com&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]<0&&board[i+5][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i][j+2]==com&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]<0&&board[i+5][j-3]==pla) humresults[i][j]+=9;   
                   
                 //第十一种情?   @oxoo  
                   
                 if(board[i+1][j+2]==com&&board[i+1][j+3]<0&&board[i+1][j+4]==com&&board[i+1][j+5]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+2]==com&&board[i+3][j+3]<0&&board[i+4][j+4]==com&&board[i+5][j+5]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+1]==com&&board[i+3][j+1]<0&&board[i+4][j+1]==com&&board[i+5][j+1]==com) comresults[i][j]+=9;  
                 if(board[i+2][j]==com&&board[i+3][j-1]<0&&board[i+4][j-2]==com&&board[i+5][j-3]==com) comresults[i][j]+=9;  
                 if(board[i+1][j]==com&&board[i+1][j-1]<0&&board[i+1][j-2]==com&&board[i+1][j-3]==com) comresults[i][j]+=9;  
                 if(board[i][j]==com&&board[i-1][j-1]<0&&board[i-2][j-2]==com&&board[i-3][j-3]==com) comresults[i][j]+=9;  
                 if(board[i][j+1]==com&&board[i-1][j+1]<0&&board[i-2][j+1]==com&&board[i-3][j+1]==com) comresults[i][j]+=9;  
                 if(board[i][j+2]==com&&board[i-1][j+3]<0&&board[i-2][j+4]==com&&board[i-3][j+5]==com) comresults[i][j]+=9;  
                   
                 if(board[i+1][j+2]==pla&&board[i+1][j+3]<0&&board[i+1][j+4]==pla&&board[i+1][j+5]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+2]==pla&&board[i+3][j+3]<0&&board[i+4][j+4]==pla&&board[i+5][j+5]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+1]==pla&&board[i+3][j+1]<0&&board[i+4][j+1]==pla&&board[i+5][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j]==pla&&board[i+3][j-1]<0&&board[i+4][j-2]==pla&&board[i+5][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i+1][j]==pla&&board[i+1][j-1]<0&&board[i+1][j-2]==pla&&board[i+1][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i][j]==pla&&board[i-1][j-1]<0&&board[i-2][j-2]==pla&&board[i-3][j-3]==pla) humresults[i][j]+=9;  
                 if(board[i][j+1]==pla&&board[i-1][j+1]<0&&board[i-2][j+1]==pla&&board[i-3][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i][j+2]==pla&&board[i-1][j+3]<0&&board[i-2][j+4]==pla&&board[i-3][j+5]==pla) humresults[i][j]+=9;  
                   
                 //第十二种情?   o@xoo   
                   
                 if(board[i+1][j]==com&&board[i+1][j+2]<0&&board[i+1][j+3]<0&&board[i+1][j+4]==com) comresults[i][j]+=9;  
                 if(board[i][j]==com&&board[i+2][j+2]<0&&board[i+3][j+3]<0&&board[i+4][j+4]==com) comresults[i][j]+=9;  
                 if(board[i][j+1]==com&&board[i+2][j+1]<0&&board[i+3][j+1]<0&&board[i+4][j+1]==com) comresults[i][j]+=9;  
                 if(board[i][j+2]==com&&board[i+2][j]<0&&board[i+3][j-1]<0&&board[i+4][j-2]==com) comresults[i][j]+=9;  
                 if(board[i+1][j+2]==com&&board[i+1][j]<0&&board[i+1][j-1]<0&&board[i+1][j-2]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+2]==com&&board[i][j]<0&&board[i-1][j-1]<0&&board[i-2][j-2]==com) comresults[i][j]+=9;  
                 if(board[i+2][j+1]==com&&board[i][j+1]<0&&board[i-1][j+1]<0&&board[i-2][j+1]==com) comresults[i][j]+=9;  
                 if(board[i+2][j]==com&&board[i][j+2]<0&&board[i-1][j+3]<0&&board[i-2][j+4]==com) comresults[i][j]+=9;  
                   
                 if(board[i+1][j]==pla&&board[i+1][j+2]<0&&board[i+1][j+3]<0&&board[i+1][j+4]==pla) humresults[i][j]+=9;  
                 if(board[i][j]==pla&&board[i+2][j+2]<0&&board[i+3][j+3]<0&&board[i+4][j+4]==pla) humresults[i][j]+=9;  
                 if(board[i][j+1]==pla&&board[i+2][j+1]<0&&board[i+3][j+1]<0&&board[i+4][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i][j+2]==pla&&board[i+2][j]<0&&board[i+3][j-1]<0&&board[i+4][j-2]==pla) humresults[i][j]+=9;  
                 if(board[i+1][j+2]==pla&&board[i+1][j]<0&&board[i+1][j-1]<0&&board[i+1][j-2]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+2]==pla&&board[i][j]<0&&board[i-1][j-1]<0&&board[i-2][j-2]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j+1]==pla&&board[i][j+1]<0&&board[i-1][j+1]<0&&board[i-2][j+1]==pla) humresults[i][j]+=9;  
                 if(board[i+2][j]==pla&&board[i][j+2]<0&&board[i-1][j+3]<0&&board[i-2][j+4]==pla) humresults[i][j]+=9;  
                   
  
     }   
}  
       					//0608_11:50
       
void Gobang::r_three(int com,int pla){  
      
     for(int i=1;i<14;i++)  
         for(int j=1;j<14;j++){  
                   
                 if(board[i+1][j+1]>0) continue;  
                 
                 if(!generator(com,pla,i+1,j+1)) continue;
                 //第一种情?    x@oox  
                   
                 if(board[i+1][j]<0&&board[i+1][j+2]==com&&board[i+1][j+3]==com&&board[i+1][j+4]<0) comresults[i][j]+=10;  
                 if(board[i][j]<0&&board[i+2][j+2]==com&&board[i+3][j+3]==com&&board[i+4][j+4]<0) comresults[i][j]+=10;  
                 if(board[i][j+1]<0&&board[i+2][j+1]==com&&board[i+3][j+1]==com&&board[i+4][j+1]<0) comresults[i][j]+=10;  
                 if(board[i][j+2]<0&&board[i+2][j]==com&&board[i+3][j-1]==com&&board[i+4][j-2]<0) comresults[i][j]+=10;  
                 if(board[i+1][j+2]<0&&board[i+1][j]==com&&board[i+1][j-1]==com&&board[i+1][j-2]<0) comresults[i][j]+=10;  
                 if(board[i+2][j+2]<0&&board[i][j]==com&&board[i-1][j-1]==com&&board[i-2][j-2]<0) comresults[i][j]+=10;  
                 if(board[i+2][j+1]<0&&board[i][j+1]==com&&board[i-1][j+1]==com&&board[i-2][j+1]<0) comresults[i][j]+=10;  
                 if(board[i+2][j]<0&&board[i][j+2]==com&&board[i-1][j+3]==com&&board[i-2][j+4]<0) comresults[i][j]+=10;  
                   
                 if(board[i+1][j]<0&&board[i+1][j+2]==pla&&board[i+1][j+3]==pla&&board[i+1][j+4]<0) humresults[i][j]+=10;  
                 if(board[i][j]<0&&board[i+2][j+2]==pla&&board[i+3][j+3]==pla&&board[i+4][j+4]<0) humresults[i][j]+=10;  
                 if(board[i][j+1]<0&&board[i+2][j+1]==pla&&board[i+3][j+1]==pla&&board[i+4][j+1]<0) humresults[i][j]+=10;  
                 if(board[i][j+2]<0&&board[i+2][j]==pla&&board[i+3][j-1]==pla&&board[i+4][j-2]<0) humresults[i][j]+=10;  
                 if(board[i+1][j+2]<0&&board[i+1][j]==pla&&board[i+1][j-1]==pla&&board[i+1][j-2]<0) humresults[i][j]+=10;  
                 if(board[i+2][j+2]<0&&board[i][j]==pla&&board[i-1][j-1]==pla&&board[i-2][j-2]<0) humresults[i][j]+=10;  
                 if(board[i+2][j+1]<0&&board[i][j+1]==pla&&board[i-1][j+1]==pla&&board[i-2][j+1]<0) humresults[i][j]+=10;  
                 if(board[i+2][j]<0&&board[i][j+2]==pla&&board[i-1][j+3]==pla&&board[i-2][j+4]<0) humresults[i][j]+=10;  
                   
                   
                 //第二种情?   xo@ox         06/10
                 if(board[i+1][j+2]==com&&board[i+1][j]==com&&board[i+1][j-1]<0&&board[i+1][j+3]<0) comresults[i][j]+=10;   
                 if(board[i][j+1]==com&&board[i+2][j+1]==com&&board[i-1][j+1]<0&&board[i+3][j+1]<0) comresults[i][j]+=10;  
                 if(board[i+2][j+2]==com&&board[i][j]==com&&board[i-1][j-1]<0&&board[i+3][j+3]<0) comresults[i][j]+=10;  
                 if(board[i][j+2]==com&&board[i+2][j]==com&&board[i+3][j-1]<0&&board[i+3][j-1]<0) comresults[i][j]+=10;  
                   
                 if(board[i+1][j+2]==pla&&board[i+1][j]==pla&&board[i+1][j-1]<0&&board[i+1][j+3]<0) humresults[i][j]+=10;   
                 if(board[i][j+1]==pla&&board[i+2][j+1]==pla&&board[i-1][j+1]<0&&board[i+3][j+1]<0) humresults[i][j]+=10;  
                 if(board[i+2][j+2]==pla&&board[i][j]==pla&&board[i-1][j-1]<0&&board[i+3][j+3]<0) humresults[i][j]+=10;  
                 if(board[i][j+2]==pla&&board[i+2][j]==pla&&board[i+3][j-1]<0&&board[i+3][j-1]<0) humresults[i][j]+=10;  
                   
                 //第三种情?  x@xoox   
                   
                 if(board[i+1][j]<0&&board[i+1][j+2]<0&&board[i+1][j+3]==com&&board[i+1][j+4]==com&&board[i+1][j+5]<0) comresults[i][j]+=9;  
                 if(board[i][j]<0&&board[i+2][j+2]<0&&board[i+3][j+3]==com&&board[i+4][j+4]==com&&board[i+5][j+5]<0) comresults[i][j]+=9;  
                 if(board[i][j+1]<0&&board[i+2][j+1]<0&&board[i+3][j+1]==com&&board[i+4][j+1]==com&&board[i+5][j+1]<0) comresults[i][j]+=9;  
                 if(board[i][j+2]<0&&board[i+2][j]<0&&board[i+3][j-1]==com&&board[i+4][j-2]==com&&board[i+5][j-3]<0) comresults[i][j]+=9;  
                 if(board[i+1][j+2]<0&&board[i+1][j]<0&&board[i+1][j-1]==com&&board[i+1][j-2]==com&&board[i+1][j-3]<0) comresults[i][j]+=9;  
                 if(board[i+2][j+2]<0&&board[i][j]<0&&board[i-1][j-1]==com&&board[i-2][j-2]==com&&board[i-3][j-3]<0) comresults[i][j]+=9;  
                 if(board[i+2][j+1]<0&&board[i][j+1]<0&&board[i-1][j+1]==com&&board[i-2][j+1]==com&&board[i-3][j+1]<0) comresults[i][j]+=9;  
                 if(board[i+2][j]<0&&board[i][j+2]<0&&board[i-1][j+3]==com&&board[i-2][j+4]==com&&board[i-3][j+5]<0) comresults[i][j]+=9;  
                   
                 if(board[i+1][j]<0&&board[i+1][j+2]<0&&board[i+1][j+3]==pla&&board[i+1][j+4]==pla&&board[i+1][j+5]<0) humresults[i][j]+=9;  
                 if(board[i][j]<0&&board[i+2][j+2]<0&&board[i+3][j+3]==pla&&board[i+4][j+4]==pla&&board[i+5][j+5]<0) humresults[i][j]+=9;  
                 if(board[i][j+1]<0&&board[i+2][j+1]<0&&board[i+3][j+1]==pla&&board[i+4][j+1]==pla&&board[i+5][j+1]<0) humresults[i][j]+=9;  
                 if(board[i][j+2]<0&&board[i+2][j]<0&&board[i+3][j-1]==pla&&board[i+4][j-2]==pla&&board[i+5][j-3]<0) humresults[i][j]+=9;  
                 if(board[i+1][j+2]<0&&board[i+1][j]<0&&board[i+1][j-1]==pla&&board[i+1][j-2]==pla&&board[i+1][j-3]<0) humresults[i][j]+=9;  
                 if(board[i+2][j+2]<0&&board[i][j]<0&&board[i-1][j-1]==pla&&board[i-2][j-2]==pla&&board[i-3][j-3]<0) humresults[i][j]+=9;  
                 if(board[i+2][j+1]<0&&board[i][j+1]<0&&board[i-1][j+1]==pla&&board[i-2][j+1]==pla&&board[i-3][j+1]<0) humresults[i][j]+=9;  
                 if(board[i+2][j]<0&&board[i][j+2]<0&&board[i-1][j+3]==pla&&board[i-2][j+4]==pla&&board[i-3][j+5]<0) humresults[i][j]+=9;  
                   
                 //第四种情?    xox@ox  
                   
                 if(board[i+1][j+3]<0&&board[i+1][j+2]==com&&board[i+1][j]<0&&board[i+1][j-1]==com&&board[i+1][j-2]<0) comresults[i][j]+=9;  
                 if(board[i+3][j+3]<0&&board[i+2][j+2]==com&&board[i][j]<0&&board[i-1][j-1]==com&&board[i-2][j-2]<0) comresults[i][j]+=9;  
                 if(board[i+3][j+1]<0&&board[i+2][j+1]==com&&board[i][j+1]<0&&board[i-1][j+1]==com&&board[i-2][j+1]<0) comresults[i][j]+=9;  
                 if(board[i+3][j-1]<0&&board[i+2][j]==com&&board[i][j+2]<0&&board[i-1][j+3]==com&&board[i-2][j+4]<0) comresults[i][j]+=9;  
                 if(board[i+1][j-1]<0&&board[i+1][j]==com&&board[i+1][j+2]<0&&board[i+1][j+3]==com&&board[i+1][j+4]<0) comresults[i][j]+=9;  
                 if(board[i-1][j-1]<0&&board[i][j]==com&&board[i+2][j+2]<0&&board[i+3][j+3]==com&&board[i+4][j+4]<0) comresults[i][j]+=9;  
                 if(board[i-1][j+1]<0&&board[i][j+1]==com&&board[i+2][j+1]<0&&board[i+3][j+1]==com&&board[i+4][j+1]<0) comresults[i][j]+=9;  
                 if(board[i-1][j+3]<0&&board[i][j+2]==com&&board[i+2][j]<0&&board[i+3][j-1]==com&&board[i+4][j-2]<0) comresults[i][j]+=9;  
                   
                 if(board[i+1][j+3]<0&&board[i+1][j+2]==pla&&board[i+1][j]<0&&board[i+1][j-1]==pla&&board[i+1][j-2]<0) humresults[i][j]+=9;  
                 if(board[i+3][j+3]<0&&board[i+2][j+2]==pla&&board[i][j]<0&&board[i-1][j-1]==pla&&board[i-2][j-2]<0) humresults[i][j]+=9;  
                 if(board[i+3][j+1]<0&&board[i+2][j+1]==pla&&board[i][j+1]<0&&board[i-1][j+1]==pla&&board[i-2][j+1]<0) humresults[i][j]+=9;  
                 if(board[i+3][j-1]<0&&board[i+2][j]==pla&&board[i][j+2]<0&&board[i-1][j+3]==pla&&board[i-2][j+4]<0) humresults[i][j]+=9;  
                 if(board[i+1][j-1]<0&&board[i+1][j]==pla&&board[i+1][j+2]<0&&board[i+1][j+3]==pla&&board[i+1][j+4]<0) humresults[i][j]+=9;  
                 if(board[i-1][j-1]<0&&board[i][j]==pla&&board[i+2][j+2]<0&&board[i+3][j+3]==pla&&board[i+4][j+4]<0) humresults[i][j]+=9;  
                 if(board[i-1][j+1]<0&&board[i][j+1]==pla&&board[i+2][j+1]<0&&board[i+3][j+1]==pla&&board[i+4][j+1]<0) humresults[i][j]+=9;  
                 if(board[i-1][j+3]<0&&board[i][j+2]==pla&&board[i+2][j]<0&&board[i+3][j-1]==pla&&board[i+4][j-2]<0) humresults[i][j]+=9;  
                   
                 //第五种情?     xoxo@x  
                   
                 if(board[i+1][j+2]<0&&board[i+1][j]==com&&board[i+1][j-1]<0&&board[i+1][j-2]==com&&board[i+1][j-3]<0) comresults[i][j]+=9;  
                 if(board[i+2][j+2]<0&&board[i][j]==com&&board[i-1][j-1]<0&&board[i-2][j-2]==com&&board[i-3][j-3]<0) comresults[i][j]+=9;  
                 if(board[i+2][j+1]<0&&board[i][j+1]==com&&board[i-1][j+1]<0&&board[i-2][j+1]==com&&board[i-3][j+1]<0) comresults[i][j]+=9;   
                 if(board[i+2][j]<0&&board[i][j+2]==com&&board[i-1][j+3]<0&&board[i-2][j+4]==com&&board[i-3][j+5]<0) comresults[i][j]+=9;  
                 if(board[i+1][j]<0&&board[i+1][j+2]==com&&board[i+1][j+3]<0&&board[i+1][j+4]==com&&board[i+1][j+5]<0) comresults[i][j]+=9;  
                 if(board[i][j]<0&&board[i+2][j+2]==com&&board[i+3][j+3]<0&&board[i+4][j+4]==com&&board[i+5][j+5]<0) comresults[i][j]+=9;  
                 if(board[i][j+1]<0&&board[i+2][j+1]==com&&board[i+3][j+1]<0&&board[i+4][j+1]==com&&board[i+5][j+1]<0) comresults[i][j]+=9;  
                 if(board[i][j+2]<0&&board[i+2][j]==com&&board[i+3][j-1]<0&&board[i+4][j-2]==com&&board[i+5][j-3]<0) comresults[i][j]+=9;  
                   
                 if(board[i+1][j+2]<0&&board[i+1][j]==pla&&board[i+1][j-1]<0&&board[i+1][j-2]==pla&&board[i+1][j-3]<0) humresults[i][j]+=9;  
                 if(board[i+2][j+2]<0&&board[i][j]==pla&&board[i-1][j-1]<0&&board[i-2][j-2]==pla&&board[i-3][j-3]<0) humresults[i][j]+=9;  
                 if(board[i+2][j+1]<0&&board[i][j+1]==pla&&board[i-1][j+1]<0&&board[i-2][j+1]==pla&&board[i-3][j+1]<0) humresults[i][j]+=9;   
                 if(board[i+2][j]<0&&board[i][j+2]==pla&&board[i-1][j+3]<0&&board[i-2][j+4]==pla&&board[i-3][j+5]<0) humresults[i][j]+=9;  
                 if(board[i+1][j]<0&&board[i+1][j+2]==pla&&board[i+1][j+3]<0&&board[i+1][j+4]==pla&&board[i+1][j+5]<0) humresults[i][j]+=9;  
                 if(board[i][j]<0&&board[i+2][j+2]==pla&&board[i+3][j+3]<0&&board[i+4][j+4]==pla&&board[i+5][j+5]<0) humresults[i][j]+=9;  
                 if(board[i][j+1]<0&&board[i+2][j+1]==pla&&board[i+3][j+1]<0&&board[i+4][j+1]==pla&&board[i+5][j+1]<0) humresults[i][j]+=9;  
                 if(board[i][j+2]<0&&board[i+2][j]==pla&&board[i+3][j-1]<0&&board[i+4][j-2]==pla&&board[i+5][j-3]<0) humresults[i][j]+=9;  
                   
                 //第六种情?    x@xoxox  
                   
                 if(board[i+1][j]<0&&board[i+1][j+2]<0&&board[i+1][j+3]==com&&board[i+1][j+4]<0&&board[i+1][j+5]==com&&board[i+1][j+6]<0) comresults[i][j]+=8;   
                 if(board[i][j]<0&&board[i+2][j+2]<0&&board[i+3][j+3]==com&&board[i+4][j+4]<0&&board[i+5][j+5]==com&&board[i+6][j+6]<0) comresults[i][j]+=8;  
                 if(board[i][j+1]<0&&board[i+2][j+1]<0&&board[i+3][j+1]==com&&board[i+4][j+1]<0&&board[i+5][j+1]==com&&board[i+6][j+1]<0) comresults[i][j]+=8;  
                 if(board[i][j+2]<0&&board[i+2][j]<0&&board[i+3][j-1]==com&&board[i+4][j-2]<0&&board[i+5][j-3]==com&&board[i+6][j-4]<0) comresults[i][j]+=8;  
                 if(board[i+1][j+2]<0&&board[i+1][j]<0&&board[i+1][j-1]==com&&board[i+1][j-2]<0&&board[i+1][j-3]==com&&board[i+1][j-4]<0) comresults[i][j]+=8;  
                 if(board[i+2][j+2]<0&&board[i][j]<0&&board[i-1][j-1]==com&&board[i-2][j-2]<0&&board[i-3][j-3]==com&&board[i-4][j-4]<0) comresults[i][j]+=8;  
                 if(board[i+2][j+1]<0&&board[i][j+1]<0&&board[i-1][j+1]==com&&board[i-2][j+1]<0&&board[i-3][j+1]==com&&board[i-4][j+1]<0) comresults[i][j]+=8;  
                 if(board[i+2][j]<0&&board[i][j+2]<0&&board[i-1][j+3]==com&&board[i-2][j+4]<0&&board[i-3][j+5]==com&&board[i-4][j+6]<0) comresults[i][j]+=8;  
                   
                 if(board[i+1][j]<0&&board[i+1][j+2]<0&&board[i+1][j+3]==pla&&board[i+1][j+4]<0&&board[i+1][j+5]==pla&&board[i+1][j+6]<0) humresults[i][j]+=8;   
                 if(board[i][j]<0&&board[i+2][j+2]<0&&board[i+3][j+3]==pla&&board[i+4][j+4]<0&&board[i+5][j+5]==pla&&board[i+6][j+6]<0) humresults[i][j]+=8;  
                 if(board[i][j+1]<0&&board[i+2][j+1]<0&&board[i+3][j+1]==pla&&board[i+4][j+1]<0&&board[i+5][j+1]==pla&&board[i+6][j+1]<0) humresults[i][j]+=8;  
                 if(board[i][j+2]<0&&board[i+2][j]<0&&board[i+3][j-1]==pla&&board[i+4][j-2]<0&&board[i+5][j-3]==pla&&board[i+6][j-4]<0) humresults[i][j]+=8;  
                 if(board[i+1][j+2]<0&&board[i+1][j]<0&&board[i+1][j-1]==pla&&board[i+1][j-2]<0&&board[i+1][j-3]==pla&&board[i+1][j-4]<0) humresults[i][j]+=8;  
                 if(board[i+2][j+2]<0&&board[i][j]<0&&board[i-1][j-1]==pla&&board[i-2][j-2]<0&&board[i-3][j-3]==pla&&board[i-4][j-4]<0) humresults[i][j]+=8;  
                 if(board[i+2][j+1]<0&&board[i][j+1]<0&&board[i-1][j+1]==pla&&board[i-2][j+1]<0&&board[i-3][j+1]==pla&&board[i-4][j+1]<0) humresults[i][j]+=8;  
                 if(board[i+2][j]<0&&board[i][j+2]<0&&board[i-1][j+3]==pla&&board[i-2][j+4]<0&&board[i-3][j+5]==pla&&board[i-4][j+6]<0) humresults[i][j]+=8;  
                   
                 //第八种情?   xox@xox  
                   
                 //       
                   
                 }       
                   
}  
  
  
  
void Gobang::r_two(int com,int pla){  
         
       
     for(int i=1;i<14;i++)  
            for(int j=1;j<14;j++){  
                      
                    if(board[i+1][j+1]>0) continue;  
                    
                    if(!generator(com,pla,i+1,j+1)) continue;
                    //第一种情?  xx@oxx  
                      
                    if(board[i+1][j-1]<0&&board[i+1][j]<0&&board[i+1][j+2]==com&&board[i+1][j+3]<0&&board[i+1][j+4]<0) comresults[i][j]+=2;  
                    if(board[i-1][j-1]<0&&board[i-1][j]<0&&board[i+2][j+2]==com&&board[i+3][j+3]<0&&board[i+4][j+4]<0) comresults[i][j]+=2;  
                    if(board[i-1][j+1]<0&&board[i][j+1]<0&&board[i+2][j+1]==com&&board[i+3][j+1]<0&&board[i+4][j+1]<0) comresults[i][j]+=2;  
                    if(board[i][j+2]<0&&board[i-1][j+3]<0&&board[i+2][j]==com&&board[i+3][j-1]<0&&board[i+4][j-2]<0) comresults[i][j]+=2;  
                    if(board[i+1][j+3]<0&&board[i+1][j+2]<0&&board[i+1][j]==com&&board[i+1][j-1]<0&&board[i+1][j-2]<0) comresults[i][j]+=2;  
                    if(board[i+3][j+3]<0&&board[i+2][j+2]<0&&board[i][j]==com&&board[i-1][j-1]<0&&board[i-2][j-2]<0) comresults[i][j]+=2;  
                    if(board[i+3][j+1]<0&&board[i+2][j+1]<0&&board[i][j+1]==com&&board[i-1][j+1]<0&&board[i-2][j+1]<0) comresults[i][j]+=2;  
                    if(board[i+3][j-1]<0&&board[i+2][j]<0&&board[i][j+2]==com&&board[i-1][j+3]<0&&board[i-2][j+4]<0) comresults[i][j]+=2;  
                      
                    if(board[i+1][j-1]<0&&board[i+1][j]<0&&board[i+1][j+2]==pla&&board[i+1][j+3]<0&&board[i+1][j+4]<0) humresults[i][j]+=2;  
                    if(board[i-1][j-1]<0&&board[i-1][j]<0&&board[i+2][j+2]==pla&&board[i+3][j+3]<0&&board[i+4][j+4]<0) humresults[i][j]+=2;  
                    if(board[i-1][j+1]<0&&board[i][j+1]<0&&board[i+2][j+1]==pla&&board[i+3][j+1]<0&&board[i+4][j+1]<0) humresults[i][j]+=2;  
                    if(board[i][j+2]<0&&board[i-1][j+3]<0&&board[i+2][j]==pla&&board[i+3][j-1]<0&&board[i+4][j-2]<0) humresults[i][j]+=2;  
                    if(board[i+1][j+3]<0&&board[i+1][j+2]<0&&board[i+1][j]==pla&&board[i+1][j-1]<0&&board[i+1][j-2]<0) humresults[i][j]+=2;  
                    if(board[i+3][j+3]<0&&board[i+2][j+2]<0&&board[i][j]==pla&&board[i-1][j-1]<0&&board[i-2][j-2]<0) humresults[i][j]+=2;  
                    if(board[i+3][j+1]<0&&board[i+2][j+1]<0&&board[i][j+1]==pla&&board[i-1][j+1]<0&&board[i-2][j+1]<0) humresults[i][j]+=2;  
                    if(board[i+3][j-1]<0&&board[i+2][j]<0&&board[i][j+2]==pla&&board[i-1][j+3]<0&&board[i-2][j+4]<0) humresults[i][j]+=2;   
                      
                    //第二种情?   xx@xox   
                      
                    if(board[i+1][j-1]<0&&board[i+1][j]<0&&board[i+1][j+2]<0&&board[i+1][j+3]==com&&board[i+1][j+4]<0) comresults[i][j]+=1;  
                    if(board[i-1][j-1]<0&&board[i-1][j]<0&&board[i+2][j+2]<0&&board[i+3][j+3]==com&&board[i+4][j+4]<0) comresults[i][j]+=1;  
                    if(board[i-1][j+1]<0&&board[i][j+1]<0&&board[i+2][j+1]<0&&board[i+3][j+1]==com&&board[i+4][j+1]<0) comresults[i][j]+=1;  
                    if(board[i][j+2]<0&&board[i-1][j+3]<0&&board[i+2][j]<0&&board[i+3][j-1]==com&&board[i+4][j-2]<0) comresults[i][j]+=1;  
                    if(board[i+1][j+3]<0&&board[i+1][j+2]<0&&board[i+1][j]<0&&board[i+1][j-1]==com&&board[i+1][j-2]<0) comresults[i][j]+=1;  
                    if(board[i+3][j+3]<0&&board[i+2][j+2]<0&&board[i][j]<0&&board[i-1][j-1]==com&&board[i-2][j-2]<0) comresults[i][j]+=1;  
                    if(board[i+3][j+1]<0&&board[i+2][j+1]<0&&board[i][j+1]<0&&board[i-1][j+1]==com&&board[i-2][j+1]<0) comresults[i][j]+=1;  
                    if(board[i+3][j-1]<0&&board[i+2][j]<0&&board[i][j+2]<0&&board[i-1][j+3]==com&&board[i-2][j+4]<0) comresults[i][j]+=1;  
                      
                    if(board[i+1][j-1]<0&&board[i+1][j]<0&&board[i+1][j+2]<0&&board[i+1][j+3]==pla&&board[i+1][j+4]<0) humresults[i][j]+=1;  
                    if(board[i-1][j-1]<0&&board[i-1][j]<0&&board[i+2][j+2]<0&&board[i+3][j+3]==pla&&board[i+4][j+4]<0) humresults[i][j]+=1;  
                    if(board[i-1][j+1]<0&&board[i][j+1]<0&&board[i+2][j+1]<0&&board[i+3][j+1]==pla&&board[i+4][j+1]<0) humresults[i][j]+=1;  
                    if(board[i][j+2]<0&&board[i-1][j+3]<0&&board[i+2][j]<0&&board[i+3][j-1]==pla&&board[i+4][j-2]<0) humresults[i][j]+=1;  
                    if(board[i+1][j+3]<0&&board[i+1][j+2]<0&&board[i+1][j]<0&&board[i+1][j-1]==pla&&board[i+1][j-2]<0) humresults[i][j]+=1;  
                    if(board[i+3][j+3]<0&&board[i+2][j+2]<0&&board[i][j]<0&&board[i-1][j-1]==pla&&board[i-2][j-2]<0) humresults[i][j]+=1;  
                    if(board[i+3][j+1]<0&&board[i+2][j+1]<0&&board[i][j+1]<0&&board[i-1][j+1]==pla&&board[i-2][j+1]<0) humresults[i][j]+=1;  
                    if(board[i+3][j-1]<0&&board[i+2][j]<0&&board[i][j+2]<0&&board[i-1][j+3]==pla&&board[i-2][j+4]<0) humresults[i][j]+=1;  
                      
                      
                    }  
}  
       
       


















void Gobang::default_board()//初始化棋盤15x15 
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
void Gobang::show_board()//顯示棋盤15x15 
{ 	
     for(int i=0 ;i<=16 ;i++){ 
           for(int j=0 ;j<=16 ;j++){ 
                 switch(board[i][j]){ 
                    case -1: 
                      cout << "└"; 
                      break; 
                    case -2: 
                      cout << "┴"; 
                      break; 
                    case -3: 
                      cout << "┘"; 
                      break; 
                    case -4: 
                      cout << "├"; 
                      break; 
                    case -5: 
                      cout << "┼"; 
                      break; 
                    case -6: 
                      cout << "┤"; 
                      break; 
                    case -7: 
                      cout << "┌"; 
                      break; 
                    case -8: 
                      cout << "┬"; 
                      break; 
                    case -9: 
                      cout << "┐"; 
                      break; 
                    case 0: 
                      cout << "　"; 
                      break; 
                    case 1: 
                      cout << "○"; 
                      break; 
                    case 2: 
                      cout << "●"; 
                      break; 
                    /*case 3: 
                      cout << "☆"; 
                      break; 
                    case 4: 
                      cout << "★"; 
                      break;*/ 
                    case 11: 
                      cout << "１"; 
                      break; 
                    case 12: 
                      cout << "２"; 
                      break; 
                    case 13: 
                      cout << "３"; 
                      break; 
                    case 14: 
                      cout << "４"; 
                      break; 
                    case 15: 
                      cout << "５"; 
                      break; 
                    case 16: 
                      cout << "６"; 
                      break; 
                    case 17: 
                      cout << "７"; 
                      break; 
                    case 18: 
                      cout << "８"; 
                      break; 
                    case 19: 
                      cout << "９"; 
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
                      cout << "Ａ"; 
                      break; 
                    case 32: 
                      cout << "Ｂ"; 
                      break; 
                    case 33: 
                      cout << "Ｃ"; 
                      break; 
                    case 34: 
                      cout << "Ｄ"; 
                      break; 
                    case 35: 
                      cout << "Ｅ"; 
                      break; 
                    case 36: 
                      cout << "Ｆ"; 
                      break; 
                    case 37: 
                      cout << "Ｇ"; 
                      break; 
                    case 38: 
                      cout << "Ｈ"; 
                      break; 
                    case 39: 
                      cout << "Ｉ"; 
                      break; 
                    case 40: 
                      cout << "Ｊ"; 
                      break; 
                    case 41: 
                      cout << "Ｋ"; 
                      break; 
                    case 42: 
                      cout << "Ｌ"; 
                      break; 
                    case 43: 
                      cout << "Ｍ"; 
                      break; 
                    case 44: 
                      cout << "Ｎ"; 
                      break; 
                    case 45: 
                      cout << "Ｏ"; 
                      break; 
                    
                 } 
           } 
           cout << endl; 
     } 
}
 
void Gobang::put_chess(short i,short j,short whosturn){//下棋+判斷有無棋子 
     if(i == 0 || i >= 16 || j == 0 || j >= 16){ 
        cout <<"下棋的範圍超出格子外！"<< endl; 
        endtry = 0; 
        system("pause"); 
     }else if(board[i][j] == 1 || board[i][j] == 2){ 
        cout <<"此位置已經有棋子了！"<< endl; 
        endtry = 0; 
        system("pause"); 
     }else{ 
        board[i][j] = whosturn; 
     } 
} 

bool Gobang::winner(short i,short j,short whosturn){//勝負 win = 1 勝利 
   short count,tempi,tempj; 
   bool win = 0; 
   //←→ 
   count = 1; 
   tempi = i; 
   while(board[--tempi][j] == whosturn){count++;} 
   tempi = i; 
   while(board[++tempi][j] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //↑↓ 
   count = 1; 
   tempj = j; 
   while(board[i][--tempj] == whosturn){count++;} 
   tempj = j; 
   while(board[i][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //↖↘ 
   count = 1; 
   tempi = i,tempj = j; 
   while(board[--tempi][--tempj] == whosturn){count++;} 
   tempi = i,tempj = j; 
   while(board[++tempi][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
   //↙↗ 
   count = 1; 
   tempi = i,tempj = j; 
   while(board[++tempi][--tempj] == whosturn){count++;} 
   tempi = i,tempj = j; 
   while(board[--tempi][++tempj] == whosturn){count++;} 
   if(count >= 5){win = 1; goto winner_check_end;} 
winner_check_end: 
   return win; 
} 
void Gobang::multiplayer(int pla){//, 白棋先下 
     string keyin; 
     short whosturn = pla,I,J; 
   //  system("cls"); 
   //  show_board(); 
nextstep: 
     I = 0; 
     J = 0; 
     endtry = 1; 
    system("cls"); 
     show_board(); 
     cout<<"換玩家下:\n";
    
     getline(cin,keyin); 
    
     for(int n=0 ;n<keyin.length() ;n++){//處理字串keyin 
        if(keyin[n]>='a' && keyin[n]<='o'){ 
           J = keyin[n] - 'a' + 1; 
        }else if(keyin[n]>='A' && keyin[n]<='O'){ 
           J = keyin[n] - 'A' + 1; 
        }else if(keyin[n]>='0' && keyin[n]<='9'){ 
           I = I*10 + keyin[n] - '0'; 
       
        }else if(keyin[n] == ' '){ 
           continue; 
        }else{ 
           cout <<"輸入了不合法的字元！"<< endl; 
           system("pause"); 
           goto nextstep; 
        } 
     } 
     put_chess(I,J,whosturn); 
     if(endtry == 0){goto nextstep;} 
      system("cls"); 
      show_board(); 
 /*    if(endtry == 0){goto nextstep;} 
     endtry = winner(I,J,whosturn); 
     whosturn = (whosturn == 1? 2:1); 
     if(endtry == 0){goto nextstep;} 
     else{ 
        whosturn = (whosturn == 1? 2:1); 
        system("cls"); 
        show_board(); 
        if(whosturn == 1){cout <<"黑棋贏了！"<< endl;}else{cout <<"白棋贏了！"<< endl;} 
     } 
     */ 
} 
