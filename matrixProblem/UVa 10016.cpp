#include <bits/stdc++.h>
using namespace std;
 
#define fR(i, a, b) for (int i = (a); i < (b); i++)
#define fRD(i, a, b) for (int i = (a); i > (b); i--)
#define fRJ(i, a, b, j) for (int i = (a), i < (b); i += j)
#define fRJD(i, a, b, j) for (int i = (a), i > (b); i -= j)
#define fL(i, n) for (int i = 0; i < (n); i++)    
 
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cout << '>' << #x << ": " << x << endl;
#define printMap(mp) for(auto &it: mp) cout<<" ("<<it.F<<"-> "<<it.S<<") ";
#define printVector(v) for(auto &it: v) cout<<it<<" ";
#define printMatrix(v) for(auto &it: v) { for(auto &i: it) { cout<<i<<" "; cout<<endl;}}
#define rV(v) reverse(all(v));
#define cinV(v) for(auto &it: v) cin>>it;
#define sort(v) sort(all(v));
#define p_sort(f, m, e) partial_sort(f, m, e)
#define s_sort(v) stable_sort(all(v));

 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set<int> si;
typedef map<int, int> mii;

vector<string> tokenize(string &str){	
	vector <string> tokens;
    stringstream check1(str);
     
    string intermediate;
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
    return tokens;
}

#include <bits/stdc++.h>
using namespace std;

class Matrix {
private:
    int n;
    vector<vector<int>> mat;

public:
    Matrix(int size) : n(size), mat(size, vector<int>(size)) {}

    void readMatrix() {
        for (auto& row : mat)
            for (auto& elem : row)
                cin >> elem;
    }

    void printMatrix1() const {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << mat[i][j] << (j + 1 < n ? " " : "\n");
    }

    void upsideDownFlip(int ring) {
        int limit = n - ring - 1;
        for (int k = ring; k <= limit; ++k)
            swap(mat[ring][k], mat[limit][k]);

        for (int k = ring + 1; (k << 1) < n - 1; ++k) {
            int l = n - k - 1;
            swap(mat[k][ring], mat[l][ring]);
            swap(mat[k][limit], mat[l][limit]);
        }
    }

    void leftRightFlip(int ring) {
        int limit = n - ring - 1;
        for (int k = ring; k <= limit; ++k)
            swap(mat[k][ring], mat[k][limit]);

        for (int k = ring + 1; (k << 1) < n - 1; ++k) {
            int l = n - k - 1;
            swap(mat[ring][k], mat[ring][l]);
            swap(mat[limit][k], mat[limit][l]);
        }
    }

    void mainDiagonalFlip(int ring) {
        int limit = n - ring - 1;
        for (int k = ring + 1; k <= limit; ++k) {
            swap(mat[ring][k], mat[k][ring]);
            swap(mat[limit][k], mat[k][limit]);
        }
    }

    void inverseDiagonalFlip(int ring) {
        int limit = n - ring - 1;
        for (int k = limit - 1, l = ring + 1; k >= ring; --k, ++l) {
            swap(mat[ring][k], mat[l][limit]);
            swap(mat[l][ring], mat[limit][k]);
        }
    }

    void performAction(int action, int ring) {
        switch (action) {
            case 1: upsideDownFlip(ring); break;
            case 2: leftRightFlip(ring); break;
            case 3: mainDiagonalFlip(ring); break;
            case 4: inverseDiagonalFlip(ring); break;
        }
    }

    int getSize() const { return n; }
};

class ProblemSolver {
public:
    void processTestCases() {
        int testCases;
        cin >> testCases;

        while (testCases--) {
            int n;
            cin >> n;
            Matrix matrix(n);
            matrix.readMatrix();

            int rings = (n >> 1) + (n & 1);
            for (int i = 0; i < rings; ++i) {
                int actions;
                cin >> actions;
                for (int j = 0; j < actions; ++j) {
                    int action;
                    cin >> action;
                    matrix.performAction(action, i);
                }
            }

            matrix.printMatrix1();
        }
    }
};

int main() {
    fast_io;
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt",  "r",  stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ProblemSolver solver;
    solver.processTestCases();

    return 0;
}

