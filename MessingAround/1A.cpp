#include <iostream>

using namespace std;

int main() {
	// Construction
	int x(10);
	double y = 25.0;
	char c{ 'A' };
	bool b(true);

	cout << "enter x, y, c, b: ";

	cin >> x >> y >> c >> b;

	cout << x << " " << y << " " << c << " " << b;

	return 0;
}