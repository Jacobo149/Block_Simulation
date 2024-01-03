#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "sha256.h"
#include "transaction.h"

// Block struct
struct Block {
    uint32_t number;
    uint32_t nonce;
    time_t timestamp;
    struct Transaction* transactions;
    uint32_t numTransactions;
    char* previousHash;
    char hash[65]; // 64 characters for the hash, plus 1 for the null terminator
};

// Function to calculate the SHA-256 hash for a block
void calculateBlockHash(struct Block* block) {
    SHA256_CTX sha256;
    sha256_init(&sha256);

    // Include block number, nonce, timestamp, and transaction IDs in the hash calculation
    sha256_update(&sha256, (const BYTE*)&block->number, sizeof(block->number));
    sha256_update(&sha256, (const BYTE*)&block->nonce, sizeof(block->nonce));
    sha256_update(&sha256, (const BYTE*)&block->timestamp, sizeof(block->timestamp));
    sha256_update(&sha256, (const BYTE*)block->previousHash, strlen(block->previousHash));

    for (uint32_t i = 0; i < block->numTransactions; ++i) {
        sha256_update(&sha256, (const BYTE*)&block->transactions[i].id, sizeof(block->transactions[i].id));
    }

    BYTE hash[32];
    sha256_final(&sha256, hash);

    // Convert the binary hash to a hexadecimal string
    for (int i = 0; i < 32; ++i) {
        sprintf(&block->hash[i * 2], "%02x", hash[i]);
    }

    block->hash[64] = '\0'; // Null terminate the hash
}

// Function to create a new block
struct Block* createBlock(uint32_t number, uint32_t nonce, struct Transaction* transactions, uint32_t numTransactions, char* previousHash) {
    struct Block* block = malloc(sizeof(struct Block));

    block->number = number;
    block->nonce = nonce;
    block->timestamp = time(NULL);
    block->transactions = malloc(numTransactions * sizeof(struct Transaction));
    block->numTransactions = numTransactions;
    block->previousHash = strdup(previousHash);
    calculateBlockHash(block);

    return block;
}

// Function to free memory allocated for a block
void freeBlock(struct Block* block) {
    free(block->transactions);
    free(block->previousHash);
    free(block);
}

// Function to display a block
void displayBlock(struct Block* block) {

    printf("Block #%d\n", block->number);
    printf("Hash: %s\n", block->hash);
    printf("Nonce: %d\n", block->nonce);
    printf("Timestamp: %s", ctime(&block->timestamp));
    printf("Previous hash: %s\n", block->previousHash);
    printf("Transactions:\n");
}
