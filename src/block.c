#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// Transaction struct
struct Transaction {
    char* sender;
    char* receiver;
    int amount;
    // Add other transaction details as needed
};

// Block struct
struct Block {
    uint32_t number;
    uint32_t nonce;
    time_t timestamp;
    struct Transaction* transactions;
    uint32_t numTransactions;
    char* previousHash;
    char* hash;
};

// Function to create a new block
struct Block* createBlock(uint32_t number, uint32_t nonce, struct Transaction* transactions, uint32_t numTransactions, char* previousHash) {
    struct Block* block = malloc(sizeof(struct Block));

    block->number = number;
    block->nonce = nonce;
    block->timestamp = time(NULL);
    block->transactions = malloc(numTransactions * sizeof(struct Transaction));
    
    for (uint32_t i = 0; i < numTransactions; ++i) {
        // Assuming you have a copyTransaction function to copy transactions
        // block->transactions[i] = copyTransaction(transactions[i]);
        // Compute Hash based on transacions and nonce
    }

    block->numTransactions = numTransactions;
    block->previousHash = strdup(previousHash);
    block->hash = NULL; // You'll need to compute the hash separately

    return block;
}

// Function to free memory allocated for a block
void freeBlock(struct Block* block) {
    free(block->transactions);
    free(block->previousHash);
    free(block->hash);
    free(block);
}

// Function to display a block
int main() {
    // Example usage of createBlock
    uint32_t number = 1;
    uint32_t nonce = 12345;
    struct Transaction* transactions = NULL;
    uint32_t numTransactions = 0;
    char* previousHash = "0";
    char* hash = "190abcdef";

    struct Block* myBlock = createBlock(number, nonce, transactions, numTransactions, previousHash);

    // Display information about the created block
    printf("Block Details:\n");
    printf("Number: %d\n", myBlock->number);
    printf("Nonce: %d\n", myBlock->nonce);
    printf("Timestamp: %ld\n", myBlock->timestamp);
    printf("Previous Hash: %s\n", myBlock->previousHash);
    printf("Hash: %s\n", myBlock->hash);

}