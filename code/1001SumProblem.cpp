#include<iostream>
using namespace std;

int main()
{
	int a, sum = 0;
	while(cin >> a){
	
		for(int i=1; i<=a;i++){
			sum += i;
		}
		cout<<sum<<endl<<endl;
		sum = 0;
		
	}
	
	return 0;
}
