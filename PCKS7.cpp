#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

vector<uint8_t> pkcs7_pad(const vector<uint8_t>& data, int block_size) {
    int padding_size = block_size - data.size() % block_size;
    cout<<"size of the padding is:"<<padding_size<<endl;
    vector<uint8_t> padded_data(data);
    padded_data.resize(data.size() + padding_size, padding_size);
   return padded_data;
}

int main() {
    vector<uint8_t> data = {'H', 'H', 'l', 'l', 'o','p','e','r','t','y','u','j','H','H','H','H','H'};
    int block_size = 16;

    vector<uint8_t> padded_data_hex = pkcs7_pad(data, block_size);

    for (uint8_t c : padded_data_hex) {
        cout<<setfill('0')<<hex<<setw(2)<<static_cast<unsigned int>(c) << " ";
    }

    return 0;
}

