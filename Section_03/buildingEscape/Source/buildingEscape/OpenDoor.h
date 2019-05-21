// Copyright Nathan Kendall 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private: 
	UPROPERTY(EditAnywhere)
		float OpenAngle = -200.f;
	UPROPERTY(EditAnywhere)
		float CloseAngle = -90.f;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;
	UPROPERTY(VisibleAnywhere)
	AActor* ActorThatOpens; //pawn inherits from actors;
	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;
	float LastDoorOpenTime;
	AActor* Owner;
};
