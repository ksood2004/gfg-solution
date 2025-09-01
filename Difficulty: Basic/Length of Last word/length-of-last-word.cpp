// User function Template for C++

int findLength(string s) {
    int n=s.size();
    int i=n-1;
    int si=0;
    while(i>=0 && s[i]==' '){
        i--;
    }
    while(i>=0 && s[i]!=' '){
        si++;
        i--;
    }
    return si;
}