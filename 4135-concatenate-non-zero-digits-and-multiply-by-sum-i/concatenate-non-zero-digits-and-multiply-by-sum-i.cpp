class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long ans=0;
        vector<int>non;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                int dig=s[i]-'0';
                ans+=dig;
                non.push_back(dig);
            }
        }
        long long sum1=0;
        for(int i=0;i<non.size();i++){
            sum1=sum1*10+non[i];
        } 
        return sum1*ans;
    }
};