// Matrix class to add,subtract,multiply
#include <iostream>
 #include <cstring>
 using namespace std;
 struct matrixType{
   int matDimension;
   int matValues[10][10];
 };
 class MatrixADT{
   private:
     matrixType resultMatrix;
   public:

     void intializeResultMatrix(int);
 matrixType add(matrixType, matrixType);
     matrixType subtract(matrixType,matrixType);
     matrixType multiply(matrixType,matrixType);
     void printResult();
 };

 matrixType MatrixADT::add(matrixType M1, matrixType M2){

 int i,j,temp=0;
 matrixType mat;
 temp=resultMatrix.matDimension;
   for(i=0;i<temp;i++){
     for(j=0;j<temp;j++)
     {
      resultMatrix.matValues[i][j]=M1.matValues[i][j]+M2.matValues[i][j];
      mat.matValues[i][j]=resultMatrix.matValues[i][j];
           }
     }
     return mat;
 }
 matrixType MatrixADT::subtract(matrixType M1, matrixType M2){

 int i,j,temp=0;
 matrixType mat;
 temp=resultMatrix.matDimension;
   for(i=0;i<temp;i++){
     for(j=0;j<temp;j++)
     {
        resultMatrix.matValues[i][j]=M1.matValues[i][j]-M2.matValues[i][j];
        mat.matValues[i][j]=resultMatrix.matValues[i][j];
     }
     }
     return mat;
 }
 matrixType MatrixADT::multiply(matrixType M1, matrixType M2){

 int i,j,temp=0,k;
 matrixType mat;
 temp=resultMatrix.matDimension;
 for(i=0;i<temp;i++){
 for(j=0;j<temp;j++)
 {
 mat.matValues[i][j]=0;
 for(k=0;k<temp;k++)
 {
 resultMatrix.matValues[i][j]=mat.matValues[i][j]+(M1.matValues[i][k]*M2.matValues[k][j]);
 mat.matValues[i][j]=resultMatrix.matValues[i][j];
 }
 }
 }
   return mat;
 }
 void MatrixADT::intializeResultMatrix(int dim){
  resultMatrix.matDimension=dim;
   for(int i=0;i<dim;i++){
     for(int j=0;j<dim;j++)
     {
       resultMatrix.matValues[i][j]=0;
     }
   }
 }
 int main(){
   MatrixADT maX;
   matrixType M1, M2;
   char op;
   cout<<"Enter dimention and operation(+,*,-):\n";
   int dim,i,j;
    cin>>dim>>op;

   maX.intializeResultMatrix(dim);
    cout<<"Matrix A:\n";
   for(i=0;i<dim;i++){
   for(j=0;j<dim;j++)
   {
     cin>>M1.matValues[i][j];
   }
   }
    cout<<"Matrix B:\n";
   for(i=0;i<dim;i++){

   for(j=0;j<dim;j++)
   {
     cin>>M2.matValues[i][j];
   }
   }
    cout<<"Result\n";
   switch(op)
   {
     case '+': maX.add(M1,M2);
       break;
     case '-': maX.subtract(M1,M2);
       break;
     case '*': maX.multiply(M1,M2);
       break;
   }

 maX.printResult();
 }
 void MatrixADT::printResult(){
   int i,j;
   for (i=0;i<resultMatrix.matDimension;i++){
     for (j=0; j<resultMatrix.matDimension-1;j++){
       cout<<resultMatrix.matValues[i][j]<<" ";
     }
     cout <<resultMatrix.matValues[i][j]<<"\n";
   }
   cout <<"Done";
 }

