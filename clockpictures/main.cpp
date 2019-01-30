#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

int clockSize;

std::vector<int> clockbase;
std::vector<int> clockchange;
ll baseSum, changeSum;

bool clocksEqual(int startIndex, ll totalChange) {

	for (int i = 0; i < clockSize; ++i) {
		ll baseVal = clockbase[i];
		ll changeVal = (((ll)clockchange[(i + startIndex) % clockSize] - totalChange) % 360'000);
		if(changeVal < 0)
			changeVal += 360'000;

		if(baseVal != changeVal)
			return false;
	}

	return true;

}

int main() {

	scanf("%d", &clockSize);

	clockbase.resize(clockSize);
	clockchange.resize(clockSize);

	for (int i = 0; i < clockSize; ++i) {
		scanf("%d", &clockbase[i]);
	}
	for (int i = 0; i < clockSize; ++i) {
		scanf("%d", &clockchange[i]);
	}

	std::sort(clockbase.begin(), clockbase.end());
	std::sort(clockchange.begin(), clockchange.end());

	ll change = clockbase[0];
	for(auto& i : clockbase) {
		i -= change;
		baseSum += i;
	}

	change = clockchange[0];
	for(auto& i : clockchange) {
		i -= change;
		changeSum += i;
	}

	if(baseSum == changeSum && clocksEqual(0, 0)) {
		printf("possible\n");
		return 0;
	} else {
		ll totalChange = 0;
		for (int i = 1; i < clockSize; ++i) {

			ll newChange = clockchange[i] - totalChange;
			totalChange += newChange;

			changeSum = changeSum - (clockSize - 1) * newChange + (360'000 - newChange);

			if(baseSum == changeSum && clocksEqual(i, totalChange)) {
				printf("possible\n");
				return 0;
			}

		}

		printf("impossible\n");

	}

}