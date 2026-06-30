class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt[3]={-1,-1,-1};
        int sum=0;
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']=i;
            if(cnt[0]!=-1 && cnt[1]!=-1 && cnt[2]!=-1){
                sum+=(1+min({cnt[0],cnt[1],cnt[2]}));
            }
        }
        return sum;
    }
};