#include "Facebook.h"

Facebook::Facebook() 
{

}

const vector<Entity*>& Facebook::getEntitiesArr() const
{
	return Entities;
}

void Facebook::addMember()
{
	string name;
	Member *newMem;
	int day, month, year;
	Date *bDay;

	cout << "Please enter full name: ";
	getline(cin, name);

	if (searchEntity<Member>(name))
	{
		setTextColor(RED);
		cout << "Member is already exists." << endl;
		setTextColor(LIGHTGREY);
	}
	else
	{
		cout << "Please enter birth date, " << endl;

		cout << "Day: ";
		cin >> day;
		getchar();
		cout << "Month: ";
		cin >> month;
		getchar();
		cout << "Year: ";
		cin >> year;
		getchar();

		if (day > 31 || day < 1 || month > 12 || month < 1 || year > 2018 || year < 1898)
		{
			setTextColor(RED);
			cout << "Date input is invalid" << endl;
			setTextColor(LIGHTGREY);
		}
		else
		{
			bDay = new Date(day, month, year);
			newMem = new Member(name, bDay);
			Entities.push_back(newMem);
			
			setTextColor(GREEN);
			cout << "Member added successfully." << endl;
			setTextColor(LIGHTGREY);
		}
	}
}

void Facebook::addStatus()
{
	int inpKind, inpStatusKind;
	string text, name;
	bool isImg, isVid, stopLoop;
	Member* foundMem;
	FanPage* foundFanPage;

	isImg = false, isVid = false, stopLoop = false,	foundFanPage = nullptr, foundMem = nullptr;

	cout << "For a member status press 1, For a fanpage status press 2." << endl << endl <<
		    ">> ";
	cin >> inpKind;
	getchar();

	switch (inpKind)
	{
	case 1:
		cout << "Enter member's name: ";
		getline(cin, name);
		foundMem = searchEntity<Member>(name);

		if (foundMem != nullptr)
		{
			cout << "For	text press 1	image press 2	video press 3" << endl << endl << 
				    ">> ";
			cin >> inpStatusKind;
		}
		else
		{
			setTextColor(RED);
			cout << "Member not found" << endl;
			setTextColor(LIGHTGREY);
		}
		break;

	case 2:
		cout << "Enter fan page name: ";
		getline(cin, name);
		foundFanPage = searchEntity<FanPage>(name);

		if (foundFanPage != nullptr)
		{
			cout << "For	text press 1	image press 2	video press 3" << endl << endl <<
				    ">> ";
			cin >> inpStatusKind;
		}
		else
		{
			setTextColor(RED);
			cout << "Fan page not found" << endl;
			setTextColor(LIGHTGREY);
		}
		break;
	}

	getchar();

	if (foundMem || foundFanPage)
	{
		while (!stopLoop)
		{
			switch (inpStatusKind)
			{
			case 1:
				cout << "Enter text: ";
				getline(cin, text);
				break;

			case 2:
				isImg = true;
				cout << "Uploading image..." << endl;
				break;

			case 3:
				isVid = true;
				cout << "uploading video..." << endl;
				break;

			default:
				setTextColor(RED);
				cout << "Input is invalid." << endl;
				setTextColor(LIGHTGREY);
				break;
			}

			if (text.empty() || !isImg || !isVid)
			{
				if (!(!text.empty() && isImg || !text.empty() && isVid))
				{
					cout << endl << "For	";
				}
			}

			if (text.empty())
			{
				cout << "text press 1	";
			}

			if (isImg == false && isVid == false)
			{
				cout << "image press 2	";
			}

			if (isVid == false && isImg == false)
			{
				cout << "video press 3	";
			}

			if (text.empty() || !isImg || !isVid)
			{
				if (!text.empty() && isImg || !text.empty() && isVid)
				{
					stopLoop = true;
				}
				else
				{
					cout << "| press 4 to continue" << endl << endl << ">> ";
					cin >> inpStatusKind;
					getchar();
				}
			}
			else
			{
				stopLoop = true;
			}

			if (inpStatusKind == 4)
			{
				stopLoop = true;
			}
		}

		if (foundFanPage != nullptr)
		{
			foundFanPage->addStatus(text, isImg, isVid);
		}
		else if (foundMem != nullptr)
		{
			foundMem->addStatus(text, isImg, isVid);
		}

		setTextColor(GREEN);
		cout << "Status uploaded successfully." << endl;
		setTextColor(LIGHTGREY);
	}
}

