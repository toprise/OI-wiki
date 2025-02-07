#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
int c[N];
int ans = 0;
void merge_sort(int l, int r) {
	if (l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int i = l, j = mid + 1, pos = i;
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) {
			ans += mid - i + 1;
			c[pos++] = a[j++];
		}
		else {
			c[pos++] = a[i++];
		}
	}
	while (i <= mid) {
		c[pos++] = a[i++]; 
	}
	while (j <= r) {
		c[pos++] = a[j++];
	}
	for (int i = l; i <= r; i++) {
		a[i] = c[i];
	}
	return ;
} // ans 为逆序对个数
