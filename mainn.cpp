#include <iostream> // input output
#include <thread>  // Untuk fungsi sleep_for
#include <chrono>  // Untuk waktu
#include <cstdlib> // Untuk fungsi system()

using namespace std;

bool isUserRegistered = false, isAccesApp = true;
string loggedInUser, passwordUser;
void menuPage();

struct listBooks {
    // struct daftar buku
    int id;
    string judul;
    string namaPenulis;
    int tahunTerbit;
};

void clearTerminal() {
    // Membersihkan terminal
    #ifdef _WIN32
    system("cls"); // Untuk Windows
    #else
    system("clear"); // Untuk Unix/Linux
    #endif
}

listBooks books[50] = {
    // Daftar 50 buku
    {1, "Pemburu Mimpi", "Haruki Murakami", 2009},
    {2, "Matahari Terbit", "Ernest Hemingway", 1926},
    {3, "Cahaya Kecil", "Anthony Doerr",2014},
    {4, "Lelaki Terbalik" ,"Orhan Pamuk",1999},
    {5, "Perahu Kertas" ,"Dee Lestari",2008},
    {6, "Ketika Mas Gagah Pergi" ,"Helvy Tiana Rosa",2012},
    {7, "Sapiens: Sejarah Manusia" ,"Yuval Noah Harari",2014},
    {8, "Rantau 1 Muara" ,"Ahmad Fuadi",2009},
    {9, "1984" ,"George Orwell",1949},
    {10, "Pergi" ,"Tere Liye",2011},
    {11, "The Great Gatsby" ,"F.Scott Fitzgerald",1925},
    {12, "Ayat ayat Cinta" ,"Habiburrahman El Shirazy",2004},
    {13, "To Kill a Mockingbird" ,"Harper Lee",1960},
    {14, "Laskar Pelangi" ,"Andrea Hirata",2005},
    {15, "The Catcher in the Rye" ,"J.D.Salinger",1951},
    {16, "Gone with the Wind" ,"Margaret Mitchell",1936},
    {17, "Dilan: Dia adalah Dilanku Tahun 1990" ,"Pidi Baiq",2014},
    {18, "Brave New World" ,"Aldous Huxley",1932},
    {19, "Bumi Manusia" ,"Pramoedya Ananta Toer",1980},
    {20, "The Alchemist" ,"Paulo Coelho",1988},
    {21, "Norwegian Wood" ,"Haruki Murakami",1987},
    {22, "Harry Potter and the Philosopher's Stone" ,"J.K.Rowling",1997},
    {23, "Jane Eyre" ,"Charlotte Brontë",1847},
    {24, "Kafka on the Shore" ,"Haruki Murakami",2002},
    {25, "The Lord of the Rings: The Fellowship of the Ring" ,"J.R.R.Tolkien",1954},
    {26, "Aku Ini Binatang Jalang" ,"Chairil Anwar",1943},
    {27, "One Hundred Years of Solitude" ,"Gabriel García Márquez",1967},
    {28, "Matinya Seorang Penyair" ,"Taufiq Ismail",1963},
    {29, "The Hunger Games" ,"Suzanne Collins",2008},
    {30, "Kau, Aku, dan Sepucuk Angpau Merah" ,"Tere Liye",2005},
    {31, "The Road" ,"Cormac McCarthy",2006},
    {32, "Ayahku Bukan Pembohong" ,"Tere Liye",2006},
    {33, "The Hitchhiker's Guide to the Galaxy" ,"Douglas Adams",1979},
    {34, "Pulang" ,"Tere Liye",2008},
    {35, "Fahrenheit 451" ,"Ray Bradbury",1953},
    {36, "Lima Sekawan" ,"Enid Blyton",1942},
    {37, "The Da Vinci Code" ,"Dan Brown",2003},
    {38, "Negeri 5 Menara" ,"Ahmad Fuadi",2009},
    {39, "Misteri Gunung Merapi" ,"S.H.Mintardja",1967},
    {40, "The Girl with the Dragon Tattoo" ,"Stieg Larsson",2005},
    {41, "Bumi" ,"Tere Liye",2015},
    {42, "The Color Purple" ,"Alice Walker",1982},
    {43, "Rumah Kaca" ,"Pramoedya Ananta Toer",1988},
    {44, "The Hobbit" ,"J.R.R.Tolkien",1937},
    {45, "Hujan Bulan Juni" ,"Sapardi Djoko Damono",1964},
    {46, "The Fault in Our Stars" ,"John Green",2012},
    {47, "Ketika Cinta Bertasbih" ,"Habiburrahman El Shirazy",2004},
    {48, "Sang Pemimpi" ,"Andrea Hirata",2006},
    {49, "The Kite Runner" ,"Khaled Hosseini",2003},
    {50, "Hujan Matahari" ,"Fira Basuki",2005},
};

