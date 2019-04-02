#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <time.h>


//the different strengths of the user input
int TE;
int TV;
int TR;
int TF;

int TM;
int TS;
int TJ;
int TA;
//user input, below
long TT;
//answer, pre random, below
double FE;
double FT;
double FR;
double FF;
double FY;
double FS;
double FJ;
double FA;
//AN �r en checker f�r true input, TT
long AN;
//string input = "";

int main() {
	
	std::cout << "Welcome to number guessing machine!\n";
	//getline(cin, input);
	
	std::cout << "Pick your challenge!\n";
	std::cout << "1. EASY\n";
	std::cout << "2. HARD\n";
	int Mode;
	int GameMode;
	std::cin >> Mode;
	if (Mode == 2){
		std::cout << "Welcome to HARD MODE!\n";
	}
	else {
		std::cout << "Easy Mode Activated.\n";
	}
	
	//Only 8 numbers will work for now, and even so, the randomizer will not care for already used
	//numbers or respect the interval for the difficulties choosen. Reminder.
	
	std::cout << "Press '1' for One versus One match!\n";
	std::cout << "Press '2' for Co-Op play!\n";
	std::cin >> GameMode;
	if (GameMode == 1){
		std::cout << "Guesser, look away!\n";
		std::cout << "Now write your eight numbers for guessing!\n";
		//To be implemented as a single 8-number, instead of CIN-ing in each
		//seperately, but for now there is no time!
		std::cin >> FE;
		std::cin >> FT;
		std::cin >> FR;
		std::cin >> FF;
		std::cin >> FY;
		std::cin >> FS;
		std::cin >> FJ;
		std::cin >> FA;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	else if (GameMode == 2){
	
	srand(time(NULL));
	
	//std::cout << "A";
	FE = rand() % 8 + 1;
	//Nedan dekl 2
	//std::cout << "B";
	FT = FE;
	//std::cout << "C";
	while (FT == FE){
		FT = rand() % 8 + 1;
	}
	
	//Slut dekl 2 
	FR = FT;
	while (FR == FT||FR == FE){
		FR = rand() % 8 + 1;
	}
	//std::cout << "xxx";
	//Slut dekl 3
	FF = FR;
	while (FF == FR||FF == FT||FF == FE){
		FF = rand() % 8 + 1;
	}
	//Slut dekl 4
	FY = FF;
	while (FY == FF||FY == FR||FY == FT||FY == FE){
		FY = rand() % 8 + 1;
	}
	//SLut dekl 5
	 
	if (Mode == 2){
		FS = FY;
		while (FS == FY||FS == FF||FS == FR||FS == FT||FS == FE){
			FS = rand() % 8 + 1;
		}
		
		FJ = FS;
		while (FJ == FS||FJ == FY||FJ == FF||FJ == FR||FJ == FT||FJ == FE){
			FJ = rand() % 8 + 1;
		} 
		
		FA = FJ;
		while (FA == FJ||FA == FS||FA == FY||FA == FF||FA == FR||FA == FT||FA == FE){
			FA = rand() % 8 + 1;
		}
		
	}
	
}

	AN = 00000000;
	
	int Guess = 0;
	int CorrectA = 0; //for checking the amount of rights in each iteration
	int WinCount = 0; //hardwired to CorrectA, just for looping the main sequence
	while (WinCount != 8){
		std::cout << "You have guessed " << Guess << " times so far!\n";
		
		if (Mode == 2){
			std::cout << "WRITE YOUR EIGHT NUMBERS!\n";
		}
		else {
		std::cout << "WRITE YOUR FIVE NUMBERS!\n";
		}
		
		std::cin>>TT;
		std::cout << TT << "\n";
		if (AN == TT){
		std::cout << "THAT'S RIGHT!\n";
		
		}
		//REDUNDANT FROM HERE?
		else if (TT < 10000000 || TT > 99999999 && Mode == 2){
			std::cout << "Eight numbers you must write!\n";
		}
		
		else if (TT < 10000 || TT > 99999 && Mode == 1){
			std::cout << "Five numbers you must write!\n";
		}
		
		else {
			//1st
			TE = TT;
			TE = (TE/10000000);
			//std::cout << TE << "\n";
			//2nd
			TV = TT;
			TV = ((TV/1000000)-(TE*10));
			//std::cout << TV << "\n";
			//3rd
			TR = TT;
			TR = ((TR/100000)-(TE*100)-(TV*10));
			//std::cout << TR << "\n";
			//4th
			TF = TT;
			TF = ((TF/10000)-(TE*1000)-(TV*100)-(TR*10));
			//std::cout << TF << "\n";
			//5th
			TM = TT;
			TM = ((TM/1000)-(TE*10000)-(TV*1000)-(TR*100)-(TF*10));
			//std::cout << TM << "\n";
			if (Mode == 2){
			
			//6th
			TS = TT;
			TS = ((TS/100)-(TE*100000)-(TV*10000)-(TR*1000)-(TF*100)-(TM*10));
			//std::cout << TS << "\n";
			//7th
			TJ = TT;
			TJ = ((TJ/10)-(TE*1000000)-(TV*100000)-(TR*10000)-(TF*1000)-(TM*100)-(TS*10));
			//std::cout << TJ << "\n";
			//8th
			TA = TT;
			TA = ((TA/1)-(TE*10000000)-(TV*1000000)-(TR*100000)-(TF*10000)-(TM*1000)-(TS*100)-(TJ*10));
			//std::cout << TA << "\n";
			}//Maybe use arrays...
		}
		//Number not more than once
		//PROBLEM: as long as ONE is different, one variable will not equal, so it returns TRUE
		//SOLVE: must make so that as long as ANY of these are true it will not run
		//NOW: as long as any one of these does not equal, it returns true in the first check, then in the RETURN
		//_SOLVED
		if (TE != TV && TE != TR && TE != TF && TE != TM && TE != TS && TE != TJ && TE != TA && TV != TR && TV != TF && TV != TM && TV != TS && TV != TJ && TV != TA && TR != TF && TR != TM && TR != TS && TR != TJ && TR != TA && TF != TM && TF != TS && TF != TJ && TF != TA && TM != TS && TM != TJ && TM != TA && TS != TJ && TS != TA && TJ != TA ){
		 
			
			if (TE == FE){
				CorrectA += 1;
			}
			if (TV == FT){
				CorrectA += 1;
			}
			if (TR == FR){
				CorrectA += 1;
			}
			if (TF == FF){
				CorrectA += 1;
			}
			if (TM == FY){
				CorrectA += 1;
			}
			if (Mode == 2){
			
				if (TS == FS){
					CorrectA += 1;
				}
				if (TJ == FJ){
					CorrectA += 1;
				}
				if (TA == FA){
					CorrectA += 1;
				}
			}
			std::cout<< "\nYou have "<< CorrectA <<" correct numbers!\n";
			if (Mode == 2){
				if (CorrectA == 8){
					std::cout << "You have won the game, HARD MODE baby!\n";
				}
			}
			else {
				if (CorrectA == 5){
					std::cout << "You have won the game on easy!\n";
				}
			} 
			
			if (Mode == 2){
				WinCount = CorrectA;
			}
			else {
				WinCount = CorrectA + 3;
			}
			
			CorrectA = 0;
			Guess += 1;
			
			
		}
		else {
			std::cout << "A number must only be used once!\n";
		}
	}
	
	
	/*How work? take eight numbers code that WAS randomized
	check for Amount of right numbers, keep leftmost 1 and shuffle left
	if 1 correct, keep first and repeat*/
}



