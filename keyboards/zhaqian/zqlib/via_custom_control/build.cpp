#include <iostream>
using namespace std;

int main (int argc, char **argv)
{
    for (int i = 0; i < 66; i ++) {
        cout << "[\"Led " << i << "\", " << i + 4 << "]," << endl;
    }
}