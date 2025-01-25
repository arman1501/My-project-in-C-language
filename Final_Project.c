#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 20 // Maximum number of Accounts.

// Using structure.
typedef struct
{
    int accountNumber;
    char name[50];
    float balance;
    char password[20];

} Account;

// Creating an array of accounts.
Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

// Manager details function and fixed details.
void Manager_Details()
{
    printf("\n- Bank Manager Details -\n");
    printf("Manager Name: Md. Arman Hussan.\n");
    printf("Contact Number: +880193-0493012\n");
    printf("Branch Name: Jalalabad branch, Sylhet-1219\n\n");
}

// Notification function uses all functions for notifications.
void notification(char *message)
{
    printf("Notification: %s\n", message);
}

// Function to create a new account.
void create_Account()
{
    if (num_accounts >= MAX_ACCOUNTS)
    {
        printf("Maximum limit reached.\n");
        return;
    }

    // Creating a new account and taking input from the user.

    Account(new_account); // Define structure function.
    printf("Enter account Number: ");
    scanf("%d", &new_account.accountNumber);
    printf("Enter account Holder name: ");
    scanf("%s", new_account.name);
    printf("Enter password: ");
    scanf("%s", new_account.password);

    new_account.balance = 0.0; //

    accounts[num_accounts++] = new_account;
    notification("Account created Successfully!!");
}

// Function for account login
void login()
{
    int accNumber;
    char password[20];
    printf("Enter account Number: ");
    scanf("%d", &accNumber);
    printf("Enter password: ");
    scanf("%s", password);

    // Checking the account number and password using a loop.
    for (int i = 0; i < num_accounts; i++)
    {
        if (accounts[i].accountNumber == accNumber && strcmp(accounts[i].password, password) == 0)
        {
            printf("Login Successful! %s Welcome to Jalalabad branch.\n", accounts[i].name);
            return;
        }
    }
    printf("Invalid account Number or Password.\n");
}

// Function to deposit money
void deposit_money()
{
    int acc_number;
    float amount;
    printf("Enter account Number: ");
    scanf("%d", &acc_number);
    printf("Enter amount to Deposit: ");
    scanf("%f", &amount);

    // Checking the account number and depositing money using a loop.
    for (int i = 0; i < num_accounts; i++)
    {
        if (accounts[i].accountNumber == acc_number) // Checking the account number.
        {
            accounts[i].balance += amount;
            notification("Deposit successful.");
            printf("Money deposited Successfully! New balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!!\n");
}

// Function to withdraw money and checking the account number and balance.
void withdraw_money()
{
    int acc_number1;
    float withdraw_amount;
    printf("Enter account Number: ");
    scanf("%d", &acc_number1);
    printf("Enter amount to Withdraw: ");
    scanf("%f", &withdraw_amount);

    for (int i = 0; i < num_accounts; i++) // Checking the account number.
    {
        if (accounts[i].accountNumber == acc_number1)
        {
            if (accounts[i].balance >= withdraw_amount)
            {
                accounts[i].balance -= withdraw_amount;
                notification("Withdrawal Successful.");
                printf("Money withdraw Successfully! New balance: $%.2f\n", accounts[i].balance);
            }
            else
            {
                printf("Insufficient balance!!\n");
            }
            return;
        }
    }
    printf("Account not found!!\n");
}

// Function to view account details
void view_details()
{
    int accNumber;
    printf("Enter account number: ");
    scanf("%d", &accNumber);

    for (int i = 0; i < num_accounts; i++)
    {
        if (accounts[i].accountNumber == accNumber)
        {
            printf("\n-- Account Details --\n");
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Total Balance: $%.2f\n\n", accounts[i].balance);

            return;
        }
    }
    printf("Account not found!\n");
}

// Function to search for an account by name
void search_name()
{
    char name[50];
    printf("Enter account Holder name to Search: ");
    scanf("%s", name);

    for (int i = 0; i < num_accounts; i++) // loop for checking the account holder name.
    {
        if (strcmp(accounts[i].name, name) == 0)
        {
            printf("Account found: %d\n", accounts[i].accountNumber);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to delete an account.
void delete_account()
{
    int acc_number3, delete = 0;
    printf("Enter account Number to Delete: ");
    scanf("%d", &acc_number3);

    for (int i = 0; i < num_accounts; i++)
    {
        if (accounts[i].accountNumber == acc_number3)
        {
            for (int j = i; j < num_accounts - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }
            num_accounts--;
            delete = 1;
            notification("Account deleted Successfully!");
            break;
        }
    }
    if (!delete)
    {
        printf("Account not found!\n");
    }
}

// Main function to display the menu and call the functions.
int main()
{
    int option;

    do
    {
        printf("\n-- Bank Management System --\n");
        printf("1. Create An Account.\n");
        printf("2. Login.\n");
        printf("3. Deposit Money.\n");
        printf("4. Withdraw Money.\n");
        printf("5. View Account Details.\n");
        printf("6. Search Account by Name.\n");
        printf("7. Delete Account.\n");
        printf("8. Manager's Details.\n");
        printf("9. Exit.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        // Switch case for calling the functions.
        switch (option)
        {
        case 1:
            create_Account();
            break;
        case 2:
            login();
            break;
        case 3:
            deposit_money();
            break;
        case 4:
            withdraw_money();
            break;
        case 5:
            view_details();
            break;
        case 6:
            search_name();
            break;
        case 7:
            delete_account();
            break;
        case 8:
            Manager_Details();
            break;
        case 9:
            printf("Exiting..\n");
            break;
        default:
            printf("Invalid choice!!\n");
        }
    } while (option != 9);

    return 0;
}
