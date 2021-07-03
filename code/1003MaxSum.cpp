#include<iostream>
using namespace std;

int MaxSum(int a[], int& x, int& y)
{
	int temp, sum=-1001;
	for(int i=0; i<sizeof(a)+1;i++)
	{
		temp=a[i];
		for(int j=i+1;j<sizeof(a)+1;j++)
		{
			temp+=a[j];
			cout<<temp<<endl; 
			if(sum<temp)
			{
				sum = temp;
				x = i;
				y = j;
			}
		}	
	}
	
	return sum;
}

int main()
{
	int nCount, queneCount, x, y, sum, n=1;

	cin>>nCount;
	while(nCount--)
	{
		cin>>queneCount;
		int a[queneCount];
		for(int i=0; i<queneCount;i++)
		{
			cin>>a[i];
			//cout<<a[i]<<endl;
		}	
		x = 0;
		y = queneCount-1;
		sum = MaxSum(a,x,y);
		cout<<"Case "<<n++<<":"<<endl;
		cout<<sum<<" "<<x+1<<" "<<y+1<<endl;
		if(nCount!=1)
		cout<<endl;
		
	}
	return 0;
}
