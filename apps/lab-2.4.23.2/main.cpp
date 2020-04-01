#include <iostream>

using namespace std;

int main() {
    unsigned short x;
    bool isPalindrome = true;

    cin >> x;

    for (unsigned int bit = 0; bit < 8; bit++) {
        unsigned int mostSignificantMask = 0x8000u >> bit;
        unsigned int leastSignificantMask = 0x0001u << bit;

        bool isMostSignificantBitSet = (bool) (x & mostSignificantMask);
        bool isLastSignificantBitSet = (bool) (x & leastSignificantMask);

        if (isMostSignificantBitSet != isLastSignificantBitSet) {
            isPalindrome = false;
            break;
        }
    }

    // alternative - not so good idea
    // TODO - Luci.

    cout << "Is palindrom: " << (isPalindrome ? "Yes" : "No");

    return 0;
}