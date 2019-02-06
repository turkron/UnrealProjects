#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

bool FBullCowGame::IsIsogram(FString WordToCheck) const
{
	//treat 0 + 1 letter words as isograms
	if (WordToCheck.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen; //setup map
	for (auto Letter : WordToCheck) //range based for loop
	{
		Letter = tolower(Letter); // handle mixed case. 
		if (!LetterSeen[Letter]) {
			LetterSeen[Letter] = true;
		} else {
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString WordToCheck) const
{
	for (auto Letter : WordToCheck) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	constexpr int32 START_TRIES = 1;
	const FString HIDDEN_WORD = "crypt";
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = START_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {//if the guess isnt an isogram  TODO write function
		return EGuessStatus::Not_Isogram;
	}
	else  if (!IsLowercase(Guess)) { //if the guess isnt lowercase TODO write function
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {//if the guess length is wrong
		return EGuessStatus::Wrong_Length;
	}
	else {
		//else return ok
		return EGuessStatus::OK;
	}
}

//receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming the same length as guess.

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) { //loop through all letters in the guess
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++) {
			if (MyHiddenWord[MHWChar] == Guess[GuessChar]) {
				if (MHWChar == GuessChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	bGameIsWon = BullCowCount.Bulls == WordLength;
	return BullCowCount;
}