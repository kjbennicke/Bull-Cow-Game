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
    if(bGameOver){
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
    PrintLine(TEXT("Press enter to play again..."));
}
void UBullCowCartridge::ProcessGuess(FString Guess){
    QualifyGuess(Guess);

    //everything below removed a life.
    --Lives;
    
    if(Lives > 0){
        ClearScreen();
        PrintLine(TEXT("That is incorrect.\nYou have %i lives left."), Lives);
        return;
    }
    if(Lives <= 0){
        ClearScreen();
        PrintLine(TEXT("You are out of lives!"));    
        PrintLine(TEXT("The hidden word was '%s'."), *HiddenWord);    
        EndGame();
        return;
    }
}
 //Check if isogram
bool UBullCowCartridge::IsIsogram(FString Word)const{
    //Take in the Guess  and compare to HIddenWord
    //check to see if it is an isogram
    // if not an isogram return false
    //if an isogram return true.
    return true;
}
void UBullCowCartridge::QualifyGuess(FString Guess){
    if(Guess == HiddenWord){
        ClearScreen();
        PrintLine(TEXT("You Guessed it!"));
        EndGame();
        return;
    }
    if(Guess.Len() != HiddenWord.Len()){
        ClearScreen();
        PrintLine(TEXT("That is not the right amount of characters..."));
        PrintLine(TEXT("You have a %i lives left."), Lives);
        return;
    }
    if(!IsIsogram(Guess)){
    PrintLine(TEXT("No repeating letters!! Try again"));
    return;
    }
}