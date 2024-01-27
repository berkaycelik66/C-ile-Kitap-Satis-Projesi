#include<stdio.h>
#include<string.h>
#include<unistd.h>

int sepet(void);
void kitapgir(void);
int girilenkitaplar(void);
void kat_macera(void);
void kat_dunyaroman(void);
void kat_bilimkurgu(void);
void kat_siir(void);
void kat_turkroman(void);

int sepetsayac=0; //Sepetteki kitap sayisini kontrol edecek
double tutar=0;	//Sepet tutarini kontrol edecek
int gir_kitap_sayi=0; //Kullanici tarafindan girilen kitap sayisini kontrol edecek

struct kitap{ //Kullanicinin girdigi kitaplari kontrol edecek
	char kitap[30];
	char yazar[30];
}k[10];

struct sepet{ //Sepete eklenen kitaplari kontrol edecek
    int barkod;
    double fiyat;
    char kitap[30];
    char yazar[30]; 
    char durum[30];
}s[50];

int main(){
	printf("\n");
	printf("\t\t\t****************************\n");
	printf("\t\t\t********HOSGELDINIZ*********");
	int secim=1;
	while(secim != 0)
	{
		printf("\n\t\t\t****************************\n");
		printf("\t\t\t   1-Aksiyon-Macera\n");
		printf("\t\t\t   2-Dunya Romanlari\n");
		printf("\t\t\t   3-Fantastik-Bilim Kurgu\n");
		printf("\t\t\t   4-Siir Kitaplari\n");
		printf("\t\t\t   5-Turk Romanlari\n");
		printf("\t\t\t   6-Yeni Kitap Ekle\n");
		printf("\t\t\t   7-Eklenilen Kitaplar\n");
		printf("\t\t\t   8-Sepete Git\n");
		printf("\t\t\t   0-Cikis\n");
		printf("\t\t\t****************************\n");
		printf("Seciminizi Yapiniz: ");
		scanf("%d",&secim);
	
		switch(secim) //secimi yapýlan kategoriye gidecek
		{
			case 1: kat_macera(); break;
			case 2: kat_dunyaroman(); break;
			case 3: kat_bilimkurgu(); break;
			case 4: kat_siir(); break;
			case 5: kat_turkroman(); break;
			case 6: kitapgir(); break;
			case 7: girilenkitaplar(); break;
			case 8: sepet(); break;
			case 0:	printf("\n\n\t\tProgram Sonlandiriliyor..........."); break;
			default: secim=0;
			 		printf("\n\n\t\tProgram Sonlandiriliyor...........");
			 		sleep(3);
					break;
		}
	}
	
	return 0;
}

int sepet(){
    
    int i;
    int secim;
    long int sifre;
    int barkodkontrol;
    
    if(sepetsayac==0) //sepetteki ürün sayisi 0 ise geri döndürecek
    {
        printf("\t\t_____Sepetinizde Hic Urun Bulunmamaktadir._____\n");
        sleep(1);
        return 0;
    }
    
    do{
	    printf("\n                  ");
	    printf("Barkod    Kitap Ad            Yazar	            Fiyat   \n");
	    printf("                ");
	    printf("------------------------------------------------------------\n");
	    for(i=0;i<sepetsayac;i++)
	    {
	        printf("                    ");
	        printf("%-4d    ",s[i].barkod);
	        printf("%-20s",s[i].kitap);
	        printf("%-20s",s[i].yazar);
	        printf("%-4.2f",s[i].fiyat);
	        printf("%15s",s[i].durum);
	        printf("\n");
	    }
	    printf("\n\t\tToplam Tutar: %5.2f\n",tutar);
	    sleep(3);
	    
	    printf("1-Sepeti Onayla\n");
	    printf("2-Sepete Kitap Ekle\n");
	    printf("3-Sepetten Kitap Cikar\n");
	    printf("Seciminizi Giriniz: ");
	    scanf("%d",&secim);
    
	    switch(secim){
	        case 1: printf("\nToplam Tutar: %5.2f",tutar);
                    printf("\n*****Odemeniz Yapilmistir.*****\n");
                    sleep(1);
                    printf("*****Bizi Tercih Ettiginiz Icin Tesekkurler.*****\n");
                    sleep(2);
                    tutar=0;
                    sepetsayac=0;
	                break;
	        case 2: return 0; break;
	        case 3: printf("\nCikarmak Istediginiz Kitabin Barkod Numarasini Giriniz: ");
	                scanf("%d",&barkodkontrol);
	                for(i=0;i<sepetsayac;i++)
	                {
	                	if(s[i].barkod==barkodkontrol)
	                    {
	                    	if(strcmp(s[i].durum,"IPTAL EDILDI")!=0){ //ayný ürünün tekrar iptal edilmemesi için yapýldý.
	                        	tutar=tutar-s[i].fiyat;
	                        	strcpy(s[i].durum,"IPTAL EDILDI");
	                        	printf("\n\t\t_____\"%s\" Kitabi Sepetinizden Cikarilmistir._____\n\n",s[i].kitap);
	                        	sleep(1);
	                    	}
	                    	else{
								printf("\n******Sectiginiz Urun Onceden Iptal Edilmistir\n");-
								sleep(1);
							} 
	                	}
	                }
	                break;
	    }
    }while(secim==3);   
}

