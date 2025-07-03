class Solution {
  public:
  int mah(vector<int>& arr){
      vector<int> karan;//nsr
      vector<int> aaryan;//nsl
      stack<pair<int,int>> s1;
      stack<pair<int,int>> s2;
      int n=arr.size();
      
      //nsl
      for(int i=0;i<n;i++){
          if(s1.size()==0){
              karan.push_back(-1);
          }
          else if(s1.size()>0 && s1.top().first <arr[i]){
              karan.push_back(s1.top().second);
          }
          else if(s1.size()>0 && s1.top().first >=arr[i]){
              while(s1.size()>0 && s1.top().first >=arr[i]){
                  s1.pop();
              }
              if(s1.size()==0){
                  karan.push_back(-1);
              }
              else{
                  karan.push_back(s1.top().second);
              }
          }
          s1.push({arr[i],i});
      }
      
       for(int i=n-1;i>=0;i--){
          if(s2.size()==0){
              aaryan.push_back(-1);
          }
          else if(s2.size()>0 && s2.top().first <arr[i]){
              aaryan.push_back(s2.top().second);
          }
          else if(s2.size()>0 && s2.top().first >=arr[i]){
              while(s2.size()>0 && s2.top().first >=arr[i]){
                  s2.pop();
              }
              if(s2.size()==0){
                  aaryan.push_back(-1);
              }
              else{
                  aaryan.push_back(s2.top().second);
              }
          }
          s2.push({arr[i],i});
      }
     reverse(aaryan.begin(),aaryan.end());
     
     int ans=0;
     for(int i=0;i<n;i++){
         int width=aaryan[i]-karan[i]-1;
         int area=width*arr[i];
         ans=max(ans,area);
     }
     
     return ans;
      
  }
    int maxWater(vector<int> &arr) {
        int n = arr.size();
    if (n <= 2) return 0;

    vector<int> left(n), right(n);
    
    // Fill left[]
    left[0] = arr[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], arr[i]);
    }

    // Fill right[]
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }

    // Calculate total trapped water
    int total_water = 0;
    for (int i = 0; i < n; i++) {
        total_water += min(left[i], right[i]) - arr[i];
    }

    return total_water;

        
    }
};