# C++ Practice Lab — Strings, Substrings & Text Analysis

## Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Task 1: Extract Domain from Email
void extractDomainFromEmail() {
    cout << "\nTask 1: Extract Domain from Email\n";
    string email;
    cout << "Input: ";
    getline(cin, email);

    int atPos = email.find('@');
    if (atPos != string::npos) {
        string username = email.substr(0, atPos);
        string domain = email.substr(atPos + 1);
        cout << "Output:\n";
        cout << "Username: " << username << endl;
        cout << "Domain: " << domain << endl;
    } else {
        cout << "Invalid email address (no '@' found)." << endl;
    }
}

// Task 2: Replace all occurrences of "Miramar" with "San Diego Miramar College"
void replaceMiramar() {
    cout << "\nTask 2: Replace a Word\n";
    cout << "Input: ";
    string text;
    getline(cin, text);

    size_t pos = 0;
    while ((pos = text.find("Miramar", pos)) != string::npos) {
        text.replace(pos, 7, "San Diego Miramar College");
        pos += 25; // move past the replaced text to avoid infinite loop
    }
    cout << "Output: " << text << endl;
}

// Task 3: Palindrome Checker (Ignore spaces and capitalization)
bool isPalindrome(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());  // remove spaces
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    return s == reversed;
}

void checkPalindrome() {
    cout << "\nTask 3: Palindrome Checker\n";
    cout << "Input: ";
    string input;
    getline(cin, input);

    cout << "Output: ";
    if (isPalindrome(input)) {
        cout << "It’s a palindrome." << endl;
    } else {
        cout << "Not a palindrome." << endl;
    }
}

// Task 4: Find the Longest Word in a sentence
void findLongestWord() {
    cout << "\nTask 4: Find the Longest Word\n";
    cout << "Input: ";
    string sentence;
    getline(cin, sentence);

    string longestWord = "";
    size_t maxLen = 0;

    size_t start = 0, end = 0;
    while (end <= sentence.length()) {
        if (end == sentence.length() || sentence[end] == ' ') {
            string word = sentence.substr(start, end - start);
            if (word.length() > maxLen) {
                maxLen = word.length();
                longestWord = word;
            }
            start = end + 1;
        }
        end++;
    }

    cout << "Output:\n";
    cout << "Longest word: " << longestWord << endl;
    cout << "Length: " << maxLen << endl;
}

// Task 5: Character Histogram (counts letters ignoring digits and punctuation)
void charHistogram() {
    cout << "\nTask 5: Character Histogram\n";
    cout << "Input: ";
    string input;
    getline(cin, input);

    // Convert to uppercase
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    map<char, int> freq;
    for (char c : input) {
        if (isalpha(c)) {
            freq[c]++;
        }
    }

    cout << "Output:\n";
    for (auto &p : freq) {
        cout << p.first << " -> " << p.second << endl;
    }
}

// Task 6: Mask Email Address - mask username except first and last letter
void maskEmail() {
    cout << "\nTask 6: Mask Email Address\n";
    cout << "Input: ";
    string email;
    getline(cin, email);

    int atPos = email.find('@');
    if (atPos != string::npos && atPos > 1) {
        for (int i = 1; i < atPos - 1; i++) {
            email[i] = '*';
        }
        cout << "Output: " << email << endl;
    } else {
        cout << "Invalid email or username too short to mask." << endl;
    }
}

int main() {
    cout << "C++ Practice Lab — Strings, Substrings & Text Analysis\n";

    // Run each task twice (normal case and edge case)
    extractDomainFromEmail();   // Normal case
    extractDomainFromEmail();   // Edge case

    replaceMiramar();           // Normal case
    replaceMiramar();           // Edge case (no "Miramar")

    checkPalindrome();          // Normal palindrome
    checkPalindrome();          // Not a palindrome

    findLongestWord();          // Normal sentence
    findLongestWord();          // Sentence with multiple same-length words

    charHistogram();            // Mixed input
    charHistogram();            // All digits/symbols

    maskEmail();                // Normal case
    maskEmail();                // Edge case (too short username)

    cout << "\nAll tasks completed.\n";
    return 0;
}
```

## Screenshot Link

https://github.com/THo2018/assignments/blob/main/CISC191/images/C%2B%2B%20Practice%20Lab%20—%20Strings%2C%20Substrings%20%26%20Text%20Analysis%20Successful%20Execution%20code%20screenshot.png
