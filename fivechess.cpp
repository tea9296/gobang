
#include<iostream>  
#include<iomanip>  
#include<fstream>  
#include<cstring>  
  
using namespace std;  
  
class Gobang{  
        
      private:  
                
             int chessboard[15][15];          //棋?   
             int five[5][5];                  //5*5小棋?   
             int six[6][6];  
             int computernum,humannum;         //棋子?   
             int p1,p2;                       //棋子?   
             int last1,last2;                    //??上一步    
             int comresults[15][15];             //存?分?  
             int humresults[15][15];  
             int temp[15][15];             //??棋?   
             int max_com,max_hum,max_com_i,max_com_j,max_hum_i,max_hum_j;           //存???和玩家的最高分? 和相?的坐?   
             int total_com,total_hum;              //??和玩家分??分   
             int goback;                      //反回主菜?；   
     
        
      public:  
  
              Gobang();  
              void setchessboard(int ,int,int);     //改?棋子   
              void count();                         //??，棋子?   
              void count_total();                //?算?分   
              void save(int);                     //保存游?   
              int dir();                         //?示已保存的棋局   
              void firstgo();                  //??先走棋        
              void print(int n);              //?示棋?   
              void input(int n);              //?入   
              void getfive(int i,int j);             // ?取 ?据，存入5*5 的棋?中   
              void getsix(int,int);  
              int ifwin();                     //判?胜?        
              void think();  
              void getresults();          //打分下子   
              void r_four();  
              void r_three();             
              void r_two();  
              int returngoback();  
                
   
};  
                
  
  
Gobang::Gobang(){  
                 for(int i=0;i<15;i++)  
                         for(int j=0;j<15;j++){  
                                chessboard[i][j]=0;  
                                temp[i][j]=0;  
                                comresults[i][j]=0;  
                                humresults[i][j]=0;}  
                                  
                 for(int i=0;i<5;i++)  
                         for(int j=0;j<5;j++)  
                                {five[i][j]=0;}  
                 computernum=0;  
                 humannum=0;  
                 p1=0;p2=0;  
                 last1=-1;last2=-1;       //-1表示?未?始   
                 max_com=0;max_hum=0;max_com_i=0;  
                 max_com_j=0;max_hum_i=0;max_hum_j=0;  
                 total_com=0;total_hum=0;  
                 goback=0;  
}  
  
  
  
void Gobang::setchessboard(int i,int j,int n){  
     chessboard[i][j]=n;}  
       
       
void Gobang::count(){  
     computernum=0;  
     humannum=0;  
     for(int i=0;i<15;i++)  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]==1) computernum++;  
                 if(chessboard[i][j]==2) humannum++;  
                 p1=computernum;p2=humannum;  
                 }  
}  
               
  
  
//分??算??和玩家 得?得分   
   
void Gobang::count_total(){  
       
     total_com=0;total_hum=0;  
     for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    comresults[i][j]=0;  
                    humresults[i][j]=0;}                //每次先置零   
       
       
       //?始打分   
       r_four();  
       r_three();  
       r_two();  
         
       //分??算各自的?分   
       for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    total_com+=comresults[i][j];  
                    total_hum+=humresults[i][j];  
                    }  
                      
       //能?了，加1000  
         
       //判?是否可以下一?子就立即?或?,即成五   
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //找空位   
                  chessboard[i][j]=1;  
                  if(ifwin()==1) {total_com+=1000;}                  //???   
                  chessboard[i][j]=0;                      //?用的位置不下子   
                  }  
         }  
           
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //找空位   
                  chessboard[i][j]=2;  
                  if(ifwin()==2) {total_hum+=1000;}                  //玩家?   
                  chessboard[i][j]=0;                      //?用的位置不下子   
                  }  
         }   
         
}  
  
  
//保存游?  
  
void Gobang::save(int n){                                  //n=1表示人机??，n=2表示?人??  
          cout<<"?入文件名?（不含后?）："<<endl;  
          string filename;  
          cin>>filename;  
          filename=filename+".gbg";  
          ofstream ofile(filename.c_str());  
          ofile<<n<<endl;  
          for(int i=0;i<15;i++)  
              for(int j=0;j<15;j++){  
                      ofile<<chessboard[i][j]<<endl;  
                      }  
          ofile.close();  
          cout<<"棋局保存在 “"<<filename<<"”文件中"<<endl;  
}   
                        
  
//?示  
  
int Gobang::dir(){  
     system("dir/b>dir.txt");  
     ifstream ifile("dir.txt");  
     string filename;  
     int num=0;  
     while(ifile>>filename){  
              if(filename.find(".gbg")!=-1) {  
                                             cout<<filename<<endl;   
                                             num++;  
                                             }  
              }  
    cout<<"共?"<<num<<"?文件"<<endl;  
    return num;  
}   
  
  
int Gobang::returngoback(){  
    return goback;  
}         
            
       
//??先走   
  
void Gobang::firstgo(){  
     chessboard[8][8]=1;  
     last1=8,last2=8;  
     }  
                   
  
//屏幕?示   
                   
void Gobang::print(int n){  
     system("cls");  
     count();  
     count_total();  
     cout<<"****************五子棋****************"<<endl;  
     cout<<"                        axun. 2009.8.13"<<endl;  
     if(n==1){  
              cout<<"棋子??： - ?子 ， * ?? ，o 玩家。"<<endl;  
             cout<<"棋子?:  ??："<<setw(4)<<computernum<<" 玩家："<<setw(4)<<humannum<<endl;  
             cout<<"??分:  ??："<<setw(4)<<total_com<<" 玩家："<<setw(4)<<total_hum<<endl;   
             }  
     if(n==2) {  
              cout<<"棋子??： - ?子 ， * 玩家1 ，o 玩家2。"<<endl;  
             cout<<"棋子?:    玩家1："<<setw(4)<<p1<<" 玩家2："<<setw(4)<<p2<<endl;  
             cout<<"局??分:  玩家1："<<setw(4)<<total_com<<" 玩家2："<<setw(4)<<total_hum<<endl;  
             }  
     cout<<"行/列"<<endl;  
     cout<<"  ";  
     for(int i=0;i<15;i++){  
             cout<<setw(3)<<i;}  
     cout<<endl;  
     for(int i=0;i<15;i++)  
            {  
             cout<<setw(3)<<i;  
             for(int j=0;j<15;j++)  
                    {  
                     if(chessboard[i][j]==0) cout<<" - ";  
                     if(chessboard[i][j]==1) cout<<" X ";  
                     if(chessboard[i][j]==2) cout<<" O ";  
                     }  
             cout<<endl;  
             }  
     if(last1!=-1) {  
                   if(n==1) cout<<"pc下子位置： "<<last1<<"  "<<last2<<endl;  
                   if(n==2) cout<<"玩家下子位置： "<<last1<<"  "<<last2<<endl;  
                   }   
      else cout<<"上一步下子位置：?"<<endl;    
     cout<<"?入坐?下子: "<<endl;        
}  
                       
  
//?理?入?据  
   
