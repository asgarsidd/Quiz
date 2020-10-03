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

void main_menu()
{	
	char what;
	printf("\n\n\n    MAIN MENU\n\n    Key    Function\n\n    P      Play\n    R      Rules\n    C      Credits\n    I      Interesting info\n    H      High score\n    E      Exit\n\n    Please type an input and press enter-");
	fflush(stdin);
	scanf("%c",&input);
	
	switch(input)
	{
		case 'P':  
		case 'p':
				system("cls");
				play();
	       		break;
	       		
	 	case 'R':
		case 'r':
				system("cls");
				printf("RULES:\n\nThe rules of the game are simple.\n\nThe player is presented with a question having four options each.\n\nEach question carries a particular number of coins.\n\nThe number of coins associated with each question is more than the number of coins carried by the previous one.\n\nCorrect answer rewards the player with the coins associated with the question.\n\nAn incorrect answer would lead to loosing the game and the coins associated with the question.\n\n\nPress M to go to the main menu.\n");
				fflush(stdin);
				scanf("%c",&what);
				
				if(what=='m' || what=='M')
				{
					system("cls");
					main_menu();
				}
	   			
	   			else
	   			{
					system("cls");
					printf("illegal input");
					main_menu();//just take the user back to the main menu....
				}
	   						
				break;
	   			
		case 'C':  
		case 'c':	
				system("cls");
				printf("\nThis program was developed by Suyash on in the month of January 2019.\n\nIf you make an edit to the program, go ahead and add your name here!\n\nPress M to go to the main menu. ");
				fflush(stdin);
				scanf("%c",&what);
				
				if(what=='m' || what=='M')
				{
					system("cls");
					main_menu();
				}
				else 
				{
					system("cls");
					printf("illegal input");
					main_menu();//just take the user back to the main menu....
				
				}
				
				break;
				
		case 'H': 
		case 'h':
				system("cls");
				high_score();
				printf("\n\nPress M to go back to the main menu. ");
				fflush(stdin);
				scanf("%c",&what);
				
				if(what=='m' || what=='M')
				{
					system("cls");
					main_menu();
				}
				else 
				{
					system("cls");
					printf("illegal input");
					main_menu();//just take the user back to the main menu....
				
				}
				
				break;
				
		case 'E':  
		case 'e':
				printf("\nAre you sure you want to exit?[y-->exit/n-->back to main menu] ");	
				fflush(stdin);
				scanf("%c",&what);
				
				if(what== 'y' || what=='Y')
				{	
					system("cls");
					printf("\nThank you for playing!");
					exit(0);// 0 means exit the program without nay error messages(if any).
				}	
				else if(what== 'N' || what=='n')
				{
					system("cls");
					main_menu();
				}
				else 
				{
					system("cls");	
					printf("illegal input");
					main_menu();		
				}				
				
				break;
				
		case 'I':
		case 'i':
				 system("cls");
				 printf("Interesting Information!\n\n-->This game contains only a few questions as the developer got bored of adding questions.\n  You are welcome to add more!\n\n-->Developement of this game took over 10 hours of work.\n   (primaraly because the developer is new to this field and had to learn quite a few concepts while making the game.)");
			 	 printf("\n\nPress E to exit\n\nPress any other key to go to main menu.");
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
					printf("illegal input");
					main_menu();//just take the user back to the main menu....
				}
				 break;
				
		default:system("cls");	
				printf("illegal input!\n\nPress E to exit\n\nPress any other key to go to main menu.");
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
				break;			
	}	
}

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
void ask_question(int value_of_question_in_coins,char question[100] , char a[50] , char b[50] , char c[50] , char d[50] , char correct_ans_small, char correct_ans_capital)
{
	printf("\nFor %d coins\n\nQuestion: %s?\n\nA)%s\n\nB)%s\n\nC)%s\n\nD)%s\n\nType your response and press enter-", value_of_question_in_coins, question, a, b, c, d);	
	fflush(stdin);
	scanf("%c",&ans);
	
	if(ans == correct_ans_capital || ans == correct_ans_small)
	{
		coins= coins+ value_of_question_in_coins;
		correct();
	}
	else
	{
		incorrect();
	}
}
	
void play()
{	
	ask_question(10,"What is the capital of India?", "Islamabad", "Delhi" , "Mumbai", "Jaipur", 'b', 'B');
	ask_question(20,"What is the capital of Nepal?", "Padampuri", "Newai", "Kathmandu", "Kumaribadi", 'c', 'C');
	ask_question(40,"Who was the first Indian to go to space?", "Rakesh Verma", "Rakesh Sharma", "Rakesh Shrivastav", "Rakesh J. Sharma", 'b', 'B');
	ask_question(100,"What hich of the following is not a fruit?", "Tomatoe", "Onion", "Apple", "Grape", 'b', 'B');
	ask_question(250,"What was the surname of the famous physist Stephan?", "Harvins", "Hawkings", "Hawkins", "Hawking", 'd', 'D');
	ask_question(600,"What is India's highest civillian honour?", "Paramveer chakra", "Bharat Ratna", "Mahaveer Ratna", "Tejaswi Chakra", 'b', 'B');
	ask_question(1000,"Who is also called the \"Missile man\" of India?", "Abdul kalam Azad", "A.P.J. Abdul Kalam Azad", "A.P.J Abdul Kalam", "Abdul Kalam", 'c', 'C');
	ask_question(2500,"What is the real colour of sunlight?", "White", "Blue", "Yellow", "Colourless", 'a', 'A');
	ask_question(5000,"What was Mahatma Gandhi\'s middle name?", "Karamvir", "Karamdas", "Karamchandra", "Karamkhot", 'c', 'C');
	ask_question(7500,"Why does most part of earth look blue from the space?", "Because clouds and sky are blue", "Because of god\'s will", "No one knows", "Because a large part of earth is covered in water", 'd', 'D');
	ask_question(10000,"what\'s the answer bruh??", "habibi", "habibi", "habibi", "habibi", 'x', 'x');
	//ask_question(15000,"", "", "", "", "", '', '');
	//ask_question(20000,"", "", "", "", "", '', '');
	//ask_question(30000,"", "", "", "", "", '', '');
	//ask_question(40000,"", "", "", "", "", '', '');
	//ask_question(60000,"", "", "", "", "", '', '');
	//ask_question(90000,"", "", "", "", "", '', '');
}


