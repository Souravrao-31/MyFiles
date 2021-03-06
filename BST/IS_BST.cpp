/*
check whether tree is bst or not

*/
#include <iostream>
#include <queue>
#include<climits>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *insert(node *root, int data)
{
    //old root node and return new root node old = null
    //updating the node

    //base case
    if (root == NULL)
    {
        return new node(data);
    }
    //Rec case - Insert in the subtree and update Pointers
    if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}
node *buildtree()
{
    //Read a list of numbers till -1 and also this number will be inserted to BST
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = insert(root, d);
        cin >> d;
    }
    return root;
}
void BFS_2(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *f = q.front();

        if (f == NULL)
        {

            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    //Left root right
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
bool is_BST(node*root,int minV = INT_MIN,int maxV =INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data >= minV && root->data <maxV && is_BST(root->left,minV,root->data) && is_BST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}
int main()
{
    //5 3 7 1 6 8 -1
    node *root = buildtree();
    
    Inorder(root); //IMP- Inorder print in BSt is always sorted
   cout<<endl;
    if(is_BST(root)){
       cout<<"Yes";
    }
    else{
        cout<<"No";
    }



    return 0;
}