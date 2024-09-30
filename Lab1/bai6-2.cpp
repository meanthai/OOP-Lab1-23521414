#include <bits/stdc++.h>
#define fi(i,a,b) for(i=a;i<=b;i++)
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

// Object Student và các attributes để lưu trữ thông tin
struct Student {
    string name;
    float math;
    float literature;
    float english;
    float GPA;
    string evaluation;
};

// Hàm dùng để xét điểm toán lớn hoặc bé hơn
bool cmp(Student x, Student y) {
    return x.math < y.math;
}

// Hàm kiểm tra điểm hợp lý
bool check(float x) {
    return x >= 0.0 && x <= 10.0;
}

// Kiểm tra tên hợp lý
bool isValidName(const string& name) {
    // Check if name is empty or exceeds a reasonable length
    if (name.empty() || name.length() > 50) return false;

    // Check if name contains only valid characters (letters and spaces)
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false; // Only allow letters and spaces
    }
    return true;
}

// Calculate GPA
float GPACalculation(Student x) {
    return (x.math * 2 + x.literature + x.english) / 4.0;
}

// Tìm kiếm học sinh theo tên
void searchByName(const string& searchTerm, const vector<Student>& students) {
    bool found = false;
    for (const auto& student : students) {
        if (student.name.find(searchTerm) != string::npos) {
            if (!found) {
                cout << "Danh sach cac hoc sinh co ten \"" << searchTerm << "\" la:" << endl;
                found = true;
            }
            cout << "+) Hoc sinh " << student.name << "." << endl;
        }
    }
    if (!found) {
        cout << "Khong tim thay hoc sinh nao co ten \"" << searchTerm << "\"." << endl;
    }
}

// Hàm input nhập thông tin cho mỗi học sinh
void inputInformation(Student& student, int index) {
    cout << "+) Nhap ten cua hoc sinh thu " << index + 1 << ": " << endl; 
    cout << endl;
    cin.ignore();
    while (true) {
        getline(cin, student.name);
        if (isValidName(student.name)) break;
        cout << "(*): Ten khong hop le, vui long nhap lai." << endl;
    }

    cout << "+) Nhap diem mon toan cua hoc sinh thu " << index + 1 << ": " << endl; 
    while (cin >> student.math) {
        if (check(student.math)) break;
        cout << "(*) Diem da nhap khong hop le, vui long nhap lai" << endl;
    }
    cout << "+) Nhap diem mon van cua hoc sinh thu " << index + 1 << ": " << endl; 
    while (cin >> student.literature) {
        if (check(student.literature)) break;
        cout << "(*) Diem da nhap khong hop le, vui long nhap lai" << endl;
    }        
    cout << "+) Nhap diem mon tieng anh cua hoc sinh thu " << index + 1 << ": " << endl; 
    while (cin >> student.english) {
        if (check(student.english)) break;
        cout << "(*) Diem da nhap khong hop le, vui long nhap lai" << endl;
    }
}

// Hàm xử lý chính input và thực hiện các functions
void process6() {
    int n;
    cout << "Nhap so luong hoc sinh: " << endl;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the buffer

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cout << "- Nhap thong tin cua hoc sinh thu " << i + 1 << ":" << endl;
        inputInformation(students[i], i);
    }

    Student best = students[0];

    cout << "- Diem trung binh cua moi hoc sinh la: " << endl;
    for (auto & student : students) {
        student.GPA = GPACalculation(student);
        if (student.GPA >= 9) student.evaluation = "Xuat sac";
        else if (student.GPA >= 8) student.evaluation = "Gioi";
        else if (student.GPA >= 6.5) student.evaluation = "Kha";
        else if (student.GPA >= 5) student.evaluation = "Trung binh";
        else student.evaluation = "Yeu";

        if (best.GPA < student.GPA) best = student;

        cout << "+) Diem trung binh cua hoc sinh ten " << student.name << " la: " 
             << fixed << setprecision(2) << student.GPA << " - Xep loai: " << student.evaluation << endl;
    }

    cout << "- Hoc sinh co diem trung binh (GPA) cao nhat la: " << best.name << " - GPA: " << fixed << setprecision(2) << best.GPA << endl;

    string searchTerm;
    cout << "Nhap ten cua hoc sinh muon tim kiem: " << endl;
    cin.ignore();
    getline(cin, searchTerm);
    searchByName(searchTerm, students);

    cout << "- Danh sach hoc sinh co diem toan thap nhat la: " << endl;
    sort(students.begin(), students.end(), cmp);
    for (const auto& student : students) {
        cout << "+) Hoc sinh ten '" << student.name << "' co diem toan la: " << student.math << endl;
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
