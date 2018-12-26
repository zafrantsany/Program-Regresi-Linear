#include <stdio.h>
#include "regresi3.h"
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
//#include "calculator.h"


void printd(char* x, int y);
void gotoxy(int x, int y); 
void salah(); 

void printd(char* x, int y){
	int i;
	for(i=0;i<strlen(x);i++)
	{
		printf("%c",x[i]);
		Sleep(y);
	}
}

void pembuka(){
	system("color 11");
	Sleep(50);  
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                            "); 
	printd("	REGRESI LINIER V5.3", 60);
	Sleep(1850);  
}

void penutup(){
	system("color 11");
	Sleep(50); 
	printf("\n\n\n\n\n\n\n\n\n\n"); 
	printf("                            "); 
	printd("Terima kasih telah menggunakan aplikasi kami\n", 60); 
	Sleep(2000); 
}

typedef struct calculate
{
    float total;
    float number1, number2;
} calculate;

calculate add(calculate n1, calculate n2)
{
	calculate hasil; 
    hasil.number1= n1.number1 + n1.number2;
    hasil.number2= n2.number1 + n2.number2;
    hasil.total=hasil.number1+hasil.number2; 
    return(hasil);
}

calculate sub(calculate n1,calculate n2){

	calculate hasil; 
    hasil.number1= n1.number1 - n1.number2;
    hasil.number2= n2.number1 - n2.number2;
    hasil.total=hasil.number1 - hasil.number2; 
    return(hasil);	
}

calculate bagi(calculate n1,calculate n2){

	calculate hasil; 
    hasil.number1= n1.number1 / n1.number2;
    hasil.number2= n2.number1 / n2.number2;
    hasil.total=hasil.number1 / hasil.number2; 
    return(hasil);	
}

calculate time(calculate n1,calculate n2){

	calculate hasil; 
    hasil.number1= n1.number1 * n1.number2;
    hasil.number2= n2.number1 * n2.number2;
    hasil.total=hasil.number1 * hasil.number2; 
    return(hasil);	
}

void hasil_total()
{
    calculate n1, n2, hasil;
	
    printf("For 1st number \n");
    printf("Enter 2nd numberber:\n");
    scanf("%f %f", &n1.number1, &n1.number2);

    printf("\nFor 3rd number \n");
    printf("Enter 4rd number:\n");
    scanf("%f %f", &n2.number1, &n2.number2);
	
	printf("__________________________________________________________________________________________\n");
    printf("|#|####################################################################################|#|\n");
    printf("|#|                                   SIMPLE CALCULATOR                                |#|\n");
    printf("|#|------------------------------------------------------------------------------------|#|\n");
    printf("|#| Menu pilihan : 1. Hitung Penjumlahan                                               |#|\n");
    printf("|#|                2. Hitung Pengurangan                                               |#|\n");
    printf("|#|                3. Hitung Pembagian                                                 |#|\n");
    printf("|#|                4. Hitung Perkalian                                                 |#|\n");
    printf("|#|                                                                                    |#|\n");
    printf("|#|                5. Keluar                                                           |#|\n");
    printf("|#|____________________________________________________________________________________|#|\n");
    printf("|#|####################################################################################|#|\n");

	switch(getch())
	{
		case '1' :
			hasil = add(n1, n2);
			printf("__________________________________________________________________________________________\n");
    		printf("|#|####################################################################################|#|\n");
    		printf("|#| TOTAL  = %.1f + %1.f= %1.f\n", hasil.number1, hasil.number2, hasil.total,          "|#|\n");
    		printf("|#|------------------------------------------------------------------------------------|#|\n");
    		//Sleep(2850); 
			system("PAUSE"); 
    		menu(); 
			break;
		case '2':
			hasil = sub(n1, n2);
			printf("__________________________________________________________________________________________\n");
    		printf("|#|####################################################################################|#|\n");
    		printf("|#| TOTAL  = %.1f - %1.f= %1.f\n", hasil.number1, hasil.number2, hasil.total,          "|#|\n");
    		printf("|#|------------------------------------------------------------------------------------|#|\n");
    		system("PAUSE"); 
			menu(); 
			break;
		case '3':
			hasil = bagi(n1, n2);
			printf("__________________________________________________________________________________________\n");
    		printf("|#|####################################################################################|#|\n");
    		printf("|#| TOTAL  = %.1f - %1.f= %1.f\n", hasil.number1, hasil.number2, hasil.total,          "|#|\n");
    		printf("|#|------------------------------------------------------------------------------------|#|\n");
    		system("PAUSE"); 
			menu(); 
			break;
		case '4':
			hasil = time(n1, n2);
			printf("__________________________________________________________________________________________\n");
    		printf("|#|####################################################################################|#|\n");
    		printf("|#| TOTAL  = %.1f x %1.f= %1.f\n", hasil.number1, hasil.number2, hasil.total,          "|#|\n");
    		printf("|#|------------------------------------------------------------------------------------|#|\n");
    		system("PAUSE"); 
			menu(); 
			break;
		case '5' : 
			keluar(); 
			break; 
		default:
			MessageBox(0, "Inputan Salah!", "ERROR", MB_ICONEXCLAMATION); 
			menu(); 
            break;
	}
	system("pause");
}

regresi() // modular perhitungan regresi linier
{
	system("cls"); 
	regresi1();
	/*printf("\n    Masukkan pilihan Anda : ");
	system("cls");
	
   switch(getch())
	{
		case '1' :
			regresi1();
			break;
		case '2' : 
			baca_file();
			break; 
		case '3' : 
			menu();
			break; 
		case '4' :
			keluar(); 
			break; 
		default: 
			MessageBox(0, "Inputan Salah!", "ERROR", MB_ICONEXCLAMATION);
			menu(); 
			break;
	}
	system("pause");*/
}

