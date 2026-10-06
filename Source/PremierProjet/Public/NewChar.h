// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PremierProjetCharacter.h"
#include "NewChar.generated.h"

class UInputAction;

UCLASS()
class PREMIERPROJET_API ANewChar : public APremierProjetCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANewChar();
	
	void AddPoint(int32 Points);
	
	void LoseLife();
	
	void Die();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	void StartSprint();
	void StopSprint();
	
	void UpdateLivesDisplay();
	void RestartLevel();
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SprintAction;
	
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed = 250.f;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintSpeed = 700.f;
	
	UPROPERTY(EditAnywhere, Category = "Jump")
	float JumpForce = 700.f;
	
	UPROPERTY(EditAnywhere, Category = "Jump")
	int32 MaxJumps = 3;
	
	
	UPROPERTY(EditAnywhere, Category = "Score")
	int32 Score = 0;
	
	UPROPERTY(EditAnywhere, Category = "Score")
	int32 ScoreToWin = 5;
	
	
	UPROPERTY(EditAnywhere, Category = "Lives", meta = (ClampMin = "1"))
	int32 MaxLives = 3;
	
	UPROPERTY(EditAnywhere, Category = "Lives")
	int32 Lives = 0;
	
	UPROPERTY(EditAnywhere, Category = "Lives")
	bool bIsDead = false;
	
	UPROPERTY(EditAnywhere, Category = "Lives")
	float RestartDelay = 3.f;
	
	FTimerHandle RestartTimer;
	
	
};
