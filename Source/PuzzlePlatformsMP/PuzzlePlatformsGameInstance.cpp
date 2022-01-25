// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));

}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("init"));
}

void UPuzzlePlatformsGameInstance::Host()
{
	if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, FString::Printf(TEXT("Hosting"))); } // Can also use UEngine* GetEngine(); then do a null check

}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, FString::Printf(TEXT("Joining %s"), *Address)); } // Can also use UEngine* GetEngine(); then do a null check
}
