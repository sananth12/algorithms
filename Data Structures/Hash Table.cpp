#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

typedef struct CellType* Position;
typedef int ElementType;

struct CellType{
    ElementType value;
    Position next;
};
class List{

    private:
        Position listHead;
        int count;

    public:

        void setCount(int num){
            count = num;
        }


        void makeEmptyList(){
            listHead = new CellType;
            listHead->next = NULL;
        }


        int insertList(ElementType data, Position p){
            Position temp;
            temp = p->next;
            p->next = new CellType;
            p->next->next = temp;
            p->next->value = data;
            return ++count;
        }


        Position end(){
            Position p;
            p = listHead;
            while (p->next != NULL){
                p = p->next;
            }
            return p;
        }

        int getCount(){
            return count;
        }
};
 typedef struct CellType* Position;
 typedef int ElementType;

 class HashTable
 {
   private:
     List bucket[10];
     int bucketIndex;
     int numElemBucket;
     Position posInsert;
     string collision;
     bool reportCol;
           bool reportCol2;
   public:
     HashTable()
           {
       int i;
       for (i=0;i<10;i++)
                {
         bucket[i].setCount(0);
       }
       collision = "";
       reportCol = false;
       reportCol2=false;

       numElemBucket=0;
     }
     int insert(int data)
           {
        bucketIndex = data%10;
        if(bucket[bucketIndex].getCount()==0)
                 {
                      bucket[bucketIndex].makeEmptyList();
                 }
                 else
                 {
                      reportCol=true;
                      reportCol2=true;
                 }
        posInsert = bucket[bucketIndex].end();
        bucket[bucketIndex].insertList(data,posInsert);
        numElemBucket++;
        if(reportCol2==true)
        {
                          listCollision(bucket[bucketIndex].getCount());
                     reportCol2=false;
        }
        return numElemBucket;
     }
     void listCollision(int pos)
           {

                   if(collision.empty())
              {
              std::ostringstream oss;
                   oss << "(" << numElemBucket << "," << bucketIndex << "," << pos << ")"<<" " ;
 collision += oss.str();
              }
              else
              {
                                 std::ostringstream oss;
                   oss << "(" << numElemBucket << "," << bucketIndex << "," << pos << ")"<<" " ;
                   collision += oss.str();
              }
     }
     void printCollision();
 };
 int main()
 {
   HashTable ht;
   int i, data;
   for (i=0;i<10;i++)
   {
     cin>>data;
     ht.insert(data);
   }

   ht.printCollision();
 }
 void HashTable::printCollision(){
   if (reportCol == false)
     cout <<"NO";
   else
     cout<<collision;
 }

