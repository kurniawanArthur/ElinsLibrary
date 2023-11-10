#include <iostream>
using namespace std;
#include <thread>  // Untuk fungsi sleep_for
#include <chrono>  // Untuk waktu
#include <cstdlib> // Untuk fungsi system()

bool isUserRegistered = false, isAccesApp = true;
string loggedInUser, passwordUser;
void menuPage();

void about() {
    cout << "tentang perpustakaan kami";
}

void bookList() {
    cout << "daftar buku";
}

void borrowing() {
    cout << "daftar buku yang tersedia: ";
}

void returnBook() {
    cout << "pengembalian buku";
}

void report() {
    cout << "laporan peminjaman";
}

void clearTerminal() {
    // Membersihkan terminal
    #ifdef _WIN32
    system("cls"); // Untuk Windows
    #else
    system("clear"); // Untuk Unix/Linux
    #endif
}

void countdown(int seconds) {
    for (int i = seconds; i > 0; --i) {
        std::cout << "Tunggu sebentar! Kamu akan diarahkan ke halaman selanjutnya dalam: " << i << " seconds...\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void registerUser() {
    cout << "Registration\n";
    cout << "Enter your username: ";
    cin >> loggedInUser;
    isUserRegistered = true;
    cout << "Enter your password: ";
    cin >> passwordUser;
    cout << "Registration successful!\n";
    countdown(3);
    clearTerminal();
}

void loginUser() {
    cout << "Login\n";
    cout << "Masukkan ID/username: ";
    string username;
    cin >> username;
    cout << "Masukkan Password: ";
    string password;
    cin >> password;

    if (isUserRegistered && username == loggedInUser && password == passwordUser) {
        cout << "Login successful! Welcome, " << loggedInUser << "!\n";
        countdown(3);
        clearTerminal();
        menuPage();
    }
    else {
        cout << "User not found. Please register first.\n";
    }
}

void menuPage() {
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tentang Perpustakaan\n";
        cout << "2. Daftar Buku\n";
        cout << "3. Peminjaman\n";
        cout << "4. Pengembalian\n";
        cout << "5. Laporan\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            // Tentang perpustakaan
            about();
            break;
        case 2:
            // Implementasi daftar buku
            bookList();
            break;
        case 3:
            // Implementasi peminjaman
            borrowing();
            break;
        case 4:
            // Implementasi pengembalian
            returnBook();
            break;
        case 5:
            // Implementasi laporan
            report();
            break;
        case 6:
            cout << "Terima kasih telah menggunakan layanan perpustakaan kami!" << endl;
            isAccesApp = false;
            clearTerminal();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    } while (pilihan != 6);
}

int main() {
	//Welcome message
    int welcome;
    do {
        std::cout << " _______  __       __  .__   __.      _______.    __       __  .______   .______          ___      .______     ____    ____ \n";
        std::cout << "|   ____||  |     |  | |  \\ |  |     /       |   |  |     |  | |   _  \\  |   _  \\        /   \\     |   _  \\   \\   \\  /  / \n";
        std::cout << "|  |__   |  |     |  | |   \\|  |    |   (----`   |  |     |  | |  |_)  | |  |_)  |      /  ^  \\    |  |_)  |    \\   \\/  /  \n";
        std::cout << "|   __|  |  |     |  | |  . `  |     \\   \\       |  |     |  | |   _  <  |      /      /  /_\\  \\   |      /      \\_   _/   \n";
        std::cout << "|  |____ |  `----.|  | |  |\\   | .----)   |      |  `----.|  | |  |_)  | |  |\\  \\----./  _____  \\  |  |\\  \\----.  |  |     \n";
        std::cout << "|_______||_______||__| |__| \\__| |_______/       |_______||__| |______/  | _| `._____/__/     \\__\\ | _| `._____|  |__|     \n";
        cout << "Selamat datang di Perpustakaan Elins" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar" << endl;
        cout << "Silahkan Login terlebih dahulu! jika belum memiliki akun pilih daftar(1/2): ";
        cin >> welcome;

        switch (welcome) {
        case 1:
            // Login page
            clearTerminal();
            loginUser();
            break;
        case 2:
            // Registration page
            clearTerminal();
            registerUser();
            break;
        }
    } while (isAccesApp == true);
}