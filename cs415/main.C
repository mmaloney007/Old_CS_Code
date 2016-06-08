#include<iostream.h>
bool oddoreven(int v);

int main(){
	int x;
	int y;
	int xSq;
	int ySq;
	cout << "x, y, xSq, ySq";
	cin >> x;
	cin >> y;
	cin >> xSq;
	cin >> ySq;

while((y--) > 0){
	int i, j, k, l, m;
	if(oddoreven(x)){
	for(i=0;i < x;i++)
	if(oddoreven(x) != 1)
	for(k=0; k < ySq; k++)
	for(j=0;j < xSq; j++)
	cout << '*';
	}
	else(oddoreven(x))
	for(l=0;i < ySq; l++)
	for(j=0;j < xSq; j++)
	cout << ' ';
	
	else
	cerr << "fuck";
	cout << '\n';
	}	
	return 0;
}

bool oddoreven(int v)
{
	return (v % 2) != 0;
}
