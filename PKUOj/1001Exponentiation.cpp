#include <iostream>
#include <string>
using std::string;


string Multiplication(string &a, string &b)
{
	int lenab = a.size() + b.size();
	int lena = a.size(), lenb = b.size();

	string c(lenab,'0');
	
	for (int i = lena - 1; i >= 0; --i)
	{
		int j = lenb - 1;
		int k = i + j + 1;
		while (j>=0)
		{
			int n = (a[i] - '0')*(b[j] - '0') + (c[k]-'0');
			c[k] = n % 10+'0';
			c[k-1] = ((c[k-1]-'0')+n / 10+'0');
			--j;
			--k;
		}
	}
	return c;
}


void Power(string &a, int n)
{
	--n;
	string b(a);
	while (n--)
	{
		a=Multiplication(a, b);
	}
}


int decimalPoint(string &a)
{
	int len = a.size();
	int i = a.find(".");
	if(i>=0)
		return len  - i - 1;
	return -1;
}

int addZero(string &b, int m)
{
	int len = b.size();
	return m - len;
}


void Decimal2Int(string &a)
{
	int x, y;
	x = a.find_first_not_of("0.");
	y = a.find(".");
	if (x > y)
		a = a.substr(x);
	else
	{
		a = a.substr(0, y) + a.substr(y+1);
	}
}

int main()
{
	string a;
	int n;
	int decimal;
	int len;
	int zero;
	while (std::cin >> a >> n)
	{
		decimal = n*decimalPoint(a);
		Decimal2Int(a);
		Power(a, n);
		a = a.substr(a.find_first_not_of("0"));
		len = a.size();
		zero = addZero(a, decimal);
		if (zero >= 0)
		{
			std::cout << ".";
			while (zero--)
				std::cout << "0";
			int j = a.find_last_not_of("0");
			std::cout << a.substr(0, j + 1) << std::endl;
		}
		else
		{
			std::cout << a.substr(0, len - decimal);
				
			int j = a.find_last_not_of("0");
			if (j - len + decimal + 1 > 0)
			{
				std::cout << ".";
				std::cout << a.substr(len - decimal, j - len + decimal + 1) ;
			}
			std::cout <<  std::endl;
		}
	}
	return 0;
}
