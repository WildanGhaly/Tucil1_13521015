/* Nama file    : display.cpp */
/* Fungsi       : Melakukan display, penyimpanan file, dan pengoperasian dengan brute force */

#include "brackets.cpp"

void start(){
/* Opening program */
    cout << "==========================================\n";
    cout << "=== Selamat datang di '24 Game Solver' ===\n";
    cout << "==========================================\n";
}

void finishing(){
/* Closing program */
    cout << "========================================================\n";
    cout << "=== Terima kasih karena telah mencoba program ini :) ===\n";
    cout << "========================================================\n";
}

void displayAnswer(double cards[4]){
    auto timeStart = chrono::high_resolution_clock::now();
    vector<string> allSol;              /* Menyimpan solusi */
    vector<array<char, 3>> allOps;      /* Operators yang legal */
    vector<array<int, 4>> allPossib; 
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i == j)
                continue;
            for (int k = 0; k < 4; k++){
                if (k == i || k == j)
                    continue;
                for (int l = 0; l < 4; l++){
                    if (l == i || l == j || l == k)
                        continue;
                    array<int, 4> arr = {i, j, k, l};
                    bool isValid = true;
                    for (int i = 0; i < 3 && isValid; i++){
                        for (int j = i + 1; j < 4 && isValid; j++){
                            if (arr[i] > arr[j] && cards[arr[i]] == cards[arr[j]]){
                                isValid = false;
                            }
                        }
                    }
                    if (isValid)
                        allPossib.push_back(arr);
                }
            }
        }
    }

    /* Brute force operators */
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                array<char, 3> arr = {ops[i], ops[j], ops[k]};
                allOps.push_back(arr);
            }
        }
    }

    /* Brute force perhitungan */
    for (int i = 0; i < allPossib.size(); i++){
        for (int j = 0; j < allOps.size(); j++){
            double cur_nums[4] = {cards[allPossib[i][0]],
                                  cards[allPossib[i][1]],
                                  cards[allPossib[i][2]],
                                  cards[allPossib[i][3]]};
            char cur_ops[3] =    {allOps[j][0],
                                  allOps[j][1],
                                  allOps[j][2]};
            allPossibleKurung(&allSol, cur_nums, cur_ops);
        }
    }

    /* Perhitungan waktu eksekusi */
    auto exeDone = chrono::high_resolution_clock::now();
    auto durasi = chrono::duration_cast<chrono::microseconds>(exeDone - timeStart);
    double executionTime = (double)durasi.count() / 1000000;

    /* Finalisasi */
    if (allSol.size() == 0){
        cout << "Tidak ditemukan solusi\nWaktu eksekusi program: " << executionTime << " detik\n";
        return;
    }
    cout << allSol.size() << " solusi ditemukan\n";
    for (int i = 0; i < allSol.size(); i++){
        cout << allSol[i] << endl;
    }
    cout << "Waktu eksekusi program: " << executionTime << " detik\n\n";

    while(true){
        char ans;
        cout << "Apakah Anda ingin menyimpan solusi (y/n)?\n>> ";
        cin >> ans;
        cin.ignore();
        if ((ans == 'y') || (ans == 'Y')){
            /* Menyimpan solusi ke dalam file */
            string name;
            cout << "Masukkan nama file: ";
            getline(cin, name);
            ofstream file("../test/" + name);
            file << "Kartu dipilih  : " << cards[0] << " " << cards[1] << " " << cards[2] << " " << cards[3] << endl;
            file << "Jumlah solusi  : " << allSol.size() << "\n";
            file << "Waktu eksekusi : " << executionTime << " detik\n\n";
            for (int i = 0; i < allSol.size(); i++){
                file << allSol[i] << endl;
            }
            file.close();
            cout << "Solusi berhasil disimpan ke file test/" << name << endl;
            finishing();
            break;
        } else if ((ans == 'n') || (ans == 'N')){
            finishing();
            break;
        } else {
            cout << "Input tidak valid!\n";
        }
    }
}