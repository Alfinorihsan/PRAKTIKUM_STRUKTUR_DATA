//file header C++
#include<iostream>

//library standar yang di gunakan di program
using namespace std;

//Deklarasi struck 
struct data_anime{
    string nama_anime;
    int tahun;
    float skor;
    int episode;
    int member;
};

//Array untuk menampung peringkat
data_anime peringkat[50];  

//prosedur yang di gunakan pada program
void tampil(data_anime *peringkat, int *jumlah_anime);
void tambah(data_anime *peringkat, int *jumlah_anime);
void inputan(int &input);
void ubah(data_anime *peringkat);
void hapus(data_anime *peringkat, int *jumlah_anime);
bool keluar();

//program utama
int main(){
    //Deklrasi variabel local main
    int input, jumlah_anime = 0;;
    bool loop = true;
    data_anime* ptr;

    //peruangan untuk menampilkan menu utama
    while(loop == true){
        ptr = &peringkat[0];
        cout << ".===================================================." << endl
             << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
             << ".===================================================." << endl
             << endl
             << " Daftar Menu : " << endl
             << " 1. Tampilkan Seluruh data. " << endl
             << " 2. Tambahkan ke anime ke daftar peringkat. " << endl
             << " 3. Ubah peringkat. " << endl
             << " 4. Hapus anime dari daftar peringkat. " << endl
             << " 5. Keluar. " << endl
             << endl
             << "Silahkan inputkan pilihan : ";
        cin >> input;

        //Berbagai kasus yang bisa di pilih user
        switch(input){
            case 1:
                //menampilkan data
                tampil(ptr, &jumlah_anime);
                break;

            case 2:
                //menambahkan data
                tambah(ptr, &jumlah_anime);
                cout << endl
                     << "-- Anime Tersebut telah di tambahkan ke daftar peringkat --" << endl
                     << endl;
                break;

            case 3:
                //mengubah data 
                tampil(ptr, &jumlah_anime);
                if(jumlah_anime == 0){
                    break;
                }
                ubah(peringkat);
                cout << endl
                     << "-- Peringkat telah di ubah --" << endl
                     << endl;
                break;
    
            case 4:
                //mengahapus data 
                tampil(ptr, &jumlah_anime);
                if(jumlah_anime == 0){
                    break;
                }
                hapus(ptr, &jumlah_anime);
                cout << endl
                     << "-- Anime Tersebut telah di hapus dari daftar peringkat --" << endl
                     << endl;
                break;

            case 5:
                //keluar dari program
                loop = keluar();
                cout  <<  "-- Terima kasih telah menggunakan program, Semoga harimu menyenangkan --" << endl;
                break;
        }
    }
}

//prosedur untuk menampilkan data
void tampil(data_anime *peringkat, int *jumlah_anime){
    cout << ".===================================================." << endl
         << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
         << ".===================================================." << endl;
    if(*jumlah_anime>0){
        int ulangi = 0;
        while(ulangi < *jumlah_anime){
            cout << ulangi+1 
                 << ". Nama Anime  : " << peringkat->nama_anime << endl
                 << "   Tahun rilis : " << peringkat->tahun << endl
                 << "   Skor        : " << peringkat->skor << endl 
                 << "   Episode     : " << peringkat->episode << endl
                 << "   Member      : " << peringkat->member << endl << endl;
            ulangi++;
            peringkat++;
        }
    }
    else{
        cout << "        -- Tidak ada data yang di inputkan --" << endl
             << endl;
    }
}

//Prosedur untuk menambahkan data
void tambah(data_anime *peringkat, int *jumlah_anime){
    for (int x = 0; x < *jumlah_anime; x++) {
        peringkat++;
    }
    cout << "Masukkan nama Anime   : "; fflush(stdin); getline(cin, peringkat->nama_anime);
    cout << "Masukkan tahun rilis  : ";cin >> peringkat->tahun;
    cout << "Masukkan skor         : ";cin >> peringkat->skor;
    cout << "Masukkan episode      : ";cin >> peringkat->episode;
    cout << "Masukkan member       : ";cin >> peringkat->member;
    *jumlah_anime = *jumlah_anime + 1;
}

//Prosedur untuk input memilih nomor urut di daftar menu
void inputan(int &inputan_noUrut){
    cout << "\n Nomor Urut : ";cin >> inputan_noUrut;
}

//Prosedur untuk mengubah data peringkat
void ubah(data_anime *peringkat){
    int inputan_noUrut;
    inputan(inputan_noUrut);
    inputan_noUrut -= 1;
    tambah(peringkat, &inputan_noUrut);
}

///Prosedur menghapus salah satu data
void hapus(data_anime *peringkat, int *jumlah_anime){
    int inputan_hapus;
    inputan(inputan_hapus);
    for(int x = 0;x < *jumlah_anime;x++){
        if(x == inputan_hapus-1){
            for(int y = x;y<*jumlah_anime-1;y++){
                peringkat[y] = peringkat[y+1];
            }
            *jumlah_anime = *jumlah_anime - 1;
            cout << "\n data anime telah di hapus! \n";
            return;
        }
    }
}

//Prosedur untuk keluar dari program
bool keluar(){
    return false;
}