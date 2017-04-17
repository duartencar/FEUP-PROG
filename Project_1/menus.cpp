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

void edit_driver_menu()
{
	cout << "1 - Nome\n2 - Identificador\n3 - Horas que pode trabalhar por dia\n4 - Horas que pode trabalhar por semana\n5 - Horas de descanso\n";

  cout << "O que pretende alterar? <Resp (espaco) nova_informacao\n";
}

void edit_line_menu()
{
	cout << "1 - Identificador\n";
	cout << "2 - Frequencia de partida\n";
	cout << "3 - Paragens\n";
	cout << "4 - Tempos entre paragens\n";

	cout << "O que pretende alterar? <Resp ('-') nova_informacao, separada por '-' caso seja necessario\n";
}
