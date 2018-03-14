#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>


using namespace std;

typedef long long int lint;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	double r1 = (double)a.first / a.second;
	double r2 = (double)b.first / b.second;
	return r1 > r2;
}

double f_knap(vector< pair<int, int> > &arr, int n, int W) {
	sort(arr.begin(), arr.end(), compare);
	int curWeight = 0;
	double finalvalue = 0.0;
	for (int i = 0; i < n; i++) {
		if (curWeight + arr[i].second <= W) {
			curWeight += arr[i].second;
			finalvalue += arr[i].first;
			cout << 1 << " ";
		} else {
			int remain = W - curWeight;
			finalvalue += arr[i].first * ((double) remain / arr[i].second);
			cout << arr[i].first * ((double) remain / arr[i].second) << " ";
			break;
		}
	}
	return finalvalue;
}

int main() {
	int N, C, x, y;
	cin >> N >> C;
	vector< pair<int, int> > A(N);
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		A[i].first = x;
		A[i].second = y;
	}
	double ans = f_knap(A, N, C);
	cout << "\n" << ans << endl;
	return 0;
}