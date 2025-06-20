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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root== NULL){
            return NULL;
        }
        TreeNode* left= invertTree(root->left);
        TreeNode* right = invertTree(root-> right);

        root -> left= right;
        root-> right = left;

        return root;
        
    }
};


/*}
    // Iterative approach
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            // Swap nodes
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            // Add left and right children to the queue
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
        return root;
    }
};*/