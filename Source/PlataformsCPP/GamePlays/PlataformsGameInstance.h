// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlataformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PLATAFORMSCPP_API UPlataformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPlataformsGameInstance(const FObjectInitializer& ObjecInitializer);

	UFUNCTION(Exec)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join();
	
private:
	TSubclassOf<class UUserWidget> MenuClass;

};
