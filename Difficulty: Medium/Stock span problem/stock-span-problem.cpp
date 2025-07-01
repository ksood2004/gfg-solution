class Solution {
  public:
  
    vector<int> calculateSpan(vector<int>& arr) {
         int n=arr.size();
      stack<pair<int,int>> s;
      vector<int> karan;
      for(int i=0;i<n;i++){
          if(s.size()==0){
              karan.push_back(-1);
          }
          else if(s.size()>0 && s.top().first>arr[i]){
              karan.push_back(s.top().second);
          }
          else if(s.size()>0 && s.top().first<=arr[i]){
              while(s.size()>0 && s.top().first<=arr[i]){
                  s.pop();
              }
              if(s.size()==0){
                  karan.push_back(-1);
              }
              else{
                  karan.push_back(s.top().second);
              }
          }
          s.push({arr[i],i});
      }
      for(int i=0;i<n;i++){
          karan[i]=i-karan[i];
      }
      return karan;
        
        
    }
};