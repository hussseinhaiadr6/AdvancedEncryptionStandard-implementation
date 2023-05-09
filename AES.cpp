#include <iostream>
#include <array>
#include <sstream>
#include "AesEnc.h"
#include <iomanip>
// typedef unsigned char uint8_t;
using namespace std;


int main()
{

    string cipher = AES_Encrypt("00000000000000000000000000000000", "10a58869d74be5a374cf867cfb473859");

    cout << "Encryption Output is: " << endl;
    cout << cipher<<endl;
    string plainText =  AES_Decrypt(cipher, "10a58869d74be5a374cf867cfb473859");
    

    cout << "Decryption Output is: " << endl;
    cout << plainText;
}
