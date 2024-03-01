// build tree from preorder and inorder
#include <iostream>
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
{ // constructor
    data = value;
    left = NULL;
    right = NULL;
}
class node2
{
    node1 *root;
    int *inorder = new int();
    int *preorder = new int();
    int n;

public:
    node2();
    int *insertInorder(int n);
    int *insertPreorder(int n);
    void showdata(int n, int x[]);
    node1 *BuildTree(int preorder[], int inorder[], int start, int end);
    void inorderPrint(node1 *root);
};
node2::node2()
{ // constructor
    cout << "Element No: ";
    cin >> n;
    preorder = insertPreorder(n);
    inorder = insertInorder(n);
    cout << endl
         << "Preorder: ";
    showdata(n, preorder);
    cout << endl
         << "Inorder: ";
    showdata(n, inorder);

    node1 *root = BuildTree(preorder, inorder, 0, n-1);
    cout << endl
         << endl
         << "After creating Tree" << endl;
    inorderPrint(root);
}
void node2::inorderPrint(node1 *root)
{
    if (root)
    {
        inorderPrint(root->left);
        cout << root->data << " ";
        inorderPrint(root->right);
    }
    return;
}
int search(int inorder[], int start, int end, int current)
{
    for (int i = 0; i <= end; i++)
    {
        if (inorder[i] == current)
            return i;
    }
    return -1;
}
node1 *node2::BuildTree(int preorder[], int inorder[], int start, int end)
{
    static int index = 0;
    if (start > end)
        return NULL;

    int current = preorder[index];
    index++;
    node1 *newnode = new node1(current);

    if (start == end)
    {
        return newnode;
    }
    int pos = search(inorder, start, end, current);
    newnode->left = BuildTree(preorder, inorder, start, pos - 1);
    newnode->right = BuildTree(preorder, inorder, pos + 1, end);
    return newnode;
}
void node2::showdata(int n, int x[])
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
}
int *node2::insertPreorder(int n)
{
    cout << "Preorder: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    return preorder;
}
int *node2::insertInorder(int n)
{
    cout << "Inorder: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    return inorder;
}
int main()
{
    node2 n2;
    return 0;
}
