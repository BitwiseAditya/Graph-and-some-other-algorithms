#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, int sourceStick, int helpStick, int destinationStick)
{
    if (n == 1)
    {
        cout << "Move Disk " << n << "From Rod" << sourceStick << "To Rod " << destinationStick << endl;
        return;
    }

    towerOfHanoi(n - 1, sourceStick, destinationStick, helpStick);
    cout << "Move Disk " << n << "From Rod" << sourceStick << "To Rod " << destinationStick << endl;
    towerOfHanoi(n - 1, helpStick, sourceStick, destinationStick);
}
// Total Moves == pow(2,n) - 1;
// Time Complexity == O(pow(2,n));