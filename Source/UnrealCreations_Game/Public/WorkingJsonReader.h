// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WorkingJsonReader.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCREATIONS_GAME_API UWorkingJsonReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
   Json::Value data;
   vector<Score> scores;
   string filename = "scores.json";

public:
   JSONReader();
	~JSONReader();

   void readFile();
   void extractScores();
   void updateScores(string name, int score);
   void printScores() const;
   void saveScores();
   string getName(int rank);
   int getScore(int rank);
	
};
