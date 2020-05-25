/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            Buddha bless       No BUG
 *
 *
 *   ZHANG Yubo 19079784d
 *   Assignment2 Tic-Tac-Toe
 *   Github: https://github.com/ZHANGYuboPolyU/cpp/blob/master/assignment2.cpph
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

char board[9]={'1','2','3','4','5','6','7','8','9'};  // 'board' contains 1st~9th cell's element
int num=0,step=1;  //num is the cell's index; 
char flag,chess;  // 'flag' record the 1st entered chess; 'chess' record every time entered chess;
int system_command,game_mode;
string winner=" ";

void welcome() //print welcome message and instruction on how to play this game.
{
    //Welcome message
    cout<<
        "████████╗██╗ ██████╗              ████████╗ █████╗  ██████╗              ████████╗ ██████╗ ███████╗\n"
        "╚══██╔══╝██║██╔════╝              ╚══██╔══╝██╔══██╗██╔════╝              ╚══██╔══╝██╔═══██╗██╔════╝\n"
        "   ██║   ██║██║         █████╗       ██║   ███████║██║         █████╗       ██║   ██║   ██║█████╗  \n"
        "   ██║   ██║██║         ╚════╝       ██║   ██╔══██║██║         ╚════╝       ██║   ██║   ██║██╔══╝  \n"
        "   ██║   ██║╚██████╗                 ██║   ██║  ██║╚██████╗                 ██║   ╚██████╔╝███████╗\n"
        "   ╚═╝   ╚═╝ ╚═════╝                 ╚═╝   ╚═╝  ╚═╝ ╚═════╝                 ╚═╝    ╚═════╝ ╚══════╝\n";
                                                                                                                
    cout<<"Instructions: Tic-tac-toe is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3×3 grid.\n"<<
    "The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner."<<endl<<endl;

	cout<<"Here is what the game board looks like the the IDs of each cell:"<<endl;
    cout<<" "<<board[0]<<"| "<<board[1]<<" |"<<board[2]<<endl;
    cout<<"---------"<<endl;
    cout<<" "<<board[3]<<"| "<<board[4]<<" |"<<board[5]<<endl;
    cout<<"---------"<<endl;
    cout<<" "<<board[6]<<"| "<<board[7]<<" |"<<board[8]<<endl<<endl;
}
bool isOccupied(int num);  //check whether the cell is occupied or not
bool isWin();  //check whether there is a player win
void refreshBoard(int step,char chess,int mode);  //process of putting a chess into the cell and update board
void h2h();  //human vs human
void h2c();  //human vs computer
int minimax(char flag);  //Minimax (sometimes MinMax, MM[1] or saddle point[2]) is a decision rule used in artificial intelligence, decision theory, game theory, statistics, and philosophy for minimizing the possible loss for a worst case (maximum loss) scenario. 
void BubbleSort(int  *p, int * ind_diff);  //bubble sort and return the original index based on the sorted order
int evaluate(int i,char flag);  //evaluate the best cell choice for computer

int main()
{
    welcome();
    //Choose system command
    Start_game:
    step=1;  //initial step=1
    winner=" ";  //initial winner is " " 
	cout<<"Please enter system command."<<endl;
    cout<<"     0: Exit the System"<<endl;
    cout<<"     1: Begin entering a new game"<<endl;
    cout<<"****************************************************************************************"<<endl;
    cout<<"System command: ";
    cin>>system_command;
    cout<<endl;
    //Check input system command is integer 
    if(cin.fail())
    {
        cin.clear();
        cin.sync();
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Start_game;   
    }
    //Check input system command is 1/0 or other number
    if(system_command!=1)
    {
        if(system_command==0)  
          return 0;
        else{
            cout<<"Invalid input, please try again."<<endl<<endl; 
            goto Start_game;
        }
    }
    //Chose game mode
    Choose_mode:
	cout<<"Please select the game mode"<<endl;
    cout<<"     1: The human player plays against the computer player"<<endl;
    cout<<"     2: Two human players play against each other"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"Game mode: ";
    cin>>game_mode;
    cout<<endl;
    if(cin.fail()||(game_mode!=1&&game_mode!=2))
    {
        cin.clear();
        cin.sync();  //clean the input buffer in case wrong conmand was read again
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Choose_mode;   
    }
    //initial board cell from 1 to 9 
    for(int i=0;i<9;i++)
    {
        board[i]=i+1+'0';
    }
    //differnt game mode
    if(game_mode==1)  h2c();  //human vs computer
    else h2h();  //human vs human

    if(winner==" ")  cout<<"It's Draw!"<<endl<<endl;  

    cout<<"---New Game---"<<endl;
    goto Start_game;  //Start game again.
    return 0;
}

