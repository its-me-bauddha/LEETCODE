class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        char ch = t[0];
        int i=0;
        while(i<t.size()){
            if(s[i] != t[i]){
                ch = t[i];
                i++;
                break;
            }
            else{
                i++;
            }
        }
        return ch;
    }
};