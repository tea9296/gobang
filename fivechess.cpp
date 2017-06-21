
#include<iostream>  
#include<iomanip>  
#include<fstream>  
#include<cstring>  
  
using namespace std;  
  
class Gobang{  
        
      private:  
                
             int chessboard[15][15];          //��?   
             int five[5][5];                  //5*5�p��?   
             int six[6][6];  
             int computernum,humannum;         //�Ѥl?   
             int p1,p2;                       //�Ѥl?   
             int last1,last2;                    //??�W�@�B    
             int comresults[15][15];             //�s?��?  
             int humresults[15][15];  
             int temp[15][15];             //??��?   
             int max_com,max_hum,max_com_i,max_com_j,max_hum_i,max_hum_j;           //�s???�M���a���̰���? �M��?����?   
             int total_com,total_hum;              //??�M���a��??��   
             int goback;                      //�Ϧ^�D��?�F   
     
        
      public:  
  
              Gobang();  
              void setchessboard(int ,int,int);     //��?�Ѥl   
              void count();                         //??�A�Ѥl?   
              void count_total();                //?��?��   
              void save(int);                     //�O�s��?   
              int dir();                         //?�ܤw�O�s���ѧ�   
              void firstgo();                  //??������        
              void print(int n);              //?�ܴ�?   
              void input(int n);              //?�J   
              void getfive(int i,int j);             // ?�� ?�u�A�s�J5*5 ����?��   
              void getsix(int,int);  
              int ifwin();                     //�P?�`?        
              void think();  
              void getresults();          //�����U�l   
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
                 last1=-1;last2=-1;       //-1���?��?�l   
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
               
  
  
//��??��??�M���a �o?�o��   
   
void Gobang::count_total(){  
       
     total_com=0;total_hum=0;  
     for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    comresults[i][j]=0;  
                    humresults[i][j]=0;}                //�C�����m�s   
       
       
       //?�l����   
       r_four();  
       r_three();  
       r_two();  
         
       //��??��U�۪�?��   
       for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    total_com+=comresults[i][j];  
                    total_hum+=humresults[i][j];  
                    }  
                      
       //��?�F�A�[1000  
         
       //�P?�O�_�i�H�U�@?�l�N�ߧY?��?,�Y����   
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //��Ŧ�   
                  chessboard[i][j]=1;  
                  if(ifwin()==1) {total_com+=1000;}                  //???   
                  chessboard[i][j]=0;                      //?�Ϊ���m���U�l   
                  }  
         }  
           
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //��Ŧ�   
                  chessboard[i][j]=2;  
                  if(ifwin()==2) {total_hum+=1000;}                  //���a?   
                  chessboard[i][j]=0;                      //?�Ϊ���m���U�l   
                  }  
         }   
         
}  
  
  
//�O�s��?  
  
void Gobang::save(int n){                                  //n=1��ܤH��??�An=2���?�H??  
          cout<<"?�J���W?�]���t�Z?�^�G"<<endl;  
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
          cout<<"�ѧ��O�s�b ��"<<filename<<"�����"<<endl;  
}   
                        
  
//?��  
  
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
    cout<<"�@?"<<num<<"?���"<<endl;  
    return num;  
}   
  
  
int Gobang::returngoback(){  
    return goback;  
}         
            
       
//??����   
  
void Gobang::firstgo(){  
     chessboard[8][8]=1;  
     last1=8,last2=8;  
     }  
                   
  
//�̹�?��   
                   
void Gobang::print(int n){  
     system("cls");  
     count();  
     count_total();  
     cout<<"****************���l��****************"<<endl;  
     cout<<"                        axun. 2009.8.13"<<endl;  
     if(n==1){  
              cout<<"�Ѥl??�G - ?�l �A * ?? �Ao ���a�C"<<endl;  
             cout<<"�Ѥl?:  ??�G"<<setw(4)<<computernum<<" ���a�G"<<setw(4)<<humannum<<endl;  
             cout<<"??��:  ??�G"<<setw(4)<<total_com<<" ���a�G"<<setw(4)<<total_hum<<endl;   
             }  
     if(n==2) {  
              cout<<"�Ѥl??�G - ?�l �A * ���a1 �Ao ���a2�C"<<endl;  
             cout<<"�Ѥl?:    ���a1�G"<<setw(4)<<p1<<" ���a2�G"<<setw(4)<<p2<<endl;  
             cout<<"��??��:  ���a1�G"<<setw(4)<<total_com<<" ���a2�G"<<setw(4)<<total_hum<<endl;  
             }  
     cout<<"��/�C"<<endl;  
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
                   if(n==1) cout<<"pc�U�l��m�G "<<last1<<"  "<<last2<<endl;  
                   if(n==2) cout<<"���a�U�l��m�G "<<last1<<"  "<<last2<<endl;  
                   }   
      else cout<<"�W�@�B�U�l��m�G?"<<endl;    
     cout<<"?�J��?�U�l: "<<endl;        
}  
                       
  
//?�z?�J?�u  
   
