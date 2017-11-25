#include "zoo_tree.h"

zoo_tree::zoo_tree() : root(NULL)
{
}

zoo_tree::~zoo_tree()
{
	remove(root);
}

void zoo_tree::remove(node* start)
{
	if (start != NULL) {
		remove(start->no);
		remove(start->yes);
		delete start;
	}
}

void zoo_tree::play()
{
	char replay = 'y';

	while (replay == 'y') {
		traverse(root);
		cout << "Play again? (y/n)\n";
		cin >> replay;
	}
}

void zoo_tree::traverse(node* &start)
{
	if (start == NULL) {
		cout << "You win:(\nEnter the animal and its question, please\n";
		string a, q;
		cin >> a >> q;
		start = new node(q);
		start->yes = new node("Is_it_a_" + a + "?");
	}
	else {
		cout << start->question << endl;
		char reply;
		cin >> reply;
		if (reply == 'n') traverse(start->no);
		else if (start->yes != NULL) traverse(start->yes);
		else cout << "I win :)\n";
	}
}

bool zoo_tree::is_ancestor(node *start, string question1, string question2)
{
	if (start == NULL)
		return false;
	if (start->question == question1)
		return subtree_includes(start, question2);
	return is_ancestor(start->yes, question1, question2) || is_ancestor(start->no, question1, question2);
}

bool zoo_tree::subtree_includes(node *start, string question)
{
	if (start == NULL)
		return false;
	if (start->question == question)
		return true;
	return subtree_includes(start->yes, question) || subtree_includes(start->no, question);
}
