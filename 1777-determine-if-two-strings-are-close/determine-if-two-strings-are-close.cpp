class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map <char , int> mpp1 , mpp2;
        for ( char ch : word1 ) mpp1[ch]++;
        for ( char ch : word2 ) mpp2[ch]++;

        if ( word1.size() != word2.size() ) return false;

        vector <char> ans1 , ans2;
        vector <int> freq1 , freq2;

        for ( auto &it : mpp1 ) {
            freq1.push_back( it.second );
            ans1.push_back( it.first);
        }

        for ( auto &it : mpp2 ) {
            freq2.push_back( it.second );
            ans2.push_back(it.first);
        }

        sort ( ans1.begin() , ans1.end() );
        sort ( ans2.begin() , ans2.end() );
        sort ( freq1.begin() , freq1.end() );
        sort ( freq2.begin() , freq2.end() );
        if ( ans1 == ans2  && freq1 == freq2 ) return true;
        return false;
    }
};