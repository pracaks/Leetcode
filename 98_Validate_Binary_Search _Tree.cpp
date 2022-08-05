/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// my initial code has INT_MAX and INT_MIN but since data range is also -231 <= Node.val <= 231 - 1
// there are cases where INT_MAX and INT_MIN are given as node value for Root node and also for leaf nodes...
// that was creating problem as in our code we are matching with < INT_MAX  and > INT_MIN which fails 
// I then changed it to long long int  all TC passed
// putting MAX VALUE can brake ... what if node data is also long long int .. then How will we manage ?
// best way is to either do INorder Traversal with Prev. node or .. inspite of passing Const values pass node values itself .
 bool checkBST(TreeNode * root , long long int minRange , long long int maxRange)
 {
     if(root == NULL)
         return true;
     if (minRange < root->val && root->val < maxRange){         
         bool b_left =  checkBST(root->left, minRange , root->val);
         bool b_right = checkBST(root->right, root->val , maxRange);
         return b_left && b_right;
     }
     else 
         return false;
 }
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       
        return checkBST(root , LLONG_MIN , LLONG_MAX);        
    }
};
