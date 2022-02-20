#include <bits/stdc++.h>
using namespace std;

int mod_exp(int a, int b, int n) {
	if (a == 0 || a == 1) {
		return a%n;
	}

	if (b == 0) {
		return 1;
	}

	long ans = 1;

	while (b != 0) {
		if(b&1) {
			ans = (ans * a) % n;
		}
		a = (a * a) % n;
		b >>= 1;
	}

	return (int)((ans+c)%c);
}