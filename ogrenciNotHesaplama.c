#include <stdio.h>
#include <stdlib.h>
#define    NOT     60 ///GECME NOTU


typedef struct Ders
{
    int DKod;
    int vize,finaln;
    float ort;
    int durum;
}D;


typedef struct Ogrenci
{
    int ogrenciNo;
    char ad[20];
    int DSayisi;
    D *Dersler;
}Ogr;


Ogr *bilgi_al(int OgrSayisi);

void ort_hesapla(Ogr *Ogrenciler, int OgrSayisi);

void yazdir(Ogr *Ogrenciler, int OgrSayisi);

int main()
{
    int sayi = 0;
    Ogr *ptr;
    printf("Kac ogrenci girmek istiyorsunuz.\n");
    scanf("%d",&sayi);
    ptr = bilgi_al(sayi);
    ort_hesapla(ptr, sayi);
    yazdir(ptr, sayi);
    return 0;
}


Ogr * bilgi_al(int OgrSayisi)
{
    int ders_sayisi, i, j;
    Ogr *ogr_bilgi = (Ogr *) malloc(sizeof(Ogr) * OgrSayisi);

    for(i = 0; i < OgrSayisi; i++)
    {
        printf("%d.Ogrenci No: ",i+1);
        scanf("%d",&(ogr_bilgi+i)->ogrenciNo);

        printf("%d.Ogrenci Adi: ",i+1);
        scanf("%s",(ogr_bilgi+i)->ad);

        printf("%d.Ogrenci Ders Sayisi: ",i+1);
        scanf("%d",&ders_sayisi);

        (ogr_bilgi+i)->DSayisi = ders_sayisi;
        (ogr_bilgi+i)->Dersler = (D *) malloc(sizeof(D) * ders_sayisi);

        for(j = 0; j < ders_sayisi; j++)
        {
           printf("%d. Ogrenci icin %d. ders kodu: ",i+1,j+1);
           scanf("%d",&((ogr_bilgi+i)->Dersler+j)->DKod);

           printf("%d. Ogrenci icin %d. vize notu: ",i+1,j+1);
           scanf("%d",&((ogr_bilgi+i)->Dersler+j)->vize);

           printf("%d. Ogrenci icin %d. final notu: ",i+1,j+1);
           scanf("%d",&((ogr_bilgi+i)->Dersler+j)->finaln);
        }
    }
    return ogr_bilgi;
}


void ort_hesapla(Ogr *Ogrenciler, int OgrSayisi)
{
    int i, j, ders_sayisi;
    float ortalama;
    for(i = 0; i < OgrSayisi; i++)
    {
        ders_sayisi = (Ogrenciler + i)->DSayisi;
        for(j = 0; j < ders_sayisi; j++)
        {
            ortalama = (float)((Ogrenciler+i)->Dersler+j)->vize * 0.4 + (float)((Ogrenciler+i)->Dersler+j)->finaln * 0.6 ;
            ((Ogrenciler+i)->Dersler+j)->ort = ortalama;
            if(ortalama >= NOT)
                ((Ogrenciler+i)->Dersler+j)->durum = 1;
            else
                ((Ogrenciler+i)->Dersler+j)->durum = 0;
        }
    }
}


void yazdir(Ogr *Ogrenciler, int OgrSayisi)
{
    int i, j, ders_sayisi;
    for(i = 0; i < OgrSayisi; i++)
    {
        ders_sayisi = (Ogrenciler+i)->DSayisi;
        for(j = 0; j < ders_sayisi; j++)
        {
            printf("Ogrenci No: %d, Ders Kodu: %d, Ortalama: %.2f, Durum: %d\n",
                   (Ogrenciler+i)->ogrenciNo,((Ogrenciler+i)->Dersler+j)->DKod,
                   ((Ogrenciler+i)->Dersler+j)->ort,((Ogrenciler+i)->Dersler+j)->durum);
        }
    }
}
