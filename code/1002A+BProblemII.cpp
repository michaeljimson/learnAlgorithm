#include<iostream>
#include<cstring>
using namespace std;

void Sum(string s1, string s2, char sum[], int& count)
{
	int len1 = s1.length();
	int len2 = s2.length();
	int i = len1-1, j = len2-1, temp = 0, up = 0;
	count = 0;
	
	while(i>=0&&j>=0)
	{
		temp = s1[i]-'0'+s2[j]-'0'+up;
		sum[count++] = temp%10+'0';
		up = temp/10;
		--i;
		--j;	
	}
	if(i>=0)
	{
		while(i>=0)
		{
			temp = s1[i]-'0'+up;
			sum[count++] = temp%10+'0';
			up = temp/10;
			--i;
		}
	}
	if(j>=0)
	{
		while(j>=0)
		{
			temp = s2[j]-'0'+up;
			sum[count++] = temp%10+'0';
			up = temp/10;
			--j;
		}
	}
		
	if(up>0)
	{
		sum[count++] = '1';
	}	
		
}

void reversePrint(char arr[], int len)
{
	for(int i = len-1;i>=0;--i)
	{
		cout<<arr[i];
	}
	cout<<endl;
}

int main()
{
	string s1, s2;
	char sum[2000];
	memset(sum,'0',2000);
	int nCount = 0;
	int caseNum, curCase = 0;
	cin>>caseNum;
	do{
		curCase++;
		cin>>s1>>s2;
		Sum(s1,s2,sum,nCount);
		cout<<"Case "<<curCase<<":"<<endl;
		cout<<s1<<" + "<<s2<<" = ";
		reversePrint(sum, nCount);
		if(curCase<caseNum)
		{
			cout<<endl;
		}
	}while(curCase<caseNum);
	return 0;
} 
