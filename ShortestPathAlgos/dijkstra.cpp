#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <set>

using namespace std;

class Graph {
public:
    int V;
    list<pair<int,int>> *l;

    Graph(int v) {
        this->V = v;
        this->l = new list<pair<int,int>> [this->V];
    }

    void insertEdge(int a, int b, int wt, bool undir = true) {
        this->l[a].push_back({wt, b});
        if (undir) this->l[b].push_back({wt, a});
    }

    int dijkstra(int source, int destination) {
        vector<int> dist(this->V, INT_MAX);
        dist[source] = 0;
        set<pair<int,int>> s;
        s.insert({0, source});

        while (!s.empty()) {
            auto it = s.begin();
            s.erase(it);

            int distTillNow = it->first;
            int node = it->second;

            for (auto nbrPair: this->l[node]) {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if ( currentEdge + distTillNow < dist[nbr] ) {
                    if (s.find({dist[nbr], nbr}) != s.end()) {
                        s.erase({dist[nbr], nbr});
                    }

                    dist[nbr] = currentEdge + distTillNow;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        return dist[destination];
    }
};

int main(void) {
    Graph g(5);
    g.insertEdge(0,1,1);
    g.insertEdge(1,2,1);
    g.insertEdge(0,2,4);
    g.insertEdge(0,3,7);
    g.insertEdge(3,2,2);
    g.insertEdge(3,4,3);

    cout << g.dijkstra(0,4) << endl;

    return 0;
}