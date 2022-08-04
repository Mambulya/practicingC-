#include "E:\c++\practicing\std_lib_facilities.h"


int main()
{	
	double a;
	string m = "";
	double min = 1000000;
	double max = -100000000;
	double current = 0;
	vector<double> measures;

	cin >> a >> m;
	
	while (a != 0 and m != "")
	{
		if (m != "m" and m != "cm" and m != "in" and m != "ft") {
			cout << "Sorry, wrong dimension\n";
		}
		else {
			cout << "--- " << a << " " << m << "\n";
			if (m == "cm")
			{
				current = a * 0.01;
			}
			else if (m == "in")
			{
				current = a * 0.0254; // 2.54cm = 2.54 * 0.01m
			}
			else if (m == "ft")
			{
				current = a * 12 * 0.0254;
			}
			else
			{
				current = a;
			}
			measures.push_back(current);
		}
		if (current < min)
		{
			min = current;
		}
		else if (current > max)
		{
			max = current;
		}
		
		cin >> a >> m;
	}
	cout << "MIN = " << min << " m\n";
	cout << "MAX = " << max << " m\n";
	sort(measures);
	for (double m : measures)
	{
		cout << m << " m\n";
	}
}

