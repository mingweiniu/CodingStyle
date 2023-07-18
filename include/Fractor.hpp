#include <vector>

void Fractor(int n, std::vector<int> &p, std::vector<int> &k)
{
	p.clear();
	k.clear();
	
	for(int i=2; i<n; ++i)
	{
		if( n%i ==0)
		{
			n /= i;
			p.push_back(i);
			k.push_back(1);
			while( n%i ==0)
			{
				n /= i;
				++k.back();
			}
		}
	}
	if(n > 2)
	{
		p.push_back(i);
		k.push_back(1);
	}
}

void TestFractor()
{
	using std::vector;
	using std::cout;
	
	vector<int> p;
	vector<int> k;

	int x = 213222400;
	Fractor(x, p, k);
	// should be 2 ^ 10 * 5 ^ 2 *8329
	cout << x << " = ";
	for (int i = 0; i < p.size(); ++i) {
		cout << p[i] << "^" << k[i] << " ";
	}
	cout << '\n';
}
