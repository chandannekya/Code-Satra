#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std; 

int getBouquetCount(const vector<int>& bloomDay, int k, int waitingDays) {
    int bouquetCount = 0;
    int requiredFlowers = k;
    for (const int day : bloomDay) {
        if (day > waitingDays) {
            // Reset `requiredFlowers` since there was not enough adjacent flowers.
            requiredFlowers = k;
        } else if (--requiredFlowers == 0) {
            // Use k adjacent flowers to make a bouquet.
            ++bouquetCount;
            requiredFlowers = k;
        }
    }
    return bouquetCount;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if (bloomDay.size() < static_cast<long>(m) * k)
        return -1;

    int l = ranges::min(bloomDay);
    int r = ranges::max(bloomDay);

    while (l < r) {
        const int mid = (l + r) / 2;
        if (getBouquetCount(bloomDay, k, mid) >= m)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main() {
    vector<int> bloomDay = {5, 5, 5, 5, 10, 5, 5};
    int m = 2;
    int k = 3;
    cout << minDays(bloomDay, m, k) << endl;  // Output: 3
    return 0;
}
