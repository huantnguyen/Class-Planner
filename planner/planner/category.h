#ifndef CATEGORY_H
#define CATEGORY_H
#include "lecture.h"
#include <vector>

struct Node
{
	// vector of subcategories
	std::vector<Node*> subcat;
	// node back up to the parent category
	Node* parent = nullptr;
	// vector of all lectures under this category
	// only for the leaves
	std::vector<Lecture*> lectures;
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

	void add(Lecture* lecture);

	// destructor
	~Category();
};

#endif