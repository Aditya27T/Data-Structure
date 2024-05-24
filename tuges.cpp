#include <iostream>
#include <string>

using namespace std;

struct Queue {
    string nama[100];
    int front, rear;
    unsigned capacity;
    unsigned count;
};

Queue* createQueue(unsigned capacity) {
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->count = 0;
    queue->rear = capacity - 1; 
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->count == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->count == 0);
}

void enqueue(Queue* queue, string nama) {
    if (isFull(queue)) {
        cout << "Antrian penuh!" << endl;
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->nama[queue->rear] = nama;
    queue->count++;
}

void dequeue(Queue* queue, int n) {
    if (isEmpty(queue)) {
        cout << "Antrian kosong!" << endl;
        return;
    }

    cout << "Panggilan dari Antrian:" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < n; ++i) {
        cout << queue->nama[queue->front] << " ";
        queue->front = (queue->front + 1) % queue->capacity;
        queue->count--;
    }
    cout << endl;
}

void displayQueue(Queue* queue, string wahana) {
    cout << "Antrian untuk " << wahana << ": " << endl;
    cout << "Jumlah: " << queue->count << endl;
    cout << "Urutan Nama: ";
    int i = queue->front;
    int j = 0;
    while (j < queue->count) {
        cout << queue->nama[i] << ", ";
        i = (i + 1) % queue->capacity;
        j++;
    }
    cout << endl;
}

int main() {
    Queue* tongSetan = createQueue(25);
    Queue* rumahHantu = createQueue(10);
    Queue* bianglala = createQueue(35);
    Queue* ombakBanyu = createQueue(15);

    int choice;
    string nama;
    char input;

    do {
        cout << "\nPasar Malam Menu: " << endl;
        cout << "1. Masukkan Antrian" << endl;
        cout << "2. Panggil Antrian" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch(choice) {
            case 1:
                do {
                    cout << "Masukkan nama: ";
                    cin >> nama;
                    cout << "Pilih wahana: " << endl;
                    cout << "1. Tong Setan" << endl;
                    cout << "2. Rumah Hantu" << endl;
                    cout << "3. Bianglala" << endl;
                    cout << "4. Ombak Banyu" << endl;
                    cout << "Pilihan Anda: ";
                    cin >> choice;
                    switch(choice) {
                        case 1:
                            enqueue(tongSetan, nama);
                            break;
                        case 2:
                            enqueue(rumahHantu, nama);
                            break;
                        case 3:
                            enqueue(bianglala, nama);
                            break;
                        case 4:
                            enqueue(ombakBanyu, nama);
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                    if (isFull(tongSetan) && isFull(rumahHantu) && isFull(bianglala) && isFull(ombakBanyu)) {
                        cout << "Antrian penuh!" << endl;
                        break;
                    }
                    cout << "Apakah Anda ingin memasukkan nama lagi? (y/n): ";
                    cin >> input;
                } while (input == 'y' || input == 'Y');
                break;
            case 2:
                cout << "Pilih wahana untuk memanggil antrian: " << endl;
                cout << "1. Tong Setan" << endl;
                cout << "2. Rumah Hantu" << endl;
                cout << "3. Bianglala" << endl;
                cout << "4. Ombak Banyu" << endl;
                cout << "Pilihan Anda: ";
                cin >> choice;
                switch(choice) {
                    case 1:
                        dequeue(tongSetan, 10);
                        break;
                    case 2:
                        dequeue(rumahHantu, 2);
                        break;
                    case 3:
                        dequeue(bianglala, 15);
                        break;
                    case 4:
                        dequeue(ombakBanyu, 5);
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
                break;
            case 3:
                displayQueue(tongSetan, "Tong Setan");
                displayQueue(rumahHantu, "Rumah Hantu");
                displayQueue(bianglala, "Bianglala");
                displayQueue(ombakBanyu, "Ombak Banyu");
                break;
            case 4:
                cout << "Terima kasih telah menggunakan layanan Pasar Malam!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(choice != 4);

    return 0;
}