void Gobang::input(int n){  
     if(n==1)  
     while(1){   
     int i,j;  
     cin>>i;  
     if(i==111) {cout<<"�O�_?���ѧ��O�s�Hy/n"<<endl;  
                  char yn;cin>>yn;  
                  if(yn=='y'){  
                              save(1);   
                             cout<<"�O�s��?�I??��?�I"<<endl;   
                             }  
                  if(yn=='n') cout<<"���O�s�I??��?�I"<<endl;  
                  cin>>i>>j;  
                  }  
     else if(i==222) {goback=1;return;}  
     else cin>>j;                
     if(!(i>=0&&i<15)) {  
                       cout<<"?�J??!�W�X��?�S?�I?���s?�J"<<endl;  
                       continue;  
                       }  
     else if(!(j>=0&&j<15)) {  
                       cout<<"?�J??!�W�X��?�S?�I?���s?�J"<<endl;  
                       continue;  
                       }  
     else if(chessboard[i][j]!=0){  
                             cout<<"?�J??�I ?��m�W�w���Ѥl�I?���s?�J"<<endl;  
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
              cout<<"���a1�U�l:"<<endl;   
              int i,j;  
              cin>>i;  
               if(i==111) {cout<<"�O�_?���ѧ��O�s�Hy/n"<<endl;  
                  char yn;cin>>yn;  
                  if(yn=='y') {  
                              save(2);  
                               cout<<"�O�s��?�I??��?�I"<<endl;   
                               }  
                  if(yn=='n') cout<<"���O�s�I??��?�I"<<endl;  
                  cin>>i>>j;  
                  }  
              else if(i==222) {goback=1;return;}  
              else cin>>j;  
              if(!(i>=0&&i<15)) {  
                       cout<<"?�J??!�W�X��?�S?�I?���s?�J"<<endl;  
                       continue;  
                       }  
              else if(!(j>=0&&j<15)) {  
                       cout<<"?�J??!�W�X��?�S?�I?���s?�J"<<endl;  
                       continue;  
                       }  
              else if(chessboard[i][j]!=0){  
                             cout<<"?�J??�I ?��m�W�w���Ѥl�I?���s?�J"<<endl;  
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
              cout<<"���a2�U�l:"<<endl;   
              int i,j;  
              cin>>i>>j;  
              if(!(i>=0&&i<15)) {  
                       cout<<"������J!�W�X�ѽL�S���I�Э��s�J"<<endl;  
                       continue;  
                       }  
              else if(!(j>=0&&j<15)) {  
                       cout<<"������J!�W�X�ѽL�S���I�Э��s�ѤJ"<<endl;  
                       continue;  
                       }  
              else if(chessboard[i][j]!=0){  
                             cout<<"���~��J�I �Ӧ�m�W�w���Ѥl�I�Э��s�ѤJ"<<endl;  
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
                               
  
//�P?�O�_���H?   
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
      
                        
//??���   
void Gobang::think(){  
       
     total_com=0;total_hum=0;  
       
     //�����P?�O�_�i�H�U�@?�l�N�ߧY?��?,�Y����   
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //��Ŧ�   
                  chessboard[i][j]=1;  
                  if(ifwin()==1) {last1=i;last2=j;return;}                  //???   
                  chessboard[i][j]=0;                      //?�Ϊ���m���U�l   
                  }  
         }  
           
     for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(chessboard[i][j]!=0) continue;       //��Ŧ�   
                  chessboard[i][j]=2;  
                  if(ifwin()==2) {chessboard[i][j]=1;last1=i;last2=j;return;}                  //����a?   
                  chessboard[i][j]=0;                      //?�Ϊ���m���U�l   
                  }  
         }      
           
  
           
           
      //??�����Ĥ@�B�A��l�A��??��   
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
       
                        
           
   //�H�W����?���A?�l����  
   getresults();   
       
              
          
    
}     
  
  
  
void Gobang::getresults(){  
       
          for(int i=0;i<15;i++)  
            for(int j=0;j<15;j++){  
                    comresults[i][j]=0;  
                    humresults[i][j]=0;}                //�C�����m�s   
       max_com=0;max_hum=0;max_com_i=0;  
       max_com_j=0;max_hum_i=0;max_hum_j=0;  
         
         
       //?�l����   
       r_four();  
       r_three();  
       r_two();  
         
       //��?????�M���a���̰����A�}�O�s�䧤?   
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
                      
       //���R??�̰����A?�w��?�O��  
         
       if(max_com>=1000) {                                      //??�ন�|   
                       chessboard[max_com_i][max_com_j]=1;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=1000) {                                      //����a�|   
                       chessboard[max_hum_i][max_hum_j]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
       if(max_com>=18) {                                      //??�ন?�T �]�Χ�h�^   
                       chessboard[max_com_i][max_com_j]=1;   
                       last1=max_com_i;last2=max_com_j;         
                       return;  
                       }          
       if(max_hum>=18) {                                      //����a?�T �]�Χ�h�^   
                       chessboard[max_hum_i][max_hum_j]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
         
         
       if(max_com==17||max_com==16) {                                      //�t�@��������`?�T  
                       chessboard[max_com_i][max_com_j]=1;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum==17||max_hum==16) {                                        
                       chessboard[max_hum_i][max_hum_j]=1;  
                       last1=max_hum_i;last2=max_hum_j;          
                       return;  
                       }  
                         
                         
       if(max_com<16&&max_com>=10) {                                      //3,3+1 ,3+2�A?4   
                       chessboard[max_com_i][max_com_j]=1;  
                       last1=max_com_i;last2=max_com_j;           
                       return;  
                       }          
       if(max_hum<16&&max_hum>=10) {                                        
                       chessboard[max_hum_i][max_hum_j]=1;   
                       last1=max_hum_i;last2=max_hum_j;         
                       return;  
                       }                                        
  
       //��L��?���ު��a�A??���̦n��  
       chessboard[max_com_i][max_com_j]=1;  
       last1=max_com_i;last2=max_com_j;   
       return;  
}   
  
  
//�`�G �|�s�b���@?�ܤj??�O�A�b?��?�{����??�V�ɡA���O??�G��?���v?  
//�i�H�[�J????�ɪ�?�d�A�Ӧh�F�A�H�Z�A?   
  
void Gobang::r_four(){  
       
     for(int i=1;i<14;i++)  
         for(int j=1;j<14;j++){  
                   
                 if(chessboard[i][j]!=0) continue;  
                   
                   
                 //�Ĥ@����?    xooo@x  
                   
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
                   
                   
                 //�ĤG����?   xoo@ox  
                   
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
                   
                   
                   
                   
                   
                 //�ĤT����?     *ooo@x   
                   
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
                   
                 //�ĥ|����?   *oo@ox  
                   
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
                   
                 //�Ĥ�����?   *o@oox  
                   
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
                   
                 //�Ĥ�����?  *@ooox  
                   
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
                   
                 //�ĤC����?   @xooo*    
                   
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
                   
                 //�ĤK����?  ox@oo*     *�O?�F���M���T���`�[��   
                   
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
                   
                 //�ĤE����?   oxo@o*  
                   
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
                   
                 //�ĤQ����?   oxoo@*   
                   
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
                   
                 //�ĤQ�@����?   @oxoo  
                   
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
                   
                 //�ĤQ�G����?   o@xoo   
                   
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
                      
                    //�ĤG����?   xx@xox   
                      
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
       
       
  
  
//?�l��?   
                  
  
void go(int n){  
     Gobang g;  
     if(n==1)  
     {  
             cout<<"�֥����ѡG"<<endl;  
             cout<<"     1.���a��"<<endl;  
             cout<<"     2.pc��"<<endl;  
             int n;cin>>n;  
             if(n==2)  g.firstgo();  
     while(1){  
              if(g.ifwin()==1) {  
                                g.print(1);  
                                cout<<"pc�ӡI"<<endl;   
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"���a�ӡI"<<endl;  
                              break;  
                              }   
              g.print(1);  
              g.input(1);  
              if(g.returngoback()==1) {cout<<"over�F�I"<<endl;return;}  
              if(g.ifwin()==1) {  
                                g.print(1);  
                              cout<<"pc�ӡI"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"���a�ӡI"<<endl;  
                              break;  
                              }   
              g.think();  
              }  
     }  
     if(n==2){  
              while(1){  
              if(g.ifwin()==1) {  
                                g.print(2);  
                              cout<<"���a1�ӡI"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(2);  
                              cout<<"���a2�ӡI"<<endl;  
                              break;  
                              }  
              g.print(2);  
              g.input(2);  
              if(g.returngoback()==1) {cout<<"over�F�I"<<endl;return;}  
              }  
              }   
                
                
}  
  
  
//??�s?   
  
void load(){  
     Gobang g;  
     cout<<"�w�����s�����p�U�G"<<endl;  
     if(g.dir()==0) {cout<<"�w���s�����A�L�k�s��!"<<endl;return;}  
     cout<<"?�J���W�]��?�Z?�^:"<<endl;  
     string filename;  
     cin>>filename;  
     filename=filename+".gbg";  
     ifstream ifile(filename.c_str());   
     int choice;  
     ifile>>choice;  
     if(choice!=1&&choice!=2) {  
                              cout<<"��󤣮e�I" <<endl;  
                              return;  
                              }  
     for(int i=0;i<15;i++)  
         for(int j=0;j<15;j++)  
                {int n;  
                  ifile>>n;  
                  if(n!=1&&n!=2&&n!=0) {  
                                       cout<<"��󤣮e�I"<<endl;  
                                       return;  
                                       }   
                  g.setchessboard(i,j,n);  
                  }  
                   ifile.close();  
       
     if(choice==1) {  
             while(1){  
                   if(g.ifwin()==1) {  
                                g.print(1);  
                              cout<<"pc�ӡI"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"���a�ӡI"<<endl;  
                              break;  
                              }   
              g.print(1);  
              g.input(1);  
              if(g.returngoback()==1) {cout<<"??�F�I"<<endl;return;}  
              if(g.ifwin()==1) {  
                                g.print(1);  
                              cout<<"pc�ӡI"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(1);  
                              cout<<"���a�ӡI"<<endl;  
                              break;  
                              }   
              g.think();  
              }  
              }  
     if(choice==2){  
                while(1){  
              if(g.ifwin()==1) {  
                                g.print(2);  
                              cout<<"���a1�ӡI"<<endl;  
                              break;  
                              }  
              if(g.ifwin()==2){  
                              g.print(2);  
                              cout<<"���a2�ӡI"<<endl;  
                              break;  
                              }  
              g.print(2);  
              g.input(2);  
              if(g.returngoback()==1) {cout<<"over�F�I"<<endl;return;}  
                
              }  
              }   
  
}    
                     
  
  
void explain(){  
     cout<<"****************?��****************"<<endl;  
       
     cout<<"�ɭ�?���G"<<endl;  
     cout<<"   �Ѥl??�A?�ܴ�?�W����?��??���Ѥl"<<endl;  
     cout<<"   �Ѥl?�A?��?�誺�Ѥl?? "<<endl;  
     cout<<"   ��?�j�p?15*15�A��C��?��??1��14�A��?�@?�`�b��??�W�C"<<endl;  
     cout<<"   ��?�U��?�ܤW�@�B���U�l��?��m�C"<<endl;  
       
     cout<<"�ާ@?���G"<<endl;   
     cout<<"   ?�J��?�U�l�A��??�J��C��?�C�i�H�ΪŮ�j?�A�]�i�H�Φ^?�A���঳��L��?�C"<<endl;   
     cout<<"   �b��?��?�J111�i??�O�s��?�]?�H??���u��ѥ���O�s�^�C"<<endl;  
     cout<<"   ?�J222??�I"<<endl;  
       
     cout<<"���?���G"<<endl;   
     cout<<"   ���l��.exe   �D�{�Ǥ�� "<<endl;   
     cout<<"   *.gbg    �s?���"<<endl;  
     cout<<"   dir.txt   �O�s�H��  "<<endl;   
     }   
       
       
       
//�D��?   
  
int main(){  
    while(1){  
             system("cls");  
             cout<<"****************���l��****************"<<endl;  
             cout<<"                         axun. 2009.8.13"<<endl;  
             cout<<"?�J?�r??�G"<<endl;  
             cout<<"             1.�H���C���C"<<endl;  
             cout<<"             2.���H�C���C"<<endl;  
             cout<<"             3.Ū���s�ҡC"<<endl;  
             cout<<"             4.����"<<endl;   
             cout<<"             0.�h�X�����C"<<endl;  
             int s;  
             cin>>s;  
             if(s==1) go(1);  
             if(s==2) go(2);  
             if(s==3) load();  
             if(s==4) explain();  
             if(s==0) exit(0);  
             cout<<"��^�D���H  y�G�O  �Cn�G�h�X���� "<<endl;  
             char yn;  
             cin>>yn;  
             if(yn=='n') break;   
            }  
}  
