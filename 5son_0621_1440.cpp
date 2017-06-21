
#include<iostream> 
#include<string> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <algorithm>
#include <memory.h>

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


struct Node
{
    int x ;//�槤�� 
    int y ;//�C���� 
    int value ;//�b���`�I�U���Z�����p��
    int win ;//���F�@�B�ѦZ�O�_��Ĺ�A1�N��Ĺ�A0�Y��Ĺ�]����A-1��F
    bool operator < ( const Node aNode ) const
    {
        return this->value > aNode.value ;
    }
} ;

class Search
{
public:
    Search( int depth , int numOfGoodNodes , short chessBoard[ 17 ][ 17 ] ) ;
    void search_several_good_nodes(int com,int pla, short board[ 17 ][ 17 ] , Node* goodNodeArray  , int numGoodNodes  ) ;//�g�ߪk����X�X�Ӥ���n��
    int alphaBetaSearch( int depth , int alpha , int beta , int player,int rival ) ; //alpha-beta�ŪK�j����k
    bool win( int x , int y , int player,int rival ) ;//�P�_��_�ӧQ 
    Node bestMove ; //�U�@�B�n�����a��
	bool generator(int com,int pla,int I ,int J,short boar[17][17]);
    int depth ; //�j�����`��
    int numOfGoodNodes ; //�X�Ӥ���n���I���ӼơA�H��p���Y���`����
 //   Gobang evaluator ;
    short chessBoard[ 17 ][ 17 ] ;//�ѽL���A 
};













//class of  computer
int com_choose=100;  //�q��������� 
int I2,J2,I3,J3;
int ccc=0,ppp=0;
class Gobang{  
        
      public:   
                
             short board[17][17];          //�ѽL  
              int five[5][5];                  //5*5�p��?   
             int six[6][6];
           	 bool endtry;
             int computernum,humannum;         //�Ѥl   
             int p1,p2; 
			                       //�Ѥl   
             int last1,last2;                    //�����W�@�B    
             int comresults[15][15];             //�s����  
             int humresults[15][15];  
             int temp[15][15];             //15x15�{�ɴ� �L 
             int max_com,max_hum,max_com_i,max_com_j,max_hum_i,max_hum_j;             
             int total_com,total_hum;              //�q���M���a�`��   
             int getValue(int player,int rival , short board[17][17] , int *whether_win,int i,int j );
     
     		 
              void default_board();//��l�ƴѽL15x15 
			  void show_board();//��ܴѽL15x15 
			  void put_chess(short,short,short);//�U��+�P�_���L�Ѥl 
			  bool winner(short i,short j,short whosturn);//�ӭt win = 1 �ӧQ 
			  void go(int COMI2,int COMJ2,int COMI3,int COMJ3) ; // �C���}�l 
			  void multiplayer(int pla);//��Ӫ��a, �´ѥ��U 	
              Gobang();  
              void setboard(int ,int,int);     //���ܴѤl   
              void count(int com,int pla);                         //�O�ơA�Ѥl��   
            //  void count_total();                //���`��   
			  bool generator(int com,int pla,int I,int J); 
 
			void getfive(int i,int j,short board[17][17]);             // Ū���ƾڡA�s�J5*5 ���ѽL��   
            
              void getsix(int,int);  
              int ifwin(int com,int pla,short board[17][17]);                     //�P�_�ӭt        
             // void think(int com,int pla);  
            
