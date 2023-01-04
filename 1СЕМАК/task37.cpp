#include <iostream>
using namespace std;

string sign = " ";

void reword() {
	
	string word;
	string prev;
	string next;

	cin >> prev;
	prev = prev.substr(0, prev.size() - 1);

	cin >> word;
	word = word.substr(0, word.size() - 1);



	while (sign != ".") {
		cin >> next;
		sign = next.substr(next.size() - 1, next.size()); // если точка, то это последнее слово
		next = next.substr(0, next.size() - 1);

		if (prev == next)
			cout << word << endl;

		prev = word;
		word = next;
	}
	if (prev == next)
		cout << word << endl;
}

int main() 
{	
	reword();

	return 0;
}
