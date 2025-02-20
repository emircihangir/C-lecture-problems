#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int yil, ay, gun;
}tarih;


typedef struct{
    char isim[100];
    float maas;
    tarih dogumTarihi;
}personel;

int main(){

    // Problem 4
    personel personeller[5];
    for(int i = 0; i < 5; i++){
        personel p;
        printf("%d. personelin ismi: ", (i + 1)); scanf("%s", p.isim);
        printf("%d. personelin maaşı: ", (i + 1)); scanf("%f", &p.maas);
        printf("%d. personelin doğum tarihi (yıl, ay, gün): ", (i + 1)); scanf("%d.%d.%d", &p.dogumTarihi.yil, &p.dogumTarihi.ay, &p.dogumTarihi.gun);
        personeller[i] = p;
    }
    printf("isim\tmaaş\tdoğum tarihi\n");
    for(int i = 0; i < 5; i++){
        personel p = personeller[i];
        printf("%s\t%f\t%d.%d.%d \n", p.isim, p.maas, p.dogumTarihi.yil, p.dogumTarihi.ay, p.dogumTarihi.gun);
    }
    printf("\n");
    return 0;
}