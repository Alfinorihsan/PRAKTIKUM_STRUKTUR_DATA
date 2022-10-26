//file header C++
#include <iostream>
#include <bits/stdc++.h>
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

//prosedur untuk menampilakn data
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

//node baru dari daftar peringkat
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


//prosedur untuk menampilakn pilihan tambah data
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

//prosuder untuk mengubah data
void ubah(Node **head){
  if (kosong(*head)){
    cout  <<  "-- Data tidak ada di daftar --" << endl;
    return;
  }
  int pilihan = 0;
  cout << "Peringkat yang ada pada daftar : " << rentang(*head) << endl;
  cout << "Silahkan pilih peringkat yang akan diubah : ";
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
    cout << "Harap Inputkan data sesuai jumlah peringkat yang ada" << endl;
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
    cout  <<  "-- Data berhasil di hapus --" << endl;
	}
	else{
		hapus_akhir(&HEAD);
	}
}

// Metode Marge Sort untuk mengurutkan data
Node *SortedMerge(Node *a, Node *b, int attribute, int type);
void FrontBackSplit(Node *source, Node **frontRef, Node **backRef);
void MergeSort(Node **headRef, int attribute, int type)
{
    Node *head = *headRef;
    Node *a;
    Node *b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a, attribute, type);
    MergeSort(&b, attribute, type);
    *headRef = SortedMerge(a, b, attribute, type);
}

Node *SortedMerge(Node *a, Node *b, int attribute, int type)
{
    Node *result = NULL;
    bool isAsc = type == 1;
    bool condition = false;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if(attribute == 1) {
        condition = isAsc ? a->data.skor <= b->data.skor : a->data.skor >= b->data.skor;
    } else if(attribute == 2) {
        condition = isAsc ? a->data.member <= b->data.member : a->data.member >= b->data.member;
    } else if(attribute == 3) {
        condition = isAsc ? a->data.tahun <= b->data.tahun : a->data.tahun >= b->data.tahun;
    }

    if (condition) {
        result = a;
        result->next = SortedMerge(a->next, b, attribute, type);
    } else {
        result = b; 
        result->next = SortedMerge(a, b->next, attribute, type);
    }
    return (result);
}


void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Tampilan menu pilihan pengurutan
void sort(Node **head)
{
    int attribute = 1;
    int type = 1;
    cout<< ".===================================================." << endl
        << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
        << ".===================================================." << endl
        << endl
        << "Silahkan masukkan kategori pengurutan berdasarkan :" << endl
        << "1. Skor" << endl
        << "2. Member" << endl
        << "3. Tahun rilis" << endl
        << "Pilihan : ";
    cin >> attribute;

    cout<< ".===================================================." << endl
        << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
        << ".===================================================." << endl
        << endl
        << "Silahkan masukkan metode pengurutan yang di inginkan :" << endl
        << "1. Ascending" << endl
        << "2. Descending" << endl
        << "Pilihan : ";
    cin >> type;

    MergeSort(head, attribute, type);

    cout << endl
         << "-- Data Berhasil Diurutkan --" << endl
         << endl;
}

// Prosedur Fibonacci Searching
int fibonacciSearch(Node *node, int x, int n){
    int F0 = 0; 
    int F1 = 1; 
    int F = F0 + F1; 
    while (F < n){
        F0 = F1;
        F1 = F;
        F = F0 + F1;
    }
    int offset = -1;
    int trv = 0;
    
    while (F > 1){
        Node *temp = node;
        int i = min(offset + F0, n - 1);

        while (temp->next != NULL && trv < i){
            temp = temp->next;
            trv++;
        }

        if (temp->data.member < x){
            F = F1;
            F1 = F0;
            F0 = F - F1;
            offset = i;
        }

        else if (temp->data.member > x){
            F = F0;
            F1 = F1 - F0;
            F0 = F - F1;
        }

        else return i;
        trv = 0;

    }

    Node  *temp2 = node;
    while (temp2->next != NULL && trv < offset +1){
        temp2 = temp2->next;
        trv++;
    }
    if (F1 && temp2->data.member == x) return offset + 1;
    return -1;
}

// Prosedur cari data
void cari_data(Node **head){

    int jum_member;

    Node *temp = *head;

    int panjangNode = rentang(*head);
    int index = 0;

    cout << ".===================================================." << endl
         << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
         << ".===================================================." << endl
         << endl 
        << "Silahkan Masukkan jumlah member anime yang ingin di cari : ";
    cin >> jum_member; 
    int nilai;
    nilai = fibonacciSearch(*head, jum_member, panjangNode);
    
    int no;
    no = nilai;
    int nomor = no + 1;
    if (no >= 0) {
        while (temp != NULL){

            if (index == no){
                cout << "Peringkat Ke-"<< nomor << endl
                     << "Nama Anime   : " << temp->data.nama_anime << endl
                     << "Tahun rilis  : " << temp->data.tahun << endl
                     << "Skor         : " << temp->data.skor << endl
                     << "Episode      : " << temp->data.episode << endl
                     << "Member       : " << temp->data.member << endl;
                break;
            }
            index++;
            temp = temp->next;
        }
    }else{
        cout  <<  "-- Data tidak ada di daftar --" << endl;
    }

}




//Menu utama dari program
int main()
{
  Node *HEAD = NULL;
  int pilihan = 0;
  while (pilihan != 7){
   cout << ".===================================================." << endl
        << "|    Top Anime Series (Dari Web MyAnimeList.net)    |" << endl
        << ".===================================================." << endl
        << endl
        << " Daftar Menu : " << endl
        << " 1. Tampilkan Seluruh data. " << endl
        << " 2. Tambahkan ke anime ke daftar peringkat. " << endl
        << " 3. Ubah peringkat. " << endl
        << " 4. Hapus anime dari daftar peringkat. " << endl
        << " 5. Mengurutkan anime dari daftar peringkat. " << endl
        << " 6. Cari data anime. " << endl
        << " 7. Keluar. " << endl
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
    //mengurutkan data
      sort(&HEAD);
      tampil_data(HEAD);
      break;


    case 6:
        MergeSort(&HEAD, 2, 1);
        cari_data(&HEAD);
        break;

    case 7:
    //Keluar dari program
        cout << endl 
             <<  "-- Terima kasih telah menggunakan program, Semoga harimu menyenangkan --" << endl
             << endl;
      break;
    default:
      break;
    }
  }
  return 0;
}