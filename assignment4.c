#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayChoice(int choice) {
    if (choice == 0) printf("Rock");
    else if (choice == 1) printf("Paper");
    else printf("Scissors");
}

int main() {
    int userChoice, computerChoice;
    srand(time(0)); 
    computerChoice = rand() % 100;

    if (computerChoice < 33) computerChoice = 0;  // Rock
    else if (computerChoice < 66) computerChoice = 1;  // Paper
    else computerChoice = 2;  // Scissors

    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("Enter your choice: 0 for Rock, 1 for Paper, 2 for Scissors: ");
    scanf("%d", &userChoice);

    if (userChoice < 0 || userChoice > 2) {
        printf("Invalid choice. Please restart the game.\n");
        return 1;
    }

    printf("You chose: ");
    displayChoice(userChoice);
    printf("\nComputer chose: ");
    displayChoice(computerChoice);
    printf("\n");

    if (userChoice == computerChoice) {
        printf("It's a draw!\n");
    } else if ((userChoice == 0 && computerChoice == 2) || 
               (userChoice == 1 && computerChoice == 0) || 
               (userChoice == 2 && computerChoice == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}
