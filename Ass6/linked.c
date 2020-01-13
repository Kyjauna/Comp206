//Katie Younge
//260799539

//Kyjauna Marshall
//260802473

#include<stdio.h>
#include<stdlib.h>
#include "linked.h"

//first we define the struct for the account linked list

struct ACCOUNT {
    int accountNumber;
    float balance;
    struct ACCOUNT *next;
};

//we don't want head to be pointer to anything before we use it in main.c
struct ACCOUNT *head = NULL;

void findUpdate(int account, float amount){
    //here we are creating methods base off the assumption that we do not know what our .ssv file looks like
    
    //if there are NO accounts in the linked list
    if (head==NULL){
        struct ACCOUNT *new = (struct ACCOUNT *) malloc(sizeof(struct ACCOUNT));
        new->accountNumber=account;
        new->balance=amount;
        new->next=NULL;
        head = new;
    }
    //if there ARE accounts in the linked list
    else{
        struct ACCOUNT *temp = head;
        int found = 0;
        while(temp!=NULL){
        
            if (temp->accountNumber==account){
                temp->balance = temp->balance + amount;
                found = 1;
                break;
            }
        
            else temp=temp->next;
    
        }
        //and finally if no account is found
        
        if (!found){
        
            //creating a new account node
            struct ACCOUNT *new = (struct ACCOUNT *) malloc(sizeof(struct ACCOUNT));
            new->accountNumber=account;
            new->balance=amount;
            new->next = head;
            head=new;
        }
               
    }

}


void prettyPrint(){
    //reference struct
    struct ACCOUNT *temp = head;
    //while our file isnt empty, print the contents of the struct
    while(temp != NULL){
        printf("ACCOUNT ID: %5d  BALANCE: $%6.2f\n", temp->accountNumber, temp->balance);
        temp=temp->next; //moves us to the next location from the pointer to print
    }
    
}

