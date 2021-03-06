// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Looking.generated.h"


struct FBTLookingMemory {
	class AMutantAIController* MyController;

	float LookTime = 0.0f; //How long the task runs
	float TimePassed = 0.0f; //How much time has passed since beginning
};

UCLASS()
class MUTANTAI_API UBTTask_Looking : public UBTTask_BlackboardBase
{
	GENERATED_BODY()


public:
	UBTTask_Looking();

	uint16 GetInstanceMemorySize() const override;

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;	

	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
	float Duration = 0.0f; //How long the task should run

	UPROPERTY(EditAnywhere)
	float RandomDiviation = 0.0f; //Random diviation of the tasks duration
};
