//file header C++
#include <iostream>
#include <string>

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

//Node untuk menampung peringkat
data_anime peringkat;

struct Node{
  data_anime data;
  Node *next = NULL;
};

 
bool kosong(Node *head){
  if (head == NULL){
    return true;
  }
  return false;
}

int rentang(Node *head){
  int jumlah = 0;
  while (head != NULL){
    jumlah++;
    head = head->next;
  }
  return jumlah;
}

//node baru dari dafatar peringkat
Node *node_baru(){
	Node *nodeBaru = new Node;
	cout << ".===================================================." << endl
         << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
         << ".===================================================." << endl;
	cout << "Masukkan nama anime   : ";cin >> nodeBaru->data.nama_anime;
	cout << "Masukkan tahun rilis  : ";cin >> nodeBaru->data.tahun;
	cout << "Masukkan skor         : ";cin >> nodeBaru->data.skor;
	cout << "Masukkan episode      : ";cin >> nodeBaru->data.episode;
	cout << "Masukkan member       : ";cin >> nodeBaru->data.member;
	return nodeBaru;
}

//prosedur untuk menambah data di awal data
void tambah_pertama(Node **head){
  Node *nodeBaru = node_baru();
  nodeBaru->next = *head;
  *head = nodeBaru;
}

//prosedur untuk menambah data di akhir data
void tambah_akhir(Node **head){
  Node *nodeBaru = node_baru();
  if (kosong(*head)){
    *head = nodeBaru;
  }
  else{
    Node *temp = *head;
    while (temp->next != NULL){
      temp = temp->next;
    }
    temp->next = nodeBaru;
  }
}