void Gobang::input(int n){  
     if(n==1)  
     while(1){   
     int i,j;  
     cin>>i;  
     if(i==111) {cout<<"是否?此棋局保存？y/n"<<endl;  
                  char yn;cin>>yn;  
                  if(yn=='y'){  
                              save(1);   
                             cout<<"保存完?！??游?！"<<endl;   
                             }  
                  if(yn=='n') cout<<"未保存！??游?！"<<endl;  
                  cin>>i>>j;  
                  }  
     else if(i==222) {goback=1;return;}  
     else cin>>j;                
     if(!(i>=0&&i<15)) {  
                       cout<<"?入??!超出棋?范?！?重新?入"<<endl;  
                       continue;  
                       }  
     else if(!(j>=0&&j<15)) {  
                       cout<<"?入??!超出棋?范?！?重新?入"<<endl;  
                       continue;  
                       }  
     else if(chessboard[i][j]!=0){  
                             cout<<"?入??！ ?位置上已有棋子！?重新?入"<<endl;  
                             continue;  
                             }  
     else{chessboard[i][j]=2;  
         last1=i;last2=j;  
         humannum++;  
         break;  
         }   
       
     }  
     if(n==2){  
     while(1){  
              cout<<"玩家1下子:"<<endl;   
              int i,j;  
              cin>>i;  
               if(i==111) {cout<<"是否?此棋局保存？y/n"<<endl;  
                  char yn;cin>>yn;  
                  if(yn=='y') {  
                              save(2);  
                               cout<<"保存完?！??游?！"<<endl;   
                               }  
                  if(yn=='n') cout<<"未保存！??游?！"<<endl;  
                  cin>>i>>j;  
                  }  
              else if(i==222) {goback=1;return;}  
              else cin>>j;  
              if(!(i>=0&&i<15)) {  
                       cout<<"?入??!超出棋?范?！?重新?入"<<endl;  
                       continue;  
                       }  
              else if(!(j>=0&&j<15)) {  
                       cout<<"?入??!超出棋?范?！?重新?入"<<endl;  
                       continue;  
                       }  
              else if(chessboard[i][j]!=0){  
                             cout<<"?入??！ ?位置上已有棋子！?重新?入"<<endl;  
                             continue;  
                             }  
              else{chessboard[i][j]=1;  
                  p1++;  
                  last1=i;last2=j;  
                  break;  
                   }  
              }  
              print(2);  
      while(1){  
              cout<<"玩家2下子:"<<endl;   
              int i,j;  
              cin>>i>>j;  
              if(!(i>=0&&i<15)) {  
                       cout<<"錯物輸入!超出棋盤范為！請重新入"<<endl;  
                       continue;  
                       }  
              else if(!(j>=0&&j<15)) {  
                       cout<<"錯物輸入!超出棋盤范為！請重新書入"<<endl;  
                       continue;  
                       }  
              else if(chessboard[i][j]!=0){  
                             cout<<"錯誤輸入！ 該位置上已有棋子！請重新書入"<<endl;  
                             continue;  
                             }  
              else{chessboard[i][j]=2;  
                  p2++;  
                  last1=i;last2=j;  
                  break;  
                   }  
     }  
     }  
                
       
}   
       
       
        
  
void Gobang::getfive(int i,int j){  
     for(int m=0;m<5;m++)  
         for(int n=0;n<5;n++)  
                 five[m][n]=chessboard[m+i][n+j];  
}  
  
  
  
