#include <stdio.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void foundNumber(int num,int tries,int n)
{
	printf("Tehát a kitalált számod: %i!\n",num);
	printf("Ez mindössze %i kérdésbe került a %i lehetőség közül! :)\n",tries,n);
}

int main(int argc, const char *argv[])
{
	printf("Gondolj egy számra 1-től N-1-ig, ahol N: ");
	int N;
	cin>>N;
	int max=N; 
	int current=max/2;
	int prev;
	int questions=0;
	char response;

	while (true) {
		if (current==max-1 && max!=3){foundNumber(current,questions,N);break;}
		cout<<"Nagyobb vagy egyenlő a számod ennél a számnál: "<< current <<"? (Igen,Nem,Egyenlő)=(i,n,e)"<<endl; 
		questions++;
		cin>>response;
		if(response=='i')
		{
			prev=current;
			current+=(max-current)/2;
		}
		else if(response=='n')
		{
			max=current;
			current-=(current-prev)/2;
		}
		else if(response=='e')
		{
			foundNumber(current,questions,N);
			break;
		}
	}
	return 0;
}
