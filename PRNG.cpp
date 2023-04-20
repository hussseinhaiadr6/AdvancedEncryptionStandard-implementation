#include <openssl/rand.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdint>

using namespace std;
string RandomKeyGenrator(int key_size){
  // Generate a 128-bit (16-byte) random key
  // here we are declaring a constant int of to be 16 which is going to be be represent the key length of 16 bytes 
  // here we are definety an array of U_int8  to be of size 16 
  uint8_t key[key_size];
  // here we are checking of RAND_bytes fails 
  if (!RAND_priv_bytes(key, key_size))
  {
    cerr << "Error: Failed to generate random key" << endl;
    return NULL;
  }

  // Print the key in hexadecimal format
  stringstream key_stream;
  for (int i = 0; i < key_size; ++i)
  {
    // set ffill will add a padding of 0 example if the byte resulted in 0d as hex ouptut wihtout this I/O maipulator 
    // we will get  " d" in the oupt so this will make the output "0d"
    // setw(2) this I/O manipulator set the width of the next ouptut to 2  meaning the each byte is going
    // to be 2 characters 
    key_stream << hex << setw(2) << setfill('0') << static_cast<int>(key[i]);
  }
return  key_stream.str() ;

}
int main(){
    string key;
    key =RandomKeyGenrator(16);
    cout<<key;
    
    
}









