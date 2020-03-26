/*********************************************
	Matrix using class
	Author - Partha Pratim Dey
	Date - 26/03/2020
***************************************************/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Matrix{
	int **mat;
	int row,col;
	public:
		Matrix(int r,int c){
			row = r;
			col = c;
			// int* arr = (int*)malloc(n*sizeof(int));
			mat = (int**)malloc(row*sizeof(int*));
			for(int i=0;i<row;i++){
				// mat[i] = (int*)malloc(sizeof(int*));
				mat[i] = (int*)malloc(col*sizeof(int));
				//for(int j=0;j<col;j++) {
           			// mat[i][j]=*(int*)malloc(sizeof(int));
       			//}
			}
		}
	
	 void addElement() {
	      cout << "Enter the elements: ";
	      for(int i=0;i<row;i++) {
	          for(int j=0;j<col;j++) {
	              cin >> mat[i][j];
	          }
	      }
	  }
	void show(ostream& os = cout) {    
	      os << "The matrix : " << endl;
	      for(int i=0;i<row;i++) {
	          for(int j=0;j<col;j++) {
	              os << mat[i][j] << " ";
	          }
	          os << endl;
	      }
	  }
	friend ostream& operator <<(ostream& os, Matrix& m) {
        m.show(os);
        return os;
    }
};


int main(){
	int r,c;
	cout<<"Enter row and column:"<<endl;
	cin>>r>>c;
	Matrix mat(r,c);
	mat.addElement();
	mat.show();
	cout<<mat;
	return 0;
}