void Facebook::addFanPage()
{
	string name;
	FanPage *fp;

	cout << "Please enter fan page name: ";
	getline(cin, name);

	if (searchEntity<FanPage>(name))
	{
		setTextColor(RED);
		cout << "Fan page is already exist." << endl;
		setTextColor(LIGHTGREY);
	}
	else
	{
		fp = new FanPage(name);
		Entities.push_back(fp);

		setTextColor(GREEN);
		cout << "Fan page added successfully." << endl;
		setTextColor(LIGHTGREY);
	}
}

void Facebook::printStatusArr() const
{
	int inpKind;
	string name;
	Member* foundMem;
	FanPage* foundFanPage;

	cout << "For a member status press 1, For a fanpage status press 2." << endl << endl << 
		    ">> ";
	cin >> inpKind;
	getchar();

	switch (inpKind)
	{
	case 1:
		cout << "Enter member's name: ";
		getline(cin, name);
		foundMem = searchEntity<Member>(name);

		if (foundMem)
		{
			foundMem->printStatusArr();
		}
		else
		{
			setTextColor(RED);
			cout << "Member not found." << endl;
			setTextColor(LIGHTGREY);
		}
		break;

	case 2:
		cout << "Enter fan page name: ";
		getline(cin, name);
		foundFanPage = searchEntity<FanPage>(name);

		if (foundFanPage)
		{
			foundFanPage->printStatusArr();
		}
		else
		{
			setTextColor(RED);
			cout << "Fan page not found." << endl;
			setTextColor(LIGHTGREY);
		}
		break;
	}
}

void Facebook::createFriendship()
{
	string name1, name2;
	Member *member1, *member2;

	cout << "Please enter first member name: ";
	getline(cin, name1);
	member1 = searchEntity<Member>(name1);

	if (!member1)
	{
		setTextColor(RED);
		cout << "Member not found." << endl;
		setTextColor(LIGHTGREY);
	}
	else
	{
		cout << "Please enter second name: ";
		getline(cin, name2);
		member2 = searchEntity<Member>(name2);

		if (member1 == member2)
		{
			setTextColor(RED);
			cout << "A member can't be a friend with himself." << endl;
			setTextColor(LIGHTGREY);
		}
		else if (member1->isEntityExist(member2))
		{
			cout << member1->getName() << " has already created a friendship with " << member2->getName() << "." << endl;
		}
		else
		{
			if (!member2)
			{
				setTextColor(RED);
				cout << "Member not found." << endl;
				setTextColor(LIGHTGREY);
			}
			else
			{
				*member1+=*member2;
				setTextColor(GREEN);
				cout << "Friendship created successfully." << endl;
				setTextColor(LIGHTGREY);
			}
		}
	}
}

