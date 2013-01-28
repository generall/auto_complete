/*
 * complete.h
 *
 *  Created on: 27.01.2013
 *      Author: generall
 */

#ifndef COMPLETE_H_
#define COMPLETE_H_
#include "tree.h"
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class complete
{
private:
	class compare
	{
	public:
		bool operator()(pair<bool, char> a, pair<bool, char> b)
		{
			return a.second==b.second;
		}
	};
	tree<pair<bool, char> > prefix;

public:
	void add_word(const string &word);
	void print();
	void list(string _prefix, vector<string> &array);
	void load_from_file(string filenama);
	vector<string> finish(string word);
	complete();
	virtual ~complete();
};

#endif /* COMPLETE_H_ */
