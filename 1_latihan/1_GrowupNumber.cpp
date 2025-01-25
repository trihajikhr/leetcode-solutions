#include<iostream>

// fungsi growDownNumber
int growDownNumber(int a){
    int arr[a+1];
    int x=a;
    for(int i=a+1;i-1>-1;i--){
         arr[x]=i;
    }
    
    for(int i=0;i<a+1;i++){
        std::cout << arr[i] << ", ";
    }
    std::cout<<std::endl;
}


int main(){
    growDownNumber(5);
    growDownNumber(3);
    growDownNumber(0);
    growDownNumber(10);
}