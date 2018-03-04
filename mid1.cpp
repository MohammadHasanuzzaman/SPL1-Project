#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int noOfEqn,noOfVars,totalCols,totalRows;
int matrix[MAX][MAX];
int prow,pcol;

void takeInput(){
    cout<<"Numbers of variables:"<<endl;
    cin>>noOfVars;

    cout<<"Numbers of Equations:"<<endl;
    cin>>noOfEqn;

    totalCols=noOfVars+noOfEqn+2;
    totalRows=noOfEqn+1;

    for(int i=0;i<totalRows;i++){
        if(i==0)
         matrix[i][0]=1;
        else
        matrix[i][0]=0;

        for(int j=0;j<noOfVars+1;j++){
            if (j==noOfVars)
            cin>>matrix[i][totalCols-1];
            else
            cin>>matrix[i][j+1];
        }


        for(int j=0;j<noOfEqn;j++){
            if(i==j)
            matrix[i+1][j+noOfVars+1]=1;
            else
            matrix[i+1][j+noOfVars+1]=0;
        }
    }

}


bool findPivote (){



    double mini=1000000;
    for(int j=0;j<totalCols;j++){
        double temp=matrix[0][j];
        if (temp<mini){
            mini=temp;
            pcol=j;
        }
    }
    if(mini>=0)
    return false;



    mini=9999999;


    for(int i=1;i<noOfEqn;i++){
        double temp=matrix[i][totalCols-1]/matrix[i][pcol];

        if(temp>=0 && temp<mini){
            mini=temp;
            prow=i;
        }
    }



    return true;
}

int main(){
    takeInput();
    for(int i=0;i<totalRows;i++){
        for(int j=0;j<totalCols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    findPivote();
    cout<<prow<<" "<<pcol<<endl;

}




