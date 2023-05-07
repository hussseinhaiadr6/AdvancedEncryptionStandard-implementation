#include <iostream>
#include <array>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

void print(array<array<uint8_t, 4>, 4> &state)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << std::setfill('0') << std::setw(sizeof(uint8_t) * 2) << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }
}
array<array<uint8_t, 4>, 4> convertStringTo2DStateArray(string s)
{
    string spacedS;
    for (int i = 0; i < s.size(); i += 2)
    {
        spacedS += s[i];
        spacedS += s[i + 1];
        spacedS += " ";
    }

    array<array<uint8_t, 4>, 4> state;
    istringstream hex_chars_stream(spacedS);
    unsigned int c;
    int i = 0;
    int j = 0;
    while (hex_chars_stream >> hex >> c)
    {
        state[i][j] = (uint8_t)c;
        i++;
        if (i == 4)
        {
            j += 1;
            i = 0;
        }
    }
    return state;
}
string convert2DStateArrayToString(array<array<uint8_t, 4>, 4> &state)
{
    std::stringstream stream;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            stream << setfill('0') << setw(sizeof(uint8_t) * 2)
                   << hex << (int)state[j][i];
        }
    }
    return stream.str();
}
array<uint8_t, 16> convertStringTo1DStateArray(string s)
{
    string spacedS;
    for (int i = 0; i < s.size(); i += 2)
    {
        spacedS += s[i];
        spacedS += s[i + 1];
        spacedS += " ";
    }
    array<uint8_t, 16> state;
    istringstream hex_chars_stream(spacedS);
    unsigned int c;
    int i = 0;

    while (hex_chars_stream >> hex >> c)
    {
        state[i] = (uint8_t)c;
        i++;
    }
    return state;
}

string convert1DStateArrayToString(array<uint8_t, 16> &state)
{
    std::stringstream stream;
    for (int i = 0; i < 16; i++)
    {

        stream << std::setfill('0') << std::setw(sizeof(uint8_t) * 2)
               << std::hex << (int)state[i];
    }
    return stream.str();
}
int main()
{
    // array<uint8_t,16> state = convertStringTo1DStateArray("00000000000000000000000000000000");
    //  for (int j = 0; j < 16; j++)
    //     {
    //         cout << std::setfill('0') << std::setw(sizeof(uint8_t) * 2) << hex << (int)state[j] << " ";
    //     }
    //     cout << endl;

    array<array<uint8_t, 4>, 4> state = convertStringTo2DStateArray("10a58869d74be5a374cf867cfb473859");
    string str = convert2DStateArrayToString(state);
    cout << str;
    array<uint8_t, 16> state2 = convertStringTo1DStateArray("00000000000000000000000000000000");
    string s = convert1DStateArrayToString(state2);
    cout << s;
}
