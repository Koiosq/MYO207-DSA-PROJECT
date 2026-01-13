#include <stdio.h>

// İsim SOYİSİM      : Kadir Kaynak
// Öğrenci Numarası  : 2420161002
// BTK Akademi Linki : https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=gK2halNG6e

void yer_degistir(int *sayi1, int *sayi2) {
    int gecici = *sayi1;
    *sayi1 = *sayi2;
    *sayi2 = gecici;
}

void yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

void baloncuk_sirala(int dizi[], int BOYUT) {
    int i, j;
    int yer_degis;
    
    for (i = 0; i < BOYUT - 1; i++) {
        yer_degis = 0;
        for (j = 0; j < BOYUT - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                yer_degistir(&dizi[j], &dizi[j + 1]);
                yer_degis = 1;
            }
        }
        if (yer_degis == 0) break;
        
        printf("%d. tur sonucu: ", i + 1);
        yazdir(dizi, BOYUT);
    }
}

int ikili_arama(int dizi[], int bas_indis, int son_indis, int aranan) {
    while (bas_indis <= son_indis) {
        int orta = bas_indis + (son_indis - bas_indis) / 2;

        if (dizi[orta] == aranan)
            return orta;

        if (dizi[orta] < aranan)
            bas_indis = orta + 1;
        else
            son_indis = orta - 1;
    }
    return -1;
}

int main() {
    int A[] = {42, 56, 65, 12, 6, 54, 39, 27, 90, 17, 83, 3};
    int N = sizeof(A) / sizeof(A[0]);
    int aranan_sayi, sonuc;

    printf("Siralanmamis dizi:\n");
    yazdir(A, N);
    
    baloncuk_sirala(A, N);
    
    printf("Siralanmis Sonuc Dizisi:\n");
    yazdir(A, N);

    printf("\nAranan sayiyi giriniz: ");
    if (scanf("%d", &aranan_sayi) == 1) {
        sonuc = ikili_arama(A, 0, N - 1, aranan_sayi);

        if (sonuc != -1)
            printf("Sonuc: %d sayisi %d. indiste bulundu.\n", aranan_sayi, sonuc);
        else
            printf("Sonuc: %d sayisi dizide bulunmadi.\n", aranan_sayi);
    }
    return 0;
}



