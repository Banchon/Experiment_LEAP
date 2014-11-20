#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> v = {1,2,3,4,5,6};

	for(auto a : v)
		cout << a << endl;

	return 0;
}
