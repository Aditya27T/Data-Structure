#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int front, rear;
} Queue;

/**
 * Inisialisasi antrian.
 * @param q Pointer ke antrian yang akan diinisialisasi.
 */
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

/**
 * Memeriksa apakah antrian penuh.
 * @param q Pointer ke antrian yang akan diperiksa.
 * @return 1 jika antrian penuh, 0 jika tidak.
 */
int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

/**
 * Memeriksa apakah antrian kosong.
 * @param q Pointer ke antrian yang akan diperiksa.
 * @return 1 jika antrian kosong, 0 jika tidak.
 */
int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

/**
 * Menambahkan elemen ke antrian.
 * @param q Pointer ke antrian.
 * @param value Karakter yang akan ditambahkan ke antrian.
 */
void enqueue(Queue *q, char value) {
    if (isFull(q)) {
        printf("Antrian penuh\n");
        return;
    } else {
        if (isEmpty(q))
            q->front = q->rear = 0;
        else
            q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = value;
    }
}

/**
 * Menghapus elemen dari antrian.
 * @param q Pointer ke antrian.
 * @return Karakter yang dihapus dari antrian, -1 jika antrian kosong.
 */
char dequeue(Queue *q) {
    char value;
    if (isEmpty(q)) {
        printf("Antrian kosong\n");
        return -1;
    } else {
        value = q->items[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

/**
 * Membalikkan string menggunakan antrian.
 * @param q Pointer ke antrian.
 * @param str String yang akan dibalikkan.
 */
void reverseString(Queue *q, char *str) {
    int i;
    for (i = 0; i < strlen(str); i++)
        enqueue(q, str[i]);
    
    for (i = 0; i < strlen(str); i++)
        str[i] = dequeue(q);
    
    for (i = 0; i < strlen(str) / 2; i++) {
        char temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}

int main() {
    Queue q;
    initQueue(&q);
    // input and output
    char str[MAX_SIZE];
    char choice;
    do {
        printf("Masukkan sebuah string: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        if (strlen(str) == 0 || (strlen(str) == 1 && str[0] == ' ')) {
            printf("String kosong\n");
            printf("Apakah Anda ingin membalikkan string lain? (y/n): ");
            scanf(" %c", &choice);
            getchar(); // mengonsumsi karakter newline
            continue;
        }

        reverseString(&q, str);

        printf("String yang dibalikkan: ");
        puts(str);

        printf("Apakah Anda ingin membalikkan string lain? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // mengonsumsi karakter newline

    } while (choice == 'y' || choice == 'Y');

    return 0;
}