int Fibo(int n){
    if (n==1){
        return 1;
    }
    else if (n==2){
        return 1;
    }
    else if (n==0){
        return 0;
    }
    
    return Fibo(n-1)+Fibo(n-2);
}
