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

// Fixed manager details
char managerName[50] = "Md. Arman Hussan";
char managerContact[20] = "+8801930-493012";
char managerBranch[50] = "Jalalabad branch, Sylhet-1219";

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

    accounts[numAccounts++] = newAccount;
    printf("Account created Successfully!\n");
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

void depositMoney() {
    int accNumber;
    float amount;
    printf("Enter account Number: ");
    scanf("%d", &accNumber);
    printf("Enter amount to Deposit: ");
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

void viewManagerDetails() {
    printf("\n--- Manager Details ---\n");
    printf("Manager Name: %s\n", managerName);
    printf("Manager Contact: %s\n", managerContact);
    printf("Brach Name: %s\n", managerBranch);

}

void deleteAccount() {
    int accNumber, found = 0;
    printf("Enter account number to Delete Account: ");
    scanf("%d", &accNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            found = 1;
            printf("Account deleted Successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("\n\n~ Bank Management System ~ \n\n");
        printf("1. Create an account\n");
        printf("2. View account details\n");
        printf("3. Deposit money\n");
        printf("4. Manager details\n");
        printf("5. Account delete\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccountDetails(); break;
            case 3: depositMoney(); break;
            case 4: viewManagerDetails(); break;
            case 5: deleteAccount(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
    
    return 0;
}
