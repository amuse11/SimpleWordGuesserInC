#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {

    // Size of array
    const int size = 5;
    // 2D array to hold words of certain length as in [word][lengthOfWord]
    char words[size][40];
    // Longest commonly-used word can have potentially 40 letters in the English language.
    char wordToGuess[40];
    // User's guesses will be stored in this variable
    char guess;


    // variables initialised
    int i = 0, j = 0;
    int a = 0;

    // Words
    strcpy(words[0], "lemon");
    strcpy(words[1], "box");
    strcpy(words[2], "tissue");
    strcpy(words[3], "hamster");
    strcpy(words[4], "cardboard");


    // Greeting
    printf("Would you like to play Word Guesser?\n");
    printf("Great! Let's start\n");

    // Randomize the word chosen from array
    srand(time(NULL));

    i = rand() % size;

    // Copy word to letterguess variable
    strcpy(wordToGuess, words[i]);
    // Print secret word
    printf("The word is:\n");

    // Hides word by covering it with -
    for (j = 1; j <= strlen(words[i]); j++) {
        printf("-");
    }

    printf("Have fun guessing!\n");
    // number of tries stored in this variable and set to the number of letters in word
    int numberOfTries = strlen(wordToGuess);
    while (numberOfTries > 0) {
        printf("Guess a letter\n");
        fflush(stdin);
        scanf(" %c", &guess);

        if (strchr(wordToGuess, guess) != NULL) {
            a++;
        }

        if (a == strlen(wordToGuess)) {
            numberOfTries = 0;
            printf("You got it correct!\n");
        } else if (strchr(wordToGuess, guess) == NULL) {
            numberOfTries--;
            printf("The letter %c you entered is wrong, you have %d tries left\n", guess, numberOfTries);
        }


    }
    printf("Thank you for playing!");

    return 0;
}