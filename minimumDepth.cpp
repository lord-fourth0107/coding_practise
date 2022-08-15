using namespace std;

#include <iostream>
#include <queue>

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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int minimumTreeDepth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        minimumTreeDepth++;
        int levelSize=q.size();
        for(int i =0;i<levelSize;i++)
        {
            TreeNode * temp = q.front();
            q.pop();
            if(temp->left == nullptr && temp->right == nullptr)
            {
                return minimumTreeDepth;
            }
            if(temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if(temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
        
    }
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
