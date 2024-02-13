#include <bits/stdc++.h>
using namespace std;

/*
----------------
    input
    -----

ABSJHSDASDFEFVSA
6
A
B
C
G
V
S
-----------------
    OUTPUT
    -------
3
1
0
0
1
4

*/

int main()
{
    string s;
    cin >> s; // ABSJHSDASDFEFVSA

    // pre compute - hashing table
    int hash[26] = {0}; // since A-Z total 26 chars are there.
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'A'; // subtracting the ascii value of 'A' from the character of the string to get the index of int
        hash[idx] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << hash[c - 'A'] << endl;
    }

    return 0;
}