void kitapgir(void)
{
	char secim;
	do{
		printf("\nKitap Adi: ");
		scanf("	%[^\n]s",k[gir_kitap_sayi].kitap);
		printf("Yazar: ");
		scanf("	%[^\n]s",k[gir_kitap_sayi].yazar);
		printf("\n");
		gir_kitap_sayi++;
		printf("Kitap Ekleme Islemine Devam Etmek Ister Misiniz?(E/H): ");
		scanf(" %c",&secim);
	}while(secim=='E' || secim=='e');
}

int girilenkitaplar(void)
{
	int i;
	int j=0;
	char secim;
	int barkod[10]={7100,7101,7102,7103,7104,7105,7106,7107,7108,7109};
    float puan[10]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float fiyat[10]={100.00,100.00,100.00,100.00,100.00,100.00,100.00,100.00,100.00,100.00};
    int stok[10]={1,1,1,1,1,1,1,1,1,1};
    int barkodgir;
    
    if(gir_kitap_sayi==0) //kitap eklenmediyse programi geri dondurecektir.
    {
    	printf("\n\t\t_____Bu Kategoride Kitap Bulunmamaktadir._____\n\n");
    	return 0;
	}
	
	do{
		printf("\n                  ");
		printf("Barkod    Kitap Ad            Yazar	        Puan    Fiyat   Stok Durumu\n");
		printf("                ");
	    printf("-----------------------------------------------------------------------------\n");
	    
	    for(i=0;i<gir_kitap_sayi;i++){
	        printf("                    ");
	        printf("%-4d    ",barkod[i]);
	        printf("%-20s",k[i].kitap);
	        printf("%-17s",k[i].yazar);
	    	printf("%-2.1f\t",puan[i]);
	      	printf("%-4.2f\t",fiyat[i]);
	    	printf("    %d",stok[i]);
	        printf("\n");
	    }
	    
	    if(j==0){
	    	printf("\nBu kategoriden Alisveris Yapmak Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	j++;
	    }
	    
	    while(secim=='E' || secim=='e'){
	    	printf("\nAlmak Istediginiz Kitabin Barkod Numarasini Giriniz: ");
	    	scanf("%d",&barkodgir);
	    	for(i=0;i<gir_kitap_sayi;i++)
	    	{
	        	if(barkodgir==barkod[i])
	        	{
	        	    if(stok[i]>=1)
	        	    {
	        	        s[sepetsayac].barkod=sepetsayac;
	        	        strcpy(s[sepetsayac].kitap,k[i].kitap);
	        	        strcpy(s[sepetsayac].yazar,k[i].yazar);
	        	        s[sepetsayac].fiyat=fiyat[i];
	        	        sepetsayac++;
	            	    tutar=tutar+fiyat[i];
	            	    stok[i]=stok[i]-1;
	            	    printf("\n\t\t_________\"1\"Adet \"%s\" Kitabi Sepetinize Eklenmistir._________",k[i].kitap);
	            	    sleep(1);
	            	    printf("\nSepet Tutari: %5.2f",tutar);
	            	    sleep(2);
	        	    }
	        		else printf("\n*******Elimizde Yeterli Stok Bulunmamaktadir.");
	        	}
	    	}
	    	printf("\n\nBu Kategoriden Alisverise Devam Etmek Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	if(secim=='E' || secim=='e'){
	    		break;
			}
	    } 
	}while(secim == 'E' || secim== 'e');
}

void  kat_macera(void )
{
	char secim;
	int barkod[5]={1100,1101,1102,1103,1104};
    char kitap[5][30]={"Da Vinci Sifresi","Baslangic","Aclik Oyunlari","Alacakaranlik","Labirent"};
    char yazar[5][20]={"Dan Brown","Dan Brown","Suzanne Collins","Stephenie Meyer","James Dashner"};
    float puan[5]={8.8,8.6,8.6,8.0,8.8};
    float fiyat[5]={64.00,68.00,42.00,54.50,49.98};
    int stok[5]={3,3,3,3,3};
    int i;
    int j=0;
    int n;
    int barkodgir;
    int adet;
    
    do{
	    printf("\n                  ");
		printf("Barkod    Kitap Ad            Yazar	        Puan    Fiyat   Stok Durumu\n");
		printf("                ");
	    printf("-----------------------------------------------------------------------------\n");
	    
	    for(i=0;i<5;i++){
	        printf("                    ");
	        printf("%-4d    ",barkod[i]);
	        printf("%-20s",kitap[i]);
	        printf("%-17s",yazar[i]);
	    	printf("%-2.1f\t",puan[i]);
	      	printf("%-4.2f\t",fiyat[i]);
	    	printf("    %d",stok[i]);
	        printf("\n");
	    }
	    
	    if(j==0){
	    	printf("\nBu Kategoriden Alisveris Yapmak Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	j++;
	    }
	    
	    while(secim=='E' || secim=='e'){
	    	printf("\nAlmak Istediginiz Kitabin Barkod Numarasini Giriniz: ");
	    	scanf("%d",&barkodgir);
	    	printf("Almak Istediginiz Adet Sayisini Girin: ");
	    	scanf("%d",&adet);
	    	for(i=0;i<5;i++)
	    	{
	        	if(barkodgir==barkod[i])
	        	{
	        	    if(stok[i]>=adet)
	        	    {
	        	    	n=adet; //adet sayýsýný deðiþtirmemek için onu n deðiþkenine aktarýyoruz.
	        	        for(;n>0;n--) //Bu bölüm ürünün sepete gitmesi için çalýþacaktýr.
	        	        {
	        	            s[sepetsayac].barkod=sepetsayac;
	        	            strcpy(s[sepetsayac].kitap,kitap[i]);
	        	            strcpy(s[sepetsayac].yazar,yazar[i]);
	        	            s[sepetsayac].fiyat=fiyat[i];
	        	            sepetsayac++;
	        	        }
	            	    tutar=tutar+adet*fiyat[i];
	            	    stok[i]=stok[i]-adet;
	            	    printf("\n\t\t_________\"%d\"Adet \"%s\" Kitabi Sepetinize Eklenmistir.__________",adet,kitap[i]);
	            	    printf("\nSepet Tutari: %5.2f",tutar);
	        	    }
	        		else printf("\n******Elimizde Yeterli Stok Bulunmamaktadir.");
	        	}
	    	}
	    	printf("\n\nBu Kategoriden Alisverise Devam Etmek Istiyor Musunuz?(E/H): ");
		    scanf(" %c",&secim);
		   	if(secim=='E' || secim=='e'){
		    	break;
			}
	    }
	}while(secim=='E' || secim=='e');
}

void kat_dunyaroman(void )
{
	char secim;
	int barkod[9]={2100,2101,2102,2103,2104,2105,2106,2107,2108};
    char kitap[9][30]={"Altinci Kogus","Suc ve Ceza","Sefiller","Insan Neyle Yasar","Martin Eden","Gurur ve Onyargi","Hayvan Ciftligi","Satranc","Korluk"};
    char yazar[9][20]={"Anton Cehov","Dostoyevski","Victor Hugo","Lev Tolstoy","Jack London","Jane Austen","George Orwell","Stefan Zweig","Jose Saramago"};
    float puan[9]={8.5,9.4,9.3,8.5,9.2,8.4,8.4,8.6,8.5};
    float fiyat[9]={7.00,22.00,54.00,10.00,25.00,20.00,14.00,35.00,44.00};
    int stok[9]={3,3,3,3,3,3,3,3,3};
    int i;
    int j=0;
    int n;
    int barkodgir;
    int adet;
    
	do{
		printf("\n                  ");
		printf("Barkod    Kitap Ad            Yazar	        Puan    Fiyat   Stok Durumu\n");
		printf("                ");
	    printf("-----------------------------------------------------------------------------\n");
	    
	    for(i=0;i<9;i++){
	        printf("                    ");
	        printf("%-4d    ",barkod[i]);
	        printf("%-20s",kitap[i]);
	        printf("%-17s",yazar[i]);
	    	printf("%-2.1f\t",puan[i]);
	      	printf("%-4.2f\t",fiyat[i]);
	    	printf("    %d",stok[i]);
	        printf("\n");
	    }
	    
	    if(j==0){
	    	printf("\nBu Kategoriden Alisveris Yapmak Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	j++;
	    }
	    
	    while(secim=='E' || secim=='e'){
	    	printf("\nAlmak Istediginiz Kitabin Barkod Numarasini Giriniz: ");
	    	scanf("%d",&barkodgir);
	    	printf("Almak Istediginiz Adet Sayisini Girin: ");
	    	scanf("%d",&adet);
	    	for(i=0;i<9;i++)
	    	{
	        	if(barkodgir==barkod[i])
	            {
	        	    if(stok[i]>=adet)
	        	  	{
	        	  		n=adet;
	        	        for(;n>0;n--)
	        	        {
	        	            s[sepetsayac].barkod=sepetsayac;
	        	            strcpy(s[sepetsayac].kitap,kitap[i]);
	        	            strcpy(s[sepetsayac].yazar,yazar[i]);
	        	            s[sepetsayac].fiyat=fiyat[i];
	        	            sepetsayac++;
	        	        }
	            	    tutar=tutar+adet*fiyat[i];
	            	   	stok[i]=stok[i]-adet;
	        	    	printf("\n\t\t_________\"%d\"Adet \"%s\" Kitabi Sepetinize Eklenmistir._________",adet,kitap[i]);
	    		    	printf("\nSepet Tutari: %5.2f",tutar);
	   		    	}
	        		else    printf("\n******Elimizde Yeterli Stok Bulunmamaktadir.");
	        	}
	    	}
	    	
	        printf("\n\nBu Kategoriden Alisverise Devam Etmek Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	if(secim=='E' || secim=='e'){
			    	break;
			}
	    }
	}while(secim=='E' || secim=='e');
}

void kat_bilimkurgu(void )
{
	char secim;
	int barkod[5]={3100,3101,3102,3103,3104};
    char kitap[5][30]={"Harry Potter","Cesur Yeni Dunya","Fahrenheit 451","Zaman Makinesi","Ben,Kirke"};
    char yazar[5][20]={"J.K Rowling","Aldous Huxley","Ray Bradbury","H.G Wells","Madeline Miller"};
    float puan[5]={9.1,8.0,8.1,8.0,8.1};
    float fiyat[5]={28.00,40.00,40.00,14.00,56.00};
    int stok[5]={3,3,3,3,3};
    int i;
    int j=0;
    int n;
    int barkodgir;
    int adet;
    
	do{
		printf("\n                  ");
		printf("Barkod    Kitap Ad            Yazar	        Puan    Fiyat   Stok Durumu\n");
		printf("                ");
	    printf("-----------------------------------------------------------------------------\n");
	    
	    for(i=0;i<5;i++){
	        printf("                    ");
	        printf("%-4d    ",barkod[i]);
	        printf("%-20s",kitap[i]);
	        printf("%-17s",yazar[i]);
	    	printf("%-2.1f\t",puan[i]);
	      	printf("%-4.2f\t",fiyat[i]);
	    	printf("    %d",stok[i]);
	        printf("\n");
	    }
	    
	    if(j==0){
	    	printf("\nBu Kategoriden Alisveris Yapmak Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	j++;
	    }
	    
	    while(secim=='E' || secim=='e'){
	    	printf("\nAlmak Istediginiz Kitabin Barkod Numarasini Giriniz: ");
	    	scanf("%d",&barkodgir);
	    	printf("Almak Istediginiz Adet Sayisini Girin: ");
	    	scanf("%d",&adet);
	    	for(i=0;i<5;i++)
	    	{
	        	if(barkodgir==barkod[i])
	            {
	        	    if(stok[i]>=adet)
	        	  	{
	        	  		n=adet;
	        	        for(;n>0;n--)
	        	        {
	        	            s[sepetsayac].barkod=sepetsayac;
	        	            strcpy(s[sepetsayac].kitap,kitap[i]);
	        	            strcpy(s[sepetsayac].yazar,yazar[i]);
	        	            s[sepetsayac].fiyat=fiyat[i];
	        	            sepetsayac++;
	        	        }
	            	    tutar=tutar+adet*fiyat[i];
	            	   	stok[i]=stok[i]-adet;
	        	    	printf("\n\t\t_________\"%d\"Adet \"%s\" Kitabi Sepetinize Eklenmistir._________",adet,kitap[i]);
	    		    	printf("\nSepet Tutari: %5.2f",tutar);
	   		    	}
	        		else    printf("\n******Elimizde Yeterli Stok Bulunmamaktadir.");
	        	}
	    	}
	    	
	        printf("\n\nBu Kategoriden Alisverise Devam Etmek Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	if(secim=='E' || secim=='e'){
				break;
			}
	    }
	}while(secim=='E' || secim=='e');
}

void kat_siir(void )
{
    char secim;
	int barkod[8]={4100,4101,4102,4103,4104,4105,4106,4107};
    char kitap[8][30]={"Sevda Sozleri","Dortlukler","Goge Bakma Duragi","Dokuza Kadar On","Lavinia","Soneler","Yedi Guzel Adam","Ah'lar Agaci"};
    char yazar[8][20]={"Cemal Sureya","Omer Hayyam","Turgut Uyar","Ozdemir Asaf","Ozdemir Asaf","Shakespeare","Cahit Zarifoglu","Didem Madak"};
    float puan[8]={8.7,8.4,7.9,8.7,8.9,8.6,8.2,8.9};
    float fiyat[8]={48.00,10.00,10.00,10.00,12.00,18.00,26.00,20.00};
    int stok[8]={3,3,3,3,3,3,3,3};
    int i;
    int j=0;
    int n;
    int barkodgir;
    int adet;
    
	do{
		printf("\n                  ");
		printf("Barkod    Kitap Ad            Yazar	        Puan    Fiyat   Stok Durumu\n");
		printf("                ");
	    printf("-----------------------------------------------------------------------------\n");
	    for(i=0;i<8;i++){
	        printf("                    ");
	        printf("%-4d    ",barkod[i]);
	        printf("%-20s",kitap[i]);
	        printf("%-17s",yazar[i]);
	    	printf("%-2.1f\t",puan[i]);
	      	printf("%-4.2f\t",fiyat[i]);
	    	printf("    %d",stok[i]);
	        printf("\n");
	    }
	    
	    if(j==0){
	    	printf("\nBu Kategoriden Alisveris Yapmak Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	j++;
	    }
	    
	    while(secim=='E' || secim=='e'){
	        printf("\nAlmak Istediginiz Kitabin Barkod Numarasini Giriniz: ");
	        scanf("%d",&barkodgir);
			printf("Almak Istediginiz Adet Sayisini Girin: ");
			scanf("%d",&adet);
			for(i=0;i<8;i++)
	    	{
	        	if(barkodgir==barkod[i])
	        	{
	        	    if(stok[i]>=adet)
	        		{
	        			n=adet;
	        	        for(;n>0;n--)
	        	        {
	        	            s[sepetsayac].barkod=sepetsayac;
	        	            strcpy(s[sepetsayac].kitap,kitap[i]);
	        	            strcpy(s[sepetsayac].yazar,yazar[i]);
	        	            s[sepetsayac].fiyat=fiyat[i];
	        	            sepetsayac++;
	        	        }
	        	    	tutar=tutar+adet*fiyat[i];
	    		    	stok[i]=stok[i]-adet;
	    		    	printf("\n\t\t_________\"%d\"Adet \"%s\" Kitabi Sepetinize Eklenmistir._________",adet,kitap[i]);
	    		    	printf("\nSepet Tutari: %5.2f",tutar);
	        		}
	        		else    printf("\n******Elimizde Yeterli Stok Bulunmamaktadir.");
	        	}
	    	}
	    	
	    	printf("\n\nBu Kategoriden Alisverise Devam Etmek Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	if(secim=='E' || secim=='e'){
				break;
			}
	    }
	}while(secim=='E' || secim=='e');
}

void kat_turkroman(void )
{
    char secim;
	int barkod[9]={5100,5101,5102,5103,5104,5105,5106,5107,5108};
    char kitap[9][30]={"Tutunamayanlar","Serenad","Ince Memed","Masumiyet Muzesi","Aksam Gunesi","Icimizdeki Seytan","Aylak Adam","Fatih Harbiye","Kirlangic Cigligi"};
    char yazar[9][20]={"Oguz Atay","Zulfu Livaneli","Yasar Kemal","Orhan Pamuk","Resat Nuri G.","Sabahattin Ali","Yusuf Atilgan","Peyami Safa","Ahmet Umit"};
    float puan[9]={9.1,9.1,9.4,8.2,8.3,8.6,7.9,7.9,8.7};
    float fiyat[9]={78.00,46.00,38.00,44.00,34.00,10.00,27.50,12.00,32.00};
    int stok[9]={3,3,3,3,3,3,3,3,3};
    int i;
    int j=0;
    int n;
    int barkodgir;
    int adet;
    
	do{
		printf("\n                  ");
		printf("Barkod    Kitap Ad            Yazar	        Puan    Fiyat   Stok Durumu\n");
		printf("                ");
	    printf("-----------------------------------------------------------------------------\n");
	    for(i=0;i<9;i++){
	        printf("                    ");
	        printf("%-4d    ",barkod[i]);
	        printf("%-20s",kitap[i]);
	        printf("%-17s",yazar[i]);
	    	printf("%-2.1f\t",puan[i]);
	      	printf("%-4.2f\t",fiyat[i]);
	    	printf("    %d",stok[i]);
	        printf("\n");
	    }
	    
	    if(j==0){
	    	printf("\nBu Kategoriden Alisveris Yapmak Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
	    	j++;
	    }
	    
	    while(secim=='E' || secim=='e'){
	        printf("\nAlmak Istediginiz Kitabin Barkod Numarasini Giriniz: ");
	        scanf("%d",&barkodgir);
			printf("Almak Istediginiz Adet Sayisini Girin: ");
			scanf("%d",&adet);
			for(i=0;i<9;i++)
	    	{
	        	if(barkodgir==barkod[i])
	        	{
	        	    if(stok[i]>=adet)
	        		{
	        			n=adet;
	        	        for(;n>0;n--)
	        	        {
	        	            s[sepetsayac].barkod=sepetsayac;
	        	            strcpy(s[sepetsayac].kitap,kitap[i]);
	        	            strcpy(s[sepetsayac].yazar,yazar[i]);
	        	            s[sepetsayac].fiyat=fiyat[i];
	        	            sepetsayac++;
	        	        }
	        	    	tutar=tutar+adet*fiyat[i];
	    		    	stok[i]=stok[i]-adet;
	    		    	printf("\n\t\t_________\"%d\"Adet \"%s\" Kitabi Sepetinize Eklenmistir._________",adet,kitap[i]);
	    		    	printf("\nSepet Tutari: %5.2f",tutar);
	        		}
	        		else    printf("\n******Elimizde Yeterli Stok Bulunmamaktadir.");
	        	}
	    	}
	    	
	    	printf("\n\nBu Kategoriden Alisverise Devam Etmek Istiyor Musunuz?(E/H): ");
	    	scanf(" %c",&secim);
		    if(secim=='E' || secim=='e'){
				break;
			}
	    }
	}while(secim=='E' || secim=='e');
}

