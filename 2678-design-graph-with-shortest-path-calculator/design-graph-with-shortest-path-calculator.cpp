using P = pair<int, int>;
class Graph {
public:
    int n;
    unordered_map<int, list<P>> adjList;

    Graph(int n, vector<vector<int>>& edges) {

        this->n = n;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adjList[u].push_back({v, cost});
        }
    }

    void addEdge(vector<int> edge) {

        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        adjList[u].push_back({v, cost});
    }

    int shortestPath(int src, int dest) {

        vector<int> dist(n, INT_MAX);

        // {distance, node}
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {

            auto [curr_dist, node] = pq.top();
            pq.pop();

            // Purana distance hai
            if (curr_dist > dist[node]) {
                continue;
            }

            // Destination mil gaya
            if (node == dest) {
                return curr_dist;
            }

            // Neighbours check karo
            for (auto [nbr, edge_cost] : adjList[node]) {

                // Better distance mila
                if (curr_dist + edge_cost < dist[nbr]) {

                    dist[nbr] = curr_dist + edge_cost;

                    pq.push({curr_dist + edge_cost, nbr});
                }
            }
        }

        return -1;
    }
};