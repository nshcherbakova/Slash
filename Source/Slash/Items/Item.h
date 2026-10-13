// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintPure)
	float TransformSin();

	UFUNCTION(BlueprintPure)
	float TransformCos();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Sine parameters")
	float amplitude = 0.25f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Sine parameters")
	float timeConstant = 5.f;
//private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Sine parameters")
	float runningTime = 0.f;

	private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* itemMesh;
};	
