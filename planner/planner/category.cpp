#include "category.h"

// copying the category tree
void copyCategory(Node*& thisRoot, Node* sourceRoot)
{
	if (sourceRoot == nullptr)
		thisRoot = sourceRoot;
	else
	{
		thisRoot = new Node();
	}
}