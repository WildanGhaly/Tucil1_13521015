# 24 Game Solver dengan Algoritma Brute Force

Program ini merupakan program yang mencari semua kemungkinan penyelesaian dari permainan 24 dengan empat kartu yang memanfaatkan algoritma brute force. Kartu valid yang ada di program ini antara lain adalah {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"} degan A bernilai 1, J bernilai 11, Q bernilai 12, dan K bernilai 13.

Jika program tidak mendapatkan solusi maka program akan menampilkan solusi tidak ditemukan. Apabila program menemukan setidaknya satu solusi maka program akan menampilkan jumlah solusi yang didapatkan, semua solusinya, dan juga waktu eksekusinya. Setelah itu program akan meminta user untuk input apakah ingin menyimpan solusi ke dalam file. Jika user ingin menyimpannya maka solusi akan disimpan di folder test.


## Requirement dan Cara Menjalankan Program

Program ini menggunakan bahasa C++ sehingga hanya akan bisa dijalankan apabila sistem telah memiliki compiler C++. Apabila sistem telah memiliki compiler C++ maka cara compile program dengan cara membuka folder program ini lalu menjalankan:

```bash
  g++ src/main.cpp -o bin/main
```

Setelah itu program bisa dijalankan dengan cara:

```bash
  bin/main
```

## Authors
Program ini dibuat oleh:
- 13521015 Hidayatullah Wildan Ghaly Buchary 