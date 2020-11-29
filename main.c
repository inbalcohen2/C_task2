#include <stdio.h>
#include "myBank.h"


int main(){
    
    char selection_func;
    create();
      do {

    
    printf("\nPlease choose a transaction type:\n");
   printf("O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");

   if(scanf(" %c",  &selection_func) != 1){
	printf("\n Failed to read the transaction type\n");
	}
     else{

    switch (selection_func){
    
    case 'O':
        Open_Account(); 
        break;
        

        case 'B':
        Balance_Inquiry();
        break;

        case 'D':
        Deposit();
        break;

        case 'W':
        withdrawal();
        break;

        case 'C':
        Close_Account();
        break;

        case 'I':
        Adding_Interest();
        break;

       case 'P':
        Print_Account();
        break;


	    case 'E':
				Close_Account_AndExit();
				break;

			default:
				printf("\nInvalid transaction type\n");
                break;
			}
       }
      }
       while(selection_func != 'E');
        return 0;
        
      }


