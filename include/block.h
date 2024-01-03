// block.h

#ifndef BLOCK_H
#define BLOCK_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
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
void calculateBlockHash(struct Block* block);

// Function to create a new block
struct Block* createBlock(uint32_t number, uint32_t nonce, struct Transaction* transactions, uint32_t numTransactions, char* previousHash);

// Function to free memory allocated for a block
void freeBlock(struct Block* block);

// Function to display a block
void displayBlock(struct Block* block);

#endif // BLOCK_H