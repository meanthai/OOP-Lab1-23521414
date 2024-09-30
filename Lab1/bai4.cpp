#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ii pair<int, int>
#define iii pair<ll, pair<int, int>>
#define MASK(c) (1LL << (c))
const ll N =  1e6 + 30;
const ll inf = 1e9 + 7;
const ll base = 7013;
using namespace std;

/*
     /\_/\
    (  ._.)
    / >() \>()
*/

// Tính toán hàm số sin(x) theo công thức của đề bài với sai số xấp xỉ nhỏ hơn 0.00001 (Đầu vào là giá trị x, đầu ra là kqua hàm sin(x))
double calculate(double x){
    double sinx = 0, n = 0, sign = 1.0, tmp = 1.0 * x;
    while(!(tmp < 0.00001)){
        sinx += tmp * sign;
        n++;
        tmp = tmp * x * x / ((2 * n) * (2 * n + 1));
        sign = -sign;
    }
    return sinx * 1.0;
}

// Hàm xử lý chính input và function sin(x)
void process4()
{
    double x;
    cout << "- Nhap gia tri cua x:" << endl;
    cin >> x;
    cout << "--> Ket qua cua ham sin(x) co gia tri la: " << endl;
    cout << fixed << setprecision(5) << calculate(x) << endl;
    return;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    while(test --) process4();
    return 0;
}
