#include <iostream>
#include <array>
#include <sstream>
#include "AesEnc.h"
#include <iomanip>
// typedef unsigned char uint8_t;
using namespace std;

void print(array<array<uint8_t, 4>, 4> &state)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << std::setfill('0') << std::setw(sizeof(uint8_t) * 2) << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }
}

array<array<uint8_t, 4>, 4> AES_Encrypt(array<array<uint8_t, 4>, 4> &state, array<uint8_t, 16> &key)
{

    array<array<uint8_t, 16>, 11> expandedKey;

    KeyExpansion(key, expandedKey);

    add_round_key(state, expandedKey[0]);

    for (int i = 1; i <= 9; i++)
    {
        subBytes(state);

        shiftRows(state);

        mixColumns(state);

        add_round_key(state, expandedKey[i]);
    }
    subBytes(state);

    shiftRows(state);

    add_round_key(state, expandedKey[10]);

    return state;
}

array<array<uint8_t, 4>, 4> AES_Decrypt(array<array<uint8_t, 4>, 4> &cipher, array<uint8_t, 16> &key)
{

    array<array<uint8_t, 16>, 11> expandedKey;

    KeyExpansion(key, expandedKey);

    add_round_key(cipher, expandedKey[10]);

    for (int i = 9; i >= 1; i--)
    {
        invShiftRows(cipher);

        invSubBytes(cipher);

        add_round_key(cipher, expandedKey[i]);

        inverseMixColumns(cipher);
    }
    invShiftRows(cipher);
    invSubBytes(cipher);

    add_round_key(cipher, expandedKey[0]);

    return cipher;
}

int main()
{

    array<array<uint8_t, 4>, 4> state{0x32, 0x88, 0x31, 0xe0,
                                      0x43, 0x5a, 0x31, 0x37,
                                      0xf6, 0x30, 0x98, 0x07,
                                      0xa8, 0x8d, 0xa2, 0x34};

    array<uint8_t, 16> key = {0x2b, 0x7E, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

    AES_Encrypt(state, key);

    cout << "Encryption Output is: " << endl;
    print(state);
    AES_Decrypt(state, key);

    cout << "Decryption Output is: " << endl;
    print(state);
}
