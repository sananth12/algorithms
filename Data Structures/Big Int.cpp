// Big Int class to add 2 numbers of upto 4000 digits.
#include <iostream>
#include <cstring>
using namespace std;

class ListNode{
	private:
		int data;
		ListNode * next;
	public:
		ListNode(){}
		ListNode(int num){
			data=num;
			next = NULL;
		}
		int getData();
		void setData(int);
		void setNext(ListNode *);
		ListNode* getNext();
};

int ListNode::getData(){
		return data;
}
void ListNode::setData(int x){
		data = x;
}
ListNode * ListNode::getNext(){
		return next;
}
void ListNode::setNext(ListNode * P){
		next = P;
}


class List{
	private:
		ListNode * Head;
	public:

		List(){
			Head=NULL;
		}
		~List(){}

		ListNode * getHead();
		void setHead(ListNode *);
		ListNode * last();
		void append(int);
		void prepend(int);
		void popBack();
		void print();
		void copy(List);
		void printReverse();
		ListNode * prevNode(ListNode* P);
		void popFront();

};

ListNode * List::getHead(){
		return Head;
}

ListNode * List::last(){
		ListNode * temp=Head;
		if(Head==NULL) return NULL;
		while(temp->getNext()!=NULL){
			temp=temp->getNext();
		}
		return temp;
}
void List::setHead(ListNode * P){
		Head = P;
}
void List::append(int num){
		ListNode * new_node = new ListNode(num);
		ListNode * temp=Head;
		if(temp==NULL){
			Head = new_node;
			return;
		}
		while(temp->getNext()!=NULL) temp=temp->getNext();
		temp->setNext(new_node);
}
void List::prepend(int num){
		ListNode * new_node = new ListNode(num);

		new_node->setNext(Head);
		Head = new_node;
}

void List::popBack(){
		ListNode * temp=Head,*prev=NULL;

		if(Head==NULL){cout<<"List is Empty\n";}

		if(Head->getNext()==NULL){
			delete Head;
			Head=NULL;
			return;
		}
		while(temp->getNext()!=NULL){
			prev = temp;
			temp=temp->getNext();
		}
		delete temp;
		prev->setNext(NULL);
}
void List::print(){
		ListNode * temp=Head;
		while(temp!=NULL){
			cout<<temp->getData();
			temp=temp->getNext();
		}
}

void List::copy(List L){
		Head = NULL;
		ListNode * temp = L.Head;
		while(temp!=NULL){
			this->append(temp->getData());
			temp=temp->getNext();
		}
}

void List::printReverse(){
		ListNode * curr=Head;
		ListNode * prev_last=NULL;

		while(Head!=NULL && prev_last!=Head){
			curr = Head;
			while(curr->getNext()!=prev_last){
				curr = curr->getNext();
			}
			cout<<curr->getData();
			prev_last = curr;
		}
}


class BigInt{
   private:
	    List L;
   public:
	   BigInt(){}
	   ~BigInt(){}

	   void append(int num);
	   void prepend(int num);
	   BigInt add(BigInt A);
	   void print();

	   void removeZeroes();
	   void copy(BigInt B);

};


 int l1,l2,count=0;
 void populate(BigInt &A, char * str){

   int i=0,k;
   while(str[i]!=0)
   {
    k=(int)str[i]-48;
    A.prepend(k);
    i++;
   }
     if(count==0)
     {l1=i;
     count++;
     }
     else
     l2=i;
 }
 void BigInt::append(int num){

   L.append(num);
 }
 void BigInt::prepend(int num){

   L.prepend(num);
 }
 BigInt BigInt::add(BigInt A){

    int t;
    t=l1-l2;
    if(t>0)
    {
    while(t!=0)
    {
      A.append(0);
      t--;
    }
    }
    else if(t<0)
    {
    while(t!=0)
    {
     append(0);
     t++;
    }
    }
    else
    {
    }
    ListNode * temp1=L.getHead();
    ListNode * temp2=A.L.getHead();
    int x,carry=0;
    while(temp1!=NULL)
    {
     x=temp1->getData()+temp2->getData()+carry;
     carry=0;
     if(x<10)
     {
     temp2->setData(x);
     }
     else
     {
      x=x%10;
      temp2->setData(x);
      carry=1;
     }
     temp1=temp1->getNext();
     temp2=temp2->getNext();
    }
    if(carry==1)
    {
     A.L.append(1);
    }
    return A;
 }
 void BigInt::removeZeroes(){

     ListNode * temp=L.getHead();

     while(temp->getNext()!=0) temp=temp->getNext();
     if(temp->getData()==0)
     {
     L.popBack();
     }
 }
 void BigInt::print(){
    ListNode * temp=L.getHead();
    removeZeroes();
    removeZeroes();
     while(temp->getNext()!=NULL) temp=temp->getNext();
     L.printReverse();
 }

 int main(){
    char str[4000];
    BigInt A,B;
    cin>>str;
     populate(A,str);
    cin>>str;
    populate(B,str);
    cout<<"\nSum is:";
    (A.add(B)).print();
    return 0;
 }
