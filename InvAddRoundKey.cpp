#include <iostream>
#include <array>

using namespace std;

void inv_add_round_key(array<array<uint8_t, 4>, 4>& state, const array<uint8_t, 16>& round_key) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[j][i] ^= round_key[i * 4 + j];
        }
    }
}

int main() {
    // Example key and state
    array<uint8_t, 16> key = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
    array<array<uint8_t, 4>, 4> state = { {
        { 0x39, 0x02, 0xdc, 0x19 },
        { 0x25, 0xdc, 0x11, 0x6a },
        { 0x84, 0x09, 0x85, 0x0b },
        { 0x1d, 0xfb, 0x97, 0x32 }
    } };

    // Add round key
    inv_add_round_key(state, key);

    // Print decrypted state
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << static_cast<int>(state[j][i]) << " ";
        }
        cout << endl;
    }

    return 0;
}