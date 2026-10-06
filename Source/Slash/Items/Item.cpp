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
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Called test text	"));
	
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.0f, FColor::Yellow, TEXT("Item on screen Message"));
	}

	DRAW_SPHERE( GetActorLocation());
	DRAW_VECTOR( GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Delta time:	%f"), DeltaTime);

	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.0f, FColor::Turquoise, FString::Printf(TEXT("Delta time:	 			%f"), DeltaTime));
	}

	
	
	
}
