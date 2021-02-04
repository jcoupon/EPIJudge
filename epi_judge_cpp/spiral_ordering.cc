#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

void getShellValues(
  const vector<vector<int>>& square_matrix, 
  vector<int> &result, int start, int end){

    if(start == end){
      result.push_back(square_matrix[start][start]);
      return;
    }

    // top row
    for(int col=start; col<=end-1; ++col)
      result.push_back(square_matrix[start][col]);

    // right col
    for(int row=start; row<=end-1; ++row)
      result.push_back(square_matrix[row][end]);

    // bottom row
    for(int col=end; col>=start+1; --col)
      result.push_back(square_matrix[end][col]);

    // left col
    for(int row=end; row>=start+1; --row)
      result.push_back(square_matrix[row][start]);
    
    return;
}


vector<int> MatrixInSpiralOrder(const vector<vector<int>>& square_matrix) {
    int n = square_matrix.size();

    vector<int> result;
  for(int shell = 0; shell < (n+1)/2; shell++){
    getShellValues(square_matrix, result, shell, n-shell-1);
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "spiral_ordering.cc", "spiral_ordering.tsv",
                         &MatrixInSpiralOrder, DefaultComparator{},
                         param_names);
}
