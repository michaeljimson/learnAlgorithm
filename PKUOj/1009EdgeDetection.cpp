#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int size = 1000;
int width;
int total = 0;

typedef class OutMapPix
{
	public:
		int pos;
		int code;
}Pix;

int InMapPair[size][2];
Pix OutMap[size*8];

int cmp(const void* a,const void* b);
int GetValue(int pos);
int GetCode(int pos);

int main(int k)
{
	while(cin >> width && width){
		int pairv, pairt;
		k=total=0;
		while(cin >> pairv >> pairt && pairt){
			InMapPair[k][0] = pairv;
			InMapPair[k++][1] = pairt;
			total += pairt;
		}
		int PairNum = k;
		
		cout << width << endl;	
		
		int pos = 1;
		k = 0;
		for(int p=0; p <= PairNum; p++){
			int row = (pos-1) / width;
			int col = (pos-1) % width;
			
			for(int i=row-1; i<=row+1; i++)
				for(int j=col-1; j<= col+1; j++){
					int tpos = i * width + j;
					
					if(i<0 || j<0 || j>=width || tpos>=total)
						continue;
					
					OutMap[k].pos = tpos + 1;
					OutMap[k++].code = GetCode(tpos+1);
 				}
 		
 			pos += InMapPair[p][1];
		}		
		qsort(OutMap, k, sizeof(Pix), cmp);
		
		
		Pix temp = OutMap[0];
		for(int i=0; i<k; i++){
			if(temp.code == OutMap[i].code)
				continue;
			cout << temp.code << ' ' << OutMap[i].pos - temp.pos << endl;
			temp = OutMap[i];	
		}
		cout << temp.code << ' ' << total - temp.pos +1<< endl;
		cout << "0 0" << endl;
	}
		cout << 0 << endl;
	
	return 0;
}


int cmp(const void* a, const void* b)
{
	Pix* x = (Pix*) a;
	Pix* y = (Pix*) b;
	return x->pos - y->pos;
}

int GetValue(int pos)
{
	int i = 0, p = 0;
	while(p<pos)
		p+=InMapPair[i++][1];
	
	return InMapPair[i-1][0];
}

int GetCode(int pos)
{
	int code = GetValue(pos);
	
	int MaxAbs = 0;
	
	int row = (pos-1)/width;
	int col = (pos-1)%width;
	
	for(int i=row-1; i<=row+1; i++){
		for(int j = col-1; j<=col+1; j++){
			int tpos = i * width + j;
			
			if(i<0 || j<0 || j>=width || tpos >= total || tpos==pos-1)
				continue;
				
			int tcode = GetValue(tpos+1);
			
			if(MaxAbs < abs(tcode-code))
				MaxAbs = abs(tcode-code);	
		}
	}
	
	return MaxAbs;
}
