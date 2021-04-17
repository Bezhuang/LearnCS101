//序列循环左移
#include <iostream>
#define N 50
using namespace std;
void Reverse(int R[], int l, int r)
{
    int i, j;
    int temp;
    for (i = l, j = r; i < j; ++i, --j)
    {
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }        
}
void RCR(int R[], int n, int p)
{
    if (p <= 0 || p >= n)
        cout << "ERROR" << endl;
    else
    {
        Reverse(R, 0, p - 1);
        Reverse(R, p, n - 1);
        Reverse(R, 0, n - 1);
    }    
}
int main()
{
    int L, i;
    int R[N], n;
    cin >> L;
    cin >> n;
    for (i = 0;i <= n - 1;++i)
        cin >> R[i];
    RCR(R, n, L);
    for (i = 0;i <= n - 1;++i)
        cout << R[i] << " ";
    cout << endl;
    return 0;
}