              void a_four(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
              void a_three(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
              void a_two(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
              void a_one(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
              void a_blockfour(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
              void a_blockthree(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
              void a_blocktwo(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
              void a_blockone(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf);
      //        int returngoback();  
                
   
};  







int main()//�� �D�{�� �� 
{ 	string bw2,bw3;
	
    string who_first;
    int COMI2,COMI3,COMJ2,COMJ3; //�����q���H���� 
	cout<<"������(1)�ΰ����(0)?\n";
    getline(cin,who_first);
    string choose; 
    
    
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
      system("cls");
      g.show_board();
      srand((unsigned)time(NULL));
      com_choose=rand()%2;
 }	  
    
	  
	 
       //����� 
       else if(who_first=="0")
       {
       	// �H�����l 
    step5:
	   	srand( (unsigned)time(NULL) );
      	COMI2=rand() % 3 +7;
       	Sleep(1000);
       	COMJ2=rand() % 3 + 7;
       	
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
       cout <<"��J y �A���@���H�G"; 
       getline(cin,choose); 
    }while(choose == "y" || choose == "Y"); 
    return 0; 
} 



bool Search::generator(int com,int pla,int I,int J,short boar[17][17]){

	
		
			 if(boar[I][J+1]==ccc||boar[I][J+1]==ppp) return true;
			else if(boar[I][J+2]==ccc||boar[I][J+2]==ppp) return true;
			else if(boar[I][J-1]==ccc||boar[I][J-1]==ppp) return true;
			else if(boar[I][J-2]==ccc||boar[I][J-2]==ppp) return true;
			
			else if(boar[I+1][J]==ccc||boar[I+1][J]==ppp) return true;
			else if(boar[I+1][J+1]==ccc||boar[I+1][J+1]==ppp) return true;
			else if(boar[I+1][J+2]==ccc||boar[I+1][J+2]==ppp) return true;
			else if(boar[I+1][J-1]==ccc||boar[I+1][J-1]==ppp) return true;
			else if(boar[I+1][J-2]==ccc||boar[I+1][J-2]==ppp) return true;
			
			else if(boar[I+2][J]==ccc||boar[I+2][J]==ppp) return true;
			else if(boar[I+2][J+1]==ccc||boar[I+2][J+1]==ppp) return true;
			else if(boar[I+2][J+2]==ccc||boar[I+2][J+2]==ppp) return true;
			else if(boar[I+2][J-1]==ccc||boar[I+2][J-1]==ppp) return true;
			else if(boar[I+2][J-2]==ccc||boar[I+2][J-2]==ppp) return true;
			
			else if(boar[I-1][J]==ccc||boar[I-1][J]==ppp) return true;
			else if(boar[I-1][J+1]==ccc||boar[I-1][J+1]==ppp) return true;
			else if(boar[I-1][J+2]==ccc||boar[I-1][J+2]==ppp) return true;
			else if(boar[I-1][J-1]==ccc||boar[I-1][J-1]==ppp) return true;
			else if(boar[I-1][J-2]==ccc||boar[I-1][J-2]==ppp) return true;
			
			else if(boar[I-2][J]==ccc||boar[I-2][J]==ppp) return true;
			else if(boar[I-2][J+1]==ccc||boar[I-2][J+1]==ppp) return true;
			else if(boar[I-2][J+2]==ccc||boar[I-2][J+2]==ppp) return true;
			else if(boar[I-2][J-1]==ccc||boar[I-2][J-1]==ppp) return true;
			else if(boar[I-2][J-2]==ccc||boar[I-2][J-2]==ppp) return true;
			
			else{
				return false;
			}
	
	
}










//�۳y��ơCdepth�G�j���`�סFnumOfGoodNodes�G�C�@�B�j�A�Y�j���e�סFboard�G�ѽL 
Search::Search( int depth , int numOfGoodNodes , short chessBoard[ 17 ][ 17 ] )
{
   // evaluator = Gobang() ;
    this->depth = depth ;
    this->numOfGoodNodes = numOfGoodNodes ;
    //��l��bestMove
    bestMove.x = bestMove.y = - 1 ;
    bestMove.value = 0 ;
    bestMove.win = 0 ;

    //?��??��
    for( int i = 0 ; i < 17 ; i ++ )
    {
        for ( int j = 0 ; j <17 ; j ++ )
        {
            this->chessBoard[ i ][ j ] = chessBoard[ i ][ j ] ;
        }
    }
}

//?�ߪk����XnumGoodNodes���Ƥ���n��
void Search::search_several_good_nodes(int player,int rival, short board[ 17 ][17 ] , Node* goodNodeArray  , int numGoodNodes )
{
    int countGood = 0 ; //??goodNodeArray??��?�w?�s�F�h��?
	Gobang evaluator;
    Node tmpNode ; //???�q
    for( int i = 0 ; i <15 ; i ++ )
    {
        for ( int j = 0 ; j < 15 ; j ++ )
        {
            if ( board[ i+1 ][ j+1 ] <0 )
            {
                int whether_win  = 0 ,temp=0;
               if(!generator(player,rival,i+1,j+1,board))  continue;
                temp=board[i+1][j+1];
                board[ i+1 ][ j+1 ] = player ;
               
                
                int value = evaluator.getValue(player,rival, board , &whether_win,i,j ) ;
             //   cout<<i+1<<"  "<<j+1<<"  "<<value<<"\n";
            //    system("pause");
                board[ i+1 ][ j+1 ] = temp ;
                 if(value==0)  continue;

                tmpNode.x = i ;
                tmpNode.y = j ;
                tmpNode.value = value ;
                tmpNode.win = whether_win ;

                //�����ȥѤj�ܤp��?�ǧ�X�̦n��numGoodNodes???
                if ( ++countGood <= numGoodNodes )
                {
                    goodNodeArray[ countGood - 1 ] = tmpNode ;
                    if ( countGood == numGoodNodes )
                    {
                        sort( goodNodeArray , goodNodeArray + numGoodNodes ) ;
                    }
                }
                else
                {
                    if ( value > goodNodeArray[ numGoodNodes - 1 ].value )
                    {
                        for ( int k = 0 ; k < numGoodNodes ; ++ k )
                        {
                            if ( value > goodNodeArray[ k ].value )
                            {
                                goodNodeArray[ k ] = tmpNode ;
                                break ;
                            }
                        } //end-for
                    } //end-if
                }//end-else
            }//end-if
        }//end-for-j
    }//end-for-i
  /*  cout<<"----------------------------\n";
    for(int k=0;k<numGoodNodes ; k++)
    cout<<goodNodeArray[k].value<<"\n";
 	system("pause");
*/

}//end-func

//alpha-beta?�K�j����k
int Search::alphaBetaSearch( int search_depth , int alpha , int beta ,int player,int rival )
{	
    int score,temp ;//���ȵ��G
    Node *goodNodes = new Node[ numOfGoodNodes ] ;
    Node *badNodes = new Node[ 1 ] ;
    badNodes[ 0 ].x = badNodes[ 0 ].y = badNodes[ 0 ].win = 0 ;
    search_several_good_nodes(  player, rival , chessBoard , goodNodes , numOfGoodNodes  ) ;
    search_several_good_nodes( (player==ccc) ? rival : player , (player==ccc) ?  player : rival , chessBoard , badNodes , 1 ) ;

   //�p�G?�F�A���i��A�b����¦�W�U�U�h
    if ( goodNodes[ 0 ].win == 100 )
    {
        if ( search_depth == 1)
        {
            bestMove.x = goodNodes[ 0 ].x ;
            bestMove.y = goodNodes[ 0 ].y ;
        }
        return goodNodes[ 0 ].value ;
    }
    //�ۤv���U�A��Ĺ�A�ҥH�U�@�B�o���b?�誺�@�B�W
    if ( badNodes[ 0 ].win == 100 )
    {
        if ( search_depth == 1 )
        {
            bestMove.x = badNodes[ 0 ].x ;
            bestMove.y = badNodes[ 0 ].y ;
        }

        return badNodes[ 0 ].value ;
    }
		
    //�j����F�̦Z�@�h�A��^
    if ( search_depth == this->depth )
    {	
    //	cout<<goodNodes[0].value;
    //	system("pause");
        return ( search_depth % 2 ) ? goodNodes[ 0 ].value : ( - goodNodes[ 0 ].value ) ;
    }

    for ( int i = 0 ; i < numOfGoodNodes ; ++ i )
    {	temp=chessBoard[ goodNodes[ i ].x+1 ][ goodNodes[ i ].y+1 ];
        chessBoard[ goodNodes[ i ].x+1 ][ goodNodes[ i ].y+1 ] = player ;
        score = -alphaBetaSearch( search_depth + 1 , -beta , -alpha , (player==ccc) ? rival : player , (player==ccc) ?  player : rival) ;
        chessBoard[ goodNodes[ i ].x+1 ][ goodNodes[ i ].y+1 ] =temp  ;

        if ( score >= beta )
        {
            return beta ;
        }

        if ( score > alpha )
        {
            alpha = score ;
            if ( search_depth == 1 )
            {
                bestMove.x = goodNodes[ i ].x ;
                bestMove.y = goodNodes[ i ].y ;
            }
        }
    }
    return alpha ;
}

























































//�}�l�C��//
#define width 5
#define depth 3
void Gobang::go(int COMI2,int COMJ2,int COMI3,int COMJ3){  
       
       char n;
            if(com_choose==100){
			
             cout<<"���a�n�´ѩΥմ�?�G"<<endl;  
             cout<<"     1.�´�"<<endl;  
             cout<<"     2.�մ�"<<endl;  
              n= getchar();
			cout<<"\n";
		    }
		
             int computer=0,player=0;
             if(com_choose==0){
             	cout<<"�q����F�¤l\n"; 
             	ccc=1;
             	ppp=2;
             	player=2;
             	computer=1;
             	last1=I3-1;
				last2=J3-1;
             	system("pause");
			 }
			 else if(com_choose==1){
			 	cout<<"�q����F�դl\n"; 
			 	ccc=2;
			 	ppp=1;
			 	player=1;
			 	computer=2;
             	
             	last1=I2-1;
				last2=J2-1;
			
				
             	system("pause");
             Search search( depth , width , board ) ;
    		search.alphaBetaSearch( 1 , -9999999, 9999999 , computer ,player) ;
    		 last1=search.bestMove.x ;
    		 last2=search.bestMove.y ;
    		 board[last1+1][last2+1]=computer;
			 }
             else if(n=='2'){
             	ccc=1;
             	ppp=2;
             	player=2;
             	computer=1;
             	last1=COMI3-1;
				last2=COMJ3-1;
			
			 }  
             else if(n=='1'){
			 	player=1;
			 	computer=2;
             	ppp=1;
             	ccc=2;
             	last1=COMI2-1;
				last2=COMJ2-1;
			Search search( depth , width , board ) ;
    		search.alphaBetaSearch( 1 , -9999999, 9999999 , computer ,player) ;
    		 last1=search.bestMove.x ;
    		 last2=search.bestMove.y ;
    		 board[last1+1][last2+1]=computer;
		
			}
     while(1){  
              if(ifwin(computer,player,board)==computer) { 
			  					system("cls"); 
                                 show_board();  
                                cout<<"�q���ӧQ�I"<<endl;   
                              break;  
                              }  
              if(ifwin(computer,player,board)==2){ 
			  					system("cls");  
                              show_board(); 
                              cout<<"���a�ӧQ�I"<<endl;  
                              break;  
                              }   
              
             system("cls");
             show_board();
            cout<<"�q���U�F "<<last1+1<<" "<<last2+1<<"\n"; 
             system("pause");
             multiplayer(player);   
      
              if(ifwin(computer,player,board)==computer) { 
              					system("cls"); 
                               show_board();  
                              cout<<"�q���ӧQ�I"<<endl;  
                              break;  
                              }  
              if(ifwin(computer,player,board)==player){  
              					system("cls"); 
                              show_board();  
                              cout<<"���a�ӧQ�I"<<endl;  
                              break;  
                              }   
           //   think(computer,player);  
            Search search( depth , width , board ) ;
    		search.alphaBetaSearch( 1 , -9999999, 9999999 , computer ,player) ;
    		 last1=search.bestMove.x ;
    		 last2=search.bestMove.y ;
    		 board[last1+1][last2+1]=computer;
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



//�P�_�Ӥl���񦳨S���l�A�O�_�n���� 
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

  
//�P�O�_���H���  
int Gobang::ifwin(int com,int pla,short board[17][17]){  
    for(int i=0;i<=10;i++)  
        for(int j=0;j<=10;j++){  
              getfive(i,j,board);  
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
              getfive(i,j,board);  
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




  
//�p��q���M���a�o��   
   








  
void Gobang::getfive(int i,int j,short board[17][17]){  
     for(int m=0;m<5;m++)  
         for(int n=0;n<5;n++)  
                 five[m][n]=board[m+i+1][n+j+1];  
}  
  
  
  
void Gobang::getsix(int i,int j){  
     for(int m=0;m<6;m++)  
         for(int n=0;n<6;n++)  
                 six[m][n]=board[m+i+1][n+j+1];  
}  













int Gobang::getValue(int player,int rival,short board[17][17] ,int *whether_win ,int I,int J){
			
	       int temp2=0,temp=0,clf=0,cbf=0,clt=0,plf=0,pbf=0;
     //�����P�_�O�_�i�H�U�@�l�N�ߧY����   
   
   /*    for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]>0) continue;       //��Ŧ�   
                  temp=board[i+1][j+1];
                  board[i+1][j+1]=ccc;  
                  if(ifwin(ccc,ppp)==ccc) {last1=i;last2=j; return 4000000;}                  //???   
                  board[i+1][j+1]=temp;                      //�Ϊ���m���U�l 
				    
                  }  
         } 
         */
         
      for(int k=0;k<15;k++)  
            for(int l=0;l<15;l++){  
                    comresults[k][l]=0;  
                    humresults[k][l]=0;}   
                    
            
                    
                    
                    
                    
                    
                    
                    
  /*   
     for(int i=0;i<15;i++){
     	for(int j=0;j<15;j++){
     		cout<<board[i+1][j+1];
     		
		 }
		 cout<<"\n";
	 }*/
   //  system("pause");
  
	
//	cout<<"position: "<<I+1<<"  "<<J+1<<"\n";

		for(int m=0;m<15;m++){
				for(int n=0;n<15;n++){
	
					if(board[m+1][n+1]<0) continue;
			 		a_four(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf);  
			 		a_blockfour(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf); 
       		 		a_three(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf);  
       		 		a_blockthree(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf); 
             		a_two(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf);  
             		a_blocktwo(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf);
             		a_one(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf);
             		a_blockone(ccc,ppp,m+1,n+1,I,J, board,clf,cbf,clt,plf,pbf);
             		
			}	  //for n
		}	    //for  m
			
			
	    if (ifwin(ccc,ppp,board)==ppp )
    {
        *whether_win = -1 ;
        return -6000000 ;
    }
    //�p�G�ڤ褭?�A�ڤ��
    if ( ifwin(ccc,ppp,board)==ccc )
    {
        *whether_win = 100 ;
        return 4000000 ;
    }
    //�p�G��謡�|�ΨR�|�A��
    if ( plf>0 ||pbf>0 )
    {
        *whether_win = -1 ;
        return -3200000 ;
    }
    //�ڤ謡�|�A?�ڤ�?
    if ( clf>0 )
    {
        *whether_win = 100 ;
        return 1800000 ;
    }
    //�p�G�ڤ誺�v�|�M���T���M�j�_���_2�A?�ڤ�?
    if ( cbf+clt>6)
    {
        *whether_win = 100 ;
        return 1000000 ;
    }             
                    
           
//	cout<<comresults[I][J]<<"    "<<humresults[I][J]<<"\n";
//	if(player==ccc)   
return comresults[I][J]-humresults[I][J];
//	else if(player==ppp) 	return humresults[I][J]-comresults[I][J];
	
	
}



//if(board[m-4][n]&&board[m-3][n]&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n])	comresults[i][j]+=50;
// if(board[m][n-4]&&board[m][n-3]&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4])  comresults[i][j]+=50;
//if(board[m-4][n-4]&&board[m-3][n-3]&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]) comresults[i][j]+=50;
//if(board[m-4][n+4]&&board[m-3][n+3]&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]) comresults[i][j]+=50;
void Gobang::a_four(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){  
	
	if(board[m][n]==com){
	
		//    x@ooox 
				if(board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]<0)	comresults[i][j]+=2500;  clf++; 
				if(board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=2500;  clf++; 
				if(board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=2500;  clf++;
				if(board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]<0) comresults[i][j]+=2500;  clf++;
		//	  xooo@x
				if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0) comresults[i][j]+=2500;  clf++;   
                if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0)  comresults[i][j]+=2500;  clf++; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0) comresults[i][j]+=2500 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0) comresults[i][j]+=2500;  clf++; 	
		//    xo@oox
				  if(board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0)	comresults[i][j]+=2500;  clf++;  
				  if(board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0)	comresults[i][j]+=2500;  clf++;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0)	comresults[i][j]+=2500;  clf++;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0)	comresults[i][j]+=2500;  clf++; 
		//    xoo@ox

				 if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0)	comresults[i][j]+=2500;  clf++; 
				 if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0)	comresults[i][j]+=2500;  clf++; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0)	comresults[i][j]+=2500;  clf++; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0)	comresults[i][j]+=2500;  clf++; 
				 
				 
				 
	}
		else if(board[m][n]==pla){
				
				//    x@ooox 
				if(board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]<0)	humresults[i][j]+=10000;  plf++;
				if(board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=10000;  plf++;
				if(board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=10000;  plf++;
				if(board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]<0) humresults[i][j]+=10000;  plf++;
		//	  xooo@x
				if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0) humresults[i][j]+=10000;  plf++;   
                if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0)  humresults[i][j]+=10000;  plf++; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0) humresults[i][j]+=10000 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0) humresults[i][j]+=10000;  plf++; 	
		//    xo@oox
				  if(board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=10000;  plf++;  
				  if(board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=10000;  plf++;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=10000;  plf++;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=10000;  plf++; 
		//    xoo@ox

				 if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0)	humresults[i][j]+=10000;  plf++; 
				 if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0)	humresults[i][j]+=10000;  plf++; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0)	humresults[i][j]+=10000;  plf++; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0)	humresults[i][j]+=10000;  plf++; 
			
			
			
		}
	
	
}