void Gobang::getsix(int i,int j){  
     for(int m=0;m<6;m++)  
         for(int n=0;n<6;n++)  
                 six[m][n]=chessboard[m+i][n+j];  
}  
                               
  
//判?是否有人?   
int Gobang::ifwin(){  
    for(int i=0;i<=10;i++)  
        for(int j=0;j<=10;j++){  
              getfive(i,j);  
              for(int m=0;m<5;m++){  
                      if(five[m][0]==1&&five[m][1]==1&&five[m][2]==1&&five[m][3]==1&&five[m][4]==1)  
                          return (1);  
                      if(five[0][m]==1&&five[1][m]==1&&five[2][m]==1&&five[3][m]==1&&five[4][m]==1)  
                          return (1);}  
              if(five[0][0]==1&&five[1][1]==1&&five[2][2]==1&&five[3][3]==1&&five[4][4]==1)  
                   return (1);  
              if(five[0][4]==1&&five[1][3]==1&&five[2][2]==1&&five[3][1]==1&&five[4][0]==1)  
                   return (1);  
              }  
                
    for(int i=0;i<=10;i++)  
        for(int j=0;j<=10;j++){  
              getfive(i,j);  
              for(int m=0;m<5;m++){  
                      if(five[m][0]==2&&five[m][1]==2&&five[m][2]==2&&five[m][3]==2&&five[m][4]==2)  
                          return 2;  
                      if(five[0][m]==2&&five[1][m]==2&&five[2][m]==2&&five[3][m]==2&&five[4][m]==2)  
                          return 2;}  
              if(five[0][0]==2&&five[1][1]==2&&five[2][2]==2&&five[3][3]==2&&five[4][4]==2)  
                   return 2;  
              if(five[0][4]==2&&five[1][3]==2&&five[2][2]==2&&five[3][1]==2&&five[4][0]==2)  
                   return 2;  
              }  
      
    return 0;  
}  
      
                        
//??思考   
void Gobang::think(){  
       
     total_com=0;total_hum=0;  
       
     //首先判?是否可以下一?子就立即?或?,即成五   
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //找空位   
                  chessboard[i][j]=1;  
                  if(ifwin()==1) {last1=i;last2=j;return;}                  //???   
                  chessboard[i][j]=0;                      //?用的位置不下子   
                  }  
         }  
           
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //找空位   
                  chessboard[i][j]=2;  
                  if(ifwin()==2) {chessboard[i][j]=1;last1=i;last2=j;return;}                  //阻止玩家?   
                  chessboard[i][j]=0;                      //?用的位置不下子   
                  }  
         }      
           
  
           
           
      //??走的第一步，跟子，避??界   
      if(computernum==0) {  
                         if(last1<=2&&chessboard[last1+1][last2]==0)   
                            {chessboard[last1+1][last2]=1;last1++;return; }  
                               else if(last1>=12&&chessboard[last1-1][last2]==0)   
                                     {chessboard[last1-1][last2]=1;last1--;return;}  
                                        else if(last2<=2&&chessboard[last1][last2+1]==0)   
                                            {chessboard[last1][last2+1]=1;last2++;return;}  
                                                else if(last2>=12&&chessboard[last1][last2-1]==0)   
                                                     {chessboard[last1][last2-1]=1;last2--;return;}   
                                                        else if(chessboard[last1+1][last2]==0)   
                                                           {chessboard[last1+1][last2]=1;last1++;return;}  
                                                                  else if(chessboard[last1-1][last2]==0)   
                                                                        {chessboard[last1-1][last2]=1;last1--;return;}  
                                                                          else if(chessboard[last1][last2+1]==0)   
                                                                                  {chessboard[last1][last2+1]=1;last2++;return;}  
                                                                                       else if(chessboard[last1][last2-1]==0)   
                                                                                                {chessboard[last1][last2-1]=1;last2--;return;}  
                         }  
       
                        
           
   //以上都不?足，?始打分  
   getresults();   
       
              
          
    
}     
  
  
  
