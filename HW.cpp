#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

using tupIp = tuple<int, int, int, int>;

auto parse(const string& input)
{
	size_t idx = 0;
	size_t shift = 0;
	auto temp = input.substr(idx);
	int ip1 = stoi(temp, &shift);
	idx += shift + 1;
	int ip2 = stoi(input.substr(idx), &shift);
	idx += shift + 1;
	int ip3 = stoi(input.substr(idx), &shift);
	idx += shift + 1;
	int ip4 = stoi(input.substr(idx), &shift);
	return make_tuple(ip1, ip2, ip3, ip4);
}

void checkIp(const tupIp& ip) {
	for (int i = 0; i < tuple_size<tupIp>::value; i++)
		if ((get<0>(ip) < 0) || (get<0>(ip) > 255)) {
			cout << "Incorrect IP" << endl;
		}
}

//void checkIp(const tupIp& ip) {
//	if ((ipX < 0) || (ipX > 255))
//		cout << "Incorrect IP" << endl;
//}
//

void PrintIP(const tupIp& ip)
{
	std::cout << (get<0>(ip)) << "." << get<1>(ip) << "." << get<2>(ip) << "." << get<3>(ip) << endl;
}

void conditionalOutput(const vector<tupIp>& addrs, bool(*func)(const tupIp&))
{
	for_each(addrs.begin(), addrs.end(), [&](const tupIp& ip) {
		if (func(ip)) {
			PrintIP(ip);
		}
	});
}


int main()
{
	vector<tupIp> poolIp;
	string text1, text2, text3;

	while (getline(cin, text1)) {
			if (text1 == "") //for windows
				break;
			tupIp ip = parse(text1);
			checkIp(ip);
			poolIp.emplace_back(std::move(ip));
	}

	sort(poolIp.begin(), poolIp.end(), [](const auto& a, const auto& b) {	return a > b;} );
	
	for_each(poolIp.begin(), poolIp.end(), [](const tupIp& ip) {
		PrintIP(ip);
	});
	
	conditionalOutput(poolIp, [](const tupIp& ip) {
		if (get<0>(ip) == 1) return true;
		else return false;
	});
	
	conditionalOutput(poolIp, [](const tupIp& ip) {
		if (get<0>(ip) == 46 && get<1>(ip) == 70) return true;
		else return false;
	});
	
	conditionalOutput(poolIp, [](const tupIp& ip) {
		if (get<0>(ip) == 46 || get<1>(ip) == 46 || get<2>(ip) == 46 || get<3>(ip) == 46) return true;
		else return false;
	});


    std::cout << "Hello World!\n";

	return 0;
}
