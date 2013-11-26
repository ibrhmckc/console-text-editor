#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Liste_Elemani{
    int Karakter;
    Liste_Elemani* Onceki;
    Liste_Elemani* Sonraki;

};

class Metin{
public:
    Liste_Elemani *Baslangic,*Son,*Kullanimda;
void Ekle(int Giris){


    if(Baslangic->Onceki==NULL){
        //henuz giris yapilmamissa
        Liste_Elemani* Yeni = new Liste_Elemani;
        Yeni->Karakter=Giris;

        Baslangic=Yeni;
        Son=Baslangic;
        Kullanimda=Son;
    }else{
        //kullanimdaki listenin sonundami
        if(Kullanimda->Sonraki==NULL){
            Liste_Elemani* Yeni = new Liste_Elemani;
            Yeni->Karakter=Giris;

            Son->Sonraki=Yeni;
            Yeni->Onceki=Son;
            Son=Yeni;
            Kullanimda=Son;

        }else{
            //liste sonundaki degilse araya ekleme
            Liste_Elemani* Yeni = new Liste_Elemani;
            Yeni->Karakter=Giris;

            Liste_Elemani* Sonraki=Kullanimda->Sonraki;

            Yeni->Onceki=Kullanimda;
            Yeni->Sonraki=Sonraki;

            Sonraki->Onceki=Yeni;
            Kullanimda->Sonraki=Yeni;
        }
    }
}
void degistir(int Giris){
    //listede giris yapilmissa degistir
    if(Baslangic!=NULL){
        Kullanimda->Karakter=Giris;
    }
}

void sil(){
    //listede giris yapilmissa degistir
    if(Baslangic!=NULL){
        Liste_Elemani* Sonra = Kullanimda->Sonraki;
        Liste_Elemani*Once = Kullanimda->Onceki;

        Once->Sonraki=Sonra;
        Sonra->Onceki=Once;

        Kullanimda=Once;
    }
}

int karakter_sayisi(){
    if(Baslangic==NULL){
        return 0;

    }else{
        int Sonuc=1;
        Liste_Elemani* Gecici = Baslangic;
        while(Gecici->Sonraki!=NULL){
            Sonuc++;
            Gecici=Gecici->Sonraki;
        }
        return Sonuc;
    }
}

char[] metni_diziye_cevir(){
    if(Baslangic==NULL){
        return NULL;

    }else{
        char Dizi[karakter_sayisi()];
        int i=0;
        Liste_Elemani* Gecici = Baslangic;

        while(Gecici->Sonraki!=NULL){
            Dizi[i]=(char)Gecici->Karakter;
            i++;
            Gecici=Gecici->Sonraki;
        }
        return Dizi;

    }
}
};

class Dosya{
public:
    Metin Kaydedilecek_Metin;
    Dosya(Metin M){
        Kaydedilecek_Metin = M;
    };

};

class Kontrol{
public:
    Metin Text = new Metin();
    void Klavye_Girisi_Al(){
        /*while(!kbhit()){
            //Klavye giris icin bekle
            int Giris = getch();

        }*/
        BYTE keys[256];

        if(GetKeyboardState(keys))
        {

        //check if A key is pressed
            if((keys[VK_A]&0xF0) && !(prevKeys[VK_A]&0xF0))
            {
                DoAPressed();
            }
            //check if S key is pressed too
            if((keys[VK_S]&0xF0) && !(prevKeys[VK_S]&0xF0))
            {
                DoSPressed();
            }
            // the same goes for all keys you want to check
        }
    }
    void kontrol_mu(char K){
        switch(K){
            //Yon tuslari
            case 24: break;
            case 25: break;
            case 26: break;
            case 27: break;
            // ?
            case 63: break;
            // =
            case 61: break;
        }
    }
};

int main()
{
    system("color 2");
    cout << "------------------------------------------------" << endl;
    Kontrol Editor = new Kontrol();
    Editor.Klavye_Girisi_Al();
    return 0;
}
