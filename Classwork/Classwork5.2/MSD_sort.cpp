#include <iostream>
#include <random>
#define L 123 //последняя буква латинского алфавита имеет код 122 в ASCII

using namespace std;

int char_to_int(string s, int i);
void MSD_sort(string s[], int start, int end, int j);
string random_string(size_t length);
void print(string s[], int n);


int main()
{
	cout << "Input the number of strings:\n";
	int n;
	cin >> n;

	std::mt19937 mt(time(nullptr));

	string* s = new string[n];
	for (int i = 0; i < n; i++) 
		s[i] = random_string((mt() % 100) + 100);


	cout << "Unsorted strings:\n";
	print(s, n);
	cout << endl;

	MSD_sort(s, 0, n - 1, 0);

	cout << "Sorted strings:\n";
	print(s, n);
	cout << endl;

	delete[] s;
}


int char_to_int(string s, int i) {
	if (i < s.length())
		return s[i];
	else
		return -1;
}

void MSD_sort(string s[], int start, int end, int j)
{
	if (end <= start) {
		return;
	}

	int count[L] = { 0 };

	string* temp = new string[s->length()];

	for (int i = start; i <= end; i++) {
		count[char_to_int(s[i], j)]++;
	}

	for (int i = 1; i < L; i++)
		count[i] += count[i - 1];

	for (int i = start; i <= end; i++) {
		temp[count[char_to_int(s[i], j)] - 1] = s[i];
		--count[char_to_int(s[i], j)];
	}

	for (int i = start; i <= end; i++)
		s[i] = temp[i - start];

	for (int i = 0; i < L; i++)
		MSD_sort(s, start + count[i], start + count[i + 1] - 1, j + 1);

	delete[] temp;
}

string random_string(size_t length)
{
	const string CHARACTERS = "abcdefghijklmnopqrstuvwxyz";

	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

	string random_string;

	for (size_t i = 0; i < length; ++i)
	{
		random_string += CHARACTERS[distribution(generator)];
	}

	return random_string;
}

void print(string s[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << i << ". " << s[i] << endl;
	}
}

