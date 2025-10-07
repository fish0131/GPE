#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

// �Ω�Ƨ��I�ɪ�����]x �p�����F�Y x �ۦP�h y �p�����^
bool cmpPoint(const Point &a, const Point &b) {
    if (fabs(a.x - b.x) > 1e-9) return a.x < b.x;
    return a.y < b.y;
}

// �p��V�q OA �� OB ���e�n
// �P�_���s��V�G>0 -> ����A<0 -> �k��A=0 -> �@�u 
double cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// �إY�]�]Monotone Chain�^
// �^�ǥY�]���I�C��]�̫�@�I�|���ƲĤ@�I�H��K�j��B��^
vector<Point> convexHull(vector<Point> &pts) {
    int n = pts.size();
    vector<Point> H;  // �Ȧs�u�Y�ߡv�}�C 
    if (n < 3) return H;
	
	// �ƧǨϱo�ڭ̯�q�̥��U���I�}�l���y��̥k�W���I 
    sort(pts.begin(), pts.end(), cmpPoint);
    
    // �U�b�� (����k) �]�t�̥k���I 
    for (int i = 0; i < n; i++) {
    	// �O�� H �����ݩl�׬��Y���]�Y�Φ�����^
    	// �Y > 0�G�q P_{k-1}��P_k��pts[i] �O����]�}�n�A�i�O�d P_k�^�C
		// �Y <= 0�G�N�� P_k �M pts[i] �P�e�@�q���O����]�����u�Υk��^�A�]�� P_k ���O�Y�ߪ����n���I�A�n�u�X�]pop_back()�^�C
        while (H.size() >= 2 && cross(H[H.size()-2], H[H.size()-1], pts[i]) <= 0)
            H.pop_back();
        H.push_back(pts[i]);
    }
    // �W�b�� (�k�쥪) ���L�̥k���I 
    int lowerSize = H.size(); // �O���U�b���c�ا����� H ���j�p�]�ΨӰϤ��U�b�P�W�b�^�C�o�ӭȥΦb�W�b���c�عL�{���P�_���A�T�O�b�u�X�I�ɤ��|��U�b�������n�I���u���C
    for (int i = n-2; i >= 0; i--) {
        while (H.size() >= lowerSize + 1 && cross(H[H.size()-2], H[H.size()-1], pts[i]) <= 0)
            H.pop_back();
        H.push_back(pts[i]);
    }
    return H;
}

// �p��Y�h��Ϊ���� (centroid)�A��J�O�Y�]�A���]�̫�@�I�P�Ĥ@�I����
Point centroid(const vector<Point> &poly) {
    int n = poly.size();
    double A2 = 0.0;  // 2 �ѭ��n (���V)
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
    // A2 = 2 * Area ���V
    // ��ߤ������������O 6A = 3 * (2A) = 3 * A2
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
        // �`�N�GconvexHull �^�ǳ̫�@�I�O���ƲĤ@�I
        Point c = centroid(hull);
        cout << fixed << setprecision(3) 
             << c.x << " " << c.y << "\n";
    }
    return 0;
}
