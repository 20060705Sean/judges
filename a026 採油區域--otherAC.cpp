#include <cstdio> 
#include <cstring>
#include <string>
#include <algorithm>
#define LL long long
using std::max;
using std::string;

const int MAXN = 1510;
LL val[MAXN][MAXN];
LL s[MAXN][MAXN];		//  以(i,j)为右下角的 k*k 正方形价值前缀和
LL sum[MAXN][MAXN];	// 从 (0,0) 到 (i,j) 的矩形的价值前缀和 
LL ul[MAXN][MAXN],		// up-left
    ur[MAXN][MAXN],		// up-right
    dl[MAXN][MAXN],		// down-left
    dr[MAXN][MAXN],		// down-right
    r[MAXN],			// row max
    c[MAXN];			// col max
int m, n, k;

int main()
{
    scanf("%d%d%d", &m, &n, &k);	// line, col, unit
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &val[i][j]);
            sum[i][j] = sum[i-1][j] - sum[i-1][j-1] + sum[i][j-1] + val[i][j];// 处理前缀和 
        }
    }
    
    for (int i = k; i <= m; i++) {
        for (int j = k; j <= n; j++) {
            s[i][j] = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
        }
    }
    
    // up-left
    for (int i = k; i <= m; i++) {
        for (int j = k; j <= n; j++) {
            ul[i][j] = max(max(ul[i-1][j], ul[i][j-1]), s[i][j]);
        }
    }
    
    // up-right
    for (int i = 1; i <= m; i++) {
        for (int j = (n - k + 1); j >= 1; j--) {
            ur[i][j] = max(max(ur[i-1][j], ur[i][j+1]), s[i][j + k - 1]);
        }
    }
    
    // down-left
    for (int i = (m - k + 1); i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            dl[i][j] = max(max(dl[i+1][j], dl[i][j-1]), s[i + k - 1][j]);
        }
    }
    
    // down-right
    for (int i = (m - k + 1); i >= 1; i--) {
        for (int j = (n - k + 1); j >= 1; j--) {
            dr[i][j] = max(max(dr[i+1][j], dr[i][j+1]), s[i + k - 1][j + k - 1]);
        }
    }
    
    // line & col
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            r[i] = max(r[i], s[i][j]);
            c[j] = max(c[j], s[i][j]);
        }
    }
    
    // enumerate boundary
    LL ans = 0LL;
    for (int i = k; i <= (m - k); i++) {
        for (int j = k; j <= (n - k); j++) {
            ans = max(ans, ul[i][j] + dl[i + 1][j] + ur[m][j + 1]);
            ans = max(ans, ur[i][j] + dr[i + 1][j] + ul[m][j - 1]);
            ans = max(ans, ul[i][j] + ur[i][j + 1] + dl[i + 1][n]);
            ans = max(ans, dl[i][j] + dr[i][j + 1] + ul[i - 1][m]);
        }
    }
    
    for (int i = 2 * k; i <= m - k; i++) {
        ans = max(ans, ul[i - k][n] + r[i] + dl[i + 1][n]);
    }
    for (int i = 2 * k; i <= n - k; i++) {
        ans = max(ans, ul[m][i - k] + c[i] + ur[m][i + 1]);
    }
    
    printf("%lld", ans);
    
    return 0;
}