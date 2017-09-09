#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand ((unsigned)time(0));
	int random_integer = rand();
	int a[100];
	int b[100];
	int i;
	
	for (i=1;i<=10;i++)
		a[i]=i;
	for (i=0;i<=10;i++)
	{
		b[i]=a[i]%2;
		cout<<"gimme a number (1 to 10) : ";cin>>b[i];
		do{
			random_integer = rand();
			random_integer=random_integer%10;
			cout<<b[i]<<endl<<random_integer<<endl;
		}
		while(random_integer < b[i]);
	}
	return 0;
}
