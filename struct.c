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

typedef struct{
    char isim[100];
    float bakiye;
}musteri;

void YasHesapla(tarih t1, tarih bugun){
    int toplamGun = (bugun.yil - t1.yil)*365 + (bugun.ay - t1.ay)*30 + (bugun.gun - t1.gun);
    int yilFark = (int)(toplamGun / 365);
    toplamGun -= yilFark * 365;
    int ayFark = (int)(toplamGun / 30);
    toplamGun -= ayFark * 30;

    tarih s = {yilFark, ayFark, toplamGun};
    printf("%d %d %d", s.yil, s.ay, s.gun);

}

void HesapListele(musteri* musteriler, int N){
    printf("isim\tbakiye\n");
    for (int i = 0; i < N; i++)
    {
        printf("%s\t%f\n", (musteriler + i)->isim, (musteriler + i)->bakiye);
    }
}

int main(){
    // Problem 4
    // personel personeller[5];
    // for(int i = 0; i < 5; i++){
    //     personel p;
    //     printf("%d. personelin ismi: ", (i + 1)); scanf("%s", p.isim);
    //     printf("%d. personelin maaşı: ", (i + 1)); scanf("%f", &p.maas);
    //     printf("%d. personelin doğum tarihi (yıl, ay, gün): ", (i + 1)); scanf("%d.%d.%d", &p.dogumTarihi.yil, &p.dogumTarihi.ay, &p.dogumTarihi.gun);
    //     personeller[i] = p;
    // }
    // printf("isim\tmaaş\tdoğum tarihi\n");
    // for(int i = 0; i < 5; i++){
    //     personel p = personeller[i];
    //     printf("%s\t%f\t%d.%d.%d \n", p.isim, p.maas, p.dogumTarihi.yil, p.dogumTarihi.ay, p.dogumTarihi.gun);
    // }

    // Problem 5
    // tarih* sonuc = (tarih*)malloc(sizeof(tarih) * 1);
    // tarih t, bugun;
    // printf("bugünün tarihini giriniz (yıl.ay.gün): "); scanf("%d.%d.%d", &bugun.yil, &bugun.ay, &bugun.gun);
    // printf("doğum tarihinizi giriniz (yıl.ay.gün): "); scanf("%d.%d.%d", &t.yil, &t.ay, &t.gun);
    // YasHesapla(t, bugun, sonuc);
    // printf("%d yıl %d ay %d gün yaşındasınız.", sonuc->yil, sonuc->ay, sonuc->gun);

    // Problem 7
    int N;
    printf("kaç müşteri gireceksiniz? "); scanf("%d", &N);
    musteri* musteriler = (musteri*)malloc(sizeof(musteri) * N);
    float toplamBakiye = 0;
    for (int i = 0; i < N; i++)
    {
        printf("%d. müşterinin ismini ve bakiyesini giriniz: ", (i + 1));
        scanf("%s", (musteriler + i)->isim);
        float bakiye;
        scanf("%f", &bakiye);
        (musteriler + i)->bakiye = bakiye;
        toplamBakiye += bakiye;
    }
    HesapListele(musteriler, N);
    printf("toplam bakiye: %f", toplamBakiye);

    printf("\n");
    return 0;
}