#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Source_5.h"



using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace std;



void count_words()
{
	string s;
	map<string, int> counters;

	while (cin >> s)
		++counters[s];

	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;  // using pair data structure: pair<const K, V> it->first is key, it->second is value
	}
}



map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)  // find_words has default value: split
{
	string line;
	int line_number = 0;
	map<string, vector<int>> ret;

	while (getline(in, line))
	{
		++line_number;

		vector<string> words = find_words(line);

		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
		{
			ret[*it].push_back(line_number);
		}
	}

	return ret;
}



typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;



Grammar read_grammer(istream& in)
{
	Grammar ret;
	string line;

	while (getline(in, line))
	{
		vector<string> entry = split(line);
		if (!entry.empty())
		{
			ret[entry[0]].push_back(Rule(entry.begin()+1, entry.end()));
		}
	}

	return ret;
}



vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}



bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}



void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word))
	{
		ret.push_back(word);
	}
	else
	{
		Grammar::const_iterator it = g.find(word);  // search word in map keys
		if (it == g.end())
			throw logic_error("empty rule");

		const Rule_collection& c = it->second;

		const Rule& r = c[nrand(c.size())];

		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
		{
			gen_aux(g, *i, ret);
		}
	}
}



int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
	{
		throw domain_error("out of range");
	}

	const int bucket_size = RAND_MAX / n;
	int r;
	do { r = rand() / bucket_size; }  // user rand() to generate a number between 0 and RAND_MAX
	while (r >= n);

	return r;
}



int source_7()
{
	count_words();

	return 0;
}