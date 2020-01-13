#include <stdio.h>
#include <stdlib.h>

/*Kyjauna Marshall 260802473*/

int main(int argc, char* argv[]){
 if(argc == 1){ /*if no args were given*/

        int i,j, size; /*initializing int variables*/
        char term;

        printf("\nWhat size would you like your triangle to be?\nEnter here ==> : ");

       
if(scanf("%d%c", &size, &term) != 2 || term != '\n' || size <=0) /*checks for invalid inputs*/

        printf("An incorrect triangle size was inputted. The size must be greater than 0 and an integer number. Syntax: ./triangles SIZE\n\n");
else		
  for(i=1; i<=size; i++) {
        /* Print spaces in decreasing order*/
        for(j=i; j<size; j++) {
            printf(" ");
        }
        /* Print star in increasing order */
        for(j=1; j<=i; j++) {
            printf("*");
        }
	 /* Move to next line */
        printf("\n");
    }
return 0;
}
else if(argc == 2){ /*argument was given*/
        char *a =argv[1];
        int size = atoi(a);
        int h, k;
if(size  <=  0){
        printf("\nAn incorrect triangle size was inputted. The size must be greater than 0 and an integer number. Syntax: ./triangles SIZE\n\n");
}
else
for(h=1; h<=size; h++) {
        for(k=h; k<size; k++) {
            printf(" ");
        }
        for(k=1; k<=h; k++){
            printf("*");
        }

        printf("\n");
	}
   return 0;
   }
}
