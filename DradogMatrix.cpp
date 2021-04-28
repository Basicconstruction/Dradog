#include <iostream>
#include <string>
#include <cmath>
#include "DradogMatrix.h"
using namespace std;
DradogMatrix::DradogMatrix(){
    
}
int DradogMatrix::ladderMatrix(double *matrix,const int m,const int n){
    double matrixs[m][n];
    this->matrix = matrix;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrixs[i][j] = matrix[i*n+j];
        }
    }
    for(int i=0;i<m;i++){
        
    }
}