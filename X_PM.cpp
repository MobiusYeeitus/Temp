#include<iostream>
#include<stack>
#include<bits/stdc++.h>
#include<stdio.h>
#include<string>

using namespace std;
#define n 99

class Matrix{
    public:
        int vertices=7;
        int marked_edges=0;
        int result=0;
        int prims(int matrix[7][7],int start);
};

int Matrix::prims(int matrix[7][7],int start){
    int ptr_i,ptr_j,min;
    int mark[7]={0,0,0,0,0,0,0};
    mark[start]=1;
    while(marked_edges!=vertices-1){
        min=n;
        for(int i=0;i<vertices;i++){
            if(mark[i]==0)
                continue;
            for(int j=0;j<vertices;j++){
                if(matrix[i][j]>0 && matrix[i][j]<min && mark[j]!=1){
                    min=matrix[i][j];
                    ptr_i=i;
                    ptr_j=j;
        }   }   }
        mark[ptr_j]=1;
        result=result+min;
        cout<<ptr_i+1<<"<--->"<<ptr_j+1<<"   "<<min<<"\n";
        marked_edges++;
    }
    return result;
}

int main(){
	int start;
	Matrix M;
	int matrix[7][7]={
	// j 0  1  2  3	 4  5  6
		{0, 2, 2, 0, 0, 0, 0}, //0
		{2, 0, 1, 2, 4, 0, 0}, //1
		{2, 1, 0, 3, 0, 4, 0}, //2
		{0, 2, 3, 0, 2, 3, 0}, //3
		{0, 4, 0, 2, 0, 2, 3}, //4
		{0, 0, 4, 3, 2, 0, 3}, //5
		{0, 0, 0, 0, 3, 3, 0}};//6
    cout<<"Enter starting node (0 to 6): ";
	cin>>start;
	M.prims(matrix,start);
	cout<<"Sum="<<M.result;
	return 0;
}