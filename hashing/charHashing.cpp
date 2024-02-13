#include <bits/stdc++.h>
using namespace std;

/*
----------------
    input
    -----

ILOVEc++34eVer
6
E
e
+
c
V
4
-----------------
    OUTPUT
    -------
1
2
2
1
2
1

*/

int main()
{
    string s;
    cin >> s; // abcdefavddecde

    // pre compute - hashing table
    int hash[256] = {0}; // total 256 chars are there
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i]; // subtracting the ascii value of 'a' from the character of the string to get the index of int
        hash[idx] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }

    return 0;
}