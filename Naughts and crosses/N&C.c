#include <stdio.h>
#include <time.h>

// why doesnt C have bools ?
typedef enum Bool {
    TRUE,
    FALSE
} Bool; // enum's are good for making a bool data type, that work like other programs. 

#define PLAYER 'X';
#define COMPUTER 'O';

char game_board[3][3];

char winner;

void _board_setup();
void _draw_board();
void _player_move();
void _computer_move();
int _board_space_check(int x, int y);
char _check_winner();
int _random_number(int min, int max);

int main(){
    char replay_input;

    do {

        winner = ' ';
        _board_setup();

        do { 
            
            _player_move(); 
            _draw_board();
            winner = _check_winner();
            if (winner!=' ') {break;}

            _computer_move();
            _draw_board();
            winner = _check_winner();
            if (winner!=' ') {break;}

        } while (winner==' ');


        if (winner=='d'){printf("It's a draw!\n");}
        else {printf("%c is the winner!\n", winner);}

        printf("Do you want to play again (Y/N): ");
        scanf(" %c", &replay_input); // why does the space before the %c fix the issue of the input being skiped ? i havent had this issue anywhere else ?

    } while (replay_input=='Y'||replay_input=='y');
    
    return 0;
}

void _board_setup(){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            game_board[i][j] = ' ';
        }
    }
}

void _draw_board(){
    printf(" %c | %c | %c \n", game_board[0][0], game_board[0][1], game_board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", game_board[1][0], game_board[1][1], game_board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", game_board[2][0], game_board[2][1], game_board[2][2]);
}

void _player_move(){
    int x, y;

    do {       
        do {
            printf("Enter a 'y' position (1-3): ");
            scanf("%d", &x); --x;

            printf("Enter a 'x' position (1-3): ");
            scanf("%d", &y); --y;
        } while ((0>x||x>2)||(0>y||y>2));
    } while (_board_space_check(x, y)==FALSE);

    game_board[x][y] = PLAYER;
}

void _computer_move(){
    int x, y;

    do {
        x = _random_number(0,2);
        y = _random_number(0,2);
    } while (_board_space_check(x, y)==FALSE);

    game_board[x][y] = COMPUTER;
}

int _board_space_check(int x, int y){
    if (game_board[x][y] == ' ') {return TRUE;}
    else {return FALSE;}
}

char _check_winner(){

    // horizontal lines
    for (int i=0;i<3;i++){
        if (game_board[0][i]==game_board[1][i]&&game_board[1][i]==game_board[2][i]) {return game_board[0][i];}
    }
    
    // vertical lines
    for (int i=0;i<3;i++){
        if (game_board[i][0]==game_board[i][1]&&game_board[i][1]==game_board[i][2]) {return game_board[i][0];}
    }

    // diagonal lines
    if (game_board[0][0]==game_board[1][1]&&game_board[0][0]==game_board[2][2]) {return game_board[0][0];}
    if (game_board[0][2]==game_board[1][1]&&game_board[0][2]==game_board[2][0]) {return game_board[0][2];}

    // draw
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (_board_space_check(i, j)) {return ' ';} 
        }
    }
    
    return 'd'; 
}

int _random_number(int min, int max){return (time(NULL)%(max+1))+min;}  // wanted to have a go at writng a random number genorator function           