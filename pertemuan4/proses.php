<?php

// berfungsi untuk enkripsi dari text yang didapat
function encrypt($kunci, $text)
{
  // mengubah kunci menjadi huruf kecil untuk disederhanakan
  $kunci = strtolower($kunci);

  // inisialisasi
  $ki = 0;
  $kl = strlen($kunci);
  $panjang = strlen($text);

  // mengulangi program setiap baris dalam teks
  for ($i = 0; $i < $panjang; $i++) {
    // jika hurufnya alfa maka lakukan enkripsi
    if (ctype_alpha($text[$i])) {
      // untuk mengecek ini huruf besar
      if (ctype_upper($text[$i])) {
        $text[$i] = chr(((ord($kunci[$ki]) - ord("a") + ord($text[$i]) - ord("A")) % 26) + ord("A"));
      }

      // untuk mengecek ini huruf kecil
      else {
        $text[$i] = chr(((ord($kunci[$ki]) - ord("a") + ord($text[$i]) - ord("a")) % 26) + ord("a"));
      }

      // memperbarui pada indeks kuncinya
      $ki++;
      if ($ki >= $kl) {
        $ki = 0;
      }
    }
  }

  // mengembalikan nilai encrypt atau enkripsi
  return $text;
}

// berfungsi untuk dekripsi dari text yang didapat
function decrypt($kunci, $text)
{
  // mengubah kunci menjadi huruf kecil untuk disederhanakan
  $kunci = strtolower($kunci);

  // menginisialisasi variable
  $ki = 0;
  $kl = strlen($kunci);
  $panjang = strlen($text);

  // mengulangi program setiap baris dalam teks
  for ($i = 0; $i < $panjang; $i++) {
    // jika hurufnya alfa maka lakukan dekripsi
    if (ctype_alpha($text[$i])) {
      // mengecek jika huruf besar
      if (ctype_upper($text[$i])) {
        $x = (ord($text[$i]) - ord("A")) - (ord($kunci[$ki]) - ord("a"));

        if ($x < 0) {
          $x += 26;
        }

        $x = $x + ord("A");

        $text[$i] = chr($x);
      }

      // mengecek jika huruf kecil
      else {
        $x = (ord($text[$i]) - ord("a")) - (ord($kunci[$ki]) - ord("a"));

        if ($x < 0) {
          $x += 26;
        }

        $x = $x + ord("a");

        $text[$i] = chr($x);
      }

      // memperbarui pada indeks kuncinya
      $ki++;
      if ($ki >= $kl) {
        $ki = 0;
      }
    }
  }

  // mengembalikan nilai decrypt atau dekripsi
  return $text;
}
