Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough



could you make the best solution based on factors like efficiency, readability,clarity, conciseness,correctness,robustness,simplicity and maintainability for me to prepare for my coding interview in c++







Median in a row-wise sorted Matrix

// Helper function to count how many elements in a row are <= mid using binary search
int countLessEqual(const vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

// Function to find the median in a row-wise sorted matrix
int findMedian(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Define the search range: the smallest and largest elements in the matrix
    int low = matrix[0][0];
    int high = matrix[m-1][n-1];
    
    // The position of the median (middle element)
    int medianPos = (m * n) / 2;

    // Perform binary search on the value range
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Count how many elements are <= mid
        int count = 0;
        for (int i = 0; i < m; i++) {
            count += countLessEqual(matrix[i], mid);
        }

        // If we have enough elements <= mid, the median is <= mid, so we search left
        if (count <= medianPos) {
            low = mid + 1;
        } else {
            // Otherwise, the median is greater than mid, so we search right
            high = mid - 1;
        }
    }
    
    // When low == high, we've found the median
    return low;
}



Remove Outermost Parentheses

string removeOuterParentheses(const string& s) {
    string result;
    int balance = 0;
    
    for (char c : s) {
        if (c == '(') {
            // If balance > 0, it's not the outermost '('
            if (balance > 0) {
                result += c;
            }
            balance++;
        } else {
            balance--;
            // If balance > 0, it's not the outermost ')'
            if (balance > 0) {
                result += c;
            }
        }
    }
    
    return result;
}




Reverse Words in a String

std::string reverseWords(const std::string& s) {
    std::istringstream stream(s);
    std::vector<std::string> words;
    std::string word;
    
    // Split the string into words using the stream
    while (stream >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    std::reverse(words.begin(), words.end());
    
    // Join the words back into a single string with a single space separator
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";
        }
    }

    return result;
}





Largest Odd Number in String

std::string largestOddSubstring(const std::string& num) {
    // Traverse the string from the end to the beginning
    for (int i = num.length() - 1; i >= 0; --i) {
        // Check if the current character is an odd digit
        if (num[i] % 2 != 0) {
            // Return the substring from the start to this position (inclusive)
            return num.substr(0, i + 1);
        }
    }
    // If no odd digit is found, return an empty string
    return "";
}






 Longest Common Prefix

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) return "";  // Edge case: if the vector is empty, return an empty string.

    // Start by assuming the first string is the common prefix.
    std::string prefix = strs[0];
    
    // Compare the prefix with each string in the array.
    for (int i = 1; i < strs.size(); ++i) {
        // Keep reducing the prefix until it matches the start of the current string.
        while (strs[i].find(prefix) != 0) {
            // Shorten the prefix by one character at a time.
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";  // If the prefix becomes empty, return an empty string.
        }
    }

    return prefix;
}



Isomorphic Strings

bool isIsomorphic(const std::string& s, const std::string& t) {
    // If the strings have different lengths, they cannot be isomorphic
    if (s.length() != t.length()) {
        return false;
    }

    // Hash maps to store character mappings
    std::unordered_map<char, char> map_s_to_t;
    std::unordered_map<char, char> map_t_to_s;

    for (size_t i = 0; i < s.length(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        // Check if there's an existing mapping from s -> t
        if (map_s_to_t.count(char_s)) {
            if (map_s_to_t[char_s] != char_t) {
                return false;  // Mismatch found
            }
        } else {
            map_s_to_t[char_s] = char_t;
        }

        // Check if there's an existing mapping from t -> s
        if (map_t_to_s.count(char_t)) {
            if (map_t_to_s[char_t] != char_s) {
                return false;  // Mismatch found
            }
        } else {
            map_t_to_s[char_t] = char_s;
        }
    }

    return true;  // No mismatches, the strings are isomorphic
}



Rotate String

bool canBeShifted(const std::string& s, const std::string& goal) {
    // Check if the strings have the same length
    if (s.length() != goal.length()) {
        return false;
    }

    // Concatenate s with itself and check if goal is a substring
    return (s + s).find(goal) != std::string::npos;
}


Valid Anagram

bool isAnagram(string s, string t) {
    // If the lengths are different, they cannot be anagrams
    if (s.length() != t.length()) {
        return false;
    }

    // Create a hash map to count character frequencies for string s
    unordered_map<char, int> count;

    // Increment count for characters in s and decrement for characters in t
    for (char c : s) {
        count[c]++;
    }

    for (char c : t) {
        count[c]--;
        if (count[c] < 0) {
            return false; // If count goes negative, t has an extra character
        }
    }

    return true; // If all counts are zero, it's an anagram
}




Sort Characters By Frequency

string frequencySort(string s) {
    // Step 1: Count the frequency of each character
    unordered_map<char, int> freq_map;
    for (char ch : s) {
        freq_map[ch]++;
    }

    // Step 2: Create a vector of pairs and sort it by frequency in descending order
    vector<pair<char, int>> freq_vec(freq_map.begin(), freq_map.end());
    sort(freq_vec.begin(), freq_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; // Sorting by frequency in descending order
    });

    // Step 3: Build the result string based on the sorted frequencies
    string result;
    for (const auto& [ch, count] : freq_vec) {
        result.append(count, ch); // Append 'ch' 'count' times
    }

    return result;
}





