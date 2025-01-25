#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 20

// typedef enum {SAVINGS, CURRENT, FD} AccountType;

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
    char password[20];
    // AccountType accountType; // Savings, Current, or FD
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// I use global variables for manager details. Because maanger's details fixed.
char managerName[50];
char managerContact[20];
char branchName[50];

// Notification function
void sendNotification(char *message) {
    printf("Notification: %s\n", message);
}

// Function to create a new account
void create_Account() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter account Number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    printf("Enter password: ");
    scanf("%s", newAccount.password);

    // printf("Choose account type (0 = Savings, 1 = Current, 2 = FD): ");
    // int type;
    // scanf("%d", &type);
    // newAccount.accountType = (AccountType)type;

    newAccount.balance = 0.0;

    accounts[numAccounts++] = newAccount;
    sendNotification("Account created successfully!");
}

// Function for account login
void login() {
    int accNumber;
    char password[20];
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber && strcmp(accounts[i].password, password) == 0) {
            printf("Login successful! Welcome %s.\n", accounts[i].name);
            return;
        }
    }
    printf("Invalid account number or password.\n");
}

// Function to deposit money
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
            sendNotification("Deposit successful.");
            printf("Money deposited successfully!\nNew balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    int accNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                sendNotification("Withdrawal successful.");
                printf("Money withdrawn successfully! New balance: $%.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to view account details
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
            printf("Manager Name: %s\n", managerName);
            printf("Manager Contact: %s\n", managerContact);
            printf("Branch Name: %s\n", branchName);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to search for an account by name
void searchAccountByName() {
    char name[50];
    printf("Enter account holder name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Account found: %d\n", accounts[i].accountNumber);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to delete an account
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
            sendNotification("Account deleted successfully!");
            printf("Account deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
}

// Function to add or update manager details
void updateManagerDetails() {
    printf("\n~ Bank Manager Details ~\n");
    printf("------------------------\n\n");
    printf("Manager Name: Md. Arman Hussan\n");
    printf("Contact Number: +880193-0493012\n");
    printf("Branch Name: Jalalabad branch, Sylhet-1219\n");

}

// Main function to display the menu
int main() {
    int choice;

    do {
        printf("\n~ Bank Management System ~\n\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. View Account Details\n");
        printf("6. Search Account by Name\n");
        printf("7. Delete Account\n");
        printf("8. Manager's Details\n");
        printf("9. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_Account(); 
            break;
            case 2: login(); 
            break;
            case 3: depositMoney(); 
            break;
            case 4: withdrawMoney(); 
            break;
            case 5: viewAccountDetails(); 
            break;
            case 6: searchAccountByName(); 
            break;
            case 7: deleteAccount(); 
            break;
            case 8: updateManagerDetails(); 
            break;
            case 9: printf("Exiting...\n"); 
            break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}
