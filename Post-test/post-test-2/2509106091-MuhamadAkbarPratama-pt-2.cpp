#include <iostream>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
};

struct Anomali {
    int id;
    string nama;
};

User user = {"Akbar", "091"};

Anomali anomali[50];
int jumlah = 0;

int main() {

    string username, password;
    int percobaan = 0;

    cout << "=====================================\n";
    cout << "     SISTEM MANAJEMEN DATA ANOMALI   \n";
    cout << "=====================================\n";

    while (percobaan < 3) {

        cout << "=========== LOGIN SISTEM ============\n";
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;

        if (username == user.username && password == user.password) {
            cout << "\nLogin berhasil! Selamat datang " << username << ".\n";
            cout << "berhasil masuk ke sistem.\n";
            break;
        } 
        else {
            cout << "\nLogin gagal! Username atau password salah.\n";
            percobaan++;
            cout << "Sisa percobaan login: " << 3 - percobaan << endl << endl;
        }

        if (percobaan == 3) {
            cout << "gagal login sebanyak 3 kali.\n";
            cout << "Program akan dihentikan.\n";
            return 0;
        }
    }

    int menu;

    do {

        cout << "\n=====================================\n";
        cout << "            MENU UTAMA               \n";
        cout << "=====================================\n";
        cout << "1. Tambah Data Anomali\n";
        cout << "2. Lihat Data Anomali\n";
        cout << "3. Update Data Anomali\n";
        cout << "4. Hapus Data Anomali\n";
        cout << "5. Keluar Program\n";
        cout << "-------------------------------------\n";
        cout << "Pilih menu : ";
        cin >> menu;

        switch (menu) {

        case 1:
            cout << "\n===== TAMBAH DATA ANOMALI =====\n";

            if (jumlah < 50) {
                cout << "Masukkan ID Anomali   : ";
                cin >> anomali[jumlah].id;
                cin.ignore();

                cout << "Masukkan Nama Anomali : ";
                getline(cin, anomali[jumlah].nama);

                jumlah++;

                cout << "\nData berhasil ditambahkan ke dalam sistem.\n";
            } 
            else {
                cout << "Penyimpanan data penuh!\n";
            }
            break;

        case 2:

            cout << "\n===== DAFTAR DATA ANOMALI =====\n";

            if (jumlah == 0) {
                cout << "Belum ada data anomali yang tersimpan.\n";
            } 
            else {

                for (int i = 0; i < jumlah; i++) {

                    cout << "Data ke-" << i + 1 << endl;
                    cout << "ID Anomali   : " << anomali[i].id << endl;
                    cout << "Nama Anomali : " << anomali[i].nama << endl;
                    cout << "----------------------------------";
                }

                cout << endl;
            }

            break;

        case 3:
        {
            cout << "\n===== UPDATE DATA ANOMALI =====\n";

            int cari;
            bool ditemukan = false;

            cout << "Masukkan ID yang ingin diubah : ";
            cin >> cari;
            cin.ignore();

            for (int i = 0; i < jumlah; i++) {

                if (anomali[i].id == cari) {

                    cout << "Masukkan nama anomali baru : ";
                    getline(cin, anomali[i].nama);

                    cout << "Data berhasil diperbarui.\n";

                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data dengan ID tersebut tidak ditemukan.\n";
            }

            break;
        }

        case 4:
        {
            cout << "\n===== HAPUS DATA ANOMALI =====\n";

            int cari;
            bool ditemukan = false;

            cout << "Masukkan ID yang ingin dihapus : ";
            cin >> cari;

            for (int i = 0; i < jumlah; i++) {

                if (anomali[i].id == cari) {

                    for (int j = i; j < jumlah - 1; j++) {
                        anomali[j] = anomali[j + 1];
                    }

                    jumlah--;

                    cout << "Data berhasil dihapus dari sistem.\n";

                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data dengan ID tersebut tidak ditemukan.\n";
            }

            break;
        }

        case 5:

            cout << "\n=====================================\n";
            cout << "Terima kasih telah menggunakan sistem\n";
            cout << "Manajemen Data Anomali.\n";
            cout << "Program selesai.\n";
            cout << "=====================================\n";

            break;

        default:
            cout << "Menu tidak tersedia. Silakan pilih menu yang benar.\n";
        }

    } while (menu != 5);

    return 0;
}