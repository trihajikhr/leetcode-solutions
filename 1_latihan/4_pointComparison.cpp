//firzal

#include <iostream>
#include <cmath>

using namespace std;

// Struktur untuk mendefinisikan titik dengan koordinat x, y dan nama
struct titik {
    float x;    // Koordinat x dari titik
    float y;    // Koordinat y dari titik
    char nama;  // Nama untuk titik, yang diwakili dengan karakter
    
    // Fungsi untuk menampilkan titik dalam format "Nama(x, y)"
    void display () {
        cout << nama << "(" << x << ", " << y << ")";
    };
};

// Fungsi untuk menghitung jarak antara dua titik menggunakan rumus jarak Euclidean
float getJarak (titik &p1, titik &p2) {
    return sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) );
};

// Fungsi untuk mengkonversi angka ke huruf (0 -> 'A', 1 -> 'B', dst)
char huruf (int i) {
    return static_cast<char>(65 + i);  // 65 adalah nilai ASCII untuk huruf 'A'
};

// Fungsi untuk membandingkan jarak antara dua titik, menampilkan hasilnya dan mengembalikan jarak tersebut
float banding (titik &p1, titik &p2) {
    float _jarak = getJarak(p1,p2);
            
    // Menampilkan jarak antara p1 dan p2
    cout << "jarak titik ";  p1.display() ;
    cout << " -> "; p2.display() ;
    cout << " : " << _jarak << endl;
    
    return _jarak;
};

// Fungsi untuk menginputkan koordinat titik dari user
void inputTitik (titik *p, int urutan) {
    p->nama = huruf(urutan);  // Memberikan nama titik sesuai urutan (misalnya A, B, C)
        
    cout << "titik " << p->nama << endl;
    cout << "x: "; cin >> p->x;  // Input nilai x
    cout << "y: "; cin >> p->y;  // Input nilai y
}


int main () {
    
    // Loop untuk mengulang program jika diinginkan
    do {
        system("cls");  // Membersihkan layar (platform Windows)
        
        int jumlah;
    
        cout << "masukkan jumlah titik: ";  // Menanyakan jumlah titik
        cin >> jumlah;
        
        // Validasi agar jumlah titik lebih dari 1
        if (jumlah <= 1) {
            cout << "Jumlah titik harus lebih dari 1\n";
            system("pause");  // Menunggu input dari user untuk melanjutkan
            continue;  // Kembali ke awal loop
        }
        
        // Alokasi dinamis untuk array titik
        titik* p = new titik[jumlah];
        
        // Loop untuk input titik sesuai jumlah yang diberikan
        for (int i = 0; i < jumlah; i++) {    
            system("cls");
            inputTitik(p+i, i);  // Menginput titik ke dalam array
        };
        
        system("cls");
        
        // Menampilkan semua titik yang sudah dimasukkan
        for (int i = 0; i < jumlah; i++) {
            cout << "titik " << huruf(i) << ": "; p[i].display();
            cout << endl;
        };
        
        cout << endl << "perbandingan jarak:" << endl;
        
        // Inisialisasi titik pertama dan kedua untuk pencarian jarak terpendek
        int t1 = 0;
        int t2 = t1 + 1;
        float jarak = getJarak(p[t1], p[t1 + 1]);
        
        // Loop untuk mencari jarak terpendek di antara semua pasangan titik
        for (int i = t1; i < jumlah; i++) {
            for (int j = i + 1; j < jumlah; j++) {
                
                // Membandingkan jarak antara titik i dan j
                float _jarak = banding(p[i],p[j]);
                
                // Memperbarui jarak terpendek dan pasangan titik jika ditemukan jarak yang lebih kecil
                if (_jarak < jarak) {
                    t1 = i;
                    t2 = j;
                    jarak = _jarak;
                }
            }
        };
        
        cout << endl;
        
        // Menampilkan jarak terpendek
        cout << "Jarak terendah:" << endl;
        banding(p[t1],p[t2]);
    
        // Menghapus array dinamis untuk menghindari memory leak
        delete[] p;
        
        // Menanyakan apakah user ingin mengulangi program
        char konfirm;
        cout << endl << "apakah anda ingin mengulangi? (Y/n) ";
        cin >> konfirm;
        
        // Jika input selain 'Y' atau 'y', program akan berhenti
        if (konfirm != 'Y' && konfirm != 'y') {
            cout << "Terima kasih";  // Ucapan terima kasih saat keluar
            return 0;
        };
        
        cin.ignore();  // Mengabaikan karakter yang tersisa dalam buffer input
    } while (true);  // Ulangi terus jika user memilih untuk mengulang

    return 0;  // Program selesai
}

