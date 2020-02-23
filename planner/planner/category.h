#ifndef CATEGORY_H
#define CATEGORY_H
#include "lecture.h"
#include <vector>
/*
struct Node
{
	// vector of subcategories
	std::vector<Node*> subcat;
	
	// node back up to the parent category
	Node* parent;

	// vector of all lectures under this category
	// only for the leaves
	std::vector<Lecture*> lectures;

	// name of the category
	std::string name;

	// default constructor
	Node() : parent(nullptr), name("") {};
	// check up on this constructor
	Node(std::string input_name, std::vector<Lecture*> input_lectures) : parent(nullptr), name(input_name) {};
};

class Category
{
private:
	Node* root;
	void copyCategory(Node*& thisRoot, Node* sourceRoot);
	void clearCategory(Node* thisRoot);
public:
	// default constructor
	Category() : root(nullptr) {};

	// copy constructor
	Category(const Category& rhs);

	// assignment operator
	const Category& operator=(const Category& rhs);

	// add a node
	void addLeaf(std::vector<Lecture*> input);

	void addSub(std::vector<Node*> input);

	// destructor
	~Category();
};
*/
#endif