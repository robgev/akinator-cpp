#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class zoo_tree
{
public:
	zoo_tree();
	~zoo_tree();

	void play(); //the main public function

private:
	struct node
	{
		string question;
		node *yes, *no;
		node(string new_q) : question(new_q), yes(NULL), no(NULL) {};
	};

	node *root;

	//Recursive implementations of the zoo_tree operations.
	//Private data type of the recursive argument makes them private too.

	void remove(node* start); //recursive argument called by value
	void traverse(node* &start); //recursive argument called by reference
	bool is_ancestor(node* start, string question1, string question2);
	bool subtree_includes(node *start, string question);
};
