
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 20

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter account Number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account Holder name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;

    accounts[numAccounts++] = newAccount;//we add on the new index
    printf("Account created Successfully!\n");
}

void depositMoney() {
    int accNumber;
    float amount;
    printf("Enter account Number: ");
    scanf("%d", &accNumber);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            accounts[i].balance += amount;
            printf("Money deposited Successfully!\nNew balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdrawMoney() {
    int accNumber;
    float amount;
    printf("Enter account Number: ");
    scanf("%d", &accNumber);
    printf("Enter amount to Withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Money withdrawn Successfully!\nNew balance: $%.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void viewAccountDetails() {
    int accNumber;
    printf("Enter account Number: ");
    scanf("%d", &accNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("\n--- Account Details ---\n");
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    
    do {
        printf("\n\n ~ Bank Management System ~\n\n");
        printf("1. Create an Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: viewAccountDetails(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    
    return 0;
}