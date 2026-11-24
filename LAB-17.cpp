
#include <iostream>
using namespace std;

int main()
{
    int key[16];

    cout << "Enter 16 round keys:\n";

    for(int i = 0; i < 16; i++)
    {
        cin >> key[i];
    }

    cout << "\nDES Decryption Key Order:\n";

    for(int i = 15; i >= 0; i--)
    {
        cout << "K" << i + 1 << " = " << key[i] << endl;
    }

    cout << "\nDecryption uses reverse key order.";

    return 0;
}

