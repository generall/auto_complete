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
		node* getChild(const uint a)
		{
			uint n = children.size();
			if (a >= n)
				return NULL;
			return children[a];
		}

		node(T v, node* _parent = NULL, uint _index = 0) :
				index(_index), value(v), parent(_parent)
		{

		}
		~node()
		{
			delete_children();
		}
	};
public:
	uint level;
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
			current->children.push_back(temp);
		}
	}
	bool to_parent()
	{
		if (current != NULL)
		{
			current = current->parent;
			level--;
			return true;
		}
		return false;
	}
	bool to_child(const uint i)
	{
		node* temp = current->getChild(i);
		if (temp == NULL)
		{
			return false;
		}
		else
		{
			current = temp;
			level++;
			return true;
		}
	}
	bool right_neighbor()
	{
		if (current->parent == NULL)
			return false;
		uint index = current->index;
		node* temp = current->parent->getChild(index + 1);
		if (temp != NULL)
		{
			current = temp;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool left_neighbor()
	{
		if (current->parent == NULL)
			return false;
		uint index = current->index;
		node* temp = current->parent->getChild(index - 1);
		if (temp != NULL)
		{
			current = temp;
			return true;
		}
		else
		{
			return false;
		}
	}
	void to_root()
	{
		current = root;
		level = 0;
	}
	uint childrenCount()
	{
		return current->children.size();
	}
	void print()
	{
		for (uint i = 0; i < level; i++)
			std::cout << "-";
		std::cout << current->value << std::endl; //unknown eclipse error, comment pleas
		for (uint i = 0; i < current->children.size(); i++)
		{
			to_child(i);
			print();
			to_parent();
		}
	}
	tree();
	~tree();
};

template<class T> tree<T>::tree()
{
	root = NULL;
	level = 0;
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
