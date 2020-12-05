#include <stdio.h>
#include "myBank.h"

#define Min_account_num 901
#define Max_account_num 950
#define Account_amount 50
#define Account_information 3
#define openORclose 0
#define balance 1
#define account_number 2

//Initializes an array to zeros
//double Bank_Accounts[50][3]
double Bank_Accounts[Account_amount][Account_information] = {0};

//create all the arr with the account number (901-950) and initializes an array to zeros
void create() {
  int ACC_NUM = 901;
  for (int i = 0; i < Account_amount; i++) {

    Bank_Accounts[i][openORclose] = 0;
    Bank_Accounts[i][balance] = 0;
    Bank_Accounts[i][account_number] = ACC_NUM;
    ACC_NUM++;
  }
  return;
}

//A variable that the input from the user will enter
double number = 0.0;
//counter
int count = 0;

//This function rounds a number to a specified number of digits
double round(double x) {
  x = x * 100;
  x = x / 100;
  return x;
}

// This function opens a new bank account
void Open_Account(){
  for (int i = 0; i < Account_amount; i++) {
    if (Bank_Accounts[i][openORclose] == 0) {
      printf("Please enter amount for deposit: ");

      //The scanf read only one value . 
      if (scanf("%lf", & number) == 1) {
        if (number < 0) {
          printf(" It is not possible to open an account with a negative number");
          break;
        }
         else {
          //Change from 0 which means closed to 1 which means open
          Bank_Accounts[i][openORclose] = 1;
          //Change to the balance entered by the user
          Bank_Accounts[i][balance] = round(number);

          count++;
          printf("New account number is: %d \n", i + Min_account_num);
        }
      } else {
        printf("Failed to read the amount\n");
      }
      break;
    }
  }

  // If there are already 50 accounts open
  if (count == Account_amount) {
    printf(" Sorry there is no place for more accounts\n ");
  }
}

//This function checks and returns the balance of the user account
void Balance_Inquiry(){
  int temp_dep = 0;
  int status = 0;

  printf("Please enter account number: ");
  if (scanf("%d", & temp_dep) == 1) {
    //Checks if the account number is in range: 901-950
    if (temp_dep < Min_account_num || temp_dep > Max_account_num) {
      printf("Invalid account number\n");
    } 
    else {
      for (int i = 0; i < Account_amount; i++) {
        // Finding the bank account of the user out of all the accounts
        if (Bank_Accounts[i][account_number] == temp_dep) {
          //chaek if the account is open or close
          status = Bank_Accounts[i][openORclose];
          if (status == openORclose) {
            printf("This account is closed\n");
            break;
          } else {
            printf("The balance of account number %d is: %0.2lf\n", i + Min_account_num, Bank_Accounts[i][balance]);
          }
          break;
        }
      }
    }
  }
  else {
    printf("Failed to read the account number\n");
  }
}
//This function deposits the amount it receives from the user for a balance in his bank account 
//and prints the new balance
void Deposit(){
  int temp_dep = 0;
  double new_balance = 0.0;
  int status = 0;

  printf("Please enter account number: ");
  if (scanf("%d", & temp_dep) == 1) {
    if (temp_dep < Min_account_num || temp_dep > Max_account_num) {
      printf("Invalid account number\n");
    } 
    else {
      for (int i = 0; i < Account_amount; i++) {
        if (Bank_Accounts[i][account_number] == temp_dep) {
          status = Bank_Accounts[i][openORclose];
          if (status == openORclose) {
            printf("This account is closed\n");
            break;
          } 
          else {
            printf("Please enter the amount you want to deposit :");
            if (scanf("%lf", & new_balance) == 1) {
              if (new_balance < 0) {
                printf(" It is not possible to open an account with a negative number\n");
                break;
              } 
              else {
                Bank_Accounts[i][balance] += round(new_balance);
              }
             printf("The new balance is: %0.2lf\n", Bank_Accounts[i][balance]);
              break;
          }
          else{
           printf("Failed to read the amount\n");
            } 
            break;
          }
        } 
      }
    }
  }
   else {
    printf("Failed to read the account number\n");
  }
}

