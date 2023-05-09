#include <iostream>
#include "CBC.h"

using namespace std;

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
        key = RandomKeyGenrator(16);
        return key;
    }
};


int main(){

    CryptoPortal test;
    
    string keyVal = test.generate_key();
    cout<<"New key created."<<"Key Value is : "<< keyVal<<endl;
    string plainText = "Doctor Rida Bazzi is the best!!!!";
    cout<<"Trying to encrypt: "<<plainText<<endl;
    string cipherText = test.encrypt_CBC(plainText,true);
    cout<<"The cipher text is: "<<cipherText<<endl;
    string retrievedText = test.decrypt_CBC(cipherText,true);
    cout<<"The decrypted text is: "<<retrievedText<<endl;

}
