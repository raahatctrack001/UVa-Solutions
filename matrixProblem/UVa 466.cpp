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

// mirror_transform.cpp
#include <bits/stdc++.h>
using namespace std;

class PatternMatrix {
private:
    int dimension;
    vector<string> original;
    vector<string> transformed;

public:
    PatternMatrix(int n) : dimension(n) {
        original.resize(n);
        transformed.resize(n);

        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            ss >> original[i] >> transformed[i];
        }
    }

    vector<string> getOriginal() const {
        return original;
    }

    vector<string> getTransformed() const {
        return transformed;
    }
};

class PatternTransformer {
public:
    static vector<string> rotate90(const vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<string> rotated(m, string(n, ' '));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                rotated[j][n - 1 - i] = matrix[i][j];
        return rotated;
    }

    static vector<string> rotate180(const vector<string>& matrix) {
        return rotate90(rotate90(matrix));
    }

    static vector<string> rotate270(const vector<string>& matrix) {
        return rotate90(rotate180(matrix));
    }

    static vector<string> reflectVertical(const vector<string>& matrix) {
        vector<string> reflected = matrix;
        reverse(reflected.begin(), reflected.end());
        return reflected;
    }
};

class MirrorAnalyzer {
private:
    PatternMatrix pattern;
    int patternNumber;

public:
    MirrorAnalyzer(PatternMatrix pm, int pNo) : pattern(pm), patternNumber(pNo) {}

    void analyze() {
        vector<string> orig = pattern.getOriginal();
        vector<string> target = pattern.getTransformed();

        cout << "Pattern " << patternNumber << " ";

        if (orig == target) {
            cout << "was preserved." << endl;
        } else if (PatternTransformer::rotate90(orig) == target) {
            cout << "was rotated 90 degrees." << endl;
        } else if (PatternTransformer::rotate180(orig) == target) {
            cout << "was rotated 180 degrees." << endl;
        } else if (PatternTransformer::rotate270(orig) == target) {
            cout << "was rotated 270 degrees." << endl;
        } else if (PatternTransformer::reflectVertical(orig) == target) {
            cout << "was reflected vertically." << endl;
        } else {
            vector<string> reflected = PatternTransformer::reflectVertical(orig);
            if (PatternTransformer::rotate90(reflected) == target) {
                cout << "was reflected vertically and rotated 90 degrees." << endl;
            } else if (PatternTransformer::rotate180(reflected) == target) {
                cout << "was reflected vertically and rotated 180 degrees." << endl;
            } else if (PatternTransformer::rotate270(reflected) == target) {
                cout << "was reflected vertically and rotated 270 degrees." << endl;
            } else {
                cout << "was improperly transformed." << endl;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string line;
    int testCase = 1;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int n;
        ss >> n;
        PatternMatrix pm(n);
        MirrorAnalyzer analyzer(pm, testCase++);
        analyzer.analyze();
    }

    return 0;
}
