#include <iostream> 
#include <string>   
#include <vector>   
#include <time.h>   
#include <fstream>  


using namespace std;
float kartu1, kartu2, kartu3, kartu4;
string masukan1, masukan2, masukan3, masukan4;
int solution = 0 ;


// Deklarasi fungsi
float kartuToValue(string kartu)

// Mengubah kartu dari string menjadi float

{
    if (kartu == "A") {
        return 1;
    }
    else if (kartu == "J") {
        return 11;
    }
    else if (kartu == "Q") {
        return 12;
    }
    else if (kartu == "K") {
        return 13;
    }
    else {
        return stof(kartu);
    }
}


void valueToString(int angka, string &str)

// Mengubah int menjadi string

{
    if (angka == 1) {
        str = "A";
    }
    else if (angka == 11) {
        str = "J";
    }
    else if (angka == 12) {
        str = "Q";
    }
    else if (angka == 13) {
        str = "K";
    }
    else {
        str = to_string(angka);
    }
}

bool isKartuValid(string kartu)

// Mengecek apakah kartu valid

{
    if (kartu == "A" || kartu == "J" || kartu == "Q" || kartu == "K") {
        return true;
    }
    else if (stof(kartu) >= 2 && stof(kartu) <= 10) {
        return true;
    }
    else {
        return false;
    }
}

void randomkartu()

// Membaca keempat kartu secara random

{
    srand(time(NULL));
    int random1 = rand() % 13 + 1;
    int random2 = rand() % 13 + 1;
    int random3 = rand() % 13 + 1;
    int random4 = rand() % 13 + 1;
    valueToString(random1, masukan1);
    valueToString(random2, masukan2);
    valueToString(random3, masukan3);
    valueToString(random4, masukan4);
    kartu1 = kartuToValue(masukan1);
    kartu2 = kartuToValue(masukan2);
    kartu3 = kartuToValue(masukan3);
    kartu4 = kartuToValue(masukan4);
    cout << " " << endl;
    cout << "Kartu yang terpilih adalah " << masukan1 << ", " << masukan2 << ", " << masukan3 << ", dan " << masukan4 << endl;

}

void inputKartu()

// Membaca keempat kartu dari keyboard

{
    string pilihan;

    //pilih masukan dari keyboard atau random

    cout << "  " << endl;
    cout << " Selamat Datang di 24 Card Game Solver" << endl;
    cout << " Silahkan Memilih Masukan :" << endl;
    cout << " 1. Keyboard" << endl;
    cout << " 2. Random" << endl;
    cout << "  " << endl;
    cout << " Ketik Pilihan Anda: ";
    cin >> pilihan;

    // Mengecek apakah masukan valid
    while (pilihan != "1" && pilihan != "2") {
        cout << "  " << endl;
        cout << " Pilihan tidak valid. Masukkan kembali pilihan. " << endl;
        cout << "  " << endl;
        cout << " Ketik Pilihan Anda: ";
        cin >> pilihan;
    }

    // masukan dari keyboard
    if (pilihan == "1") {
        cout << "  " << endl;
        cout << " Masukkan 4 kartu: " << endl;
        cout << "  " << endl;
        cout << " Masukkan kartu : ";
        cin >> masukan1 >> masukan2 >> masukan3 >> masukan4;
        kartu1 = kartuToValue(masukan1);
        kartu2 = kartuToValue(masukan2);
        kartu3 = kartuToValue(masukan3);
        kartu4 = kartuToValue(masukan4);

        // Mengecek apakah masukan kartu valid
        while (!isKartuValid(masukan1) || !isKartuValid(masukan2) || !isKartuValid(masukan3) || !isKartuValid(masukan4)) {
            cout << "  " << endl;
            cout << " Kartu tidak valid. Masukkan kembali 4 kartu. " << endl;
            cout << " Masukkan 4 kartu: ";
            cin >> masukan1 >> masukan2 >> masukan3 >> masukan4;
            kartu1 = kartuToValue(masukan1);
            kartu2 = kartuToValue(masukan2);
            kartu3 = kartuToValue(masukan3);
            kartu4 = kartuToValue(masukan4);
        }
        cout << " " << endl;
        cout << " Kartu yang anda pilih adalah " << masukan1 << ", " << masukan2 << ", " << masukan3 << ", dan " << masukan4 << endl;
    }
    // masukan random
    else if (pilihan == "2") {
        randomkartu();
    }
}

