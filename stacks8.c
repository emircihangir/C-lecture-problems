#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    char isim[50];
    char yazar[50];
    int yil;
}Kitap;

#define N 10
Kitap stack[N];
int stackTop = -1;

void push(Kitap item){
    if(stackTop == N-1){
        printf("Stack is full. Cannot add %s", item.isim);
        return;
    }

    stack[++stackTop] = item;
}
void pop(){
    if(stackTop == -1){
        printf("Stack is empty. Cannot pop any further.");
        return;
    }
    
    stackTop-=1;
}

void kitapEkle(){
    char isim[50];
    char yazar[50];
    int yil;
    
    printf("kitap ismini giriniz: "); scanf("%s", isim);
    printf("yazar ismini giriniz: "); scanf("%s", yazar);
    printf("yıl giriniz: "); scanf("%d", &yil);

    Kitap yeniKitap;
    strcpy(yeniKitap.isim, isim);
    strcpy(yeniKitap.yazar, yazar);
    yeniKitap.yil = yil;

    push(yeniKitap);
}

void kitapListele(){
    printf("isim \t yazar \t yıl \n");
    for (int i = 0; i <= stackTop; i++)
    {
        printf("%s \t %s \t %d \n", stack[i].isim, stack[i].yazar, stack[i].yil);
    }
}

void kitapCikar(){
    if(stackTop == -1){
        printf("Kitap listesi boş, çıkarma yapılamaz. \n");
        return;
    }

    stackTop -= 1;
}

void ustKitapYazdir(){
    printf("isim \t yazar \t yıl \n");
    printf("%s \t %s \t %d \n", stack[stackTop].isim, stack[stackTop].yazar, stack[stackTop].yil);
}

void toplamKitapYazdir(){
    printf("Toplam kitap sayısı: %d \n", (stackTop + 1));
}

int main(){
    while(1){
        printf("İşlem seçiniz: \n");
        printf("1 - Kitap ekleme \n");
        printf("2 - Kitap çıkarma \n");
        printf("3 - Kitapları listeleme \n");
        printf("4 - En üsttteki kitabı yazdırma \n");
        printf("5 - Toplam kitap sayısını yazdırma \n");
        printf("6 - Çıkış \n");
        printf("> ");
        int input; 
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                kitapEkle();
                break;

            case 2:
                kitapCikar();
                break;

            case 3:
                kitapListele();
                break;
        
            case 4:
                ustKitapYazdir();
                break;
            
            case 5:
                toplamKitapYazdir();
                break;

            case 6:
                return 0;
        
            default:
                printf("Geçersiz girdi.\n");
                break;
        }
    }
    
    printf("\n");
    return 0;
}