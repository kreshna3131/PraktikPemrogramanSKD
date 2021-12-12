from cryptography.fernet import Fernet
import rsa
# membuka file symmetric.key
skey = open('symmetric.key','rb')
key = skey.read()

# membuat cipher
cipher = Fernet(key)

# mmebuka file yang akan di enkripsi
myfile = open('cashback.jpeg', 'rb')
myfiledata= myfile.read()

# fungsi enkripsi
encrypted_data = cipher.encrypt(myfiledata)
edata = open('cashbackenkrip.jpeg', 'wb')
edata.write(encrypted_data)

print(encrypted_data)

# membuka public key
pkey = open('publickey.key','rb')
pkdata = pkey.read()

# load file
pubkey = rsa.PublicKey.load_pkcs1(pkdata)

# enkripsi symmetric key  dengan public key
encrypted_key = rsa.encrypt(key,pubkey)

ekey = open('kunci_enskripsi.txt','wb')
ekey.write(encrypted_key)

print(encrypted_key)
