// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"

class UStaticMeshComponent;

UCLASS()
class PREMIERPROJET_API ACube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACube();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Cours")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Cours")
	float RotationSpeed = 90.f;
	
	UPROPERTY(VisibleAnywhere, Category = "Cours")
	bool bFlotting = true;
	
	UPROPERTY(VisibleAnywhere, Category = "Cours")
	float FlottingMaxHeight = 50.f;
	
	UPROPERTY(VisibleAnywhere, Category = "Cours")
	float FlottingSpeed = 2.f;
	
private:
	
	FVector StartPosition;
	float Time = 0.f;

};
