// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentPosition = FVector(0, 0, 0);	// 시작 위치 초기화
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	Move();	// Move 함수 호출
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move() {
	// 10번 이동 수행
	for (int i = 0; i < 10; i++) {
		
		// x와 y이동 값 계산
		int x = Step();
		int y = Step();

		// 현재 위치에서 x와 y값만큼 이동
		CurrentPosition.X += x;
		CurrentPosition.Y += y;

		
		// 로그 출력
		UE_LOG(LogTemp, Warning, TEXT("Step %d: (%d, %d)"), i + 1, (int)CurrentPosition.X, (int)CurrentPosition.Y);
	}
}

int AMyActor::Step() {
	return FMath::RandRange(0, 1);	// 0 또는 1을 랜덤으로 반환
}
