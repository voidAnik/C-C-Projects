#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
int n, m, u, v, w;
struct Edge{
	int v, w;
	bool used;
	Edge(int _v, int _w){
		v = _v;
		w = _w;
		used = false;
	}
	//Edge(){
	//}
	//bool operator<(const Edge& p) const //using operator overloading
	//{
	//	return disA[v] < dis[p.v];
	//}
};
vector<Edge>ugraph[MAXN];
int distA[MAXN], distB[MAXN];

void add_edge(int u, int v, int w)
{
	Edge edge(v, w);
	ugraph[u].push_back(edge);
}

void Dijkstra(int source, int dis[])
{
	priority_queue<Edge>Q;
	for (int i = 0; i<n; i++){
		dis[i] = 100000000;
	}
	dis[source] = 0;
	Edge e(source, dis[source]);
	Q.push(e);

	while (!Q.empty()){
		int u = Q.top().v; Q.pop();
		for (int i = 0; i<(int)ugraph[u].size(); i++){
			int v = ugraph[u][i].v;
			if (dis[v] > dis[u] + ugraph[u][i].w){
				dis[v] = dis[u] + ugraph[u][i].w;
				Edge e(v, dis[v]);
				Q.push(e);
			}
		}
	}
	for (int i = 0; i<n; i++){
		printf("Distance for source of %d is: %d\n", i, dis[i]);
	}
}
void findSecondShortestPath(int N, int A, int B)
{
	Dijkstra(A, distA);
	Dijkstra(B, distB);

	int v0 = A, bestCost = distA[B];
	vector<Edge>::iterator it;
	vector<int> bestPath;
	while (v0 != B) {			
		bestPath.push_back(v0);
		for (it = ugraph[v0].begin(); it != ugraph[v0].end(); it++)
		if (distA[v0] + it->w + distB[it->v] == bestCost) {
			it->used = true;
			v0 = it->v;
			break;
		}
	}
	int second = 100000000, v, turningPoint, t;
	v0 = A;			
	while (v0 != B) {	
		for (it = ugraph[v0].begin(); it != ugraph[v0].end(); it++)
		if (it->used == false) {
			t = distA[v0] + it->w + distB[it->v];
			if (second > t) {
				second = t;
				turningPoint = v0;
			}
		}
		else
			v = it->v;
		v0 = v;
	}
	printf("Second best = %d\n", second);
	for (v0 = 0; bestPath[v0] != turningPoint; v0++)
		printf("%d ", bestPath[v0]);
	v0 = turningPoint;
	printf("%d ", v0);	// print path
	while (v0 != B) {
		for (it = ugraph[v0].begin(); it != ugraph[v0].end(); it++)
		if (distA[v0] + it->w + distB[it->v] == second) {
			printf("%d ", it->v);
			v0 = it->v;
			break;
		}
	}
	putchar('\n');
}
int main(void){

	scanf_s("%d %d", &n, &m);
	for (int i = 0; i<m; i++){
		scanf_s("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	printf("Printing the ugraph\n");
	for (int i = 0; i<n; i++){
		printf("%d :\n", i);
		for (int j = 0; j<(int)ugraph[i].size(); j++){
			printf("To: %d cost: %d\n", ugraph[i][j].v, ugraph[i][j].w);
		}
		puts("");
	}
	puts("===============================");
	int source, des;
	scanf_s("%d %d", &source, &des);
	findSecondShortestPath(n, source, des);
	return 0;
}