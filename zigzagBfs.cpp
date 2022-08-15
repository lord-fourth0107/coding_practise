using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> q;
    if(root == NULL)
    {
        return result;
    }
    q.push(root);
    bool l2r = true;
    while(!q.empty()){
        int levelSize = q.size();
        vector<int>level(levelSize);
        for(int i=0; i < levelSize; i++)
        {
            TreeNode * temp = q.front();
            q.pop();
            if(l2r){
                level[i]=temp->val;
            }
            else{
                level[levelSize-1-i]=temp->val;
            }
            if(temp->left!= nullptr)
                {
                    q.push(temp->left);
                }
            if(temp->right != nullptr)
                {
                    q.push(temp->right);
                }   
        }
        result.push_back(level);
        l2r = !l2r;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}