void Gobang::a_blockfour(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){

		if(board[m][n]==com){
			
			//�Ĥ@�ر���  *@ooox
			if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]<0)	comresults[i][j]+=250;  cbf++;
			if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=250;    cbf++;
			if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=250;  cbf++;  
			if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]<0) comresults[i][j]+=250;  cbf++;
			
			//  		xooo@*
			if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=250;  cbf++;   
            if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=250;  cbf++; 				
            if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=250 ; 	
			if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=250;  cbf++; 	
			
			
			//�ĤG�ر���   *o@oox
				  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0)	comresults[i][j]+=250;  cbf++;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0)	comresults[i][j]+=250;  cbf++; 
			
			//			xoo@o*
				 if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=250;  cbf++; 
			
			
			//�ĤT�ر���   *oo@ox
				 if(board[m-3][n]==pla&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-3]==pla&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n-3]==pla&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n+3]==pla&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0)	comresults[i][j]+=250;  cbf++; 
			
			//			xo@oo*
				  if(board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==pla)	comresults[i][j]+=250;  cbf++;  
				  if(board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==pla)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==pla)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==pla)	comresults[i][j]+=250;  cbf++; 
			
			
			
			//�ĥ|�ر��� *ooo@x
				  if(board[m-4][n]==pla&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0) comresults[i][j]+=250;  cbf++; 	
			
			//			x@ooo*
				if(board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]==pla)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]==pla)  comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]==pla) comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]==pla) comresults[i][j]+=250;  cbf++;
			
			
			
			
			//�Ĥ��ر���		@ooxo
				if(board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0&&board[m+4][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0&&board[m][n+4]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0&&board[m+4][n-4]==com) comresults[i][j]+=250;  cbf++;
			
			//				oxoo@
				  if(board[m-4][n]==com&&board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com) comresults[i][j]+=250;  cbf++; 
			
			//�Ĥ��ر���   		o@oxo
			
				if(board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==com) comresults[i][j]+=250;  cbf++;
			//				oxo@o
				  if(board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com) comresults[i][j]+=250 ; 	
				  if(board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com) comresults[i][j]+=250;  cbf++; 	
			
			
			
			
			//�ĤC�ر���		oo@xo
				 if(board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]==com)	comresults[i][j]+=250;  cbf++; 
			
			
			//				ox@oo
				if(board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com)	comresults[i][j]+=250;  cbf++; 
			
			//�ĤK�ر���		ooox@
				  if(board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]<0) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]<0)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]<0) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]<0) comresults[i][j]+=250;  cbf++; 
			
			
			//			@xooo
			
				if(board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]==com) comresults[i][j]+=250;  cbf++;
			
			
			
			
			
			//�ĤE�ر���	@oxoo
				
				
				if(board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==com) comresults[i][j]+=250;  cbf++;
			//				ooxo@
				  if(board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==com) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==com)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==com) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==com) comresults[i][j]+=250;  cbf++; 
			
			//�ĤQ�ر���	o@xoo
				if(board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]==com) comresults[i][j]+=250;  cbf++;
			
			//			oox@o			
			
				  if(board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==com) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==com)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==com) comresults[i][j]+=250 ; 	
				  if(board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==com) comresults[i][j]+=250;  cbf++; 	
			
			
			
			
			
		


		}


		else if(board[m][n]==pla){
				
			//�Ĥ@�ر���  *@ooox
			if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]<0)	humresults[i][j]+=1000;  pbf++;
			if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=1000;  pbf++;
			if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=1000;  pbf++;
			if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]<0) humresults[i][j]+=1000;  pbf++;
			
			//  		xooo@*
			if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=1000;  pbf++;   
            if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=1000;  pbf++; 				
            if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=1000 ; 	
			if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=1000;  pbf++; 	
			
			
			//�ĤG�ر���   *o@oox
				  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=1000;  pbf++; 
			
			//			xoo@o*
				 if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=1000;  pbf++; 
			
			
			//�ĤT�ر���   *oo@ox
				 if(board[m-3][n]==com&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-3]==com&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n-3]==com&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n+3]==com&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0)	humresults[i][j]+=1000;  pbf++; 
			
			//			xo@oo*
				  if(board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==com)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==com)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==com)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==com)	humresults[i][j]+=1000;  pbf++; 
			
			
			
			//�ĥ|�ر��� *ooo@x
				  if(board[m-4][n]==com&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0) humresults[i][j]+=1000;  pbf++; 	
			
			//			x@ooo*
				if(board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]==com)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]==com)  humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]==com) humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]==com) humresults[i][j]+=1000;  pbf++;
			
			
			
			
			//�Ĥ��ر���		@ooxo
				if(board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0&&board[m+4][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0&&board[m][n+4]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0&&board[m+4][n-4]==pla) humresults[i][j]+=1000;  pbf++;
			
			//				oxoo@
				  if(board[m-4][n]==pla&&board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla) humresults[i][j]+=1000;  pbf++; 
			
			//�Ĥ��ر���   		o@oxo
			
				if(board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==pla) humresults[i][j]+=1000;  pbf++;
			//				oxo@o
				  if(board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla) humresults[i][j]+=1000 ; 	
				  if(board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla) humresults[i][j]+=1000;  pbf++; 	
			
			
			
			
			//�ĤC�ر���		oo@xo
				 if(board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]==pla)	humresults[i][j]+=1000;  pbf++; 
			
			
			//				ox@oo
				if(board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla)	humresults[i][j]+=1000;  pbf++; 
			
			//�ĤK�ر���		ooox@
				  if(board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]<0) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]<0)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]<0) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]<0) humresults[i][j]+=1000;  pbf++; 
			
			
			//			@xooo
			
				if(board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla) humresults[i][j]+=1000;  pbf++;
			
			
			
			
			
			//�ĤE�ر���	@oxoo
				
				
				if(board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla) humresults[i][j]+=1000;  pbf++;
			//				ooxo@
				  if(board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==pla) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==pla)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==pla) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==pla) humresults[i][j]+=1000;  pbf++; 
			
			//�ĤQ�ر���	o@xoo
				if(board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla) humresults[i][j]+=1000;  pbf++;
			
			//			oox@o			
			
				  if(board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==pla) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==pla)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==pla) humresults[i][j]+=1000 ; 	
				  if(board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==pla) humresults[i][j]+=1000;  pbf++; 	
			



		
		}


}
void Gobang::a_three(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){  
				if(board[m][n]==com){
     			//�Ĥ@�ر���    x@ooxx    	//�ĤG�ر���			  xx@oox
               
                if(board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0&&board[m+4][n]<0){
				 comresults[i][j]+=333;  ++clt;   }
                else if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0){
					comresults[i][j]+=333;  ++clt; }
                
                if(board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0&&board[m][n+4]<0) {
				 comresults[i][j]+=333;  ++clt; }
				else if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0){
					comresults[i][j]+=333;  ++clt;  }
								
                if(board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]<0){
					comresults[i][j]+=333;  ++clt;  }
				 else if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0){
					comresults[i][j]+=333;  ++clt;  }
				 	
				if(board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]<0){
					comresults[i][j]+=333;  ++clt;  }
				else if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0){
					comresults[i][j]+=333;  ++clt;  }			
                
				
				//           xxoo@x
				if(board[m-4][n]<0&&board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0){
					comresults[i][j]+=333;  ++clt;  }
				else if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0){
					comresults[i][j]+=333;  ++clt;  }  
				
                if(board[m][n-4]<0&&board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0){
					comresults[i][j]+=333;  ++clt;  }
				else if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0){
					comresults[i][j]+=333;  ++clt;  }
				 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0){
					comresults[i][j]+=333;  ++clt;  }
				 else if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0){
					comresults[i][j]+=333;  ++clt;  }	
				if(board[m-4][n+4]<0&&board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0){
					comresults[i][j]+=333;  ++clt;  }
				else if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0){
					comresults[i][j]+=333;  ++clt;  }
				
				
			
				
				
                 //�ĤT�ر���   xxo@oxx         06/10
                
                 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0)	comresults[i][j]+=333;  ++clt; 
                 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0)	comresults[i][j]+=333;  ++clt; 
                 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	comresults[i][j]+=333;  ++clt; 
                 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	comresults[i][j]+=333;  ++clt; 
                
                
                
                
                
                   
                 //�ĥ|�ر���  x@xoox   
                   
                if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]<0) comresults[i][j]+=333;  ++clt;   
                if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=333;	++clt;			
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=333;  ++clt;	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]<0) comresults[i][j]+=333;  ++clt;
                 	
                 	// xoox@x
                 	
                if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]<0) comresults[i][j]+=333;  ++clt;   
                if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]<0)  comresults[i][j]+=333;  ++clt; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]<0) comresults[i][j]+=333; 	++clt;
				if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]<0) comresults[i][j]+=333;  ++clt; 	
                 	
                   
                 //�Ĥ��ر���    xox@ox  
                   
                 if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]<0)	comresults[i][j]+=333;  ++clt; 
				 if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]<0)	comresults[i][j]+=333;  ++clt; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]<0)	comresults[i][j]+=333;  ++clt; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]<0)	comresults[i][j]+=333;  ++clt; 
                   
                   
                   
                   //    		xo@xox
                  if(board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]<0)	comresults[i][j]+=333;  ++clt;  
				  if(board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]<0)	comresults[i][j]+=333;  ++clt;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]<0)	comresults[i][j]+=333;  ++clt;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]<0)	comresults[i][j]+=333;  ++clt;  
                   
                 //�Ĥ��ر���    xoxo@x  
                   
                   
                if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]<0) comresults[i][j]+=333;  ++clt;   
                if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]<0)  comresults[i][j]+=333;  ++clt; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]<0) comresults[i][j]+=333; 	++clt;
				if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]<0) comresults[i][j]+=333;  ++clt;
				
				//   x@oxox
                if(board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]<0) comresults[i][j]+=333;  ++clt;   
                if(board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=333;	++clt;			
                if(board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=333; 	++clt;
				if(board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=333;  ++clt;	
				
			}
			else if(board[m][n]==pla){
				
			
			
			
				//�Ĥ@�ر���    x@ooxx  
                if(board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0&&board[m+4][n]<0) humresults[i][j]+=1000;   
                else if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=1000; 
                
                if(board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0&&board[m][n+4]<0)  humresults[i][j]+=1000; 
				else if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=1000;  
								
                if(board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]<0) humresults[i][j]+=1000;  
				 else if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=1000; 
				 	
				if(board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]<0) humresults[i][j]+=1000;
				else if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=1000;  			
                
				
				//           xxoo@x
				if(board[m-4][n]<0&&board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0) humresults[i][j]+=1000; 
				else if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0)	humresults[i][j]+=1000;   
				
                if(board[m][n-4]<0&&board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0)  humresults[i][j]+=1000;
				else if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0)	humresults[i][j]+=1000;
				 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0) humresults[i][j]+=1000; 
				 else if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0)	humresults[i][j]+=1000;  	
				if(board[m-4][n+4]<0&&board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0) humresults[i][j]+=1000;
				else if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0)	humresults[i][j]+=1000; 
				
				
				
				
				
				
                 //�ĤT�ر���   xxo@oxx         06/10
                
                 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0)	humresults[i][j]+=1000; 
                 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0)	humresults[i][j]+=1000; 
                 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	humresults[i][j]+=1000; 
                 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	humresults[i][j]+=1000; 
                
                
                
                
                
                   
                 //�ĥ|�ر���  x@xoox   
                   
                if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]<0) humresults[i][j]+=1000;   
                if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=1000 ;				
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=1000 ; 	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]<0) humresults[i][j]+=1000;
                 	
                 	// xoox@x
                 	
                if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]<0) humresults[i][j]+=1000;   
                if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]<0)  humresults[i][j]+=1000 ;				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]<0) humresults[i][j]+=1000 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]<0) humresults[i][j]+=1000 ;	
                 	
                   
                 //�Ĥ��ر���    xox@ox  
                   
                 if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]<0)	humresults[i][j]+=1000; 
				 if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]<0)	humresults[i][j]+=1000; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]<0)	humresults[i][j]+=1000; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]<0)	humresults[i][j]+=1000; 
                   
                   
                   
                   //    		xo@xox
                   if(board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=1000;  
				  if(board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=1000;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=1000;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=1000;  
                   
                 //�Ĥ��ر���    xoxo@x  
                   
                   
                if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]<0) humresults[i][j]+=1000;   
                if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]<0)  humresults[i][j]+=1000 ;				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]<0) humresults[i][j]+=1000 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]<0) humresults[i][j]+=1000;
				
				//   x@oxox
                if(board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]<0) humresults[i][j]+=1000;   
                if(board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=1000 	;			
                if(board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=1000  	;
				if(board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=1000;






			
	}
	
}

void Gobang::a_blockthree(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){
		
		
			if(board[m][n]==com){
		
		
			//�Ĥ@�ر���    *@oxox
				if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]<0) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]<0) comresults[i][j]+=33;
				
				
			//	xoxo@*
				if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
			
			
			
			//�ĤG�ر���   *o@xox
			 	  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]<0)	comresults[i][j]+=33;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]<0)	comresults[i][j]+=33;  
			
			
			
			     //  xox@o*
			     if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=33; 
			
			
			
			
			//�ĤT�ر���   *oox@x
				if(board[m-4][n]==pla&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]<0) comresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]<0)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]<0) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]<0) comresults[i][j]+=33; 
				
				
				
				//		x@xoo*
				if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]==pla) comresults[i][j]+=33; 
			    if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]==pla)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]==pla) comresults[i][j]+=33;	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]==pla) comresults[i][j]+=33;
				
				
				
				
				
			//�ĥ|�ر���    *@oxxo
				if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==com) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==com)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==com) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==com) comresults[i][j]+=33;
				//			oxxo@*		
				if(board[m-4][n]==com&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
				
			//�Ĥ��ر���   *o@xxo
				  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com)	comresults[i][j]+=33;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com)	comresults[i][j]+=33;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com)	comresults[i][j]+=33;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com)	comresults[i][j]+=33; 
				  
				  
				//			oxx@o*
				 if(board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=33; 
				 if(board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=33; 
				
			//�Ĥ��ر���  *ooxx@
				if(board[m-5][n]==pla&&board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0)	comresults[i][j]+=33; 
				if(board[m][n-5]==pla&&board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0)	comresults[i][j]+=33; 
				if(board[m-5][n-5]==pla&&board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0)	comresults[i][j]+=33; 
				if(board[m-5][n+5]==pla&&board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0)	comresults[i][j]+=33; 
			
				// 			@xxoo*
				if(board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==com&&board[m+5][n]==pla)	comresults[i][j]+=33;
				if(board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==com&&board[m][n+5]==pla)  comresults[i][j]+=33;
				if(board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==com&&board[m+5][n+5]==pla) comresults[i][j]+=33;
				if(board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==com&&board[m+5][n-5]==pla) comresults[i][j]+=33;
				
				
				
				
			//�ĤC�ر���  *@xxoo
				if(board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==com) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==com)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==com) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==com) comresults[i][j]+=33;
			
				//   ooxx@*
				if(board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
			
			
			
			
			
			//�ĤK�ر���   *oxx@o
				if(board[m-4][n]==pla&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com) comresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com) comresults[i][j]+=33; 
			
			
				//       o@xxo*
				if(board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==pla) comresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==pla)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==pla) comresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==pla) comresults[i][j]+=33;
				
				
				
			//�ĤE�ر���   *oxxo@
				if(board[m-5][n]==pla&&board[m-4][n]==com&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com)	comresults[i][j]+=33; 
				if(board[m][n-5]==pla&&board[m][n-4]==com&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com)	comresults[i][j]+=33; 
				if(board[m-5][n-5]==pla&&board[m-4][n-4]==com&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com)	comresults[i][j]+=33; 
				if(board[m-5][n+5]==pla&&board[m-4][n+4]==com&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com)	comresults[i][j]+=33; 
			
			//       @oxxo*
				if(board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==com&&board[m+5][n]==pla)	comresults[i][j]+=33;
				if(board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==com&&board[m][n+5]==pla)  comresults[i][j]+=33;
				if(board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==com&&board[m+5][n+5]==pla) comresults[i][j]+=33;
				if(board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==com&&board[m+5][n-5]==pla) comresults[i][j]+=33;
			
			//�ĤQ�ر���   *@ooxx
				if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0&&board[m+4][n]<0) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0&&board[m][n+4]<0)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]<0) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0&&board[m+4][n-4]<0) comresults[i][j]+=33;
			
			
			//			xxoo@*
				if(board[m-4][n]<0&&board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
			//�ĤQ�@�ر���  *o@oxx
				  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0)	comresults[i][j]+=33;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	comresults[i][j]+=33;
			
			
			// 		xxo@o*
				 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=33; 
			
			//�ĤQ�G�ر��� *oo@xx
				 if(board[m-3][n]==pla&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0)	comresults[i][j]+=33; 
				 if(board[m][n-3]==pla&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0)	comresults[i][j]+=33; 
				 if(board[m-3][n-3]==pla&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0)	comresults[i][j]+=33; 
				 if(board[m-3][n+3]==pla&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0)	comresults[i][j]+=33; 
			
			
			
			
			//			xx@oo*
				  if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==pla)	comresults[i][j]+=33;  
				  if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==pla)	comresults[i][j]+=33;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==pla)	comresults[i][j]+=33;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==pla)	comresults[i][j]+=33;
			
			
			//if(board[m-4][n]&&board[m-3][n]&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n])	comresults[i][j]+=50;
			// if(board[m][n-4]&&board[m][n-3]&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4])  comresults[i][j]+=50;
			//if(board[m-4][n-4]&&board[m-3][n-3]&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]) comresults[i][j]+=50;
			//if(board[m-4][n+4]&&board[m-3][n+3]&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]) comresults[i][j]+=50;
			
			
			
			
			
			
			
			
			
			//�ĤQ�T�ر���  *x@oox* 
			if(board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0&&board[m+4][n]==pla)	comresults[i][j]+=33;
			if(board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0&&board[m][n+4]==pla)  comresults[i][j]+=33;
			if(board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]==pla) comresults[i][j]+=33;
			if(board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0&&board[m+4][n-4]==pla) comresults[i][j]+=33;
			
			
			
			//			*xoo@x*
			
			
			//�ĤQ�|�ر���  *xo@ox*
	
			
			if(board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==pla)	comresults[i][j]+=33;
			if(board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==pla)	comresults[i][j]+=33;
			if(board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==pla)	comresults[i][j]+=33;
			if(board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==pla)	comresults[i][j]+=33;
	
	
	}
	else if(board[m][n]==pla){
		
		
			//�Ĥ@�ر���    *@oxox
				if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]<0) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]<0) humresults[i][j]+=33;
				
				
			//	xoxo@*
				if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=33; 
			
			
			
			//�ĤG�ر���   *o@xox
			 	  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=33;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=33;  
			
			
			
			     //  xox@o*
			     if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=33; 
			
			
			
			
			//�ĤT�ر���   *oox@x
				if(board[m-4][n]==com&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]<0) humresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]<0)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]<0) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]<0) humresults[i][j]+=33; 
				
				
				
				//		x@xoo*
				if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]==com) humresults[i][j]+=33; 
			    if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]==com)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]==com) humresults[i][j]+=33;	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]==com) humresults[i][j]+=33;
				
				
				
				
				
			//�ĥ|�ر���    *@oxxo
				if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==pla) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==pla)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==pla) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==pla) humresults[i][j]+=33;
				//			oxxo@*		
				if(board[m-4][n]==pla&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=33; 
				
			//�Ĥ��ر���   *o@xxo
				  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla)	humresults[i][j]+=33;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla)	humresults[i][j]+=33; 
				  
				  
				//			oxx@o*
				 if(board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=33; 
				 if(board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=33; 
				
			//�Ĥ��ر���  *ooxx@
				if(board[m-5][n]==com&&board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0)	humresults[i][j]+=33; 
				if(board[m][n-5]==com&&board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0)	humresults[i][j]+=33; 
				if(board[m-5][n-5]==com&&board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0)	humresults[i][j]+=33; 
				if(board[m-5][n+5]==com&&board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0)	humresults[i][j]+=33; 
			
				// 			@xxoo*
				if(board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==pla&&board[m+5][n]==com)	humresults[i][j]+=33;
				if(board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==pla&&board[m][n+5]==com)  humresults[i][j]+=33;
				if(board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla&&board[m+5][n+5]==com) humresults[i][j]+=33;
				if(board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla&&board[m+5][n-5]==com) humresults[i][j]+=33;
				
				
				
				
			//�ĤC�ر���  *@xxoo
				if(board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==pla) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==pla)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla) humresults[i][j]+=33;
			
				//   ooxx@*
				if(board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com) humresults[i][j]+=33; 
			
			
			
			
			
			//�ĤK�ر���   *oxx@o
				if(board[m-4][n]==com&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla) humresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla) humresults[i][j]+=33; 
			
			
				//       o@xxo*
				if(board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==com) humresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==com)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==com) humresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==com) humresults[i][j]+=33;
				
				
				
			//�ĤE�ر���   *oxxo@
				if(board[m-5][n]==com&&board[m-4][n]==pla&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla)	humresults[i][j]+=33; 
				if(board[m][n-5]==com&&board[m][n-4]==pla&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla)	humresults[i][j]+=33; 
				if(board[m-5][n-5]==com&&board[m-4][n-4]==pla&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla)	humresults[i][j]+=33; 
				if(board[m-5][n+5]==com&&board[m-4][n+4]==pla&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla)	humresults[i][j]+=33; 
			
			//       @oxxo*
				if(board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==pla&&board[m+5][n]==com)	humresults[i][j]+=33;
				if(board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==pla&&board[m][n+5]==com)  humresults[i][j]+=33;
				if(board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==pla&&board[m+5][n+5]==com) humresults[i][j]+=33;
				if(board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==pla&&board[m+5][n-5]==com) humresults[i][j]+=33;
			
			//�ĤQ�ر���   *@ooxx
				if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0&&board[m+4][n]<0) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0&&board[m][n+4]<0)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]<0) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0&&board[m+4][n-4]<0) humresults[i][j]+=33;
			
			
			//			xxoo@*
				if(board[m-4][n]<0&&board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=33; 
			//�ĤQ�@�ر���  *o@oxx
				  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0)	humresults[i][j]+=33;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	humresults[i][j]+=33;
			
			
			// 		xxo@o*
				 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=33; 
			
			//�ĤQ�G�ر��� *oo@xx
				 if(board[m-3][n]==com&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0)	humresults[i][j]+=33; 
				 if(board[m][n-3]==com&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]==com&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]==com&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0)	humresults[i][j]+=33; 
			
			
			
			
			//			xx@oo*
				  if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==com)	humresults[i][j]+=33;  
				  if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==com)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==com)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==com)	humresults[i][j]+=33;
			
		
			
			
			
			
			
			
			
			
			//�ĤQ�T�ر���  *x@oox* 
			if(board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0&&board[m+4][n]==com)	humresults[i][j]+=33;
			if(board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0&&board[m][n+4]==com)  humresults[i][j]+=33;
			if(board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]==com) humresults[i][j]+=33;
			if(board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0&&board[m+4][n-4]==com) humresults[i][j]+=33;
			
			
			
			//			*xoo@x*
			
			
			//�ĤQ�|�ر���  *xo@ox*
	
			
			if(board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==com)	humresults[i][j]+=33;
			if(board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==com)	humresults[i][j]+=33;
			if(board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==com)	humresults[i][j]+=33;
			if(board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==com)	humresults[i][j]+=33;
		
		
		
	}
	
	
	
}

