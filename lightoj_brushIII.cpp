#include<bits/stdc++.h>

using namespace std;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define long long int ll
#define endl '\n'


int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


const int MOD = 1000000007;

int n;
int w, k;
int points[101];
int DP[101][101];

int call(int pos, int mov_rem) {

    if(mov_rem == 0 || pos >= n) return 0;

    int &ret = DP[pos][mov_rem];
    if(ret != -1) return ret;

    int lim = points[pos] + w;
    int t1 = 0;
    int i;

    for(i = pos; i < n && points[i] <= lim; i++) {

        t1++;
    }
    t1 += call(i, mov_rem - 1);

    int t2 = call(pos + 1, mov_rem);

    ret = max(t1, t2);

    return ret;

}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int test;

    cin >> test;

    for(int i = 0; i < test; i++) {

      cin >> n;
      cin >> w >> k;

      for(int j = 0; j < n; j++) {

        int t;
        cin >> t >> points[j];
      }

      sort(points, points+n);

      memset(DP, -1, sizeof(DP));

      cout << "Case " << i+1 << ": " << call(0, k) << endl;

    }






}
