class Solution {
    public:
        int countSequences(vector<int>& freq) {
            int count = 0;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    count++;  
                    freq[i]--;  
                    
                    count += countSequences(freq);
                    
                    freq[i]++;
                }
            }
            return count;
        }
    
        int numTilePossibilities(string tiles) {
            vector<int> freq(26, 0);
            for (char c : tiles) freq[c - 'A']++;  
    
            return countSequences(freq);
        }
    };
    