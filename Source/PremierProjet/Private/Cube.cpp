// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube.h"

#include <ThirdParty/ShaderConductor/ShaderConductor/External/DirectXShaderCompiler/include/dxc/DXIL/DxilConstants.h>

// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Cree Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));

	//Mesh -> Racine
	RootComponent = Mesh;
	
	//Movable
	Mesh -> SetMobility (EComponentMobility::Movable);
	 
	//Chercher Cube dans fichiers
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ModelCube(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));

	//Si trouve -> Applique
	if (ModelCube.Succeeded())
	{
		Mesh -> SetStaticMesh(ModelCube.Object);
	}
}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	
	//Save Start Pos 
	StartPosition = GetActorLocation();
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//Angle to Rotate
	float AddRotation = RotationSpeed * DeltaTime;
	
	//Rotate
	AddActorLocalRotation(FRotator(0.f, AddRotation, 0.f));
	
	if (bFlotting)
	{
		Time += DeltaTime;
		
		//Sin to go up and down
		float Decal = FMath::Sin(Time*FlottingSpeed)*FlottingMaxHeight;
		
		FVector NewPos = StartPosition;//From start Pos
		NewPos.Z = StartPosition.Z + Decal;//Change Height based on Sin Formula
		SetActorLocation(NewPos);//Move 
	}
}

