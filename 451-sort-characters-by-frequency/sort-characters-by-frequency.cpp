class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto m:mp){
            q.push({m.second,m.first});
        }
        string res;
        while(!q.empty()){
            int freq=q.top().first;
            while(freq--){
                res+=q.top().second;
            }
            q.pop();
        }
        return res;
    }
};