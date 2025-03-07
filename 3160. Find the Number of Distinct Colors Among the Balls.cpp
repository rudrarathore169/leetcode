class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_color;
        unordered_map<int, int> color_count;
        vector<int> ans;
        int count = 0;

        for (auto &q : queries) {
            int ball = q[0], color = q[1];

            // If the ball already had a color, decrease the previous color count
            if (ball_color.count(ball)) {
                int prev_color = ball_color[ball];
                color_count[prev_color]--;
                if (color_count[prev_color] == 0) {
                    color_count.erase(prev_color);
                }
            }

            // Assign the new color to the ball
            ball_color[ball] = color;
            color_count[color]++;

            // Unique colors = size of color_count map
            ans.push_back(color_count.size());
        }
        return ans;
    }
};
