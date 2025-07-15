class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool isConsonant(char c) {
        c = tolower(c);
        return isalpha(c) && !isVowel(c);
    }

    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool vowelPresent = false;
        bool consonantPresent = false;

        for (char c : word) {
            if (!isalnum(c)) return false;

            if (isVowel(c)) vowelPresent = true;
            else if (isConsonant(c)) consonantPresent = true;
        }

        return vowelPresent && consonantPresent;
    }
};
