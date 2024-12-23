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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int swaps = 0;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelNodes;
                for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelNodes.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            swaps += countSwaps(levelNodes);
        }
        
        return swaps;
    }

private:
    int countSwaps(vector<int>lvl) {
        int swaps = 0;
        vector<int> target =lvl;
        sort(target.begin(), target.end());

        // Map to track current positions of values
        unordered_map<int, int> pos;
        for (int i = 0; i <lvl.size(); i++) {
            pos[lvl[i]] = i;
        }

        // For each position, swap until correct value is placed
        for (int i = 0; i <lvl.size(); i++) {
            if (lvl[i] != target[i]) {
                swaps++;

                // Update position of swapped values
                int curPos = pos[target[i]];
                pos[lvl[i]] = curPos;
                swap(lvl[curPos],lvl[i]);
            }
        }
        return swaps;
    }
};
