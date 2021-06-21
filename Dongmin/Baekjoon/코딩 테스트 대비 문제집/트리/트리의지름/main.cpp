#include<iostream>
#include<vector>
using namespace std;
#define MAX_NODE 10001
struct Edge;
struct Node;

struct Diameter {
    int total;
    int long_arm;
};
struct Node {
    vector<struct Edge*> children;
    Node() {}
    ~Node() {
        for (int i=0; i<children.size(); i++) {
            delete children[i];
        }
    }
    void addEdge(struct Edge* edge) {
        children.push_back(edge);
    }
};

struct Edge {
    struct Node *to;
    int weight;
    
    Edge(struct Node* to, int weight) {
        this->to = to;
        this->weight = weight;
    }
    ~Edge() {
        to->~Node();
    }
};


Node* nodes[MAX_NODE];

Node* makeTree(int n, vector<vector<int> > &edges) {
    for (int i=1; i<=n; i++) {
        nodes[i] = new Node();
    }
    
    for (auto edge: edges) {
        Edge* e = new Edge(nodes[edge[1]], edge[2]);
        nodes[edge[0]]->addEdge(e);
    }
    return nodes[1];
}

Diameter getMaxLength(Node* tree) {    
    vector<Edge*> children = tree->children;
    if (children.size() == 0) {
        return Diameter {0,0};
    }
    
    int max_total_arm = 0;
    int max_arm = 0;
    int second_max_arm = 0;
    for (int i=0; i<children.size(); i++) {
        int w = children[i]->weight;

        Diameter d = getMaxLength(children[i]->to);

        max_total_arm = max(max_total_arm, d.total);
        int arm = w + d.long_arm;
        if (arm > max_arm) {
            second_max_arm = max_arm;
            max_arm = arm;
        } else {
            second_max_arm = max(arm, second_max_arm);
        }
    }

    return Diameter{max(max_arm + second_max_arm, max_total_arm), max_arm};
}

int solve(int n, vector<vector<int> > edges) {
    Node* tree = makeTree(n, edges);
    return getMaxLength(tree).total;
}

int main() {
    int n;
    vector<vector<int> > edges;
    cin >> n;
    edges.assign(n-1, vector<int>(3,0));
    
    for (int i=0; i<n-1; i++) {
        vector<int> edge(3, 0);
        cin >> edge[0] >> edge[1] >> edge[2];
        edges[i] = edge;
    }
    
    cout << solve(n, edges) << endl;
    return 0;
}