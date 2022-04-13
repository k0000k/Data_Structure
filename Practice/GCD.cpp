int GCD(int a, int b){
    int r = a % b;
    
    if (b % r == 0){
        return r;
    }
    return GCD(b, r);
}
