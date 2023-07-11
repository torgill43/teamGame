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
	GENERATED_UCLASS_BODY()

public:
   struct Score {
      string name;
      int score;
   };

   struct ScoreF {
      FString name;
      int score;
   };

   // TEST
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	   static bool amIHere();

   // Read existing High Score data
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void readFile();

   // ?
   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void extractScores();

   // Add a new score to the existing vector of scores
   /*UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void updateScores(string name, int score);
      */
   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void updateScoresF(FString name, int score);

   // Save the vector of scores to the .json
   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static void saveScores();

   // Get the name for a specific rank
   /*UFUNCTION(BlueprintCallable, Category = "Custom Functions")
    static string getName(int rank);
    */

   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static FString getNameF(int rank);

   // Get the score for a specific rank
   UFUNCTION(BlueprintCallable, Category = "Custom Functions")
      static int getScore(int rank);

private:
   static Json::Value data;
   static vector<Score> scores;
   static vector<ScoreF> scoreFs;
   static string filename; // Some issues with initializing variables at declaration, done in readFile

   // Printing scores to the terminal
   static void printScores();
};
