#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class node1
{
	int data;
	node1 *left;
	node1 *right;

public:
	node1(int value);
	friend class node2;
};
node1::node1(int value)
{
	data = value;
	left = NULL;
	right = NULL;
}
class node2
{
	node1 *root;
	node1 *insert();
	void inorder(node1 *root);
	void preorder(node1 *root);
	void postorder(node1 *root);
	void level(node1 *root);
	int countNode(node1 *root);
	int countLeaf(node1 *root);

public:
	node2();
	void traversal(); // iterative
	void level();
	void count();
};
node2::node2()
{
	root = insert();
}
node1 *node2::insert()
{
	int n;
	cout << "Data (-1 for exit): ";
	cin >> n;
	if (n == -1)
	{
		return NULL;
	}
	node1 *newnode = new node1(n);
	cout << "LC of " << newnode->data << " : ";
	newnode->left = insert();
	cout << "RC of " << newnode->data << " : ";
	newnode->right = insert();
	return newnode;
}
int node2::countLeaf(node1 *root)
{
	/*	int n;
		if(root){
			if(!root->left)
				n = 1;
			else{
				n=countLeaf(root->left);
				n = n + countLeaf(root->right);
			}
		}
		return n;
	*/
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	else
		return countLeaf(root->left) + countLeaf(root->right);
}
int node2::countNode(node1 *root)
{
	if (root)
	{
		return 1 + countNode(root->left) + countNode(root->right);
	}
	return 0;
}
void node2::level(node1 *root)
{
	queue<node1 *> q;
	node1 *current = root;
	q.push(current);
	q.push(NULL);
	while (q.size() > 1)
	{
		current = q.front();
		q.pop();
		if (current == NULL)
		{
			q.push(NULL);
			cout << endl;
		}
		else
		{
			if (current->left)
				q.push(current->left);
			if (current->right)
				q.push(current->right);
			cout << current->data << " ";
		}
	}
}
void node2::postorder(node1 *root)
{
	stack<node1 *> s1, s2;
	node1 *current = root;
	s1.push(current);
	while (!s1.empty())
	{
		current = s1.top();
		s1.pop();
		s2.push(current);
		if (current->left)
			s1.push(current->left);
		if (current->right)
			s1.push(current->right);
	}
	while (!s2.empty())
	{
		current = s2.top();
		cout << current->data << " ";
		s2.pop();
	}
}
void node2::preorder(node1 *root)
{
	stack<node1 *> s;
	node1 *current = root;
	s.push(current);
	while (!s.empty())
	{
		current = s.top();
		s.pop();
		cout << current->data << " ";
		if (current->right)
			s.push(current->right);
		if (current->left)
			s.push(current->left);
	}
}
void node2::inorder(node1 *root)
{
	node1 *current = root;
	stack<node1 *> s;
	while (current || !s.empty())
	{
		while (current)
		{
			s.push(current);
			current = current->left;
		}
		current = s.top();
		cout << current->data << " ";
		s.pop();
		current = current->right;
	}
}
void node2::count()
{
	int x, y;
	x = countNode(root);
	cout << endl
		 << "Total Nodes: " << x;
	cout << endl
		 << "Total edges: " << x - 1;
	y = countLeaf(root);
	cout << endl
		 << "Total Leaf: " << y;
}
void node2::traversal()
{
	cout << endl
		 << "Inorder" << endl;
	inorder(root);
	cout << endl
		 << "Preorder" << endl;
	preorder(root);
	cout << endl
		 << "Postorder" << endl;
	postorder(root);
	cout << endl
		 << "Level Order" << endl;
	level(root);
}
int main()
{
	node2 n2;
	n2.traversal();
	n2.count();
	return 0;
}
