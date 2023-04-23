#include "pch.h"
#include "AES.h"

TEST(AESTest, Test1)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "10a58869d74be5a374cf867cfb473859";
    string expected_ciphertext = "6d251e6944b051e04eaa6fb4dbf78465";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test2)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "caea65cdbb75e9169ecd22ebe6e54675";
    string expected_ciphertext = "6e29201190152df4ee058139def610bb";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test3)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "a2e2fa9baf7d20822ca9f0542f764a41";
    string expected_ciphertext = "c3b44b95d9d2f25670eee9a0de099fa3";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test4)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "b6364ac4e1de1e285eaf144a2415f7a0";
    string expected_ciphertext = "5d9b05578fc944b3cf1ccf0e746cd581";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test5)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "64cf9c7abc50b888af65f49d521944b2";
    string expected_ciphertext = "f7efc89d5dba578104016ce5ad659c05";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test6)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "47d6742eefcc0465dc96355e851b64d9";
    string expected_ciphertext = "0306194f666d183624aa230a8b264ae7";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test7)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "3eb39790678c56bee34bbcdeccf6cdb5";
    string expected_ciphertext = "858075d536d79ccee571f7d7204b1f67";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test8)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "64110a924f0743d500ccadae72c13427";
    string expected_ciphertext = "35870c6a57e9e92314bcb8087cde72ce";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test9)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "18d8126516f8a12ab1a36d9f04d68e51 ";
    string expected_ciphertext = "6c68e9be5ec41e22c825b7c7affb4363";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test10)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "f530357968578480b398a3c251cd1093";
    string expected_ciphertext = "f5df39990fc688f1b07224cc03e86cea";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test11)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "da84367f325d42d601b4326964802e8e ";
    string expected_ciphertext = "bba071bcb470f8f6586e5d3add18bc66";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test12)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "e37b1c6aa2846f6fdb413f238b089f23";
    string expected_ciphertext = "43c9f7e62f5d288bb27aa40ef8fe1ea8";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test13)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "6c002b682483e0cabcc731c253be5674";
    string expected_ciphertext = "3580d19cff44f1014a7c966a69059de5";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test14)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "143ae8ed6555aba96110ab58893a8ae1";
    string expected_ciphertext = "806da864dd29d48deafbe764f8202aef";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test15)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "b69418a85332240dc82492353956ae0c";
    string expected_ciphertext = "a303d940ded8f0baff6f75414cac5243";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test16)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "71b5c08a1993e1362e4d0ce9b22b78d5";
    string expected_ciphertext = "c2dabd117f8a3ecabfbb11d12194d9d0";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test17)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "e234cdca2606b81f29408d5f6da21206";
    string expected_ciphertext = "fff60a4740086b3b9c56195b98d91a7b";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test18)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "13237c49074a3da078dc1d828bb78c6f";
    string expected_ciphertext = "8146a08e2357f0caa30ca8c94d1a0544";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test19)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "3071a2a48fe6cbd04f1a129098e308f8 ";
    string expected_ciphertext = "4b98e06d356deb07ebb824e5713f7be3";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test20)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "90f42ec0f68385f2ffc5dfc03a654dce";
    string expected_ciphertext = "7a20a53d460fc9ce0423a7a0764c6cf2";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test21)
{
    string plaintext = "00000000000000000000000000000000";
    string key = "febd9a24d8b65c1c787d50a4ed3619a9 ";
    string expected_ciphertext = "f4a70d8af877f9b02b4c40df57d45b17";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}