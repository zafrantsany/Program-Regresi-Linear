#include <stdio.h> 
#include <float.h>
#include <math.h>
#define LEN 256
#define MAXCHAR 1000
#include <windows.h>

void baca_file()
{
	FILE *fp;
    char str[MAXCHAR];
    char* filename = "hasil.doc";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1; // untuk kendala syntax atau text yang error
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    
    printf("\n   >> Hasil regresi linier berhasil dicetak, silahkan buka file hasil.doc \n\n");
    return 0;
}

regresi1()

{
	int n,i,j,dummyx,dummyy,sy1; // n adalah banyak data, i adalah variabel bebas
	float jumlah = 0, hasil=0;
    float meanx, meany, medianx=0, mediany=0;
	double a,b,p1,q1,p2,q2,r,s1,s2,t1; 
	double sy12; // sy12 adalah komponen pengolahan delta y
	double syy; // syy adalah delta y kuadrat
	double sy; // sy adalah delta y
	double sy2, sy3, sy4, sy5; // sy2, sy3, sy4, sy5 adalah komponen pengolahan delta y
	double sya, syb, syc; // sya, syb, syc adalah komponen pengolahan delta y
    double sb, sb1, sb2, sb3; // sb, sb1, sb2, sb3 adalah komponen pengolahan delta b
    double kesalahan, bagi; // kesalahan adalah kesalahan relatif, bagi adalah hasil pembagian perhitungan
    
    
    

// tampilan menu perhitungan regresi

	printf(" ________________________________________________________________________________________ \n");
	printf("|#|                    PROGRAM REGRESI LINIER DATA HASIL PRAKTIKUM                     |#|\n");
	printf("|#|________________________FAKULTAS TEKNIK UNIVERSITAS INDONESIA_______________________|#|\n");
	printf("|#|####################################################################################|#|\n");
	printf("|#|                                                                                    |#|\n");
	printf("|#|    Regresi  linear  adalah  alat statistik yang  dipergunakan untuk  mengetahui    |#|\n");
	printf("|#| pengaruh antara satu atau beberapa variabel terhadap satu buah variabel. Variabel  |#|\n");
	printf("|#| yang mempengaruhi sering disebut variabel bebas, variabel independen atau variabel |#|\n");
	printf("|#| penjelas. Variabel yang  dipengaruhi sering disebut dengan variabel  terikat atau  |#|\n");
	printf("|#| variabel dependen.                                                                 |#|\n");
	printf("|#|                                                                                    |#|\n");
	printf("|#|      Analisis  regresi linear sederhana dipergunakan  untuk mengetahui pengaruh    |#|\n");
	printf("|#| antara satu  buah variabel bebas terhadap satu  buah variabel  terikat. Persamaan  |#|\n");
	printf("|#| umumnya adalah :                                                                   |#|\n");
	printf("|#|                                                                                    |#|\n");
	printf("|#|      Y = a + bx                                                                    |#|\n");
	printf("|#|                                                                                    |#|\n");
	printf("|#|____________________________________________________________________________________|#|\n");
	printf("|#|####################################################################################|#|\n");  
	printf("\n\n");
    printf("\tMasukkan banyak data :  ");
    scanf ("%d",&n);
    
   
    
    float datax[n];
    float datay[n];
    float dataxy[n];
    
    double sigmax = 0;
    double sigmay = 0;
    double sigmaxy = 0;
    double sigmaxkuadrat = 0;
    double sigmaykuadrat = 0;
    double sigmaxdikuadratkan;
    double sigmaydikuadratkan;
    double sigmaxydikuadratkan;
    
    for (i=1;i<=n;i++)
    {
    
    	printf ("\n\tMasukkan nilai x ke-%d: ",i);
        scanf("%f",&datax[i]);
        
        printf("\tMasukkan nilai y ke-%d: ",i);
        scanf("%f",&datay[i]);
	}
	
	
	
	for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (datax[i] > datax[j])
            {
                dummyx = datax[i];
                datax[i] = datax[j];
                datax[j] = dummyx;
                
            }
            
        }
    }
    
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (datay[i] > datay[j])
            {
                dummyy = datay[i];
                datay[i] = datay[j];
                datay[j] = dummyy;
                
            }
            
        }
    }
    
    

    for (i=1;i<=n;i++) // Perulangan untuk menginput data percobaan praktikan
    {
        
        dataxy[i] = datax[i] * datay[i];
        
        sigmaxy = sigmaxy + dataxy[i];
    
        sigmax = sigmax + datax[i];
        sigmay = sigmay + datay[i];
    
        sigmaxdikuadratkan = sigmax * sigmax;
        sigmaydikuadratkan = sigmay * sigmay;
        sigmaxydikuadratkan = sigmaxy * sigmaxy;
        
    }
    
    FILE * out;
    out=fopen("hasil.doc","w+");
    
    fprintf(out, "\n");
    
    fprintf(out, "\n  Mengurutkan data x :\n");
    for (i = 1; i <= n; ++i)
    {
        fprintf(out, "  %.2f ", datax[i]);
        
        jumlah = jumlah + datax[i];
    }
    
    fprintf(out, "\n");
  
  	meanx = jumlah / n;
   	fprintf(out, "\n  Mean : %.2f", meanx);
    
    
    fprintf(out, "\n\n  Mengurutkan data y :\n");
    for (i = 1; i <= n; ++i)
    {
        fprintf(out, "  %.2f ", datay[i]);
        
        hasil = hasil + datay[i];
    }
    
    fprintf(out, "\n");
  
  	meany = hasil / n;
   	fprintf(out, "\n  Mean : %.2f", meany);
    
    // penampilan tabel data hasil praktikum
    
    
	fprintf(out, "\n\n\n");
      
    fprintf(out, "__________________________________________________________________________________________\n");
    fprintf(out, "##########################################################################################\n");
	fprintf(out, "                       PROGRAM REGRESI LINIER DATA HASIL PRAKTIKUM                        \n");
	fprintf(out, "___________________________FAKULTAS TEKNIK UNIVERSITAS INDONESIA__________________________\n");
    fprintf(out, "##########################################################################################\n");
	fprintf(out, "\n\n\n \t x\t\t y\t      x kuadrat\t      y kuadrat\t\t xy\n");  
    
    

    //pengulangan untuk membuat tabel data hasil praktikum
    
    for(i=1;i<=n;i++)
	{
      fprintf(out, "\n\t%.2f", datax[i]);
      datax[i] = datax[i] * datax[i];
      
      sigmaxkuadrat = sigmaxkuadrat + datax[i];
      
      fprintf(out, "\t\t%.2f", datay[i]);
      datay[i] = datay[i] * datay[i];
      
      sigmaykuadrat = sigmaykuadrat + datay[i];
      
      fprintf(out, "\t\t%.2f", datax[i]);
      
      fprintf(out, "\t\t%.2f", datay[i]);
      
      fprintf(out, "\t\t%.2f\n", dataxy[i]);
    }  
    
   fprintf(out, "\n\n\n");
   
   fprintf(out, "__________________________________________________________________________________________\n");
   fprintf(out, "##########################################################################################\n");
   
    
    
   fprintf(out, "\n\n  Sigma x : %.2f", sigmax);
   fprintf(out, "\n  Sigma y : %.2f", sigmay);
   
   
   fprintf(out, "\n\n  Sigma x kuadrat : %.2f", sigmaxkuadrat);
   fprintf(out, "\n  Sigma y kuadrat : %.2f", sigmaykuadrat);
   
   fprintf(out, "\n\n  Sigma xy : %.2f", sigmaxy);
   
   
   fprintf(out, "\n\n  Sigma x dikuadratkan : %.2f", sigmaxdikuadratkan);
   fprintf(out, "\n  Sigma y dikuadratkan : %.2f", sigmaydikuadratkan);
   fprintf(out, "\n  Sigma xy dikuadratkan : %.2f", sigmaxydikuadratkan);
   
   fprintf(out, "\n\n\n");
   
   p1 = sigmay * sigmaxkuadrat;
   q1 = sigmax * sigmaxy;
   p2 = n * sigmaxy;
   q2 = sigmax * sigmay;
   r  = n * sigmaxkuadrat;
   
   s1 = p1 - q1;
   s2 = p2 - q2;
   t1 = r - sigmaxdikuadratkan;
   
   a = ( p1 - q1) /  t1;

   b = ( p2 - q2 ) / t1;
   
   sy1 = (n - 2);
   sy12 = pow(sy1, -1);
   sy2 = sigmaxkuadrat * sigmaydikuadratkan;
   sy3 = 2 * sigmax * sigmay * sigmaxy;
   sy4 = n * sigmaxydikuadratkan;
   sy5 = n * sigmaxkuadrat;
   
   
   sya = sy2 + sy4 - sy3;
   syb = sy5 - sigmaxdikuadratkan;
   syc = sya / syb;
   
   
   syy = sy12 * sigmaxkuadrat * syc;
   
   sy  = sqrt(syy);
   
   
   fprintf(out, "\n\t       (sigma y * sigma x kuadrat - sigma x * sigma xy)\n");
   fprintf(out, ">> Nilai a  = --------------------------------------------------\n");  
   fprintf(out, "\t        (n * sigma x kuadrat - sigma x dikuadratkan) \n"); 
    
   fprintf(out, "\n\n\n\t        (%.2f * %.2f - %.2f * %.2f)\n", sigmay, sigmaxkuadrat, sigmax, sigmaxy);
   fprintf(out, "\t    = --------------------------------------------\n");  
   fprintf(out, "\t             (%d * %.2f  - %.2f) \n", n, sigmaxkuadrat, sigmaxdikuadratkan);  
   
   fprintf(out, "\n\n\n\t\t   (%.2f - %.2f)\n", p1, q1);
   fprintf(out, "\t    = -----------------------------------\n");  
   fprintf(out, "\t\t    (%.2f - %.2f) \n", r, sigmaxdikuadratkan); 
   
   fprintf(out, "\n\n\n\t        %.2f\n", s1); 
   fprintf(out, "\t    = ------------\n");
   fprintf(out, "\t        %.2f \n", t1);
   
   fprintf(out, "\n\n\n\t    = %.2f", a);
   	
   fprintf(out, "\n\n\n\n\t            (n * sigma xy - sigma x * sigma y)\n");
   fprintf(out, ">> Nilai b = --------------------------------------------------\n");  
   fprintf(out, "\t        (n * sigma x kuadrat - sigma x dikuadratkan) \n");   
   
   fprintf(out, "\n\n\n\t        (%d * %.2f - %.2f * %.2f)\n", n, sigmaxy, sigmax, sigmay);
   fprintf(out, "\t    = --------------------------------------------\n");  
   fprintf(out, "\t             (%d * %.2f  - %.2f) \n", n, sigmaxkuadrat, sigmaxdikuadratkan);  
   
   fprintf(out, "\n\n\n\t\t   (%.2f - %.2f)\n", p2, q2);
   fprintf(out, "\t    = -----------------------------------\n");  
   fprintf(out, "\t\t    (%.2f - %.2f) \n", r, sigmaxdikuadratkan); 
   
   fprintf(out, "\n\n\n\t        %.2f\n", s2); 
   fprintf(out, "\t    = ------------\n");
   fprintf(out, "\t        %.2f \n", t1);
   
   fprintf(out, "\n\n\n\t    = %.2f", b);
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, ">> Persamaan regresi linier : \n");
   fprintf(out, "\n\n\t   Y = a + bx");
   fprintf(out, "\n\n\t   Y = (%.2f) + (%.2f)x\n\n", a, b);
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, ">> Nilai Delta Y :");
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "                     1                     ( sigmaxkuadrat * sigmaydikuadratkan - 2 * sigmax * sigmay * sigmaxy + n * sigmaxydikuadratkan )  \n");
   fprintf(out, "        Delta Y^2 = --- * sigmaxkuadrat * -------------------------------------------------------------------------------------------------- \n");
   fprintf(out, "                    n-2                                              ((n * sigmaxkuadrat) - sigmaxdikuadratkan )                             \n");
   
   fprintf(out, "\n\n\n"); 
   
   fprintf(out, "                     1                      (%.2f - %.2f + %.2f)  \n", sy2, sy3, sy4);
   fprintf(out, "        Delta Y^2 = --- * %.2f * ------------------------------------------------------------- \n", sigmaxkuadrat);
   fprintf(out, "                     %d                              (%.2f - %.2f)                             \n", sy1, sy5, sigmaxdikuadratkan);
   
   fprintf(out, "\n\n\n");
    
   fprintf(out, "                                       %.2f \n", sya);
   fprintf(out, "        Delta Y^2 = %.2f * %.2f * --------------\n", sy12, sigmaxkuadrat);
   fprintf(out, "                                       %.2f \n", syb);
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "        Delta Y^2 = %.2f * %.2f * %.2f", sy12, sigmaxkuadrat, syc);
   
   fprintf(out, "\n\n\n\n");
   
   fprintf(out, "        Delta Y^2 = %.2f", syy);
   
   fprintf(out, "\n\n\n\n");
    
   fprintf(out, "        Delta Y   = %.2f", sy);

   sb1 = sy5 - sigmaxdikuadratkan;
   sb2 = n / sb1;
   sb3 = sqrt(sb2);
   sb  = sy * sb3;
   
   fprintf(out, "\n\n\n\n\n");
   
   fprintf(out, ">> Nilai Delta b :");
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "                                                    n                     \n");
   fprintf(out, "        Delta b = delta y * akar ----------------------------------------\n");
   fprintf(out, "                                  n * sigmaxkuadrat - sigmaxdikuadratkan     \n");
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "                                             %d           \n", n);
   fprintf(out, "                = %.2f * akar ------------------------- \n", sy);
   fprintf(out, "                                   %d * %.2f - %.2f   \n", n, sigmaxkuadrat, sigmaxdikuadratkan);
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "                                      %d    \n", n);
   fprintf(out, "                = %.2f * akar ----------- \n", sy);
   fprintf(out, "                                   %.2f    \n", sb1);
   
   fprintf(out, "\n\n\n\n");
   
   fprintf(out, "                = %.2f * akar ( %f ) \n", sy, sb2);
   
   fprintf(out, "\n\n\n\n");
   
   fprintf(out, "                = %.2f *  %.2f  \n", sy, sb3);
  
   fprintf(out, "\n\n\n\n");
   
   fprintf(out, "                = %.2f \n", sb);
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "      Pelaporan = ( b +- delta b)\n\n");
   fprintf(out, "                = ( %.2f +- %.2f)", b, sb);
   
   bagi = sb / b;
   kesalahan = bagi / 100;
   
   fprintf(out, "\n\n\n\n");
   
   fprintf(out, "                        delta b         \n");
   fprintf(out, ">> Kesalahan relatif = --------- * 100 persen \n");
   fprintf(out, "                           b            \n");
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "                         %.2f      \n", sb);
   fprintf(out, "                      = --------- * 100 persen \n" );
   fprintf(out, "                          %.2f      \n", b );
   
   fprintf(out, "\n\n\n");
   
   fprintf(out, "                      = %f * 100 persen \n", bagi);
   
   fprintf(out, "\n\n\n"); 
   
   fprintf(out, "                      = %.2f persen\n", kesalahan);
   
   fprintf(out, "\n\n\n");
   
   fclose(out);
   

   
   // menu selanjutnya setelah pengolahan data
   
   printf("\n Perhitungan berhasil disimpan..\n");
   printf("__________________________________________________________________________________________\n");
   printf("|#|####################################################################################|#|\n");
   printf("|#|------------------------------------------------------------------------------------|#|\n");
   printf("|#| Menu pilihan : 1. Hitung Kembali Regresi Linier                                    |#|\n");
   printf("|#|                2. Print Hasil                                                      |#|\n");
   printf("|#|                3. Menu utama                                                       |#|\n");
   printf("|#|                                                                                    |#|\n");
   printf("|#|                4. Keluar                                                           |#|\n");
   printf("|#|____________________________________________________________________________________|#|\n");
   printf("|#|####################################################################################|#|\n");
   
   switch(getch())
	{
		case '1' :
			regresi1();
			break;
		case '2' : 
			baca_file();
			system ("PAUSE");
			menu(); 
			break; 
		case '3' : 
			menu();
			break; 
		default: 
			MessageBox(0, "Inputan Salah!", "ERROR", MB_ICONEXCLAMATION);
			menu(); 
			break;
	}
	system("pause");

}
