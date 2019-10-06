#include <iostream>
#include "Facebook.h"
using namespace std;

void main()
{
	Facebook fb;

	int inp = 0;

	while (inp != 12)
	{
		cout <<
			"Please choose one of the following:" << endl <<
			" 1. Add member" << endl <<
			" 2. Add fan page." << endl <<
			" 3. Add status to member or fan page." << endl <<
			" 4. Show all statuses of a member or a fan page." << endl <<
			" 5. Create friendship." << endl <<
			" 6. Add fan to a fan page." << endl <<
			" 7. Show all entities." << endl <<
			" 8. Show all friends of a member or show all fans of a fan page." << endl <<
			" 9. Print last 10 statuses of friends of a member." << endl <<
			"10. Compare number of friends/followers." << endl <<
			"11. Compare two statuses." << endl <<
			"12. Exit." << endl << endl <<
			">> ";
		cin >> inp;
		getchar();

		switch (inp)
		{
		case 1:
			fb.addMember();
			cout << endl;
			break;
		case 2:
			fb.addFanPage();
			cout << endl;
			break;
		case 3:
			fb.addStatus();
			cout << endl;
			break;
		case 4:
			fb.printStatusArr();
			cout << endl;
			break;
		case 5:
			fb.createFriendship();
			cout << endl;
			break;
		case 6:
			fb.addFollower();
			cout << endl;
			break;
		case 7:
			fb.printEntities();
			cout << endl;
			break;
		case 8:
			fb.printConnections();
			cout << endl;
			break;
		case 9:
			fb.printLastTen();
			cout << endl;
			break;
		case 10:
			fb.comparef();
			cout << endl;
			break;
		case 11:
			fb.compareStatuses();
			cout << endl;
			break;
		case 12:
			break;
		}
	}

	cout << "Bye Bye!" << endl;
}