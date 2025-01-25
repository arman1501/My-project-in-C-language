# Bank Management System--

This is a simple Bank Management System implemented in C. It allows users to create accounts, log in, deposit and withdraw money, view account details, search for accounts by name, and delete accounts. Additionally, it includes manager details and notifications for various actions.

## Features

- **Create a New Account**: Users can create new bank accounts.
- **Login**: Users can log in to their accounts using their account number and password.
- **Deposit Money**: Users can deposit money into their accounts.
- **Withdraw Money**: Users can withdraw money from their accounts.
- **View Account Details**: Users can view the details of their accounts.
- **Search Account by Name**: Users can search for accounts by the account holder's name.
- **Delete an Account**: Users can delete existing accounts.
- **View Manager's Details**: Users can view the bank manager's details.
- **Notifications**: Various actions trigger notifications for the users.

## File Structure


## Compilation and Execution

To compile and run the program, follow these steps:

1. Open a terminal and navigate to the directory containing the `main.c` file.
2. Compile the program using a C compiler (e.g., `gcc`):

   ```bash
   gcc main.c -o bank_management_system
## Run the compiled program:
./bank_management_system

## Data Structures
Account: A structure to hold account details, including account number, name, balance, and password.

## Main Functions
Manager_Details: Displays the bank manager's details.

notification: Displays a notification message.

create_Account: Creates a new bank account.

login: Allows a user to log in to their account.

deposit_money: Deposits money into an account.

withdraw_money: Withdraws money from an account.

view_details: Displays account details.

search_name: Searches for an account by the account holder's name.

delete_account
