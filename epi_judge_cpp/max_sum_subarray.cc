#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int FindMaximumSubarray(const vector<int>& A) {
  // TODO - you fill in here.

    if(A.empty()) return 0;

    int maxSum = 0;
    int result = maxSum;
    for(int i=0; i<A.size(); ++i){
        maxSum = std::max(A[i], maxSum + A[i]);
        result = std::max(result, maxSum);       
    }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "max_sum_subarray.cc", "max_sum_subarray.tsv",
                         &FindMaximumSubarray, DefaultComparator{},
                         param_names);
}
