#pragma once

#include "BSTNode.hpp"
#include <fstream>

template <typename data>
class BST
{
public:
	// Constructor
	BST(const std::string fileLoc);

	// Destructor
	~BST();

	// Print the tree in order (left to right, bottom up)
	void printTree() const;

	// Search the tree for an occurance of a node
	// Takes a parameter to search for
	// Returns the node's data
	template <typename searchType>
	BSTNode<data>* search(const searchType target) const;

private:
	// Data Member
	BSTNode<data>* root;

	/* ------------ Member Methods ------------ */

	// Inserts a new node into the BST
	// Takes a parameter of the same data type as the BST, and a pointer to the root; Neither may be NULL
	// Returns true if node was inserted
	bool insert(const data nData, BSTNode<data>* subTRoot);

	// Print the tree in order recursively (left to right, bottom up)
	// Takes a pointer to the current node
	void printTree(BSTNode<data>* subTRoot) const;

	// Deconstructs the tree recursively in post order (bottom up)
	// Takes a pointer to the current node
	void destroyPostOrder(BSTNode<data>* subTRoot);
};

/* -------------- Template Methods-------------- */

// Constructor
template <typename data>
BST<data>::BST(const std::string fileLoc)
{
	// Initialize an empty tree
	root = nullptr;

	// Open the given file
	std::fstream file(fileLoc);

	// Extract each datapoint from the file
	while (!file.eof())
	{
		data nData;

		file >> nData;
		
		// Set the new data as the root node if tree is empty
		if (root == nullptr)
			root = new BSTNode<data>(nData);

		// Otherwise insert the data into the tree
		else
			insert(nData, root);
	}

	// Close the file
	file.close();
}

// Destructor
template <typename data>
BST<data>::~BST()
{
	destroyPostOrder(root);
}

// Print the tree in order (left to right, bottom up)
template <typename data>
void BST<data>::printTree() const
{
	printTree(root);
}

// Search the tree for an occurance of a node
// Takes a character to search for
// Returns the node's data; nullptr if no node was found
template <typename data>
template <typename searchType>
BSTNode<data>* BST<data>::search(const searchType target) const
{
	// Traversal pointer
	BSTNode<data>* pCur = root;

	// While we have not reached a leaf
	while (pCur != nullptr)
	{
		// Return the node once found
		if (pCur->getData() == target)
			return pCur;

		// Search the left tree if target is less than current node
		if (pCur->getData() > target)
		{
			pCur = pCur->getLeft();
			continue;
		}

		// Search the right tree if target is greater than current node
		if (pCur->getData() < target)
			pCur = pCur->getRight();
	}

	// Return a nullptr if node was not found
	return nullptr;
}

// Inserts a new node into the BST
// Takes a parameter of the same data type as the BST
// Returns true if node was inserted
template <typename data>
bool BST<data>::insert(const data nData, BSTNode<data>* subTRoot)
{
	// Search the left branch
	if (subTRoot->getData() > nData)
	{
		if (subTRoot->getLeft() != nullptr)
			return insert(nData, subTRoot->getLeft());

		subTRoot->setLeftPtr(new BSTNode<data>(nData));
		return true;
	}

	// Search the right branch
	else if (subTRoot->getData() < nData)
	{
		if (subTRoot->getRight() != nullptr)
			return insert(nData, subTRoot->getRight());

		subTRoot->setRightPtr(new BSTNode<data>(nData));
		return true;
	}

	return false;
}

// Print the tree in order recursively (left to right, bottom up)
// Takes a pointer to the current node
template <typename data>
void BST<data>::printTree(BSTNode<data>* subTRoot) const
{
	// Traverse the left branch
	if (subTRoot->getLeft() != nullptr)
		printTree(subTRoot->getLeft());

	// Print the node when it cannot move any further left
	std::cout << subTRoot->getData() << std::endl;

	// Traverse the right branch
	if (subTRoot->getRight() != nullptr)
		printTree(subTRoot->getRight());
}

// Deconstructs the tree recursively in post order (bottom up)
// Takes a pointer to the current node
template <typename data>
void BST<data>::destroyPostOrder(BSTNode<data>* subTRoot)
{
	// Traverse the left subtree
	if (subTRoot->getLeft() != nullptr)
		destroyPostOrder(subTRoot->getLeft());

	// Traverse the right subtree
	if (subTRoot->getRight() != nullptr)
		destroyPostOrder(subTRoot->getRight());

	// Delete the node once you cannot traverse in either direction
	delete subTRoot;
}