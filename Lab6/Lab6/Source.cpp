#include <IOStream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

const int numPrices = 10;

int main()
{
	ifstream fin;
	string fileName, stockName, date;
	float prices[10];
	int times[10];
	float average, median, change, high, low, sum = 0;

	cout << fixed << setprecision(2);
	cout << "Enter stock data file name: ";
	cin >> fileName;

	fin.open(fileName);

	if (fin.fail())
	{
		cout << "Failed to open file" << endl;
		system("PAUSE");
		return 0;
	}

	fin >> stockName >> date;	

	for (int i = 0; i < numPrices; i++)
	{
		fin >> prices[i];
		
		times[i] = 8 + i;
		if (times[i] > 12)
		{
			times[i] -= 12;
		}
	}

	fin.close();

	cout << setw(5) << "TIME " << "    " << setw(8) << "PRICES" << endl;
	cout << setw(5) << "-----" << "    " << setw(8) << "--------" << endl;
	
	for (int i = 0; i < numPrices; i++)
	{
		cout << setw(2) << right << times[i] << ":00    " << setw(3) << "$  " << prices[i] << endl;
		sum += prices[i];
	}

	sort(prices, prices + numPrices);

	high = prices[9];
	low = prices[0];
	average = sum / numPrices;
	median = (prices[4] + prices[5]) / 2.0;
	change = prices[9] - prices[0];

	cout << endl;
	cout << "CHANGE:  $" << setw(7) << right << change << endl;
	cout << "HIGH:    $" << setw(7) << right << high << endl;
	cout << "LOW:     $" << setw(7) << right << low << endl;
	cout << "AVERAGE: $" << setw(7) << right << average << endl;
	cout << "MEDIAN:  $" << setw(7) << right << median << endl;
	
	system("PAUSE");
}