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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
 
    vector<double> result;
       if(root == NULL)
        {
            return result;
        }
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty())
    {
        int levelSize = q.size();
        double levelSum = 0;
        int levelCount =0;
        for(int i =0;i<levelSize;i++)
        {
            TreeNode * temp = q.front();
            q.pop();
            levelSum += temp->val;
            levelCount++;
            if(temp->left!= nullptr)
            {
                q.push(temp->left);
            }
            if(temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
        result.push_back(levelSum/levelSize);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
