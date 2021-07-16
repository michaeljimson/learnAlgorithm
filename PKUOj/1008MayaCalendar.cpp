#include <string.h>
#include <iostream>
using namespace std;
 
int main()
{
	char Haab_month_code[19][7] = {"pop", "no"    , "zip",   "zotz"  , "tzec",
		                           "xul", "yoxkin", "mol",   "chen"  , "yax" ,
		                           "zac", "ceh"   , "mac",   "kankin", "muan",
							       "pax", "koyab" , "cumhu", "uayet" };
 
	char Tzolkin_day_code[20][9] = {"imix" ,"ik"   ,"akbal","kan"  ,"chicchan",
		                            "cimi" ,"manik","lamat","muluk","ok"      ,
								    "chuen","eb"   ,"ben"  ,"ix"   ,"mem"     ,
								    "cib"  ,"caban","eznab","canac","ahau"   };
 
	int n;
	cin>>n;
	int  *day = new int[n];
	char **day_name = new char*[n];
	int  *year = new int[n];
 
	for(int i=0; i<n; ++i)
	{
		int H_day;
		char dot;
		char H_month[10];
		int H_year;
 
		cin>>H_day;
		cin>>dot;
		cin>>H_month;
		cin>>H_year;
 
		int month_int =0;
		for(int j=0; j<19; ++j)
		{	if(!strcmp(H_month,Haab_month_code[j]))
				month_int = j;			
		}
 
		int num = 0;
		if(month_int != 18)
		{	num = H_year*365 + month_int*20 + H_day; }
		else
		{	num = H_year*365 + 360 +H_day;}
 
		day_name[i] = new char[10];
		day[i]      = ((num%260)%13+1);
		day_name[i] = Tzolkin_day_code[(num%260)%20];
		year[i]     =( num/260);
 
	}
 
	cout<<n<<endl;
	for(int i=0; i<n; ++i)
	{
		cout<<day[i]<<" ";
		cout<<day_name[i]<<" ";
		cout<<year[i]<<endl;	
	}
 
	return 0;
}