cal()
{
	system("cls"); 
	hasil_total();	
}

keluar() // modular keluar
{
		system("cls"); 
		penutup(); 
}

void help() // modular menu bantuan
{
		printf("\n ________________________________________________________________________________________ \n");
		printf("|#|                     PROGRAM REGRESI LINIER DATA HASIL PRAKTIKUM                    |#|\n");
		printf("|#|________________________FAKULTAS TEKNIK UNIVERSITAS INDONESIA_______________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		printf("|#|-----------------------------------MENU BANTUAN-------------------------------------|#|\n");
		printf("|#| Apabila terdapat kesulitan pada saat penggunaan program, silahkan lihat video      |#|\n");
		printf("|#| tutorial yang telah kami buat. Anda dapat mengaksesnya pada link berikut :         |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#|                         >> https://youtu.be/nB5piX839SQ <<                         |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| Atau silahkan ajukan pertanyaan Anda via email berikut :                           |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| - zafrantsany30@gmail.com                                                          |#|\n");
		printf("|#| - luminare.fadil@gmail.com                                                         |#|\n");
		printf("|#| - fajarmill21@gmail.com                                                            |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| Tekan enter untuk lanjut..                                                         |#|\n");
		printf("|#|____________________________________________________________________________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		system("PAUSE");
		system("cls");  
		menu(); 
}

void ket(){
		printf("\n ________________________________________________________________________________________ \n");
		printf("|#|                      PROGRAM REGRESI LINIER DATA HASIL PRAKTIKUM                   |#|\n");
		printf("|#|________________________FAKULTAS TEKNIK UNIVERSITAS INDONESIA_______________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| NAMA : 1. ZAFRAN HIBATULLAH TSANY          ( 1706986082 )                          |#|\n");
		printf("|#|        2. MUHAMAD FADIL                    ( 1706042812 )                          |#|\n");
		printf("|#|        3. MUHAMMAD FAJAR MILLEANO MUFIANTO ( 1706043014 )                          |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#|------------------------------------------------------------------------------------|#|\n");
		printf("|#| PETUNJUK PEMAKAIAN : 1. Ketikkan angka sesuai opsi pilihan                         |#|\n");
		printf("|#|                      2. Tekan enter                                                |#|\n");
		printf("|#|------------------------------------------------------------------------------------|#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| Tekan enter untuk lanjut..                                                         |#|\n");
		printf("|#|____________________________________________________________________________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		system("PAUSE");
		system("cls");  
		menu(); 
}

void menu() // Menu Utama
{
		system("cls"); 
		system("color 17");
		printf(" ________________________________________________________________________________________ \n");
		printf("|#|                      PROGRAM REGRESI LINIER DATA HASIL PRAKTIKUM                   |#|\n");
		printf("|#|________________________FAKULTAS TEKNIK UNIVERSITAS INDONESIA_______________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		printf("|#| Pilih pilihan Anda :                                                               |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#|   1. Hitung Regresi Linier                                                         |#|\n");
		printf("|#|   2. Calculator                                                                    |#|\n");
		printf("|#|   3. Menu Bantuan                                                                  |#|\n");
		printf("|#|   4. Tentang Aplikasi                                                              |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#|   5. Keluar                                                                        |#|\n");
		printf("|#|____________________________________________________________________________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		printf("\n    Masukkan pilihan Anda : ");
	
	
		switch(getch())
		{		
			case '1' :
				regresi();
				break;
			case '2' :
				cal();
				break;
			case '3' :
				help();
				break;
			case '4' :
				ket();
				break;
			case '5' : 
				keluar(); 
				break; 
			default:
				MessageBox(0, "Inputan Salah!", "ERROR", MB_ICONEXCLAMATION);
				menu();
				break; 
		}
		
	system("PAUSE");
	system("cls"); 
}

int main(){
	pembuka();
	menu();  
}

void gotoxy(int x, int y)
{
 
 COORD coord;
 
 coord.X = x;
 
 coord.Y = y;
 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
}

salah() // modular pesan kesalahan input oleh pengguna
{
		printf(" ________________________________________________________________________________________ \n");
		printf("|#|        PROGRAM REGRESI LINIER DATA HASIL PRAKTIKUM FISIKA MEKANIKA DAN PANAS       |#|\n");
		printf("|#|________________________FAKULTAS TEKNIK UNIVERSITAS INDONESIA_______________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		printf("|#|-----------------------------------PESAN KESALAHAN----------------------------------|#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| Maaf, Sepertinya input yang Anda masukkan salah..                                  |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| Silahkan ikuti perintah yang tertera pada menu utama. Pastikan pula input yang     |#|\n");
		printf("|#| Anda masukkan adalah berupa angka yang tertera pada pilihan dan bukan huruf.       |#|\n");
		printf("|#|                                                                                    |#|\n");	
		printf("|#| Apabila terdapat kesulitan pada saat penggunaan program, silahkan lihat video      |#|\n");
		printf("|#| tutorial yang telah kami buat. Anda dapat mengaksesnya pada link berikut :         |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#|                         >> https://youtu.be/nB5piX839SQ <<                         |#|\n");
		printf("|#|                                                                                    |#|\n");
		printf("|#| Untuk melanjutkan silahkan tekan Enter..                                           |#|\n");
		printf("|#|____________________________________________________________________________________|#|\n");
		printf("|#|####################################################################################|#|\n");
		
		
		system("pause");
		system("cls");
		
}
