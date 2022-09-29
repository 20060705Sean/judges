#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#define WOW ios::sync_with_stdio(false);cin.tie(0);
#define EB emplace_back
#define F first
#define S second

class bst{
    public:
        int  val;
        bst* left;
        bst* right;
        bst(int val)
            :val(val)
            ,right(NULL)
            ,left(NULL)
        {
        }
};

void Insert(bst*& root,int num){
    bst* node = new bst(num);
    if(!root){
        root = node;
        return;
    }
    bst* pre = NULL;
    bst* tmp = root;
    while(tmp){
        if(tmp-> val < num){
            pre = tmp;
            tmp = tmp->right;
        }else if(tmp->val > num){
            pre = tmp;
            tmp = tmp->left;
        }
    }
    if(pre->val < num){
        pre->right = node;
    }else if(pre->val > num){
        pre->left = node;
    }
}

void inorder(bst* root){
    bst* tmp = root;
    stack<bst*> st;
    while(tmp != NULL || !st.empty()){
        if(tmp != NULL){
            cout << tmp->val << ' ';
            st.push(tmp);
            tmp = tmp-> left;
        }else{
            tmp = st.top();
            st.pop();
            tmp = tmp-> right;
        }
    }
    cout << "\n";
}
int main(){
    WOW
    int n;
    while(cin >> n){
        bst* root = NULL;
        while(n--){
            int x;
            cin >> x;
            Insert(root,x);
        }
        inorder(root);
    }
    return 0;
}
