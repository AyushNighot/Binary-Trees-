Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100



Code: Recursive:
----------------

/*
class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode() {
        }
        
        TreeNode(int data) {
            this->data = data;
        }
        
        TreeNode(int data, TreeNode* left, TreeNode* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};
*/

class Solution {
public:
    void inOrder(TreeNode* &root, vector<int> &ans) {
        if(root == NULL) {
            return ;
        }

        inOrder(root -> left, ans);
        ans.push_back(root -> data);
        inOrder(root -> right, ans);
    }
	vector<int> inorderTraversal(TreeNode* & root) {
		vector<int> ans;
        inOrder(root, ans);
        return ans;
	}
};


Code - Iterative:
------------------
