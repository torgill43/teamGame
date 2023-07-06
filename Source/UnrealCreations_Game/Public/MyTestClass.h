// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <random>
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyTestClass.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UNREALCREATIONS_GAME_API MyTestClass : public UObject
{
	GENERATED_BODY()
	public:
	MyTestClass();
	~MyTestClass();

	UFUNCTION(BlueprintNativeEvent, Category="Test Functions")
	int GetRandom();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Test Variables")
	int testVar = 10;
};
