//Katie Younge
//260799539

//Kyjauna Marshall
//260802473

#include <stdio.h>
#include <stdlib.h>
#include "ssv.h"

//parsing the ssv file for use by main.c

void parse(char record[], int *acct, float *amnt){
    
    sscanf(record, "%d %f", acct , amnt);
    
}
