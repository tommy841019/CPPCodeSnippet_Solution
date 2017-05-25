#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "utility.h"



void printVector(const std::vector<std::string> &v)
{
	for(int i=0; i<v.size(); ++i){
		std::cout<<v.at(i)<<'\n';
	}

	for(std::vector<std::string>::const_iterator it(v.begin()); it!=v.end(); ++it){
		std::cout<<*it<<"-";
	}
}



int main()
{
	using namespace std;
	
	vector<string> names(20, "names");
	vector<string> names1(names.begin(), names.end());
	for(vector<string>::iterator it(names.begin()); it!=names.end(); ++it){
		cout<<*it<<'\0';
	}
	/*
	for(int i=0; i<names.size(); ++i){
		cout<<names.at(i)<<'\n';
	}

	vector< vector<string> > fullnames(20, vector<string>(20, "*"));
	for(int i=0; i<fullnames.size(); ++i){
		for(int j=0; j<fullnames.at(i).size(); ++j){
			cout<<fullnames.at(i).at(j)<<' ';
		}
		cout<<'\n';
	}

	printVector(names);
	*/
	vector< pair<string, pair<double, double> > > records;

	std::pair<string, pair<double, double> > record;
	record.first = "sol";
	record.second.first = 0.32;
	record.second.second = 0.65;

	records.push_back(record);

	cout<<records.size()<<" "<<records.capacity();

	map<string, int> map1;
	map1.insert(pair<string, int>("a", 1));
	map1.insert(pair<string, int>("b", 2));
	map1.insert(pair<string, int>("c", 3));
	vector< pair<string, int> > v1(map1.begin(), map1.end());
	cout<<v1[0].first<<endl;
	map1["d"]=4;
	cout<<map1["d"]<<endl;
	cout<<(map1.find("d")!=map1.end())<<endl<<map1.empty()<<endl;

	map1.clear();
	cout<<map1.size();

	int a;
	std::cin>>a;
	Utility::pauseForInput();
	return 0;
}

