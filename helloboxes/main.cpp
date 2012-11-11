#include <stdio.h>
#include <iostream>
#include <string>

int main(int argc, const char *argv[])
{
	printf("Give me the padding you want: ");
	int PAD;
	std::cin>>PAD;
	const int ROWS=PAD*2+3;
	printf("Give me your name: ");
	std::string name;
	std::cin >> name;
	const std::string greeting="Hello "+name+'!';
	const std::string::size_type COLS=greeting.size()+PAD*2+2;
	printf("\n");
	for (int r = 0; r < ROWS; ++r) {
		std::string::size_type c=0;
		while (c!=COLS) {
			if (r==PAD+1 && c==PAD+1) {
				std::cout<<greeting;
				c+=greeting.size();
			}
			else
			{
				if (r==0||r==ROWS-1||c==0||c==COLS-1) 
					std::cout<<'*';
				else
					std::cout<<' ';
				++c;

			}
		}
		
	printf("\n");
	}
	return 0;
}
