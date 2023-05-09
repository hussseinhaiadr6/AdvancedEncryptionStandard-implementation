#include <iostream>
#include <sstream>
#include <random>
#include <fstream>
#include <cassert>
#include"CBC.h"

string generate_hex_key() {
    stringstream ss;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    for (int i = 0; i < 32; i++) {  // Fixed length of 32 characters
        int value = dis(gen);
        ss << hex << value;
    }
    return ss.str();
}
void generate_hex_keys(int i) {
    for (int j = 0; j < i; j++) {
        std::string hex_key = generate_hex_key();
        std::ofstream output_file("Keys.txt", std::ios::app);
        if (output_file.is_open()) {
            output_file << hex_key << std::endl;
            output_file.close();
        } else {
            std::cout << "Error: could not open file for writing." << std::endl;
            return;
        }
    }
}

string generate_hex_string(int length) {
    if (length %2 !=0) length++;
    stringstream ss;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    for (int i = 0; i < length; i++) {
        int value = dis(gen);
        ss << hex << value;
    }
    return ss.str();
}

void generate_hex_strings(int i) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> length_dis(2, 1028);
    for (int j = 0; j < i; j++) {
        int length = length_dis(gen);
        string hex_string = generate_hex_string(length);
        ofstream output_file("hex_strings.txt", ios::app);
        if (output_file.is_open()) {
            output_file << hex_string << endl;
            output_file.close();
        } else {
            cout << "Error: could not open file for writing." << endl;
            return;
        }
    }
}

int main() {   
    // we have genarted 285 hex stirng so that we can test the the string are of different length 
     //generate_hex_strings(285);
    //generate_hex_keys(120);
    ifstream input_file("Keys.txt"); 
    string key;
    int keyindex;
 while (getline(input_file, key) ) {
        keyindex++;
        vector<string> tokens;
        istringstream iss(key);
        string token;
        while (getline(iss, token, ' ')) {
            tokens.push_back(token);
        }
        
        string key_sample = tokens[0];
      cout<< "key "<<keyindex<<" :" <<key_sample<<endl;
      // after hetting the key now we will loop on each plain text sample 
    ifstream input_file("hex_strings.txt"); 
    string line;
    int caseIndex=1;
    while (getline(input_file, line) ) {
        vector<string> tokens;
        istringstream iss(line);
        string token;
        while (getline(iss, token, ' ')) {
            tokens.push_back(token);
        }
        //cout<<"Case "<<caseIndex<<endl;
        string plain_text_sample = tokens[0];
    // cout<<plain_text_sample<<endl;
        
        string cipher = CBC_encrypt(plain_text_sample, key_sample);
        // cout<<"cipher is :"<<cipher<<endl;
        string decryption_ouptut= CBC_decrypt(cipher,key_sample);
       // cout<<decryption_ouptut<<endl;
        if ( decryption_ouptut==plain_text_sample){
            cout<<"key "<<keyindex<<": with text "<<caseIndex<<": has succeeded"<<endl;
        }
        else{
            cout<<"key "<<keyindex<<": with text "<<caseIndex<<": has failed"<<endl;
            cout<<"plain text sample:"<<plain_text_sample<<endl;
            cout<<endl<<endl;
            cout<<"decryption output:"<<decryption_ouptut<<endl;
            return 0;
        }
         caseIndex++;
   
    }
 }


    // input_file.close();    
    return 0;
}
