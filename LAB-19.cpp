
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char text[100];
    int key1 = 5, key2 = 7, key3 = 3;
    int iv = 10, cipher;

    cout << "Enter plaintext: ";
    cin.getline(text, 100);

    cout << "\nEncrypted text: ";

    for(int i = 0; i < strlen(text); i++)
    {
        cipher = text[i] ^ iv;
        cipher = cipher + key1;
        cipher = cipher - key2;
        cipher = cipher + key3;

        cout << cipher << " ";

        iv = cipher;
    }

    cout << endl;

    return 0;
}

