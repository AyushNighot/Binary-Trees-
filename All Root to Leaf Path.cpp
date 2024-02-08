/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    Where N is the number of nodes in the tree.
*/

void dfs(BinaryTreeNode < int > * root, vector < string > & result, string curr) {

    // Base Case.
    if (!root) {
        return;
    }

    // Current string consists of data at root node.
    curr += to_string(root -> data) + " ";

    // If both child of root is NULL, then pushing the path in result array.
    if (!root -> left && !root -> right) {
        result.push_back(curr.substr(0, curr.size() - 1));
    }

    // If left child is not NULL, traverse on the left side.
    if (root -> left) {
        dfs(root -> left, result, curr);
    }

    // If right child is not NULL, traverse on the right side.
    if (root -> right) {
        dfs(root -> right, result, curr);
    }

    return;
}

vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {

    // It stores all the paths from root to leaf.
    vector < string > result;

    // It is used for traversal.
    dfs(root, result, "");

    return result;
}
