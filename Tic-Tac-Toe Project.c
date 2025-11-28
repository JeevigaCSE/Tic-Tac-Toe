//Mini Project
//Title:Tic-Tac-Toe
//Simple two-player console-based game
#include<stdio.h>

char board[3][3]={ //2 players 3x3 Board with position
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void printboard()
{
    //To print the board for each and every play of players
    printf("\n-------------\n");
    for(int i=0;i<3;i++){
    printf("| %c | %c | %c |",board[i][0],board[i][1],board[i][2]);
    if(i<2)
        printf("\n-------------\n");
   }
   printf("\n");
   printf("-------------\n");
}
int checkwin()
{
    //To check the winning status
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}
int isdraw()
{
    //To check if the match is draw
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X'&& board[i][j]!='O')
                return 0;
        }
    }
    return 1;
}
int main()
{
    char cp='X';
    int p,r,c;
    printf("Tic Tac Toe Game\n");
    printf("\nPlayer 1 = X\nPlayer 2 = O\n");
    while(1)
    {
        printboard();//To print Initial Board before starting the game
        printf("\nPlayer %c enter position(1-9):",cp);
        scanf("%d",&p);
        if(p<1||p>9){
            printf("Invalid position! Try again.\n");//To ensure player chooses correct position
            continue;
        }
        r=(p-1)/3;
        c=(p-1)%3;
        if (board[r][c] == 'X' || board[r][c] == 'O') {
            printf("Position already taken! Try again.\n");//To ensure no repetition
            continue;
        }

        board[r][c] = cp;

        if (checkwin()) {
            printboard();//Function call to display the Winner player
            printf("Player %c wins!\n", cp);
            break;
        }

        if (isdraw()) {
            printboard();//Function call to display if the match is Draw
            printf("Match Draw!\n");
            break;
        }
        //Switch the turn between players
        cp = (cp == 'X') ? 'O' : 'X';
    }
    return 0;
}
