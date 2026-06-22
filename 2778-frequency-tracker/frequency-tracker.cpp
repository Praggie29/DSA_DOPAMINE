class FrequencyTracker {
public:
    int cnt[100001] = {0};
    int freqCount[100001] = {0};
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int oldFreq = cnt[number];
        int newFreq = oldFreq + 1;
        if ( oldFreq > 0 ) {
            freqCount[oldFreq]--;
        }
        freqCount[newFreq]++;
        cnt[number] = newFreq;
    }
    
    void deleteOne(int number) {
        if ( cnt[number] == 0 ) return;
        int oldFreq = cnt[number];
        int newFreq = oldFreq - 1;
        freqCount[oldFreq]--;
        cnt[number] = newFreq;
        if ( newFreq > 0 ) {
            freqCount[newFreq]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if ( frequency > 100000 ) return false;
        return freqCount[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */