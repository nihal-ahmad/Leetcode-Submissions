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
#include<bits/stdc++.h>
class Solution {
public:
     bool isSameTree(TreeNode* root, TreeNode* subRoot){
        return (!root && !subRoot) || (root && subRoot && root->val == subRoot->val && isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right));
    }
        
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isSameTree(root,subRoot) || (root && (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot)));
    }
};