void Gobang::getresults(){  
       
          for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    comresults[i][j]=0;  
                    humresults[i][j]=0;}                //每次先置零   
       max_com=0;max_hum=0;max_com_i=0;  
       max_com_j=0;max_hum_i=0;max_hum_j=0;  
         
         
       //?始打分   
       r_four();  
       r_three();  
       r_two();  
         
       //分?????和玩家的最高分，并保存其坐?   
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
                      
       //分析??最高分，?定攻?是防  
         
       if(max_com>=1000) {                                      //??能成四   
                       chessboard[max_com_i][max_com_j]=1;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=1000) {                                      //阻止玩家四   
                       chessboard[max_hum_i][max_hum_j]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
       if(max_com>=18) {                                      //??能成?三 （或更多）   
                       chessboard[max_com_i][max_com_j]=1;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=18) {                                      //阻止玩家?三 （或更多）   
                       chessboard[max_hum_i][max_hum_j]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
         
       if(max_com==17||max_com==16) {                                      //另一种不能取胜?三  
                       chessboard[max_com_i][max_com_j]=1;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum==17||max_hum==16) {                                        
                       chessboard[max_hum_i][max_hum_j]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
                         
                         
       if(max_com<16&&max_com>=10) {                                      //3,3+1 ,3+2，?4   
                       chessboard[max_com_i][max_com_j]=1;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum<16&&max_hum>=10) {                                        
                       chessboard[max_hum_i][max_hum_j]=1;   
                       last1=max_hum_i;last2=max_hum_j;         
                       return;  
                       }                                        
  
       //其他情?不管玩家，??走最好的  
       chessboard[max_com_i][max_com_j]=1;  
       last1=max_com_i;last2=max_com_j;   
       return;  
}   
  
  
//注： 尚存在的一?很大??是，在?分?程中的??越界，但是??果基本?有影?  
//可以加入????界的?查，太多了，以后再?   
  
void Gobang::r_four(){  
       
     for(int i=1;i<14;i++)  
         for(int j=1;j<14;j++){  
                   
                 if(chessboard[i][j]!=0) continue;  
                   
                   
                 //第一种情?    xooo@x  
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==1&&chessboard[i][j-4]==0) comresults[i][j]+=100;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==1&&chessboard[i-4][j-4]==0) comresults[i][j]+=100;   
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==1&&chessboard[i-4][j]==0) comresults[i][j]+=100;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==1&&chessboard[i-4][j+4]==0) comresults[i][j]+=100;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==1&&chessboard[i][j+4]==0) comresults[i][j]+=100;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==1&&chessboard[i+4][j+4]==0) comresults[i][j]+=100;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==1&&chessboard[i+4][j]==0) comresults[i][j]+=100;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==1&&chessboard[i+4][j-4]==0) comresults[i][j]+=100;  
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==2&&chessboard[i][j-4]==0) humresults[i][j]+=100;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==2&&chessboard[i-4][j-4]==0) humresults[i][j]+=100;   
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==2&&chessboard[i-4][j]==0) humresults[i][j]+=100;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==2&&chessboard[i-4][j+4]==0) humresults[i][j]+=100;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==2&&chessboard[i][j+4]==0) humresults[i][j]+=100;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==2&&chessboard[i+4][j+4]==0) humresults[i][j]+=100;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==2&&chessboard[i+4][j]==0) humresults[i][j]+=100;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==2&&chessboard[i+4][j-4]==0) humresults[i][j]+=100;  
                   
                   
                 //第二种情?   xoo@ox  
                   
                 if(chessboard[i][j+2]==0&&chessboard[i][j+1]==1&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) comresults[i][j]+=100;  
                 if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) comresults[i][j]+=100;   
                 if(chessboard[i+2][j]==0&&chessboard[i+1][j]==1&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) comresults[i][j]+=100;  
                 if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) comresults[i][j]+=100;  
                 if(chessboard[i][j-2]==0&&chessboard[i][j-1]==1&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) comresults[i][j]+=100;  
                 if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) comresults[i][j]+=100;  
                 if(chessboard[i-2][j]==0&&chessboard[i-1][j]==1&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) comresults[i][j]+=100;  
                 if(chessboard[i-2][j+2]==0&&chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) comresults[i][j]+=100;  
                   
                 if(chessboard[i][j+2]==0&&chessboard[i][j+1]==2&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==0) humresults[i][j]+=100;  
                 if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==0) humresults[i][j]+=100;   
                 if(chessboard[i+2][j]==0&&chessboard[i+1][j]==2&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==0) humresults[i][j]+=100;  
                 if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==0) humresults[i][j]+=100;  
                 if(chessboard[i][j-2]==0&&chessboard[i][j-1]==2&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==0) humresults[i][j]+=100;  
                 if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==0) humresults[i][j]+=100;  
                 if(chessboard[i-2][j]==0&&chessboard[i-1][j]==2&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==0) humresults[i][j]+=100;  
                 if(chessboard[i-2][j+2]==0&&chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==0) humresults[i][j]+=100;  
                   
                   
                   
                   
                   
                 //第三种情?     *ooo@x   
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==1&&chessboard[i][j-4]==2) comresults[i][j]+=11;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==1&&chessboard[i-4][j-4]==2) comresults[i][j]+=11;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==1&&chessboard[i-4][j]==2) comresults[i][j]+=11;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==1&&chessboard[i-4][j+4]==2) comresults[i][j]+=11;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==1&&chessboard[i][j+4]==2) comresults[i][j]+=11;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==1&&chessboard[i+1][j+2]==1&&chessboard[i+3][j+3]==1&&chessboard[i+4][j+4]==2) comresults[i][j]+=11;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==1&&chessboard[i+4][j]==2) comresults[i][j]+=11;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==1&&chessboard[i+4][j-4]==2) comresults[i][j]+=11;  
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==2&&chessboard[i][j-4]==1) humresults[i][j]+=11;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==2&&chessboard[i-4][j-4]==1) humresults[i][j]+=11;  
                 if(chessboard[i+1][j]==0&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==2&&chessboard[i-4][j]==1) humresults[i][j]+=11;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==2&&chessboard[i-4][j+4]==1) humresults[i][j]+=11;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==2&&chessboard[i][j+4]==1) humresults[i][j]+=11;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==2&&chessboard[i+1][j+2]==2&&chessboard[i+3][j+3]==2&&chessboard[i+4][j+4]==1) humresults[i][j]+=11;  
                 if(chessboard[i-1][j]==0&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==2&&chessboard[i+4][j]==1) humresults[i][j]+=11;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==2&&chessboard[i+4][j-4]==1) humresults[i][j]+=11;  
                   
                 //第四种情?   *oo@ox  
                   
                 if(chessboard[i][j+2]==0&&chessboard[i][j+1]==1&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==2) comresults[i][j]+=11;  
                 if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==2) comresults[i][j]+=11;   
                 if(chessboard[i+2][j]==0&&chessboard[i+1][j]==1&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==2) comresults[i][j]+=11;  
                 if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==2) comresults[i][j]+=11;  
                 if(chessboard[i][j-2]==0&&chessboard[i][j-1]==1&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==2) comresults[i][j]+=11;  
                 if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==2) comresults[i][j]+=11;  
                 if(chessboard[i-2][j]==0&&chessboard[i-1][j]==1&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==2) comresults[i][j]+=11;  
                 if(chessboard[i-2][j+2]==0&&chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==2) comresults[i][j]+=11;  
                   
                 if(chessboard[i][j+2]==0&&chessboard[i][j+1]==2&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==1) humresults[i][j]+=11;  
                 if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==1) humresults[i][j]+=11;   
                 if(chessboard[i+2][j]==0&&chessboard[i+1][j]==2&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==1) humresults[i][j]+=11;  
                 if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==1) humresults[i][j]+=11;  
                 if(chessboard[i][j-2]==0&&chessboard[i][j-1]==2&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==1) humresults[i][j]+=11;  
                 if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==1) humresults[i][j]+=11;  
                 if(chessboard[i-2][j]==0&&chessboard[i-1][j]==2&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==1) humresults[i][j]+=11;  
                 if(chessboard[i-2][j+2]==0&&chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==1) humresults[i][j]+=11;  
                   
                 //第五种情?   *o@oox  
                   
                 if(chessboard[i][j+2]==2&&chessboard[i][j+1]==1&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) comresults[i][j]+=11;  
                 if(chessboard[i+2][j+2]==2&&chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) comresults[i][j]+=11;   
                 if(chessboard[i+2][j]==2&&chessboard[i+1][j]==1&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) comresults[i][j]+=11;  
                 if(chessboard[i+2][j-2]==2&&chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) comresults[i][j]+=11;  
                 if(chessboard[i][j-2]==2&&chessboard[i][j-1]==1&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) comresults[i][j]+=11;  
                 if(chessboard[i-2][j-2]==2&&chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) comresults[i][j]+=11;  
                 if(chessboard[i-2][j]==2&&chessboard[i-1][j]==1&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) comresults[i][j]+=11;  
                 if(chessboard[i-2][j+2]==2&&chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) comresults[i][j]+=11;  
                   
                 if(chessboard[i][j+2]==1&&chessboard[i][j+1]==2&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==0) humresults[i][j]+=11;  
                 if(chessboard[i+2][j+2]==1&&chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==0) humresults[i][j]+=11;   
                 if(chessboard[i+2][j]==1&&chessboard[i+1][j]==2&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==0) humresults[i][j]+=11;  
                 if(chessboard[i+2][j-2]==1&&chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==0) humresults[i][j]+=11;  
                 if(chessboard[i][j-2]==1&&chessboard[i][j-1]==2&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==0) humresults[i][j]+=11;  
                 if(chessboard[i-2][j-2]==1&&chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==0) humresults[i][j]+=11;  
                 if(chessboard[i-2][j]==1&&chessboard[i-1][j]==2&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==0) humresults[i][j]+=11;  
                 if(chessboard[i-2][j+2]==1&&chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==0) humresults[i][j]+=11;  
                   
                 //第六种情?  *@ooox  
                   
                 if(chessboard[i][j+1]==2&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==1&&chessboard[i][j-4]==0) comresults[i][j]+=11;  
                 if(chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==1&&chessboard[i-4][j-4]==0) comresults[i][j]+=11;  
                 if(chessboard[i+1][j]==2&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==1&&chessboard[i-4][j]==0) comresults[i][j]+=11;  
                 if(chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==1&&chessboard[i-4][j+4]==0) comresults[i][j]+=11;  
                 if(chessboard[i][j-1]==2&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==1&&chessboard[i][j+4]==0) comresults[i][j]+=11;  
                 if(chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==1&&chessboard[i+1][j+2]==1&&chessboard[i+3][j+3]==1&&chessboard[i+4][j+4]==0) comresults[i][j]+=11;  
                 if(chessboard[i-1][j]==2&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==1&&chessboard[i+4][j]==0) comresults[i][j]+=11;  
                 if(chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==1&&chessboard[i+4][j-4]==0) comresults[i][j]+=11;  
                   
                 if(chessboard[i][j+1]==1&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==2&&chessboard[i][j-4]==0) humresults[i][j]+=11;  
                 if(chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==2&&chessboard[i-4][j-4]==0) humresults[i][j]+=11;  
                 if(chessboard[i+1][j]==1&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==2&&chessboard[i-4][j]==0) humresults[i][j]+=11;  
                 if(chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==2&&chessboard[i-4][j+4]==0) humresults[i][j]+=11;  
                 if(chessboard[i][j-1]==1&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==2&&chessboard[i][j+4]==0) humresults[i][j]+=11;  
                 if(chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==2&&chessboard[i+1][j+2]==2&&chessboard[i+3][j+3]==2&&chessboard[i+4][j+4]==0) humresults[i][j]+=11;  
                 if(chessboard[i-1][j]==1&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==2&&chessboard[i+4][j]==0) humresults[i][j]+=11;  
                 if(chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==2&&chessboard[i+4][j-4]==0) humresults[i][j]+=11;    
                   
                 //第七种情?   @xooo*    
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==1&&chessboard[i][j+4]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==1&&chessboard[i+4][j+4]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==1&&chessboard[i+4][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==1&&chessboard[i+4][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==1&&chessboard[i][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==1&&chessboard[i-4][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==1&&chessboard[i-4][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==1&&chessboard[i-4][j+4]==1) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j+1]==0&&chessboard[i][j+2]==2&&chessboard[i][j+3]==2&&chessboard[i][j+4]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==2&&chessboard[i+3][j+3]==2&&chessboard[i+4][j+4]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j]==0&&chessboard[i+2][j]==2&&chessboard[i+3][j]==2&&chessboard[i+4][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==2&&chessboard[i+4][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i][j-1]==0&&chessboard[i][j-2]==2&&chessboard[i][j-3]==2&&chessboard[i][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==2&&chessboard[i-4][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j]==0&&chessboard[i-2][j]==2&&chessboard[i-3][j]==2&&chessboard[i-4][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==2&&chessboard[i-4][j+4]==2) humresults[i][j]+=9;  
                   
                 //第八种情?  ox@oo*     *是?了不和活三重复加分   
                   
                 if(chessboard[i][j+3]==2&&chessboard[i][j+2]==1&&chessboard[i][j+1]==1&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1) comresults[i][j]+=9;  
                 if(chessboard[i+3][j+3]==2&&chessboard[i+2][j+2]==1&&chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1) comresults[i][j]+=9;   
                 if(chessboard[i+3][j]==2&&chessboard[i+2][j]==1&&chessboard[i+1][j]==1&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i+3][j-3]==2&&chessboard[i+2][j-2]==1&&chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1) comresults[i][j]+=9;  
                 if(chessboard[i][j-3]==2&&chessboard[i][j-2]==1&&chessboard[i][j-1]==1&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1) comresults[i][j]+=9;  
                 if(chessboard[i-3][j-3]==2&&chessboard[i-2][j-2]==1&&chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==12) comresults[i][j]+=9;  
                 if(chessboard[i-3][j]==2&&chessboard[i-2][j]==1&&chessboard[i-1][j]==1&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i-3][j+3]==2&&chessboard[i-2][j+2]==1&&chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j+3]==1&&chessboard[i][j+2]==2&&chessboard[i][j+1]==2&&chessboard[i][j-1]==0&&chessboard[i][j-2]==2) humresults[i][j]+=9;  
                 if(chessboard[i+3][j+3]==1&&chessboard[i+2][j+2]==2&&chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==2) humresults[i][j]+=9;   
                 if(chessboard[i+3][j]==1&&chessboard[i+2][j]==2&&chessboard[i+1][j]==2&&chessboard[i-1][j]==0&&chessboard[i-2][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i+3][j-3]==1&&chessboard[i+2][j-2]==2&&chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==2) humresults[i][j]+=9;  
                 if(chessboard[i][j-3]==1&&chessboard[i][j-2]==2&&chessboard[i][j-1]==2&&chessboard[i][j+1]==0&&chessboard[i][j+2]==2) humresults[i][j]+=9;  
                 if(chessboard[i-3][j-3]==1&&chessboard[i-2][j-2]==2&&chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==2) humresults[i][j]+=9;  
                 if(chessboard[i-3][j]==1&&chessboard[i-2][j]==2&&chessboard[i-1][j]==2&&chessboard[i+1][j]==0&&chessboard[i+2][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i-3][j+3]==1&&chessboard[i-2][j+2]==2&&chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==2) humresults[i][j]+=9;   
                   
                 //第九种情?   oxo@o*  
                   
                 if(chessboard[i][j+2]==2&&chessboard[i][j+1]==1&&chessboard[i][j-1]==1&&chessboard[i][j-2]==0&&chessboard[i][j-3]==1) comresults[i][j]+=9;  
                 if(chessboard[i+2][j+2]==2&&chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==1) comresults[i][j]+=9;  
                 if(chessboard[i+2][j]==2&&chessboard[i+1][j]==1&&chessboard[i-1][j]==1&&chessboard[i-2][j]==0&&chessboard[i-3][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i+2][j-2]==2&&chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==1) comresults[i][j]+=9;  
                 if(chessboard[i][j-2]==2&&chessboard[i][j-1]==1&&chessboard[i][j+1]==1&&chessboard[i][j+2]==0&&chessboard[i][j+3]==1) comresults[i][j]+=9;  
                 if(chessboard[i-2][j-2]==2&&chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==1) comresults[i][j]+=9;  
                 if(chessboard[i-2][j]==2&&chessboard[i-1][j]==1&&chessboard[i+1][j]==1&&chessboard[i+2][j]==0&&chessboard[i+3][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i-2][j+2]==2&&chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==1) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j+2]==2&&chessboard[i][j+1]==2&&chessboard[i][j-1]==2&&chessboard[i][j-2]==0&&chessboard[i][j-3]==2) humresults[i][j]+=9;  
                 if(chessboard[i+2][j+2]==2&&chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==2) humresults[i][j]+=9;  
                 if(chessboard[i+2][j]==2&&chessboard[i+1][j]==2&&chessboard[i-1][j]==2&&chessboard[i-2][j]==0&&chessboard[i-3][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i+2][j-2]==2&&chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==2) humresults[i][j]+=9;  
                 if(chessboard[i][j-2]==2&&chessboard[i][j-1]==2&&chessboard[i][j+1]==2&&chessboard[i][j+2]==0&&chessboard[i][j+3]==2) humresults[i][j]+=9;  
                 if(chessboard[i-2][j-2]==2&&chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==2) humresults[i][j]+=9;  
                 if(chessboard[i-2][j]==2&&chessboard[i-1][j]==2&&chessboard[i+1][j]==2&&chessboard[i+2][j]==0&&chessboard[i+3][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i-2][j+2]==2&&chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==2) humresults[i][j]+=9;   
                   
                 //第十种情?   oxoo@*   
                   
                 if(chessboard[i][j+1]==2&&chessboard[i][j-1]==1&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0&&chessboard[i][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0&&chessboard[i-4][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j]==2&&chessboard[i-1][j]==1&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0&&chessboard[i-4][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0&&chessboard[i-4][j+4]==1) comresults[i][j]+=9;  
                 if(chessboard[i][j-1]==2&&chessboard[i][j+1]==1&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0&&chessboard[i][j+4]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==1&&chessboard[i+1][j+2]==1&&chessboard[i+3][j+3]==0&&chessboard[i+4][j+4]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j]==2&&chessboard[i+1][j]==1&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0&&chessboard[i+4][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0&&chessboard[i+4][j-4]==1) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j+1]==1&&chessboard[i][j-1]==2&&chessboard[i][j-2]==2&&chessboard[i][j-3]==0&&chessboard[i][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==2&&chessboard[i-3][j-3]==0&&chessboard[i-4][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j]==1&&chessboard[i-1][j]==2&&chessboard[i-2][j]==2&&chessboard[i-3][j]==0&&chessboard[i-4][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==2&&chessboard[i-3][j+3]==0&&chessboard[i-4][j+4]==2) humresults[i][j]+=9;  
                 if(chessboard[i][j-1]==1&&chessboard[i][j+1]==2&&chessboard[i][j+2]==2&&chessboard[i][j+3]==0&&chessboard[i][j+4]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==2&&chessboard[i+1][j+2]==2&&chessboard[i+3][j+3]==0&&chessboard[i+4][j+4]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j]==1&&chessboard[i+1][j]==2&&chessboard[i+2][j]==2&&chessboard[i+3][j]==0&&chessboard[i+4][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==2&&chessboard[i+3][j-3]==0&&chessboard[i+4][j-4]==2) humresults[i][j]+=9;   
                   
                 //第十一种情?   @oxoo  
                   
                 if(chessboard[i][j+1]==1&&chessboard[i][j+2]==0&&chessboard[i][j+3]==1&&chessboard[i][j+4]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==1&&chessboard[i+4][j+4]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j]==1&&chessboard[i+2][j]==0&&chessboard[i+3][j]==1&&chessboard[i+4][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==1&&chessboard[i+4][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i][j-1]==1&&chessboard[i][j-2]==0&&chessboard[i][j-3]==1&&chessboard[i][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==1&&chessboard[i-4][j-4]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j]==1&&chessboard[i-2][j]==0&&chessboard[i-3][j]==1&&chessboard[i-4][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==1&&chessboard[i-4][j+4]==1) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j+1]==2&&chessboard[i][j+2]==0&&chessboard[i][j+3]==2&&chessboard[i][j+4]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==2&&chessboard[i+4][j+4]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j]==2&&chessboard[i+2][j]==0&&chessboard[i+3][j]==2&&chessboard[i+4][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==2&&chessboard[i+4][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i][j-1]==2&&chessboard[i][j-2]==0&&chessboard[i][j-3]==2&&chessboard[i][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==2&&chessboard[i-4][j-4]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j]==2&&chessboard[i-2][j]==0&&chessboard[i-3][j]==2&&chessboard[i-4][j]==2) humresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==2&&chessboard[i-4][j+4]==2) humresults[i][j]+=9;  
                   
                 //第十二种情?   o@xoo   
                   
                 if(chessboard[i][j-1]==1&&chessboard[i][j+1]==0&&chessboard[i][j+2]==0&&chessboard[i][j+3]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==1&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j]==1&&chessboard[i+1][j]==0&&chessboard[i+2][j]==0&&chessboard[i+3][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==1) comresults[i][j]+=9;  
                 if(chessboard[i][j+1]==1&&chessboard[i][j-1]==0&&chessboard[i][j-2]==0&&chessboard[i][j-3]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j]==1&&chessboard[i-1][j]==0&&chessboard[i-2][j]==0&&chessboard[i-3][j]==1) comresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==1&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==1) comresults[i][j]+=9;  
                   
                 if(chessboard[i][j-1]==2&&chessboard[i][j+1]==0&&chessboard[i][j+2]==0&&chessboard[i][j+3]==1) humresults[i][j]+=9;  
                 if(chessboard[i-1][j-1]==2&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==1) humresults[i][j]+=9;  
                 if(chessboard[i-1][j]==2&&chessboard[i+1][j]==0&&chessboard[i+2][j]==0&&chessboard[i+3][j]==1) humresults[i][j]+=9;  
                 if(chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==1) humresults[i][j]+=9;  
                 if(chessboard[i][j+1]==2&&chessboard[i][j-1]==0&&chessboard[i][j-2]==0&&chessboard[i][j-3]==1) humresults[i][j]+=9;  
                 if(chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==1) humresults[i][j]+=9;  
                 if(chessboard[i+1][j]==2&&chessboard[i-1][j]==0&&chessboard[i-2][j]==0&&chessboard[i-3][j]==1) humresults[i][j]+=9;  
                 if(chessboard[i+1][j-1]==2&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==1) humresults[i][j]+=9;  
                   
  
     }   
}  
       
       
void Gobang::r_three(){  
      
     for(int i=1;i<14;i++)  
         for(int j=1;j<14;j++){  
                   
                 if(chessboard[i][j]!=0) continue;  
                   
                 //第一种情?    x@oox  
                   
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
                   
                   
                 //第二种情?   xo@ox  
                 if(chessboard[i][j+1]==1&&chessboard[i][j-1]==1&&chessboard[i][j-2]==0&&chessboard[i][j+2]==0) comresults[i][j]+=10;   
                 if(chessboard[i-1][j]==1&&chessboard[i+1][j]==1&&chessboard[i-2][j]==0&&chessboard[i+2][j]==0) comresults[i][j]+=10;  
                 if(chessboard[i+1][j+1]==1&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==0&&chessboard[i+2][j+2]==0) comresults[i][j]+=10;  
                 if(chessboard[i-1][j+1]==1&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==0&&chessboard[i+2][j-2]==0) comresults[i][j]+=10;  
                   
                 if(chessboard[i][j+1]==2&&chessboard[i][j-1]==2&&chessboard[i][j-2]==0&&chessboard[i][j+2]==0) humresults[i][j]+=10;   
                 if(chessboard[i-1][j]==2&&chessboard[i+1][j]==2&&chessboard[i-2][j]==0&&chessboard[i+2][j]==0) humresults[i][j]+=10;  
                 if(chessboard[i+1][j+1]==2&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==0&&chessboard[i+2][j+2]==0) humresults[i][j]+=10;  
                 if(chessboard[i-1][j+1]==2&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==0&&chessboard[i+2][j-2]==0) humresults[i][j]+=10;  
                   
                 //第三种情?  x@xoox   
                   
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
                   
                 //第四种情?    xox@ox  
                   
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
                   
                 //第五种情?     xoxo@x  
                   
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
                   
                 //第六种情?    x@xoxox  
                   
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
                   
                 //第八种情?   xox@xox  
                   
                 //??似乎不必?，先放?            
                   
                 }       
                   
}  
  
  
  
