// This code will give MLE / TLE on LeetCode.

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<vector<string>> q;
    q.push({beginWord});
    unordered_set<string> st(wordList.begin(),wordList.end());
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    vector<vector<string>> ans;

    while(!q.empty()) {
        for (auto it : usedOnLevel) {
            st.erase(it);
        }
        usedOnLevel.clear();

        int s = q.size();
        for (int i=0 ; i<s ; i++) {
            vector<string> vec = q.front();
            q.pop();
            string word = vec[vec.size()-1];

            if (word == endWord) {
                ans.push_back(vec);
                continue;
            }

            for (int j=0 ; j<word.size() ; j++) {
                char original = word[j];
                for (char ch='a' ; ch<='z' ; ch++) {
                    word[j] = ch;
                    if (st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        usedOnLevel.push_back(word);
                    }
                }
                word[j] = original;
            }
        }
    }
    return ans;
}   

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = findLadders(beginWord, endWord, wordList);
    
    cout << "The transformation sequences are:\n";
    for (const auto& sequence : result) {
        for (const auto& word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}