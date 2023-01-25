/* Nama file    : main.cpp */
/* Fungsi       : Program utama yang dijalankan */

#include "display.cpp"

int main(){
    double cards[4];
    start();
    srand(time(NULL));
    userInput(cards);
    displayAnswer(cards);
    return 0;
}