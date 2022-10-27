#pragma once

#include <iostream>

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 6	                                               *
 * Date: 10/28/22                                                              *
 *                                                                             *
 * Description: This program converts a given text file to morse code		   *
 *				using a Binary Search Tree									   *
 ******************************************************************************/

template <typename data>
class BSTNode
{
public:
	// Constructor
	BSTNode(const data& nData);

	// Getters
	data getData() const { return mData; }
	BSTNode<data>* getRight() const { return mpRight; }
	BSTNode<data>* getLeft() const { return mpLeft; }

	// Setters
	void setData(const data nData) { mData = nData; }
	void setRightPtr(BSTNode<data>* const npRight) { mpRight = npRight; }
	void setLeftPtr(BSTNode<data>* const npLeft) { mpLeft = npLeft; }

private:
	// Data Members
	data mData;
	BSTNode<data>* mpRight;
	BSTNode<data>* mpLeft;
};

/* -------------- Template Methods-------------- */

// Constructor
template <typename data>
BSTNode<data>::BSTNode(const data& nData)
{
	mData = nData;
	mpRight = nullptr;
	mpLeft = nullptr;
}