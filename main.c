#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int menu = 0,i = 0,j =0, kode, total=0;
	string id,nama,confirm;
	Index index;
	Pemesanan matriks[baris][kolom];
	init(matriks);
	do{
		system("cls");
		printf("\n\t[UGD TIPE A]");
		printf("\n");
		printf("\n[1] Input Data Penumpang");
		printf("\n[2] Print All Penumpang");
		printf("\n[3] Print Khusus");
		printf("\n[4] Hitung Total Pendapatan");
		printf("\n");
		printf("\n==============================================");
		printf("\n");
		printf("\n[5] Update Pemesanan Penumpang		[Bonus]");
		printf("\n[6] Batalkan Pemesanan			[BONUS]");
		printf("\n>>>");scanf("%d",&menu);
		switch(menu){
			case 1:{
				printf("\n\t[Input Data Penumpang]");
				printf("\n");
				
				index = getIndex();
				
				if(cekKosong(matriks,index)==1){
					do{
						printf("Nama	:");fflush(stdin);gets(nama);
						if(strlen(nama)==0){
							invalid();
							printf("\n");
						}else{
							break;
						}
					}while(1);	
					
					do{
						printf("Id	:");fflush(stdin);gets(id);
						if(strlen(id)!=2 || cekIdSama(matriks,id)==1){
							invalid();
							printf("\n");
						}else{
							break;
						}
					}while(1);
					strcpy(matriks[index.i][index.j].id,id);
					strcpy(matriks[index.i][index.j].nama,nama);
					printf("\n[o]Berhasil Input	[o]");				
				}else{
					printf("\n[!] Nguwawor! Kursi Sudah Terisi	[!]");
				}
				break;
			}
			case 2:{
				printf("\n\t\t[Print All Penumpang]");
				printAll(matriks);
				break;
			}
			case 3:{
				printf("\n\t[Print Khusus]");
				printf("\n");
				
				index = getIndex();
								
				if(cekKosong(matriks,index)==0){
					printKhusus(matriks,index);				
				}else{
					printf("\n[!] Nguwawor! Kursi Masih Kosong	[!]");
				}
				break;
			}
			case 4:{
				printf("\n\t[Pendapatan Gerbong]");
				printf("\n");
				total = cekKeuntungan(matriks);
				printf("\nKursi Terisi		: %d",total);
				printf("\nPendapatan Total	: %d",total*100000);
				break;
			}
			case 5:{
				printf("\n\t[Update Pemesanan Penumpang]");
				printf("\n");
				
				index = getIndex();
				
				if(cekKosong(matriks,index)==0){
					do{
						printf("Nama	:");fflush(stdin);gets(nama);
						if(strlen(nama)==0){
							invalid();
							printf("\n");
						}else{
							break;
						}
					}while(1);	
					
					do{
						printf("Id	:");fflush(stdin);gets(id);
						if(strlen(id)!=2){
							invalid();
							printf("\n");
						}else{
							break;
						}
					}while(1);
					strcpy(matriks[index.i][index.j].id,id);
					strcpy(matriks[index.i][index.j].nama,nama);
					printf("\n[o]Berhasil Input	[o]");				
				}else{
					printf("\n[!] Nguwawor! Kursi Masih Kosong	[!]");
				}
				break;
			}
			case 6:{
				printf("\n\t[Batalkan Pemesanan]");
				printf("\n");
				
				index = getIndex();
				
				if(cekKosong(matriks,index)==0){
					printKhusus(matriks,index);
					printf("\nYakin Ingin Batalkan Pesanan	[Y|T]");fflush(stdin);gets(confirm);
					if(strcmpi(confirm,"y")==0){
						strcpy(matriks[index.i][index.j].id,"-");
						strcpy(matriks[index.i][index.j].nama,"-");
						printf("\n[o] Berhasil Batalkan Pesanan	[o]");
					}else{
						printf("\n[o] Tidak Jadi Batalkan Pesanan	[o]");
					}
				}else{
					printf("\n[!] Nguwawor! Kursi Masih Kosong	[!]");
				}
				break;
			}
			case 0:{
				printf("[Good BYE]");
				break;
			}
			default :{
				printf("\n[!] Nguwawor! Menu Belum Ada	[!]");
				break;
			}
		}	
		getch();
	}while(menu!=0);
	//printf("\n");
	return 0;
}
