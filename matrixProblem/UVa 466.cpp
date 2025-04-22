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

class Mirror{
private:
	int dimension;
	int patternNo;
	vector<string> pattern;
	vector<string> mPattern; //modified Pattern

public:
	Mirror(int n, int pNo): dimension(n), patternNo(pNo){
		pattern.resize(n);
		mPattern.resize(n);

		for(int i = 0; i < n; i++){
			string line;
			getline(cin, line);
			stringstream ss(line);

			string leftPattern, rightPattern;
			ss >> leftPattern >> rightPattern;

			pattern[i] = leftPattern;
			mPattern[i] = rightPattern;
		}
	}

	vector<string> getPatternMatrix(){
		return pattern;
	}
	vector<string> getMPatternMatrix(){
		return mPattern;
	}

	vector<string> rotate90Degree(vector<string> matrix){
		reverse(matrix.begin(), matrix.end());

		vector<string> ansMatrix = matrix;

		for(int i = 0; i < matrix.size(); i++){
			for(int j = 0; j < matrix[0].size(); j++){
				ansMatrix[i][j] = matrix[j][i];
			}
		}
		return ansMatrix;
	}

	bool isPreserved(vector<string> &matrix){
		return matrix == mPattern;
	}

	bool isVerticallyReflected(vector<string> matrix){
		reverse(matrix.begin(), matrix.end());
		return matrix == mPattern;
	}

	void executeSolution(){
		cout<<"Pattern "<<patternNo<<" ";
		vector<string> matrix = pattern;
		if(matrix == mPattern){
			cout<<"was preserved."<<endl;
			return;
		}
		else{
			vector<string> rotatedMatrix = rotate90Degree(matrix); //90 degree rotation of pattern
			if(rotatedMatrix == mPattern){
				cout<<"was rotated 90 degrees."<<endl;
				return;
			}

			rotatedMatrix = rotate90Degree(rotatedMatrix); //180 degree rotation;
			if(rotatedMatrix == mPattern){
				cout<<"was rotated 180 degrees."<<endl;
				return;
			}
			rotatedMatrix = rotate90Degree(rotatedMatrix); //270 degree rotation;
			if(rotatedMatrix == mPattern){
				cout<<"was rotated 270 degrees."<<endl;
				return;
			}

		}
		if(isVerticallyReflected(matrix)){
			cout<<"was reflected vertically."<<endl;
			return;
		}
		else{
			reverse(matrix.begin(), matrix.end());
			vector<string> rotatedMatrix = rotate90Degree(matrix); //90 degree rotation of pattern
			if(rotatedMatrix == mPattern){
				cout<<"was reflected vertically and rotated 90 degrees."<<endl;
				return;
			}

			rotatedMatrix = rotate90Degree(rotatedMatrix); //180 degree rotation;
			if(rotatedMatrix == mPattern){
				cout<<"was reflected vertically and rotated 180 degrees."<<endl;
				return;
			}
			rotatedMatrix = rotate90Degree(rotatedMatrix); //270 degree rotation;
			if(rotatedMatrix == mPattern){
				cout<<"was reflected vertically and rotated 270 degrees."<<endl;
				return;
			}
		}

		cout<<"was improperly transformed.";
		cout<<endl;
	}

	void printPatternMatrix(vector<string> matrix){
		for(auto &mat: matrix)
			cout<<mat<<endl;
	}
};

int main(){
 
	fast_io;
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt",  "r",  stdin);
		freopen("output.txt", "w", stdout);
	#endif
 
	string dimension;
	int i = 1;
	while(getline(cin, dimension)){
		stringstream ss(dimension);
		int n;
		ss >> n;		
		Mirror m(n, i);
		m.executeSolution();
		i++;
	}

 
	return 0;
}