void back() {
    char a;
    cout << "\nTekan 'x' untuk kembali ke menu" << endl;
    cin >> a;
    if (a == 'x') {
        clearTerminal();
    }
}

void about() {
    // Menu Tentang Perpustakaan
    clearTerminal();
    cout << "Selamat datang di Elins Library – tempat di mana pengetahuan bersatu dengan kreativitas! Di sini, kami merayakan warisan intelektual yang dibangun oleh tiga pikiran brilian: Luthfi Awaludin Safi, pakar sejarah yang membawa kita ke masa lalu; Kurniawan Arthur Jarnuzi, ilmuwan komputer yang membuka jendela dunia digital; dan Muhammad Winner An Nuur Alam Suskalanggeng, sastrawan yang memberi ruang pada keindahan kata.\n" << endl;
    cout << "Mari temukan keajaiban di setiap halaman buku, jelajahi sumber daya digital yang mutakhir, dan rasakan kehangatan seni yang menyelimuti ruang baca kami.Perpustakaan ini bukan hanya tempat untuk membaca, tapi juga untuk memimpikan, mencipta, dan berkumpul sebagai komunitas pencinta ilmu.\n" << endl;
    cout << "Selamat menikmati petualangan intelektual Anda di Elins Library tempat di mana setiap cerita memiliki peluang untuk merajut kisahnya sendiri.Selamat membaca dan menemukan inspirasi!\n";
    cout << "\nTekan 'x' untuk kembali ke menu" << endl;
    back();
}

void bookList() {
    // Menu Daftar Buku
    clearTerminal();
    cout << "Daftar Buku - Elins Library\n" << endl;
    for (int i = 0; i < 50; i++) {
        cout << books[i].id << ". " << books[i].judul << " " << books[i].namaPenulis << " " << books[i].tahunTerbit << "." << endl;
    }
    back();
}

void borrowing() {
    cout << "Daftar buku yang bisa dipinjam: \n" << endl;
    srand(time(nullptr));
    int randomNum = rand() % 25 + 1;
    int randomNum2 = rand() % 50 + 25;
    int dif = randomNum2 - randomNum;
    int temp = 0;
    for (int i = randomNum; i < randomNum2; i++) {
        cout << books[temp].id << ". " << books[i].judul << " " << books[i].namaPenulis << " " << books[i].tahunTerbit << "." << endl;
        temp++;
    }  
    back();
}

void returnBook() {
    cout << "pengembalian buku\n";
}

void report() {
    cout << "laporan peminjaman\n";
}

void countdown(int seconds) {
    cout << endl;
    for (int i = seconds; i > 0; --i) {
        std::cout << "Tunggu sebentar! Kamu akan diarahkan ke halaman selanjutnya dalam: " << i << " seconds...\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void greetingAnimate(int seconds) {
    string greeting = R"(
         /$$$$$$$$ /$$                           /$$             /$$     /$$                  /$$
        |__  $$__/| $$                          | $$            |  $$   /$$/                 | $$
           | $$   | $$$$$$$   /$$$$$$  /$$$$$$$ | $$   /$$       \  $$ /$$//$$$$$$  /$$   /$$| $$
           | $$   | $$__  $$ |____  $$| $$__  $$| $$  /$$/        \  $$$$//$$__  $$| $$  | $$| $$
           | $$   | $$  \ $$  /$$$$$$$| $$  \ $$| $$$$$$/          \  $$/| $$  \ $$| $$  | $$|__/
           | $$   | $$  | $$ /$$__  $$| $$  | $$| $$_  $$           | $$ | $$  | $$| $$  | $$    
           | $$   | $$  | $$|  $$$$$$$| $$  | $$| $$ \  $$          | $$ |  $$$$$$/|  $$$$$$/ /$$
           |__/   |__/  |__/ \_______/|__/  |__/|__/  \__/          |__/  \______/  \______/ |__/
    )";

    int greetingLength = greeting.size();
    string spaces(greetingLength, ' ');

    for (int i = seconds; i > 0; --i) {
        std::cout << greeting;
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        clearTerminal();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
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
        cout << "\n*** User not found. Please register first. ***\n";
        countdown(3);
        clearTerminal();
    }
}

