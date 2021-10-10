// berfungsi untuk memanggil fungsi input dan output
#include <iostream>
#include <regex>

using namespace std;

int moduloFunc(int a, int b){
    int result = a % b;
    if (result < 0){
        result += b;
    }
    return result;
}

// mendeklarasikan fungsi Enkripsi
void cipherEnkripsi(){
  // memasukkan string Pesan
    string pesan;
    // mencetak pesan
    cout << "Masukkan Pesan : ";
    // mengambil cin dan pesan
    getline(cin, pesan);

    // ubah pesan ke Uppercase
    // jika i = 0 kurang dari panjang pesan, maka lakukan penambahan
    for (int i = 0; i < pesan.length(); i++){
        // jika pesan array i = toupper
        pesan[i] = toupper(pesan[i]);
    }

    // maka hapus spasi dari pesan
    pesan = regex_replace(pesan, regex("\\s+"), "");

    // jika panjang pesan modulus 2 tidak sama dengan 0 maka lakukan padding
    int lenChk = 0;
    if(pesan.length()%2 != 0){
        pesan += "0";
        lenChk = 1;
    }

    // message to 2x pesan.length/2 matrix
    // pesan 2x panjang pesan dibagi 2
    int pesan2D[2][pesan.length()/2];
    // deklarasi iterasi1 dan iterasi2
    int iterasi1 = 0;
    int iterasi2 = 0;
    // melakukan perulangan jika i = 0 dan panjang pesan kurang dari panjang pesan maka i++
    for (int i = 0; i < pesan.length(); i++){
        // jika i modulus 2 sama dengan 0
        if(i%2 == 0){
            // maka lakukan perintah dibawah ini diisi dengan pesan array i dikurang 65
            pesan2D[0][iterasi1] = pesan[i] - 65;
            iterasi1++;
          // jika tidak
        } else {
            // maka lakukan iterasi2
            pesan2D[1][iterasi2] = pesan[i] - 65;
            iterasi2++;
        } //if-else
    } // for

    cout << "Masukkan 4 Baris Kunci : ";
    string kunci;
    getline(cin, kunci);

    // kunci ke Uppercase
    // jika i = 0 dan i kurang dari panjang kunci maka lakukan i++
    for (int i = 0; i < kunci.length(); i++){
        kunci[i] = toupper(kunci[i]);
    }

    // menghapus spasi pada kunci
    kunci = regex_replace(kunci, regex("\\s+"), "");

    // kunci matriks 2x2
    int kunci2D[2][2];
    // deklarasi iterasi3
    int iterasi3 = 0;
    // jika i sama dengan 0 dan kurang dari 2 maka lakukan i++
    for (int i = 0; i < 2; i++){
        // jika j sama dengan 0 dan kurang dari 2 maka lakukan j++
        for (int j = 0; j<2; j++){
            // untuk matriks dan dikurangi 65
            kunci2D[i][j] = kunci[iterasi3]-65;
            // return iterasi3
            iterasi3++;
        }
    }

    // mengecek validasi pada kunci
    // mencari determinan
    int deter = kunci2D[0][0] * kunci2D[1][1] - kunci2D[0][1] * kunci2D[1][0];
    deter = moduloFunc(deter, 26);

    // mencari multiple invers
    int mulInv = -1;
    // jika i sama dengan 0 dan i kurang dari 26 maka i++
    for (int i=0; i<26; i++){
        // deklarasi untuk determinan
        int tempInv = deter * i;
        // jika sama dengan 1
        if (moduloFunc(tempInv, 26) == 1){
            // maka mmulInv sama dengan i
            mulInv = i;
            // untuk berhenti
            break;
        } else {
            // untuk lanjut
            continue;
        }
    } // for

    // jika mulInv sama dengan -1
    if (mulInv == -1){
        // maka cetak kunci tidak tepat dan keluar
        cout << "Kunci Tidak Tepat" << endl;
        exit(EXIT_FAILURE);
    }

    // deklarasi enkripsi teks diisi dengan stringkosong
    string enkripsiTeks = "";
    // deklarasi panjang pesan dibagi 2
    int itrCount = pesan.length()/2;
    if (lenChk == 0){
        // jika panjang pesan modulus 2 = 0
        for (int i = 0; i < itrCount; i++){
            // maka temp1 diisi dengan pesan2D dan dikalikan kunci2D ditambah pesan2D dikali kunci2D
            int temp1 = pesan2D[0][i] * kunci2D[0][0] + pesan2D[1][i] * kunci2D[0][1];
            // enkripsi teks
            enkripsiTeks += (char)((temp1 % 26) + 65);
            // maka temp2 diisi dengan pesan2D dan dikalikan kunci2D ditambah pesan2D dikali kunci2D
            int temp2 = pesan2D[0][i] * kunci2D[1][0] + pesan2D[1][i] * kunci2D[1][1];
            // enkripsi teks
            enkripsiTeks += (char)((temp2 % 26) + 65);
        }
      // jika salah
    } else {
        // jika panjang pesan modulus 2 = o
        // if pesan.length % 2 == 0
        for (int i = 0; i < itrCount-1; i++){
            // maka lakukan program dibawah ini
            int temp1 = pesan2D[0][i] * kunci2D[0][0] + pesan2D[1][i] * kunci2D[0][1];
            enkripsiTeks += (char)((temp1 % 26) + 65);
            int temp2 = pesan2D[0][i] * kunci2D[1][0] + pesan2D[1][i] * kunci2D[1][1];
            enkripsiTeks += (char)((temp2 % 26) + 65);
        }
    }
    // mencetak atau menampilkan hasil enkripsi teks
    cout << endl << "Enkripsi Teks : " << enkripsiTeks << endl;
}

