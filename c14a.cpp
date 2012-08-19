#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
	int n, m;
	scanf("%d%d", &n, &m);

	char sheet[60][60];

	for (int i = 0; i < n; ++i) {
		scanf("%s", sheet[i]);
	}

	int rs = 0, re = n - 1;
	int cs = 0, ce = m - 1;

	// find Rs
	for (int i = 0; i < n; ++i) {
		bool cut = true;
		for (int j = 0; j < m; j++) {
			if (sheet[i][j] != '.') {
				cut = false;
				break;
			}
		}
		rs = i;
		if (!cut) {
			break;
		}
	}

	// find Re
	for (int i = n - 1; i >= 0; i--) {
		bool cut = true;
		for (int j = 0; j < m; j++) {
			if (sheet[i][j] != '.') {
				cut = false;
				break;
			}
		}
		re = i;
		if (!cut) {
			break;
		}
	}

	// find Cs
	for (int i = 0; i < m; ++i) {
		bool cut = true;
		for (int j = 0; j < n; j++) {
			if (sheet[j][i] != '.') {
				cut = false;
				break;
			}
		}
		cs = i;
		if (!cut) {
			break;
		}
	}

	// find Ce
	for (int i = m - 1; i >=0; i--) {
		bool cut = true;
		for (int j = 0; j < n; j++) {
			if (sheet[j][i] != '.') {
				cut = false;
				break;
			}
		}
		ce = i;
		if (!cut) {
			break;
		}
	}


	for (int i = rs; i <= re; i++) {
		for (int j = cs; j <= ce; j++)
			printf("%c", sheet[i][j]);
		puts("");
	}

	return 0;
}


