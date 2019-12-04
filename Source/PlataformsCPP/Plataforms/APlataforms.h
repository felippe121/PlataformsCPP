// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "APlataforms.generated.h"

/**
 * 
 */
UCLASS()
class PLATAFORMSCPP_API AAPlataforms : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAPlataforms();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;

	UPROPERTY(EditAnyWhere)
		float SpeedPlataform = 20;

	void AddActiveTrigger();
	void RemoveActiveTrigger();

private:
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;

	UPROPERTY(EditAnywhere)
		int ActiveTriggers = 1;
};

