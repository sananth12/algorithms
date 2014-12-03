// BST with insert, remove and post order functions
#include <iostream>
using namespace std;
class binarySearchTree;
class treeNode{

	friend class binarySearchTree;
	private:
		int data;
		treeNode * left;
		treeNode * right;

	public:
		treeNode(){
			left=right=NULL;

		}
		treeNode(int key){
			data=key;
			left=right=NULL	;

		}
		int getData(){ return data;}
		void setData(int key){data=key;}
};

class binarySearchTree{
	private:
		treeNode * root;
	public:
		binarySearchTree(){root=NULL;}

void recursiveInsert(treeNode *&tree,int key)
 {
   treeNode *t=new treeNode(key);
   if(tree==NULL)
   {
    t->setData(key);
   }
   else if(key<tree->data)
   {
     recursiveInsert(tree->left,key);
   }
   else if(key>tree->data)
   {
     recursiveInsert(tree->right,key);
   }
   return;
 }
 void insert(int num) {
  if(root == NULL)
   root = new treeNode(num);
  else
   insertSorted(num, root);
 }

 void insertSorted(int num, treeNode* head) {
  if(num < head->getData()) {
   if(head->left == NULL)
    head->left = new treeNode(num);
   else
    insertSorted(num, head->left);
  }
  else {
   if(head->right == NULL)
    head->right = new treeNode(num);
   else
    insertSorted(num, head->right);
 }
 }
 void removeRoot(treeNode *&tree1)
 {
   treeNode *temp;
   temp=tree1;
   if(tree1->left==NULL)
   {
     tree1=tree1->right;
     delete temp;
   }
   else if(tree1->right==NULL)
   {
     tree1=tree1->left;
     delete temp;
   }
   else
   {
     temp=tree1->left;
     while(temp->right!=NULL)
     temp=temp->right;
     tree1->data=temp->data;
     removeKey(tree1->left,temp->data);
   }
 }
 void removeKey(treeNode *&tree,int key)
 {
   if(tree==NULL)
    {
      return;
    }
    if(key<tree->data)
     {
      removeKey(tree->left,key);
    }
    else if(key>tree->data)
    {
       removeKey(tree->right,key);
    }
    else
    removeRoot(tree);
 }
 void remove(int key)
 {

    if(root==NULL)
    {
      return;
    }
    if(key<root->data)
    {
      removeKey(root->left,key);
    }
    else if(key>root->data)
    {
       removeKey(root->right,key);
    }
    else
    removeRoot(root);
 }
 void newPrint(treeNode *&t,int flag)
 {

   if(t->left != NULL)
     { newPrint(t->left,1);}
     if(t->right != NULL)
        { newPrint(t->right,1);}
   (flag == 0) ? cout <<t->getData() : cout <<t->getData() <<" ";
 }
 void print()
 {
   if(root==NULL)
   {
     cout<<"NULL";
   }
   else
   {
     newPrint(root,0);
 }
 }
 };

int main(){

	binarySearchTree bst;
	int N,val,k;
	char op;
	cin>>N;
	while(N--){
		cin>>val;
		bst.insert(val);
	}

	cin>>k;

	while(k--){
		cin>>op;
		cin>>val;

		if(op == 'i'){
			bst.insert(val);
		}
		else if (op=='d'){
			bst.remove(val);
		}

	}
	bst.print();
	return 0;
}
