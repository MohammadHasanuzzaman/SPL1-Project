#include<iostream>
#define N 100
using namespace std;

double mat[N][N+1];

int numOfVar;

void input(){
    cin>>numOfVar;

    for(int i=0;i<numOfVar;i++){
        for(int j=0;j<numOfVar+1;j++){
            cin>>mat[i][j];
        }
    }
}
void printMatrix(){

    for(int i=0;i<numOfVar;i++){
        for(int j=0;j<numOfVar+1;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void multiplyRow(double x,int r){

    for(int j=0;j<numOfVar+1;j++){
        mat[r][j]=mat[r][j]*x;
    }
}

void addRows(int r1,int r2){

    for(int j=0;j<numOfVar+1;j++){
        mat[r1][j]=mat[r1][j]+mat[r2][j];
    }
}

void exchangeRows(int r1,int r2){

    for(int j=0;j<numOfVar+1;j++){
        swap(mat[r1][j],mat[r2][j]);
    }

}

void elimination(){

     for(int i=0;i<numOfVar;i++){
        double pivot= mat[i][i];

        if(pivot==0){

            for(int k=i+1;k<numOfVar;k++){
                if(mat[k][i]!=0){
                    exchangeRows(i,k);
                    pivot = mat[i][i];
                    break;
                }
            }
        }
        if(pivot==0){
            cout<<"Invalid matrix"<<endl;
            return ;
        }
        for(int k=i+1;k<numOfVar;k++){
            //cout<<mat[k][i]<<endl;
            if(mat[k][i]==0) continue;
            double x=-pivot/mat[k][i];
            multiplyRow(x,k);
            addRows(k,i);
        }
     }
}

void backSubstitute(){

     for(int i=numOfVar-1;i>=0;i--){
        multiplyRow(1/mat[i][i],i);

        for(int k=i-1;k>=0;k--){
            if(mat[k][i]==0)
            continue;
            double x=-1/mat[k][i];
            multiplyRow(x,k);
            addRows(k,i);
        }
        printMatrix();
     }
}

int main(){

    input();

    printMatrix();

    elimination();

    printMatrix();

    backSubstitute();

    printMatrix();

    return 0;



}














