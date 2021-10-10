# deklrasi untuk input
kunci = input("Masukkan Kunci : ")
# di replace atau diinput ulang
kunci = kunci.replace(" ", "")
# agar kunci ini selalu uppercasse atau huruf besar
kunci = kunci.upper()
# untuk membuat suatu perintah yang bisa digunakan berkali-kali
def matrix(x,y,inisial):
    # mengembalikan nilai
    return [[inisial for i in range(x)] for j in range(y)]

# mengisi hasil di dalam list
result = list()
# jika c di dalam kunci
for c in kunci:
    # jika tidak ada di dalam result
    if c not in result:
        # jika c == J
        if c=='J':
            # mengambil dan menambahkan nilai array pada urutan akhir
            result.append('I')
            # mengembalikan C
        else:
            result.append(c)

flag = 0
# jika i ada di antara 65 dan 91
for i in range(65,91):
    # jika i tidak ada di dalam result
    if chr(i) not in result:
        # jika i ==73 dan 74 tidak ada di result
        if i == 73 and chr(74) not in result:
            # maka mengambil ini
            result.append("I")
            flag = 1
        # jika flag 0 dan i 73 / 74
        elif flag == 0 and i == 73 or i == 74:
            pass    
        # jika tidak
        else:
            result.append(chr(i))
k = 0
# inisialisasi matriks
my_matrix = matrix(5,5,0)
# membuat matrix
for i in range(0,5):
    # jika j
    for j in range(0,5):
        # menampilkan matriks
        my_matrix[i][j] = result[k]
        k += 1

# mendapatkan lokasi karakter
# membuat fungsi
def locindex(c):
    # deklarasi loc diisi dengan list
    loc = list()
    # jika c = J maka c = I
    if c == 'J':
        c = 'I'
    # menambahkan penghitung ke setiap item dari objek yang dapat diubah
    for i ,j in enumerate(my_matrix):
        for k,l in enumerate(j):
            if c == l:
                loc.append(i)
                loc.append(k)
                return loc

# fungsi enkripsi
def enkripsi():
    # deklarasi pesan dan input string
    pesan = str(input("Masukkan Pesan : "))
    # membuat pesan menjadi uppercase
    pesan = pesan.upper()
    # mereplace pesan
    pesan = pesan.replace(" ", "")             
    i=0
    # jika s berada pada 0 dan panjang pesan ditambah 1,2
    for s in range(0,len(pesan) + 1,2):
        # jika s kurang dari panjang pesan -1
        if s <len(pesan) - 1:
            # jika pesan s == pesan s+1
            if pesan[s] == pesan[s+1]:
                # maka tambahkan pesan
                pesan = pesan[:s+1]+'X'+pesan[s+1:]
    # jika panjang pesan modulus 2 tidak sama dengan 0
    if len(pesan)%2!=0:
        # maka pesan ditambah X
        pesan = pesan[:]+'X'
    # mencetak
    print("CIPHER TEXT:",end=' ')
    # jika i kurang dari panjang pesan
    while i<len(pesan):
        # maka deklarasi loc diisi list
        loc = list()
        # loc diisi pesan
        loc = locindex(pesan[i])
        # loc1 deklarasi yang diisi dengan list
        loc1 = list()
        # loc1 diisi pesan
        loc1 = locindex(pesan[i+1])
        # jika loc[1] sama dengan loc1[1] maka cetak format dibawah
        if loc[1]==loc1[1]:
            print("{}{}".format(my_matrix[(loc[0]+1)%5][loc[1]],my_matrix[(loc1[0]+1)%5][loc1[1]]),end=' ')
        # jika loc[0] sama dengan loc1[0] maka cetak format dibawah
        elif loc[0]==loc1[0]:
            print("{}{}".format(my_matrix[loc[0]][(loc[1]+1)%5],my_matrix[loc1[0]][(loc1[1]+1)%5]),end=' ')  
        # jika salah maka cetak format dibawah
        else:
            print("{}{}".format(my_matrix[loc[0]][loc1[1]],my_matrix[loc1[0]][loc[1]]),end=' ')    
        i=i+2        

# fungsi dekripsi
def dekripsi():
    # pesan diisi dengan string
    pesan = str(input("Memasukkan Cipher Text : "))
    # pesan diubah menjadi uppercase
    pesan = pesan.upper()
    # mereplace pesan
    pesan = pesan.replace(" ", "")
    # mencetak plain teks
    print("PLAIN TEXT : ",end=' ')
    i = 0
    # jika i kurang dari panjang pesan
    while i<len(pesan):
        # maka deklarasi loc diisi list
        loc = list()
        # loc diisi pesan
        loc = locindex(pesan[i])
        # loc1 deklarasi yang diisi dengan list
        loc1 = list()
        # loc1 diisi pesan
        loc1 = locindex(pesan[i+1])
        # jika loc[1] sama dengan loc1[1] maka cetak format dibawah
        if loc[1]==loc1[1]:
            print("{}{}".format(my_matrix[(loc[0]-1)%5][loc[1]],my_matrix[(loc1[0]-1)%5][loc1[1]]),end=' ')
        # jika loc[0] sama dengan loc1[0] maka cetak format dibawah
        elif loc[0]==loc1[0]:
            print("{}{}".format(my_matrix[loc[0]][(loc[1]-1)%5],my_matrix[loc1[0]][(loc1[1]-1)%5]),end=' ')  
        # jika salah maka cetak format dibawah
        else:
            print("{}{}".format(my_matrix[loc[0]][loc1[1]],my_matrix[loc1[0]][loc[1]]),end=' ')    
        i=i+2        

# perulangan
while(1):
    # mencetak yang ditulis
    print("\n 1.Enkripsi \n 2.Dekripsi: \n 3.Keluar")
    # memilih inputan
    choice = int(input("Masukkan Pilihan : "))
    # jika choice sama dengan 1
    if choice == 1:
        # maka jalankan fungsi enkripsi
        enkripsi()
    # jika choice sama dengan 2
    elif choice == 2:
        # maka jalankan fungsi dekripsi
        dekripsi()
    # jika choice sama dengan 3
    elif choice == 3:
        # keluar program
        exit()
    else:
        # cetak menu
        print("Pilih Menu : ")