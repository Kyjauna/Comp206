//Kyjauna Marshall
//260802473

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
        int size1 = strlen(argv[1]);
        int size2 = strlen(argv[2]); //getting the lengths of the arguments

        if (argc != 3) { //checking that there are the right amount of args to compare
                printf("Wrong number of arguments. Please input: ./reverse WORD1 WORD2.");
        }

        if(size1 == size2){ //initially checks that sizes are the same to proceed
                char word1[100] = ""; //creating empty char arrays
                char word2[100] = "";
                strcat(word1, argv[1]);
                strcat(word2, argv[2]); //putting the chars of arguments in the char arrays
       
		int i;

       //for loop so we can iterate forward from word1 and backwards from word2
       for(i=0; i<size2+1; i++){

                //comparing the letter of word1 with letter of word2 but starts at opposite ends
                if(word1[i] == word2[size2-(i+1)]) {
                }
                else{
                        printf("WORD1= %s WORD2= %s -NOT REVERSE\n", word1, word2);
			return 0;
                }
        
        }
       printf("WORD1= %s WORD2= %s -REVERSE\n", word1,word2);
return 0;
        }
}
