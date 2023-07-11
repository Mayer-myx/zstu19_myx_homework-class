#include<iostream>
#include<algorithm>
using namespace std;

int a[6];

int main() {
	int step = 1;
	while (step) {
		int sum = 0;
		for (int i = 0; i < 6; i++) { cin >> a[i]; sum += a[i] * (i + 1); }
		if (sum == 0) break;
		cout << "Collection #" << step << ":" << endl;
		if (sum % 2 == 1) {
			cout << "Can't be divided." << endl << endl; step++;  continue;
		}
		int res = sum / 2, maxj = 0; bool dp[60000];
		for (int i = 0; i < 60000; i++)dp[i] = false;
		dp[0] = 1;
		for (int i = 0; i < 6; i++) {
			if (!a[i] || dp[res])continue;
			for (int j = maxj; j >= 0; j--) {
				if (dp[j] && !dp[res]) {
					for (int k = 1; k <= a[i]; k++) {
						if (j + k * (i + 1) == res) {
							dp[res] = 1; break;
						}
						if (j + k * (i + 1) > res || dp[j + k * (i + 1)])break;
						dp[j + k * (i + 1)] = 1;
					}
				}
			}
			maxj += a[i] * (i + 1);
			if (maxj > res)maxj = res;
		}
		if (dp[res])cout << "Can be divided." << endl << endl;
		else cout << "Can't be divided." << endl << endl;
		step++;
	}
}
