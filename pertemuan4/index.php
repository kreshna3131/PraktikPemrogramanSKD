<?php

// mendeklarasikan variable yang digunakan
$kunci = "";
$error = "";
$valid = true;
$warna = "#FF0000";

// percabangan if atau jika benar terjadi kiriman maka akan menjalankan program yang ada didalam proses
if ($_SERVER['REQUEST_METHOD'] == "POST") {
  // mendeklarasikan fungsi enkripsi dan dekripsi
  require_once('proses.php');

  // melakukan pendeklarasian nilai dengan fungsi yang ada dari nilai yang dimasukkan
  $kunci = $_POST['kunci'];
  $code = $_POST['code'];

  // percabangan if untuk mengecek nilai yang dikirim post kosong atau tidak jika kosong akan menjalankan program
  if (empty($_POST['kunci'])) {
    // deklarasi nilai error
    $error = "Dimohon masukkan kata kunci";
    // pendeklarasian nilai valid sama dengan false
    $valid = false;
  }

  // percabangan untuk mengecek nilai yang dikirim atau dipost kosong atau tidak jika kosong maka akan menjalankan program
  else if (empty($_POST['code'])) {
    // pendeklarasian nilai error untuk plaintext
    $error = "Masukkan Teks";
    // pendeklarasian nilai valid sama dengan false
    $valid = false;
  }

  // percabangan untuk mengecek nilai yang dikirim atau dipost kosong atau tidak jika kosong maka akan menjalankan program
  else if (isset($_POST['kunci'])) {
    // if jika untuk mengecek nilai yang diikirimkan tidak sesuai maka akan menjalankan program
    if (!ctype_alpha($_POST['kunci'])) {
      // pendeklarasian nilai error untuk katakunci
      $error = "Kata sandi hanya Karakter";
      // pendeklarasian nilai valid sama dengan false
      $valid = false;
    }
  }

  // jika nilainya valid
  if ($valid) {
    // jika tombol enkripsi sudah ditekan maka akan menjalankan program
    if (isset($_POST['encrypt'])) {
      // deklarasi nilai plaintext
      $code = encrypt($kunci, $code);
      // pendeklarasian nilai error untuk katakunci
      $error = "Teks yang ditulis berhasil di Enkripsi";
      // deklarasi warna
      $warna = "#526F35";
    }

    // jika tombol dekripsi sudah ditekan maka akan menjalankan program
    if (isset($_POST['decrypt'])) {
      // deklarasi nilai plaintext
      $code = decrypt($kunci, $code);
      // pendeklarasian nilai error untuk plaintext
      $error = "Kode yang ditulis berhasil di Dekripsi";
      // deklarasi warna
      $warna = "#526F35";
    }
  }
}

?>

<html>

<head>
  <title>PERTEMUAN 4 VIGENER CIPHER</title>
  <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
  <br><br><br>
  <form action="index.php" method="post">
    <table cellpadding="5" align="center" cellpadding="2" border="7">
      <caption>
        <hr><b>VIGENER CIPHER ENKRIPSI DAN DEKRIPSI</b>
        <hr>
      </caption>
      <tr>
        <td align="center">MASUKKAN KUNCI : <input type="text" name="kunci" id="pass" value="<?php echo htmlspecialchars($kunci); ?>" /></td>
      </tr>
      <tr>
        <td align="center"><textarea id="box" name="code"><?php echo htmlspecialchars($code); ?></textarea></td>
      </tr>
      <tr>
        <td><input type="submit" name="encrypt" class="button" value="Enkripsi" onclick="validate(1)" /></td>
      </tr>
      <tr>
        <td><input type="submit" name="decrypt" class="button" value="Dekripsi" onclick="validate(2)" /></td>
      </tr>
      <tr>
        <td>
          <center>
            <div style="color: <?php echo htmlspecialchars($warna) ?>"><?php echo htmlspecialchars($error) ?></div>
          </center>
        </td>
      </tr>
    </table>
  </form>
</body>

</html>