class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
         unordered_map<char, int> mp;
        int minlen=INT_MAX, start=0;
        for(auto ch:s2){
            mp[ch]++;
        }
        int i=0,j=0,count=mp.size();
        while(j<s1.length()){
            if(mp.find(s1[j])!=mp.end()){
                mp[s1[j]]--;
                if(mp[s1[j]]==0)
                    count--;
            }
            if(count==0){
                while(count==0){
                    if(mp.find(s1[i])!=mp.end()){
                        mp[s1[i]]++;
                        if(mp[s1[i]]==1) {
                            count++;
                            if(j-i+1<minlen){
                                minlen=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                }  
            }
            j++;
        }
        if(minlen==INT_MAX) return "";
        return s1.substr(start, minlen);
        
    }
};