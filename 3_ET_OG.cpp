#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
  char data;
  Tree *left, *right;

  Tree(char n)
  {
    data = n;
    left = NULL;
    right = NULL;
  }
};

Tree *createTree(string postfix, Tree *root){
  stack<Tree *> s;
  int i = 0;
  while (postfix[i] != '\0')
  {
    if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z') || (postfix[i] >= '0' && postfix[i] <= '9'))
    {
      Tree *new_node = new Tree(postfix[i]);
      s.push(new_node);
    }
    else
    {
      Tree *new_node = new Tree(postfix[i]);
      new_node->right = s.top();
      s.pop();
      new_node->left = s.top();
      s.pop();
      s.push(new_node);
    }
    i++;
  }
  return s.top();
}

void inorder_traversal(Tree *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder_traversal(root->left);
  cout << root->data << " ";
  inorder_traversal(root->right);
}
void preorder_traversal(Tree *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}
void postorder_traversal(Tree *root)
{
  if (root == NULL)
  {
    return;
  }
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  cout << root->data << " ";
}

int prec(char c)
{
  if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}
// A+B*C+D      INFIX
// ABC*+D+     POSTFIX
void InToPostfix(string &infix, string &postfix, stack<char> &st){    //take value by reference
  for (int i = 0; i < infix.length(); i++){   //run over the length of the string
    if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))   //if alphabet or number
      postfix += infix[i];  //add directly to postfix string
    else if (infix[i] == ')'){
      while (st.top() != '('){
        postfix += st.top();
        st.pop();
      }
      st.pop(); // Pop '('
    }
    else{
      while (!st.empty() && prec(infix[i]) < prec(st.top()) || !st.empty() && prec(infix[i]) == prec(st.top())){
        postfix += st.top();
        st.pop();
      }
      st.push(infix[i]);
  } }
  while (!st.empty()){
    postfix += st.top();
    st.pop();
} }

int main()
{
  string infix = "A+B*C+D";
  string postfix;
  stack<char> st;
  InToPostfix(infix, postfix, st);
  cout << "postfix= " + postfix + "\n";
  Tree *root;
  Tree *Root_Top = createTree(postfix, root);
  cout << "inorder_traversal= ";
  inorder_traversal(Root_Top);
  cout << "\n";
  cout << "preorder_traversal= ";
  preorder_traversal(Root_Top);
  cout << "\n";
  cout << "postorder_traversal= ";
  postorder_traversal(Root_Top);
  return 0;
}
// A+B*C+D INFIX
// ABC*+D+
