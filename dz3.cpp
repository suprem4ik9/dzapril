#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100001];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int imin = 0;
    int ibest = 0;
    int jbest = 1;
    for (int j = 2; j < n; ++j)
    {
        if (a[j - 1] < a[imin])
            imin = j - 1;
        if (a[j] - a[imin] > a[jbest] - a[ibest])
        {
            jbest = j;
            ibest = imin;
        }
    }
    if (a[ibest] - a[jbest] == 0)
    {
        cout << 0 << " " << 0;
    }
    else
    {
        cout << ibest + 1 << " " << jbest + 1 << endl;
    }

}
