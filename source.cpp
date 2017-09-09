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
	int your_number[100];
	int my_number[100];
	int i;
	int t;
	int count;
	int x;
	cout<<"How many times do you want to play: ";cin>>t;
	for (i=1;i<=t;i++)
	{
		count=0;
		cout<<"gimme a number : ";cin>>your_number[i];
		do{
			count++;
			random_integer = rand();
			x = your_number[i] +10;
			random_integer=random_integer % x;
			cout<<your_number[i]<<"   "<<random_integer<<endl;
		}
		while(random_integer < your_number[i]);
		my_number[i]=random_integer;
		cout<<"it took me :"<<count<<" times to beat you"<<endl;
	}
	return 0;
}
