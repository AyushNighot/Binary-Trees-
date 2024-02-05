Given the root of a binary tree, return the preorder traversal of its nodes' values.


Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Code: (Recursive)
------------------
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
    void preOrder(TreeNode* & root, vector<int> &ans) {
        if(root == NULL) {
            return ;
        }

        ans.push_back(root -> data);
        preOrder(root -> left, ans);
        preOrder(root -> right, ans);
    }
	vector<int> preorderTraversal(TreeNode* & root) {
		vector<int> ans;
        preOrder(root, ans);
        return ans;
	}
};


Code: (Iterative):
-------------------
vector < int > preOrder;
  if (curr == NULL)
    return preOrder;

  stack < node * > s;
  s.push(curr);

  while (!s.empty()) {
    node * topNode = s.top();
    preOrder.push_back(topNode -> data);
    s.pop();
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;

}





	