void Facebook::compareStatuses() const
{
	int inp, inp1, inp2;
	Member *member1, *member2;
	FanPage *fanpage1, *fanpage2;
	string name1, name2;
	vector<Status*> statusArr1, statusArr2;

	member1 = member2 = nullptr;
	fanpage1 = fanpage2 = nullptr;

	cout << "Press 1 to compare between members statuses" << endl <<
		"Press 2 to compare between fan pages statuses" << endl <<
		"Press 3 to compare between a member and a fan page statuses." << endl << endl <<
		">> ";

	cin >> inp;
	getchar();

	switch (inp)
	{
	case 1:
		cout << "Enter the first name: ";
		getline(cin, name1);
		member1 = searchEntity<Member>(name1);

		if (member1 != nullptr)
		{
			member1->printStatusArr();
			cout << endl << "Enter status number: ";
			cin >> inp1;
			getchar();
			statusArr1 = member1->getStatusArr();

			cout << "Enter the second name: ";
			getline(cin, name2);
			member2 = searchEntity<Member>(name2);

			if (member2 != nullptr)
			{
				member2->printStatusArr();
				cout << endl << "Enter status number: ";
				cin >> inp2;
				getchar();
				statusArr2 = member2->getStatusArr();

				if (*(statusArr1[inp1 - 1]) == *(statusArr2[inp2 - 1]))
				{
					cout << endl << "Same status." << endl;
				}
				else if (*(statusArr1[inp1 - 1]) != *(statusArr2[inp2 - 1]))
				{
					cout << endl << "Different status." << endl;
				}
			}
			else
			{
				setTextColor(RED);
				cout << "Member not found" << endl;
				setTextColor(LIGHTGREY);
			}
		}
		else
		{
			setTextColor(RED);
			cout << "Member not found" << endl;
			setTextColor(LIGHTGREY);
		}
		break;

	case 2:
		cout << "Enter the first name: ";
		getline(cin, name1);
		fanpage1 = searchEntity<FanPage>(name1);

		if (fanpage1 != nullptr)
		{
			fanpage1->printStatusArr();
			cout << endl << "Enter status number: ";
			cin >> inp1;
			getchar();
			statusArr1 = fanpage1->getStatusArr();

			cout << "Enter the second name: ";
			getline(cin, name2);
			fanpage2 = searchEntity<FanPage>(name2);

			if (fanpage2 != nullptr)
			{
				fanpage2->printStatusArr();
				cout << endl << "Enter status number: ";
				cin >> inp2;
				getchar();
				statusArr2 = fanpage2->getStatusArr();

				if (*(statusArr1[inp1 - 1]) == *(statusArr2[inp2 - 1]))
				{
					cout << endl << "Same status." << endl;
				}
				else if (*(statusArr1[inp1 - 1]) != *(statusArr2[inp2 - 1]))
				{
					cout << endl << "Different status." << endl;
				}
			}
			else
			{
				setTextColor(RED);
				cout << "fan page not found" << endl;
				setTextColor(LIGHTGREY);
			}
		}
		else
		{
			setTextColor(RED);
			cout << "fanpage not found" << endl;
			setTextColor(LIGHTGREY);
		}
		break;
	case 3:
		cout << "Enter member name: ";
		getline(cin, name1);
		member1 = searchEntity<Member>(name1);

		if (member1 != nullptr)
		{
			member1->printStatusArr();
			cout << endl << "Enter status number: ";
			cin >> inp1;
			getchar();
			statusArr1 = member1->getStatusArr();

			cout << "Enter fanpage name: ";
			getline(cin, name2);
			fanpage1 = searchEntity<FanPage>(name2);

			if (fanpage1 != nullptr)
			{
				fanpage1->printStatusArr();
				cout << endl << "Enter status number: ";
				cin >> inp2;
				getchar();
				statusArr2 = fanpage1->getStatusArr();

				if (*(statusArr1[inp1 - 1]) == *(statusArr2[inp2 - 1]))
				{
					cout << endl << "Same status." << endl;
				}
				else if (*(statusArr1[inp1 - 1]) != *(statusArr2[inp2 - 1]))
				{
					cout << endl << "Different status." << endl;
				}
			}
			else
			{
				setTextColor(RED);
				cout << "fan page not found" << endl;
				setTextColor(LIGHTGREY);
			}
		}
		else
		{
			setTextColor(RED);
			cout << "Member not found" << endl;
			setTextColor(LIGHTGREY);
		}
		break;

	default:
		setTextColor(RED);
		cout << "Input is invalid." << endl;
		setTextColor(LIGHTGREY);
		break;
	}
}

void Facebook::printLastTen() const
{
	Member* foundMem;
	string name;

	cout << "Please enter a member name: ";
	getline(cin, name);

	foundMem = searchEntity<Member>(name);
	if (foundMem != nullptr)
	{
		foundMem->printLastTen();
	}
	else
	{
		setTextColor(RED);
		cout << name << " is not exits in facebook." << endl;
		setTextColor(LIGHTGREY);
	}
}

void Facebook::addFollower()
{
	string fanPageName, followerName;
	FanPage *foundFp;
	Member *foundMem;

	cout << "Please enter fan page name: ";
	getline(cin, fanPageName);
	foundFp = searchEntity<FanPage>(fanPageName);

	if (!foundFp)
	{
		setTextColor(RED);
		cout << "fan page not found." << endl;
		setTextColor(LIGHTGREY);
	}
	else
	{
		cout << "Please enter member name: ";
		getline(cin, followerName);
		foundMem = searchEntity<Member>(followerName);

		if (foundFp->isEntityExist(foundMem))
		{
			cout << foundFp->getName() << " is already being followed by " << foundMem->getName() << "." << endl;
		}
		else
		{
			if (!foundMem)
			{
				setTextColor(RED);
				cout << "Member not found." << endl;
				setTextColor(LIGHTGREY);
			}
			else
			{
				*foundFp += *foundMem;
				setTextColor(GREEN);
				cout << followerName << " now following " << fanPageName << '.' << endl;
				setTextColor(LIGHTGREY);
			}
		}
	}
}

