#include <stdio.h>
#include <stdlib.h> // for system() function
#include <string.h> // for strcpy function

char square[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player1_name[20];
char player2_name[20];
int player1_score = 0;
int player2_score = 0;

void print_board();
int showMenu();
int checkwin();

int main()
{
    int player = 1, i, choice, playChoice;
    char mark;

    // Get player names
    printf("Enter Player 1's name: ");
    scanf("%s", player1_name);

    printf("Enter Player 2's name: ");
    scanf("%s", player2_name);

    // switch player names initially
    char temp_name[20];
    strcpy(temp_name, player1_name);
    strcpy(player1_name, player2_name);
    strcpy(player2_name, temp_name);

    do // loop continuously
    {
        // display board and get player choice
        playChoice = showMenu();

        if (playChoice == 2)
        {
            printf("\n\nGoodbye!\n\n");
            return 0; // exit game
        }
        else if (playChoice != 1)
        {
            printf("\nInvalid choice. Exiting...\n");
            return 1;
        }

        for (int game_number = 1;; game_number++)
        {
            // reset player number
            player = 1;
            // Reset the game board
            for (int square_number = 1; square_number <= 9; square_number++)
            {
                square[square_number] = square_number + '0'; // stores numbers as characters
            }
            // switch players every new game
            strcpy(temp_name, player1_name);
            strcpy(player1_name, player2_name);
            strcpy(player2_name, temp_name);
            // Switch player scores
            int temp = player1_score;
            player1_score = player2_score;
            player2_score = temp;

            do
            {
                print_board();
                player = (player % 2) ? 1 : 2;
                mark = (player == 1) ? 'X' : 'O';
                printf("%s, enter a number: ", (player == 1) ? player1_name : player2_name);
                scanf("%d", &choice);

                // check if valid position is entered
                if (choice >= 1 && choice <= 9 && square[choice] == (choice + '0'))
                {
                    square[choice] = mark;
                }
                else
                {
                    getchar();
                    printf("Invalid move. Press enter key to continue.");
                    player--;
                    getchar();
                }

                i = checkwin();
                player++;
            } while (i == -1);

            print_board();

            if (i == 1)
            {
                printf("==>\a%s wins !!!\n", (player == 1) ? player2_name : player1_name);
                // update player score
                if (player == 1)
                {
                    player2_score++;
                }
                else
                {
                    player1_score++;
                }
            }
            else
            {
                printf("==>\aGame draw :(\n");
            }

            // Display scoreboard
            printf("Scoreboard:\n\n");
            printf("%s: %d\n", player1_name, player1_score);
            printf("%s: %d\n", player2_name, player2_score);

            printf("\nDo you want to play another game? (1 = Yes, 2 = No): ");
            scanf("%d", &playChoice);
            if (playChoice != 1)
            {
                printf("\n\nGoodbye!\n\n");
                return 0;
            }
        }

    } while (1);
}

// Function to show menu and get user choice
int showMenu()
{
    int choice;
    printf("Welcome to Tic Tac Toe!\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to diaplay board
void print_board()
{
    system("clear"); // clears console
    printf("\nTic Tac Toe\n");
    printf("%s (X)  -  %s (O)\n\n\n", player1_name, player2_name);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

// check win conditions
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
