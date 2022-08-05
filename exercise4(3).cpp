#include "E:\c++\practicing\std_lib_facilities.h"


int main()
{	
	double sum = 0.0, m = 0.0;
	double min = 10000000, max = -10000000;
	vector<double> distances;

	cin >> m; 

	while (m != 0.0) {

		distances.push_back(m);
		sum += m;

		if (m > max) {
			max = m;
		}
		else if (m < min) {
			min = m;
		}
		cin >> m;
	}

	for (int i = 0; i < size(distances); ++i) {

	}

	cout << "sum distances: " << sum << "\n";
	cout << "min distance: " << min << "\n";
	cout << "max distance: " << max << "\n";
	cout << "avarage distance: " << (sum / size(distances)) << "\n";
	
}
