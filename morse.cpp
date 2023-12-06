#include <fstream>
using namespace std;
void morse(int n, ostream & g);
int nrBitiDeUnu(int n);
int main()
{
	ifstream f("morse.in");
	ofstream g("morse.out");
	int a, b;
	f >> a >> b;
	f.close();
	int i, nrmax = 0;
	for (i = a; i <= b; i++)
	{
		int nr = nrBitiDeUnu(i);
		if (nr > nrmax) nrmax = nr;
	}
	for (i = a; i <= b; i++)
		if (nrBitiDeUnu(i) == nrmax)
			morse(i, g);
	g.close();
	return 0;
}
void morse(int n, ostream & g)
{
	int i;
	for (i = 31; i >= 0; i--)
		if (n & (1 << i)) break;
	g << '-';
	for (i--; i >= 0; i--)
		if (n & (1 << i))
			g << '-';
		else
			g << '.';
	g << ' ';
}
int nrBitiDeUnu(int n)
{
	int nr = 0;
	for (int i = 0; i < 32; i++)
		if (n & (1 << i)) nr++;
	return nr;
}
