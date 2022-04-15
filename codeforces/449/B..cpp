/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5;
struct Edge{
	long long v, w, type;
	
	Edge() {}
	Edge(long long _v, long long _w, long long _type){
		v = _v;
		w = _w;
		type = _type;
	}
};

vector<Edge> ara[MX+5];
vector<long long> dist(MX+5, -1);
bool b[MX+5];

struct Node{
	long long cost, at;
	
	Node(long long _cost, int _at){
		cost = _cost;
		at = _at;
	}
};
bool operator<(Node A, Node B){
	return A.cost > B.cost;
}

int main()
{
	long long n, m, k, u, v, w;
	
	cin >> n >> m >> k;
	
	while(m--){
		cin >> u >> v >> w;
		
		ara[u].push_back(Edge(v, w, 0));
		ara[v].push_back(Edge(u, w, 0));
	}
	for(int K = 0; K < k; K++){
		cin >> v >> w;
		
		ara[1].push_back(Edge(v, w, 1));
		ara[v].push_back(Edge(1, w, 1));
	}
	
	
	priority_queue<Node> PQ;
	dist[1] = 0;
	PQ.push(Node(0, 1));
	
	while(!PQ.empty()){
		Node x = PQ.top();
		PQ.pop();
		
		if(x.cost != dist[x.at]) continue;
		dist[x.at] = x.cost;
		
		for(Edge e:ara[x.at]){
			if(dist[e.v] == -1 || dist[e.v] >  dist[x.at]+e.w){
				dist[e.v] = dist[x.at]+e.w;
				PQ.push(Node(dist[e.v], e.v));
			}
		}
	}
	
	for(int K = 1; K <= n; K++){
		for(Edge e:ara[K]){
			if(dist[K]+e.w == dist[e.v]){
				if(e.type == 0) b[e.v] = 1;
			}
		}
	}
	
	int ans = k;
	for(int K = 2; K <= n; K++) if(!b[K]) ans--;
	
	cout << ans << "\n";
	
	
	return 0;
}












