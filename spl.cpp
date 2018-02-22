#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int col=0;
int row=1;
int total;
int numOfVars;
int numOfEqus;
int vars[MAX];


void take_input(double equations[][MAX+1]){

     total=numOfVars+numOfEqus+2;
     for(int i=0; i<numOfEqus+1; i++){
        if(i==0){
            cout << "This is the object function: " << endl;
        }

        for(int j=1; j<=numOfVars+1; j++){ 
            if(j==numOfVars+1){ 
                if(i==0){
                    equations[i][total-1]=0;
                }
                else {
                    printf("%c%d = ",96+j,i);
                    cin >> equations[i][total-1];
                }
            }
            else {
                printf("%c%d = ",96+j,i);
                cin >> equations[i][j];
            }

        }
        if(i==0){ 
            equations[i][0]=1;
        }
        else{
            equations[i][0]=0;
        }
        for(int k=1;k<=numOfEqus;k++){
            if(i==0){ 
                equations[i][numOfVars+k]=0;
            }
            else{ 
                if(k==i){
                    equations[i][numOfVars+k]=1;
                }
                else{
                    equations[i][numOfVars+k]=0;
                }
            }
        }
    }
