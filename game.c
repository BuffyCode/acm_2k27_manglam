#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    srand(time(0));

    int randomNumber = (rand() % 100) + 1;
    int no_of_guesses_player1 = 0;
    int no_of_guesses_player2 = 0;
    int total_guesses = 0;
    int guessed;
    int currentPlayer = 1;

    printf("Welcome to the 1v1 Number Guessing Game!\n");
    printf("A random number between 1 and 100 has been generated.\n");

    do {
        clearScreen();
        printf("Current Number to Guess: [Hidden]\n");
        printf("Player %d's turn\n", currentPlayer);
        printf("Guess the number: ");
        scanf("%d", &guessed);

        // Show the guessed number
        printf("Player %d guessed: %d\n", currentPlayer, guessed);

        total_guesses++; // Increment total guesses

        if (guessed > randomNumber) {
            printf("Lower Number Please!\n");
        } else if (guessed < randomNumber) {
            printf("Higher Number Please!\n");
        } else {
            printf("Congratulations Player %d! You guessed the number!\n", currentPlayer);
        }

        // Increment the guess count for the current player
        if (currentPlayer == 1) {
            no_of_guesses_player1++;
        } else {
            no_of_guesses_player2++;
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        // Pause for a moment before the next turn
        printf("Press Enter to continue...");
        while (getchar() != '\n'); // Clear the input buffer
        getchar(); // Wait for Enter

    } while (guessed != randomNumber);

    // Display the total number of guesses and each player's guess count
    printf("Game Over!\n");
    printf("Total number of guesses made: %d\n", total_guesses);
    printf("Player 1 made %d guesses.\n", no_of_guesses_player1);
    printf("Player 2 made %d guesses.\n", no_of_guesses_player2);

    return 0;
}
