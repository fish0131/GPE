#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

// 用於排序點時的比較（x 小的先；若 x 相同則 y 小的先）
bool cmpPoint(const Point &a, const Point &b) {
    if (fabs(a.x - b.x) > 1e-9) return a.x < b.x;
    return a.y < b.y;
}

// 計算向量 OA × OB 的叉積
// 判斷轉彎方向：>0 -> 左轉，<0 -> 右轉，=0 -> 共線 
double cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// 建凸包（Monotone Chain）
// 回傳凸包頂點列表（最後一點會重複第一點以方便迴圈運算）
vector<Point> convexHull(vector<Point> &pts) {
    int n = pts.size();
    vector<Point> H;  // 暫存「凸殼」陣列 
    if (n < 3) return H;
	
	// 排序使得我們能從最左下的點開始掃描到最右上的點 
    sort(pts.begin(), pts.end(), cmpPoint);
    
    // 下半部 (左到右) 包含最右端點 
    for (int i = 0; i < n; i++) {
    	// 保持 H 的尾端始終為凸的（即形成左轉）
    	// 若 > 0：從 P_{k-1}→P_k→pts[i] 是左轉（良好，可保留 P_k）。
		// 若 <= 0：代表 P_k 和 pts[i] 與前一段不是左轉（為直線或右轉），因此 P_k 不是凸殼的必要頂點，要彈出（pop_back()）。
        while (H.size() >= 2 && cross(H[H.size()-2], H[H.size()-1], pts[i]) <= 0)
            H.pop_back();
        H.push_back(pts[i]);
    }
    // 上半部 (右到左) 跳過最右端點 
    int lowerSize = H.size(); // 記錄下半部構建完成後 H 的大小（用來區分下半與上半）。這個值用在上半部構建過程的判斷中，確保在彈出點時不會把下半部的必要點給彈掉。
    for (int i = n-2; i >= 0; i--) {
        while (H.size() >= lowerSize + 1 && cross(H[H.size()-2], H[H.size()-1], pts[i]) <= 0)
            H.pop_back();
        H.push_back(pts[i]);
    }
    return H;
}

// 計算凸多邊形的質心 (centroid)，輸入是凸包，假設最後一點與第一點重複
Point centroid(const vector<Point> &poly) {
    int n = poly.size();
    double A2 = 0.0;  // 2 ×面積 (有向)
    double Cx_times_6A = 0.0, Cy_times_6A = 0.0;

    for (int i = 0; i < n - 1; i++) {
        double x1 = poly[i].x;
        double y1 = poly[i].y;
        double x2 = poly[i+1].x;
        double y2 = poly[i+1].y;
        double crossTerm = x1 * y2 - x2 * y1;  // x_i y_{i+1} - x_{i+1} y_i
        A2 += crossTerm;
        Cx_times_6A += (x1 + x2) * crossTerm;
        Cy_times_6A += (y1 + y2) * crossTerm;
    }
    // A2 = 2 * Area 有向
    // 質心公式中的分母是 6A = 3 * (2A) = 3 * A2
    double A = A2 / 2.0;
    double Cx = Cx_times_6A / (3.0 * A2);
    double Cy = Cy_times_6A / (3.0 * A2);
    return Point(Cx, Cy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (!cin || n < 3) break;

        vector<Point> pts(n);
        for (int i = 0; i < n; i++) {
            cin >> pts[i].x >> pts[i].y;
        }
        vector<Point> hull = convexHull(pts);
        // 注意：convexHull 回傳最後一點是重複第一點
        Point c = centroid(hull);
        cout << fixed << setprecision(3) 
             << c.x << " " << c.y << "\n";
    }
    return 0;
}
