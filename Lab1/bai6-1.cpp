#include <bits/stdc++.h>
#define fi(i,a,b) for(i=a;i<=b;i++)
#define ll long long
#define ff first
#define ss second
#define ii pair<int, int>
#define iii pair<ll, pair<int, int>>
#define MASK(c) (1LL << (c))
const ll N =  1e5 + 30;
const ll inf = 1e9 + 7;
const ll base = 7013;
const ll oo=1e9+7;
using namespace std;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y)
        {
            x = y;
            return 1;
        }
        return 0;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y)
        {
            x = y;
            return 1;
        }
        return 0;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/*
     /\_/\
    (  ._.)
    / >() \>()
*/

ll powx[N], h[N]; // Khai báo mảng chứa mã Hash.

// Lấy mã Hash của một đoạn trong B để so sánh
ll getHash(int l, int r){
    return (h[r] - h[l-1] * powx[r - l + 1] + oo * oo) % oo;
}

// Hàm tính mã hash và duyệt các đoạn của mảng B để so sánh với mảng A
vector<int> countNumberExist(const vector<int> &a, const vector<int> &b, int n, int m) {
    vector<int> pos;

    if(n > m) return pos; // Mảng A nhiều phần tử hơn mảng B

    powx[0] = 1;

    // Tính mã hash cho mảng B
    for(int i = 1; i <= m; i++)
    {
        h[i] = (h[i - 1] * base + b[i]) % oo;
        powx[i] = powx[i - 1] * base % oo;
    }

    // Tính mã hash cho mảng A
    ll hashA = 0;
    for(int i = 1; i <= n; i++){
        hashA = (hashA * base + a[i]) % oo;
    }


    for(int i = 1; i <= m - n + 1; i++){
        if(getHash(i, i + n - 1) == hashA) pos.push_back(i);
    }
    return pos;
}

// Hàm xử lý chính input và các functions khác
void process6() {
    int n, m;
    vector<int> a, b;

    cout << "- Nhap so phan tu cua mang A: " << endl;
    cin >> n;
    cout << "- Nhap so phan tu cua mang B: " << endl;
    cin >> m;

    a.resize(n + 1);
    b.resize(m + 1);

    cout << "- Nhap cac phan tu cua mang A: " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << "- Nhap cac phan tu cua mang B: " << endl;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    vector<int> res = countNumberExist(a, b, n, m);

    cout << "- So lan mang A xuat hien trong mang B la: " << res.size() << endl;
    if(res.size()){
        cout << "- Mang A xuat hien tai cac vi tri sau:" << endl;
        for(auto x : res){
            cout << "+) Vi tri thu " << x << endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    while (test--) process6();
    return 0;
}
