#include <iostream>
#include <array>
#include <sstream>
#include "AesEnc.h"
typedef unsigned char uint8_t;
using namespace std;





// define the key schedule for example purposes
 array<uint8_t, 16> keyini{ {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
} };



void round(array<array<uint8_t, 4>, 4>& state,  array<uint8_t, 16>& round_key){
	cout<<"the state at the beginnig of the method"<<endl;
	for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }

    SubBytes(state);

    shiftRows(state);

	unsigned char **state_ptr = new unsigned char*[4];
for (int i = 0; i < 4; i++) {
    state_ptr[i] = new unsigned char[4];
    for (int j = 0; j < 4; j++) {
        state_ptr[i][j] = state[i][j];
    }
}
	mixColumns(state_ptr);
	//cout<<"after the mix column method"<<endl;
	for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        state[i][j] = state_ptr[i][j];
    }
}

    add_round_key(state,round_key);
	cout<<"rounded ended"<<endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }
}
array<array<uint8_t, 4>, 4> AES_Encrypt(array<array<uint8_t, 4>, 4> state1,string str){
    istringstream hex_chars_stream(str);
	unsigned char key[16];
	int i = 0;
	unsigned int c;
	while (hex_chars_stream >> hex >> c)
	{
		key[i] = c;
       // cout<<key[i]<<"hu"<<"\n";
		i++;
        
	}

	array<uint8_t, 176>* expandedKey_1;
expandedKey_1 = new array<uint8_t, 176>[176];

unsigned char* expandedKey = reinterpret_cast<unsigned char*>(expandedKey_1->data());
	KeyExpansion(key, expandedKey);
    for ( int i=0;i< 176;i++){
       // cout<<dec<<"Byte: "<<(int)i<<"  d";
       if( (int)expandedKey[i]>15){
        if ((i+1)%4==0){
            cout<<hex<<(int)expandedKey[i]<<endl;}
            else{
                cout<<hex<<(int)expandedKey[i]<<" ";
            }
       }
       else{
         if ((i+1)%4==0){
            cout<<"0"<<hex<<(int)expandedKey[i]<<endl;}
            else{
                cout<<"0"<<hex<<(int)expandedKey[i]<<" ";
            }
       }
  
    }
    
    add_round_key(state1, keyini);

	array<uint8_t, 176> myU8Array;
	unsignedCharToU8Array(expandedKey, myU8Array);
	int index=1;
	unsignedCharToU8Array(expandedKey, myU8Array);
	for( int i=1 ;i<=10;i++){
	
	
   	array<uint8_t, 16> tempArray{{myU8Array[index*16],myU8Array[index*16+1],myU8Array[index*16+2],myU8Array[index*16+3],myU8Array[index*16+4],myU8Array[index*16+5],myU8Array[index*16+6],myU8Array[index*16+7],myU8Array[index*16+8],myU8Array[index*16+9],myU8Array[index*16+10],myU8Array[index*16+11],myU8Array[index*16+12],myU8Array[index*16+13],myU8Array[index*16+14],myU8Array[index*16+15]}};
array<uint8_t, 16>& expandedkey1 = tempArray;
cout<<" the "<<index<<" reound key is :"<<endl;
for (int j = 0; j < 16; j++) {
        
            cout << hex << (int)expandedkey1[j] << " ";
        
        cout << endl;
    }

    index++;
	if(i<=9)round(state1,expandedkey1);
	
	}
	SubBytes((state1));
	shiftRows(state1);
	array<uint8_t, 16> tempArray{{myU8Array[160],myU8Array[161],myU8Array[162],myU8Array[163],myU8Array[164],myU8Array[165],myU8Array[166],myU8Array[167],myU8Array[168],myU8Array[169],myU8Array[170],myU8Array[171],myU8Array[172],myU8Array[173],myU8Array[174],myU8Array[175]}};
	add_round_key(state1,tempArray);

	
    return state1;

}


int main() {
	
     array<array<uint8_t, 4>, 4> state1{ {
        {0x00, 0x44, 0x88, 0xcc},
        {0x11, 0x55, 0x99, 0xdd},
        {0x22, 0x66, 0xaa, 0xee},
        {0x33, 0x77, 0xbb, 0xff}
    } };

    string str="00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f";

    state1=AES_Encrypt(state1,str);

    cout<<"output is: "<<endl;
		for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << (int)state1[i][j] << " ";
        }
        cout << endl;
    }
    
}

