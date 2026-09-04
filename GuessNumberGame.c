#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int maxNumber;
    int maxAttempts;
    int randomNumber;
    int guess;
    int attempts;
    int score;
    char playAgain;

    srand(time(NULL));

    printf("\n========================================\n");
    printf("        🎯 GUESS NUMBER GAME\n");
    printf("========================================\n");

    do {
        /* -------------------------------
           DIFFICULTY SELECTION
           ------------------------------- */

        printf("\nChoose Difficulty Level:\n");
        printf("1. Easy   (1 - 50, 10 attempts)\n");
        printf("2. Medium (1 - 100, 7 attempts)\n");
        printf("3. Hard   (1 - 500, 5 attempts)\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter 1, 2, or 3.\n");

            while (getchar() != '\n');

            continue;
        }

        switch (choice) {

            case 1:
                maxNumber = 50;
                maxAttempts = 10;
                break;

            case 2:
                maxNumber = 100;
                maxAttempts = 7;
                break;

            case 3:
                maxNumber = 500;
                maxAttempts = 5;
                break;

            default:
                printf("\nInvalid choice! Please select 1, 2, or 3.\n");
                continue;
        }

        /* Generate random number */

        randomNumber = rand() % maxNumber + 1;

        attempts = 0;
        score = 0;

        printf("\n========================================\n");
        printf("Game Started!\n");
        printf("Guess a number between 1 and %d.\n", maxNumber);
        printf("You have %d attempts.\n", maxAttempts);
        printf("========================================\n");

        /* -------------------------------
           GAME LOOP
           ------------------------------- */

        while (attempts < maxAttempts) {

            printf("\nAttempt %d/%d", attempts + 1, maxAttempts);
            printf("\nEnter your guess: ");

            if (scanf("%d", &guess) != 1) {
                printf("Invalid input! Please enter a number.\n");

                while (getchar() != '\n');

                continue;
            }

            if (guess < 1 || guess > maxNumber) {
                printf("Please enter a number between 1 and %d.\n",
                       maxNumber);
                continue;
            }

            attempts++;

            if (guess < randomNumber) {

                printf("⬆ Too Low! Try a larger number.\n");

            } else if (guess > randomNumber) {

                printf("⬇ Too High! Try a smaller number.\n");

            } else {

                /* Score based on remaining attempts */

                score = (maxAttempts - attempts + 1) * 10;

                printf("\n========================================\n");
                printf("🎉 CONGRATULATIONS!\n");
                printf("You guessed the correct number!\n");
                printf("Number: %d\n", randomNumber);
                printf("Attempts Used: %d\n", attempts);
                printf("Your Score: %d\n", score);
                printf("========================================\n");

                break;
            }
        }

        /* -------------------------------
           GAME OVER
           ------------------------------- */

        if (guess != randomNumber) {

            printf("\n========================================\n");
            printf("💀 GAME OVER!\n");
            printf("The correct number was: %d\n", randomNumber);
            printf("Better luck next time!\n");
            printf("========================================\n");
        }

        /* -------------------------------
           PLAY AGAIN
           ------------------------------- */

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    printf("\n========================================\n");
    printf("Thank you for playing! 🎮\n");
    printf("Developed by: Ishika\n");
    printf("========================================\n");

    return 0;
}
