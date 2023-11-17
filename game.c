/*
AUTHOR'S NAME: GURCHETAN SINGH
STUDENT ID: 100163468
NUMBER OF GROUP MEMBERS:1

**ALL CODE BELOW IS WRITTEN BY AUTHOR**

*/

#include <stdio.h>
//#include <stdlib.h> library containing a rand() function <<uncomment to increase complexicity of virtual player>>

//defining some required constants
#define TRUE 1
#define FALSE 0
//definig some function prototypes
void welcome();
char displayBoard(char userArray[]);
int getInput(char userArray[], int userInput);
int validateMove(char userArray[], int playerMove);
char computerMoves(char userArray[]);
int checkIfWonOrLost(char userArray[]);
char reset_board(char userArray[]);
int checkBoxes(char userArray[]);
void flushInputBuffer();
//Variables
int game_status = 1;
char board[8] = {' ',' ',' ',' ',' ',' ',' ',' '};
int playerMove;
//main


int main(){
//START OF THE GAME WELCOME MESSAGE AND SOME FANCY GRAPHICS<@o@>
welcome();
            while(game_status == 1){
                      displayBoard(board);
                    //break;
                      getInput(board,playerMove);
                      computerMoves(board);
                      if(checkIfWonOrLost(board)== 1){
                                     displayBoard(board);
                                     printf("\nPreparing for a new game!...\n");
                                     printf("\nResetting board..\n");
                                     reset_board(board);                                            
                                    //printf("\nboard should reset now!\n");  
                      }
                      
/*some print statements to decide function placements<<DONOT UNCOMMENT>>   
                       else if(checkIfWonOrLost(board)== 0){
//                                            printf("returns 0 on loss");  
//                          }
//                          else{
//                                    printf("Unclear branch returned!");  
                      }*/
/*to check if infinite loop works<<DONOT UNCOMMENT>>//printf("game running!!");*/
                
    }
}
//Function definations
//welcome message
void welcome(){
    printf("\n------------------------------------------------------------------\n");
    printf("\t  WELCOME TO\n");
    printf("\t%c  |  %c  |  %c  ", 'T','I','C');
    printf("\n\t----------------\n");
    printf("\t%c  |  %c  |  %c  ", 'T', 'A', 'C');
    printf("\n\t----------------\n");
    printf("\t%c  |  %c  |  %c  ", 'T', 'O', 'E');
    printf("\n*a classic game re-imagined in a terminal*\n\tPowered by C!\n");
    printf("\n------------------------------------------------------------------\n");
    printf("\n------------------------------------------------------------------\n");
    printf("\nBoxes are number from 0-8 as such:\n");    
    printf(" %d  |  %d  |  %d  ", 0,1,2);
    printf("\n---------------\n");
    printf(" %d  |  %d  |  %d  ", 3,4,5);
    printf("\n---------------\n");
    printf(" %d  |  %d  |  %d  ", 6,7,8);
    printf("\nPlayer[O] vs Computer[X]\n");

}
//displaying ttt board
char displayBoard(char userArray[]){
    printf("\n------------------------------------------------------------------\n");
    printf(" %c  |  %c  |  %c  ", userArray[0], userArray[1], userArray[2]);
    printf("\n---------------\n");
    printf(" %c  |  %c  |  %c  ", userArray[3], userArray[4], userArray[5]);
    printf("\n---------------\n");
    printf(" %c  |  %c  |  %c  ", userArray[6], userArray[7], userArray[8]);
    printf("\n------------------------------------------------------------------\n");
    printf("\n********press Ctrl+c to quit at any time********\n");
    printf("\n------------------------------------------------------------------\n");
}
//validation of input
int validateMove(char userArray[],int playerMove){
        if(playerMove<9 && playerMove>=0){        
            if((userArray[playerMove] == 'X' || userArray[playerMove] =='O')&& userArray[playerMove] != ' '){
                            printf("\n------------------------------------------------------------------\n");
                            printf("\nSorry this box is already filled!\n");                        
                            printf("\n------------------------------------------------------------------\n");                            
                            return 0;
            }
                return 1;
        }
        else{
                printf("\n------------------------------------------------------------------\n");
                printf("\n\tInvalid input range.Please enter number between 0-8\n");            
                printf("\n------------------------------------------------------------------\n");
                return 0;
        }
    }
//getting player's move
int getInput(char userArray[],int userInput){
    printf("\nPlayer's turn now, enter your chosen box number to mark 'O': ");
    while(1){    
    if(scanf("%d", &userInput)==1){
        if (validateMove(userArray,userInput)== 1){
            userArray[userInput] = 'O';
            break;
        }
        else{
            printf("\nInvalid move try again\n");
            //getInput(userArray,userInput);  recursion does not work here since it calls to same invalid buffer before flushing it ;hence it is omitted out
        }
    }
    else{
        printf("\nInvalid input. Please enter a number:\n");
        //infinite loop issue starts here;upon further research i have concluded that this issue is caused by invalid input that causes program to continue using that input because of unclear buffer!
        flushInputBuffer();
    }
    }
    printf("\nYou played O at : %d\n", userInput);
return userInput;
}
//getting computer's move

