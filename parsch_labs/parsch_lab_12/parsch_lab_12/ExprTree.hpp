#pragma once
#ifndef EXPRTREE_HEADER
#define EXPRTREE_HEADER

#include <memory>
#include <stdexcept>
#include <string>

using namespace std;

// The parent node for the tree. Contains all the base information
// as well as what type of node it actually is.
struct expr_node
{
	expr_node* higher = nullptr;
	expr_node* lower = nullptr;
	char node_type; // 'n' for numeric | 'o' for operator

	virtual string getValue() = 0;
};

// This represents a node with a numberic value
struct num_node : expr_node
{
	double value;

	num_node() { node_type = 'n'; }
	virtual string getValue() 
	{ 
		char toReturn[50] = {};

		sprintf_s(toReturn, 50, "%.2f", value);

		return (string)toReturn; 
	}
};

// This represents a node with an operator value
struct opr_node : expr_node
{
	char value;

	opr_node() { node_type = 'o'; }
	virtual string getValue() 
	{ 
		return (string)"" + value; 
	}
};

// The actual Expression Tree
class ExprTree
{
public:
	// ExprTree()
	// Constructor. Creates an empty expression tree.
	ExprTree();

	// ~ExprTree()
	// Destructor. Deallocates (frees) the memory used to store an expression tree.
	~ExprTree();

	// build()
	// Reads an arithmetic expression in prefix form from the keyboard and builds
	// the corresponding expression tree.
	void build() throw (bad_alloc);

	// expression()
	// Outputs the corresponding arithmetic expression in fully parenthesized infix
	// form.
	void expression() const;

	// evaluate()
	// Returns the value of the corresponding arithmetic expression.
	float evaluate() const throw (logic_error);

	// clear()
	// Removes all the data items in an expression tree.
	void clear();

	// showStructure()
	// Outputs an expression tree with its branches oriented from left (root) to
	// right (leaves) - that is, the tree is output rotated counterclockwise 90
	// degrees from its conventional orientation. If the tree is empty, outputs
	// "Empty tree.". Note that this operation is intended for debugging purposes
	// only. It assumes that arithmetic expressions contain only single-digit, nonnegative
	// integers and the arithmetic operators for addition, subtraction, multiplication, and
	// division.
	void showStructure() const;

protected:
	expr_node* top = nullptr;

	// clearLeaf
	// Clears a leaf and deletes its branches. Recursive.
	void clearLeaf(expr_node* toClear);


	// showLeaf()
	// Recursively displays leafs on a tree.
	void showLeaf(expr_node* toShow, int depth) const;

	// buildTree()
	// Recursively builds a tree from an expression tree.
	expr_node* buildTree(string& expr, unsigned int& pos) throw (bad_alloc);

	// buildExpression()
	// Recursively builds the expression as a string
	string buildExpression(expr_node* current) const;

	// nodeEvaluate()
	// Recursively evaluates the tree
	float nodeEvaluate(expr_node* current) const;
	
private:

};

#endif // EXPRTREE_HEADER