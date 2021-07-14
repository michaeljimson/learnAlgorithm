#include<iostream>

using namespace std;

int main()
{
	float n = 0.0;
	while(cin>>n)
	{
		float sum = 0;
		float i = 0;
		int count = 0;
		if(n==0.00)
			break;
		for(i=2.0;sum<=n;i++){
			sum+=1/i;
			count++;
		}
		printf("%d card(s)\n",count);
	}
	return 0;
}
