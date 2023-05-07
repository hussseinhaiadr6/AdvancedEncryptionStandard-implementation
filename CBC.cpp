#include "AesEnc.h"
#include <vector>
#include <bitset>
using namespace std;

int increment_function(string nonce){
    return -1;
}


string initializationVector(string nonce,string key){
    return AES_Encrypt(nonce,key);
}

string xorStrings(string const &str1,string const &str2) {
    std::string binary1 = "";
    for (char const &c: str1) {
        binary1 += std::bitset<8>(c).to_string();
    }
    std::string binary2 = "";
    for (char const &c: str2) {
        binary2 += std::bitset<8>(c).to_string();
    }
    int len = binary1.length(); 
    string result = ""; // Initialize the result string
 
   // Perform XOR operation bit by bit
   for (int i = 0; i < len; i++) {
       // XOR of current bits and convert it to char ('0' or '1')
       char currentXOR = ((binary1[i] - '0') ^ (binary2[i] - '0')) + '0';
       // Append the currentXOR to the result string
       result += currentXOR;
   }
    return result;
}

vector<uint8_t> pkcs7_pad(const vector<uint8_t>& data, int block_size) {
    int padding_size = block_size - data.size() % block_size;
    vector<uint8_t> padded_data(data);
    padded_data.resize(data.size() + padding_size, padding_size);
   return padded_data;
}

vector<uint8_t> RemovePadding(const vector<uint8_t>& padded_data) {
    uint8_t padding_size = padded_data.back(); // Get padding size from last byte
    vector<uint8_t> data(padded_data.begin(), padded_data.end() - padding_size);
    return data;
}

vector<string> adjustCBCInput(string input){
    vector<uint8_t> temp;
     for (auto x: input)
    {   
        temp.push_back(x);
    }
    vector<uint8_t> paddedInput = pkcs7_pad(temp,16);
    vector<string> paddedInputStringValues;
    for(int i=0;i<(paddedInput.size()/16);i++){
        array<uint8_t, 16> state;
        for (int j=0;j<16;j++){
            state[j] = paddedInput[i*16 +j];
        }
        paddedInputStringValues.push_back(convert1DStateArrayToString(state));
    }
    return paddedInputStringValues;
}


string CBC(string input,string key){
    vector<string> inputVector = adjustCBCInput(input);
    string IV = initializationVector("",key);

}


int main(){
    cout<<xorStrings("0798c4640bad75c7c3227db910174e72","f798c4640bad7c7c3227db910174e72");
}
