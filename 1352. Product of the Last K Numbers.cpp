class ProductOfNumbers {
    public:
        vector<int> prefix; 
        
        ProductOfNumbers() {
            prefix = {1}; 
        }
        
        void add(int num) {
            if (num == 0) {
                prefix = {1};
            } else {
                prefix.push_back(prefix.back() * num);
            }
        }
        
        int getProduct(int k) {
            if (k >= prefix.size()) return 0; 
            return prefix.back() / prefix[prefix.size() - 1 - k];
        }
    };
    