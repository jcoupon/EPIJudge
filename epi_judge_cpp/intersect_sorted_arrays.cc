#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  // TODO - you fill in here.

  vector<int> result;

  int i = 0;
  int j = 0;

  while(i < A.size() && j < B.size()){
    if(A[i] == B[j]){
      if(result.size() == 0 || result.back() != A[i])
        result.push_back(A[i]);
      ++i;
      ++j;
    }else if(A[i] < B[j]){
      ++i;
    }else{
      ++j;
    }
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
