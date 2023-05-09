#include <iostream>
#include "CBC.h"
#include "PRNG.h"

class CryptoPortal
{
private:
    string key;

public:
    CryptoPortal()
    {
    }

    // can take input in ASCII or in HEX. Default is hex. Output is always is in hex;
    string encrypt_CBC(string plaintext, bool ASCII = false)
    {
        if (ASCII)
        {
            return CBC_encrypt(stringToHex(plaintext), key);
        }
        return CBC_encrypt(plaintext, key);
    }

    string decrypt_CBC(string ciphertext, bool ASCII = false)
    {
        if (ASCII)
        {
            return hexToASCII(CBC_decrypt(ciphertext, key));
        }
        return CBC_decrypt(ciphertext, key);
    }

    void set_key(string input_key){
        key = input_key;
    }

    string generate_key(){
        key = RandomKeyGenrator();
        return key;
    }
};