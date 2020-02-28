/* 
 * lab11.c
 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 
 * no, isim, soyisimle verilen kaydi f dosyasinin sonuna ekler 
 */
void ekle(FILE *f, char *no, char *isim, char *soyisim){
    /* TODO */
      
    fprintf(f, "\n%s\t%s\t%s", no, isim, soyisim);
    
        
    return ;
}

/* 
 * numaralarinin baslangic n karakteri no'ya esit olan
 *  kayitlarin bilgilerini listeler 
 */
int no_ile_ara(FILE *f, char *no, int n)
{
    /* TODO */
    
    char l[150], l2[150];
    
    while(fgets(l, 150, f) != NULL)
    {
		strncpy(l2, l, 150);
		
		char *pno = strtok(l, "\t");
		if(!strncmp(no, pno, n))
		{
			printf("No: %.10s\n", pno);
			printf("Isim: %.40s\n", strtok(NULL, "\t"));
			printf("Soy Isim: %.40s\n", strtok(NULL, "\t"));
			
			return 1;
		}
	}

    
    return 0;
}

/* 
 * isimlerinin baslangic n karakteri isim'e esit olan 
 * kayitlarin bilgilerini listeler 
 */
int isim_ile_ara(FILE *f, char *isim, int n){
    /* TODO */
    
    
    char l[150], l2[150];
    
    while(fgets(l, 150, f) != NULL)
    {
		strncpy(l2, l, 150);
		
		char *token = strtok(l, "\t");
		char *no = token;
		token = strtok(NULL, "\t");
		char *pisim = token;
		
		if(!strncmp(isim, pisim, n))
		{
			printf("No: %.10s\n", no);
			printf("Isim: %.40s\n", pisim);
			printf("Soy Isim: %.40s\n", strtok(NULL, "\t"));
			
			return 1;
		}
	}
	
	return 0;
}
    
 

/* 
 * soyisimlerinin baslangic n karakteri soyisim'e esit olan 
 * kayitlarin bilgilerini listeler 
 */
int soyisim_ile_ara(FILE *f, char *soyisim, int n){
    /* TODO */
    
    char l[150], l2[150];
    
    while(fgets(l, 150, f) != NULL)
    {
		strncpy(l2, l, 150);
		
		char *token = strtok(l, "t");
		char *no = token; 
		token = strtok(NULL, "t");
		char* isim = token;
		token = strtok(NULL, "t");
		char *psoyisim = token;
		
		if(!strncmp(soyisim, psoyisim, n))
		{
			printf("No: %.10s\n", no);
			printf("Isim: %.40s\n", isim);
			printf("Soy Isim: %.40s\n", psoyisim);
			
			return 1;
		}
	}
	
	return 0;
}
    


/* dosyayi acar ve 
 * verilen inputlari yorumlayarak ilgili fonksiyonu cagirir 
 * sonra dosyayi kapatarak programdan cikar*/
int main(int argc, char *argv[])
{
    
    char *a = 'ekle';
    char *b = 'no';
    char *c = 'isim';
    char *d = 'soyisim';
    
    if(!strncmp(argv[1], a, 4))
    {
		ekle(argv[2], argv[3], argv[4], argv[5]);
		
		return 0;
	}

	else if(!strncmp(argv[1], b, 2))
	{
		no_ile_ara(argv[2], argv[3], strlen(argv[3]));
		
		return 0;
		
	}
   
	else if(!strncmp(argv[1], c, 4))
	{
		isim_ile_ara(argv[2], argv[3], strlen(argv[3]));
		
		return 0;
		
	}
	
	else if(!strncmp(argv[1], d, 7))
	{
		soyisim_ile_ara(argv[2], argv[3], strlen(argv[3]));
		
		return 0;
		
	}
    
    return 0;
}
