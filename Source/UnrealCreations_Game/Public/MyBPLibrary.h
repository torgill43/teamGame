#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <json/json.h>
#include "MyBPLibrary.generated.h"

using namespace std;
/**
 * 
 */
UCLASS()
class UNREALCREATIONS_GAME_API UMyBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
   struct Score {
      string name;
      int score;
   };

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	   static bool amIHere();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void readFile();

   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void extractScores();

   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void updateScores(string name, int score);

   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void printScores();

   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void saveScores();

   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
     static string getName(int rank);

   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static int getScore(int rank);

};
