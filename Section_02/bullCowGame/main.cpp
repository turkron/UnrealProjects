/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic, see the FBullCowGame Class.
*/

#include <iostream>; //preprocessor directive;
#include <string>;
#include "FBullCowGame.h";

using FText = FString;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
void PrintCurrentTry();
FText GetGuessAndRepeat();
FText GetGuess();
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
	int32 GUESS_LIMIT = BCGame.GetMaxTries();

	for (int32 NumberOfGuesses = 0; NumberOfGuesses < GUESS_LIMIT; NumberOfGuesses++)
	{
		PrintCurrentTry();
		GetGuessAndRepeat();
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y'|| Response[0] == 'Y');
}


void PrintIntro() {
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

FText GetGuess() {
	FText Guess = "";
	//get a guess from the player
	std::cout << "What is your guess? ";
	std::getline(std::cin, Guess);
	return Guess;
}

FText RepeatGuess(FText Guess) {
	//repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl;
	return Guess;
}

void PrintCurrentTry()
{	
	std::cout << "Try " << BCGame.GetCurrentTry() << ". ";
	return;
}

FText GetGuessAndRepeat() {
	return RepeatGuess(GetGuess());
}