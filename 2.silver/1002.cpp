#include <iostream>
#include <math.h>
using namespace	std;

int main()
{
	int		t;
	float		x1,x2,y1,y2,r1,r2;
	float		dis;

	cin >> t;
	while (t--)
	{
		cin >> x1;
		cin >> y1;
		cin >> r1;
		cin >> x2;
		cin >> y2;
		cin >> r2;
		dis = pow((x1 - x2),2) + pow((y1 - y2),2);
		if (dis == 0 && r1 == r2) // 원이 일치
			cout << "-1" << endl;
		else if (dis > pow(r1 + r2, 2)) // 외부에서 만나지 않음
			cout << "0" << endl;
		else if (dis == pow(r1 + r2, 2)) // 외접
			cout << "1" << endl;
		else if (dis > pow(abs(r1 - r2),2) && dis < pow(r1 + r2, 2)) // 두점에서 만남
			cout << "2" << endl;
		else if (dis == pow(abs(r1 - r2), 2)) // 내접
			cout << "1" << endl;
		else if (dis < pow(abs(r1 - r2),2)) // 내부에서 만나지 않음
			cout << "0" << endl;
		else
			cout << "2" << endl;
	}
}