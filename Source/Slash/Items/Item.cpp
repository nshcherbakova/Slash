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
	float MoveSpeed = 50.f;
    float RotationSpeed = 45.f;
	//UE_LOG(LogTemp, Warning, TEXT("Delta time:	%f"), DeltaTime);
	AddActorWorldOffset(FVector(DeltaTime*MoveSpeed, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, DeltaTime*RotationSpeed, 0.f));
	DRAW_SPHERE_single_frame(GetActorLocation());
	DRAW_VECTOR_single_frame(GetActorLocation(), GetActorLocation() + GetActorForwardVector()*100.f);
}
