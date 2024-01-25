#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// Function to implement the game
int intGame(char charUser, char charComputer) {
    if (charUser == charComputer)
        return -1;
    if (charUser == 'r' && charComputer == 'p')
        return 0;
    else if (charUser == 'p' && charComputer == 'r')
        return 1;
    if (charUser == 'r' && charComputer == 's')
        return 1;
    if (charUser == 's' && charComputer == 'r')
        return 0;
    if (charUser == 'p' && charComputer == 's')
        return 0;
    if (charUser == 's' && charComputer == 'p')
        return 1;
}

int main() {
	
	char charUser = ' ', charComputer = ' ', charResult = ' ', charPress = ' ', charChoice = ' ';
	
	do {
		system("cls");
	    int intRandomNum = 0;
	    
	    // Chooses the random number every time
	    srand(time(NULL));
	
	    // Make random number less than 100, divided by 100
	    intRandomNum = rand() % 100;
	
	    // Using simple probability 100 is roughly divided among stone, paper, and scissor
	    if (intRandomNum < 33)
	        charComputer = 'r';
	    else if (intRandomNum > 33 && intRandomNum < 66)
	        charComputer = 'p';
	    else
	        charComputer = 's';
	
	    do {
	        // User input
	        printf("\n\n\n\n\t\t\t\tEnter r for ROCK, p for PAPER, and s for SCISSOR\n\t\t\t\t\t\t\t");
	        scanf(" %c", &charUser);  // Added space before %c to skip whitespace characters
	
	        // Check if input is valid
	        if (charUser != 'r' && charUser != 'p' && charUser != 's') {
	            printf("\n\n\t\t\t\tInvalid Entry. Try Again!\n");
	            printf("\t\t\t\tPress Any Key to Continue...");
	            getch();  // Wait for key press
	            system("cls");
	        }
	    } while (charUser != 'r' && charUser != 'p' && charUser != 's');
	
	    // Call function to play the game
	    charResult = intGame(charUser, charComputer);
	
	    // Display game result
	    if (charResult == -1) {
	        printf("\n\n\t\t\t\tGame Draw!\n");
	    } else if (charResult == 1) {
	        printf("\n\n\t\t\t\tWow! You have won the game!\n");
	    } else {
	        printf("\n\n\t\t\t\tOh! You have lost the game!\n");
	    }
	
	    printf("\t\t\t\tYou choose: %c and Computer choose: %c\n\n\n", charUser, charComputer);
	    
	    // Ask user to play again
	    printf("\t\t\t\tPlay again [Y/N]?");
	    scanf(" %c", &charChoice);
	
	} while (toupper(charChoice)!='N');
	
		printf("\n\t\t\t\t!!!!! GAME OVER!!!!!\n\n\n");
		return 0;
}
