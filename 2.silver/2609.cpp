#include <iostream>

using namespace std;


int	gcd(int k, int l)
{
	return (l ? gcd(l, k%l) : k);
}
int	lcm(int k, int l)
{
	return (k / gcd(k, l) * l);
}
int main ()
{
	int K, L;
	cin >> K >> L;
	cout << gcd(K, L) << endl;
	cout << lcm(K, L) << endl;

}