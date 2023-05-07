#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

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

int main() {
    vector<uint8_t> data = {'H', 'H', 'l', 'l', 'o','p','e','r','t','y','u','j','H','H','H','H','H', 'H', 'l', 'l', 'o','p','e','r','t','y','u','j','H','H','H','H'};
    int block_size = 16;

    vector<uint8_t> padded_data_hex = pkcs7_pad(data, block_size);

    for (uint8_t c : padded_data_hex) {
        cout<<setfill('0')<<hex<<setw(2)<<static_cast<unsigned int>(c) << " ";
    }
    cout<<endl;
vector<uint8_t>unpadded= RemovePadding(padded_data_hex);
for (uint8_t c : unpadded) {
    //in hex format
        cout<<setfill('0')<<hex<<setw(2)<<static_cast<unsigned int>(c) << " ";
    }
    cout<<endl;
for (uint8_t c : unpadded) {
      // in string format
     cout<<static_cast<unsigned char>(c) << " ";
}
    return 0;
}

