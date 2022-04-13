void Hanoi(int n, char from, char by, char to){
    if (n==1){
        cout << from << "=>" << to << endl;
    }
    else{
        Hanoi(n-1, from, to, by);
        cout << from << "=>" << to << endl;
        Hanoi(n-1, by, from, to);
    }
}
