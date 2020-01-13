//Kyjauna Marshall
//260802473
//Katie Younge
//260799539
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
       //first we need to get the payload so we can see what the players command was and their gold value
        char* input = getenv("QUERY_STRING"); 
        
        //next we need to tokenize the payload into stuff we can use.
        //we want to ignore special characters & and = , we use strtok to do this
        char* token = strtok(input, "=&");
        char * field[4];
        int i = 0;
        
        //using our delimeters we can take the payload and seperate it into its 4 fields
        //we know the fields are four because our payload runs off 2 pieces of data
        //our fields will be in the form of ("command, NORTH, gold, 50 ")
        while (token!= NULL){
                field[i]=token;
                token=strtok(NULL,"=&");
                i++;
        }
       //we now assign goldpieces to our field value
       //we know that if the field is 0 yet we haven't lost, that means the player is just starting the game,
       //so we set goldpieces to 10 if 0, otherwise we take the value of goldpieces from the payload
        int goldpieces;

        if(atoi(field[3]) == 0){  
          goldpieces = 10;
        }
        else{
          goldpieces = atoi(field[3]);
        }

        char answer[30];
        strcpy(answer, field[1]);
        
        //here we are telling the browser what language we will be speaking to it 
        printf("Content-Type:text/html\n\n");
        printf("<html>");
        printf("<body><center>");

        //first we check if the users input was NOT one of the 5 commands, that way we can assume they are attempting the question 
        //Our question is "spell the profs last name" and intermediate question related to COMP 206

        if((strcmp(answer, "NORTH") != 0)&&(strcmp(answer, "EAST") != 0)&&(strcmp(answer, "SOUTH") != 0)&&(strcmp(answer, "WEST") != 0)&&(strcmp(answer, "GOLD") != 0)){
                // here we check if the input is the correct answer, if it is we add 10 pieces of gold.
                // If the gold is >= 100 the player wins the game, else we offer links to keep progressing. 
                // If the player guessed wrong we subtract 5 pieces of gold and check that they are still >0 else they lose.

                if(strcmp(answer, "Vybihal") == 0){
                        goldpieces = goldpieces + 10;

                        if(goldpieces >= 100){
                                printf("YOU WON! CONGRADULATIONS");
                        }
                        else{
                                printf("CORRECT! keep going bro");
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go North</a>", goldpieces);
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~wbouch4/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go East</a>", goldpieces);
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~mbutea/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go South</a>", goldpieces);
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~doball/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go West</a>", goldpieces);
                        }
                }
                else{
                  goldpieces = goldpieces - 5;

                        if(goldpieces <= 0){
                                printf("you lost ya big loser :/");
                        }
                        else{
                            printf("You dont even know our profs name? C'mon (wo)man");
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go North</a>", goldpieces);
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~wbouch4/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go East</a>", goldpieces);
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~mbutea/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go South</a>", goldpieces);
                                printf("<br/><a href=\"https://www.cs.mcgill.ca/~doball/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go West</a>", goldpieces);
                              } 
                }
        }
        //outside our initial if have our else statement which guarentees the player input one of the following commands
        //we incrementally check to see which command the player input and direct them to the appropriate link
        else{
                if(strcmp(answer, "NORTH") == 0){
                         printf("<br/><a href=\"https://www.cs.mcgill.ca/~dma24/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go North</a>", goldpieces);
                }
                else if(strcmp(answer, "EAST") == 0){
                        printf("<br/><a href=\"https://www.cs.mcgill.ca/~wbouch4/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go East</a>", goldpieces);
                }
                else if(strcmp(answer, "SOUTH") == 0){
                        printf("<br/><a href=\"https://www.cs.mcgill.ca/~mbutea/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go South</a>", goldpieces);
                }
                else if(strcmp(answer, "WEST") == 0){
                        printf("<br/><a href=\"https://www.cs.mcgill.ca/~doball/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go West</a>", goldpieces);
                }
                else{
                        printf("you have %d gold pieces, you are %d away from winning", goldpieces, 100-goldpieces);
                        printf("<br/><a href=\"https://www.cs.mcgill.ca/~kmarsh14/\">Press HERE to go back</a>");
                }

        }
        //finish up the html body that will be printed to the page
        printf("</center></body>");
        printf("</html>");
    return 0;
}
