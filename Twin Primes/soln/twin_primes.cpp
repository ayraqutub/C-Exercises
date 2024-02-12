// Remember, style matters!
// While you may rely upon additional functions 
// ensure isPrime and twinPrime follow the specifications.
// -----------------------
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // 1 and 0 are not prime numbers
    if (n <= 3) return true; // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false; // not prime if divisible by 2 or 3
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false; 
    } // loops through numbers from 5 to sqrt(n) and checks if divisible
    return true; // if none of the above conditions, number is prime
}

void twinPrimes(int k) {
    int count=0;
    for (int i = 3; count < k; i++) { // start at first twin prime, continue until count reaches k
        if (isPrime(i) && isPrime(i+2)) { // call isPrime function to check
            cout << i << ' ' << i+2 << endl; // output
            count++;
        }
    }
}

int main()
{
    char pt;
    int nk;

    cin >> pt;
    cin >> nk;

    if (pt == 'p') // isPrime query, output “prime” if n is prime and “not prime” otherwise
    {
        if ((isPrime(nk))) // call isPrime function
        {
            cout << "prime" << endl;
        }
        else
        {
            cout << "not prime" << endl;
        }
    }
    else if (pt == 't') // output the first k twin prime pairs, one per line
    {
        twinPrimes(nk); // call twinPrimes function
 }
}