void Gobang::a_two(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){  
		//�Ĥ@�ر���   xx@oxx   
		if(board[m][n]==com){			
		           
                    
                    //  xx@oxx
                    if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0) comresults[i][j]+=50;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0) comresults[i][j]+=50;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0) comresults[i][j]+=50;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0) comresults[i][j]+=50;
                   
                   
                   //  xxo@xx
                     if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0) comresults[i][j]+=50;
                   if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0) comresults[i][j]+=50;
                   if(board[m-3][n-3]&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0) comresults[i][j]+=50;
                   if(board[m-3][n+3]&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0) comresults[i][j]+=50;
                    
                    
     }
     if(board[m][n]==pla){
                     //  xx@oxx
                    if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0) humresults[i][j]+=50;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0) humresults[i][j]+=50;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0) humresults[i][j]+=50;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0) humresults[i][j]+=50;
                   
                   
                   //  xxo@xx
                   if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0) humresults[i][j]+=50;
                   if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0) humresults[i][j]+=50;
                   if(board[m-3][n-3]&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0) humresults[i][j]+=50;
                  if(board[m-3][n+3]&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0) humresults[i][j]+=50;
         }
         
         
         
                    //�ĤG����?   xx@xox   
    if(board[m][n]==com){
                 
                    
                     //  xx@xox
                    if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]<0) comresults[i][j]+=5;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]<0) comresults[i][j]+=5;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]<0) comresults[i][j]+=5;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]<0) comresults[i][j]+=5;
                   
                   
                   //  xox@xx
                     if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]<0) comresults[i][j]+=5;
                   if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]<0) comresults[i][j]+=5;
                   if(board[m-3][n-3]&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]<0) comresults[i][j]+=5;
                   if(board[m-3][n+3]&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]<0) comresults[i][j]+=5;
                   
                   
         }
         if(board[m][n]==pla){
                      //  xx@xox
                    if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]<0) humresults[i][j]+=5;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]<0) humresults[i][j]+=5;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]<0) humresults[i][j]+=5;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]<0) humresults[i][j]+=5;
                   
                   
                   //  xox@xx
                     if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]<0) humresults[i][j]+=5;
                   if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]<0) humresults[i][j]+=5;
                   if(board[m-3][n-3]&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]<0) humresults[i][j]+=5;
                   if(board[m-3][n+3]&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]<0) humresults[i][j]+=5;
                      
                    }  
  


}

