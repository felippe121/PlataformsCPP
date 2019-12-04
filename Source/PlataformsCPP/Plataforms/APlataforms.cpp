// Fill out your copyright notice in the Description page of Project Settings.


#include "APlataforms.h"

AAPlataforms::AAPlataforms()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AAPlataforms::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AAPlataforms::AddActiveTrigger() {
	ActiveTriggers++;
}

void AAPlataforms::RemoveActiveTrigger() {
	if (ActiveTriggers > 0) {
		ActiveTriggers--;
	}
}

void AAPlataforms::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0) {
		FVector Location = GetActorLocation();

		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (Location - GlobalStartLocation).Size();

		if (JourneyTravelled >= JourneyLength) {
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}

		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += DeltaTime * SpeedPlataform * Direction;
		SetActorLocation(Location);
	}
}