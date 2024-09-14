#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define baris 10
#define kolom 4

typedef char string[50];

typedef struct Pemesanan{
	int kodeKursi;
	string id;
	string nama;
}Pemesanan;

typedef struct Index{
	int i;
	int j;
}Index;

void init(Pemesanan matriks[baris][kolom]);
//Pemesanan alokasi(int kode, string id, string nama);
void printAll(Pemesanan matriks[baris][kolom]);
Index cari(Pemesanan matriks[baris][kolom], int kode);
int cekKosong(Pemesanan matriks[baris][kolom], Index index);
void invalid();
void printKhusus(Pemesanan matriks[baris][kolom], Index index);
int cekAllKosong(Pemesanan matiks[baris][kolom]);
int cekKeuntungan(Pemesanan matriks[baris][kolom]);
int cekIdSama(Pemesanan matriks[baris][kolom], string id);
Index getIndex();
