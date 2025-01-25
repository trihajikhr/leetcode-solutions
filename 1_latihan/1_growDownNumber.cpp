#include<iostream>

// fungsi growDownNumber
int growDownNumber(int a){
    if(a==0){
        return 0;
    }
    int arr[a+1];
    int x=a;
    for(int i=0;i<=a;i++){
         arr[i]=x;
         x--;
    }
    
    for(int i=0;i<=a;i++){
        if(i==a){
            std::cout << arr[i];
        } else {    
            std::cout << arr[i] << ", ";
        }
    }
    std::cout<<std::endl;
}


int main(){
    growDownNumber(5);
    growDownNumber(3);
    growDownNumber(0);
    growDownNumber(10);
}