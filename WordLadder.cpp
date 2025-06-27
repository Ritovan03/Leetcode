#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        int step = 1;
        for(string word:wordList)
        {
            dict.insert(word);
        }
        queue<string> q;
        q.push(beginWord);
        if(dict.find(endWord) == dict.end())
        {
            return 0;
        }
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                string temp = q.front();
                q.pop();
                for(int j = 0;j<temp.size();j++)
                {
                    for(char c = 'a';c<='z';c++)
                    {
                        if(c == temp[j])
                        {
                            continue;
                        }
                        
                        char t = temp[j];
                        temp[j] = c;
                        if(temp == endWord)
                        {
                            return step+1;
                        }
                        if(dict.find(temp) != dict.end())
                        {
                            q.push(temp);
                            
                            dict.erase(temp);
                        }
                        temp[j] = t;
                    }
                }
            }
            step++;
        }

        return 0;
    }
};