#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

bool isNext(string base,string w)
{
	int diffs=0;
	int i;
	for (i = 0; i < 4; ++i) {
		if(base[i]!=w[i])++diffs;
	}
	return diffs==1;
}

int countNext(string base,const vector<string>& words)
{
	int nexts=0;
	for(auto i=words.begin();i!=words.end();++i)
		if(isNext(base,*i))
			++nexts;
	return nexts;
}

int main(int argc, const char *argv[])
{
	if(argc<2){cerr<<"Too few arguments."<<endl;exit(EXIT_FAILURE);}
	ifstream f("words.txt",ios::in);
	if(!f){cerr<<"No words.txt present/not openable"<<endl;exit(EXIT_FAILURE);}
	vector<string> words;
	string buf;
	int wcount=0;
	string mainword=argv[1];
	while(f>>buf)
	{
		words.push_back(buf);
		if(isNext(mainword,buf)) cout<<buf<<endl;
	}
/* Bonus 1: O(n^2) time, sigh.
 * Answer: care has 33 mutations.
 	for (auto i =words.begin();i!=words.end();++i) {
		if(countNext(*i,words)==33)
		{
			cout<<*i<<" has 33 mutations."<<endl;
			break;
		}
	}
*/

/* Bonus 2: 5508 depth with 3 depth
	vector<string> reached;
	reached.push_back("best");
	vector<string> nextreached;
    const int depth=3;
	int diffword=0;
	int i;
	for (i = 0; i < depth; ++i) {
 		for (auto j =reached.begin();j!=reached.end();++j) {
			for(auto k=words.begin();k!=words.end();++k){
				if(isNext(*j,*k))
				{
					++diffword;
					nextreached.push_back(*j);
				}
			}
		}
		reached=nextreached;
	}
	cout<<"best has "<<diffword<<" mutations in "<<depth<<" deep depth."<<endl;
*/
	cout<<mainword<<" string's mutations: "<<countNext(mainword,words)<<endl;
	f.close();
	return 0;
}
