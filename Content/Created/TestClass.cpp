#import "string"
using namespace std;

public class TestClass {

   TestClass()
   {
      this->scores[{"Name1": 1}, { "Name2": 2 }, { "Name3": 3 }, { "Name4": 4 }, { "Name5": 5 }, { "Name6": 6 }, { "Name7": 7 }, { "Name8": 8 }, { "Name9": 9 }, { "Name10": 10 }];
      this->scoresTwo = { "one": 1, "two" : 2, "three" : 3, "four" : 4, "five" : 5 };

      this->names = [];
      this->values = [];
   }

   public string getName(int num) { return scores[num]; }
   public int getVal(int num) { return ; }

   private scores;
   private scoresTwo;
};