void Gobang::a_blocktwo(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){  
		
		
			//�Ĥ@�ر���   xx@o*x   
		if(board[m][n]==com){			
		             //  xx@o*
                    if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==pla) comresults[i][j]+=5;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==pla) comresults[i][j]+=5;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==pla) comresults[i][j]+=5;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==pla) comresults[i][j]+=5;
                   
                   
                   //  *o@xx
                     if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0) comresults[i][j]+=5;
                   if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0) comresults[i][j]+=5;
                   if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0) comresults[i][j]+=5;
                   if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0) comresults[i][j]+=5;
     }
        if(board[m][n]==pla){
                     //  xx@o*
                    if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==com) humresults[i][j]+=5;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==com) humresults[i][j]+=5;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==com) humresults[i][j]+=5;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==com) humresults[i][j]+=5;
                   
                   
                   //  *o@xx
                     if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0) humresults[i][j]+=5;
                   if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0) humresults[i][j]+=5;
                   if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0) humresults[i][j]+=5;
                   if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0) humresults[i][j]+=5;
         }
		



	//�ĤG�ر���   xxo@*x   
		if(board[m][n]==com){			
		              //  xxo@*
                    if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=5;
                   if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==pla) comresults[i][j]+=5;
                   if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=5;
                   if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=5;
                   
                   
                   //  *@oxx
                     if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0) comresults[i][j]+=5;
                   if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0) comresults[i][j]+=5;
                   if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0) comresults[i][j]+=5;
                   if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0) comresults[i][j]+=5;
                   
                   
     }
        if(board[m][n]==pla){
                      //  xxo@*
                    if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==com) comresults[i][j]+=5;
                   if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==com) comresults[i][j]+=5;
                   if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) comresults[i][j]+=5;
                   if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) comresults[i][j]+=5;
                   
                   
                   //  *@oxx
                     if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0) comresults[i][j]+=5;
                   if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0) comresults[i][j]+=5;
                   if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0) comresults[i][j]+=5;
                   if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0) comresults[i][j]+=5;
                   
         }


}


