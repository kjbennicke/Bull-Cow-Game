// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); //Game setup
    // PrintLine(FString::Printf(TEXT("The hidden word is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len())); //Debug line

}
void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    //Game loop win or lose.
    if(bGameOver || Lives < 1){
        ClearScreen();
        SetupGame();
    }
    else{
        ProcessGuess(Input);
    }
}

//Game Setup and Logic functions
void UBullCowCartridge::SetupGame(){
    HiddenWord = TEXT("diner"); //Set the HiddenWord
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Hi, welcome to the Bull Cows!"));
    PrintLine(TEXT("The word you are looking for is a %i letter\nword.\nYou have %i Lives"), HiddenWord.Len(), Lives); //Magic number, Hardcoded.
    PrintLine(TEXT("Enter your guess and press \'Enter\'"));   //Prompt player for guess   
    
}
void UBullCowCartridge::EndGame(){
    bGameOver = true;
}
void UBullCowCartridge::ProcessGuess(FString Input){
    ClearScreen();
    if(Input == HiddenWord){
        PrintLine(TEXT("You Guessed it!"));
        EndGame();
    }
    else{
        if(Input.Len() != HiddenWord.Len()){
            PrintLine(TEXT("That is not the right amount of characters..."));
            EndGame();
            return;
        }
        PrintLine(TEXT("...That is not correct."));
        PrintLine(TEXT("You have %i Lives left."), --Lives);
    }
    //Check if isogram
    //Prompt to guess again
    //check is number of characters is correct 
    //prompt to guess again

    //Remove life

    //Check if lives > 0
    //if lives greater than 0, go back to  loop and try again.
    //else if lives are 0 or less, Game Over prompt to play again
    //If play again, then reset lives and restart loop.
    //IF play again no, quit game
}