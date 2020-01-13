//Kyjauna Marshall
//260802473

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>

int show(){
        FILE *File = fopen("database.csv", "r");
	//declaring space for the array of records
        char space[100]; 
	//declaring array for specific data
        char ID[10];
        char name[10];
        char age[10];
        char GPA[10];
	//we will use these in our while
        int j=0;
        int n=0;
        int i=0;

        if (File == NULL){
                printf("Problem reading the file \n");
                exit(1);
        }
	//here we are iterating over each row until commas and ignoring spaces
	//we have four pieces of data so we need four for loops so we can seperate each piece of data into their appropriate array
        fgets(space, 100, File);
        while(!feof(File)) {
                n++;
                i=0;
                for (j=0; space[i]!=','; i++){
                        if (space[i]!=' '){
                                ID[j]=space[i];
                                j++;
                        }
                }
                ID[j]='\0';
                i++;
                for (j=0; space[i]!=','; i++){
                        if (space[i]!=' '){
                                name[j]=space[i];
                                j++;
                        }
                }
                 name[j]='\0';
                i++;
                 for (j=0; space[i]!=','; i++){
                        if (space[i]!=' '){
                                age[j]=space[i];
                                j++;
                        }
                }
                age[j]='\0';
                i++;
                for (j=0; j<3; i++){
                  if (space[i]!=' '){
                                GPA[j]=space[i];
                                j++;
                        }
                }

		// converting values to required form
		
                GPA[j]='\0';
                float g = (float)atof(GPA);
                int a = (int)atoi(age);
                int id = (int)atoi(ID);

                printf("Record %-2d: ", n);
                printf("ID = %-10d ", id);
                printf("NAME = %-10s ", name);
                printf("AGE = %-10d ", a);
                printf("GPA = %.1f\n", g);
                n++;
                fgets(space, 100, File);

        }
        fclose(File);
	//dont forget to close your file!
}

void add(int ID, char *name, int age, float GPA){

        FILE *f = fopen("database.csv", "at");
	//opens file with add to 
	
        fprintf(f, "%d, %s, %d, %f\n", ID, name, age, GPA);
        fclose(f);

}

void delete(char *ID){
	//In this method we open the file and create a temp file
        FILE *File = fopen("database.csv", "r");
        FILE *Temp = fopen("database.tmp", "at");
        char space[100];
        char idToDelete[10];
        sprintf(idToDelete, "%s", ID);

        char id[10];
        int j =0;
        int n =0;
        int i =0;
	// define a boolean variable for deleted
        bool isIdDeleted = false;
        while(fgets(space, 100, File)){
                n++;
                i=0;
                for(j=0; space[i] != ','; i++){
                  if(space[i] != ' '){
                        id[j] = space[i];
                        j++;
                }
        }
        id[j] = '\0';
	//use strcmp so we can copy files we want into temp 
        if(strcmp(id, idToDelete) != 0){
                fputs(space, Temp);
        }
        else {
                isIdDeleted = true;
        }
}
if(isIdDeleted == false) {
        printf("name of record to delete is missing\n");
}else{
        fclose(File);
        fclose(Temp);
	//set temp file to orig name and tada!!
	//
        rename("database.tmp", "database.csv");
}
}
int main(int argc, char *argv[]){

    if(argc == 1){
        printf("You did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4\n");
        return 0;
    }

    else if((strcmp(argv[1], "ADD") != 0)&&(strcmp(argv[1], "SHOW") != 0)&&(strcmp(argv[1], "DELETE") != 0)){
        printf("The command you requested is invalid. Please select from one of these: SHOW, DELETE, ADD\n");
    }
    else {
        if(strcmp(argv[1], "ADD") == 0){
                if (argc < 6){
                        printf("Missing ID, Name, AGE, and GPA arguments\n");
                }
                else{
                int ID = atoi(argv[2]);
                float GPA = atof(argv[5]);
		int AGE = atoi(argv[4]);
                add(ID, argv[3], AGE, GPA);
                }
        }
        else if(strcmp(argv[1], "DELETE") == 0){
                if (argc <3){
                        printf("Name of record to delete is missing\n");
                }
                else{
                        //int ID = atoi(argv[2]);
                        delete(argv[2]);
                }
     }
        else if(strcmp(argv[1], "SHOW") == 0){
                show();
        }
    }
}
