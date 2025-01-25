#include <iostream>
using namespace std;

bool isMatchIdenty(string input) {
    // program harus menentukan apakah inputan menggunakna karakter yang sama atau tidak
    // contoh inputan yang benar: "aaaaaa", "bbbbbb", "cccccc"
    // contoh inputan yang salah: "aaaaab", "bbbbbn", "ccmccc"
    for(int i=0;i<input.length();i++){
        if(input[0]!=input[i]){ 
            return false;  
        } 
    }
    return true;
}

// sebelumnya menggunakan sizeof(input), tapi ternyata lupa bahwa fungsi itu 
// mengembalikan ukuran dari tipe data, bukan panjang dari string
// solusinya gunakan [variabel].length() atau [variabel].size()

int main() {
    string input;
    std::cout << "Masukan inputan: ";
    std::cin >> input;

    if(isMatchIdenty(input)){
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}