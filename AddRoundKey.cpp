#include <iostream>
#include <array>

using namespace std;

// define the key schedule for example purposes
const array<uint8_t, 16> key{ {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
} };

// perform the AddRoundKey transformation
void add_round_key(array<array<uint8_t, 4>, 4>& state, const array<uint8_t, 16>& round_key) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[j][i] ^= round_key[i * 4 + j];
        }
    }
}

int main() {
    // example usage
    array<array<uint8_t, 4>, 4> state{ {
        {0x32, 0x88, 0x31, 0xe0},
        {0x43, 0x5a, 0x31, 0x37},
        {0xf6, 0x30, 0x98, 0x07},
        {0xa8, 0x8d, 0xa2, 0x34}
    } };
    add_round_key(state, key);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << (int)state[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}