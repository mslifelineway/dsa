#include <bits/stdc++.h>
using namespace std;

/*
----------------
    input
    -----

abcdefavddecde
6
a
b
c
e
d
f
-----------------
    OUTPUT
    -------
2
1
2
3
4
1

*/

int main()
{
    string s;
    cin >> s; // abcdefavddecde

    // pre compute - hashing table
    int hash[26] = {0}; // since a-z total 26 chars are there.
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a'; // subtracting the ascii value of 'a' from the character of the string to get the index of int
        hash[idx] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << hash[c - 'a'] << endl;
    }

    return 0;
}