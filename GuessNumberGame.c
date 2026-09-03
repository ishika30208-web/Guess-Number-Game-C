#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int random, guess;
    int no_of_guesses = 0;
    srand(time(NULL));
    printf("Welcome to the world of Guessing Numbers\n");
    random = rand() % 100 + 1;

    do{
        printf("\nPlease enter your Guess between(1 to 100):");
        scanf("%d",&guess);
        no_of_guesses++;

        if(guess < random){
            printf("Guess a larger number.\n");
        } else if(guess > random){
            printf("guess a smaller number.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", no_of_guesses);
        }
} while(guess != random);
printf("Thank you for playing the game!\n");
printf("Developed by: Ishika\n");
return 0;
}
