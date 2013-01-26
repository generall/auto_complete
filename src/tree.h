/*
 * tree.h
 *
 *  Created on: 26.01.2013
 *      Author: generall
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <vector>
typedef unsigned int uint;

template<class T>
class tree
{
private:
	class node
	{
	public:
		uint index;
		T value;
		std::vector<node*> children;
		node *parent;
		void delete_children()
		{
			for (uint i = 0; i < children.size(); i++)
			{
				delete children[i];
			}
			children.clear();
		}
		node* get_child(const uint a)
		{
			uint n = children.size();
			if (a > n)
				return NULL;
			return children[a];
		}

		node(T v, node* _parent = NULL, uint _index = 0) :
				parent(_parent), value(v), index(_index)
		{

		}
		~node()
		{
			delete_children();
		}
	};
public:
	node* current;
	node* root;
	void add(T value)
	{
		if (root == NULL)
		{
			root = new node(value);
			current = root;
		}
		else
		{
			int index = current->children.size();
			node* temp = new node(value, current, index);
			current->children.push_back()
		}
	}
	tree();
	~tree();
};

template<class T> tree<T>::tree()
{
	root = NULL;
	current = root;
	// TODO Auto-generated constructor stub

}

template<class T> tree<T>::~tree()
{
	if (root != NULL)
	{
		delete root;
	}
	// TODO Auto-generated destructor stub
}

#endif /* TREE_H_ */
