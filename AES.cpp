#include <iostream>
#include <array>

using namespace std;

// define the key schedule for example purposes
const array<uint8_t, 16> key{ {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0f, 0x0e
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
        {0x00, 0x44, 0x88, 0xcc},
        {0x11, 0x55, 0x99, 0xdd},
        {0x22, 0x66, 0xaa, 0xee},
        {0x33, 0x77, 0xbb, 0xff}
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