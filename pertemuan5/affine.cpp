// membuat program affine cipher
#include <iostream>

using namespace std;

// function untuk membuat enkripsi yang diisi dengan pesan, alpha, dan beta
string enkripsi(string pesan, int alpha, int beta)
{
    // enkripsiteks diisi dengan array kosong
  string enkripsiteks = "";
    // perulangan jika r sama dengan 0 dan r kurang dari panjang pesan maka increment
    for(int r = 0; r < pesan.length(); r++)
    {
    // jika pesan pada array r tidak sama dengan array kosong
      if(pesan[r] != ' ')
    //   maka enkripsiteks ditambah char dan juga alpha dikali dengan pesan array r yang kemudian
    // dikurang A dan selanjutnya ditambah beta dengan modulus 26 ditambah A
        enkripsiteks = enkripsiteks + (char) ((((alpha * (pesan[r] - 'A')) + beta) % 26) + 'A');
        // jika salah
      else
    //   maka enkripsi teks ditambah sama dengan pesan r array
        enkripsiteks += pesan[r];

    }
// mengembalikan nilai enkripsi pada output
  return enkripsiteks;

}

// function untuk mengembalikan nilai teks kembali ke original pesan
string dekripsi(string pesan, int alpha, int beta)
{
    // membuat array dekripsi yang diisi array kosong 
  string dekripsiteks = "";
    // perulangan dengan s sama dengan 0 dan s kurang dari panjang pesan, kemudian increment s
    for(int s = 0; s < pesan.length(); s++)
    {

// dekripsi formula is applied
    // jika pesan array s tidak sama dengan array kosong
      if(pesan[s] != ' ')
        //   maka dekripsiteks ditambah char dan juga alpha dikali dengan pesan array r yang kemudian
        // dikurang A dan selanjutnya ditambah beta dengan modulus 26 ditambah A
         dekripsiteks = dekripsiteks + (char) ((((alpha * (pesan[s] - 'A')) - beta) % 26 ) + 'A');
    // jika else
      else
        // maka jalankan pesan sama dengan dekripsiteks array s
        pesan += dekripsiteks[s];
    }
    // mengembalikan nilai s
  return pesan;
}

// mengembalikan tipe data
int main()
{
    // pendeklarasian
  string pesan;
  char i;
  int alpha, beta;

// pengguna memasukkan string yang diinginkan
  while(pesan[i] < 'A' || pesan[i] > 'Z')
  {
      cout << "Masukkan String dari huruf A - Z : ";
      getline(cin, pesan);
  }
// user memasukkan nilai numerik untuk alfa dengan kondisi yang diberikan
  while(alpha <= 0 || alpha >= 26)
  {
      cout << "Masukkan angka dari 1 - 25 untuk alpha :";
      cin >> alpha;
  }

// user memasukkan nilai numerik untuk beta dengan kondisi yang diberikan
  while(beta <= 0 || beta >= 26)
  {
      cout << "Masukkan angka dari angka 0 - 25 untuk beta :";
      cin >> beta;
  }

// Program returns the user's pesan, enkripsi of the pesan, and dekripsi of the pesan

  cout << "Pesan anda adalah: " << pesan << endl;
  cout << "Enkripsi pesan anda: " << enkripsi(pesan, alpha, beta) << endl;
  cout << "Pesan Dekripsi anda: " << dekripsi(pesan, alpha, beta) << endl;
}