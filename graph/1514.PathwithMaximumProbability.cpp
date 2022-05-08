class Solution {
public:
    //Dijkstra's 
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans = 0;
        vector<unordered_map<int, double>> nProb(n);
        for (int i = 0; i<edges.size(); i++) {
            nProb[edges[i][0]][edges[i][1]] = succProb[i];
            nProb[edges[i][1]][edges[i][0]] = succProb[i];
        }
        queue<int> q;
        q.push(start);
        
        vector<double> probs(n,0.0);
        probs[start] = 1;
        
        while (!q.empty()) {
                int cur = q.front();
                q.pop();
        
                for (auto& it : nProb[cur] ) {
                    int next = it.first;
                    if (probs[cur]*it.second > probs[next]) {
                        probs[next] = probs[cur]*it.second;
                        q.push(next);
                    }
                }
        }
        return probs[end];
        
    }

};
