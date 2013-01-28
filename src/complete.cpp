/*
 * complete.cpp
 *
 *  Created on: 27.01.2013
 *      Author: generall
 */

#include "complete.h"

complete::complete()
{
	prefix.add(pair<bool, char>(0, 0));
}

complete::~complete()
{
	// TODO Auto-generated destructor stub
}

void complete::print()
{
	for (uint i = 0; i < prefix.level; i++)
		std::cout << "-";
	std::cout << prefix.getValue().second << " . " << prefix.getValue().first
			<< std::endl; //unknown eclipse error, comment pleas
	for (uint i = 0; i < prefix.childrenCount(); i++)
	{
		prefix.to_child(i);
		print();
		prefix.to_parent();
	}
}
void complete::list(string _prefix, vector<string> &array)
{
	if (prefix.getValue().first == true)
	{
		array.push_back(_prefix);
	}
	for (uint i = 0; i < prefix.childrenCount(); i++)
	{
		prefix.to_child(i);
		list(_prefix + prefix.getValue().second , array);
		prefix.to_parent();
	}
}

vector<string> complete::finish(string word)
{
	string found_prefix="";
	bool is_found=true;
	vector<string> variants;
	for (uint i = 0; i < word.size(); i++)
	{
		int res = prefix.find_child(pair<bool, char>(0, word[i]),
				complete::compare());
		if (res != -1)
		{
			found_prefix+=word[i];
			prefix.to_child(res);
		}else{
			is_found=false;
			break;
		}
	}
	if(is_found)
	{
		list(word,variants);
	}
	prefix.to_root();
	return variants;
}

void complete::add_word(const string &word)
{
	for (uint i = 0; i < word.size(); i++)
	{
		int res = prefix.find_child(pair<bool, char>(0, word[i]),
				complete::compare());
		if (res != -1)
		{
			prefix.to_child(res);
		}
		else
		{
			prefix.add(pair<bool, char>(0, word[i]));
			prefix.to_child(prefix.childrenCount() - 1);
		}
	}
	prefix.setValue(pair<bool, char>(true, prefix.getValue().second));
	prefix.to_root();
}

void complete::load_from_file(string filename)
{
	ifstream dic_file;
	dic_file.open(filename.c_str(),ios::in);
	char input[1024];
	if(!dic_file.is_open())
	{
		throw std::runtime_error("file not found");
	}else{
		while(!dic_file.eof())
		{
			dic_file.getline(input,1024);
			add_word(input);
		}
	}
}
