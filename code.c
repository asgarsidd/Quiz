#include<stdio.h>
#include<stdlib.h>//to use the system("cls") function

//...................................................GLOBAL VARIBLE DECLARATION so that variables can be used in any function.........................................................................................
int i, coins=0, highscore=0;
char name[20], input, ans;

//...................................................PROTOTYPE DECLARATION for functions being used in the program....................................................................................................
void main_menu();
void correct();
void incorrect();
void play();
void high_score();
void alter_high_score();
void ask_question(int value_of_question_in_coins, char question[200] , char a[100] , char b[100] , char c[100] , char d[100] , char correct_ans_small, char correct_ans_capital);

//...................................................MAIN FUNCTION.....................................................................................................................................................

void main()
{
	printf("Please type your name and press enter- ");
	fflush(stdin);
	gets(name);//gets used to accept whole name with spaces in between
	system("cls");//In devcpp, can't use include conio.h to use clrscr(as conio.h is not a standard c language library.) So included stdlib.h and used sustem("cls")
	printf("\n\nHello %s! \n\n\n...................welcome to....................\n...........\'KAUN   BANEGA   COIN-PATI\'........... ",name);
	main_menu();	
}

____TO 41___

void correct()
{
	printf("\n\nCorrect!\n\nScore=%d coins\n\nPress M to go to main menu.\n\nPress any other key to continue. ",coins);
	fflush(stdin);
	scanf("%c",&ans);
		
	if(ans =='m' || ans=='M')
	main_menu();
	else
	system("cls");
}
	
void incorrect()
{
		system("cls");
		printf("Your response is incorrect.\n");
		alter_high_score();
}
		

void high_score()
{
	FILE *file_pointer1, *file_pointer2;
	char ch;
	file_pointer1=fopen("quiz_highscore.txt","r");
	file_pointer2=fopen("quiz_highscore_holder.txt","r");
	
	if(file_pointer1==NULL)
	printf("\n\nCannot open target file. Contact the developer.");
	
	printf("\nCurrent highscore is ");
	
	while((ch=getc(file_pointer1))!=EOF)
	printf("%c",ch);
	
	printf(" coins.\nThis amazing feat was archieved by ");
	
	while((ch=getc(file_pointer2))!=EOF)
	printf("%c",ch);
	
	printf(".");
	
	fclose(file_pointer1);
	fclose(file_pointer2);
	
}	
	
void alter_high_score()
{	
   FILE *file_pointer, *file_pointer1, *file_pointer2;  
   char highscore_as_char[10];//creating char array to store data of file  
   
   file_pointer= fopen("quiz_highscore.txt", "r");  

   while(fscanf(file_pointer, "%s", highscore_as_char)!=EOF)
   {  
   		//printf("%s ", buff );  
   }   
   
   highscore = atoi(highscore_as_char);//converts char to int
   
   if(coins>highscore)
   {
   		highscore=coins;
   		printf("\n\n************************************\nCongratulations %s!\nYou have made a new highscore of %d coins !\n************************************",name,coins);
   	
		file_pointer1=fopen("quiz_highscore.txt","w");// the w mode overwrites and clears all data in the txt file...
		file_pointer2=fopen("quiz_highscore_holder.txt","w");
	
		if(file_pointer1==NULL || file_pointer2 ==NULL)
		printf("\n\nCannot open target file. Contact the developer.");
		else
		{
			fprintf(file_pointer1,"%d",coins); 
			fprintf(file_pointer2,"%s",name); 				
		}
		
		   fclose(file_pointer1);  
   	       fclose(file_pointer2); 
   		}
   else if(coins<highscore)
   {
   		printf("\n\nYou have earned %d coins but that is not enough to beat the highscore...\nTry again!",coins);
   }
   else if(coins=highscore)
   {
   		printf("\n\n*****************************************\nYou have earned %d coins %s.\nThat is the same as the current highscore!\n*****************************************",coins,name);
   }
    
    printf("\n\npress E to exit.\n\nPress any other key to go back to main menu.");
    fflush(stdin);
	scanf("%s",&input);
				
	if(input== 'E' || input== 'e')
	{
		system("cls");
		exit(0);
	}
	else
	{
		system("cls");
		main_menu();		
	}
		
}