void h2h()
{
    char flag=rand()%2==0?'O':'X';  //generate 1st player's chess randomly'
    cout<<"The game system has randomly thrown a virtual dice."<<endl;
    cout<<"The Player1 is: "<<flag<<endl;
    cout<<"This is the Player1's turn."<<endl;

	chess=flag;  // For 1st time, 'flag' should = 'chess'
	refreshBoard(step,chess,game_mode);
    step=2;
    
	for(step;step<=9;step++)
    {
    	Check1: if(step%2==1)  //Player1's turn
    	{
    		cout<<"Game continues, this is the Player1's turn. Please enter "<<flag<<": ";
            cin>>chess;
            chess=toupper(chess);  //both upper and lower case are accepted

    		if(chess!=flag) {
    			cout<<"Error: it is the "<<flag<<" turn."<<endl;
    			goto Check1;
			}//if users enter wrongly, then enter again.
    	    refreshBoard(step,chess,game_mode);
            if(winner==" "&&isWin()) {
                winner="Player1";
                cout<<"Player1 Wins!"<<endl;
                break;
            }
    	}
    	Check2: if(step%2==0)  //Player2's turn
    	{
    		cout<<"Game continues, this is the Player2's turn. Please enter "<<(flag=='O'?"X":"O")<<": ";//This trinocular operation gives an answer different from 'flag'
            cin>>chess;
            chess=toupper(chess);
    		if(chess!=(flag=='O'?'X':'O')){
                cout<<"Error: it is the "<<(flag=='O'?'X':'O')<<" turn."<<endl;
    			goto Check2;//if users enter wrongly, then enter again.
			}
            refreshBoard(step,chess,game_mode);
            if(winner==" "&&isWin()) {
                winner="Player2";
                cout<<"Player2 Wins!"<<endl;
                break;
            }
	    }
    }
    cout<<"The end."<<endl;
}

void h2c()
{
    //computer will be the first player
    char flag=rand()%2==0?'O':'X';
    cout<<"The game system has randomly thrown a virtual dice."<<endl;
    cout<<"The Computer is: "<<flag<<endl;

	chess=flag;  // For 1st time, 'flag' should = 'chess'
    _sleep(2*1000);  // Give 2 seconds for user to react
	refreshBoard(step,chess,game_mode);
    step=2;
    
	for(step;step<=9;step++)
    {
    	Check1: if(step%2==1)  //computer's turn
    	{
    		cout<<"Game continues, this is the Computer's turn. "<<endl;
            _sleep(1*1000);  // Give 1 second for user to react
            chess=flag;
    	    refreshBoard(step,chess,game_mode);
            if(winner==" "&&isWin()) {  //
                winner="Computer";
                cout<<"Computer Wins! Game Over"<<endl;
                break;
            }
    	}
    	Check2: if(step%2==0)//human player's tern
    	{
    		cout<<"Game continues, this is your turn. Please enter "<<(flag=='O'?"X":"O")<<": ";  //This trinocular operation gives an answer different from 'flag'
            cin>>chess;
            chess=toupper(chess);
    		if(chess!=(flag=='O'?'X':'O')){
                cout<<"Error: it is the "<<(flag=='O'?'X':'O')<<" turn."<<endl;
    			goto Check2;  //if users enter wrongly, then enter again.
			}
            refreshBoard(step,chess,game_mode);
            if(winner==" "&&isWin()) {
                winner="You";
                cout<<"You win!!!"<<endl;
                break;
            }
	    }
    }
    cout<<"The end."<<endl;
}

void refreshBoard(int step,char chess,int mode)
{
    Check_occupied:
    if(mode==1&&step%2==1){   //computer choose cell
        num=minimax(chess)+1;
    }
    else{
        cout<<"Which cell you want to place?"<<endl;   //human choose cell
        cout<<"Cell number: ";
        cin>>num;
        cout<<endl;
    }
    if(isOccupied(num)) {
        if(mode==2||(mode==1&&step%2==0))  //if human's choosen cell has been occupied then choose again
        cout<<"This cell is occupied, please enter again."<<endl<<endl;
        goto Check_occupied;
    }
    if(cin.fail()||num>9||num<1)
    {
        cin.clear();
        cin.sync();
        cout<<"Invalid input, please try again."<<endl<<endl; 
        goto Check_occupied;   
    }

    board[num-1]=chess;
    cout<<" "<<board[0]<<"| "<<board[1]<<" |"<<board[2]<<endl;
    cout<<"---------"<<endl;
    cout<<" "<<board[3]<<"| "<<board[4]<<" |"<<board[5]<<endl;
    cout<<"---------"<<endl;
    cout<<" "<<board[6]<<"| "<<board[7]<<" |"<<board[8]<<endl;

    if(step%2==1&&mode==1) cout<<"(Computer has chosen cell "<<num<<")"<<endl;   //For computer
    if(!isWin()){
        cout<<"This is step "<<step<<", there are "<<9-step<<" more steps."<<endl;
        cout<<"*************************************************"<<endl<<endl;
    }
}

