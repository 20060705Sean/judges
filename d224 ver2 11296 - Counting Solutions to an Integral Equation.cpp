#include <iostream>
using namespace std;

static const auto Initialize = [] {
	cin.sync_with_stdio(false); cin.tie(nullptr);
	return nullptr;
}();

int main() {
	int number;
	while (cin >> number) {
		number >>= 1;
		cout << ((long long)(number + 2) * (number + 1) >> 1) << '\n';
	}
}
