//============================================================================
// Name        : tree_template.cpp
// Author      : generall
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

int main()
{
	tree<int> t;
	t.add(0);
	t.add(2);
	t.add(5);
	t.add(7);
	t.to_child(0);
	t.add(3);
	t.add(4);
	t.to_parent();
	t.to_child(1);
	t.add(6);
	t.right_neighbor();
	t.add(8);
	t.to_root();
	t.print();

	cout << "1" << endl; // prints
	return 0;
}