bool isOccupied(int num)
{
    if(board[num-1]=='O'||board[num-1]=='X') return true;
    else return false;
}

bool isWin()
{
    if((board[0]==board[4]&&board[4]==board[8])||(board[2]==board[4]&&board[4]==board[6]))   //diagonal
       return true;
    for(int i=0;i<3;i++)  //column
    {
        if(board[i]==board[i+3]&&board[i+3]==board[i+6])
             return true;
    }
    for(int i=0;i<7;i+=3)  //row
    {
        if(board[i]==board[i+1]&&board[i+1]==board[i+2])
             return true;
    }
    return false;
}

int minimax(char flag)  
{
    char original_chess;  //record originally existed chess

    for(int i = 0; i <9;i++)  //Check if player only need one more chess to win
    {
       if(!isOccupied(i+1)&&board[i]!=flag)  
       {
           original_chess=board[i];
           board[i]=(flag=='O'?'X':'O');  //fill ith cell with human player's chess
           if(isWin())  
           {
               board[i]=original_chess;  
               return i;  
           }
           else  board[i]=original_chess;
       }
    }
    //use minimax method to decide which cell is the best choice for computer
    int grades[9]={0};  //mark each cell with a score of choice
    int index[9]={0,1,2,3,4,5,6,7,8};  //each cell has a one to one index and score
    for(int i=0;i<9;i++)
    {
        if(isOccupied(i+1))  grades[i]=-1000;  //don't choose the occupied chess
        else grades[i]=evaluate(i,flag);
    }

    BubbleSort(grades,index);  //sort the intex array based on the grades
    return index[0];
}

void BubbleSort(int  p[], int ind_diff[])  //ind_diff records the index of original p[]'s elements
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9- i - 1; j++)
		{
			if (p[j] < p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				int ind_temp = ind_diff[j];  //also sort index array based on grades array
				ind_diff[j] = ind_diff[j + 1];
				ind_diff[j + 1] = ind_temp;
			}
		}
	}
}

int evaluate(int ind,char flag)
{
    int count = 0;//count is the grades for computer to decide which cell is the best
    //1 for computer chess and -1 for player chess
  
    int temp_board[9]={0};
    char original_chess;  //record originally existed chess

    original_chess=board[ind];
    board[ind]=flag;  // assume that computer chess has been filled in cell ind+1

    for(int i = 0; i <9;i++)    //Fill every blank cell with computer chess 1 and check lines
    {
        if(board[i]==flag||(board[i]-'0'>0&&board[i]-'0'<10)) 
            temp_board[i]=1;
        else
            temp_board[i]=-1;
    }
    
    if(temp_board[0]+temp_board[4]+temp_board[8]==3)  //diagonal
        count++;
    if(temp_board[2]+temp_board[4]+temp_board[6]==3)  //diagonal
        count++;
    for(int i=0;i<3;i++) //column
    {
        if(temp_board[i]+temp_board[i+3]+temp_board[i+6]==3)
            count++;
    }
    for(int i=0;i<7;i+=3)  //row
    {
        if(temp_board[i]+temp_board[i+1]+temp_board[i+2]==3)
            count++;
    }
    
    for(int i = 0; i <9;i++)   //Fill every empty cell with player's chess
    {
        if(board[i]==flag) 
            temp_board[i]=1;
        else
            temp_board[i]=-1;
    }
    
    if(temp_board[0]+temp_board[4]+temp_board[8]==-3)
        count--;
    if(temp_board[2]+temp_board[4]+temp_board[6]==-3)
        count--;
    for(int i=0;i<3;i++) //column
    {
        if(temp_board[i]+temp_board[i+3]+temp_board[i+6]==-3)
            count--;
    }
    for(int i=0;i<7;i+=3)  //row
    {
        if(temp_board[i]+temp_board[i+1]+temp_board[i+2]==-3)
            count--;
    }

    board[ind]=original_chess;// del the assumption

    return count;

}
