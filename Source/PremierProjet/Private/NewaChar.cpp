// Fill out your copyright notice in the Description page of Project Settings.


#include "NewChar.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ANewChar::ANewChar()
{

}

// Called when the game starts or when spawned
void ANewChar::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->JumpZVelocity = JumpForce;
	
	JumpMaxCount = MaxJumps;
	
	AddPoint(0);
	
	Lives = MaxLives;
	UpdateLivesDisplay();
	
}


// Called to bind functionality to input
void ANewChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	if (InputComp && SprintAction)
	{
		InputComp->BindAction(SprintAction, ETriggerEvent::Started, this, &ANewChar::StartSprint);
		
		InputComp->BindAction(SprintAction, ETriggerEvent::Completed, this, &ANewChar::StopSprint);
	}
}

void ANewChar::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ANewChar::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ANewChar::AddPoint(int32 Points)
{
	Score += Points;
	
	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("Score : %d / %d"), Score, ScoreToWin);
		GEngine->AddOnScreenDebugMessage(1, 100.f, FColor::Yellow, Message);
		
		if (Score >= ScoreToWin)
		{
			GEngine->AddOnScreenDebugMessage(2, 100.f, FColor::Green, TEXT("Gagneeeeeee !!!!"), 
				true, FVector2D(3.f, 3.f));
		}
	}
}


void ANewChar::LoseLife()
{
	if (bIsDead) {
		return;
	}
	Lives --; 
	
	if (Lives <= 0)
	{
		Die();
	}
}

void ANewChar::UpdateLivesDisplay()
{
	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("Vies : %d / %d"), Lives, MaxLives);
		GEngine->AddOnScreenDebugMessage(3, 100.f, FColor::Red, Message);
	}
}

void ANewChar::Die()
{
	if (bIsDead)
	{
		return;
	}
	
	bIsDead = true;
	
	Lives = 0;
	UpdateLivesDisplay();
	
	GetCharacterMovement()->DisableMovement();
	DisableInput(Cast<APlayerController>(GetController()));
	
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
	GetMesh()->SetSimulatePhysics(true);
	
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(4, RestartDelay, FColor::Red, TEXT("Mort Mort Mort"));
	}
	
	GetWorldTimerManager().SetTimer(RestartTimer, this, &ANewChar::RestartLevel, RestartDelay, false);
}

void ANewChar::RestartLevel()
{
	FString LevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}