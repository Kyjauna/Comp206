#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
//get the payload from the last page
int goldpieces;
char *input=(getenv("QUERY_STRING"));

int linecount = 0;
int splitLines = 11;
char line[256];

//find and parse the gold pieces

printf("Content-Type:text/html\n\n");
sscanf(input, "gold=%d", &goldpieces);

FILE* file = fopen( "index.html" , "rt" );
        if ( file == NULL ) {
                printf( "Can't open input file.");
        }
//here we print out each line of index.html until we reach line 11, 
//where we isert the hidden field that passes our value through the payload!
while(fgets(line, sizeof(line), file) != NULL) {
    linecount++;
    printf("%s", line);
    if (linecount == splitLines) {
            printf("<input type=\"text\" name=\"answer\" size=\"25\">");
        printf("<input type=\"hidden\" name=\"gold\" value=\"%d\"", goldpieces);
    }
}
}
