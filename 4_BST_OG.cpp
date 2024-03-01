#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
class Tree
{
public:
	int data;
	Tree *left = NULL, *right = NULL;
	// Constructor
	Tree(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

Tree *insert_node(Tree *root, int x){
	if (root == NULL){
		Tree *temp = new Tree(x);
		return temp;
	}
	if (root->data > x)
		root->left = insert_node(root->left, x);
	else
		root->right = insert_node(root->right, x);
	return root;
}

void inorder_traversal(Tree *root)
{
	if (root == NULL)
		return;
	inorder_traversal(root->left);
	cout << root->data << " ";
	inorder_traversal(root->right);
}

int search(Tree *root, int a)
{
	while (root != NULL)
	{
		if (root->data == a)
		{
			return a;
			cout << "found";
		}
		else if (a < root->data)
		{
			root = root->left;
		}
		else if (a > root->data)
		{
			root = root->right;
		}
	}
}

int Delete(Tree *root, int a)
{
	stack<Tree *> s;
	Tree *temp;

	while (root != NULL)
	{
		if (root->data == a)
		{
			if (root->left == NULL && root->right == NULL)
			{
				s.pop();
				root = s.top();
				if (s.top()->data > a)
				{
					root->left = NULL;
				}
				else
				{
					root->right = NULL;
				}
			}
			else
			{
				s = stack<Tree *>();
				if (root->right != NULL)
				{
					temp = root->right;
				}
				else
				{
					temp = root->left;
				}
				s.push(root);
				s.push(temp);
				while (temp->left != NULL)
				{
					temp = temp->left;
					s.push(temp);
				}
				root->data = temp->data;
				s.pop();
				temp = s.top();
				temp->left = NULL;
				cout << "Deleted \n";
			}
		}
		else if (a < root->data)
		{
			root = root->left;
			s.push(root);
		}
		else if (a > root->data)
		{
			root = root->right;
			s.push(root);
		}
	}
}

int main()
{

	Tree *root = new Tree(5);
	insert_node(root, 2);
	insert_node(root, 4);
	insert_node(root, 3);
	insert_node(root, 10);
	insert_node(root, 9);
	insert_node(root, 12);
	insert_node(root, 11);

	cout << "Inorder Traversal of the Binary Search Tree:";
	inorder_traversal(root);

	cout << "\n Search ? =";
	int s;
	cin >> s;
	if (0 == search(root, s))
	{
		cout << "not found";
	}
	else
	{
		cout << "found";
	}

	cout << "\n";

	cout << "\n Delete ? =";
	int d;
	cin >> d;
	Delete(root, d);
	inorder_traversal(root);

	return 0;
}
