#include<iostream>
using namespace std;

int main(void)
{
	int p, e, i, d, icase = 0, x;
	while((cin >> p >> e >> i >> d), ~p)
	{
		x = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
		if(x == 0) x = 21252;
		cout << "Case " << ++icase << ": the next triple peak occurs in " << x << " days." << endl;
	}
	
	return 0;
}
