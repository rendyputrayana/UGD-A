#include "header.h"

void init(Pemesanan matriks[baris][kolom]){
	int i=0,j=0,kode = 10,h = 0, d =0;
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			matriks[i][j].kodeKursi = kode;
			strcpy(matriks[i][j].nama,"-");
			strcpy(matriks[i][j].id,"-");
			kode++;
		}
	}
}
/*
Pemesanan alokasi(int kode, string id, string nama){
	Data out;
	
	out.kodeKursi = kode;
	strcpy(out.id,id);
	strcpy(out.nama,nama);
	
	return out;
}
*/
void printAll(Pemesanan matriks[baris][kolom]){
	int i=0,j=0;
	printf("\n");
	printf("\n\t===Format [ kode kursi | id ]===\n");
	printf("\n");
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if(j==2){
				printf("\t\t[ %d | %s ] ",matriks[i][j].kodeKursi,matriks[i][j].id);
			}else{
				printf("[ %d | %s ] ",matriks[i][j].kodeKursi,matriks[i][j].id);
			}
		}
		printf("\n");
	}
}//printf("\n");
Index cari(Pemesanan matriks[baris][kolom], int kode){
	int i=0,j=0;
	Index index;
	index.i = -1;
	index.j = -1;
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if(matriks[i][j].kodeKursi==kode){
				index.i = i;
				index.j = j;
				return index;	
			}
		}
	}
	return index;
}
int cekKosong(Pemesanan matriks[baris][kolom], Index index){
	if(strcmpi(matriks[index.i][index.j].id,"-")==0){
		return 1;
	}else{
		return 0;
	}
}
void invalid(){
	printf("\n[!] INVALID INPUT	[!]");
}
void printKhusus(Pemesanan matriks[baris][kolom], Index index){
	printf("\n");
	printf("\n\tPenumpang Kursi %d",matriks[index.i][index.j].kodeKursi);
	printf("\n");
	printf("\nNama	: %s",matriks[index.i][index.j].nama);
	printf("\nID	: %s",matriks[index.i][index.j].id);
}
int cekAllKosong(Pemesanan matiks[baris][kolom]){
	int i =0;
	int j =0;
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if(strcmpi(matiks[i][j].id,"-")!=0){
				return 0;
			}
		}
	}
	return 1;
}
int cekKeuntungan(Pemesanan matriks[baris][kolom]){
	int i =0;
	int j =0;
	int total = 0;
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if(strcmpi(matriks[i][j].id,"-")!=0){
				total++;
			}
		}
	}
	return total;
}

int cekIdSama(Pemesanan matriks[baris][kolom], string id){
	int i =0;
	int j =0;
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if(strcmpi(matriks[i][j].id,id)==0){
				return 1;
			}
		}
	}
	return 0;
}

Index getIndex(){
	Index index;
	
	do{
		printf("\nIndex I :");scanf("%d",&index.i);
		if(index.i < 0 || index.i >= 10){
			invalid();
				printf("\n");
		}else{
			break;
		}
	}while(1);
	do{
		printf("Index J :");scanf("%d",&index.j);
		if(index.j < 0 || index.j >= 4){
			invalid();
			printf("\n");
		}else{
			break;
		}
	}while(1);
	
	return index;
}

