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
#define printMatrix(v) for(auto &row: v){ for (auto &el: row){cout << el << " ";} cout << endl;}
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

class Matrix{
	int dimension;
	vector<vector<int>> matrix;
public:
	Matrix(int n): dimension(n){
		matrix.resize(n);
		fL(i, n){
			matrix[i].resize(n);
			fL(j, n){
				cin >> matrix[i][j];
			}
		}
	}

	vector<vector<int>> getMatrix(){
		return matrix;
	}

	int getDimension(){
		return dimension;
	}
};

class MatrixOperation{
	Matrix matrix;
public:
	MatrixOperation( Matrix mat ) : matrix( mat ){}

	vector<int> rowSum(){
		vector<vector<int>> mat = matrix.getMatrix();
		int n = mat.size();
		vector<int> rowParity(n, 0);
		int oddCount = 0;

		fL(i, n){
			int count = 0;
			fL(j, n){
				count += mat[i][j];
			}
			if(count&1){
				oddCount++;
				if(oddCount == 2){
					return {-1};
				}
			}
			rowParity[i] = count;
		}
		return rowParity;
	}

	vector<int> colSum(){
		vector<vector<int>> mat = matrix.getMatrix();
		int n = mat.size();
		vector<int> colParity(n, 0);
		int oddCount = 0;

		fL(i, n){
			int count = 0;
			fL(j, n){
				count += mat[j][i];
			}
			if(count&1){
				oddCount++;
				if(oddCount == 2){
					return {-1};
				}
			}
			colParity[i] = count;
		}
		return colParity;
	}
};
 
class Solution{
	MatrixOperation mo;
public:
	Solution( MatrixOperation m) : mo(m){}

	void executeSolution(){
		vector<int> rowSum, colSum;
		rowSum = mo.rowSum();
		if(rowSum == vector<int>{-1}){
			cout<<"Corrupt"<<endl;
			return;
		}
		colSum = mo.colSum();
		if(colSum == vector<int>{-1}){
			cout<<"Corrupt"<<endl;
			return;
		}
		int r = -1;
		int c = -1;
		int n = rowSum.size();
		fL(i, n){
			if(rowSum[i]&1){
				r = i;
				break;
			}
		}

		fL(j, n){
			if(colSum[j]&1){
				c = j;
			}
		}
		if(r != -1 and c != -1){
			cout<<"Change bit ("<<r+1<<","<<c+1<<")"<<endl;
			return;
		}
		cout<<"OK"<<endl;
	} 
};

int main(){
 
	fast_io;
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt",  "r",  stdin);
		freopen("output.txt", "w", stdout);
	#endif
 	
	int dimension;
	cin >> dimension;
	cin.ignore(); //must thing
	int i = 1;
	while(dimension){
		Matrix m(dimension);
		MatrixOperation mo(m);
		Solution s(mo);
		s.executeSolution();

		cin >> dimension;
	}
	

 
	return 0;
}