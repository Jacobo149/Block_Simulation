
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "transaction.h"
#include "block.h"

// Prototypes
void intro();
struct Transaction* createTransaction();


int main() {
    // Display Graphic and Introduction
    intro();
    
    // Call createTransaction() to create 1 transaction and add it to an array of transactions
    struct Transaction transactions[1];
    transactions[0] = *createTransaction("Alice", "Bob", 100, 10, 1, 12345);
    displayTransaction(&transactions[0]);



    // Create a block with the transactions
    struct Block* block = createBlock(1, 0, transactions, 1, "00");

    // Display the block
    displayBlock(block);

    // Free Memory and Terminate(Loop back to the beginning later)
    freeBlock(block);
    return 0;
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
printf("------------Welcome to Block Simulator!------------\n");
printf("---------------------------------------------------\n");
printf("---------------------------------------------------\n");
}