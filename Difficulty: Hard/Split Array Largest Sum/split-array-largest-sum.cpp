//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool karan(int nums[],int n,int k,int maxsum){
    int current=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+nums[i]>maxsum){
            current++;
            sum=nums[i];
            if(current>k){
                return false;
            }
        }
        else{
            sum+=nums[i];
        }
    }
    return true;
}
    int splitArray(int arr[] ,int N, int K) {
        
        int sum=0;
        int maxx=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            maxx=max(maxx,arr[i]);
        }
        int s=maxx;
        int e=sum;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(karan(arr,N,K,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends