#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    unordered_set<string> st(wordList.begin(),wordList.end());
    st.erase(beginWord);
    
    while(!q.empty()) {
        string word = q.front().first;
        int transformation = q.front().second;
        q.pop();

        if (word == endWord) return transformation;

        for (int i=0 ; i<word.size() ; i++) {
            char original = word[i];
            for (char ch = 'a' ; ch <= 'z' ; ch++) {
                word[i] = ch;
                if (st.find(word) != st.end()) {
                    q.push({word,transformation+1});
                    st.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    
    int result = ladderLength(beginWord, endWord, wordList);
    cout << "The length of the shortest transformation sequence is: " << result << endl;
    
    return 0;
}