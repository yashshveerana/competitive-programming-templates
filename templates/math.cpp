int mod=1e9+7;
int fact[100002];

int modmul(int a,int b){
    return((long long)(a%mod)*(b%mod))%mod;
}

int binExpo(int a,int b){
    if(!b)return 1;
    int res=binExpo(a,b/2);
    if(b&1){
        return modmul(a,modmul(res,res));
    }else{
        return modmul(res,res);
    }
}

int modmulinv(int a){
    return binExpo(a,mod-2);
}

void getfact() {
    fact[0]=1;
    for(int i=1;i<=100001;i++){
        fact[i]=modmul(fact[i-1],i);
    }
}

// Precompute nCr using Pascal's triangle
const int MAX = 60; // since r + c ≤ 15 in LeetCode constraints, 60 is safe
long long C[MAX+1][MAX+1] = {0};
for (int i = 0; i <= MAX; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}


