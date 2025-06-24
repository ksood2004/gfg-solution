class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        set<int> s;
        int n=arr.size();
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        int index=0;
        for(int val: s){
            arr[index]=val;
            index++;
        }
        return s.size();
    }
};