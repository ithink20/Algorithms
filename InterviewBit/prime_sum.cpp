//Guarenteed to exist: read https://en.wikipedia.org/wiki/Goldbach%27s_conjecture


void Sieve(int n, vector<bool> &isPrime){
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
        isPrime[i] = true;

    for (int p = 2; p * p <= n; p++){
        if (isPrime[p] == true) {
            for (int i = p * 2; i <= n; i += p)
                isPrime[i] = false;
        }
    }
}

vector<int> Solution::primesum(int A) {
    vector <int> ans;
    vector<bool> isPrime(A + 10, false);
    Sieve(A, isPrime);
    for (int i = 0; i < A; ++i) {
        if (isPrime[i] && isPrime[A - i]) {
            ans.push_back(i);
            ans.push_back(A - i);
            return ans;
        }
    }
}
