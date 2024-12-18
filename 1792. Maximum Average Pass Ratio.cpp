class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       
        auto calcGain = [](int pass, int total) {
            double currentRatio = (double)pass / total;
            double newRatio = (double)(pass + 1) / (total + 1);
            return newRatio - currentRatio;
        };

       
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < classes.size(); i++) {
            double gain = calcGain(classes[i][0], classes[i][1]);
            pq.push({gain, {classes[i][0], classes[i][1]}});
        }

     
        while (extraStudents > 0) {
            pair<double, pair<int, int>> top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            pass++;
            total++;

            double gain = calcGain(pass, total);
            pq.push({gain, {pass, total}});
            extraStudents--;
        }

   
        double ans = 0.0;
        while (!pq.empty()) {
            pair<double, pair<int, int>> top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            ans += (double)pass / total;
        }

        return ans / classes.size();
    }
};
