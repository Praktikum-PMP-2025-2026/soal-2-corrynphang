/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 03 – Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Selasa, 28 April 2026
 *   Nama (NIM)          : Beatrice Corryn Pangestu (13224038)
 *   Nama File           : soal2.c
 *   Deskripsi           : Gudang perlengkapan penelitian memiliki banyak nama barang yang tersimpan dalam katalog digital. 
Saat operator mengetik awalan nama suatu barang, sistem pencarian harus segera memberikan 
beberapa saran paling relevan agar proses input menjadi lebih cepat. Anda diminta membuat 
mekanisme sederhana yang dapat menampilkan maksimal tiga nama barang pertama yang cocok 
dengan awalan yang diberikan. 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* inputStringDinamis() {
    char buffer[256]; 
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
