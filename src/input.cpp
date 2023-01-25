/* Nama file    : input.cpp */
/* Fungsi       : Pengoperasian input dari user */

#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <chrono>
using namespace std;

string cards[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
char ops[] = {'*', '/', '+', '-'};

void userInput(double arr[4]){
/* Prosedur digunakan untuk mendapatkan input dari user */
    string card[4];
    while (true){
        cout << "1. Input manual\n2. Dipilih secara random\n>> ";
        int N;
        cin >> N;
        cin.ignore();

        /* Validasi input user */
        if ((N < 1) || (N > 2)){
            cout << "Masukan tidak valid. Harap ulangi!\n";
            continue;
        }

        if (N == 1){
            /* Pilihan untuk input kartu dari keyboard */
            while (true){
                bool isValidInput = true;
                cout << "Masukkan 4 input kartu (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) pisahkan dengan spasi:\nContoh: 10 A K 8\n>> ";
                for (int i = 0; i < 4; i++){
                    cin >> card[i];
                }
                cin.ignore();
                for (int i = 0; i < 4; i++){
                    bool isValid = false;
                    for (int j = 0; !isValid && j < 13; j++){
                        if (card[i] == cards[j]){
                            arr[i] = (double)(j + 1);
                            isValid = true;
                        }
                    }
                    if (!isValid){
                        cout << "Masukan tidak valid. Harap ulangi!\n";
                        isValidInput = false;
                        break;
                    }
                }
                if (isValidInput){
                    break;
                }
            }
        } else {
            /* Pilihan kartu random dari user */
            for (int i = 0; i < 4; i++){
                int random_card = rand() % 13 + 1;
                arr[i] = random_card;
                card[i] = cards[random_card - 1];
            }
        }
        cout <<"===============================\n";
        printf("Kartu yang dipilih: %s %s %s %s\n", card[0].c_str(), card[1].c_str(), card[2].c_str(), card[3].c_str());
        cout <<"===============================\n";
        break;
    }
}