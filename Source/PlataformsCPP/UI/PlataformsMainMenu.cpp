// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformsMainMenu.h"
#include "Components/Button.h"
/*
bool UPlataformsMainMenu::Initialize() {

	bool Sucess = super::Initialize;
	if (!Sucess) return false;

	if (!ensure(Host != nullptr)) return false;

	Host->Onclicked.AddDynamic(this, &UPlataformsMainMenu::HostServer);
	return true;
}

void UPlaformsMainMenu::HostServer() {
	UE_LOG(LogTemp, Warning, TEXT("Indo para o Servidor"));

	UWorld* World = GetWorld();

	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Maps/Level1?Listen");

}
*/