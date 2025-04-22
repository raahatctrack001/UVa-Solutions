#include <bits/stdc++.h>
using namespace std;
 
#define fR(i, a, b) for (int i = (a); i < (b); i++) //for loop in range
#define fRD(i, a, b) for (int i = (a); i > (b); i--) //for loop in range but descending
#define fRJ(i, a, b, j) for (int i = (a), i < (b); i += j) //for loop in range with jump factor
#define fRJD(i, a, b, j) for (int i = (a), i > (b); i -= j) //for loop in range with jump factor but descending
#define fL(i, n) for (int i = 0; i < (n); i++) //for loop from 0 to n
 
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

vector<string> tokenize(string &str, char basedOn){ 
    vector <string> tokens;
    stringstream check1(str);
     
    string intermediate;
    while(getline(check1, intermediate, basedOn))
    {
        tokens.push_back(intermediate);
    }
    return tokens;
}
class BlockWorld{
private:
    vector<vector<int>> stacks;
    vector<int> blocksPosition;
    int blocksCount;
public:
    BlockWorld(int n): blocksCount(n){
        stacks.resize(n);
        blocksPosition.resize(n);

        for(int i = 0; i < n; i++){
            stacks[i].pb(i);
            blocksPosition[i] = i;
        }
    }

    void returnBlockAbove(int block, int stackIndex){
        vector<int> &stack = stacks[stackIndex];
        vector<int> :: iterator it = find(stack.begin(), stack.end(), block);

        if(it == stack.end())
            return;

        for(auto i = it+1; i != stack.end(); i++){
            int blockAbovePivote = *i;
            stacks[blockAbovePivote].pb(blockAbovePivote);
            blocksPosition[blockAbovePivote] = blockAbovePivote;
        }
        stack.erase(it+1, stack.end()); //return only blocks above pivot and not the pivot block
    }

    void moveBlock(int block, int destIndex, bool isPile = false){
        vector<int> &sourceStack = stacks[blocksPosition[block]];
        vector<int> :: iterator it = find(sourceStack.begin(), sourceStack.end(), block);

        vector<int> blocksToMove;
        if(isPile){
            blocksToMove = vector<int>(it, sourceStack.end());
            sourceStack.erase(it, sourceStack.end());
        } else {
            blocksToMove = {*it};
            sourceStack.erase(it);
        }

        vector<int> &destStack = stacks[destIndex];
        for(auto &b: blocksToMove){
            destStack.pb(b);
            blocksPosition[b] = destIndex;
        }
    }

    void moveOnto(int a, int b){
        if(a == b or blocksPosition[a] == blocksPosition[b])
            return;
        returnBlockAbove(a, blocksPosition[a]);
        returnBlockAbove(b, blocksPosition[b]);
        moveBlock(a, blocksPosition[b], false);
    }

    void moveOver(int a, int b){
        if(a == b or blocksPosition[a] == blocksPosition[b])
            return;
        returnBlockAbove(a, blocksPosition[a]);
        moveBlock(a, blocksPosition[b], false);
    }

    void pileOnto(int a, int b){
        if(a == b or blocksPosition[a] == blocksPosition[b])
            return;
        returnBlockAbove(b, blocksPosition[b]);
        moveBlock(a, blocksPosition[b], true);
    }

    void pileOver(int a, int b){
        if(a == b or blocksPosition[a] == blocksPosition[b])
            return;
        moveBlock(a, blocksPosition[b], true);
    }

    void processCommand(string &commandLine){
        stringstream ss(commandLine);
        string command, position;
        int a, b;
        ss >> command >> a >> position >> b;
        if(command == "move"){
            if(position == "onto"){
                moveOnto(a, b);
            }
            else{
                moveOver(a, b);
            }
        }
        else{
            if(position == "onto"){
                pileOnto(a, b);
            }
            else{
                pileOver(a, b);
            }
        }
    }

    void printStack(){
        for(int i = 0; i < stacks.size(); i++){
            cout<<i<<":";
            for(int j = 0; j < stacks[i].size(); j++){
                cout<<" "<<stacks[i][j];
            }
            cout<<endl;
        }
    }
};

int main() {
    fast_io;
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r",  stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;

    cout<<t<<endl;
    int numBlocks;
    cin >> numBlocks;
    cin.ignore(); // Ignore newline after the number


    BlockWorld bw(numBlocks);
    string commandLine;

    while (getline(cin, commandLine)) {
        if (commandLine == "quit") break;
        bw.processCommand(commandLine);
    }

    bw.printStack();

    return 0;
}
