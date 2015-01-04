#include<bits/stdc++.h>
#define ll long long
using namespace std;

class node{

    int data;
    node* left;
    node* right;
    public:

    node()
    { data=0; left=NULL; right=NULL; };

    void addData(int aKey)
     { data = aKey; };

    void setL(node* aLeft)
    { left = aLeft; };

    void setR(node* aRight)
    { right = aRight; };

    int Data()
    { return data; };

    node* Left() { return left; };
    node* Right() { return right; };
};

class tree{
    node* root;
    public:

    tree()
    {
        root=NULL;
    };

    void addNode(int x)
    {
        if(root==NULL)
        {
            node* n = new node();
            n->addData(x);
            root=n;
        }
        else
        {
            addNode(x,root);
        }
    }
    int addNode(int x,node* leaf)
    {

      bool insert=false;
      while(!insert)
          {
             if(leaf->Left()!=NULL && leaf)
          }
         if(leaf->Left()==NULL)
                    {
                        node* n = new node();
                        n->addData(x);
                        leaf->setL(n);
                        insert=true;
                    }
                else if(leaf->Right()==NULL)
                    {
                        node* n = new node();
                        n->addData(x);
                        leaf->setL(n);
                        insert=true;
                    }
                else
                    {
                        addNode(x,leaf->Left());
                    }
    }

};
int main()
{
   int c;
   node *root;




return 0;
}
