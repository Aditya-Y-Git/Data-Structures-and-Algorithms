#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
};

StackNode *newNode(int data)
{
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

bool isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode *StackNode = newNode(data);
    StackNode->next = *root;
    *root = StackNode;
    cout << data << " pushed to stack" << endl;
}

void pop(StackNode **root)
{
    if (isEmpty(*root))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    StackNode *temp = *root;
    *root = (*root)->next;
    cout << temp->data << " popped out" << endl;
    free(temp);
}

int peek(StackNode *root)
{
    if (isEmpty(root))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return root->data;
}

int main()
{
    StackNode *root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    pop(&root);
    cout << peek(root) << endl;
    return 0;
}