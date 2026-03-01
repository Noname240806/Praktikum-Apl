#include <iostream>
using namespace std;

int main() {
    string nama, password;
    int kesempatan = 3;

    while (kesempatan > 0) {
        cout << "===== LOGIN PROGRAM KONVERSI WAKTU =====" << endl;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan Password: ";
        cin >> password;

        if (nama == "akbar" && password == "091") {
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            kesempatan--;
            cout << "Login Salah! Sisa kesempatan: " << kesempatan << endl;
        }
    }

    if (kesempatan == 0) {
        cout << "gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    int pilihan;

    do {
        cout << "===== MENU KONVERSI WAKTU =====" << endl;
        cout << "1. Jam -> Menit dan Detik" << endl;
        cout << "2. Menit -> Jam dan Detik" << endl;
        cout << "3. Detik -> Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int jam;
            cout << "Masukkan jumlah jam: ";
            cin >> jam;

            cout << jam << " jam = "
                 << jam * 60 << " menit dan "
                 << jam * 3600 << " detik" << endl;
        }

        else if (pilihan == 2) {
            int menit;
            cout << "Masukkan jumlah menit: ";
            cin >> menit;

            cout << menit << " menit = "
                 << menit / 60 << " jam dan "
                 << menit * 60 << " detik" << endl;
        }

        else if (pilihan == 3) {
            int detik;
            cout << "Masukkan jumlah detik: ";
            cin >> detik;

            cout << detik << " detik = "
                 << detik / 3600 << " jam dan "
                 << detik / 60 << " menit" << endl;
        }

        else if (pilihan == 4) {
            cout << "Program selesai." << endl;
        }

        else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}