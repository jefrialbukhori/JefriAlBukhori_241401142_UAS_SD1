#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int N;

    cin >> N;

    int data[N];
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    sort(data, data + N);

    cout << endl;

    int cari;
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    while (low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = (float) (cari - data[low]) / (data[high] - data[low]) * (high - low) + low;
        posisi = floor(posisi1);

        if (data[posisi] == cari) {
            flag = 1;
            break;

        } else if (data[posisi] < cari) {
            low = posisi + 1;
        } else {
            high = posisi - 1;
        }
    }

    cout << "\nMencari Kursi No: " << cari << endl;
    if (flag == 1)
        cout << "Status :" << " TERSEDIA  " << "\nDetail :" << " Ditemukan pada indeks " << posisi << endl;
    else
        cout << "Status: " << " TIDAK TERSEDIA " << " \nOpsi : Kursi terdekat yang tersedia adalah No. " << cari << endl;

    return 0;
}