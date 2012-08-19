#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

edge E[200];
vector<int> G[205];

edge cut;

int color[205];  // dfs marker

/* return farthest distance and that node */
pair<int, int> dfs(int v)
{
	int f = 0, n = v;

	color[v] = 1;
	for (int i = 0; i < G[v].size(); i++) {
		if (make_pair(v, G[v][i]) != cut &&
		    make_pair(G[v][i], v) != cut &&
		    color[G[v][i]] == 0) {
			pair<int, int> r = dfs(G[v][i]);
			if (r.first + 1 > f) {
				f = r.first + 1;
				n = r.second;
			}
		}
	}
	return make_pair(f, n);
}

int diameter(int i)
{
	memset(color, 0, sizeof(color));
	pair<int, int> f = dfs(i);
	memset(color, 0, sizeof(color));
	pair<int, int> d = dfs(f.second);
	return d.first;
}


int main(int argc, char *argv[])
{

//	freopen("input", "r", stdin);
	int N;

	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		E[i] = make_pair(a, b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int result = 0;

	for (int i = 0; i < N - 1; i++) {
		cut = E[i];
		a = diameter(cut.first);
		b = diameter(cut.second);
		result = max(result, a * b);
	}
	printf("%d\n", result);

	return 0;
}
