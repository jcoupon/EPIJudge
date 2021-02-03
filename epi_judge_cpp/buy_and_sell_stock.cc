#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {

  if(prices.size() == 0)
    return 0.0;

  double minPrice = prices[0];
  double maxDiff = 0.0;

  for(int i=1;i<prices.size(); ++i){
    maxDiff = std::max(prices[i]-minPrice, maxDiff);
    minPrice = std::min(minPrice, prices[i]);
  }

  return maxDiff;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
