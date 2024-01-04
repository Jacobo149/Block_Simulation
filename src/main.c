
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "transaction.h"
#include "block.h"

// Prototypes
void intro();
struct Transaction* createTransaction();
int getInput();


int main() {
    // Display Graphic and Introduction
    intro();

    


    // Get user input
    int proceed = getInput();
    if (proceed == 0) {
        printf("Exiting...\n");
        return 0;
    }

    printf("Generating transactions...\n");
    printf("These transactions will be added to a block.\n");



    // Call createTransaction() to create 1 transaction and add it to an array of transactions
    struct Transaction transactions[5];
    transactions[0] = *createTransaction("Alice", "Bob", 100, 10, 1, 12345);
    transactions[1] = *createTransaction("Bob", "Alice", 50, 5, 2, 54321);
    transactions[2] = *createTransaction("Grace", "Bob", 100, 10, 1, 12345);
    transactions[3] = *createTransaction("Joe", "Alice", 50, 5, 2, 54321);
    transactions[4] = *createTransaction("Candy", "Cane", 100, 10, 1, 12345);

    printf("---------------------------------------------------\n");
    displayTransaction(&transactions[0]);
    printf("---------------------------------------------------\n");
    displayTransaction(&transactions[1]);
    printf("---------------------------------------------------\n");
    displayTransaction(&transactions[2]);
    printf("---------------------------------------------------\n");
    displayTransaction(&transactions[3]);
    printf("---------------------------------------------------\n");
    displayTransaction(&transactions[4]);
    printf("---------------------------------------------------\n");


    // Get user input
    proceed = getInput();
    if (proceed == 0) {
        printf("Exiting...\n");
        return 0;
    }
        
    printf("Generating block...\n");
    printf("This block will be added to the blockchain.\n");
    printf("---------------------------------------------------\n");



    // Create a block with the transactions
    struct Block* block = createBlock(1, 0, transactions, 1, "00");

    // Display the block
    displayBlock(block);

    // Free Memory and Terminate(Loop back to the beginning later)
    freeBlock(block);
    return 0;
}


int getInput() {
    printf("Do you want to proceed? (Y/N): ");
    char response = getchar();
    // Consume the newline character in the input buffer
    while (getchar() != '\n');

    if (response == 'Y' || response == 'y') {
        return 1;
    }
    else {
        return 0;
    }
}



void intro(){

printf("                                         ____   \n");
printf("    ,---,.   .--.--.      ,---,        ,'  , `. \n");
printf("  ,'  .'  \\ /  /    '. ,`--.' |     ,-+-,.' _ | \n");
printf(",---.' .' ||  :  /`. / |   :  :  ,-+-. ;   , || \n");
printf("|   |  |: |;  |  |--`  :   |  ' ,--.'|'   |  ;| \n");
printf(":   :  :  /|  :  ;_    |   :  ||   |  ,', |  ': \n");
printf(":   |    ;  \\  \\    `. '   '  ;|   | /  | |  || \n");
printf("|   :     \\  `----.   \\|   |  |'   | :  | :  |, \n");
printf("|   |   . |  __ \\  \\  |'   :  ;;   . |  ; |--'  \n");
printf("'   :  '; | /  /`--'  /|   |  '|   : |  | ,     \n");
printf("|   |  | ; '--'.     / '   :  ||   : '  |/      \n");
printf("|   :   /    `--'---'  ;   |.' ;   | |`-'       \n");
printf("|   | ,'               '---'   |   ;/           \n");
printf("`----'                         '---'            \n");
printf("---------------------------------------------------\n");
printf("------------Welcome to Block Simulator------------\n");
printf("---------------------------------------------------\n");
printf("---------------------------------------------------\n");
}