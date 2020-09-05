#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    priority_queue<pair<int, int>> pq;

	pq.push(make_pair(-50, 1));
	cout << pq.top().first << ", " << pq.top().second << endl;

	pq.push(make_pair(-40, 2));
	cout << pq.top().first << ", " << pq.top().second << endl;

	pq.push(make_pair(-20, 3));
	cout << pq.top().first << ", " << pq.top().second << endl;

	pq.push(make_pair(-30, 4));
	cout << pq.top().first << ", " << pq.top().second << endl;

	pq.push(make_pair(-10, 5));
	cout << pq.top().first << ", " << pq.top().second << endl;

	cout << pq.size() << endl << endl;

	while(!pq.empty())
	{
		cout << pq.top().first << ", " << pq.top().second << endl;
		pq.pop();
	}

    return 0;
}