Maximum Nesting Depth of the Parentheses

int maxDepth(const std::string& s) {
    int current_depth = 0;
    int max_depth = 0;

    for (char ch : s) {
        if (ch == '(') {
            current_depth++;
            max_depth = std::max(max_depth, current_depth);
        } else if (ch == ')') {
            current_depth--;
        }
    }

    return max_depth;
}


Roman to Integer

int romanToInt(const std::string& s) {
    // Create a map to store Roman numeral values
    std::unordered_map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    int n = s.length();

    // Traverse the string from left to right
    for (int i = 0; i < n; ++i) {
        // If the current value is less than the next value, subtract current value
        if (i + 1 < n && romanValues[s[i]] < romanValues[s[i + 1]]) {
            result -= romanValues[s[i]];
        } else {
            // Otherwise, just add the value
            result += romanValues[s[i]];
        }
    }

    return result;
}


String to Integer (atoi)

int myAtoi(const std::string& s) {
    int index = 0, sign = 1, result = 0;
    
    // Step 1: Skip leading whitespaces
    while (index < s.size() && s[index] == ' ') {
        ++index;
    }
    
    // Step 2: Handle sign
    if (index < s.size() && (s[index] == '+' || s[index] == '-')) {
        sign = (s[index] == '-') ? -1 : 1;
        ++index;
    }
    
    // Step 3: Convert the digits to an integer
    while (index < s.size() && std::isdigit(s[index])) {
        int digit = s[index] - '0';
        
        // Handle overflow/underflow
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        
        result = result * 10 + digit;
        ++index;
    }
    
    return result * sign;
}


Substrings with K Distinct
// Helper function to count substrings with at most k distinct characters
int countAtMostKDistinct(const string& s, int k) {
    unordered_map<char, int> freq;
    int left = 0, count = 0;

    for (int right = 0; right < s.length(); ++right) {
        freq[s[right]]++;

        // Shrink the window if we have more than k distinct characters
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        // All substrings ending at `right` and starting from any index `left` to `right` are valid
        count += (right - left + 1);
    }

    return count;
}

// Function to count substrings with exactly k distinct characters
int countSubstringsWithKDistinct(const string& s, int k) {
    if (k == 0) return 0; // No substrings can have 0 distinct characters
    return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
}





Longest Palindromic Substring

string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        string longest;
        
        // Function to expand around the center and return the longest palindrome
        auto expandAroundCenter = [&s](int left, int right) -> string {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            return s.substr(left + 1, right - left - 1);
        };
        
        for (int i = 0; i < s.size(); ++i) {
            // Odd length palindrome (centered at i)
            string palindrome1 = expandAroundCenter(i, i);
            // Even length palindrome (centered between i and i + 1)
            string palindrome2 = expandAroundCenter(i, i + 1);
            
            // Update the longest palindrome if a new one is longer
            if (palindrome1.size() > longest.size()) {
                longest = palindrome1;
            }
            if (palindrome2.size() > longest.size()) {
                longest = palindrome2;
            }
        }
        
        return longest;
    }


Sum of Beauty of All Substrings

int sumOfBeauty(string s) {
    int n = s.length();
    int totalBeauty = 0;

    // Loop through all possible starting points of substrings
    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> freq;
        int minFreq = INT_MAX;
        int maxFreq = 0;

        // Extend the substring to the right (from i to j)
        for (int j = i; j < n; ++j) {
            // Update the frequency of the current character
            freq[s[j]]++;
            
            // Update the min and max frequencies
            minFreq = min(minFreq, freq[s[j]]);
            maxFreq = max(maxFreq, freq[s[j]]);
            
            // Add the beauty of the current substring
            totalBeauty += (maxFreq - minFreq);
        }
    }

    return totalBeauty;
}



Reverse Words in a String

std::string reverseWords(const std::string& s) {
    std::istringstream stream(s);  // Create a stringstream to split the string
    std::vector<std::string> words;
    std::string word;
    
    // Extract words from the string stream (handling multiple spaces naturally)
    while (stream >> word) {
        words.push_back(word);
    }
    
    // Reverse the order of words in the vector
    std::reverse(words.begin(), words.end());
    
    // Join the words into a single string with a single space between them
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) result += " ";  // Add space between words
        result += words[i];
    }
    
    return result;
}
