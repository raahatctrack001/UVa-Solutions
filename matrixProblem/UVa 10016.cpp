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

class Solution{
public:
	 void executeSolution(){
	 	int W, H, N;
    	while (cin >> W >> H >> N && (W || H || N)) {
        	vector<vector<bool>> board(W + 1, vector<bool>(H + 1, false));
	
        	for (int i = 0; i < N; ++i) {
        	    int x1, y1, x2, y2;
        	    cin >> x1 >> y1 >> x2 >> y2;
	
        	    int x_min = min(x1, x2);
        	    int x_max = max(x1, x2);
        	    int y_min = min(y1, y2);
        	    int y_max = max(y1, y2);
	
        	    for (int x = x_min; x <= x_max; ++x) {
        	        for (int y = y_min; y <= y_max; ++y) {
        	            board[x][y] = true;
        	        }
        	    }
        	}
	
        	int emptySpots = 0;
        	for (int x = 1; x <= W; ++x) {
        	    for (int y = 1; y <= H; ++y) {
        	        if (!board[x][y]) ++emptySpots;
        	    }
        	}
	
        	if (emptySpots == 0)
        	    cout << "There is no empty spots." << endl;
        	else if (emptySpots == 1)
        	    cout << "There is one empty spot." << endl;
        	else
        	    cout << "There are " << emptySpots << " empty spots." << endl;
    	}
	}
};
int main(){
 
	fast_io;
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt",  "r",  stdin);
		freopen("output.txt", "w", stdout);
	#endif
 
	Solution sol;
	sol.executeSolution();
 
	return 0;
}