float operasi(float kartu1, float kartu2, int mark)
// Menghitung operasi kartuA dan kartuB
{
    if (mark == 1) {
        return kartu1 + kartu2;
    }
    else if (mark == 2) {
        return kartu1 - kartu2;
    }
    else if (mark == 3) {
        return kartu1 * kartu2;
    }
    else if (mark == 4) {
        return kartu1 / kartu2;
    }
    else {
        return 0;
    }
}

string mark(int operasi)
// Mengubah angka menjadi operator
{
    if (operasi == 1) {
        return "+";
    }
    else if (operasi == 2) {
        return "-";
    }
    else if (operasi == 3) {
        return "*";
    }
    else if (operasi == 4) {
        return "/";
    }
    else {
        return "";
    }
}

bool checkDouble (vector<string> hasil, string temp)

// Mengecek apakah hasil perhitungan sudah ada di vector hasil

{
    for (int i = 0; i < hasil.size(); i++) {
        if (hasil[i] == temp) {
            return true;
        }
    }
    return false;
}

void check24(float kartu1, float kartu2, float kartu3, float kartu4, vector<string> *hasil)

// Mengecek apakah ada kombinasi kartu yang menghasilkan 24

{
    int op1, op2, op3;
    float hitung;
    string temp = "";

    for (op1 = 1; op1 <= 4; op1++) {
        for (op2 = 1; op2 <= 4; op2++) {
            for (op3 = 1; op3 <= 4; op3++) {
                
                // kartu1 op1 (kartu2 op2 (kartu3 op3 kartu4))

                hitung = operasi(operasi(operasi(kartu1, kartu2, op1), kartu3, op2), kartu4, op3);
                if (hitung == 24) {
                    temp = "((" + to_string((int)kartu1) + " " + mark(op1) + " " + to_string((int)kartu2) + ") " + mark(op2) + " " + to_string((int)kartu3) + ") " + mark(op3) + " " + to_string((int)kartu4) + " = " + to_string((int)hitung);
                    if (!checkDouble(*hasil, temp)) {
                        (*hasil).push_back(temp);
                        solution++;
                    }
                }
                
                // (kartu1 op1 kartu2) op2 (kartu3 op3 kartu4)

                hitung = operasi(operasi(kartu1, kartu2, op1), operasi(kartu3, kartu4, op3), op2);
                if (hitung == 24) {
                    temp = "(" + to_string((int)kartu1) + " " + mark(op1) + " " + to_string((int)kartu2) + ") " + mark(op2) + " (" + to_string((int)kartu3) + mark(op3) + " " + to_string((int)kartu4) + ") = " + to_string((int)hitung);
                    if (!checkDouble(*hasil, temp)) {
                        (*hasil).push_back(temp);
                        solution++;
                    }
                }
                
                // kartu1 op1 ((kartu2 op2 kartu3) op3 kartu4)
                 
                hitung = operasi(kartu1, operasi(operasi(kartu2, kartu3, op2), kartu4, op3), op1);
                if (hitung == 24) {
                    temp = to_string((int)kartu1) + " " + mark(op1) + " ((" + to_string((int)kartu2) + mark(op2) + " " + to_string((int)kartu3) + ") " + mark(op3) + " " + to_string((int)kartu4) + ") = " + to_string((int)hitung);
                    if (!checkDouble(*hasil, temp)) {
                        (*hasil).push_back(temp);
                        solution++;
                    }
                }
                
                // (kartu1 op1 kartu2) op2 (kartu3 op3 kartu4)

                hitung = operasi(operasi(kartu1, operasi(kartu2, kartu3, op2), op1), kartu4, op3);
                if (hitung == 24) {
                    temp = "(" + to_string((int)kartu1) + " " + mark(op1) + " (" + to_string((int)kartu2) + mark(op2) + " " + to_string((int)kartu3) + ")) " + mark(op3) + " " + to_string((int)kartu4) + " = " + to_string((int)hitung);
                    if (!checkDouble(*hasil, temp)) {
                        (*hasil).push_back(temp);
                        solution++;
                    }
                }
            }
        }
    }
}

