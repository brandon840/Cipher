/*
 Program to implement a text cipher
 *************************************************************
 * Author	Dept		Date		Notes
 * ***********************************************************
 * Brandon Ma	Comp.Science.	Mar 13 2021	Initial version
 * Brandon Ma	Comp. Science.	Mar 16 2021	Finalized version
 *
 * Note: Fullscreen is better to visualize
 *
*/
#include <stdio.h>

int main(int argc, char *argv[]){

 if (argc != 4){
	return 1;
 }

 //Check if the option is valid
 if (argv[1][0]!='-' || (argv[1][1] != 'd' && argv[1][1] != 'e') || argv[1][2]!='\0'){

	printf("Error %s is not a valid option\n", argv[1]);
	return 1;
 } 

 //Check if the key is valid
 //First check if for if the message is non empty, then  empty
 if (argv[3][0]!=0){

	 	if ((argv[2][1]!='\0' && argv[2][2]!='\0') || argv[2][1]=='\0' && !(argv[2][0]>='2' && argv[2][0]<='9') ||  argv[2][2]=='\0' && !(argv[2][0] == '1' && argv[2][1] == '0')){
			printf("Error %s is not a valid key\n", argv[2]);
			return 1;
		}

 }else{

	 	if (argv[2][2]!='\0' || (argv[2][1]=='\0' && !(argv[2][0]>='2' && argv[2][0]<='9')) || (argv[2][1]!='\0' && !(argv[2][0] == '1' && argv[2][1] == '0'))){
			printf("Error %s is not a valid key\n",argv[2]);
			return 1;
		}
 }
 
 
 //If the message is empty, don't do anything
 if (argv[3][0] == 0){
	printf("\n"); 
	return 0;
 }

 if (argv[1][1] == 'e'){
 	int key;
	int lenMsg=0;
 	int row=1;
 	int step,start1,start2;


 	//Get the length of the message
 	while (argv[3][lenMsg]!='\0'){
 		lenMsg++;
 	}

 	//Get integer value for the key
 	if (argv[2][1] != '\0'){ 
 		key = 10;
 	}else{
 		key = argv[2][0] - '0'; //Gets the integer value of a string integer	
 	}

 	step = 2*key-2;

 	while (row<=key){

		start1 = row-1;
		start2 = start1 + step - (2*row-2);
	
		while (start1<lenMsg || start2<=lenMsg){

			putchar(argv[3][start1]);

			if (start2<lenMsg && row!=1 && row!=key){
			
				putchar(argv[3][start2]);
			}

			start1+=step;
			start2+=step;
		}
		row++;
 	}


 }

 printf("\n");
 return 0;
}
