#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_UYE 50
#define ISIM_UZUNLUK 30

char isimler[MAX_UYE][ISIM_UZUNLUK];

int uyeBilgileri[MAX_UYE][2]; 

int toplamUye = 0; 
void menuGoster();
void uyeKayit();
void uyeGirisi();
void uyeleriListele();

int main() {
    int secim;

    while (1) {
        menuGoster();
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                uyeKayit();
                break;
            case 2:
                uyeGirisi();
                break;
            case 3:
                uyeleriListele();
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }
    return 0;
}

// --- FONKSÝYONLAR ---

void menuGoster() {
    printf("\n--- SPOR SALONU YONETIM SISTEMI ---\n");
    printf("1. Yeni Uye Kaydi\n");
    printf("2. Uye Girisi (Turnike)\n");
    printf("3. Kayitli Uyeleri Listele\n");
    printf("4. Cikis\n");
    printf("-----------------------------------\n");
}

void uyeKayit() 
{
    if (toplamUye >= MAX_UYE) 
	{
        printf("HATA: Kontenjan dolu, yeni uye eklenemez!\n");
        return;
    }

    int id, gun;
    
    printf("\n--- YENI UYE KAYDI ---\n");
    
    printf("Uye Ismi: ");
    scanf("%s", isimler[toplamUye]); 

    printf("Uye ID Belirleyiniz (Orn: 101): ");
    scanf("%d", &id);
    uyeBilgileri[toplamUye][0] = id;

    printf("Uyelik Suresi (Gun): ");
    scanf("%d", &gun);
    uyeBilgileri[toplamUye][1] = gun;

    printf("Kayit Basarili! %s sisteme eklendi.\n", isimler[toplamUye]);
    
    toplamUye++;
}

void uyeGirisi() 
{
    int girilenID;
    int bulundu = 0;
    
    printf("\n--- UYE GIRISI (TURNIKE) ---\n");
    printf("Lutfen ID numaranizi giriniz: ");
    scanf("%d", &girilenID);

    int i=0;
    for ( i = 0; i < toplamUye; i++) 
	{
        if (uyeBilgileri[i][0] == girilenID) 
		{
            bulundu = 1;
            printf("\nHOÞ GELDÝNÝZ, Sayin %s!\n", isimler[i]);
            
            if (uyeBilgileri[i][1] > 0) 
			{
                printf("Giris Basarili. Kalan Gununuz: %d\n", uyeBilgileri[i][1]);
                printf("Iyi Sporlar!\n");
            
            } 
			else 
			{
                printf("UYARI: Uyelik sureniz dolmus! Lutfen yenileyiniz.\n");
            }
            break;
        }
    }

    if (bulundu == 0) {
        printf("HATA: Bu ID numarasina sahip bir uye bulunamadi!\n");
    }
}

void uyeleriListele() 
{
    printf("\n--- KAYITLI UYELER ---\n");
    printf("ID\tISIM\t\tKALAN GUN\n");
    printf("---\t----\t\t---------\n");

    int i=0;
    for ( i = 0; i < toplamUye; i++) 
	{
        
        printf("%d\t%-10s\t%d\n", 
               uyeBilgileri[i][0],  
               isimler[i],          
               uyeBilgileri[i][1]);
    }
}
