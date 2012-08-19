#include <cstdio>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[])
{

	int n, x0;

//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &x0);

	int left = 0;
	int right = 1000;

	int a, b;

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		if (a > b)
			swap(a, b);

		if (a < left && b < left) {
			printf("-1\n");
			return 0;
		}
		if (a > right && b > right) {
			printf("-1\n");
			return 0;
		}
		left = max(left, a);
		right = min(right, b);
	}
	if (x0 >= left && x0 <= right)
		printf("0\n");
	else {
		int result = min(abs(left - x0), abs(right - x0));
		printf("%d\n", result);
	}


	return 0;
}
