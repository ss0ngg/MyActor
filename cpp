// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentPosition = FVector(0, 0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	Move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move() {

	for (int i = 0; i < 10; i++) {
		int x = Step();
		int y = Step();

		CurrentPosition.X += x;
		CurrentPosition.Y += y;

		UE_LOG(LogTemp, Warning, TEXT("Step %d: (%d, %d)"), i + 1, (int)CurrentPosition.X, (int)CurrentPosition.Y);
	}
}

int AMyActor::Step() {
	return FMath::RandRange(0, 1);
}
