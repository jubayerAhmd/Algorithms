#include<iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSackZeroOne(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0) {
        return 0;
	}

	if (wt[n - 1] > W) {
        return knapSackZeroOne(W, wt, val, n - 1);
	}

    return max(
			val[n - 1]
				+ knapSackZeroOne(W - wt[n - 1], wt, val, n - 1),
			knapSackZeroOne(W, wt, val, n - 1));
}

int main()
{
    int W = 50;
	int n = 3;
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };

    cout<<"W: 50"<<endl;
    cout<<"N: 3"<<endl;
    cout<<"Profit: { 60, 100, 120 }"<<endl;
    cout<<"Weight: { 10, 20, 30 }"<<endl<<endl;;
	cout<<knapSackZeroOne(W, weight, profit, n);
	return 0;
}
