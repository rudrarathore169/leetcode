class Solution {
public:
    vector<int> a, b, c;
    int d;
    vector<vector<int>> e;

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int f = 0;
        for (char ch : s)
            if (ch == '1')
                f++;

        vector<int> h, i;

        int n = s.size();
        int idx = 0;
        while (idx < n) {
            if (s[idx] == '0') {
                int st = idx;
                while (idx < n && s[idx] == '0')
                    idx++;
                h.push_back(st);
                i.push_back(idx - 1);
            } else {
                idx++;
            }
        }

        a = h;
        b = i;
        d = a.size();

        c.clear();
        for (int k = 0; k < d - 1; k++) {
            c.push_back((b[k] - a[k] + 1) + (b[k + 1] - a[k + 1] + 1));
        }

        e.clear();
        e.push_back(c);

        int l = c.size();

        for (int m = 1; m * 2 <= l; m <<= 1) {
            vector<int>& prev = e.back();
            vector<int> cur(prev.size() - m);
            for (int p = 0; p < (int)cur.size(); p++) {
                cur[p] = max(prev[p], prev[p + m]);
            }
            e.push_back(cur);
        }

        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(f + u(q[0], q[1]));
        }

        return ans;
    }

    int t(int f, int g) {
        int h = 31 - __builtin_clz(g - f + 1);
        return max(e[h][f], e[h][g - (1 << h) + 1]);
    }

    int v(int f, int g, int h) {
        return c[f]
             - max(0, g - a[f])
             - max(0, b[f + 1] - h);
    }

    int u(int f, int g) {
        if (d < 2)
            return 0;

        int h = w(b, f);
        int i = x(a, g) - 2;

        if (h > i)
            return 0;

        return max(
            max(v(h, f, g), v(i, f, g)),
            (i - h >= 2 ? t(h + 1, i - 1) : 0)
        );
    }

    static int w(const vector<int>& a, int b) {
        int c = 0, d = a.size();
        while (c < d) {
            int e = (c + d) >> 1;
            if (a[e] < b)
                c = e + 1;
            else
                d = e;
        }
        return c;
    }

    static int x(const vector<int>& a, int b) {
        int c = 0, d = a.size();
        while (c < d) {
            int e = (c + d) >> 1;
            if (a[e] <= b)
                c = e + 1;
            else
                d = e;
        }
        return c;
    }
};