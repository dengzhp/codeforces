#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;
typedef pair<point, point> line;

bool test(int a, int b, int c, int d)
{
	if (a == b && b == c && c == d)
		return false;
	if (a != c && b != d)
		return false;
	return true;
}

bool vertical(line seg)
{
	return seg.first.first == seg.second.first;
}

bool test2(line seg[], int n)
{
	int a = -1, b = -1;

	for (int i = 0; i < 4; i++) {
		if (i == n)
			continue;
		if (seg[i] == seg[n] ||
		    (seg[i].first == seg[n].second &&
		     seg[i].second == seg[n].first))
			return false;

		if (seg[n].first == seg[i].first ||
		    seg[n].first == seg[i].second) {
			if (a != -1)
				return false;
			a = i;
			if (vertical(seg[n]) == vertical(seg[i]))
				return false;
		}

		if (seg[n].second == seg[i].first ||
		    seg[n].second == seg[i].second) {
			if (b != -1)
				return false;
			b = i;
			if (vertical(seg[n]) == vertical(seg[i]))
				return false;
		}

	}
	if (a == -1 || b == -1)
		return false;
	return true;
}

int main(int argc, char *argv[])
{
	line seg[4];
	int a, b, c, d;

//	freopen("input", "r", stdin);
	for (int i = 0; i < 4; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (!test(a, b, c, d)) {
			printf("NO\n");
			return 0;
		}
		seg[i] = make_pair(make_pair(a, b), make_pair(c, d));
	}

	for (int i = 0; i < 4; i++) {
		if (!test2(seg, i)) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}

