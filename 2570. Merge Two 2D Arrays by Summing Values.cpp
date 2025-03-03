class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            unordered_map<int, int> count;
            
            for (int i = 0; i < nums1.size(); i++) {
                count[nums1[i][0]] = nums1[i][1];
            }
            for (int i = 0; i < nums2.size(); i++) {
                count[nums2[i][0]] += nums2[i][1]; 
            }
    
            vector<vector<int>> v;
            for (auto& i : count) {
                v.push_back({i.first, i.second});
            }
            
            sort(v.begin(), v.end());  
            
            return v;
        }
    };
    