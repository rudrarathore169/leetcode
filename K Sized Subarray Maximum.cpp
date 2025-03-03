class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          // code here
          int n=arr.size();
          vector<int> ans;
          deque<int> q;
          for(int i=0;i<k;i++) {
              while(!q.empty() && arr[q.back()] <= arr[i]) 
                  q.pop_back();
              q.push_back(i);
          }
          
          int low=0, high=k-1;
          while(high < n) {
              while(!q.empty() && q.front() < low) 
                  q.pop_front();
              ans.push_back(arr[q.front()]);
              low += 1;
              high += 1;
              if(high < n) {
                  while(!q.empty() && arr[q.back()] <= arr[high])
                      q.pop_back();
                  q.push_back(high);
              }
          }
          
          return ans;
      }
  };