#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int a[100];
	int b[100];
	int i;
	
	for (i=1;i<=10;i++)
		a[i]=i;
	for (i=0;i<=10;i++)
	{
		b[i]=a[i]%2;
		cout<<b[i]<<endl;
	}
	return 0;
}
