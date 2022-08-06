#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
typedef struct {
    int level;
    TreeNode * Tnode;
} QNODE;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<QNODE> que;
        QNODE qnode;
        qnode.level = 0;
        qnode.Tnode = root;
        que.push(qnode);
        int prevLevel = 0;
        vector<int> row;
        while (!que.empty())
        {
            QNODE curNode = que.front();
            que.pop();
            if(curNode.level > prevLevel)
              {
                res.push_back(row); // row completed need to add in 2D array
                row.clear();
                prevLevel = curNode.level;
              }
            row.push_back(curNode.Tnode->val); 
            if(curNode.level %2 ==0)
            { // EVEN  rows need to enter right child ahead of left child
              if(curNode.Tnode->right)
                {
                  QNODE rightNode;
                  rightNode.level = curNode.level + 1 ;
                  rightNode.Tnode = curNode.Tnode->right;
                  que.push(rightNode);
                }
              if(curNode.Tnode->left)
                {
                  QNODE leftNode;
                  leftNode.level = curNode.level + 1 ;
                  leftNode.Tnode = curNode.Tnode->left;
                  que.push(leftNode);
                }
                
            }
            else
            { // ODD  rows need to enter Left  child ahead of Right child
                if(curNode.Tnode->left)
                {
                  QNODE leftNode;
                  leftNode.level = curNode.level + 1 ;
                  leftNode.Tnode = curNode.Tnode->left;
                  que.push(leftNode);
                }
                if(curNode.Tnode->right)
                {
                  QNODE rightNode;
                  rightNode.level = curNode.level + 1 ;
                  rightNode.Tnode = curNode.Tnode->right;
                  que.push(rightNode);
                }
            }
           
        } // while ends
        
        return res;
    } // func ends
};

int main()
{
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution S;
    vector<vector<int>> res = S.zigzagLevelOrder(root);
     for (int i = 0; i < res.size(); i++) 
     {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ,";
        cout << endl;
    }
    return 0;
}
#endif
