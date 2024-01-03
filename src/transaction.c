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
/*
int main() {
    // Example usage of createTransaction
    char* sender = "Alice";
    char* receiver = "Bob";
    int amount = 100;
    int fee = 5;
    time_t timestamp = time(NULL);  // Use the current time
    int id = 1;
    int signature = 123456;

    struct Transaction* myTransaction = createTransaction(sender, receiver, amount, fee, timestamp, id, signature);

    // Display information about the created transaction
    printf("Transaction Details:\n");
    printf("Sender: %s\n", myTransaction->sender);
    printf("Receiver: %s\n", myTransaction->receiver);
    printf("Amount: %d\n", myTransaction->amount);
    printf("Fee: %d\n", myTransaction->fee);
    printf("Timestamp: %ld\n", myTransaction->timestamp);
    printf("ID: %d\n", myTransaction->id);
    printf("Signature: %d\n", myTransaction->signature);

    // Free allocated memory
    free(myTransaction->sender);
    free(myTransaction->receiver);
    free(myTransaction);

    return 0;
}
*/