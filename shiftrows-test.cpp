

#include "pch.h"
#include "shiftrows.h"
using namespace std;




class Shiftrows_Test : public ::testing::Test {
protected:

    array<array<uint8_t, 4>, 4> state_;
    array<array<uint8_t, 4>, 4> expected_shifted_;
    array<array<uint8_t, 4>, 4> expected_inv_shifted_;

    void SetUp() override {

        state_ = { 0x87, 0xF2, 0x4D, 0x97 ,
                      0x6E, 0x4C, 0x90, 0xEC ,
                      0x46, 0xE7, 0x4A, 0xC3 ,
                      0xA6, 0x8C, 0xD8, 0x95 };

        expected_shifted_ = { 0x87, 0xF2, 0x4D, 0x97 ,
                                 0x4C, 0x90, 0xEC, 0x6E ,
                                 0x4A, 0xC3, 0x46, 0xE7 ,
                                  0x95, 0xA6, 0x8C,0xD8 };

        expected_inv_shifted_ = { 0x87, 0xF2, 0x4D, 0x97 ,
                                      0x6E, 0x4C, 0x90, 0xEC ,
                                      0x46, 0xE7, 0x4A, 0xC3 ,
                                      0xA6, 0x8C, 0xD8, 0x95 };
    }



};

// Test case for shiftRows function
TEST_F(Shiftrows_Test, ShiftRowsTest) {
    shiftRows(state_);

    // Compare expected and actual results
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(expected_shifted_[i][j], state_[i][j]);
        }
    }
}

// Test case for invShiftRows function
TEST_F(Shiftrows_Test, InvShiftRowsTest) {
    shiftRows(state_);
    invShiftRows(state_);

    // Compare expected and actual results
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(expected_inv_shifted_[i][j], state_[i][j]);
        }
    }
}

