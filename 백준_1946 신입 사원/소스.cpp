#include <iostream>
#include <algorithm>
using namespace std;

typedef struct ranks
{
	int document;
	int interview;
}ranks;

int compar(const void *rank1, const void *rank2)
{
	ranks* temp1 = (ranks*)rank1;
	ranks* temp2 = (ranks*)rank2;
	if (temp1->document > temp2->document) return 1;
	else if (temp1->document < temp2->document) return -1;
	else return 0;
}

ranks person[100000];
int main()
{
	int i, j, test_case, number, maximun, cnt;
	cin >> test_case;
	for (i = 0; i < test_case; i++)
	{
		cin >> number;
		cnt = 1;
		for (j = 0; j < number; j++)
		{
			cin >> person[j].document >> person[j].interview;
		}
		qsort(person, number, sizeof(ranks), compar);
		maximun = person[0].interview;
		for (j = 1; j < number; j++)
		{
			if (maximun > person[j].interview)
			{
				maximun = person[j].interview;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}