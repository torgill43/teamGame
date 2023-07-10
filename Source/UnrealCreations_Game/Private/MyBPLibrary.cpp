#include "MyBPLibrary.h"

bool UMyBPLibrary::amIHere() {
#if WITH_EDITOR
   return true;
#else
   return false;
#endif
}

void UMyBPLibrary::readFile()
{
   ifstream file(filename);
   Json::Reader reader;
   reader.parse(file, data);
   file.close();
}

void UMyBPLibrary::extractScores()
{
   Json::Value highScores = data["highScores"];
   for (const auto& entry : highScores) {
      Score s;
      s.name = entry.getMemberNames()[0];
      s.score = entry[s.name].asInt();
      scores.push_back(s);
   }
}

void UMyBPLibrary::updateScores(string name, int score)
{
   Score newScore;
   newScore.name = name;
   newScore.score = score;

   // Iterate through scores vector and find where score needs to be inserted
   int insertIndex = 99;

   for (int i = scores.size() - 1; i >= 0; i--) {
      if (score > scores[i].score)
         insertIndex = i;
   }

   if (insertIndex < 9)
   {
      // Insert high score and associated name
      scores.insert(scores.begin() + insertIndex, newScore);
      scores.pop_back();
   }
}

void UMyBPLibrary::printScores()
{
   cout << "High Scores:" << endl;
   for (int i = 0; i < scores.size(); i++) {
      cout << "\t" << i + 1 << ": " << scores[i].name << " - " << scores[i].score << endl;
   }
}

void UMyBPLibrary::saveScores()
{
   // Create a JSON array and populate it with struct data
   Json::Value root;
   Json::Value highScoresJson;
   int rank = 0;
   for (const auto& score : scores) {
      Json::Value playerJson;
      playerJson[score.name] = score.score;
      highScoresJson[to_string(rank)] = playerJson;
      if (rank == 9)
         break;
      rank++;
   }
   root["highScores"] = highScoresJson;

   // Convert the JSON array to a string
   Json::StreamWriterBuilder writerBuilder;
   std::string jsonString = Json::writeString(writerBuilder, root);

   // Write the JSON string to a file
   ofstream jsonFile(filename);
   if (!jsonFile.is_open()) {
      cout << "Failed to open JSON file for writing" << endl;
      return;
   }
   jsonFile << jsonString;
   jsonFile.close();

   cout << "JSON data written to" << filename << endl;
}

string UMyBPLibrary::getName(int rank)
{
   if (rank >= 0 && rank < scores.size())
      return scores[rank].name;
   else
      return "Unknown";
}

int UMyBPLibrary::getScore(int rank)
{
   if (rank >= 0 && rank < scores.size())
      return scores[rank].score;
   else
      return 0;
}