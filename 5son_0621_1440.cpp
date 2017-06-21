
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
void default_board();//初始化棋盤15x15 
void show_board();//顯示棋盤15x15 
void put_chess(short,short,short);//下棋+判斷有無棋子 
bool winner(short i,short j,short whosturn);//勝負 win = 1 勝利 
void go(int n) ; // 遊戲開始 
void multiplayer();//兩個玩家, 黑棋先下 

*/


struct Node
{
    int x ;//行坐標 
    int y ;//列坐標 
    int value ;//在此節點下完后的估計值
    int win ;//走了一步棋后是否能贏，1代表贏，0即不贏也不輸，-1輸了
    bool operator < ( const Node aNode ) const
    {
        return this->value > aNode.value ;
    }
} ;

class Search
{
public:
    Search( int depth , int numOfGoodNodes , short chessBoard[ 17 ][ 17 ] ) ;
    void search_several_good_nodes(int com,int pla, short board[ 17 ][ 17 ] , Node* goodNodeArray  , int numGoodNodes  ) ;//貪心法先找出幾個比較好的
    int alphaBetaSearch( int depth , int alpha , int beta , int player,int rival ) ; //alpha-beta剪枝搜索算法
    bool win( int x , int y , int player,int rival ) ;//判斷能否勝利 
    Node bestMove ; //下一步要走的地方
	bool generator(int com,int pla,int I ,int J,short boar[17][17]);
    int depth ; //搜索的深度
    int numOfGoodNodes ; //幾個比較好的點的個數，以減小收縮的复雜度
 //   Gobang evaluator ;
    short chessBoard[ 17 ][ 17 ] ;//棋盤狀態 
};













//class of  computer
int com_choose=100;  //電腦選先手後手 
int I2,J2,I3,J3;
int ccc=0,ppp=0;
class Gobang{  
        
      public:   
                
             short board[17][17];          //棋盤  
              int five[5][5];                  //5*5小棋?   
             int six[6][6];
           	 bool endtry;
             int computernum,humannum;         //棋子   
             int p1,p2; 
			                       //棋子   
             int last1,last2;                    //紀錄上一步    
             int comresults[15][15];             //存分數  
             int humresults[15][15];  
             int temp[15][15];             //15x15臨時棋 盤 
             int max_com,max_hum,max_com_i,max_com_j,max_hum_i,max_hum_j;             
             int total_com,total_hum;              //電腦和玩家總分   
             int getValue(int player,int rival , short board[17][17] , int *whether_win,int i,int j );
     
     		 
              void default_board();//初始化棋盤15x15 
			  void show_board();//顯示棋盤15x15 
			  void put_chess(short,short,short);//下棋+判斷有無棋子 
			  bool winner(short i,short j,short whosturn);//勝負 win = 1 勝利 
			  void go(int COMI2,int COMJ2,int COMI3,int COMJ3) ; // 遊戲開始 
			  void multiplayer(int pla);//兩個玩家, 黑棋先下 	
              Gobang();  
              void setboard(int ,int,int);     //改變棋子   
              void count(int com,int pla);                         //記數，棋子數   
            //  void count_total();                //算總分   
			  bool generator(int com,int pla,int I,int J); 
 
			void getfive(int i,int j,short board[17][17]);             // 讀取數據，存入5*5 的棋盤中   
            
