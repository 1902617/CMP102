#include <iostream> 
using namespace std;

int main()
{
	for (int i = 99; i > 0; i--)
	{
		if (i != 1)
		{
			cout << i << " bottles of beer on the wall " << i << " bottles of beer." << endl;
			cout << "Take one down, pass it around, " << (i - 1) << " bottles of beer on the wall." << endl;
		}
		else
		{
			cout << "1 bottle of beer on the wall, 1 bottle of beer. " << endl;
			cout << "Take 1 down, pass it around, 0 bottles of beer on the wall." << endl;
		}
	}

	cout << "No more bottles of beer on the wall, no more bottles of beer.Go to the storeand buy some more, 99 bottles of beer on the wall." << endl;
}