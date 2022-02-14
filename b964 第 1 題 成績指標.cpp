#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int N, i, score;
    cin >> N;
    vector<int> scores;
    for (i = 0;i < N;i++) {
        cin >> score;
        scores.push_back(score);
    }
    sort(scores.begin(), scores.end());
    for_each(scores.begin(), scores.end(), [](int s){cout << s << ' ';});
    vector<int>::iterator m = find_if(scores.begin(), scores.end(), [](int s){return s >= 60;});
    if (m == scores.begin() && *m >= 60) cout << '\n' << "best case" << '\n' << *m << endl;
    else if (m == scores.end()) cout << '\n' << *(m - 1) << '\n'  << "worst case"<< endl;
    else cout << '\n' << *(m - 1) << '\n' << *m;
    return 0;
}
