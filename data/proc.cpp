#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
	ifstream Reader;
	ofstream Writer;
	Reader.open("nc-log2");
	Writer.open("result.csv");

	int node;
	char temp;
	int rssi;

	map<int, vector<int> > ivmap;

	while(1){
		Reader >> node >> temp >> rssi;
		if(Reader.eof())
			break;

		ivmap[node].push_back(rssi);
	}

	//cout << ivmap.size() << endl;
	for(auto it = ivmap.begin(); it != ivmap.end(); it++){
		//cout << it->first << " ";
		Writer << it->first << " ";
		for(int i = 0; i<it->second.size(); i++){
			if(it->second[i] > -90){
				//cout << it->second[i] << " ";
				Writer << it->second[i]+10 << " ";
			}
			else {
				//Writer << it->second[i]+14 << " ";
			}
		}
		//cout << endl;
		Writer << endl;
	}
	//cout << endl;
	return 0;
}