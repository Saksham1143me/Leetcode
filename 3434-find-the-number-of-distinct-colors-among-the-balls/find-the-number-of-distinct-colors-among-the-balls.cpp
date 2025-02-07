class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> mp; 
        unordered_map<int, int> colorCount;
        vector<int> ans;
        
        for (auto& query : queries) {
            int index = query[0], newColor = query[1];

            if (mp.count(index)) {
                int oldColor = mp[index];
                colorCount[oldColor]--;
                if (colorCount[oldColor] == 0) {
                    colorCount.erase(oldColor);
                }
            }

            mp[index] = newColor;
            colorCount[newColor]++;

            ans.push_back(min((int)mp.size(), (int)colorCount.size()));
        }

        return ans;
    }
};
