#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

//Function prototypes
void tic_tac_toe();
void tttboardprint(char array[3][3]);
void rock_paper_scissor();
void hangman();
void hangmanprint(int moves);

int main(){
	int choice;

	cout<<"=================================================="<<endl;
	cout<<"|            Welcome to trio Game World          |"<<endl;
	cout<<"=================================================="<<endl;

	do{
		cout<<"\n=======================Menu====================="<<endl;
		cout<<"Enter the option number: "<<endl;
		cout<<"1. Tic Tac Toe\n2. Rock Paper Scissors\n3. Hangman\n4. Exit"<<endl;
		cin>>choice;

		switch(choice){
			case 1: 	tic_tac_toe();				break;
			case 2: 	rock_paper_scissor();		break;
			case 3: 	hangman();					break;
			case 4:		cout<<"Thanks for playing.\nProgram Ending...."<<endl;		break;
			default: 	cout<<"Invalid option number."<<endl;
		}
	}while(choice != 4);

	return 0;
}

void tic_tac_toe(){
	int boxnum;
	int win = 0;
	int row, col;
	int move = 0;
	bool valid;

	cout<<"\n";
	cout<<"=================================================="<<endl;
	cout<<"|                    TIC TAC TOE                 |"<<endl;
	cout<<"=================================================="<<endl;

	cout<<"\n------------------INSTRUCTIONS-------------------"<<endl;
	cout<<"You have 'O' sign!"<<endl;
	cout<<"Bot have 'X' sign!"<<endl;
	cout<<"Player 1 has first turn and player 2 has second."<<endl;
	cout<<"Kindly enter the box number on your respective turns where you want to place your sign"<<endl;
	cout<<"box numbers are from 1-9. incase of entering any other number only last digit will be considered as valid input."<<endl;
	cout<<"Following is the table format for box number"<<endl;

    //printing the board
	char array[3][3] = {{'1','2','3'},{'4', '5', '6'},{'7', '8', '9'}};
	for(int i = 0; i<3; i++){
		cout<<"\n|";
		for(int j= 0; j<3; j++){
			cout<<array[i][j]<<"|";
		}
	}
	cout<<endl;

    //randomly generating turns for bot or player
	int turn;
	srand(time(0));
	turn = rand()%2+1;

//managing terms
	do{
	if(turn == 1){
		valid = false;
		cout<<"\nIts your turn!"<<endl;
		while(valid == false){
			cout<<"Enter place number from above table to place 'O'"<<endl;
			cin>>boxnum;
			if (boxnum<1 || boxnum>9 )		//input validation check
			{
				cout<<"Invalid box! Enter place number from above table to place 'O'"<<endl;
				continue;
			}
            //assigning rows and columns to respective box number
			switch(boxnum){
				case 1:		row = 0;	col = 0;	 break;
				case 2:		row = 0;	col = 1;	 break;
				case 3:		row = 0;	col = 2;	 break;
				case 4:		row = 1;	col = 0;	 break;
				case 5:		row = 1;	col = 1;	 break;
				case 6:		row = 1;	col = 2;	 break;
				case 7:		row = 2;	col = 0;	 break;
				case 8:		row = 2;	col = 1;	 break;
				case 9:		row = 2;	col = 2;	 break;
			}
            //assigning palyer mark if box is empty
			if(array[row][col] != 'O' && array[row][col] != 'X'){
				array[row][col] = 'O';
				valid = true;
			}
			else
				cout<<"That box is already used. kindly enter unused box"<<endl;
		}
		tttboardprint(array);
		turn++;
		move++;
	}



	else if(turn == 2){
		valid = false;
		cout<<"\nIts Bot turn"<<endl;
		while(valid == false){
			boxnum = rand()%9+1;

			if (boxnum<1 || boxnum>9 )		//input validation check
			{
				continue;
			}
			switch(boxnum){
				case 1:		row = 0;	col = 0;	 break;
				case 2:		row = 0;	col = 1;	 break;
				case 3:		row = 0;	col = 2;	 break;
				case 4:		row = 1;	col = 0;	 break;
				case 5:		row = 1;	col = 1;	 break;
				case 6:		row = 1;	col = 2;	 break;
				case 7:		row = 2;	col = 0;	 break;
				case 8:		row = 2;	col = 1;	 break;
				case 9:		row = 2;	col = 2;	 break;
			}
			if(array[row][col] != 'O' && array[row][col] != 'X'){
				array[row][col] = 'X';
				valid = true;
			}
		}
		tttboardprint(array);
		turn--;
		move++;
	}

//chceking win conditions for bot and player
	if ((array[0][0] == 'O' && array[0][1] == 'O' && array[0][2] == 'O') || (array[1][0] == 'O' && array[1][1] == 'O' && array[1][2] == 'O')
		||(array[2][0] == 'O' && array[2][1] == 'O' && array[2][2] == 'O')|| (array[0][0] == 'O' && array[1][0] == 'O' && array[2][0] == 'O')
		|| (array[0][1] == 'O' && array[1][1] == 'O' && array[2][1] == 'O') ||(array[0][2] == 'O' && array[1][2] == 'O' && array[2][2] == 'O')
		|| (array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O') || (array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O'))
	{
		win = 1;
	}
	else if ((array[0][0] == 'X' && array[0][1] == 'X' && array[0][2] == 'X') || (array[1][0] == 'X' && array[1][1] == 'X' && array[1][2] == 'X')
		||(array[2][0] == 'X' && array[2][1] == 'X' && array[2][2] == 'X')|| (array[0][0] == 'X' && array[1][0] == 'X' && array[2][0] == 'X')
		|| (array[0][1] == 'X' && array[1][1] == 'X' && array[2][1] == 'X') ||(array[0][2] == 'X' && array[1][2] == 'X' && array[2][2] == 'X')
		|| (array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X') || (array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == 'X'))
	{
		win = 2;
	}
	else if (move == 9)
		win = 3;

	}while(win == 0);

//result announcement
	if(win == 1)
	{
		cout<<"\nCongratulations! you are the winner of this match"<<endl;
	}
	else if (win == 2)
	{
		cout<<"\nBot is the winner of the match"<<endl;
	}
	else if (move==9 || win == 3)
		cout<<"\nThis match is draw"<<endl;

}

void tttboardprint(char array[3][3]){
	for(int i = 0; i<3; i++){
		cout<<"\n|";
		for(int j= 0; j<3; j++){
			cout<<array[i][j]<<"|";
		}
	}
	cout<<endl;
}
void rock_paper_scissor(){
	int option;
	int pmove, bmove;
	int pwin;
	int bwin;
	int draw;

	cout<<"\n";
	cout<<"=================================================="<<endl;
	cout<<"|                 ROCK PAPER SCISSORS            |"<<endl;
	cout<<"=================================================="<<endl;
	do{
		cout<<"Select Round type\n1. 3-Round\n2. 5-Round\n3. Back"<<endl;
		cin>>option;

		switch(option){
			case 1:
				cout<<"============== 3 Rounds Game =============="<<endl;
			 	pwin = 0;
				bwin = 0;
				draw = 0;

				for(int i = 1; i <= 3; i++){
					do{
					cout<<"\n-------------- ROUND "<<i<<" -----------------"<<endl;
					cout<<"Choose your move\n1. Rock\n2. Paper\n3. Scissors"<<endl;
					cin>>pmove; }while(pmove>3 || pmove<1);
                    //bot move is random choosing one of the 3 options
					bmove = rand()%3+1;

                    //result announcement
					cout<<"\n=============result================"<<endl;
					cout<<"You chose: ";
					if(pmove == 1)		cout<<"Rock"<<endl;
					else if(pmove == 2)		cout<<"Paper"<<endl;
					else if(pmove == 3)		cout<<"Scissors"<<endl;
					cout<<"Bot chose: ";
					if(bmove == 1)		cout<<"Rock"<<endl;
					else if(bmove == 2)		cout<<"Paper"<<endl;
					else if(bmove == 3)		cout<<"Scissors"<<endl;

                    //chcing win for each round
					if(pmove == bmove){
						draw++;
						cout<<"This round was draw"<<endl;
					}

					else if((pmove == 1 && bmove == 3) || (pmove == 2 && bmove == 1) ||(pmove == 3 && bmove == 2)){
						pwin++;
						cout<<"You won round "<<i<<endl;
					}
					else if((pmove == 3 && bmove == 1) || (pmove == 2 && bmove == 3) ||(pmove == 1 && bmove == 2)){
						bwin++;
						cout<<"Bot won round "<<i<<endl;
					}
				}
                //announcement of final result
				cout<<"\n============ Final Result ================="<<endl;
				if(pwin>bwin)
					cout<<"Congratulations You won this game!\n\n";
				else if(bwin>pwin)
					cout<<"Bot won this game!\n\n";
				else
			 		cout<<"This game is draw!\n\n";
				break;
			case 2:
				cout<<"============== 5 Rounds =============="<<endl;
			 	pwin = 0;
				bwin = 0;
				draw = 0;

				for(int i = 1; i <= 5; i++){
					do{
					cout<<"\n-------------- ROUND "<<i<<" -----------------"<<endl;
					cout<<"Choose your move\n1. Rock\n2. Paper\n3. Scissors"<<endl;
					cin>>pmove; }while(pmove>3 || pmove<1);
					srand(time(0));
					bmove = rand()%3+1;
					cout<<"\n=============result================"<<endl;
					cout<<"You chose: ";
					if(pmove == 1)		cout<<"Rock"<<endl;
					else if(pmove == 2)		cout<<"Paper"<<endl;
					else if(pmove == 3)		cout<<"Scissors"<<endl;
					cout<<"Bot chose: ";
					if(bmove == 1)		cout<<"Rock"<<endl;
					else if(bmove == 2)		cout<<"Paper"<<endl;
					else if(bmove == 3)		cout<<"Scissors"<<endl;

					if(pmove == bmove){
						draw++;
						cout<<"This round was draw"<<endl;
					}

					else if((pmove == 1 && bmove == 3) || (pmove == 2 && bmove == 1) ||(pmove == 3 && bmove == 2)){
						pwin++;
						cout<<"You won round "<<i<<endl;
					}
					else if((pmove == 3 && bmove == 1) || (pmove == 2 && bmove == 3) ||(pmove == 1 && bmove == 2)){
						bwin++;
						cout<<"Bot won round "<<i<<endl;
					}
				}
				cout<<"\n============ Final Result ================="<<endl;
				if(pwin>bwin)
					cout<<"Congratulations You won this game!\n\n";
				else if(bwin>pwin)
					cout<<"Bot won this game!\n\n";
				else
			 		cout<<"This game is draw!\n\n";
				break;
			case 3:
				return;
				break;
			default:
				cout<<"Invalid option selected"<<endl;
		}
	}while(option != 3);

}
void hangman(){
	int wrongmove = 0;  //keep track of user's wrong moves
	string words[50];   //store the list of 50 words from file after reading
	string guessword;   //stroes a random word for guess
	int dash;           //stores the lenght of the word
	bool win = false;
	char letter;        //gets letter input from user

	cout<<"\n";
	cout<<"=================================================="<<endl;
	cout<<"|                       HANGMAN                  |"<<endl;
	cout<<"=================================================="<<endl;

    //opening the file to read text
	ifstream file("wordlist.txt");
    if (file.is_open()) {
        for (int i = 0; i < 50; ++i) {
            file >> words[i];
        }
        file.close();
	}
	else{
		cout<<"Unsucessful in opening file."<<endl;
	}


    //generating random index to coose word
	srand(time(0));
	int index = rand()%50;
	guessword = words[index];
	dash = guessword.size();

	char *printword = new char[dash+1];

	cout<<"\n========== GUESS THE WORD ============="<<endl;
	for(int i = 0; i<dash; i++){
		cout<<" _ ";
		printword[i] = '_';
	}
	printword[dash] = '\0';

	while(wrongmove<6 && win == false){
		cout<<"\n\nEnter a letter you want to guess"<<endl;
		cin>>letter;

        //checks if the entered letter exists in the word or not if it exists saved in string that will be printed
		bool found = false;
		for(int i = 0; i<dash; i++){
			if(guessword[i] == letter && printword[i] == '_'){
				printword[i] = letter;
				found = true;
				for(int i = 0; i<dash; i++)
					cout<<printword[i]<<" ";
					cout<<endl;
			}
		}

		if(found == false){
			wrongmove++;
			hangmanprint(wrongmove);
		}

        //converting the character aray into string to chck if it is correctly and completely guessed
		string correctword(printword);

		if (correctword == guessword){
		   	win = true;
			cout<<"\nCongratulations you guessed the correct word"<<endl;
			return;
		}
	}

	if(win == false && wrongmove == 6){
		cout<<"Correct word was: "<<guessword<<"\nBetter luck next time"<<endl;
	}

	delete []printword;
}
void hangmanprint(int moves){
    //printing hangman according to its wrong moves
	switch(moves){
		case 0:
			cout<<endl;
			cout<<"______"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<endl;
			break;
		case 1:
			cout<<endl;
			cout<<"______"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    O"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<"|"<<endl;
			cout<<endl;
			break;
		case 2:
			cout<<endl;
			cout<<"______"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    O"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|"<<endl;
			cout<<endl;
			break;
		case 3:
			cout<<endl;
			cout<<"______"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    O"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|  / |"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|"<<endl;
			cout<<endl;
			break;
		case 4:
			cout<<endl;
			cout<<"______"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    O"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|  / | \\"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|"<<endl;
			cout<<endl;
			break;
		case 5:
			cout<<endl;
			cout<<"______"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    O"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|  / | \\"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|  /"<<endl;
			cout<<endl;
			break;
		case 6:
			cout<<endl;
			cout<<"______"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|    O"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|  / | \\"<<endl;
			cout<<"|    |"<<endl;
			cout<<"|  /   \\"<<endl;
			cout<<endl;
			break;
	}
}