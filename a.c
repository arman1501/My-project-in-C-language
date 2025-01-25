#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 20

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
    char managerName[50];
    char managerContact[15];
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    printf("Enter account manager's name: ");
    scanf("%s", newAccount.managerName);
    printf("Enter account manager's contact number: ");
    scanf("%s", newAccount.managerContact);
    newAccount.balance = 0.0;

    accounts[numAccounts++] = newAccount;
    printf("Account created successfully!\n");
}

void viewAccountDetails() {
    int accNumber;
    printf("Enter account number: ");
    scanf("%d", &accNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("\n--- Account Details ---\n");
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: $%.2f\n", accounts[i].balance);
            printf("Manager Name: %s\n", accounts[i].managerName);
            printf("Manager Contact: %s\n", accounts[i].managerContact);
            return;
        }
    }
    printf("Account not found!\n");
}

void depositMoney() {
    int accNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            accounts[i].balance += amount;
            printf("Money deposited successfully! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void updateManagerDetails() {
    int accNumber;
    printf("Enter account number to update manager details: ");
    scanf("%d", &accNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("Enter new manager name: ");
            scanf("%s", accounts[i].managerName);
            printf("Enter new manager contact number: ");
            scanf("%s", accounts[i].managerContact);
            printf("Manager details updated successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void deleteAccount() {
    int accNumber, found = 0;
    printf("Enter account number to delete: ");
    scanf("%d", &accNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            found = 1;
            printf("Account deleted successfully!\n");
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
        printf("\n\n ~ Bank Management System ~ \n\n");
        printf("1. Create an account\n\n");
        printf("2. View account details\n\n");
        printf("3. Deposit money\n\n");
        printf("4. Manager details\n\n");
        printf("5. Account delete\n\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccountDetails(); break;
            case 3: depositMoney(); break;
            case 4: updateManagerDetails(); break;
            case 5: deleteAccount(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
    
    return 0;
}
