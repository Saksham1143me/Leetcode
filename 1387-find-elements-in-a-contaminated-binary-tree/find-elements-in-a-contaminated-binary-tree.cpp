#include <unordered_set>

class FindElements {
public:
    unordered_set<int> values;

    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }
    
    bool find(int target) {
        return values.count(target);
    }

private:
    void recoverTree(TreeNode* root, int val) {
        if (!root) return;
        
        root->val = val;
        values.insert(val); 
        recoverTree(root->left, 2 * val + 1);
        recoverTree(root->right, 2 * val + 2);
    }
};
