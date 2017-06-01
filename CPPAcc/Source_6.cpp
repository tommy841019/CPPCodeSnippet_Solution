#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include "Student_info.h"

using std::copy;
using std::isspace;
using std::string;
using std::vector;
using std::find_if;



bool space(char c)
{
	return isspace(c);
}



bool not_space(char c)
{
	return !isspace(c);
}



vector<string> split_iter(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), not_space);  // test for each char in iter i, stop if not_space is true, otherwise return str.end()

		iter j = find_if(i, str.end(), space);

		if (i != str.end())	
			ret.push_back(string(i, j));  // construct a string from i to j, push_back to ret

		i = j;
	}

	return ret;
}



bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}



bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());  // find, search c in url_ch
}



string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b,e, not_url_char);  // go through b to e, text if any is not url char
}



string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";
	typedef string::const_iterator iter;
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e)  // search, search sep in i to e
	{
		if (i != b && i + sep.size() != e)
		{
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))  // if find valid char, keep moving backward
			{
				--beg;
			}
			if (beg != i && !not_url_char(i[sep.size()]))  // protocol not at the beginning and there is at least one url_char after separator
			{
				return beg;
			}
		}
		i += sep.size();
	}
	return e;
}



vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while (b != e)
	{
		b = url_beg(b, e);

		if (b != e)
		{
			iter after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}

	return ret;
}



bool did_all_homework(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0))==s.homework.end());
}



int source_6()
{
	//  copy(bottom.begin(), bottom.end(), back_inserter(ret));

	return 0;
}