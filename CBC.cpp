#include "AesEnc.h"
#include <vector>
#include <bitset>
using namespace std;

/*  Conversion functions   */

string hexToASCII(string hex)
{
    string ascii = "";
    for (size_t i = 0; i < hex.length(); i += 2)
    {
        string part = hex.substr(i, 2);
        char ch = stoul(part, nullptr, 16);
        ascii += ch;
    }
    return ascii;
}
vector<uint8_t> convertStringToUint8Array(string s)
{
    string spacedS;
    for (int i = 0; i < s.size(); i += 2)
    {
        spacedS += s[i];
        spacedS += s[i + 1];
        spacedS += " ";
    }
    vector<uint8_t> state;
    istringstream hex_chars_stream(spacedS);
    unsigned int c;

    while (hex_chars_stream >> hex >> c)
    {
        state.push_back((uint8_t)c);
    }
    return state;
}

string convertUINT8ArrayToString(vector<uint8_t> &state)
{
    std::stringstream stream;
    for (int i = 0; i < state.size(); i++)
    {

        stream << std::setfill('0') << std::setw(sizeof(uint8_t) * 2)
               << std::hex << (int)state[i];
    }
    return stream.str();
}

vector<string> convertHexStringToCharArray(string str)
{
    vector<string> charArray;
    for (size_t i = 0; i < str.length(); i += 2)
    {
        charArray.push_back(str.substr(i, 2));
    }
    return charArray;
}

/*  IV functions   */

int increment_function(string nonce)
{
    return -1;
}

string initializationVector(string nonce, string key)
{
    return AES_Encrypt(nonce, key);
}

/*   Xoring Strings Functions  */

string xor_arrays(const vector<string> &arr1, const vector<string> &arr2)
{
    vector<string> result;
    if (arr1.size() != arr2.size())
    {
        cerr << "Error: arrays must be of equal size\n";
        return "";
    }
    for (size_t i = 0; i < arr1.size(); ++i)
    {
        string hex_str1 = arr1[i];
        string hex_str2 = arr2[i];
        unsigned int val1, val2;
        istringstream iss1(hex_str1), iss2(hex_str2);
        iss1 >> hex >> val1;
        iss2 >> hex >> val2;
        if (!iss1 || !iss2)
        {
            cerr << "Error: invalid hex string\n";
            return "";
        }
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << std::hex << (val1 ^ val2);
        result.push_back(oss.str());
    }
    stringstream ss;
    for (const auto &str : result)
    {
        ss << str;
    }
    return ss.str();
}
string xor_2_strings(string str1, string str2)
{
    vector<string> arr1 = convertHexStringToCharArray(str1);
    vector<string> arr2 = convertHexStringToCharArray(str2);
    string result = xor_arrays(arr1, arr2);
    return result;
}

/*   Padding Functions   */

vector<uint8_t> pkcs7_pad(const vector<uint8_t> &data, int block_size)
{
    int padding_size = block_size - (data.size() / 2) % block_size;
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(sizeof(uint8_t) * 2)
           << std::hex << padding_size;
    vector<uint8_t> padded_data(data);
    for (int i = 0; i < padding_size; i++)
    {
        padded_data.push_back(stream.str()[0]);
        padded_data.push_back(stream.str()[1]);
    }
    return padded_data;
}

string RemovePadding(string paddedString)
{
    vector<uint8_t> padded_data = convertStringToUint8Array(paddedString);
    uint8_t padding_size = padded_data.back(); // Get padding size from last byte
    vector<uint8_t> data(padded_data.begin(), padded_data.end() - padding_size);
    return convertUINT8ArrayToString(data);
}

/*   Adjusting Input For CBC_encrypt  */

vector<string> adjustCBCInput(string input)
{
    vector<uint8_t> temp;
    for (auto x : input)
    {
        temp.push_back(x);
    }

    vector<uint8_t> paddedInput = pkcs7_pad(temp, 16);
    vector<string> paddedInputStringValues;

    for (int i = 0; i < (paddedInput.size() / 32); i++)
    {
        vector<uint8_t> state;
        for (int j = 0; j < 32; j++)
        {
            state.push_back(paddedInput[i * 32 + j]);
        }
        std::stringstream stream;
        for (int i = 0; i < state.size(); i++)
        {

            stream << state[i];
        }
        paddedInputStringValues.push_back(stream.str());
    }

    return paddedInputStringValues;
}

/*   CBC functions  */

// This function returns cipher text as a hex string
string CBC_encrypt(string input, string key)
{
    vector<string> inputVector = adjustCBCInput(input);
    vector<string> cipherTextVect;
    string cipherText;
    string IV = "000102030405060708090a0b0c0d0e0f";
    cipherTextVect.push_back(IV);
    for (int i = 0; i < inputVector.size(); i++)
    {
        cipherTextVect.push_back(AES_Encrypt(xor_2_strings(cipherTextVect[i], inputVector[i]), key));
    }
    for (auto x : cipherTextVect)
    {
        cipherText += x;
    }
    return cipherText;
}

// cipher text should be in hex. Return Value is in hex.
string CBC_decrypt(string cipher, string key)
{
    vector<string> plainTextVector;
    string plainText = "";
    vector<string> cipherVect;
    for (size_t i = 0; i < cipher.length(); i += 32)
    {
        cipherVect.push_back(cipher.substr(i, 32));
    }

    for (int i = 1; i < cipherVect.size(); i++)
    {
        plainTextVector.push_back(xor_2_strings(AES_Decrypt(cipherVect[i], key), cipherVect[i - 1]));
    }

    for (auto x : plainTextVector)
    {
        plainText += x;
    }
    plainText = RemovePadding(plainText);
    return plainText;
}

int main()
{
    string originalText = "6bc1bee22e409f96e93d7e117393172aae2d8a571e03ac9c9eb76fac45af8e5130c81c46a35ce411e5fbc1191a0a52eff69f2445df4f9b17ad2b417be66c3710";
    string cipherText = CBC_encrypt(originalText, "2b7e151628aed2a6abf7158809cf4f3c");
    string plainText = CBC_decrypt(cipherText, "2b7e151628aed2a6abf7158809cf4f3c");
    bool test = originalText == plainText;
    cout << test << endl;
}
