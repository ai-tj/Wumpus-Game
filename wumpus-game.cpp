#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <ctime>

using namespace std;

void delay(int ms) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);
}

// Wumpus ditemukan
void animasiWumpus() {
    const char* frames[] = {
        "[.....] Mendeteksi sesuatu...",
        "[=....] Ada suara berat di kegelapan...",
        "[==...] Wumpus tampak samar-samar...",
        "[====.] Kamu mendekatinya perlahan...",
        "[=====] Kamu berhasil menemukan dan mengalahkan Wumpus!"
    };
    for (int i = 0; i < 5; i++) {
        cout << frames[i] << endl;
        delay(500);
    }
}

// Player jatuh kejurang
void animasiJurang() {
    const char* frames[] = {
        "Kamu terpeleset...",
        "Kamu mulai jatuh...",
        "Kamu jatuh semakin cepat...",
        "Kegelapan menelan pandanganmu...",
        "Kamu jatuh ke jurang! Game Over."
    };
    for (int i = 0; i < 5; i++) {
        cout << frames[i] << endl;
        delay(600);
    }
}

int randomNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    srand(time(0));

    while (true) {
        // Clear screen
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

        cout << "=== PERMAINAN WUMPUS ===" << endl;
        cout << "Temukan Wumpus dan hindari jurang." << endl;
        cout << "Perintah: kiri | kanan | depan\n" << endl;

        int wumpusRoom = randomNum(2, 19);
        int pit1 = randomNum(2, 19);
        int pit2 = randomNum(2, 19);

        // Pastikan lokasi tidak tabrakan
        while (pit1 == wumpusRoom) pit1 = randomNum(2, 19);
        while (pit2 == wumpusRoom || pit2 == pit1) pit2 = randomNum(2, 19);

        int playerRoom = 1;
        bool gameOver = false;

        while (!gameOver) {
            cout << "\nAnda berada di ruangan " << playerRoom << endl;
            cout << "Arah (kiri/kanan/depan): ";
            string pilih;
            cin >> pilih;

            if (pilih == "kiri") {
                playerRoom--;
            } else if (pilih == "kanan") {
                playerRoom++;
            } else if (pilih == "depan") {
                playerRoom++;
            } else {
                cout << "Perintah tidak dikenal!" << endl;
                continue;
            }

            // Batas ruangan
            if (playerRoom < 1) playerRoom = 1;
            if (playerRoom > 20) playerRoom = 20;

            // Cek jurang
            if (playerRoom == pit1 || playerRoom == pit2) {
                animasiJurang();
                gameOver = true;
                break;
            }

            // Cek Wumpus
            if (playerRoom == wumpusRoom) {
                animasiWumpus();
                gameOver = true;
                break;
            }

            // Petunjuk
            if (playerRoom == wumpusRoom - 1 || playerRoom == wumpusRoom + 1)
                cout << "Kamu mencium bau busuk... Wumpus dekat." << endl;

            if (playerRoom == pit1 - 1 || playerRoom == pit1 + 1 ||
                playerRoom == pit2 - 1 || playerRoom == pit2 + 1)
                cout << "Angin berhembus kuat... Ada jurang di dekat sini." << endl;

        } //  permainan selesai

        cout << "\n=== GAME OVER ===" << endl;
        cout << "1. Coba Lagi" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilihan: ";

        int menu;
        if (!(cin >> menu)) {
            clearInput();
            menu = 2;
        }

        if (menu == 2) {
            cout << "Terima kasih telah bermain!" << endl;
            break;
        }
    }

    return 0;
}

