#include<bits/stdc++.h>
using namespace std;

string encryptMessage(string msg, int a, int b)
{
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if(msg[i]!=' ')

            cipher = cipher +
                        (char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
        else
            cipher += msg[i];    
    }
    return cipher;
}
 
string decryptCipher(string cipher, int a, int b)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;

    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;

        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if(cipher[i]!=' ')

            msg = msg +
                       (char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
        else
            msg += cipher[i];
    }
 
    return msg;
}
 
int main(void)
{
    START:
    string text, retry;
    int a, b;

    cout << "Input:" << endl;
    cin >> text;

    cout << "Input Key a:" << endl;
    cin >> a;
    cout << "Input Key b:" << endl;
    cin >> b;

    string cipherText = encryptMessage(text, a, b);
    cout << "Encript: " << cipherText<<endl;
    cout << "Decript: " << decryptCipher(cipherText, a, b) << endl;
    cout << "Ulang?(Y/N):" << endl;
    cin >> retry;
    if (retry == "Y")
        goto START;
    return 0;

}