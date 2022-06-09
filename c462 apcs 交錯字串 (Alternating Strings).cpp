#include <bits/stdc++.h>
using namespace std;



int main() {
	// vars and inputs
	int what_to_find;
	cin >> what_to_find;	
	string the_string;
	cin.ignore();
	getline(cin, the_string);
	if (the_string.size() == 0) {
		cin.ignore();
		getline(cin, the_string);
	}
	if (what_to_find == 1 && the_string.size() == 1) {
		cout << 1;
		return 0;
	}
	vector<int> the_continious_letters_amount{0};
	int the_index = 0;
	bool now_letter_is_capital = isupper(the_string[0]);
	// Calculation
	for_each(the_string.begin(), the_string.end(), [&the_index, &now_letter_is_capital, &the_continious_letters_amount](char one_letter){
		if (islower(one_letter)) {
			if (now_letter_is_capital) {
				the_continious_letters_amount.push_back(1);
				now_letter_is_capital = false;
				the_index++;
			} else {
				the_continious_letters_amount[the_index]++;
			}
		} else {
			if (now_letter_is_capital) {
				the_continious_letters_amount[the_index]++;
			} else {
				the_continious_letters_amount.push_back(1);
				now_letter_is_capital = true;
				the_index++;
			}
		}
	});
	int now_max = 0, now_amount = 0;
	for (int i = 0;i < the_continious_letters_amount.size();i++) {
		if (the_continious_letters_amount[i] == what_to_find) {
			now_amount++;
		} else {
			if (the_continious_letters_amount[i] > what_to_find) now_amount++;
			if (now_amount > now_max) now_max = now_amount;
			if (the_continious_letters_amount[i] > what_to_find) now_amount = 1;
			else now_amount = 0;
		}
	}
	// outputs
	cout << now_max * what_to_find;
	cin >> now_max;
	return 0;
}