void menuPage() {
    int pilihan;
    do {
        cout << "  _ __ ___   ___ _ __  _   _ \n"
            " | '_ ` _ \\ / _ \\ '_ \\| | | |\n"
            " | | | | | |  __/ | | | |_| |\n"
            " |_| |_| |_|\\___|_| |_|\\__,_|\n";
        cout << "\nMenu:\n";
        cout << "1. Tentang Perpustakaan\n";
        cout << "2. Daftar Buku\n";
        cout << "3. Peminjaman\n";
        cout << "4. Pengembalian\n";
        cout << "5. Laporan\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        cout << endl;

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
            clearTerminal();
            isAccesApp = false;
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
        std::cout << R"(
        ___                            ___      ___                                           
       (   ) .-.                      (   ) .-.(   )                                          
  .--.  | | ( __) ___ .-.     .--.     | | ( __)| |.-.  ___ .-.    .---.  ___ .-.   ___  ___  
 /    \ | | (''")(   )   \  /  _  \    | | (''")| /   \(   )   \  / .-, \(   )   \ (   )(   ) 
|  .-. ;| |  | |  |  .-. . . .' `. ;   | |  | | |  .-. || ' .-. ;(__) ; | | ' .-. ; | |  | |  
|  | | || |  | |  | |  | | | '   | |   | |  | | | |  | ||  / (___) .'`  | |  / (___)| |  | |  
|  |/  || |  | |  | |  | | _\_`.(___)  | |  | | | |  | || |       / .'| | | |       | '  | |  
|  ' _.'| |  | |  | |  | |(   ). '.    | |  | | | |  | || |      | /  | | | |       '  `-' |  
|  .'.-.| |  | |  | |  | | | |  `\ |   | |  | | | '  | || |      ; |  ; | | |        `.__. |  
'  `-' /| |  | |  | |  | | ; '._,' '   | |  | | ' `-' ; | |      ' `-'  | | |        ___ | |  
 `.__.'(___)(___)(___)(___) '.___.'   (___)(___) `.__. (___)     `.__.'_.(___)      (   )' |  
                                                                                     ; `-' '  
                                                                                      .__.'   
)" << endl;
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

    greetingAnimate(3);
    cout << R"(
         /$$$$$$$$ /$$                           /$$             /$$     /$$                  /$$
        |__  $$__/| $$                          | $$            |  $$   /$$/                 | $$
           | $$   | $$$$$$$   /$$$$$$  /$$$$$$$ | $$   /$$       \  $$ /$$//$$$$$$  /$$   /$$| $$
           | $$   | $$__  $$ |____  $$| $$__  $$| $$  /$$/        \  $$$$//$$__  $$| $$  | $$| $$
           | $$   | $$  \ $$  /$$$$$$$| $$  \ $$| $$$$$$/          \  $$/| $$  \ $$| $$  | $$|__/
           | $$   | $$  | $$ /$$__  $$| $$  | $$| $$_  $$           | $$ | $$  | $$| $$  | $$    
           | $$   | $$  | $$|  $$$$$$$| $$  | $$| $$ \  $$          | $$ |  $$$$$$/|  $$$$$$/ /$$
           |__/   |__/  |__/ \_______/|__/  |__/|__/  \__/          |__/  \______/  \______/ |__/
    )";
    cout << "\n             -=== Terimakasih, Selamat beraktivitas kembali! ===-" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    clearTerminal();
    main();
}