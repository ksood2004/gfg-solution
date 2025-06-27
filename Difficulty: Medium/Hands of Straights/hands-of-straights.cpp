class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize!=0){
            return false;
        }
        map<int,int> mp;
        for(int i=0;i<N;i++){
            mp[hand[i]]++;
        }
        while(!mp.empty()){
            int card=mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                int start=card+i;
                if(mp[start]==0){
                    return false;
                }
                mp[start]--;
                if(mp[start]==0){
                    mp.erase(start);
                }
            }
        }
        return true;
    }
};