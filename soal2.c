/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 03 – Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Beatrice Corryn Pangestu (13224038)
 *   Nama File           : soal1.c
 *   Deskripsi           : Sebuah kubah pengaman dijaga oleh petugas dalam tiga shift berbeda: pagi, siang, dan malam. Setiap 
penjaga memiliki identitas dan skor respons yang menunjukkan performanya saat bertugas. Kepala 
keamanan ingin mengetahui siapa penjaga terbaik pada tiap shift agar jadwal evaluasi dapat segera 
disusun. Jika suatu shift tidak memiliki penjaga terdaftar, sistem tetap harus menandai kondisi itu 
dengan jelas. 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* inputStringDinamis() {
    char buffer[1024]; 
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return NULL;
    buffer[strcspn(buffer, "\n")] = '\0';
    char *str = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    if (str != NULL) {
        strcpy(str, buffer);
    }
    return str;
}
int main(){
    int N;
    char prefix[256];
    char **arr= NULL;
    int sum=0;
    scanf("%d ",&N);
    char *out[3];
    arr = (char**)malloc(N * sizeof(char*));
      for (int i = 0; i < N; i++) {
        arr[i] = inputStringDinamis();
    }
    scanf("%s",prefix);
    char temp[strlen(prefix)];
    for (int i=0; i <N;N++){
        strcpy(temp, arr[i]);
        if (strcmp(prefix,temp)==0){
            out[i]=arr[i];
        }
    }
    
    printf("SUGGESTION ");
    for (int i=0; i<3; i++){
        printf("%s",out[i]);
        if (i<3){
            printf(" ");
        }
    }
}
