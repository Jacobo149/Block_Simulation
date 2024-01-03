#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

// Struct to define transaction
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
struct Transaction* createTransaction(char* sender, char* receiver, int amount, int fee, time_t timestamp, int id, int signature) {
    struct Transaction* transaction = malloc(sizeof(struct Transaction));
    transaction->sender = strdup(sender);
    transaction->receiver = strdup(receiver);
    transaction->amount = amount;
    transaction->fee = fee;
    transaction->timestamp = timestamp;
    transaction->id = id;
    transaction->signature = signature;
    return transaction;
}

// Function to free memory allocated for a transaction
void freeTransaction(struct Transaction* transaction) {
    free(transaction->sender);
    free(transaction->receiver);
    free(transaction);
}

// Function to display a transaction
void displayTransaction(struct Transaction* transaction){
    printf("Transaction Details:\n");
    printf("Sender: %s\n", transaction->sender);
    printf("Receiver: %s\n", transaction->receiver);
    printf("Amount: %d\n", transaction->amount);
    printf("Fee: %d\n", transaction->fee);
    printf("Timestamp: %ld\n", transaction->timestamp);
    printf("ID: %d\n", transaction->id);
    printf("Signature: %d\n", transaction->signature);

}
