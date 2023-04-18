#include "stdint.h"
#include <iostream>
#include <array>
using namespace std;

void shiftRows(array<array<uint8_t, 4>, 4> &state)
{
    uint8_t temp;

    // shifting the second row
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    // shifting the third row
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // shifting the fourth row
    temp = state[3][0];
    state[3][0] = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = temp;
}

void invShiftRows(array<array<uint8_t, 4>, 4> &state)
{
    uint8_t temp;

    // shifting the second row
    temp = state[1][3];
    state[1][3] = state[1][2];
    state[1][2] = state[1][1];
    state[1][1] = state[1][0];
    state[1][0] = temp;

    // shifting the third row
    temp = state[2][3];
    state[2][3] = state[2][1];
    state[2][1] = temp;
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;

    // shifting the fourth row
    temp = state[3][3];
    state[3][3] = state[3][0];
    state[3][0] = state[3][1];
    state[3][1] = state[3][2];
    state[3][2] = temp;
}

int main()
{
    array<array<uint8_t, 4>, 4> state = {0x87, 0xF2, 0x4D, 0x97, 0x6E, 0x4C, 0x90, 0xEC, 0x46, 0xE7, 0x4A, 0xC3, 0xA6, 0x8C, 0xD8, 0x95};
    shiftRows(state);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    invShiftRows(state);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }
}