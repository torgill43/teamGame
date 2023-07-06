// Fill out your copyright notice in the Description page of Project Settings.
// Code by Tim Orgill

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <json/json.h>

using namespace std;

struct Score {
   string name;
   int score;
};

/**
 * The JSON Reader class, will read and write data to  a JSON file
 */
UCLASS(Blueprintable)
class UNREALCREATIONS_GAME_API JSONReader
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