void Gobang::r_two(){  
         
       
     for(int i=1;i<14;i++)  
            for(int j=1;j<14;j++){  
                      
                    if(chessboard[i][j]!=0) continue;  
                      
                    //第一种情?  xx@oxx  
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==1&&chessboard[i][j+2]==0&&chessboard[i][j+3]==0) comresults[i][j]+=2;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==1&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==0) comresults[i][j]+=2;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==1&&chessboard[i+2][j]==0&&chessboard[i+3][j]==0) comresults[i][j]+=2;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==1&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==0) comresults[i][j]+=2;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==1&&chessboard[i][j-2]==0&&chessboard[i][j-3]==0) comresults[i][j]+=2;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==1&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==0) comresults[i][j]+=2;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==1&&chessboard[i-2][j]==0&&chessboard[i-3][j]==0) comresults[i][j]+=2;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==1&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==0) comresults[i][j]+=2;  
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==2&&chessboard[i][j+2]==0&&chessboard[i][j+3]==0) humresults[i][j]+=2;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==2&&chessboard[i+2][j+2]==0&&chessboard[i+3][j+3]==0) humresults[i][j]+=2;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==2&&chessboard[i+2][j]==0&&chessboard[i+3][j]==0) humresults[i][j]+=2;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==2&&chessboard[i+2][j-2]==0&&chessboard[i+3][j-3]==0) humresults[i][j]+=2;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==2&&chessboard[i][j-2]==0&&chessboard[i][j-3]==0) humresults[i][j]+=2;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==2&&chessboard[i-2][j-2]==0&&chessboard[i-3][j-3]==0) humresults[i][j]+=2;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==2&&chessboard[i-2][j]==0&&chessboard[i-3][j]==0) humresults[i][j]+=2;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==2&&chessboard[i-2][j+2]==0&&chessboard[i-3][j+3]==0) humresults[i][j]+=2;   
                      
                    //第二种情?   xx@xox   
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) comresults[i][j]+=1;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) comresults[i][j]+=1;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) comresults[i][j]+=1;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) comresults[i][j]+=1;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) comresults[i][j]+=1;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) comresults[i][j]+=1;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) comresults[i][j]+=1;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) comresults[i][j]+=1;  
                      
                    if(chessboard[i][j-2]==0&&chessboard[i][j-1]==0&&chessboard[i][j+1]==0&&chessboard[i][j+2]==1&&chessboard[i][j+3]==0) humresults[i][j]+=1;  
                    if(chessboard[i-2][j-2]==0&&chessboard[i-1][j-1]==0&&chessboard[i+1][j+1]==0&&chessboard[i+2][j+2]==1&&chessboard[i+3][j+3]==0) humresults[i][j]+=1;  
                    if(chessboard[i-2][j]==0&&chessboard[i-1][j]==0&&chessboard[i+1][j]==0&&chessboard[i+2][j]==1&&chessboard[i+3][j]==0) humresults[i][j]+=1;  
                    if(chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==0&&chessboard[i+1][j-1]==0&&chessboard[i+2][j-2]==1&&chessboard[i+3][j-3]==0) humresults[i][j]+=1;  
                    if(chessboard[i][j+2]==0&&chessboard[i][j+1]==0&&chessboard[i][j-1]==0&&chessboard[i][j-2]==1&&chessboard[i][j-3]==0) humresults[i][j]+=1;  
                    if(chessboard[i+2][j+2]==0&&chessboard[i+1][j+1]==0&&chessboard[i-1][j-1]==0&&chessboard[i-2][j-2]==1&&chessboard[i-3][j-3]==0) humresults[i][j]+=1;  
                    if(chessboard[i+2][j]==0&&chessboard[i+1][j]==0&&chessboard[i-1][j]==0&&chessboard[i-2][j]==1&&chessboard[i-3][j]==0) humresults[i][j]+=1;  
                    if(chessboard[i+2][j-2]==0&&chessboard[i+1][j-1]==0&&chessboard[i-1][j+1]==0&&chessboard[i-2][j+2]==1&&chessboard[i-3][j+3]==0) humresults[i][j]+=1;  
                      
                      
                    }  
}  
       
       
  
  
//?始游?   
                  
  
void go(int n){  
     Gobang g;  
     if(n==1)  
     {  
             cout<<"誰先走棋："<<endl;  
             cout<<"     1.玩家先"<<endl;  
             cout<<"     2.pc先"<<endl;  
             int n;cin>>n;  
             if(n==2)  g.firstgo();  
     while(1){  
              if(g.ifwin()==1) {  
                                g.print(1);  
                                cout<<"pc勝！"<<endl;   
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"玩家勝！"<<endl;  
                              break;  
                              }   
              g.print(1);  
              g.input(1);  
              if(g.returngoback()==1) {cout<<"over了！"<<endl;return;}  
              if(g.ifwin()==1) {  
                                g.print(1);  
                              cout<<"pc勝！"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"玩家勝！"<<endl;  
                              break;  
                              }   
              g.think();  
              }  
     }  
     if(n==2){  
              while(1){  
              if(g.ifwin()==1) {  
                                g.print(2);  
                              cout<<"玩家1勝！"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(2);  
                              cout<<"玩家2勝！"<<endl;  
                              break;  
                              }  
              g.print(2);  
              g.input(2);  
              if(g.returngoback()==1) {cout<<"over了！"<<endl;return;}  
              }  
              }   
                
                
}  
  
  
//??存?   
  
