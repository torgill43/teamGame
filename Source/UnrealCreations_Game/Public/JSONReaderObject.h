// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "JSONReaderObject.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCREATIONS_GAME_API UJSONReaderObject : public UObject
{
	GENERATED_BODY()
		int getInt() { return 5; };
};
