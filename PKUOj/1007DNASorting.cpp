#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


typedef struct{
	char s[51];
	int num;
}DNA;

int InversionNumber(char *s, int n)
{
	int num = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(s[i] > s[j])
				num++;
		}
	}
	return num;
}

bool cmp(DNA a, DNA b){
	return a.num < b.num;
}

int main()
{
	int n, m;
	cin >> n >> m;
	DNA *a = new DNA [m];
	for(int i = 0; i< m; i++){
		cin >> a[i].s;
		a[i].num = InversionNumber(a[i].s, n);
	}
	sort(a, a + m, cmp);
	
	for(int i = 0; i < m; i++)
		cout << a[i].s << endl;
	return 0;
}