void load(){  
     Gobang g;  
     cout<<"已有的存此文件如下："<<endl;  
     if(g.dir()==0) {cout<<"已有存此文件，無法存取!"<<endl;return;}  
     cout<<"?入文件名（不?后?）:"<<endl;  
     string filename;  
     cin>>filename;  
     filename=filename+".gbg";  
     ifstream ifile(filename.c_str());   
     int choice;  
     ifile>>choice;  
     if(choice!=1&&choice!=2) {  
                              cout<<"文件不容！" <<endl;  
                              return;  
                              }  
     for(int i=0;i<15;i++)  
         for(int j=0;j<15;j++)  
                {int n;  
                  ifile>>n;  
                  if(n!=1&&n!=2&&n!=0) {  
                                       cout<<"文件不容！"<<endl;  
                                       return;  
                                       }   
                  g.setchessboard(i,j,n);  
                  }  
                   ifile.close();  
       
     if(choice==1) {  
             while(1){  
                   if(g.ifwin()==1) {  
                                g.print(1);  
                              cout<<"pc勝！"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"玩家勝！"<<endl;  
                              break;  
                              }   
              g.print(1);  
              g.input(1);  
              if(g.returngoback()==1) {cout<<"??了！"<<endl;return;}  
              if(g.ifwin()==1) {  
                                g.print(1);  
                              cout<<"pc勝！"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"玩家勝！"<<endl;  
                              break;  
                              }   
              g.think();  
              }  
              }  
     if(choice==2){  
                while(1){  
              if(g.ifwin()==1) {  
                                g.print(2);  
                              cout<<"玩家1勝！"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(2);  
                              cout<<"玩家2勝！"<<endl;  
                              break;  
                              }  
              g.print(2);  
              g.input(2);  
              if(g.returngoback()==1) {cout<<"over了！"<<endl;return;}  
                
              }  
              }   
  
}    
                     
  
  
