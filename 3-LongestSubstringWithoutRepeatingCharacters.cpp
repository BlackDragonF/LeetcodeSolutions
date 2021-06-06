class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, size_t> charToIndexMap;
        
        int maxLength = 0;
        pair<size_t, size_t> range(0, 0); // range<position, length>
        
        for (size_t index = 0 ; index < s.length(); ++index) {
            char c = s[index];
            auto it = charToIndexMap.find(c);
            if (it == charToIndexMap.end()) {
                range.second += 1;
            } else {
                size_t existedIndex = it->second;
                if (existedIndex >= range.first) {
                    size_t rangeEnd = range.first + range.second; // omit - 1 + 1
                    range.first = it->second + 1;
                    range.second = rangeEnd - range.first + 1;
                } else {
                    range.second += 1;
                }
            }
            charToIndexMap[c] = index;

            if (range.second > maxLength) {
                maxLength = static_cast<int>(range.second);
            }
        }

        return maxLength;
    }
};