#include<iostream>
using namespace std;

int main()
{
	double money=0.00;
	double sum=0.00;
	
	for(int i=0;i<12;i++)
	{
		cin>>money;
		sum+=money;
	}
	double average=sum/12;
	printf("$%.2lf", average);
	return 0;
}
