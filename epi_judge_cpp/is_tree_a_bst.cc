#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

bool helper(const unique_ptr<BinaryTreeNode<int>>& node, int minVal, int maxVal){
  if(node == nullptr)
    return true;

  bool inRange = (node->data >= minVal) && (node->data <= maxVal);
  bool left = helper(node->left, minVal, node->data);
  bool right = helper(node->right, node->data, maxVal);

  return inRange && left && right;
  
}

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.

  if(tree == nullptr)
    return true;

  return helper(tree, std::INT_MIN, std::INT_MAX);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
