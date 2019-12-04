// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformsGameInstance.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UPlataformsGameInstance::UPlataformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Contruindo Game Instance"));
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/UI/MainMenu/MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;
	UE_LOG(LogTemp, Warning, TEXT("Encontrei a classe BP do menu %s"), *MenuBPClass.Class->GetName());
	MenuClass = MenuBPClass.Class;

}

void UPlataformsGameInstance::LoadMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Carregando menu"));
	if (!ensure(MenuClass != nullptr)) return;
	UUserWidget *Menu =  CreateWidget<UUserWidget>(this, MenuClass);
	if (!ensure(Menu != nullptr)) return;

	Menu->AddToViewport();

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;

	//Menu->SetMenuInterface(this);
}

void UPlataformsGameInstance::Host()
{
	UE_LOG(LogTemp, Warning, TEXT("Host"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Maps/Lobby?Listen");
}

void UPlataformsGameInstance::Join()
{
	UE_LOG(LogTemp, Warning, TEXT("Join to game"));
}