              void getsix(int,int);  
              int ifwin(int com,int pla,short board[17][17]);                     //判斷勝負        
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










//构造函數。depth：搜索深度；numOfGoodNodes：每一步搜，即搜索寬度；board：棋盤 
Search::Search( int depth , int numOfGoodNodes , short chessBoard[ 17 ][ 17 ] )
{
   // evaluator = Gobang() ;
    this->depth = depth ;
    this->numOfGoodNodes = numOfGoodNodes ;
    //初始化bestMove
    bestMove.x = bestMove.y = - 1 ;
    bestMove.value = 0 ;
    bestMove.win = 0 ;

    //?棋??值
    for( int i = 0 ; i < 17 ; i ++ )
    {
        for ( int j = 0 ; j <17 ; j ++ )
        {
            this->chessBoard[ i ][ j ] = chessBoard[ i ][ j ] ;
        }
    }
}

//?心法先找出numGoodNodes分數比較好的
void Search::search_several_good_nodes(int player,int rival, short board[ 17 ][17 ] , Node* goodNodeArray  , int numGoodNodes )
{
    int countGood = 0 ; //??goodNodeArray??里?已?存了多少?
	Gobang evaluator;
    Node tmpNode ; //???量
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

                //按估值由大至小的?序找出最好的numGoodNodes???
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

//alpha-beta?枝搜索算法
int Search::alphaBetaSearch( int search_depth , int alpha , int beta ,int player,int rival )
{	
    int score,temp ;//估值結果
    Node *goodNodes = new Node[ numOfGoodNodes ] ;
    Node *badNodes = new Node[ 1 ] ;
    badNodes[ 0 ].x = badNodes[ 0 ].y = badNodes[ 0 ].win = 0 ;
    search_several_good_nodes(  player, rival , chessBoard , goodNodes , numOfGoodNodes  ) ;
    search_several_good_nodes( (player==ccc) ? rival : player , (player==ccc) ?  player : rival , chessBoard , badNodes , 1 ) ;

   //如果?了，不可能再在此基礎上下下去
    if ( goodNodes[ 0 ].win == 100 )
    {
        if ( search_depth == 1)
        {
            bestMove.x = goodNodes[ 0 ].x ;
            bestMove.y = goodNodes[ 0 ].y ;
        }
        return goodNodes[ 0 ].value ;
    }
    //自己不下，敵贏，所以下一步得走在?方的一步上
    if ( badNodes[ 0 ].win == 100 )
    {
        if ( search_depth == 1 )
        {
            bestMove.x = badNodes[ 0 ].x ;
            bestMove.y = badNodes[ 0 ].y ;
        }

        return badNodes[ 0 ].value ;
    }
		
    //搜索到了最后一層，返回
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

























































//開始遊戲//
#define width 5
#define depth 3
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
             	ccc=1;
             	ppp=2;
             	player=2;
             	computer=1;
             	last1=I3-1;
				last2=J3-1;
             	system("pause");
			 }
			 else if(com_choose==1){
			 	cout<<"電腦選了白子\n"; 
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
                                cout<<"電腦勝利！"<<endl;   
                              break;  
                              }  
              if(ifwin(computer,player,board)==2){ 
			  					system("cls");  
                              show_board(); 
                              cout<<"玩家勝利！"<<endl;  
                              break;  
                              }   
              
             system("cls");
             show_board();
            cout<<"電腦下了 "<<last1+1<<" "<<last2+1<<"\n"; 
             system("pause");
             multiplayer(player);   
      
              if(ifwin(computer,player,board)==computer) { 
              					system("cls"); 
                               show_board();  
                              cout<<"電腦勝利！"<<endl;  
                              break;  
                              }  
              if(ifwin(computer,player,board)==player){  
              					system("cls"); 
                              show_board();  
                              cout<<"玩家勝利！"<<endl;  
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




  
//計算電腦和玩家得分   
   








  
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
     //首先判斷是否可以下一子就立即成五   
   
   /*    for(int i=0;i<15;i++){  
         for(int j=0;j<15;j++){  
                 if(board[i+1][j+1]>0) continue;       //找空位   
                  temp=board[i+1][j+1];
                  board[i+1][j+1]=ccc;  
                  if(ifwin(ccc,ppp)==ccc) {last1=i;last2=j; return 4000000;}                  //???   
                  board[i+1][j+1]=temp;                      //用的位置不下子 
				    
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
    //如果我方五?，我方勝
    if ( ifwin(ccc,ppp,board)==ccc )
    {
        *whether_win = 100 ;
        return 4000000 ;
    }
    //如果對方活四或沖四，方
    if ( plf>0 ||pbf>0 )
    {
        *whether_win = -1 ;
        return -3200000 ;
    }
    //我方活四，?我方?
    if ( clf>0 )
    {
        *whether_win = 100 ;
        return 1800000 ;
    }
    //如果我方的眠四和活三之和大于等于2，?我方?
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
			
			//第一種情形  *@ooox
			if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]<0)	comresults[i][j]+=250;  cbf++;
			if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=250;    cbf++;
			if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=250;  cbf++;  
			if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]<0) comresults[i][j]+=250;  cbf++;
			
			//  		xooo@*
			if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=250;  cbf++;   
            if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=250;  cbf++; 				
            if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=250 ; 	
			if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=250;  cbf++; 	
			
			
			//第二種情形   *o@oox
				  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0)	comresults[i][j]+=250;  cbf++;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0)	comresults[i][j]+=250;  cbf++; 
			
			//			xoo@o*
				 if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=250;  cbf++; 
			
			
			//第三種情形   *oo@ox
				 if(board[m-3][n]==pla&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-3]==pla&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n-3]==pla&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-3][n+3]==pla&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0)	comresults[i][j]+=250;  cbf++; 
			
			//			xo@oo*
				  if(board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==pla)	comresults[i][j]+=250;  cbf++;  
				  if(board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==pla)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==pla)	comresults[i][j]+=250;  cbf++;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==pla)	comresults[i][j]+=250;  cbf++; 
			
			
			
			//第四種情形 *ooo@x
				  if(board[m-4][n]==pla&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0) comresults[i][j]+=250;  cbf++; 	
			
			//			x@ooo*
				if(board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]==pla)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]==pla)  comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]==pla) comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]==pla) comresults[i][j]+=250;  cbf++;
			
			
			
			
			//第五種情形		@ooxo
				if(board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0&&board[m+4][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0&&board[m][n+4]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0&&board[m+4][n-4]==com) comresults[i][j]+=250;  cbf++;
			
			//				oxoo@
				  if(board[m-4][n]==com&&board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com) comresults[i][j]+=250;  cbf++; 
			
			//第六種情形   		o@oxo
			
				if(board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==com) comresults[i][j]+=250;  cbf++;
			//				oxo@o
				  if(board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com) comresults[i][j]+=250 ; 	
				  if(board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com) comresults[i][j]+=250;  cbf++; 	
			
			
			
			
			//第七種情形		oo@xo
				 if(board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]==com)	comresults[i][j]+=250;  cbf++; 
			
			
			//				ox@oo
				if(board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com)	comresults[i][j]+=250;  cbf++; 
				 if(board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com)	comresults[i][j]+=250;  cbf++; 
			
			//第八種情形		ooox@
				  if(board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]<0) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]<0)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]<0) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]<0) comresults[i][j]+=250;  cbf++; 
			
			
			//			@xooo
			
				if(board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]==com) comresults[i][j]+=250;  cbf++;
			
			
			
			
			
			//第九種情形	@oxoo
				
				
				if(board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==com)	comresults[i][j]+=250;  cbf++;
			    if(board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==com)  comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==com) comresults[i][j]+=250;  cbf++;
			    if(board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==com) comresults[i][j]+=250;  cbf++;
			//				ooxo@
				  if(board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==com) comresults[i][j]+=250;  cbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==com)  comresults[i][j]+=250;  cbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==com) comresults[i][j]+=250 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==com) comresults[i][j]+=250;  cbf++; 
			
			//第十種情形	o@xoo
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
				
			//第一種情形  *@ooox
			if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]<0)	humresults[i][j]+=1000;  pbf++;
			if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=1000;  pbf++;
			if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=1000;  pbf++;
			if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]<0) humresults[i][j]+=1000;  pbf++;
			
			//  		xooo@*
			if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=1000;  pbf++;   
            if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=1000;  pbf++; 				
            if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=1000 ; 	
			if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=1000;  pbf++; 	
			
			
			//第二種情形   *o@oox
				  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=1000;  pbf++; 
			
			//			xoo@o*
				 if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=1000;  pbf++; 
			
			
			//第三種情形   *oo@ox
				 if(board[m-3][n]==com&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-3]==com&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n-3]==com&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-3][n+3]==com&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0)	humresults[i][j]+=1000;  pbf++; 
			
			//			xo@oo*
				  if(board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==com)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==com)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==com)	humresults[i][j]+=1000;  pbf++;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==com)	humresults[i][j]+=1000;  pbf++; 
			
			
			
			//第四種情形 *ooo@x
				  if(board[m-4][n]==com&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==com&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==com&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==com&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0) humresults[i][j]+=1000;  pbf++; 	
			
			//			x@ooo*
				if(board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]==com)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]==com)  humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]==com) humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]==com) humresults[i][j]+=1000;  pbf++;
			
			
			
			
			//第五種情形		@ooxo
				if(board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0&&board[m+4][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0&&board[m][n+4]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0&&board[m+4][n-4]==pla) humresults[i][j]+=1000;  pbf++;
			
			//				oxoo@
				  if(board[m-4][n]==pla&&board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla) humresults[i][j]+=1000;  pbf++; 
			
			//第六種情形   		o@oxo
			
				if(board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==pla) humresults[i][j]+=1000;  pbf++;
			//				oxo@o
				  if(board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla) humresults[i][j]+=1000 ; 	
				  if(board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla) humresults[i][j]+=1000;  pbf++; 	
			
			
			
			
			//第七種情形		oo@xo
				 if(board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]==pla)	humresults[i][j]+=1000;  pbf++; 
			
			
			//				ox@oo
				if(board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla)	humresults[i][j]+=1000;  pbf++; 
				 if(board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla)	humresults[i][j]+=1000;  pbf++; 
			
			//第八種情形		ooox@
				  if(board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]<0) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]<0)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]<0) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]<0) humresults[i][j]+=1000;  pbf++; 
			
			
			//			@xooo
			
				if(board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla) humresults[i][j]+=1000;  pbf++;
			
			
			
			
			
			//第九種情形	@oxoo
				
				
				if(board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==pla)	humresults[i][j]+=1000;  pbf++;
			    if(board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==pla)  humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla) humresults[i][j]+=1000;  pbf++;
			    if(board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla) humresults[i][j]+=1000;  pbf++;
			//				ooxo@
				  if(board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==pla) humresults[i][j]+=1000;  pbf++;   
            	  if(board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==pla)  humresults[i][j]+=1000;  pbf++; 				
            	  if(board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==pla) humresults[i][j]+=1000 ; 	
				  if(board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==pla) humresults[i][j]+=1000;  pbf++; 
			
			//第十種情形	o@xoo
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
     			//第一種情形    x@ooxx    	//第二種情形			  xx@oox
               
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
				
				
			
				
				
                 //第三種情形   xxo@oxx         06/10
                
                 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0)	comresults[i][j]+=333;  ++clt; 
                 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0)	comresults[i][j]+=333;  ++clt; 
                 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	comresults[i][j]+=333;  ++clt; 
                 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	comresults[i][j]+=333;  ++clt; 
                
                
                
                
                
                   
                 //第四種情形  x@xoox   
                   
                if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]<0) comresults[i][j]+=333;  ++clt;   
                if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=333;	++clt;			
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=333;  ++clt;	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]<0) comresults[i][j]+=333;  ++clt;
                 	
                 	// xoox@x
                 	
                if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]<0) comresults[i][j]+=333;  ++clt;   
                if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]<0)  comresults[i][j]+=333;  ++clt; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]<0) comresults[i][j]+=333; 	++clt;
				if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]<0) comresults[i][j]+=333;  ++clt; 	
                 	
                   
                 //第五種情形    xox@ox  
                   
                 if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]<0)	comresults[i][j]+=333;  ++clt; 
				 if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]<0)	comresults[i][j]+=333;  ++clt; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]<0)	comresults[i][j]+=333;  ++clt; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]<0)	comresults[i][j]+=333;  ++clt; 
                   
                   
                   
                   //    		xo@xox
                  if(board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]<0)	comresults[i][j]+=333;  ++clt;  
				  if(board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]<0)	comresults[i][j]+=333;  ++clt;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]<0)	comresults[i][j]+=333;  ++clt;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]<0)	comresults[i][j]+=333;  ++clt;  
                   
                 //第六種情形    xoxo@x  
                   
                   
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
				
			
			
			
				//第一種情形    x@ooxx  
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
				
				
				
				
				
				
                 //第三種情形   xxo@oxx         06/10
                
                 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0)	humresults[i][j]+=1000; 
                 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0)	humresults[i][j]+=1000; 
                 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	humresults[i][j]+=1000; 
                 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	humresults[i][j]+=1000; 
                
                
                
                
                
                   
                 //第四種情形  x@xoox   
                   
                if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]<0) humresults[i][j]+=1000;   
                if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=1000 ;				
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=1000 ; 	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]<0) humresults[i][j]+=1000;
                 	
                 	// xoox@x
                 	
                if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]<0) humresults[i][j]+=1000;   
                if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]<0)  humresults[i][j]+=1000 ;				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]<0) humresults[i][j]+=1000 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]<0) humresults[i][j]+=1000 ;	
                 	
                   
                 //第五種情形    xox@ox  
                   
                 if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]<0)	humresults[i][j]+=1000; 
				 if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]<0)	humresults[i][j]+=1000; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]<0)	humresults[i][j]+=1000; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]<0)	humresults[i][j]+=1000; 
                   
                   
                   
                   //    		xo@xox
                   if(board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=1000;  
				  if(board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=1000;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=1000;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=1000;  
                   
                 //第六種情形    xoxo@x  
                   
                   
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
		
		
			//第一種情形    *@oxox
				if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]<0) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]<0)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]<0) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]<0) comresults[i][j]+=33;
				
				
			//	xoxo@*
				if(board[m-4][n]<0&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
			
			
			
			//第二種情形   *o@xox
			 	  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]<0)	comresults[i][j]+=33;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]<0)	comresults[i][j]+=33;  
			
			
			
			     //  xox@o*
			     if(board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=33; 
			
			
			
			
			//第三種情形   *oox@x
				if(board[m-4][n]==pla&&board[m-3][n]==com&&board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]<0) comresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]==com&&board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]<0)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]==com&&board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]<0) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]==com&&board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]<0) comresults[i][j]+=33; 
				
				
				
				//		x@xoo*
				if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==com&&board[m+3][n]==com&&board[m+4][n]==pla) comresults[i][j]+=33; 
			    if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==com&&board[m][n+3]==com&&board[m][n+4]==pla)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==com&&board[m+3][n+3]==com&&board[m+4][n+4]==pla) comresults[i][j]+=33;	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==com&&board[m+3][n-3]==com&&board[m+4][n-4]==pla) comresults[i][j]+=33;
				
				
				
				
				
			//第四種情形    *@oxxo
				if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==com) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==com)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==com) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==com) comresults[i][j]+=33;
				//			oxxo@*		
				if(board[m-4][n]==com&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
				
			//第五種情形   *o@xxo
				  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com)	comresults[i][j]+=33;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com)	comresults[i][j]+=33;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com)	comresults[i][j]+=33;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com)	comresults[i][j]+=33; 
				  
				  
				//			oxx@o*
				 if(board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=33; 
				 if(board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=33; 
				
			//第六種情形  *ooxx@
				if(board[m-5][n]==pla&&board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0)	comresults[i][j]+=33; 
				if(board[m][n-5]==pla&&board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0)	comresults[i][j]+=33; 
				if(board[m-5][n-5]==pla&&board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0)	comresults[i][j]+=33; 
				if(board[m-5][n+5]==pla&&board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0)	comresults[i][j]+=33; 
			
				// 			@xxoo*
				if(board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==com&&board[m+5][n]==pla)	comresults[i][j]+=33;
				if(board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==com&&board[m][n+5]==pla)  comresults[i][j]+=33;
				if(board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==com&&board[m+5][n+5]==pla) comresults[i][j]+=33;
				if(board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==com&&board[m+5][n-5]==pla) comresults[i][j]+=33;
				
				
				
				
			//第七種情形  *@xxoo
				if(board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==com) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==com)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==com) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==com) comresults[i][j]+=33;
			
				//   ooxx@*
				if(board[m-4][n]==com&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
			
			
			
			
			
			//第八種情形   *oxx@o
				if(board[m-4][n]==pla&&board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com) comresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com) comresults[i][j]+=33; 
			
			
				//       o@xxo*
				if(board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==com&&board[m+4][n]==pla) comresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==com&&board[m][n+4]==pla)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==com&&board[m+4][n+4]==pla) comresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==com&&board[m+4][n-4]==pla) comresults[i][j]+=33;
				
				
				
			//第九種情形   *oxxo@
				if(board[m-5][n]==pla&&board[m-4][n]==com&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com)	comresults[i][j]+=33; 
				if(board[m][n-5]==pla&&board[m][n-4]==com&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com)	comresults[i][j]+=33; 
				if(board[m-5][n-5]==pla&&board[m-4][n-4]==com&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com)	comresults[i][j]+=33; 
				if(board[m-5][n+5]==pla&&board[m-4][n+4]==com&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com)	comresults[i][j]+=33; 
			
			//       @oxxo*
				if(board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==com&&board[m+5][n]==pla)	comresults[i][j]+=33;
				if(board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==com&&board[m][n+5]==pla)  comresults[i][j]+=33;
				if(board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==com&&board[m+5][n+5]==pla) comresults[i][j]+=33;
				if(board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==com&&board[m+5][n-5]==pla) comresults[i][j]+=33;
			
			//第十種情形   *@ooxx
				if(board[m-1][n]==pla&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0&&board[m+4][n]<0) comresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0&&board[m][n+4]<0)  comresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]<0) comresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0&&board[m+4][n-4]<0) comresults[i][j]+=33;
			
			
			//			xxoo@*
				if(board[m-4][n]<0&&board[m-3][n]<0&&board[m-2][n]==com&&board[m-1][n]==com&&board[m+1][n]==pla) comresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]<0&&board[m][n-2]==com&&board[m][n-1]==com&&board[m][n+1]==pla)  comresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]<0&&board[m-2][n-2]==com&&board[m-1][n-1]==com&&board[m+1][n+1]==pla) comresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]<0&&board[m-2][n+2]==com&&board[m-1][n+1]==com&&board[m+1][n-1]==pla) comresults[i][j]+=33; 
			//第十一種情形  *o@oxx
				  if(board[m-2][n]==pla&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]<0)	comresults[i][j]+=33;  
				  if(board[m][n-2]==pla&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n-2]==pla&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	comresults[i][j]+=33;  
				  if(board[m-2][n+2]==pla&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	comresults[i][j]+=33;
			
			
			// 		xxo@o*
				 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]==pla)	comresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]==pla)	comresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]==pla)	comresults[i][j]+=33; 
			
			//第十二種情形 *oo@xx
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
			
			
			
			
			
			
			
			
			
			//第十三種情形  *x@oox* 
			if(board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==com&&board[m+2][n]==com&&board[m+3][n]<0&&board[m+4][n]==pla)	comresults[i][j]+=33;
			if(board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==com&&board[m][n+2]==com&&board[m][n+3]<0&&board[m][n+4]==pla)  comresults[i][j]+=33;
			if(board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==com&&board[m+2][n+2]==com&&board[m+3][n+3]<0&&board[m+4][n+4]==pla) comresults[i][j]+=33;
			if(board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==com&&board[m+2][n-2]==com&&board[m+3][n-3]<0&&board[m+4][n-4]==pla) comresults[i][j]+=33;
			
			
			
			//			*xoo@x*
			
			
			//第十四種情形  *xo@ox*
	
			
			if(board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==com&&board[m+1][n]==com&&board[m+2][n]<0&&board[m+3][n]==pla)	comresults[i][j]+=33;
			if(board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==com&&board[m][n+1]==com&&board[m][n+2]<0&&board[m][n+3]==pla)	comresults[i][j]+=33;
			if(board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==com&&board[m+1][n+1]==com&&board[m+2][n+2]<0&&board[m+3][n+3]==pla)	comresults[i][j]+=33;
			if(board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==com&&board[m+1][n-1]==com&&board[m+2][n-2]<0&&board[m+3][n-3]==pla)	comresults[i][j]+=33;
	
	
	}
	else if(board[m][n]==pla){
		
		
			//第一種情形    *@oxox
				if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]<0) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]<0)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]<0) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]<0) humresults[i][j]+=33;
				
				
			//	xoxo@*
				if(board[m-4][n]<0&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=33; 
			
			
			
			//第二種情形   *o@xox
			 	  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]<0)	humresults[i][j]+=33;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]<0)	humresults[i][j]+=33;  
			
			
			
			     //  xox@o*
			     if(board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=33; 
			
			
			
			
			//第三種情形   *oox@x
				if(board[m-4][n]==com&&board[m-3][n]==pla&&board[m-2][n]==pla&&board[m-1][n]<0&&board[m+1][n]<0) humresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]==pla&&board[m][n-2]==pla&&board[m][n-1]<0&&board[m][n+1]<0)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]==pla&&board[m-2][n-2]==pla&&board[m-1][n-1]<0&&board[m+1][n+1]<0) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]==pla&&board[m-2][n+2]==pla&&board[m-1][n+1]<0&&board[m+1][n-1]<0) humresults[i][j]+=33; 
				
				
				
				//		x@xoo*
				if(board[m-1][n]<0&&board[m+1][n]<0&&board[m+2][n]==pla&&board[m+3][n]==pla&&board[m+4][n]==com) humresults[i][j]+=33; 
			    if(board[m][n-1]<0&&board[m][n+1]<0&&board[m][n+2]==pla&&board[m][n+3]==pla&&board[m][n+4]==com)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]<0&&board[m+1][n+1]<0&&board[m+2][n+2]==pla&&board[m+3][n+3]==pla&&board[m+4][n+4]==com) humresults[i][j]+=33;	
				if(board[m-1][n+1]<0&&board[m+1][n-1]<0&&board[m+2][n-2]==pla&&board[m+3][n-3]==pla&&board[m+4][n-4]==com) humresults[i][j]+=33;
				
				
				
				
				
			//第四種情形    *@oxxo
				if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==pla) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==pla)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==pla) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==pla) humresults[i][j]+=33;
				//			oxxo@*		
				if(board[m-4][n]==pla&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=33; 
				
			//第五種情形   *o@xxo
				  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla)	humresults[i][j]+=33;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla)	humresults[i][j]+=33; 
				  
				  
				//			oxx@o*
				 if(board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=33; 
				 if(board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=33; 
				
			//第六種情形  *ooxx@
				if(board[m-5][n]==com&&board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0)	humresults[i][j]+=33; 
				if(board[m][n-5]==com&&board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0)	humresults[i][j]+=33; 
				if(board[m-5][n-5]==com&&board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0)	humresults[i][j]+=33; 
				if(board[m-5][n+5]==com&&board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0)	humresults[i][j]+=33; 
			
				// 			@xxoo*
				if(board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==pla&&board[m+5][n]==com)	humresults[i][j]+=33;
				if(board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==pla&&board[m][n+5]==com)  humresults[i][j]+=33;
				if(board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla&&board[m+5][n+5]==com) humresults[i][j]+=33;
				if(board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla&&board[m+5][n-5]==com) humresults[i][j]+=33;
				
				
				
				
			//第七種情形  *@xxoo
				if(board[m-1][n]==com&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==pla) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==pla)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==pla) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==pla) humresults[i][j]+=33;
			
				//   ooxx@*
				if(board[m-4][n]==pla&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]==pla&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==pla&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==pla&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==com) humresults[i][j]+=33; 
			
			
			
			
			
			//第八種情形   *oxx@o
				if(board[m-4][n]==com&&board[m-3][n]==pla&&board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla) humresults[i][j]+=33;   
                if(board[m][n-4]==com&&board[m][n-3]==pla&&board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]==com&&board[m-3][n-3]==pla&&board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]==com&&board[m-3][n+3]==pla&&board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla) humresults[i][j]+=33; 
			
			
				//       o@xxo*
				if(board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0&&board[m+3][n]==pla&&board[m+4][n]==com) humresults[i][j]+=33; 
			    if(board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0&&board[m][n+3]==pla&&board[m][n+4]==com)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0&&board[m+3][n+3]==pla&&board[m+4][n+4]==com) humresults[i][j]+=33;	
				if(board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0&&board[m+3][n-3]==pla&&board[m+4][n-4]==com) humresults[i][j]+=33;
				
				
				
			//第九種情形   *oxxo@
				if(board[m-5][n]==com&&board[m-4][n]==pla&&board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla)	humresults[i][j]+=33; 
				if(board[m][n-5]==com&&board[m][n-4]==pla&&board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla)	humresults[i][j]+=33; 
				if(board[m-5][n-5]==com&&board[m-4][n-4]==pla&&board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla)	humresults[i][j]+=33; 
				if(board[m-5][n+5]==com&&board[m-4][n+4]==pla&&board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla)	humresults[i][j]+=33; 
			
			//       @oxxo*
				if(board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0&&board[m+4][n]==pla&&board[m+5][n]==com)	humresults[i][j]+=33;
				if(board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0&&board[m][n+4]==pla&&board[m][n+5]==com)  humresults[i][j]+=33;
				if(board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0&&board[m+4][n+4]==pla&&board[m+5][n+5]==com) humresults[i][j]+=33;
				if(board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0&&board[m+4][n-4]==pla&&board[m+5][n-5]==com) humresults[i][j]+=33;
			
			//第十種情形   *@ooxx
				if(board[m-1][n]==com&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0&&board[m+4][n]<0) humresults[i][j]+=33; 
			    if(board[m][n-1]==com&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0&&board[m][n+4]<0)  humresults[i][j]+=33 ;				
                if(board[m-1][n-1]==com&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]<0) humresults[i][j]+=33;	
				if(board[m-1][n+1]==com&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0&&board[m+4][n-4]<0) humresults[i][j]+=33;
			
			
			//			xxoo@*
				if(board[m-4][n]<0&&board[m-3][n]<0&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]==com) humresults[i][j]+=33;   
                if(board[m][n-4]<0&&board[m][n-3]<0&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]==com)  humresults[i][j]+=33; 				
                if(board[m-4][n-4]<0&&board[m-3][n-3]<0&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]==com) humresults[i][j]+=33 ; 	
				if(board[m-4][n+4]<0&&board[m-3][n+3]<0&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]==com) humresults[i][j]+=33; 
			//第十一種情形  *o@oxx
				  if(board[m-2][n]==com&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]<0)	humresults[i][j]+=33;  
				  if(board[m][n-2]==com&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]==com&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]<0)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]==com&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]<0)	humresults[i][j]+=33;
			
			
			// 		xxo@o*
				 if(board[m-3][n]<0&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]==com)	humresults[i][j]+=33; 
				 if(board[m][n-3]<0&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]<0&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]==com)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]<0&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]==com)	humresults[i][j]+=33; 
			
			//第十二種情形 *oo@xx
				 if(board[m-3][n]==com&&board[m-2][n]==pla&&board[m-1][n]==pla&&board[m+1][n]<0&&board[m+2][n]<0)	humresults[i][j]+=33; 
				 if(board[m][n-3]==com&&board[m][n-2]==pla&&board[m][n-1]==pla&&board[m][n+1]<0&&board[m][n+2]<0)	humresults[i][j]+=33; 
				 if(board[m-3][n-3]==com&&board[m-2][n-2]==pla&&board[m-1][n-1]==pla&&board[m+1][n+1]<0&&board[m+2][n+2]<0)	humresults[i][j]+=33; 
				 if(board[m-3][n+3]==com&&board[m-2][n+2]==pla&&board[m-1][n+1]==pla&&board[m+1][n-1]<0&&board[m+2][n-2]<0)	humresults[i][j]+=33; 
			
			
			
			
			//			xx@oo*
				  if(board[m-2][n]<0&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]==com)	humresults[i][j]+=33;  
				  if(board[m][n-2]<0&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]==com)	humresults[i][j]+=33;  
				  if(board[m-2][n-2]<0&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]==com)	humresults[i][j]+=33;  
				  if(board[m-2][n+2]<0&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]==com)	humresults[i][j]+=33;
			
		
			
			
			
			
			
			
			
			
			//第十三種情形  *x@oox* 
			if(board[m-2][n]==com&&board[m-1][n]<0&&board[m+1][n]==pla&&board[m+2][n]==pla&&board[m+3][n]<0&&board[m+4][n]==com)	humresults[i][j]+=33;
			if(board[m][n-2]==com&&board[m][n-1]<0&&board[m][n+1]==pla&&board[m][n+2]==pla&&board[m][n+3]<0&&board[m][n+4]==com)  humresults[i][j]+=33;
			if(board[m-2][n-2]==com&&board[m-1][n-1]<0&&board[m+1][n+1]==pla&&board[m+2][n+2]==pla&&board[m+3][n+3]<0&&board[m+4][n+4]==com) humresults[i][j]+=33;
			if(board[m-2][n+2]==com&&board[m-1][n+1]<0&&board[m+1][n-1]==pla&&board[m+2][n-2]==pla&&board[m+3][n-3]<0&&board[m+4][n-4]==com) humresults[i][j]+=33;
			
			
			
			//			*xoo@x*
			
			
			//第十四種情形  *xo@ox*
	
			
			if(board[m-3][n]==com&&board[m-2][n]<0&&board[m-1][n]==pla&&board[m+1][n]==pla&&board[m+2][n]<0&&board[m+3][n]==com)	humresults[i][j]+=33;
			if(board[m][n-3]==com&&board[m][n-2]<0&&board[m][n-1]==pla&&board[m][n+1]==pla&&board[m][n+2]<0&&board[m][n+3]==com)	humresults[i][j]+=33;
			if(board[m-3][n-3]==com&&board[m-2][n-2]<0&&board[m-1][n-1]==pla&&board[m+1][n+1]==pla&&board[m+2][n+2]<0&&board[m+3][n+3]==com)	humresults[i][j]+=33;
			if(board[m-3][n+3]==com&&board[m-2][n+2]<0&&board[m-1][n+1]==pla&&board[m+1][n-1]==pla&&board[m+2][n-2]<0&&board[m+3][n-3]==com)	humresults[i][j]+=33;
		
		
		
	}
	
	
	
}

void Gobang::a_two(int com,int pla,int m,int n,int i,int j,short board[17][17],int clf,int cbf,int clt,int plf,int pbf){  
		//第一種情形   xx@oxx   
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
         
         
         
                    //第二种情?   xx@xox   
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
		
		
			//第一種情形   xx@o*x   
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
		



	//第二種情形   xxo@*x   
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
 				
				 
				 //第一種 
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
	
	 //一种情  x*@xx  
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