void Facebook::comparef() const
{
	int inp, c;
	bool Error;
	Member *member1, *member2;
	FanPage *fanpage1, *fanpage2;
	string name1, name2;

	Error = false;
	member1 = member2 = nullptr;
	fanpage1 = fanpage2 = nullptr;

	cout << "To compare a member with a member press 1" << endl <<
		    "To compare a member with a fanpage press 2" << endl <<
		    "To compare a fanpage with a fanpage press 3" << endl << endl <<
		    ">> ";
	cin >> inp;
	getchar();

	switch (inp)
	{
	case 1:
		cout << "Enter the first name: ";
		getline(cin, name1);
		member1 = searchEntity<Member>(name1);

		if (member1 != nullptr)
		{
			cout << "Enter the second name: ";
			getline(cin, name2);
			member2 = searchEntity<Member>(name2);

			if (member2 != nullptr)
			{
				c = *member1 > *member2;
			}
		}
		else
		{
			Error = true;
		}
		break;
	case 2:
		cout << "Enter the member name: ";
		getline(cin, name1);
		member1 = searchEntity<Member>(name1);

		if (member1 != nullptr)
		{
			cout << "Enter the fanpage name: ";
			getline(cin, name2);
			fanpage1 = searchEntity<FanPage>(name2);

			if (fanpage1 != nullptr)
			{
				c = *member1 > *fanpage1;
			}
		}
		else
		{
			Error = true;
		}
		break;
	case 3:
		cout << "Enter the first name: ";
		getline(cin, name1);
		fanpage1 = searchEntity<FanPage>(name1);

		if (fanpage1 != nullptr)
		{
			cout << "Enter the second name: ";
			getline(cin, name2);
			fanpage2 = searchEntity<FanPage>(name2);

			if (fanpage2 != nullptr)
			{
				c = *fanpage1 > *fanpage2;
			}
		}
		else
		{
			Error = true;
		}
		break;
	default:
		setTextColor(RED);
		cout << "Input is invalid." << endl;
		setTextColor(LIGHTGREY);
		break;
	}

	if (!Error)
	{
		if (c > 0)
		{
			cout << name1 << " has more connections than " << name2 << "." << endl;
		}
		else if (c < 0)
		{
			cout << name2 << " has more connections than " << name1 << "." << endl;
		}
		else
		{
			cout << name1 << " has an equal amount of connections as " << name2 << "." << endl;
		}
	}
	else
	{
		setTextColor(RED);
		cout << "Input is invalid." << endl;
		setTextColor(LIGHTGREY);
	}
}

void Facebook::printEntities() const
{
	cout << "Printing members: " << endl;
	printOneKind<Member>();

	cout << endl;

	cout << "Printing fan pages: " << endl;
	printOneKind<FanPage>();
}

void Facebook::printConnections() const
{
	int inpKind;
	string name;
	Member* foundMem;
	FanPage* foundFanPage;

	cout << "To print all of the friends of a member press 1," << endl << 
		    "to print all of the followers of a fan page press 2." << endl << endl << 
		    ">> ";
	cin >> inpKind;
	getchar();

	switch (inpKind)
	{
	case 1:
		cout << "Enter member's name: ";
		getline(cin, name);
		foundMem = searchEntity<Member>(name);

		if (foundMem)
		{
			if (foundMem->getFC() != 0)
			{
				foundMem->printConnections();
			}
			else
			{
				cout << "This member has no friends." << endl;
			}
		}
		else
		{
			cout << "Member not found." << endl;
		}
		break;

	case 2:
		cout << "Enter fan page name: ";
		getline(cin, name);
		foundFanPage = searchEntity<FanPage>(name);

		if (foundFanPage)
		{
			if (foundFanPage->getFC() != 0)
			{
				foundFanPage->printConnections();
			}
			else
			{
				cout << "This fan page has no followers." << endl;
			}
		}
		else
		{
			cout << "Fan page not found." << endl;
		}
		break;
	}
}

Facebook::~Facebook()
{
	for (vector<Entity*>::iterator it = Entities.begin(); it != Entities.end(); it++)
	{
		delete *it;
	}

	Entities.clear();
}