#include <vector>
#include <unordered_map>

#include "test_framework/generic_test.h"
using std::vector;


int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {


  int n_scores = individual_play_scores.size();
  vector<vector<int>> DP(n_scores, vector<int>(final_score+1, 0));

  for(int i=0; i<n_scores; ++i){
    DP[i][0] = 1;
    for(int j=1; j<final_score+1;++j){
      int play_score = individual_play_scores[i];
      DP[i][j] = i>0 ? DP[i-1][j] : 0;
      DP[i][j] += j-play_score >= 0 ? DP[i][j-play_score] : 0;
    }
  }


  return DP[n_scores-1][final_score];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  return GenericTestMain(args, "number_of_score_combinations.cc",
                         "number_of_score_combinations.tsv",
                         &NumCombinationsForFinalScore, DefaultComparator{},
                         param_names);
}