char computerMoves(char userArray[]){
            printf("\nComputer played X.\n");
            for(int i = 0; i < 8; ++i){            
                if(userArray[i] != 'X' && userArray[i] != 'O' && userArray[i] == ' '){
                                    userArray[i] = 'X';
                                    break;                             
                }
                else{
                    if(i > 9){
                                   break;                        
                    }
                                  continue;                
            }
        }
//code to increase complexicity of computer moves
//int i = rand() % 9;
//if(userArray[i] != 'X' && userArray[i] != 'O' && userArray[i] == ' '){
//                                    userArray[i] = 'X';
//                }
//code to dumb down pc for debugging and draw function check purposes
//userArray[2] = 'X';
//userArray[3] = 'X';
//userArray[4] = 'X';
//userArray[7] = 'X';
}
//Checking win:) or lose :(
int checkIfWonOrLost(char userArray[]){
//horizontals
    if(userArray[0] == 'O' && userArray[1] == 'O' && userArray[2] == 'O'){
            printf("\nUSER WON!\n");            
            //reset board
            return 1;
    }
    else if(userArray[3] == 'O' && userArray[4] == 'O' && userArray[5] == 'O'){
            printf("\nUSER WON!\n");            
            //reset board
            return 1;
    }
    else if(userArray[6] == 'O' && userArray[7] == 'O' && userArray[8] == 'O'){
            printf("\nUSER WON!\n");            
            //reset board
            return 1;
    }
//verticals
    else if(userArray[0] == 'O' && userArray[3] == 'O' && userArray[6] == 'O'){
            printf("\nUSER WON!\n");            
            //reset board
            return 1;
    }
    else if(userArray[1] == 'O' && userArray[4] == 'O' && userArray[7] == 'O'){
            printf("\nUSER WON!\n");            
            //reset board
            return 1;
    }
    else if(userArray[2] == 'O' && userArray[5] == 'O' && userArray[8] == 'O'){
            printf("\nUSER WON!\n");            
            //reset board
            return 1;
    }
//diagnols
    else if(userArray[0] == 'O' && userArray[4] == 'O' && userArray[8] == 'O'){
            printf("\nUSER WON!\n");
            //reset board            
            return 1;
    }
    else if(userArray[2] == 'O' && userArray[4] == 'O' && userArray[6] == 'O'){
            printf("\nUSER WON!\n");
            //reset board            
            return 1;
    }
//for Xs
//horizontals
    if(userArray[0] == 'X' && userArray[1] == 'X' && userArray[2] == 'X'){
            printf("\nUSER LOST!\n");            
            //reset board
            return 1;
    }
    else if(userArray[3] == 'X' && userArray[4] == 'X' && userArray[5] == 'X'){
            printf("\nUSER LOST!\n");            
            //reset board
            return 1;
    }
    else if(userArray[6] == 'X' && userArray[7] == 'X' && userArray[8] == 'X'){
            printf("\nUSER LOST!\n");            
            //reset board
            return 1;
    }
//verticals
    else if(userArray[0] == 'X' && userArray[3] == 'X' && userArray[6] == 'X'){
            printf("\nUSER LOST!\n");            
            //reset board
            return 1;
    }
    else if(userArray[1] == 'X' && userArray[4] == 'X' && userArray[7] == 'X'){
            printf("\nUSER LOST!\n");            
            //reset board
            return 1;
    }
    else if(userArray[2] == 'X' && userArray[5] == 'X' && userArray[8] == 'X'){
            printf("\nUSER LOST!\n");            
            //reset board
            return 1;
    }
//diagnols
    else if(userArray[0] == 'X' && userArray[4] == 'X' && userArray[8] == 'X'){
            printf("\nUSER LOST!\n");
            //reset board            
            return 1;
    }
    else if(userArray[2] == 'X' && userArray[4] == 'X' && userArray[6] == 'X'){
            printf("\nUSER LOST!\n");                
            //reset board            
            return 1;
    }
    else if(checkBoxes(userArray) == 0){
            
            printf("\nIt's a Draw!\n");
            return 1;
        }
//final
    else{
            //reset board
            return 0;    
           }
}

//To reset the board for new game
char reset_board(char userArray[]){
                for(int i=0;i < 9; ++i){
                        userArray[i] = ' ';
            }
}


 //To check if all boxes are filled
int checkBoxes(char userArray[]){
            int emptySum = 0;
            for(int i=0;i<9;++i){
                         if(userArray[i] == ' '){
                            emptySum = emptySum + 1;
                }                
            }
            return emptySum;

}
//a function to clear input buffer much like fflush() that clears output buffer
void flushInputBuffer() {
    int c;  // Variable to store each character read from the input buffer

    // Loop until a newline character or the end of file is found
    while ((c = getchar()) != '\n' && c != EOF);
}
