#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {
  // TODO - you fill in here.

  int lo = 0;
  int hi = A.size();

  while(lo < hi){

    int mid = lo+(hi-lo)/2;
    if(A[mid] >= k){
      hi = mid;
    }
    else{
      lo = mid+1;
    }
    if(A[lo] == k)
      return lo;
  }
  
  return -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