void printSolution(vector <string> hasil)

// Menampilkan hasil ke layar

{
    int angka = 0;
    cout << solution <<"    Hasil Ditemukan   " << endl;
    if (solution == 0) {
        cout << "   Tidak ada hasil " << endl;
    }
    else {
        for (int i = 0; i < hasil.size(); i++) {
            angka++;
            cout << angka << hasil[i] << endl;
        }
    }
}

void save(vector <string> hasil)

// Menyimpan hasil ke file

{
    ofstream file;
    string namaFile, namaPath, pilihan;
    int number = 0;

    cout << " Apakah ingin menyimpan hasil? (y/n) : ";
    cin >> pilihan;
    while (pilihan != "y" && pilihan != "n") {
        cout << " " << endl;
        cout << " masukan salah, masukkan kembali (y/n) : ";
        cin >> pilihan;
    }
    if (pilihan == "y") {
        cout << " " << endl;
        cout << " Masukkan nama file: ";
        cin >> namaFile;
        namaPath = "../test/";
        file.open(namaPath + namaFile + ".txt");
        file << masukan1 << " " << masukan2 << " " << masukan3 << " " << masukan4 << endl;
        file << solution << " hasil ditemukan" << endl;
        if (solution == 0) {
            file << " Tidak ada hasil" << endl;
        }
        else {
            for (int i = 0; i < hasil.size(); i++) {
                number++;
                file << number << ".  \t" << hasil[i] << endl;
            }
        }
        file.close();
        cout << " " << endl;
        cout << " File berhasil disimpan" << endl;
    }
    else if (pilihan == "n") {
        cout << " " << endl;
        cout << " Tidak ada file yang disimpan" << endl;
    }
}

// Main Program

int main() 
{
    vector<string> hasil;
    
    inputKartu();

    clock_t start = clock();

    check24(kartu1, kartu2, kartu3, kartu4, &hasil);
    check24(kartu1, kartu2, kartu4, kartu3, &hasil);
    check24(kartu1, kartu3, kartu2, kartu4, &hasil);
    check24(kartu1, kartu3, kartu4, kartu2, &hasil);
    check24(kartu1, kartu4, kartu2, kartu3, &hasil);
    check24(kartu1, kartu4, kartu3, kartu2, &hasil);
    check24(kartu2, kartu1, kartu3, kartu4, &hasil);
    check24(kartu2, kartu1, kartu4, kartu3, &hasil);
    check24(kartu2, kartu3, kartu1, kartu4, &hasil);
    check24(kartu2, kartu3, kartu4, kartu1, &hasil);
    check24(kartu2, kartu4, kartu1, kartu3, &hasil);
    check24(kartu2, kartu4, kartu3, kartu1, &hasil);
    check24(kartu3, kartu1, kartu2, kartu4, &hasil);
    check24(kartu3, kartu1, kartu4, kartu2, &hasil);
    check24(kartu3, kartu2, kartu1, kartu4, &hasil);
    check24(kartu3, kartu2, kartu4, kartu1, &hasil);
    check24(kartu3, kartu4, kartu1, kartu2, &hasil);
    check24(kartu3, kartu4, kartu2, kartu1, &hasil);
    check24(kartu4, kartu1, kartu2, kartu3, &hasil);
    check24(kartu4, kartu1, kartu3, kartu2, &hasil);
    check24(kartu4, kartu2, kartu1, kartu3, &hasil);
    check24(kartu4, kartu2, kartu3, kartu1, &hasil);
    check24(kartu4, kartu3, kartu1, kartu2, &hasil);
    check24(kartu4, kartu3, kartu2, kartu1, &hasil);

    printSolution(hasil);

    double end = clock();
    cout << " " << endl;
    cout << " Waktu eksekuksi : " << (float)(clock() - start)/CLOCKS_PER_SEC << " detik" << endl;

    save(hasil);
}