void explain(){  
     cout<<"****************?明****************"<<endl;  
       
     cout<<"界面?明："<<endl;  
     cout<<"   棋子??，?示棋?上的符?所??的棋子"<<endl;  
     cout<<"   棋子?，?示?方的棋子?? "<<endl;  
     cout<<"   棋?大小?15*15，行列坐?分??1至14，坐?一?注在棋??上。"<<endl;  
     cout<<"   棋?下面?示上一步的下子坐?位置。"<<endl;  
       
     cout<<"操作?明："<<endl;   
     cout<<"   ?入坐?下子，分??入行列坐?。可以用空格隔?，也可以用回?，不能有其他符?。"<<endl;   
     cout<<"   在游?中?入111可??保存游?（?人??中只能由先手保存）。"<<endl;  
     cout<<"   ?入222??！"<<endl;  
       
     cout<<"文件?明："<<endl;   
     cout<<"   五子棋.exe   主程序文件 "<<endl;   
     cout<<"   *.gbg    存?文件"<<endl;  
     cout<<"   dir.txt   保存信息  "<<endl;   
     }   
       
       
       
//主函?   
  
int main(){  
    while(1){  
             system("cls");  
             cout<<"****************五子棋****************"<<endl;  
             cout<<"                         axun. 2009.8.13"<<endl;  
             cout<<"?入?字??："<<endl;  
             cout<<"             1.人機遊戲。"<<endl;  
             cout<<"             2.雙人遊戲。"<<endl;  
             cout<<"             3.讀取存黨。"<<endl;  
             cout<<"             4.說明"<<endl;   
             cout<<"             0.退出游戲。"<<endl;  
             int s;  
             cin>>s;  
             if(s==1) go(1);  
             if(s==2) go(2);  
             if(s==3) load();  
             if(s==4) explain();  
             if(s==0) exit(0);  
             cout<<"返回主菜單？  y：是  。n：退出游戲 "<<endl;  
             char yn;  
             cin>>yn;  
             if(yn=='n') break;   
            }  
}  
