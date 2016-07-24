#include <iostream>

#include "ExprTree.hpp"
#include "Stack.hpp"

using namespace std;

// clearLeaf
// Clears a leaf and deletes its branches. Recursive.
void ExprTree::clearLeaf(expr_node* toClear)
{
	if (toClear)
	{
		if (toClear->higher) { clearLeaf(toClear->higher); }
		if (toClear->lower) { clearLeaf(toClear->lower); }
		try { delete toClear; }
		catch (...) { cout << "We encountered an error while trying to clear a leaf..." << endl; }
	}
}


// showLeaf()
// Recursively displays leafs on a tree.
void ExprTree::showLeaf(expr_node* toShow, int depth) const
{
	// Check right
	if (toShow->higher)
	{
		showLeaf(toShow->higher, depth + 1); // Show right

		for (int i = 0; i < depth; i++) // Display '/'
		{
			cout << '\t';
		}
		cout << "  /" << endl;
	}

	// Show current
	if (!(toShow->higher || toShow->lower)) // If we have no branches...
	{
		depth -= 1;

		for (int i = 0; i < depth; i++)
		{
			cout << '\t';
		}

		cout << "   " << toShow->getValue() << endl;
	}
	else // If we have branches
	{
		for (int i = 0; i < depth; i++)
		{
			cout << '\t';
		}

		cout << toShow->getValue() << endl;
	}

	// Check left
	if (toShow->lower)
	{
		for (int i = 0; i < depth; i++) // Display '\'
		{
			cout << '\t';
		}
		cout << "  \\" << endl;

		showLeaf(toShow->lower, depth + 1); // Show left
	}
}

// buildTree()
// Recursively builds a tree from an expression tree.
expr_node* ExprTree::buildTree(string& expr, unsigned int& pos) throw (bad_alloc)
{
	// Digit or period
	// Adds a number to the point and ends the branch of the tree.
	if ((expr[pos] == '.') || ((expr[pos] >= '0') && (expr[pos] <= '9')))
	{
		string number;

		// If a number starts with '.' it actually starts with "0."
		if (expr[pos] == '.')
		{
			number = "0.";
			++pos;
		}

		// Rip the number right out of the string
		for (; (expr[pos] == '.') || ((expr[pos] >= '0') && (expr[pos] <= '9')); pos++)
		{
			number += expr[pos];
		}

		num_node* toReturn = new num_node();
		toReturn->value = stof(number.c_str());

		return toReturn;
	}
	// Operator
	// Creates a new split in the tree.
	else if ((expr[pos] == 'x') || (expr[pos] == 'X') || (expr[pos] == '*')
				|| (expr[pos] == '-') || (expr[pos] == '+') || (expr[pos] == '/'))
	{
		opr_node* toReturn = new opr_node();

		// Extract the value
		if ((expr[pos] == 'x') || (expr[pos] == 'X') || (expr[pos] == '*'))
		{
			toReturn->value = '*';
		}
		else { toReturn->value = expr[pos]; }

		// Move forward and get our branches
		++pos;
		toReturn->lower = buildTree(expr, pos);
		toReturn->higher = buildTree(expr, pos);
		return toReturn;
	}
	// Anything else
	// Advance 1 position and return the result of that position
	else
	{
		pos++;
		return buildTree(expr, pos);
	}
}

// buildExpression()
// Recursively builds the expression as a string
string ExprTree::buildExpression(expr_node* current) const
{
	if (current->node_type == 'o')
	{
		string toReturn = (string)((current != top) ? "(" : "") +
							buildExpression(current->lower) +
							+ " " + current->getValue() + " " +
							buildExpression(current->higher) +
							(string)((current != top) ? ")" : "");

		return toReturn;
	}
	else { return current->getValue(); }
}

// nodeEvaluate()
// Recursively evaluates the tree
float ExprTree::nodeEvaluate(expr_node* current) const
{
	if (current->node_type == 'o')
	{
		opr_node* val = (opr_node*)current;

		switch (val->value)
		{
		case '+':
			return nodeEvaluate(val->lower) + nodeEvaluate(val->higher);

		case '-':
			return nodeEvaluate(val->lower) - nodeEvaluate(val->higher);

		case '*':
			return nodeEvaluate(val->lower) * nodeEvaluate(val->higher);

		case '/':
			return nodeEvaluate(val->lower) / nodeEvaluate(val->higher);

		default:
			return 0;
		}
	}
	else
	{
		num_node* val = (num_node*)current;
		return val->value;
	}
}

// ExprTree()
// Constructor. Creates an empty expression tree.
ExprTree::ExprTree()
{

}

// ~ExprTree()
// Destructor. Deallocates (frees) the memory used to store an expression tree.
ExprTree::~ExprTree()
{
	clear();
}

// build()
// Reads an arithmetic expression in prefix form from the keyboard and builds
// the corresponding expression tree.
void ExprTree::build() throw(bad_alloc)
{
	string input;

	// Ensure that all memory is cleared before a tree is built
	clear();

	// Get the user's input
	cout << "Please input your expression in prefix form with spaces as delimiters:" << endl;
	getline(cin, input);

	// Process user input
	unsigned int pos = 0;
	top = buildTree(input, pos);
}

// expression()
// Outputs the corresponding arithmetic expression in fully parenthesized infix
// form.
void ExprTree::expression() const
{
	cout << buildExpression(top) << endl;
}

// evaluate()
// Returns the value of the corresponding arithmetic expression.
float ExprTree::evaluate() const throw(logic_error)
{
	if (!top) { throw logic_error("This tree is empty."); }

	return nodeEvaluate(top);
}

// clear()
// Removes all the data items in an expression tree.
void ExprTree::clear()
{
	if (top) { clearLeaf(top); top = NULL; }
}

// showStructure()
// Outputs an expression tree with its branches oriented from left (root) to
// right (leaves) - that is, the tree is output rotated counterclockwise 90
// degrees from its conventional orientation. If the tree is empty, outputs
// "Empty tree.". Note that this operation is intended for debugging purposes
// only. It assumes that arithmetic expressions contain only single-digit, nonnegative
// integers and the arithmetic operators for addition, subtraction, multiplication, and
// division.
void ExprTree::showStructure() const
{
	if (!top)
	{
		cout << "Empty tree..." << endl;
	}
	else
	{
		showLeaf(top, 0);
	}
}
