// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

# include "Slash/DebugMacros.h"
// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	runningTime += DeltaTime;
	//float deltaZ = amplitude*FMath::Sin(runnungTime * timeConstant);
	//AddActorWorldOffset(FVector(0.f, 0.f, deltaZ));

	DRAW_SPHERE_single_frame(GetActorLocation());
	DRAW_VECTOR_single_frame(GetActorLocation(), GetActorLocation() + GetActorForwardVector()*100.f);
}


float AItem::TransformSin()
{
	return  amplitude*FMath::Sin(runningTime * timeConstant);
}


float AItem::TransformCos()
{
	return  amplitude*FMath::Cos(runningTime * timeConstant);
}