//This function withdraws the amount it receives from the balance of the user's bank account 
//only if there is enough cash in the account

void withdrawal(){
  int temp_dep = 0;
  double Withdrawal_amount = 0.0;
  double new_balance = 0.0;
  int status = 0;

  printf("Please enter account number: ");
  if (scanf("%d", & temp_dep) == 1) {

    if (temp_dep < Min_account_num || temp_dep > Max_account_num) {
      printf("Invalid account number\n");
    }
    else {
      for (int i = 0; i < Account_amount; i++) {
        if (Bank_Accounts[i][account_number] == temp_dep) {
          status = Bank_Accounts[i][openORclose];
          if (status == openORclose) {
            printf("This account is closed\n");
            break;
          } 
          else {
            printf("Please enter the amount to withdraw: ");
            if (scanf("%lf", & Withdrawal_amount) == 1) {
              if (Withdrawal_amount < 0) {
                printf("It is not possible to draw a negative number\n");
                break;
              } 
              else {

                // Checks if the amount he wanted to withdraw is not greater than the balance he has in the account
                if ((Bank_Accounts[i][balance] - round(Withdrawal_amount) < 0.0) || Withdrawal_amount > Bank_Accounts[i][balance]) {
                  printf("Cannot withdraw more than the balance\n");
                  break;
                } 
                else {
                  Bank_Accounts[i][balance] = Bank_Accounts[i][balance] - round(Withdrawal_amount);
                }
                printf("The new balance is: %0.2lf\n", Bank_Accounts[i][balance]);
              }
            }
            else{
              printf("Failed to read the amount\n");
            }
            break;
          }

        }
      }

    }
  } 
  else {
    printf("Failed to read the account number\n");
  }
}

//This function closes an account that exists and is open
void Close_Account(){
  int temp_acc = 0;
  int status = 0;

  printf("Please enter account number: ");
  if (scanf("%d", & temp_acc) == 1) {
    if (temp_acc < Min_account_num || temp_acc > Max_account_num) {
      printf("Invalid account number\n");
    } 
    else {
      for (int i = 0; i < Account_amount; i++) {
        if (Bank_Accounts[i][account_number] == temp_acc) {
          status = Bank_Accounts[i][openORclose];
          if (status == openORclose) {
            printf("This account is already closed\n");
            break;
          } 
          else {
            // close the account
            Bank_Accounts[i][openORclose] = 0;
            //Resets the balance
            Bank_Accounts[i][balance] = 0;
            printf("Closed account number %d\n", temp_acc);
          }
          break;
        }
      }
    }
  } 
  else {
    printf("Failed to read the account number");
  }
}

//This function adds interest at a given percentage rate to all accounts open
void Adding_Interest(){

  int interest = 0;
  printf("Please enter interest rate: ");
  if (scanf("%d", & interest) == 1) {

    if (interest < 0) {
      printf("You can't enter negative rate, try again.\n");
    } else {
      for (int i = 0; i < Account_amount; i++) {
        if (Bank_Accounts[i][openORclose] == 1) {
          Bank_Accounts[i][balance] *= 1 + (interest / 100.);
          Bank_Accounts[i][balance] = round(Bank_Accounts[i][balance]);
        }
      }
    }
  } else {
    printf("Failed to read the interest rate\n");
  }
}

//This function prints all open accounts with their balance
void Print_Account(){

  for (int i = 0; i < Account_amount; i++) {
    if (Bank_Accounts[i][openORclose] == 1) {
      printf("The balance of account number %d is: %0.2lf\n", i + Min_account_num, Bank_Accounts[i][balance]);
    }
  }
}
//This function closes all accounts and exits the program
void Close_Account_AndExit(){
  for (int i = 0; i < Account_amount; i++) {
    Bank_Accounts[i][openORclose] == 0;
    Bank_Accounts[i][balance] == 0;
  }
}