//Katie Younge
//260799539

//Kyjauna Marshall
//260802473

#include <stdio.h>
#include <stdlib.h>
#include "ssv.h"
#include "linked.h"

//we use the header files ssv.h and linked.h

int main (){
    FILE *file = fopen("mini6tester.ssv", "r"); //open the file
    
    char line[99]; //space for the line of the file
    int a;
    float b;
    
    //checking if the file was opened
    if (file == NULL){
		printf("Problem reading the file \n");
		exit(1);
	}
    
    //getting a line from the file
    while(fgets(line, 99, file)){
        
        //handing the line and the pointers to the parse function in ssv.c
        parse(line, &a, &b);
        
        //finding and updating the account value from linked.c
        findUpdate(a, b);
        
    }
    
    //printing the linked list
    prettyPrint();
}
