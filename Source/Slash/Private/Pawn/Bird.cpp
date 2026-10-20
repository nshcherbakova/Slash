// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Pawn/Bird.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	capsule->SetCapsuleHalfHeight(20.f);
	capsule->SetCapsuleRadius(15.f);
	SetRootComponent(capsule);
	
	bird_mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	bird_mesh->SetupAttachment(GetRootComponent());

	spring_arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	spring_arm->SetupAttachment(GetRootComponent());
	spring_arm->TargetArmLength = 300.f;

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(spring_arm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ABird::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ABird::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ABird::LookUp);
}

 void ABird::MoveForward(float Value) 
 {
	if(Controller && Value != 0.f)
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);	
	}
 }

  void ABird::Turn(float Value) 
 {
	AddControllerYawInput(Value);
	UE_LOG(LogTemp, Warning, TEXT("Turn %f"), Value);
 }

  void ABird::LookUp(float Value) 
 {
	AddControllerPitchInput(Value);
	UE_LOG(LogTemp, Warning, TEXT("LookUp %f"), Value);
 }

