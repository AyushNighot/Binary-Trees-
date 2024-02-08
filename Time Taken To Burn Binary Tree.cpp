class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // Initialize a pointer to the starting node (corona) 
        // and a map to store the parent of each node
        TreeNode* corona = nullptr;
        unordered_map<TreeNode*, TreeNode*> parent;

        // Use a queue for level-order traversal of the tree
        queue<TreeNode*> queue;
        queue.push(root);

        // Perform level-order traversal to find the 
        // starting node and populate the parent map
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();

            // Check if the current node has the 
            // specified value (start)
            if (node->val == start) {
                corona = node;
            }

            // Process the left child
            if (node->left != nullptr) {
                parent[node->left] = node;
                queue.push(node->left);
            }

            // Process the right child
            if (node->right != nullptr) {
                parent[node->right] = node;
                queue.push(node->right);
            }
        }

        // Initialize variables to keep track of minutes and 
        // visited nodes
        int minutes = 0;
        unordered_set<TreeNode*> visited;
        visited.insert(corona);

        // Reset the queue with the starting node and perform BFS 
        // to calculate the time
        queue.push(corona);

        while (!queue.empty()) {
            int n = queue.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                // Check and enqueue the parent node if it hasn't
                // been visited
                TreeNode* father = parent[node];
                if (father != nullptr && 
                visited.find(father) == visited.end()) {
                    visited.insert(father);
                    queue.push(father);
                }

                // Check and enqueue the left child if it hasn't 
                // been visited
                if (node->left != nullptr && 
                visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    queue.push(node->left);
                }

                // Check and enqueue the right child if it 
                // hasn't been visited
                if (node->right != nullptr && 
                visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    queue.push(node->right);
                }
            }

            // Increment minutes for each level in BFS
            minutes++;
        }

        // Subtract 1 from the total minutes since the 
        // starting node is already considered
        return minutes - 1;
    }
};
