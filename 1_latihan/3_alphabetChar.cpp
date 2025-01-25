#include <iostream>
using namespace std;

int main() {
    string kata;
    cout << "Masukan kata: ";
    cin >> kata;

    // membuat kata yang dimasukan, hurufnya diurutkan berdasarkan urutan alphabet
    for(int i=0;i<kata.length();i++){
        for(int j=i+1;j<kata.length();j++){
            if(kata[i]>kata[j]){
                char temp = kata[i];  // banyak yang bertanya kenapa sering menggunakan penamaan temp
                kata[i] = kata[j];      // temp itu singkatan dari temporary, yang artinya sementara
                kata[j] = temp;         // biasa digunakan untuk pertukaran variabel sementara
            }
        }
    }

    cout << "Kata yang diurutkan: " << kata << endl;
    return 0;
}