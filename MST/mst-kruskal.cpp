#include <bits/stdc++.h>
using namespace std;


int parent[100];

void make_set(int n){
    parent[n] = n;
}

int find_set(int n){
    if(parent[n] == n) return n;
    return parent[n] = find_set(parent[n]);
}

void union_set(int u, int v){
    int pu = find_set(u);
    int pv = find_set(v);
    if(pu == pv) return;
    // parent[pu] = parent[pv];
    
    parent[pv] = parent[pu];
}


struct Edge{
    int from, to, weight;
    Edge(int x, int y, int w){
        from = x;
        to = y;
        weight = w;
    }
    void print(){
        cout<<"From: "<<from<<", To: "<<to<<", weight: "<<weight<<endl;
    }

    bool operator < (const Edge & e2){
        return weight < e2.weight;
    }
};

vector<Edge> edges;

int main(){
    int noOfVertices, noOfEdges;
    cin>>noOfVertices >> noOfEdges;

    for(int i=0; i<= noOfVertices; i++){
        make_set(i);
    }

    for(int i=0; i<noOfEdges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    for(int i=0; i<noOfEdges; i++){
        edges[i].print();
    }

    sort(edges.begin(), edges.end());

    cout<<"Sorted"<<endl;
    for(int i=0; i<noOfEdges; i++){
        edges[i].print();
    }

    vector<Edge> mstEdges;

    for(int i=0; i< noOfEdges; i++){
        int u = edges[i].from;
        int v = edges[i].to;
        
        int ur = find_set(u);
        int vr = find_set(v);

        if(ur == vr){
            continue;
        }

        mstEdges.push_back(edges[i]);
        union_set(ur, vr);
    }

    cout<<"MST Edges"<<endl;
    for(int i=0; i<noOfVertices-1; i++){
        mstEdges[i].print();
    }
}
