//Displays the output of the 1,2,3 and 4 times table
#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << (i * j) << endl;
		}	
	}
}