#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    size_t arr_count, bin_count;
    float mx, mn, x;
    vector <float> arr;
    vector <size_t> bins;
    cerr << "Enter number count: ";
    cin >> arr_count;
    cerr << "Enter " << arr_count << " numbers: ";
    for (int i = 0; i < arr_count; i++) {
            cin >> x;
            arr.push_back(x);
    }
    cerr << "Enter bin count: ";
    cin >> bin_count;
    mx = arr[0];
    mn = arr[0];
    for (int i = 0; i < arr_count; i++) {
        if (mx < arr[i]) mx = arr[i];
        if (mn > arr[i]) mn = arr[i];
    }
    float diff = (mx - mn) / bin_count;
    float n = mn;
    float m = mn + diff;
    size_t mxbin = 0;
    for (int i = 0; i < bin_count; i++) {
        size_t t = 0;
        for (int j = 0; j < arr_count; j++) {
            if ((i == bin_count - 1) && (arr[j] >= n) && (arr[j] <= m)) t++;
            else if ((n <= arr[j]) && (arr[j] < m)) t++;
        }
        bins.push_back(t);
        if (bins[mxbin] < t) mxbin = i;
        n += diff;
        m += diff;
    }

    int blm = bins[mxbin];
    int y = -1;
    while (blm > 0) {
        blm = blm / 10;
        y++;
    }
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - y - 2;
    if (bins[mxbin] > MAX_ASTERISK) {
    for (int i = 0; i < bin_count; i++) {
        size_t r = bins[i];
        while (r < pow(10, y)) {
            r *= 10;
            cout << " ";
        }
        cout << bins[i] << "|";
        if (i == mxbin) for (int i = 0; i < MAX_ASTERISK; i++) cout << "*";
        else {
            size_t height = MAX_ASTERISK * (static_cast <double> (bins[i]) / bins[mxbin]);
            for (int i = 0; i < height; i++) cout << "*";
        }
        cout << endl;
    }
    } else {
        for (int i = 0; i < bin_count; i++) {
        size_t r = bins[i];
        while (r < pow(10, y)) {
            r *= 10;
            cout << " ";
        }
        cout << bins[i] << "|";
        for (int j = 0; j < bins[i]; j++) cout << "*";
        cout << endl;
    }
    }
    return 0;
}