// fungsi dekripsi
void cipherDekripsi(){
    // deklarasi pesan
    string pesan;
    // mencetak inputan
    cout << "Masukkan Pesan : ";
    getline(cin, pesan);

    // mengubah pesan menjadi uppercase
    for (int i = 0; i < pesan.length(); i++){
        pesan[i] = toupper(pesan[i]);
    }

    // menghapus spasi pada pesan
    pesan = regex_replace(pesan, regex("\\s+"), "");

    // jika panjang pesan modulus 2 tidak sama dengan 0 maka lakukan padding
    int lenChk = 0;
    if(pesan.length()%2 != 0){
        pesan += "0";
        lenChk = 1;
    }

    // pesan 2x panjang pesan dibagi 2
    int pesan2D[2][pesan.length()/2];
    // deklarasi iterasi
    int iterasi1 = 0;
    int iterasi2 = 0;
    // jika i = 0 dan i kurang dari panjang pesan maka lakukan i++
    for (int i = 0; i < pesan.length(); i++){
        // jika i modulus 2 sama dengan 0
        if(i%2 == 0){
            pesan2D[0][iterasi1] = pesan[i] - 65;
            iterasi1++;
          // jika salah
        } else {
            pesan2D[1][iterasi2] = pesan[i] - 65;
            iterasi2++;
        } //if-else
    } // for
    // mencetak inputan
    cout << "Masukkan 4 Baris Kunci String : ";
    string kunci;
    getline(cin, kunci);

    // kunci ke uppercase
    // jika i sama dengan 0 danpanjang kunci kurang dari i maka i++
    for (int i = 0; i < kunci.length(); i++){
        kunci[i] = toupper(kunci[i]);
    }

    // menghapus spasi pada kunci
    kunci = regex_replace(kunci, regex("\\s+"), "");

    // kunci untuk matrik 2x2
    int kunci2D[2][2];
    // deklarasi iterasi3
    int iterasi3 = 0;
    // jika i sama dengan 0 dan i kurang dari 2 maka lakukan i++
    for (int i = 0; i < 2; i++){
        // jika j sama dengan 0 dan i kurang dari 2 maka lakukan j++
        for (int j = 0; j<2; j++){
            kunci2D[i][j] = kunci[iterasi3]-65;
            iterasi3++;
        }
    }

    // mencari determinan
    int deter = kunci2D[0][0] * kunci2D[1][1] - kunci2D[0][1] * kunci2D[1][0];
    deter = moduloFunc(deter, 26);

    // mencari inverse
    int mulInv = -1;
    for (int i=0; i<26; i++){
        int tempInv = deter * i;
        if (moduloFunc(tempInv, 26) == 1){
            mulInv = i;
            break;
        } else {
            continue;
        }
    } // for

    // mengubah matriks
    swap(kunci2D[0][0],kunci2D[1][1]);

    // mengubah tanda
    kunci2D[0][1] *= -1;
    kunci2D[1][0] *= -1;

    kunci2D[0][1] = moduloFunc(kunci2D[0][1], 26);
    kunci2D[1][0] = moduloFunc(kunci2D[1][0], 26);

    // perkalian inverse dan matriks
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            kunci2D[i][j] *= mulInv;
        }
    }
    for (int i=0; i<2;i++){
        for(int j =0; j <2; j++){
            kunci2D[i][j] = moduloFunc(kunci2D[i][j], 26);
        }
    }

    // mengubah menjadi dekripsi teks
    string dekripsiTeks = "";
    // deklarasi
    int itrCount = pesan.length()/2;
    // jika lenchk sama dengan 0
    if (lenChk == 0){
        // jika panjang pesan modulus 2 sama dengan 0
        for (int i = 0; i < itrCount; i++){
            // maka temp1 diisi dengan pesan2D dan dikalikan kunci2D ditambah pesan2D dikali kunci2D
            int temp1 = pesan2D[0][i] * kunci2D[0][0] + pesan2D[1][i] * kunci2D[0][1];
            // dekripsi teks
            dekripsiTeks += (char)((temp1 % 26) + 65);
            // maka temp2 diisi dengan pesan2D dan dikalikan kunci2D ditambah pesan2D dikali kunci2D
            int temp2 = pesan2D[0][i] * kunci2D[1][0] + pesan2D[1][i] * kunci2D[1][1];
            // dekripsi teks
            dekripsiTeks += (char)((temp2 % 26) + 65);
        }
    } else {
        // if pesan.length % 2 == 0
        for (int i = 0; i < itrCount-1; i++){
            // maka temp1 diisi dengan pesan2D dan dikalikan kunci2D ditambah pesan2D dikali kunci2D
            int temp1 = pesan2D[0][i] * kunci2D[0][0] + pesan2D[1][i] * kunci2D[0][1];
            // dekripsi teks
            dekripsiTeks += (char)((temp1 % 26) + 65);
            // maka temp2 diisi dengan pesan2D dan dikalikan kunci2D ditambah pesan2D dikali kunci2D
            int temp2 = pesan2D[0][i] * kunci2D[1][0] + pesan2D[1][i] * kunci2D[1][1];
            // dekripsi teks
            dekripsiTeks += (char)((temp2 % 26) + 65);
        }
    }
    // menampilkan hasil dekripsi teks
    cout << endl << "Dekripsi Teks : " << dekripsiTeks << endl;

}

// fungsi main
int main()
{
    // menampilkan pilihan
    cout << "1. Enkripsi\n2. Dekripsi\nPilih(1,2) : ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    // jika pilihan sama dengan 1
    if (pilihan == 1){
        // maka lakukan enkripsi teks
        cout << endl << "---Enkripsi---" << endl;
        cipherEnkripsi();
      // jika pilihan sama dengan 2
    } else if (pilihan == 2){
        // maka lakukan dekripsi teks
        cout << endl << "---Dekripsi---" << endl;
        cipherDekripsi();
        // jika salah maka selesaikan program
    } else {
        cout << endl << "Salah" << endl;
    }

    return 0;
}