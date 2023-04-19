#include <iostream>
#include <array>
#include <sstream>
#include "AesEnc.h"
#include <iomanip>
// typedef unsigned char uint8_t;
using namespace std;

string AES_Encrypt(string text, string keyStr)
{
    array<array<uint8_t, 4>, 4> state = convertStringTo2DStateArray(text);
    array<uint8_t, 16> key = convertStringTo1DStateArray(keyStr);
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

    return convert2DStateArrayToString(state);
}

string AES_Decrypt(string cipherText, string keyStr)
{
    array<array<uint8_t, 4>, 4> cipher = convertStringTo2DStateArray(cipherText);
    array<uint8_t, 16> key = convertStringTo1DStateArray(keyStr);
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

    return convert2DStateArrayToString(cipher);
}

int main()
{

    string cipher = AES_Encrypt("00000000000000000000000000000000", "10a58869d74be5a374cf867cfb473859");

    cout << "Encryption Output is: " << endl;
    cout << cipher<<endl;
    string plainText =  AES_Decrypt(cipher, "10a58869d74be5a374cf867cfb473859");
    

    cout << "Decryption Output is: " << endl;
    cout << plainText;
}
