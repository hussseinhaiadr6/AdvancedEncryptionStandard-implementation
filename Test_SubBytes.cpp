#include "pch.h"
#include "SubBytes.h"


TEST(SubBytesTest, BasicTest) {
    array<array<uint8_t, 4>, 4> state = { 0x19, 0xa0, 0x9a, 0xe9,
                                0x3d, 0xf4, 0xc6, 0xf8,
                                0xe3, 0xe2, 0x8d, 0x48,
                                0xbe, 0x2b, 0x2a, 0x08 };
    array<array<uint8_t, 4>, 4> expected_state = { 0xd4, 0xe0, 0xb8, 0x1e,
                                         0x27, 0xbf, 0xb4, 0x41,
                                         0x11, 0x98, 0x5d, 0x52,
                                         0xae, 0xf1, 0xe5, 0x30 };
    subBytes(state);

    EXPECT_EQ(state, expected_state);

};

// Unit test for invSubBytes
TEST(InvSubBytesTest, BasicTest) {
    array<array<uint8_t, 4>, 4> state = { 0xd4, 0xe0, 0xb8, 0x1e,
                                         0x27, 0xbf, 0xb4, 0x41,
                                         0x11, 0x98, 0x5d, 0x52,
                                         0xae, 0xf1, 0xe5, 0x30 };
    array<array<uint8_t, 4>, 4> expected_state = { 0x19, 0xa0, 0x9a, 0xe9,
                                0x3d, 0xf4, 0xc6, 0xf8,
                                0xe3, 0xe2, 0x8d, 0x48,
                                0xbe, 0x2b, 0x2a, 0x08 };
    invSubBytes(state);

    EXPECT_EQ(state, expected_state);

}
