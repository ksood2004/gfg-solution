class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Min heap with tie-breaker: bigger number first if frequency same
        priority_queue<pair<int, int>> pq;
        for (auto& it : freq) {
            pq.push({it.second, -it.first});  // store -num for tie-breaking
        }

        vector<int> result;
        while (!pq.empty()) {
            int count = pq.top().first;
            int num = -pq.top().second;  // restore original number
            pq.pop();
            for (int i = 0; i < count; i++) {
                result.push_back(num);
            }
        }

        return result;
    }
};