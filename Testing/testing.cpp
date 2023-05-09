#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include "AesEnc.h"
#include <iomanip>
#include <cassert>

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


int main() {
    ifstream input_file("TestCases.txt"); // replace "sample.txt" with the name of your input file
    string line;
    int caseIndex=1;
    while (getline(input_file, line)) {
        vector<string> tokens;
        istringstream iss(line);
        string token;
        while (getline(iss, token, ' ')) {
            tokens.push_back(token);
        }
        cout<<"Case "<<caseIndex<<endl;
        string key_sample = tokens[0];
        string plain_text_sample = tokens[1];
        string cipher_text_sample = tokens[2];
        string expected_plain_text_sample = tokens[1];
        string expected_cipher_text_sample = tokens[2];

        string cipher = AES_Encrypt(plain_text_sample, key_sample);

        cout << "Encryption Output is: ";
        cout << cipher<<endl;
       
        string plainText =  AES_Decrypt(cipher, key_sample);
        cout << "Decryption Output is: ";
        cout << plainText<<endl;
        assert(plainText == plain_text_sample);
        caseIndex++;
         assert(cipher == expected_cipher_text_sample);
    }

    input_file.close();

    return 0;
}
