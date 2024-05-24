#include <stdio.h>
#include "queue.h"

/**
 * Mencari item dalam antrian.
 * 
 * @param q Antrian yang akan dicari.
 * @param item Item yang akan dicari.
 * @return Indeks item jika ditemukan, -1 jika tidak ditemukan.
 */
int search(Queue* q, int item) {
    if (isEmpty(q)) {
        printf("Antrian kosong. Tidak dapat mencari.\n");
        return -1;
    }
    for (int i = q->front; i <= q->rear; i++) {
        if (q->data[i] == item) {
            return i;
        }
    }
    return -1;
}

/**
 * Mengedit item dalam antrian pada indeks tertentu.
 * 
 * @param q Antrian yang akan diedit.
 * @param index Indeks item yang akan diedit.
 * @param newValue Nilai baru yang akan diberikan pada item.
 */
void edit(Queue* q, int index, int newValue) {
    if (isEmpty(q)) {
        printf("Antrian kosong. Tidak dapat mengedit.\n");
        return;
    }
    if (index < q->front || index > q->rear) {
        printf("Indeks tidak valid. Tidak dapat mengedit.\n");
        return;
    }
    q->data[index] = newValue;
}

/**
 * Menghitung statistik dari antrian, termasuk total, rata-rata, nilai maksimum, dan nilai minimum.
 * 
 * @param q Antrian yang akan dihitung statistiknya.
 * @param total Pointer untuk menyimpan jumlah total dari semua item dalam antrian.
 * @param average Pointer untuk menyimpan nilai rata-rata dari semua item dalam antrian.
 * @param max Pointer untuk menyimpan nilai maksimum dalam antrian.
 * @param min Pointer untuk menyimpan nilai minimum dalam antrian.
 */
void calculateStats(Queue* q, int* total, double* average, int* max, int* min) {
    if (isEmpty(q)) {
        printf("Antrian kosong. Tidak dapat menghitung statistik.\n");
        return;
    }
    *total = 0;
    *max = q->data[q->front];
    *min = q->data[q->front];
    for (int i = q->front; i <= q->rear; i++) {
        *total += q->data[i];
        if (q->data[i] > *max) {
            *max = q->data[i];
        }
        if (q->data[i] < *min) {
            *min = q->data[i];
        }
    }
    *average = (double)(*total) / (q->rear - q->front + 1);
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // print antrian
    printf("*******[Operasi Antrian]**********\n");
    printf("Antrian: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.data[i]);
    }
    printf("\n");
    printf("***********************************\n");

    int total, max, min;
    double average;
    calculateStats(&q, &total, &average, &max, &min);
    printf("Total: %d\n", total);
    printf("Rata-rata: %.2lf\n", average);
    printf("Maksimum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("***********************************\n");

    int searchItem = 30;
    int searchIndex = search(&q, searchItem);
    if (searchIndex != -1) {
        printf("Item %d ditemukan pada indeks %d\n", searchItem, searchIndex);
    } else {
        printf("Item %d tidak ditemukan\n", searchItem);
    }
    printf("***********************************\n");

    int editIndex = 2;
    int newValue = 35;
    edit(&q, editIndex, newValue);
    printf("Item pada indeks %d diubah dengan nilai baru %d\n", editIndex, newValue);
    printf("***********************************\n");

    return 0;
}
