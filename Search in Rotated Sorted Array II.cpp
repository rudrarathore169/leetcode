class Solution {
public:
    bool search(vector<int>& arr, int key) {
    int up = -1;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            up = i + 1; 
            break;
        }
    }

    if (up == -1) {
        up = 0; 
    }

    int a = -1;


    if (binarysearch(a, 0, up - 1, key, arr)) {
        return true;
    }

    if (binarysearch(a, up, arr.size() - 1, key, arr)) {
        return true;
    }

    return false;
    }
    bool binarysearch(int& a, int s, int e, int k, vector<int>& arr) {
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k) {
            
            return true;
        } else if (arr[mid] < k) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return false;
}



    
};