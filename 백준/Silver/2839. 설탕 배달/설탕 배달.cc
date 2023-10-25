#include <iostream>
#define KG_3 3	//3Kg 봉지
#define KG_5 5	//5Kg 봉지
using namespace std;
int main() {
	
	int N;	
	cin >> N;

	int result = 0;
	while (N >= 0) {
		if (N % KG_5 == 0) {
			result += N / KG_5;
			cout << result;
			return 0;
		}
		N -= KG_3;
		result++;
	}
	cout << "-1";
	return 0;
}