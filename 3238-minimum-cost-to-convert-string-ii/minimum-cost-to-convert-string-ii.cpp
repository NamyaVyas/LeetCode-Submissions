class Solution {
public:
    static constexpr long long INF = 1e18;

    struct Trie {
        unordered_map<char, Trie*> next;
        int id = -1;
    };

    void insert(Trie* root, const string& s, int id) {
        Trie* cur = root;
        for (char c : s) {
            if (!cur->next.count(c))
                cur->next[c] = new Trie();
            cur = cur->next[c];
        }
        cur->id = id;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        int n = source.size();
        int m = original.size();

        // 1) Assign unique IDs
        unordered_map<string, int> mp;
        int idx = 0;
        for (int i = 0; i < m; i++) {
            if (!mp.count(original[i])) mp[original[i]] = idx++;
            if (!mp.count(changed[i]))  mp[changed[i]]  = idx++;
        }

        int K = idx;

        // 2) Floyd–Warshall prep
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for (int i = 0; i < K; i++) dist[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < K; k++)
            for (int i = 0; i < K; i++)
                for (int j = 0; j < K; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // 3) Build tries
        Trie* srcTrie = new Trie();
        Trie* tgtTrie = new Trie();

        for (auto& [s, id] : mp) {
            insert(srcTrie, s, id);
            insert(tgtTrie, s, id);
        }

        // 4) DP
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // single char match
            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            Trie* p = srcTrie;
            Trie* q = tgtTrie;

            for (int j = i; j < n; j++) {
                if (!p->next.count(source[j]) || !q->next.count(target[j]))
                    break;

                p = p->next[source[j]];
                q = q->next[target[j]];

                if (p->id != -1 && q->id != -1) {
                    long long c = dist[p->id][q->id];
                    if (c < INF)
                        dp[j + 1] = min(dp[j + 1], dp[i] + c);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
