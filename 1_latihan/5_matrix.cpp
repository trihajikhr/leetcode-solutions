//firzal
#include <iostream>
#include <string>

using namespace std;

void clear();

struct Matrix {
	
	int x;
	int y;
	int size;
	
	int _pointer;
	int _x;
	int _y;
	
	bool fail;
	
	float** data;
	
	void reset () {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				data[i][j] = 0;
			};
		};
	};
	
	Matrix (int row, int column) {
		x = row;
		y = column;
		
		size = x * y;
		
		_pointer = 0;
		_x = 0;
		_y = 0;
		
		data = new float*[x];
		
		for (int i = 0; i < x; i++) {
			data[i] = new float[y]();
		};
		
		reset();
		
	};
	
	~Matrix () {
		for (int i = 0; i < x; i++) {
			delete[] data[i];
		};
		delete[] data;
	};
	
	float* operator[](int x) {
		return data[x];
	};
	

	
	void output () {
		for (int i = 0; i < x; i++) {
			cout << "| ";
			for (int j = 0; j < y; j++) {
				cout << data[i][j] << " ";
			};
			cout << "|" << endl;
		};
	};
	
	bool end () {
		return _pointer >= size;
	};
	
	void reset_pointer () {
		_pointer = 0;
		_x = 0;
		_y = 0;
	};
	
	bool next_pointer () {
		_pointer++;
		if (_pointer < size) {
			_x = _pointer / y;
			_y = _pointer % y;
		};
		return end();
	}

	bool next_input (string prefix = "input") {
		cout << prefix << " [" << _x << "][" << _y << "] = ";
		float val;
		cin >> val;
		
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000,'\n');
			return false;
		} else {
			data[_x][_y] = val;
		}
		return !next_pointer();	
	}	
	
	Matrix& operator+=(Matrix &Other) {
		
		reset_pointer();
		
		do {	
			data[_x][_y] += Other[_x][_y];
		} while (!next_pointer());
		
		return *this;
	}
	
	
};

void clear() {
	system("cls");
};

string rep (char h, int times) {
	string result;
	
	for (int i = 0; i < times; i++) {
		result += h;
	};
	
	return result;
};

void header (Matrix &_matrix, string headerText = "Matrix anda:") {
	cout << headerText << endl;
	_matrix.output();
	
	cout << endl << rep('=',20) << endl;
};


void input (Matrix &_matrix) {
	
}
	

int main () {
	
	do {
		
		int x,y;
		clear();
		cout << "Masukkan baris: "; cin >> x;
		cout << "Masukkan kolom: "; cin >> y;
		
		Matrix Default(x,y);
		
		do {
				
			clear();
			header(Default);
			
			cout << "1. Input matrix\n2. Operasi Penjumlahan\n3. Operasi Pengurangan\n4. Operasi Perkalian\nPilih menu: ";
			
			int pil;
			cin >> pil;
			
			switch (pil) {
				case 1:
					Default.reset_pointer();
					while (!Default.end()) {
						clear();
						header(Default);
						
						if (!Default.next_input()) {
							break;
						}
						
					};
					break;
				case 2:
					Matrix Other(x,y);
					while (!Other.end()) {
						clear();
						header(Default);
						header(Other, "Matrix yang dijumlahkan");
						
						if (!Other.next_input("Input matrix penjumlahan")) {
							break;
						}
						
					};
					Default += Other;
					break;
		
					
			}
			
			
			
			
		} while (true);
		
		
	} while (true);
	
}
