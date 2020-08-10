#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream Reader;
	ofstream Writer;
	Reader.open("raw1");
	Writer.open("data.csv");


	srand (time(NULL));
	int rss;

	while(1){
		Reader >> rss;
		if(Reader.eof()){
			break;
		}
		if(rss>-90 && rss<-60){
			rss = -94 + rand()%5;
		}
		Writer << rss << " ";
	}



	return 0;
}