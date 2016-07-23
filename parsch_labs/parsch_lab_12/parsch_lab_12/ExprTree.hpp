#pragma once
#ifndef EXPRTREE_HEADER
#define EXPRTREE_HEADER

// The parent node for the tree. Contains all the base information
// as well as what type of node it actually is.
struct expr_node
{
	expr_node* higher = nullptr;
	expr_node* lower = nullptr;
	char node_type; // 'n' for numeric | 'o' for operator
};

// This represents a node with a numberic value
struct num_node : expr_node
{
	int value;

	num_node() { node_type = 'n'; }
};

// This represents a node with an operator value
struct opr_node : expr_node
{
	char opr;

	opr_node() { node_type = 'o'; }
};

// The actual Expression Tree
class ExprTree
{
public:
	ExprTree();
	~ExprTree();

protected:

private:

};

#endif // EXPRTREE_HEADER