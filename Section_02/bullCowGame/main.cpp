#include <iostream>; //preprocessor directive;
#include <string>;
#include "FBullCowGame.h";

/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic, see the FBullCowGame Class.
*/

using FText = FString;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
void PrintCurrentTry();
void PrintGameSummary(bool isGameWon);
FText GetValidGuess();
FText RepeatGuess(FText Guess);
FBullCowGame BCGame;

//entry point to code 
int main() {
	bool bPlayAgain = true;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}


void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for guesses while the game is NOT won
	//and there are still tries remaining.
	//for (int32 NumberOfGuesses = 0; NumberOfGuesses < MaxTries; NumberOfGuesses++)
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		PrintCurrentTry();
		FString Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << ".";
		std::cout << "Cows = " << BullCowCount.Cows << "." << std::endl;

		RepeatGuess(Guess);
		std::cout << std::endl;
	}
	PrintGameSummary(BCGame.IsGameWon());
}

bool AskToPlayAgain()
{
	std::cout << "Want to play again with the same hidden word? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}


void PrintIntro() {
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "                                       /;    ;\ " << std::endl;
	std::cout << "                                   __  \\____//" << std::endl;
	std::cout << "                                  /{_\_/   `'\____" << std::endl;
	std::cout << "                                  \___   (o)  (o)  }" << std::endl;
	std::cout << "       _____________________________/          :--'" << std::endl;
	std::cout << "   ,-,'`@@@@@@@@       @@@@@@         \_    `__\ " << std::endl;
	std::cout << "  ;:(  @@@@@@@@@        @@@             \___(o'o)" << std::endl;
	std::cout << "  :: )  @@@@          @@@@@@        ,'@@(  `===='" << std::endl;
	std::cout << "  :: : @@@@@:          @@@@         `@@@:" << std::endl;
	std::cout << "  :: \  @@@@@:       @@@@@@@)    (  '@@@'" << std::endl;
	std::cout << "  ;; /\      /`,    @@@@@@@@@\   :@@@@@)" << std::endl;
	std::cout << "  ::/  )    {_----------------:  :~`,~~;" << std::endl;
	std::cout << " ;;'`; :   )                  :  / `; ;" << std::endl;
	std::cout << ";;;; : :   ;                  :  ;  ; :" << std::endl;
	std::cout << "`'`' / :  :                   :  :  : :" << std::endl;
	std::cout << "     )_ \__;                   :_ ;  \_\ " << std::endl;



	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

void PrintGameSummary(bool GameIsWon) {

	if (GameIsWon) {
		std::cout << "CONGRATULATIONS, YOU HAVE WON!";
	}
	else {
		std::cout << "Better luck next time ";
	}
	std::cout << std::endl;
}

//loop continually until the user gives a valid guess. 
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		//get a guess from the player
		std::cout << "What is your guess? ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (word with only unique letters) \n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your guess only using lowercase letters \n\n";
			break;
		default:
			//assume the word is valid;
			break;
		}
	} while (Status != EGuessStatus::OK); //keep looping until we get no errors;
	return Guess;
}

FText RepeatGuess(FText Guess) {
	//repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl;
	return Guess;
}

void PrintCurrentTry()
{
	std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". ";
	return;
}