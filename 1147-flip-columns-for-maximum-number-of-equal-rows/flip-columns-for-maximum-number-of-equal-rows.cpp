class Solution {
public:
   

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> row_pattern_count;
    for (auto& row : matrix) {
        string original = "";
        string flipped = "";
        
        for (int i = 0; i < row.size(); ++i) {
            original += to_string(row[i]);
            flipped += to_string(1 - row[i]);  
        }
        row_pattern_count[original]++;
        row_pattern_count[flipped]++;
    }

   
    int max_rows = 0;
    for (const auto& pair : row_pattern_count) {
        max_rows = max(max_rows, pair.second);
    }

    return max_rows;
}
};