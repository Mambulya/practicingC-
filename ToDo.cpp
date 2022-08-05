// ДОДЕЛАТЬ

#include "E:\c++\practicing\std_lib_facilities.h"


int main()
{
	string answer;

	cout << "Think of the number between 1 and 100\n";
	cout << "Your number bigger then 50? (yes/no)\n";
	cin >> answer;

	if (answer == "yes") 
	{	// 51 ... 100
		cout << "Your number bigger then 75? (yes/no)\n";
		cin >> answer;
		if (answer == "yes")
		{
			// 76 ... 100
		}
		else
		{
			// 51 ... 75
			cout << "Your number bigger then 62? (yes/no)\n";
			cin >> answer;
			if (answer == "yes")
			{
				// 63 ... 75
			}
			else
			{
				// 51 ... 62
				cout << "Your number bigger then 56? (yes/no)\n";
				cin >> answer;
				if (answer == "yes") {
					// 57 ... 62
					cout << "Your number bigger then 60? (yes/no)\n";
					cin >> answer;
					if (answer == "yes")
					{
						// 60, 61, 62
						cout << "Is your number 61?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 62?\n";
							cin >> answer;
							if (answer == "yes")
							{
								cout << "Yooooo\n";
							}
							else
							{
								cout << "Is your number 60?\n";
								cin >> answer;
								cout << "Yoooooooo\n";
							}
						}
					}
					else
					{	// 57 ... 60
						cout << "Is your number 57?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 58?\n";
							cin >> answer;
							if (answer == "yes")
							{
								cout << "Yooooo\n";
							}
							else
							{
								cout << "Is your number 59?\n";
								cin >> answer;
								cout << "Yoooooooo\n";
							}
						}
					}
				}
				else
				{
					// 51 ... 56
					cout << "Your number bigger then 53? (yes/no)\n";
					cin >> answer;
					if (answer == "yes")
					{
						// 54, 55, 56
						cout << "Is your number 54?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 55?\n";
							cin >> answer;
							if (answer == "yes")
							{
								cout << "Yooooo\n";
							}
							else
							{
								cout << "Is your number 56?\n";
								cin >> answer;
								cout << "Yoooooooo\n";
							}
						}
					}
					else
					{
						// 51, 52, 53
						cout << "Is your number 51?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 52?\n";
							cin >> answer;
							if (answer == "yes")
							{
								cout << "Yooooo\n";
							}
							else
							{
								cout << "Is your number 53?\n";
								cin >> answer;
								cout << "Yoooooooo\n";
							}
						}
					}
				}
			}
		}
	}
	
	else 
	{	// 1 ... 50
	cout << "Your number bigger then 25? (yes/no)\n";
	cin >> answer;
	if (answer == "yes")
	{
		// 26 ... 50

	}
	else
	{
		// 1 ... 25
		cout << "Your number bigger then 12? (yes/no)\n";
		cin >> answer;
		if (answer == "yes")
		{	
			// 13 ... 25
			cout << "Your number bigger then 6? (yes/no)\n";
			cin >> answer;
			if (answer == "yes") {
				// 7 ... 12
				cout << "Your number bigger then 10? (yes/no)\n";
				cin >> answer;
				if (answer == "yes")
				{
					// 10, 11, 12
					cout << "Is your number 12?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 12?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 10?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
				else
				{	// 7 ... 9
					cout << "Is your number 7?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 8?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 9?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
			}
			else
			{
				// 1 ... 6
				cout << "Your number bigger then 3? (yes/no)\n";
				cin >> answer;
				if (answer == "yes")
				{
					// 4, 5, 6
					cout << "Is your number 4?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 5?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 6?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
				else
				{
					// 1, 2, 3
					cout << "Is your number 1?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 2?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 3?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
			}
		}
		else
		{
			// 1 ... 12
			cout << "Your number bigger then 6? (yes/no)\n";
			cin >> answer;
			if (answer == "yes") {
				// 7 ... 12
				cout << "Your number bigger then 10? (yes/no)\n";
				cin >> answer;
				if (answer == "yes")
				{
					// 10, 11, 12
					cout << "Is your number 12?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 12?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 10?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
				else
				{	// 7 ... 9
					cout << "Is your number 7?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 8?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 9?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
			}
			else
			{
				// 1 ... 6
				cout << "Your number bigger then 3? (yes/no)\n";
				cin >> answer;
				if (answer == "yes")
				{
					// 4, 5, 6
					cout << "Is your number 4?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 5?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 6?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
				else
				{
					// 1, 2, 3
					cout << "Is your number 1?\n";
					cin >> answer;
					if (answer == "yes")
					{
						cout << "Yooooo\n";
					}
					else
					{
						cout << "Is your number 2?\n";
						cin >> answer;
						if (answer == "yes")
						{
							cout << "Yooooo\n";
						}
						else
						{
							cout << "Is your number 3?\n";
							cin >> answer;
							cout << "Yoooooooo\n";
						}
					}
				}
			}
		}
	}
	}
}
