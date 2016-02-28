#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <time.h>
#include <conio.h>
#define NUMBER 100   
void draw(int state){
		switch(state){
			case 9 :
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|      / \\     \n");
		printf("|__             \n");
			break;
			case 8 :
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|      /|       \n");
		printf("|__             \n");
		printf("\nYou have only one wrong right!\n");
			break;
			case 7 :
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|__             \n");
			break;
			case 6 :
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|       \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|__             \n");
			break;
			case 5 :
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|__             \n");
			break;
			case 4 :
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");
			break;
			case 3 :
		printf(" __________     \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");
			break;
			case 2 :
		printf("                \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");
			break;
			case 1 :
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf(" __             \n");
			break;
			default :
			printf("\nThe man isnt  hanging yet!\n\n");
			break;
			 }
    }
void Line(char *arr, int length){
	int i;
	for( i=0; i<length; i++ )
	{
	   arr[i] = '-';
	}
    
	arr[i] = '\0';
	}
	int main(){
	char letter;
	char *letters;
	int i,true=0,hang=0,false=0,size,word;
    int j,k,l;
    char word1[100][14][8]; 
    char words[NUMBER][14];
    FILE *fptr;
    fptr=fopen("words.txt","r");
    int m[100][14]; char n[100][14];
    char line;
    for(k=0;k<100;k++)
      for( l=0; l<14; l++ )
	   {
         fscanf(fptr,"%s%c",&word1[k][l],&line);
         if(line == '\n') 
		 {
          break;
         }
          
       }
		for(k=0;k<100;k++)
         for(l=0;l<14;l++)
		 {
	
          m[k][l] = (int)(word1[k][l][0]-'0')*128+(int)(word1[k][l][1]-'0')*64+(int)(word1[k][l][2]-'0')*32+(int)(word1[k][l][3]-'0')*16+(int)(word1[k][l][4]-'0')*8+(int)(word1[k][l][5]-'0')*4+(int)(word1[k][l][6]-'0')*2+(int)(word1[k][l][7]-'0')*1;
          if(m[k][l]==92)
          {
          	words[k][l]='\0';
			break;  	
          }
         else
         n[k][l]=(char)m[k][l];
         words[k][l]=n[k][l];
         }
         fclose(fptr);
     	 
    	 srand(time(NULL));
    	
    	 word = rand() % NUMBER;
         
	    size = strlen(words[word]);
    	 
    	 letters = (char *)malloc(size + 1 * sizeof(char));
    	 if( letters == NULL ){ printf("Allocation of memory is unsuccessful!");
		  return 0; }
    	
	     Line(letters, size);
    	
    	 printf("Please dont use turkish characters! \n");
         while( hang != 9 && false != size){
          
			printf("\nenter the letter : ");
			scanf("%c", &letter);
         for( i=0; i<size; i++ ){
		
			if( letter == words[word][i] ){
				letters[i] = letter;
				false++;
			    true = 1;
			}
		 } 
            if(true != 1 ){
			
			hang++;
		 }  
		 else {
			
			true = 0;
		 } 
          printf("\nThe last state   : ");
		  draw(hang);
          printf("\nThe  word : ");
		  puts(letters);
          
		  getchar(); 
	}
          printf("\n\n");
		  if( hang != 9 ){
			
			printf("Congrulations.You found it\n");
		  } 
		   else {
			
			printf("Wrong guess.Try again\n");
 			printf("The Word is: %s", words[word]);
		  }
          
		    free(letters);
		    return 0;
		    getchar();
}

