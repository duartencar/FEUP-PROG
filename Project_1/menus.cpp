#include "menus.h"

using namespace std;

void main_menu()
{
	cout << internal << setw(30) << "Semprarrolar - Transportadora" << endl;

	cout << "1 - Show all lines\n";

	cout << "2 - Show all drivers\n";

	cout << "3 - Manage drivers\n";

	cout << "4 - Manage lines\n";

	cout << "5 - Search for driver\n";

	cout << "6 - Search for stop\n";

	cout << "7 - Plan trip\n";

	cout << "8 - Show necessary drivers for a line workload\n";

	cout << "9 - Leave\n";
}

void manage_drivers_menu()
{
	system("clear");

	cout << "1 - Edit an existing driver\n";

	cout << "2 - Create new driver\n";

	cout << "3 - Leave\n";
}

void manage_lines_menu()
{
	system("clear");

	cout << "1 - Edit an existing line\n";

	cout << "2 - Create new line\n";

	cout << "3 - Leave\n";
}
