class Solution {
    public:
        vector<int> res;
        
        bool backtrack(int n, int idx, vector<bool>& used) {
            if (idx == res.size()) return true; // Successfully placed all numbers
    
            if (res[idx] != 0) return backtrack(n, idx + 1, used); // Skip filled positions
    
            for (int num = n; num >= 1; --num) { // Try largest numbers first
                if (used[num]) continue; // Already placed
    
                if (num == 1) {
                    res[idx] = 1;
                    used[1] = true;
                    if (backtrack(n, idx + 1, used)) return true;
                    res[idx] = 0;
                    used[1] = false;
                } else if (idx + num < res.size() && res[idx + num] == 0) {
                    res[idx] = res[idx + num] = num;
                    used[num] = true;
                    if (backtrack(n, idx + 1, used)) return true;
                    res[idx] = res[idx + num] = 0;
                    used[num] = false;
                }
            }
            return false; // No valid placement found, backtrack
        }
        
        vector<int> constructDistancedSequence(int n) {
            int size = 2 * n - 1;
            res.resize(size, 0);
            vector<bool> used(n + 1, false);
            backtrack(n, 0, used);
            return res;
        }
    };
    