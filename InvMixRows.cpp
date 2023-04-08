#include <iostream>
#include <array>

using namespace std;

// define the fixed matrix used in InverseMixRows transformation
const array<array<uint8_t, 4>, 4> inv_mix_rows_matrix = { {
    {0x0e, 0x0b, 0x0d, 0x09},
    {0x09, 0x0e, 0x0b, 0x0d},
    {0x0d, 0x09, 0x0e, 0x0b},
    {0x0b, 0x0d, 0x09, 0x0e}
} };

// helper function to perform Galois field multiplication
uint8_t gf_mul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    uint8_t counter;
    uint8_t hi_bit_set;
    for (counter = 0; counter < 8; counter++) {
        if (b & 1) {
            p ^= a;
        }
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set) {
            a ^= 0x1B; // irreducible polynomial for AES GF(2^8)
        }
        b >>= 1;
    }
    return p;
}

// perform the InverseMixRows transformation
void inv_mix_rows(array<array<uint8_t, 4>, 4>& state) {
    array<array<uint8_t, 4>, 4> new_state;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            new_state[i][j] = gf_mul(inv_mix_rows_matrix[i][0], state[0][j])
                ^ gf_mul(inv_mix_rows_matrix[i][1], state[1][j])
                ^ gf_mul(inv_mix_rows_matrix[i][2], state[2][j])
                ^ gf_mul(inv_mix_rows_matrix[i][3], state[3][j]);
        }
    }
    state = new_state;
}

int main() {
    // example usage
    array<array<uint8_t, 4>, 4> state{ {
        {0x04, 0xe0, 0x48, 0x28},
        {0x66, 0xcb, 0xf8, 0x06},
        {0x81, 0x19, 0xd3, 0x26},
        {0xe5, 0x9a, 0x7a, 0x4c}
    } };
    inv_mix_rows(state);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}