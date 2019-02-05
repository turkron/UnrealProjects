#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame(){Reset();}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	constexpr int32 START_TRIES = 1;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = START_TRIES;
	return;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
