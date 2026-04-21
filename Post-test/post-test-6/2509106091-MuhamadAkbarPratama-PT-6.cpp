#include <iostream>
#include <string>
using namespace std;

struct User{
    string username;
    string password;
};

struct Anomali{
    int id;
    string nama;
};

User user = {"Akbar","091"};
Anomali anomali[50];
int jumlah = 0;

void pesan(string teks){
    cout << teks << endl;
}

void pesan(string teks, int angka){
    cout << teks << angka << endl;
}

void tampilMenu(){
    cout << "\n=====================================\n";
    cout << "            MENU UTAMA               \n";
    cout << "=====================================\n";
    cout << "1. Tambah Data Anomali\n";
    cout << "2. Lihat Data Anomali\n";
    cout << "3. Update Data Anomali\n";
    cout << "4. Hapus Data Anomali\n";
    cout << "5. Sorting Nama Ascending\n";
    cout << "6. Sorting ID Descending\n";
    cout << "7. Sorting Nama Descending\n";
    cout << "8. Cari ID Anomali\n";
    cout << "9. Cari Nama Anomali\n";
    cout << "10. Keluar Program\n";
    cout << "-------------------------------------\n";
}

bool login(User &user){
    string username,password;
    int percobaan = 0;

    while(percobaan < 3){
        cout << "=========== LOGIN SISTEM ============\n";
        cout << "Username : ";
        cin >> username;

        cout << "Password : ";
        cin >> password;

        if(username == user.username && password == user.password){
            pesan("Login berhasil!");
            return true;
        }
        else{
            pesan("Login gagal!");
            percobaan++;
            pesan("Sisa percobaan : ",3-percobaan);
        }
    }

    pesan("Login gagal 3 kali. Program berhenti.");
    return false;
}

void tambahData(Anomali *data, int &jumlah){
    cout << "\n===== TAMBAH DATA ANOMALI =====\n";

    if(jumlah < 50){
        cout << "Masukkan ID Anomali   : ";
        cin >> data[jumlah].id;
        cin.ignore();

        cout << "Masukkan Nama Anomali : ";
        getline(cin,data[jumlah].nama);

        jumlah++;
        pesan("Data berhasil ditambahkan.");
    }
    else{
        pesan("Data penuh.");
    }
}

void tampilDataRekursif(Anomali *data, int index, int jumlah){
    if(index == jumlah){
        return;
    }

    cout << "Data ke-" << index+1 << endl;
    cout << "ID Anomali   : " << data[index].id << endl;
    cout << "Nama Anomali : " << data[index].nama << endl;
    cout << "----------------------------------\n";

    tampilDataRekursif(data,index+1,jumlah);
}

void updateData(Anomali *data, int jumlah){
    cout << "\n===== UPDATE DATA =====\n";

    int cari;
    int index = -1;

    cout << "Masukkan ID yang ingin diubah : ";
    cin >> cari;
    cin.ignore();

    for(int i=0;i<jumlah;i++){
        if(data[i].id == cari){
            index = i;
            break;
        }
    }

    if(index == -1){
        pesan("ID tidak ditemukan.");
        return;
    }

    cout << "Masukkan nama baru : ";
    getline(cin,data[index].nama);

    pesan("Data berhasil diperbarui.");
}

void hapusData(Anomali *data, int &jumlah){
    cout << "\n===== HAPUS DATA =====\n";

    int cari;
    int index = -1;

    cout << "Masukkan ID yang ingin dihapus : ";
    cin >> cari;

    for(int i=0;i<jumlah;i++){
        if(data[i].id == cari){
            index = i;
            break;
        }
    }

    if(index == -1){
        pesan("ID tidak ditemukan.");
        return;
    }

    for(int j=index;j<jumlah-1;j++){
        data[j] = data[j+1];
    }

    jumlah--;
    pesan("Data berhasil dihapus.");
}

void sortingNamaAscending(Anomali *data, int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-1-i; j++){
            if(data[j].nama > data[j+1].nama){
                Anomali temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    pesan("Data berhasil diurutkan berdasarkan nama ascending.");
}

void sortingIdDescending(Anomali *data, int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-1-i; j++){
            if(data[j].id < data[j+1].id){
                Anomali temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    pesan("Data berhasil diurutkan berdasarkan ID descending.");
}

void sortingNamaDescending(Anomali *data, int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-1-i; j++){
            if(data[j].nama < data[j+1].nama){
                Anomali temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    pesan("Data berhasil diurutkan berdasarkan nama descending.");
}

void cariIdBinary(Anomali *data, int jumlah){
    if(jumlah == 0){
        pesan("Belum ada data.");
        return;
    }

    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-1-i; j++){
            if(data[j].id > data[j+1].id){
                Anomali temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    int cari;
    cout << "Masukkan ID yang dicari : ";
    cin >> cari;

    int kiri = 0;
    int kanan = jumlah - 1;
    bool ditemukan = false;

    while(kiri <= kanan){
        int tengah = (kiri + kanan) / 2;

        if(data[tengah].id == cari){
            cout << "Data ditemukan!" << endl;
            cout << "ID Anomali   : " << data[tengah].id << endl;
            cout << "Nama Anomali : " << data[tengah].nama << endl;
            ditemukan = true;
            break;
        }
        else if(cari < data[tengah].id){
            kanan = tengah - 1;
        }
        else{
            kiri = tengah + 1;
        }
    }

    if(!ditemukan){
        pesan("Data tidak ditemukan.");
    }
}

void cariNamaLinear(Anomali *data, int jumlah){
    if(jumlah == 0){
        pesan("Belum ada data.");
        return;
    }

    string cari;
    bool ditemukan = false;

    cin.ignore();

    cout << "Masukkan nama yang dicari : ";
    getline(cin, cari);

    for(int i=0; i<jumlah; i++){
        if(data[i].nama == cari){
            cout << "Data ditemukan!" << endl;
            cout << "ID Anomali   : " << data[i].id << endl;
            cout << "Nama Anomali : " << data[i].nama << endl;
            ditemukan = true;
        }
    }

    if(!ditemukan){
        pesan("Data tidak ditemukan.");
    }
}

int main(){
    cout << "=====================================\n";
    cout << "     SISTEM MANAJEMEN DATA ANOMALI   \n";
    cout << "=====================================\n";

    if(!login(user)){
        return 0;
    }

    int menu;

    do{
        tampilMenu();

        cout << "Pilih menu : ";
        cin >> menu;

        switch(menu){

        case 1:
            tambahData(anomali,jumlah);
            break;

        case 2:
            if(jumlah == 0){
                pesan("Belum ada data.");
            }
            else{
                tampilDataRekursif(anomali,0,jumlah);
            }
            break;

        case 3:
            updateData(anomali,jumlah);
            break;

        case 4:
            hapusData(anomali,jumlah);
            break;

        case 5:
            sortingNamaAscending(anomali,jumlah);
            break;

        case 6:
            sortingIdDescending(anomali,jumlah);
            break;

        case 7:
            sortingNamaDescending(anomali,jumlah);
            break;

        case 8:
            cariIdBinary(anomali,jumlah);
            break;

        case 9:
            cariNamaLinear(anomali,jumlah);
            break;

        case 10:
            pesan("Terima kasih telah menggunakan program.");
            break;

        default:
            pesan("Menu tidak tersedia.");
        }

    }while(menu != 10);

    return 0;
}