//prosedur untuk menambah data diantara daftar
void tambah_antara(Node **head) {
    if (kosong(*head)) {
        cout  <<  "-- Data tidak ada di daftar --" << endl;
        return;
    }

    Node *nodeBaru = *head;

    int i = 1;
    while (nodeBaru != NULL) {
    cout <<"Peringkat Ke-"<<i<<"    <----"<<endl;
	cout << "Masukkan nama anime  : " << nodeBaru->data.nama_anime<<endl;
	cout << "Masukkan tahun rilis : " << nodeBaru->data.tahun<<endl;
	cout << "Masukkan skor        : " << nodeBaru->data.skor<<endl;
	cout << "Masukkan episode     : " << nodeBaru->data.episode<<endl;
	cout << "Masukkan member      : " << nodeBaru->data.member<<endl
         << endl;
        i += 1;
        nodeBaru = nodeBaru->next;
    }

    int index;
    cout << "silahkan masukkan Data Sebelum Node Ke-";
    cin >> index;

    if (index > 0 && index <= rentang(*head)){        
        Node *nodeBaru = node_baru();

        int nomor = 1;
        Node *temp = (*head);
        while(nomor < index-1){
            temp = temp->next;
            nomor++;
        }

        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
    else{
        cout  <<  "-- Data tidak ada di daftar --" << endl;
    }
}



//prosedur untuk menampilakn piliahn tambah data
void menu_pilihan_tambah(Node*& HEAD){
	int pilih = 1;
	cout << "Silahkan pilih metode tambah data yang di inginkan :" << endl
		 << "1. Tambah diawal daftar" << endl
		 << "2. Tambah diantara daftar" << endl
		 << "3. Tambah diakhir daftar" << endl
		 << "Pilihan : ";
	cin>>pilih;
	if(pilih == 1){
		tambah_pertama(&HEAD);
	}
	else if(pilih == 2){
		tambah_antara(&HEAD);
	}
	else{
		tambah_akhir(&HEAD);
	}
}

//prosedur untuk menghapus data di awal
void hapus_awal(Node **head){
  if (kosong(*head)){
    cout  <<  "-- Data tidak ada di daftar --" << endl;
    return;
  }
  *head = (*head)->next;
  cout  <<  "-- Data berhasil di hapus --" << endl;
}

//prosedur untuk menghapus data di akhir
void hapus_akhir(Node **head){
  if (kosong(*head)){
    cout  <<  "-- Data tidak ada di daftar --" << endl;
    return;
  }
  if ((*head)->next == NULL){
    *head = NULL;
    cout  <<  "-- Data berhasil di hapus --" << endl;
    return;
  }
  Node *temp = *head;
  while (temp->next->next != NULL){
    temp = temp->next;
  }
  Node *hapus = temp->next;
  temp->next = NULL;
  delete hapus;
  cout  <<  "-- Data berhasil di hapus --" << endl;
}

//prosedur untuk menghapus data di antara data
void hapus_antara(Node*& head, data_anime peringkat) {
    if (head == NULL)
        return;
    if (head->next == NULL) {
        delete head;
        return;
    }
    struct Node* copyHead = head;
    int count = rentang(head);
    int mid = count / 2;
    while (mid-- > 1)
        head = head->next;
    head->next = head->next->next;
}

//prosedur untuk menampilkan piliah menu hapus
void pilihan_menu_hapus(Node*& HEAD){
	int pilih = 1;
	cout << "Silahkan pilih metode hapus data yang di inginkan :" << endl
		 << "1. Hapus diawal daftar" << endl
		 << "2. Hapus diantara daftar" << endl
		 << "3. Hapus diakhir daftar" << endl
		 << "Pilihan : ";
  cin >> pilih;
    //percabangan untuk pilihan hapus
	if(pilih == 1){
		hapus_awal(&HEAD);
	}
	else if(pilih == 2){
		hapus_antara(HEAD, peringkat
    );
	}
	else{
		hapus_akhir(&HEAD);
	}
}

//prosedur untuj menampilakn data
void tampil_data(Node *head){
  if (kosong(head)){
    cout  <<  "-- Data tidak ada di daftar --" << endl;
    return;
  }
  cout << ".===================================================." << endl
       << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
       << ".===================================================." << endl;
  Node *temp = head;
  while (temp != NULL){
    cout << "Nama anime   : "<< temp->data.nama_anime <<endl;
	cout << "Tahun rilis  : "<< temp->data.tahun <<endl;
	cout << "Skor         : "<< temp->data.skor <<endl;
	cout << "Episode      : "<< temp->data.episode <<endl;
	cout << "Member       : "<< temp->data.member <<endl
    <<endl;
    temp = temp->next;
  }
  cout << endl;
}

//prosuder untuk mengubah data
void ubah(Node **head){
  if (kosong(*head)){
    cout  <<  "-- Data tidak ada di daftar --" << endl;
    return;
  }
  int pilihan = 0;
  cout << "Node yang ada pada daftar : " << rentang(*head) << endl;
  cout << "Silahkan pilih node yang akan diubah : ";
  cin >> pilihan;
  Node *temp = *head;
  if (pilihan > 0 && pilihan <= rentang(*head)){
    for (int i = 1; i < pilihan; i++){
      temp = temp->next;
    }
	cout << "Masukkan nama anime  : ";cin >> temp->data.nama_anime;
	cout << "Masukkan tahun rilis : ";cin >> temp->data.tahun;
	cout << "Masukkan skor        : ";cin >> temp->data.skor;
	cout << "Masukkan episode     : ";cin >> temp->data.episode;
	cout << "Masukkan member      : ";cin >> temp->data.member;
  }
  else{
    cout << "Harap Inputkan data sesuai jumlah node" << endl;
  }
}

//Mennu utama dari program
int main()
{
  Node *HEAD = NULL;
  int pilihan = 0;
  while (pilihan != 5){
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
    cin >> pilihan;
    
    //pilihan menu 
    switch (pilihan)
    {
    case 1:
    //menampilkan data
      tampil_data(HEAD);
      break;
    case 2:
    //menampilkan menu tambah data
      menu_pilihan_tambah(HEAD);
      break;
    case 3:
    //mengubah data
      ubah(&HEAD);
      break;
    case 4:
    //menghapus data
      pilihan_menu_hapus(HEAD);
      break;
    case 5:
    //Keluar dari program
        cout  <<  "-- Terima kasih telah menggunakan program, Semoga harimu menyenangkan --" << endl;
      break;
    default:
      break;
    }
  }
  return 0;
}