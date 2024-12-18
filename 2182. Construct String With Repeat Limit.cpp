class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
         vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    string result = "";
    for (int i = 25; i >= 0; ) {
        if (freq[i] == 0) { 
            i--; 
            continue;
        }

        int useCount = min(freq[i], repeatLimit);
        result.append(useCount, 'a' + i);
        freq[i] -= useCount;

        if (freq[i] > 0) {
            int j = i - 1; 
            while (j >= 0 && freq[j] == 0) j--; 

            if (j < 0) break;

            result += ('a' + j);
            freq[j]--;
        } else {
            i--;
        }
    }

    return result;
    }
};