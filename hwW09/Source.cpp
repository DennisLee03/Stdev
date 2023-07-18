#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
class cData {
private:
	int n;
	double sum, sqsum;
public:
	cData() { n = 0;sum = 0;sqsum = 0; }
	void Add(int data);
	double Avg() { return(sum/n); }
	double Stdev() { return(sqrt(sqsum / n - Avg()*Avg())); }
	int N() { return(n); }
};
void cData::Add(int data) {
	sum += data;
	sqsum += data*data;
	n++;
}
void main() {
	int count;
	int buf[99];
	cData even, odd;
	ifstream file("data.txt");
	if (file.is_open()) {
		count = 0;
		while (!file.eof()) {
			file >> buf[count];
			if (buf[count] % 2 == 0) {
				even.Add(buf[count]);
				count++;
			}
			else {
				odd.Add(buf[count]);
				count++;
			}
		}file.close();
		//cout << "[" << count << "]" << endl;
		/*for (int i = 0;i < count;i++) {
			cout << buf[i] << endl;
			if (buf[i] % 2==0) even.Add(buf[i]);
			else odd.Add(buf[i]);
		}*/
	}
	else cout << "You falied!!!" << endl;
	cout << "Even: N=" << even.N() << ", " << "average=" << even.Avg() << ", " << "stdev=" << even.Stdev() << endl;
	cout << "Odd: N=" << odd.N() << ", " << "average=" << odd.Avg() << ", " << "stdev=" << odd.Stdev() << endl;
}