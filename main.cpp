#include <iostream>
#include <string>
#define GRID_SIZE 3
using namespace std;

class Game{

private:
    char grid[GRID_SIZE][GRID_SIZE];
public:

    void check_win(){

        const char* winning_moves[8] = {
            "123",
            "456",
            "789",
            "147",
            "258",
            "369",
            "159",
            "753"
        };

        //loop through possible winning moves.
        for (int i = 0; i < 8; i++){

            bool winner = true;
            char prev_grid = '0';
            const char* winning_move = winning_moves[i];

            for(int index = 0; index < GRID_SIZE; index++){
                char character = winning_move[index];

                int entered_number = character - '0';

                int grid_space = entered_number - 1;

                int row = grid_space / GRID_SIZE;
                int col = grid_space % GRID_SIZE;
                char grid_char = grid[row][col];

                if (prev_grid == '0'){
                    prev_grid = grid_char;
                }
                else if(prev_grid == grid_char){
                    continue;
                }else{
                    winner = false;
                    break;
                }
            }
            if(winner){
                puts("We have a winner!");
                printf("looks like %c won, congrats!\n", prev_grid);
                exit(0);
                break;
            }
        }

    }
    void start_turn(){
        string input;

        while (true){
            puts("Where do you want to play?");
            getline(cin, input);

            if(input != ""){
                char entered = input.c_str()[0];

                if(entered >= '1' && entered <= '9'){
                    //handle it
                    int entered_num = entered - '0';
                    int index = entered_num - 1;
                    
                    int row = index / 3;
                    int col = index % 3;

                    char grid_pos = grid[row][col];
                    if (grid_pos == 'X' || grid_pos =='O' ){
                        puts("Unavailable action!");

                    }else{
                        grid[row][col] = 'X';
                        break;
                    }

                }else{
                    puts("Play in the range 1-9!");
                }
            }else{
                puts("Enter something!");
            }

        }
    }

    void generate_grid(){

        int number = 1;
        for (int x = 0; x < GRID_SIZE; x++){

            for (int y = 0; y < GRID_SIZE; y++){
                grid[x][y] = to_string(number).c_str()[0];
                number += 1;
            }
        }
    }
    
    void show_grid(){
        printf("\n-------------\n");

        for (int x = 0; x < GRID_SIZE; x++){
            for (int y = 0; y < GRID_SIZE; y++){
                printf(" %c |", grid[x][y]);
            }
            printf("\n-------------\n");
        }

    }

    Game(){
        generate_grid();

        while (true){
            show_grid();
            check_win();
            start_turn();
        }

    }
};

int main( int argc, char *argv[] ){

    Game game;


        
    
    return 0;
}