#include <stdio.h>
#include <string.h>
int main() {
    char word[] = "hangman";
    char guessedWord[] = "_______";
    int chances = 3, won = 0;
    char guess;
    printf("Welcome to the Hangman Game!\n");
    printf("You have %d chances to guess the word correctly.\n", chances);
    printf("The word is: %s\n", guessedWord);
    while (chances > 0 && !won) {
        printf("\nEnter your guess (a single letter): ");
        scanf(" %c", &guess);
        int correctGuess = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == guess && guessedWord[i] == '_') {
                guessedWord[i] = guess;
                correctGuess = 1;
            }
        }
        if (!correctGuess) {
            chances--;
            printf("Wrong guess! You have %d chances left.\n", chances);
        } else {
            printf("Good guess! Current word: %s\n", guessedWord);
        }
        if (strcmp(word, guessedWord) == 0) {
            won = 1;
        }
    }
    if (won) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
        printf("The man survives. Well done!\n");
    } else {
        printf("\nYou ran out of chances! The word was: %s\n", word);
        printf("The man is hanged. Better luck next time!\n");
    }
    return 0;
}
