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

    try{
        if(jumlah >= 50) throw "Data penuh!";

        cout << "Masukkan ID Anomali   : ";
        cin >> data[jumlah].id;

        if(cin.fail()) throw "Input harus angka!";

        cin.ignore();
        cout << "Masukkan Nama Anomali : ";
        getline(cin,data[jumlah].nama);

        jumlah++;
        pesan("Data berhasil ditambahkan.");
    }
    catch(const char* e){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Error: " << e << endl;
    }
}

void tampilDataRekursif(Anomali *data, int index, int jumlah){
    if(index == jumlah) return;

    cout << "Data ke-" << index+1 << endl;
    cout << "ID Anomali   : " << data[index].id << endl;
    cout << "Nama Anomali : " << data[index].nama << endl;
    cout << "----------------------------------\n";

    tampilDataRekursif(data,index+1,jumlah);
}

void updateData(Anomali *data, int jumlah){
    cout << "\n===== UPDATE DATA =====\n";

    try{
        int cari, index = -1;

        cout << "Masukkan ID : ";
        cin >> cari;

        if(cin.fail()) throw "Input harus angka!";

        cin.ignore();

        for(int i=0;i<jumlah;i++){
            if(data[i].id == cari){
                index = i;
                break;
            }
        }

        if(index == -1) throw "ID tidak ditemukan!";

        cout << "Masukkan nama baru : ";
        getline(cin,data[index].nama);

        pesan("Data berhasil diperbarui.");
    }
    catch(const char* e){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Error: " << e << endl;
    }
}

void hapusData(Anomali *data, int &jumlah){
    cout << "\n===== HAPUS DATA =====\n";

    try{
        int cari, index = -1;

        cout << "Masukkan ID : ";
        cin >> cari;

        if(cin.fail()) throw "Input harus angka!";

        for(int i=0;i<jumlah;i++){
            if(data[i].id == cari){
                index = i;
                break;
            }
        }

        if(index == -1) throw "ID tidak ditemukan!";

        for(int j=index;j<jumlah-1;j++){
            data[j] = data[j+1];
        }

        jumlah--;
        pesan("Data berhasil dihapus.");
    }
    catch(const char* e){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Error: " << e << endl;
    }
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
    pesan("Data berhasil diurutkan.");
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
    pesan("Data berhasil diurutkan.");
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
    pesan("Data berhasil diurutkan.");
}

void cariIdBinary(Anomali *data, int jumlah){
    try{
        if(jumlah == 0) throw "Belum ada data!";

        int cari;
        cout << "Masukkan ID : ";
        cin >> cari;

        if(cin.fail()) throw "Input harus angka!";

        int kiri = 0, kanan = jumlah-1;

        while(kiri <= kanan){
            int tengah = (kiri + kanan)/2;

            if(data[tengah].id == cari){
                cout << "Ditemukan\n";
                return;
            }
            else if(cari < data[tengah].id) kanan = tengah-1;
            else kiri = tengah+1;
        }

        throw "Data tidak ditemukan!";
    }
    catch(const char* e){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Error: " << e << endl;
    }
}

void cariNamaLinear(Anomali *data, int jumlah){
    try{
        if(jumlah == 0) throw "Belum ada data!";

        string cari;
        cin.ignore();
        cout << "Masukkan nama : ";
        getline(cin,cari);

        for(int i=0;i<jumlah;i++){
            if(data[i].nama == cari){
                cout << "Ditemukan\n";
                return;
            }
        }

        throw "Data tidak ditemukan!";
    }
    catch(const char* e){
        cout << "Error: " << e << endl;
    }
}

int main(){
    if(!login(user)) return 0;

    int menu;

    do{
        tampilMenu();

        try{
            cout << "Pilih menu : ";
            cin >> menu;

            if(cin.fail()) throw "Menu harus angka!";
        }
        catch(const char* e){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Error: " << e << endl;
            continue;
        }

        switch(menu){
            case 1: tambahData(anomali,jumlah); break;
            case 2: tampilDataRekursif(anomali,0,jumlah); break;
            case 3: updateData(anomali,jumlah); break;
            case 4: hapusData(anomali,jumlah); break;
            case 5: sortingNamaAscending(anomali,jumlah); break;
            case 6: sortingIdDescending(anomali,jumlah); break;
            case 7: sortingNamaDescending(anomali,jumlah); break;
            case 8: cariIdBinary(anomali,jumlah); break;
            case 9: cariNamaLinear(anomali,jumlah); break;
            case 10: pesan("Terima kasih"); break;
            default: pesan("Menu tidak tersedia");
        }

    }while(menu != 10);

    return 0;
}