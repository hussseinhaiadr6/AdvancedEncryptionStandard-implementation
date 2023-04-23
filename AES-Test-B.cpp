#include "pch.h"
#include "AES.h"

TEST(AESTest, Test1)
{
    string plaintext = "f34481ec3cc627bacd5dc3fb08f273e6";
    string key = "00000000000000000000000000000000";
    string expected_ciphertext = "0336763e966d92595a567cc9ce537f5e";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test2)
{
    string plaintext = "9798c4640bad75c7c3227db910174e72";
    string key = "00000000000000000000000000000000";
    string expected_ciphertext = "a9a1631bf4996954ebc093957b234589";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test3)
{
    string plaintext = "96ab5c2ff612d9dfaae8c31f30c42168";
    string key = "00000000000000000000000000000000";
    string expected_ciphertext = "ff4f8391a6a40ca5b25d23bedd44a597";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test4)
{
    string plaintext = "6a118a874519e64e9963798a503f1d35";
    string key = "00000000000000000000000000000000";
    string expected_ciphertext = "dc43be40be0e53712f7e2bf5ca707209";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test5)
{
    string plaintext = "cb9fceec81286ca3e989bd979b0cb284";
    string key = "00000000000000000000000000000000";
    string expected_ciphertext = "92beedab1895a94faa69b632e5cc47ce";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test6)
{
    string plaintext = "b26aeb1874e47ca8358ff22378f09144";
    string key = "00000000000000000000000000000000";
    string expected_ciphertext = "459264f4798f6a78bacb89c15ed3d601";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
TEST(AESTest, Test7)
{
    string plaintext = "58c8e00b2631686d54eab84b91f0aca1";
    string key = "00000000000000000000000000000000";
    string expected_ciphertext = "08a4e2efec8a8e3312ca7460b9040bbf";
    string expected_plaintext = plaintext;
    string ciphertext = AES_Encrypt(plaintext, key);
    string decrypted_plaintext = AES_Decrypt(ciphertext, key);
    EXPECT_EQ(ciphertext, expected_ciphertext);
    EXPECT_EQ(decrypted_plaintext, expected_plaintext);
}
