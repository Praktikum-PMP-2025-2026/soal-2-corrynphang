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

int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
char* inputStringDinamis() {
    char buffer[256]; 
    if (scanf("%s", buffer) != 1) return NULL; 
    
    char *str = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    if (str != NULL) {
        strcpy(str, buffer);
    }
    return str;
}

int main(){
    int N;
    char prefix[256];

    if (scanf("%d", &N) != 1) return 0;

    char **arr = (char**)malloc(N * sizeof(char*));
    if (arr == NULL) return 1;

    for (int i = 0; i < N; i++) {
        arr[i] = inputStringDinamis();
    }
    scanf("%s", prefix);
    qsort(arr, N, sizeof(char*), compareStrings);

    char *out[3];
    int sum = 0;
    int prefix_len = strlen(prefix);
    for (int i = 0; i < N; i++) {
        if (strncmp(prefix, arr[i], prefix_len) == 0) {
            out[sum] = arr[i];
            sum++;
            if (sum == 3) break;
        }
    
    if (sum == 0) {
        printf("TIDAK ADA\n");
    } else {
        printf("SUGGESTION");
        for (int i = 0; i < sum; i++) {
            printf(" %s", out[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
}
