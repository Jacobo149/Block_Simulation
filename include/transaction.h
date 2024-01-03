// transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

// Transaction struct
struct Transaction {
    char* sender;
    char* receiver;
    int amount;
    int fee;
    time_t timestamp;
    int id;
    int signature;
};

// Function to create a transaction
struct Transaction* createTransaction(char* sender, char* receiver, int amount, int fee, int id, int signature);

// Function to free memory allocated for a transaction
void freeTransaction(struct Transaction* transaction);

// Function to display a transaction
void displayTransaction(struct Transaction* transaction);

#endif // TRANSACTION_H