void Gobang::a_one(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){  
 				
				 
				 //�Ĥ@�� 
 if(board[m][n]==com){
				//		xx@xx
                   if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]<0) comresults[i][j]+=10;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]<0) comresults[i][j]+=10;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]<0) comresults[i][j]+=10;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]<0) comresults[i][j]+=10;
                  
                
                   
                      
                      
                  }
 else if(board[m][n]==pla){
                  	
				  if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]<0) humresults[i][j]+=10;
                   if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]<0) humresults[i][j]+=10;
                   if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]<0) humresults[i][j]+=10;
                   if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]<0) humresults[i][j]+=10;

  }
}

void Gobang::a_blockone(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){
	
	 //�@����  x*@xx  
                    if(board[m][n]==com){
					
                   if(board[m+1][n]==pla&&board[m-1][n]<0&&board[m-2][n]<0) comresults[i][j]+=1;
                   if(board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0) comresults[i][j]+=1;
                   if(board[m][n+1]==pla&&board[m][n-1]<0&&board[m][n-2]<0) comresults[i][j]+=1;
                   if(board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0) comresults[i][j]+=1;
                   if(board[m+1][n+1]==pla&&board[m-1][n-1]<0&&board[m-2][n-2]<0) comresults[i][j]+=1;
                   if(board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0) comresults[i][j]+=1;
                   if(board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0) comresults[i][j]+=1;
                   if(board[m+1][n-1]==pla&&board[m-1][n+1]<0&&board[m-2][n+2]<0) comresults[i][j]+=1;
                
                   
                      
                      
                 }
                  else if(board[m][n]==pla){
                  	
				  if(board[m+1][n]==com&&board[m-1][n]<0&&board[m-2][n]<0) humresults[i][j]+=1;
                   if(board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0) humresults[i][j]+=1;
                   if(board[m][n+1]==com&&board[m][n-1]<0&&board[m][n-2]<0) humresults[i][j]+=1;
                   if(board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0) humresults[i][j]+=1;
                   if(board[m+1][n+1]==com&&board[m-1][n-1]<0&&board[m-2][n-2]<0) humresults[i][j]+=1;
                   if(board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0) humresults[i][j]+=1;
                   if(board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0) humresults[i][j]+=1;
                   if(board[m+1][n-1]==com&&board[m-1][n+1]<0&&board[m-2][n+2]<0) humresults[i][j]+=1;
					
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
void Gobang::multiplayer(int pla){//, �մѥ��U 
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
     cout<<"�����a�U:\n";
    
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
        if(whosturn == 1){cout <<"�´�Ĺ�F�I"<< endl;}else{cout <<"�մ�Ĺ�F�I"<< endl;} 
     } 
     */ 
} 
