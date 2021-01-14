#include <vector>
#include <queue>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // TODO - you fill in here.

  //priority_queue<vector<int>, vector<vector<int>>> minHeap;
  std::priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> minHeap;

  for(int i=0; i<sorted_arrays.size();++i){
    if(sorted_arrays[i].size() > 0)
      minHeap.push({sorted_arrays[i][0], 0, i});
  }

  vector<int> result;
  while(!minHeap.empty()){
    
    int minVal = minHeap.top()[0];
    int minIdx = minHeap.top()[1];
    int minArrayIdx = minHeap.top()[2];

    minHeap.pop();

    result.push_back(minVal);
    if( minIdx +1 < sorted_arrays[minArrayIdx].size()){
      minHeap.push({sorted_arrays[minArrayIdx][minIdx+1], minIdx+1, minArrayIdx});
    }

  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
