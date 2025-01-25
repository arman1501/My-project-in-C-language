#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 20
#define MAX_TRANSACTIONS 100

typedef enum {SAVINGS, CURRENT, FD} AccountType;

typedef struct {
    char type[10];  // Deposit, Withdraw, Interest
    float amount;
    char date[20];  // e.g., "2025-01-25"
} Transaction;

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
    char password[20];
    AccountType accountType;  // Savings, Current, or FD
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void sendNotification(char *message) {
    printf("Notification: %s\n", message);
}

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

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    printf("Enter password: ");
    scanf("%s", newAccount.password);

    printf("Choose account type (0 = Savings, 1 = Current, 2 = FD): ");
    int type;
    scanf("%d", &type);
    newAccount.accountType = (AccountType)type;

    newAccount.balance = 0.0;
    newAccount.numTransactions = 0;

    accounts[numAccounts++] = newAccount;
    sendNotification("Account created successfully!");
}

void calculateInterest(int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber && accounts[i].accountType == SAVINGS) {
            float interest = accounts[i].balance * 0.05; // 5% annual interest
            accounts[i].balance += interest;
            // Log interest as a transaction
            strcpy(accounts[i].transactions[accounts[i].numTransactions].type, "Interest");
            accounts[i].transactions[accounts[i].numTransactions].amount = interest;
            strcpy(accounts[i].transactions[accounts[i].numTransactions].date, "2025-01-25");
            accounts[i].numTransactions++;
            sendNotification("Interest applied.");
            printf("Interest applied.\nNew balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found or not a savings account.\n");
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
            // Log transaction
            strcpy(accounts[i].transactions[accounts[i].numTransactions].type, "Deposit");
            accounts[i].transactions[accounts[i].numTransactions].amount = amount;
            strcpy(accounts[i].transactions[accounts[i].numTransactions].date, "2025-01-25");
            accounts[i].numTransactions++;
            sendNotification("Deposit Successful.");
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
                // Log transaction
                strcpy(accounts[i].transactions[accounts[i].numTransactions].type, "Withdraw");
                accounts[i].transactions[accounts[i].numTransactions].amount = amount;
                strcpy(accounts[i].transactions[accounts[i].numTransactions].date, "2025-01-25");
                accounts[i].numTransactions++;
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

void viewTransactionHistory(int accNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("\n--- Transaction History ---\n");
            for (int j = 0; j < accounts[i].numTransactions; j++) {
                printf("Type: %s | Amount: $%.2f | Date: %s\n", accounts[i].transactions[j].type, accounts[i].transactions[j].amount, accounts[i].transactions[j].date);
            }
            return;
        }
    }
    printf("Account not found!\n");
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
            return;
        }
    }
    printf("Account not found!\n");
}

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

int main() {
    int choice;
    
    do {
        printf("\n~ Bank Management System ~\n\n");
        printf("1. Create Account:\n");
        printf("2. Login:\n");
        printf("3. Deposit Money:\n");
        printf("4. Withdraw Money:\n");
        printf("5. View Account Details:\n");
        printf("6. View Transaction History:\n");
        printf("7. Search Account by Name:\n");
        printf("8. Delete Account:\n");
        printf("9. Apply Interest to Savings Account:\n");
        printf("10. Exit:\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: createAccount();
            break;
            case 2: login();
            break;
            case 3: depositMoney();
            break;
            case 4: withdrawMoney();
            break;
            case 5: viewAccountDetails();
            break;
            case 6: {
                int accNumber;
                printf("Enter account Number to view Transaction history: ");
                scanf("%d", &accNumber);
                viewTransactionHistory(accNumber);
                break;
            }
            case 7: searchAccountByName();
            break;
            case 8: deleteAccount();
            break;
            case 9: {
                int accNumber;
                printf("Enter account Number to apply interest: ");
                scanf("%d", &accNumber);
                calculateInterest(accNumber);
                break;
            }
            case 10: printf("Exiting...\n");
            break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 10);
    
    return 0;
}
