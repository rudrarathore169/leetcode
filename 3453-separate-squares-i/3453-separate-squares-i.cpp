class Solution {
public:
    bool check(vector<vector<int>>& squares, double midy, double total) {
        double bottomarea = 0;
        for (auto &square : squares) {
            double y = square[1];
            double l = square[2];
            double bottomy = y;
            double topy = y + l;
            if (midy >= topy) {
                bottomarea += l * l;
            } else if (midy > bottomy) {
                bottomarea += l * (midy - bottomy);
            }
        }
        return bottomarea >= (total) / 2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double totalarea = 0.00000;
        for (auto &square : squares) {
            double x = square[0];
            double y = square[1];
            double l = square[2];
            low = min(low, y);
            high = max(high, y + l);
            totalarea += l * l;
        }
        double res = 0.00000;
        while (high - low > 1e-5) {
            double midy = low + (high - low) / 2;
            res = midy;
            if (check(squares, midy, totalarea)==true) {
                high = midy;
            } else {
                low = midy;
            }
        }
        return res;
    }
};