#include <iostream>
#include <cstdlib>
#include "string"
#include <fstream>

using namespace std;

struct DOP
{
	unsigned int mm;
	unsigned int dd;
	unsigned int yy;
};
class Mem
{
protected:
	string Name;
	int Id;
	int MemD;
public:
	Mem(string str="r", int id=0, int memd = 30)
	{
		Name = str;
		Id = id;
		MemD = memd;
	}

	void Edit(string name,int id)
	{
		Name = name;
		Id = id;
		MemD = 30;
	}
	int Mod(string name,int id)
	{
		if (Id == id)
		{
			Name = name;
			return 1;
		}
		else return 0;
	}
	int Search(int id)
	{
		if (Id==id)
		{
			system("CLS");
			Display();
			cout << endl;
			system("pause");
			return 1;
		}
		else return 0;
	}
	int Confirm(int id)
	{
		if (Id == id)
		{
			return 1;
		}
		else
			return 0;
	}
	void Renew()
	{
		MemD = MemD + 30;
		cout << "Membership Renewed Successfully.\n" << endl;
		system("pause");
	}
	void DPassed()
	{
		MemD = MemD - 1;
	}
	void Display()
	{
		cout << ".:(Member Information):. " << endl;
		cout << "Name: " << Name << endl;
		cout << "Registration Number: " << Id << endl;
		cout << "Membership Days Left: " << MemD << endl;
	}
	void ShortDisplay()
	{
		cout << Name <<"	"<<Id<<"	"<<MemD << endl;
	}
};
class PMem: public Mem
{
	int TMHours;
public:
	PMem(string name="a", int id=0)
	{
		Mem(name, id);
		TMHours = 30;
	}
	void Display() 
	{
		cout << ".:(Member Information):. " << endl;
		cout << "Name: " << Name << endl;
		cout << "Registration Number: " << Id << endl;
		cout << "Membership Days Left: " << MemD << endl;
		cout << "Treadmill Time Left: " << TMHours << " Hours" << endl;
	}
	void Renew()
	{
		MemD = MemD + 30;
		TMHours = 30;
		cout << "Membership Renewed Successfully.\n" << endl;
		system("pause");
	}
	int TMUsed(unsigned int Used, int id)
	{
		if (Id == id) {
			TMHours = TMHours - Used;
			if (TMHours < 0)
			{
				TMHours = 0;
			}
			return 1;
		}
		else return 0;
	}
	int Search(int id)
	{
		if (Id == id)
		{
			system("CLS");
			Display();
			cout << endl;
			system("pause");
			return 1;
		}
		else return 0;
	}
	void ShortDisplay()
	{
		cout << Name << "	" << Id << "	" << MemD << "	" << TMHours << endl;
	}
};
class Owner 
{
protected:
	string Name;
	int Password;
	int Identifier;
public:
	Owner(string name="a", int pass=0, int idf=1) 
	{
		Name = name;
		Password = pass;
		Identifier = idf;
	}

	int Login(string name, int pass) 
	{
		if (name == Name && pass == Password)
		{
			return Identifier;
		}
		else if (name == Name && pass != Password)
		{
			return 0;
		}
		else 
		{
			return 0;
		}
	}
	void Set(string name, int pass, int idf)
	{
		Name = name;
		Password = pass;
		Identifier = idf;
	}
};
class Trainer: public Owner
{
public:
	Trainer(string name="a", int pass=0)
	{
		Owner(name, pass, 2);
	}
};
class Purchase 
{
	int cost;
	string name;
	DOP date;
public:
	Purchase(int COST=0, string NAME="a", int dd=0, int mm=0, int yy=0)
	{
		cost = COST;
		name = NAME;
		date.dd = dd;
		date.mm = mm;
		date.yy = yy;
	}
	void Display()
	{
		cout << "Equipment Purchased: " << name << endl;
		cout << "Cost of Equipment: " <<cost<< endl;
		cout << "Date of Purchase: " << date.dd << "-" << date.mm << "-" << date.yy << endl;
	}
	void Edit(int COST, string NAME, int dd, int mm, int yy)
	{
		cost = COST;
		name = NAME;
		date.dd = dd;
		date.mm = mm;
		date.yy = yy;
	}
};

void MMenu() //Main Menu
{
	system("CLS");
	cout << ".:(Main Menu):." << endl;
	cout << "1. Member Management" << endl;
	cout << "2. Membership Plans " << endl;
	cout << "3. Training Plans and Exercises" << endl;
	cout << "4. Contact Information" << endl;
	cout << "5. FAQ" << endl;
	cout << "6. Purchase Logs" << endl;
	cout << "7. Quit Application" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}

// Sub-Menus
void MemMenu() //Member Data Menu 
{
	system("CLS");
	cout << ".:(Member Management):." << endl;
	cout << "1. Add a New Member" << endl;
	cout << "2. Modify a Member's Data" << endl;
	cout << "3. Delete a Member" << endl;
	cout << "4. Search a Member" << endl;
	cout << "5. Display All Members" << endl;
	cout << "6. Display The Number of Members" << endl;
	cout << "7. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void MusMenu() //Training Plans Menu
{
	system("CLS");
	cout << ".:(Training Plans and Exercises):." << endl;
	cout << "1. Training Plans" << endl;
	cout << "2. Muscle Exercises" << endl;
	cout << "3. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void EqMenu() //Purchase Logs Menu
{
	system("CLS");
	cout << ".:(Purchase Logs):." << endl;
	cout << "1. Add a New Purchase" << endl;
	cout << "2. Display Last Purchase" << endl;
	cout << "3. Display All Purchases" << endl;
	cout << "4. Modify a Purchase" << endl;
	cout << "5. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void ContactMenu()
{
	system("CLS");
	cout << ".:(Contact Information):." << endl;
	cout << "1. Gym Address and Number" << endl;
	cout << "2. Owner's Contact Number" << endl;
	cout << "3. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void MemshipMenu()
{
	system("CLS");
	cout << ".:(Membership Plans):." << endl;
	cout << "1. Regular Membership Plan" << endl;
	cout << "2. Premium Membership Plan" << endl;
	cout << "3. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void FAQ()
{
	system("CLS");
	cout << ".:(Frequently Asked Question):." << endl;
	cout << " 1. Does bodybuilding stunt height growth?" << endl;
	cout << " 2. Can I build muscle and lose fat at the same time?" << endl;
	cout << " 3. I spend hours at the gym without results. Why?" << endl;
	cout << " 4. How much protein intake is optimal for muscle growth?" << endl;
	cout << " 5. How frequently should I train a muscle?" << endl;
	cout << " 6. Does the 1-hour Anabolic Window exist?" << endl;
	cout << " 7. Should I use pre-workouts?" << endl;
	cout << " 8. Are supplements necessary?" << endl;
	cout << " 9. How heavy should I lift?" << endl;
	cout << "10. How often should I increase the weights I lift?" << endl;
	cout << "11. Should I workout even if I am above 40 years of age?" << endl;
	cout << "12. Return" << endl << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}

// Membership Menu Sub-Menus
void AddMem()
{
	system("CLS");
	cout << ".:(Member Creation):." << endl;
	cout << "1. Add a Regular Member" << endl;
	cout << "2. Add a Premium Member" << endl;
	cout << "3. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void ModifyMem()
{
	system("CLS");
	cout << ".:(Member Modification):." << endl;
	cout << "1. Modify a Regular Member's Name" << endl;
	cout << "2. Modify a Premium Member's Name" << endl;
	cout << "3. Reduce Membership Day of All Members" << endl;
	cout << "4. Modify the Treadmill Hours of a Premium Member" << endl;
	cout << "5. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void DisplayMem()
{
	system("CLS");
	cout << ".:(Multiple Member Display):." << endl;
	cout << "1. Display all Regular Members" << endl;
	cout << "2. Display all Premium Members" << endl;
	cout << "3. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void SearchMem()
{
	system("CLS");
	cout <<".:(Member Search):." <<endl;
	cout << "1. Search a Regular Member" << endl;
	cout << "2. Search a Premium Member" << endl;
	cout << "3. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void DeleteMem()
{
	system("CLS");
	cout << ".:(Member Deletion):." << endl;
	cout << "1. Delete a Regular Member" << endl;
	cout << "2. Delete a Premium Member" << endl;
	cout << "3. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}

// Training Plans
void TrainingPlans()
{
	system("CLS");
	cout << ".:(Training Plans):." << endl;
	cout << "1. Push-Pull-Legs Split" << endl;
	cout << "2. Torso-Arms-Legs Split" << endl;
	cout << "3. German Volume Training (10x10)" << endl;
	cout << "4. 5x5 Training Plan" << endl;
	cout << endl;
	system("pause");
}

// Muscle Exercises Sub-Menu
void ExercisesMenu()
{
	system("CLS");
	cout << ".:(Muscle Exercises):." << endl;
	cout << "1. Chest" << endl;
	cout << "2. Back" << endl;
	cout << "3. Biceps" << endl;
	cout << "4. Triceps" << endl;
	cout << "5. Shoulders" << endl;
	cout << "6. Legs" << endl;
	cout << "7. Return" << endl;
	cout << "Please Enter the Number of Your Desired Option: ";
}
void ChestEx()
{
	system("CLS");
	cout << ".:(Chest Exercises):." << endl;
	cout << "1. Bench Press" << endl;
	cout << "2. Inclined Bench Press" << endl;
	cout << "3. Declined Bench Press" << endl;
	cout << "4. Cable Crossovers" << endl;
	cout << "5. Push-ups" << endl;
	cout << "6. Chest Fly" << endl;
	cout << "7. Dumbbell/Barbell Pullovers" << endl;
	cout << "8. Dips" << endl << endl;
}
void BackEx()
{
	system("CLS");
	cout << ".:(Back Exercises):." << endl;
	cout << "1. Lat Pull-down" << endl;
	cout << "2. Row Machine" << endl;
	cout << "3. Barbell Rows" << endl;
	cout << "4. Deadlift" << endl;
	cout << "5. Pull-ups" << endl;
	cout << "6. Farmer's Carry" << endl;
	cout << "7. T-Bar Row" << endl << endl;
}
void BicepEx()
{
	system("CLS");
	cout << ".:(Biceps Exercises):." << endl;
	cout << "1. Dumbbell Curls" << endl;
	cout << "2. Wide-Grip Barbell Curls" << endl;
	cout << "3. Preacher Curls" << endl;
	cout << "4. Concentrated Curls" << endl;
	cout << "5. Inclined Dumbbell Curls" << endl;
	cout << "6. Hammer Curls" << endl;
	cout << "7. Chin-Ups" << endl << endl;
}
void TricepEx()
{
	system("CLS");
	cout << ".:(Triceps Exercises):." << endl;
	cout << "1. Tricep Pushdown" << endl;
	cout << "2. One-Arm Overhead Extension" << endl;
	cout << "3. Tricep Kickbacks" << endl;
	cout << "4. Bench Dip" << endl;
	cout << "5. Tricep Dips" << endl;
	cout << "6.	Skull-crusher" << endl;
	cout << "7. Close-Grip Bench Press" << endl << endl;
}
void ShoulderEx()
{
	system("CLS");
	cout << ".:(Shoulders Exercises):." << endl;
	cout << "1. Overhead Press" << endl;
	cout << "2. Dumbbell Front Raise" << endl;
	cout << "3. Dumbbell Side Lateral Raise" << endl;
	cout << "4. Dumbbell Upright Row" << endl;
	cout << "5. Shrugs" << endl;
	cout << "6. Arnold Press" << endl;
	cout << "7. Military Press" << endl << endl;
}
void LegEx()
{
	system("CLS");
	cout << ".:(Legs Exercises):." << endl;
	cout << "1. Squats" << endl;
	cout << "2. Lunges" << endl;
	cout << "3. Leg Press" << endl;
	cout << "4. Leg Extensions" << endl;
	cout << "5. Step-Ups" << endl;
	cout << "6. Box Jumps" << endl;
	cout << "7. Deadlift" << endl << endl;
}

// Membership Plans
void RegPlan()
{
	system("CLS");
	cout << ".:(Regular Membership Plan):." << endl;
	cout << "Regular Membership Cost is Rs.1,000." << endl << endl;
	cout << "Membership Features: " << endl;
	cout << "1. Access to Gym Equipment (Other than Treadmill)." << endl;
	cout << "2. 1-Week Trial Coaching from Trainers." << endl;
	cout << "3. Free Dietary Advice." << endl << endl;
}
void PremPlan()
{
	system("CLS");
	cout << ".:(Premium Membership Plan):." << endl;
	cout << "Membership Cost is Rs.5,000." << endl << endl;
	cout << "Membership Features: " << endl;
	cout << "1. Access to All Gym Equipment." << endl;
	cout << "2. Permanent Free Coaching from Trainers." << endl;
	cout << "3. Free Dietary Advice." << endl;
	cout << "4. Access to Treadmill." << endl;
	cout << "5. Training Routines Tailored for your Fitness Goals." << endl;
	cout << "6. 20% Discount on Gym Merchandise." << endl << endl;
}

int main()
{
	int Auth = 0, i, j, k, APass, MenuLoop = 0, SMLoop, MusMLoop = 0;

	int MemLoop = 0, MemID = 1, RMemCount = 0, PMemCount = 0, IdInt, TMCut, Confirm;
	string MemName;
	Mem M[50];
	PMem PM[50];

	char MMOpt, MusMOpt, SMOpt, MemOpt;
	int FAQOpt;

	int PurLoop, PCost, PNum = 0, Pdd, Pmm, Pyy, PIn;
	string PName;
	Purchase P[10];

	string Address = "Opposite to Wright & Co. Law Offices, Nessie Road, District 13, Starfish Island, Vice City.";
	string GNumber = "012-4567890", ONumber = "0123-4567890";
	Owner Own("Ahmed",1234, 1),*ptr;
	Trainer T[5];
	T[0].Set("Waseem", 1122, 2);
	T[1].Set("Sohail", 1337, 2);
	T[2].Set("Bilal", 4200, 2);
	T[3].Set("Awais", 5678, 2);
	T[4].Set("Faraz", 4444, 2);
	string AName;

	ptr = &Own;
	cout << ".:(XFit Gym Management System Login):." << endl;
	cout << "Please Enter Your Name: ";
	cin >> AName;
	cout << "Please Enter Your Password: ";
	cin >> APass;
	Auth = ptr->Login(AName, APass);
	if(Auth==0)
	{
		for (i=0;i<5;i++)
		{
			ptr = &T[i];
			Auth=ptr->Login(AName, APass);
			if (Auth == 2)
				break;
		}
		if (Auth==0)
		{
			cout << "Incorrect Login Credentials. Please Try Again.\n" << endl;
			system("pause");
		}
	}

	while(Auth == 0)
	{
		system("CLS");
		ptr = &Own;
		cout << "Please Enter Your Name: ";
		cin >> AName;
		cout << "Please Enter Your Password: ";
		cin >> APass;
		Auth = ptr->Login(AName, APass);
		if (Auth == 0)
		{
			for (i = 0; i < 5; i++)
			{
				ptr = &T[i];
				Auth = ptr->Login(AName, APass);
				if (Auth == 2)
					break;
			}
			if (Auth == 0)
			{
				cout << "Incorrect Login Credentials. Please Try Again." << endl;
			}
		}
	}

	while (MenuLoop == 0) 
	{
		SMLoop = 0;
		SMOpt = 0;
		MMenu();
		cin >> MMOpt;
		if (MMOpt == '1')
		{
			while (SMLoop == 0) 
			{
				MemMenu();
				MemLoop = 0;
				cin >> SMOpt;
				if (SMOpt == '1') 
				{
					while (MemLoop == 0)
					{
						AddMem();
						cin >> MemOpt;
						if(MemOpt=='1')
						{
							if (RMemCount < 50) 
							{
								system("CLS");
								cout << ".:(Regular Member Creation):." << endl;
								cout << "Enter the Name of the Member: ";
								cin.ignore();
								getline(cin, MemName);
								M[RMemCount].Edit(MemName, MemID);
								cout << "Member Created Successfully with ID "<<MemID<<"." << endl;
								RMemCount++;
								MemID++;
								system("pause");
							}
							else
							{
								cout << endl << "Memory Limit Reached. More Members Cannot be Added." << endl << endl;
								system("pause");
							}
						}
						else if(MemOpt=='2')
						{
							if (PMemCount < 50)
							{
								system("CLS");
								cout << ".:(Premium Member Creation):." << endl;
								cout << "Enter the Name of the Member: ";
								cin.ignore();
								getline(cin, MemName);
								PM[PMemCount].Edit(MemName, MemID);
								cout << "Member Created Successfully with ID "<<MemID<<"." << endl;
								PMemCount++;
								MemID++;
								system("pause");
							}
							else
							{
								cout << endl << "Memory Limit Reached. More Premium Members Cannot be Added." << endl << endl;
								system("pause");
							}
						}
						else if(MemOpt =='3')
						{
							MemLoop = 1;
						}
						else 
						{ 
							cout << "Invalid Entry. Please Try Again." << endl; 
						}
					}
				}
				else if (SMOpt=='2')
				{
					while(MemLoop==0)
					{
						ModifyMem();
						Confirm = 0;
						cin >> MemOpt;
						if(MemOpt=='1')
						{
							system("CLS");
							if (RMemCount > 0) 
							{
								cout << ".:(Regular Member Data Modification):." << endl;
								cout << "Enter the ID of the Member: ";
								cin >> IdInt;
								cout << "Enter the New Name of the Member: ";
								cin.ignore();
								getline(cin, MemName);
								for (i = 0; i <= RMemCount; i++)
								{
									Confirm = M[i].Mod(MemName, IdInt);
									if (Confirm == 1)
										break;
								}
								if (Confirm == 1)
								{
									cout << "Member Data Modified Successfully." << endl << endl;
									cout << "New Data is:" << endl;
									M[i].Display();
									system("pause");
								}
								else
								{
									cout << "No Regular Member with Provided ID found. Please Try Again." << endl << endl;
									system("pause");
								}
							}
							else
							{
								cout << "No Member Data Found.\n" << endl;
								system("pause");
							}
						}
						else if(MemOpt=='2')
						{
							system("CLS");
							if (PMemCount > 0) {
								cout << ".:(Premium Member Data Modification):." << endl;
								cout << "Enter the ID of the Member: ";
								cin >> IdInt;
								cout << "Enter the New Name of the Member: ";
								cin.ignore();
								getline(cin, MemName);
								for (i = 0; i <= PMemCount; i++)
								{
									Confirm = PM[i].Mod(MemName, IdInt);
									if (Confirm == 1)
										break;
								}
								if (Confirm == 1)
								{
									cout << "Member Data Modified Successfully." << endl << endl;
									cout << "New Data is:" << endl;
									PM[i].Display();
									system("pause");
								}
								else
								{
									cout << "No Premium Member with Provided ID found. Please Try Again." << endl << endl;
									system("pause");
								}
							}
							else
							{
								cout << "No Member Data Found.\n" << endl;
								system("pause");
							}
						}
						else if(MemOpt=='3')
						{
							system("CLS");
							if(PMemCount==0&&RMemCount==0)
							{
								cout << "No Member Data Found.\n" << endl;
								system("pause");
							}
							else 
							{
								cout << ".:(Membership Day Reduction):." << endl;
								for (i = 0; i < 50; i++)
								{
									PM[i].DPassed();
									M[i].DPassed();
								}
								cout << "Membership Day Reduced Successfully.\n" << endl;
								system("pause");
							}
						}
						else if(MemOpt=='4')
						{
							system("CLS");
							if (PMemCount > 0) 
							{
								cout << ".:(Premium Member Treadmill Hours Modification):." << endl;
								cout << "Enter the ID of the Member to be modified: ";
								cin >> IdInt;
								cout << "Enter the Number of Hours to Cut: ";
								cin >> TMCut;
								while(TMCut>8||TMCut<0)
								{
									cout << "Invalid Entry. Please Try Again.\n" << endl;
									cout << "Enter the Number of Hours to Cut: ";
									cin >> TMCut;
								}
								for (i = 0; i <= PMemCount; i++)
								{
									Confirm = PM[i].TMUsed(TMCut, IdInt);
									if (Confirm == 1)
										break;
								}
								if (Confirm == 1)
								{
									cout << "Treadmill Hours Modified Successfully." << endl << endl;
									cout << "New Data is:" << endl;
									PM[i].Display();
									system("pause");
								}
								else
								{
									cout << "No Premium Member with Provided ID found. Please Try Again." << endl << endl;
									system("pause");
								}
							}
							else
							{
								cout << "No Member Data found.\n" << endl;
								system("pause");
							}
						}
						else if(MemOpt=='5')
						{
							MemLoop = 1;
						}
						else 
						{
							cout << "Invalid Entry. Please Try Again." << endl;
						}
					}
				}
				else if (SMOpt == '3') 
				{
					while(MemLoop==0)
					{
						Confirm = 0;
						DeleteMem();
						cin >> MemOpt;
						if (MemOpt=='1')
						{
							system("CLS");
							if (RMemCount > 0)
							{
								cout << ".:(Regular Member Deletion):." << endl;
								cout << "Enter the ID of the Member: ";
								cin >> IdInt;
								for (i = 0; i <= RMemCount; i++)
								{
									Confirm = M[i].Confirm(IdInt);
									if (Confirm == 1)
									{
										j = i;
										break;
									}
								}
								if (Confirm == 1)
								{
									for (k = j + 1; k <= RMemCount; k++)
									{
										M[j] = M[k];
										j++;
									}
									cout << "Member Data Deleted Successfully." << endl;
									system("pause");
									RMemCount--;
								}
								else
								{
									cout << "No Regular Member with Provided ID found. Please Try Again." << endl;
									system("pause");
								}
							}
							else
							{
								cout << "No Member Data Found.\n" << endl;
								system("pause");
							}
							
						}
						else if(MemOpt=='2')
						{
							system("CLS");
							if (PMemCount > 0)
							{
								cout << ".:(Premium Member Deletion):." << endl;
								cout << "Enter the ID of the Member: ";
								cin >> IdInt;
								for (i = 0; i <= PMemCount; i++)
								{
									Confirm = PM[i].Confirm(IdInt);
									if (Confirm == 1)
									{
										j = i;
										break;
									}
								}
								if (Confirm == 1)
								{
									for (k = j + 1; k <= PMemCount; k++)
									{
										PM[j] = PM[k];
										j++;
									}
									cout << "Member Data Deleted Successfully." << endl;
									system("pause");
									PMemCount--;
								}
								else
								{
									cout << "No Premium Member with Provided ID found. Please Try Again." << endl;
									system("pause");
								}
							}
							else
							{
								cout << "No Member Data Found.\n" << endl;
								system("pause");
							}
						}
						else if(MemOpt=='3')
						{
							MemLoop = 1;
						}
						else 
						{
							cout << "Invalid Entry. Please Try Again." << endl;
							system("pause");
						}
					}
				}
				else if (SMOpt=='4')
				{
					while(MemLoop==0)
					{
						SearchMem();
						Confirm = 0;
						cin >> MemOpt;
						if(MemOpt=='1')
						{
							system("CLS");
							if (RMemCount > 0) 
							{
								cout << ".:(Regular Member Search):." << endl;
								cout << "Enter the ID of the Member: ";
								cin >> IdInt;
								for (i = 0; i <= RMemCount; i++)
								{
									Confirm = M[i].Search(IdInt);
									if (Confirm == 1)
										break;
								}
								if (Confirm == 0)
								{
									cout << "No Regular Member with Provided ID found. Please Try Again." << endl;
									system("pause");
								}
							}
							else
							{
								cout << "No Member Data Found.\n" << endl;
								system("pause");
							}
						}
						else if(MemOpt=='2')
						{
							system("CLS");
							if (PMemCount > 0) 
							{
								cout << ".:(Premium Member Search):." << endl;
								cout << "Enter the ID of the Member: ";
								cin >> IdInt;
								for (i = 0; i <= RMemCount; i++)
								{
									Confirm = PM[i].Search(IdInt);
									if (Confirm == 1)
										break;
								}
								if (Confirm == 0)
								{
									cout << "No Premium Member with Provided ID found. Please Try Again." << endl;
									system("pause");
								}
							}
							else
							{
								cout << "No Member Data Found.\n" << endl;
								system("pause");
							}
						}
						else if(MemOpt=='3')
						{
							MemLoop = 1;
						}
						else
						{
							cout << "Invalid Entry. Please Try Again." << endl;
							system("pause");
						}
					}
				}
				else if (SMOpt=='5')
				{
					while (MemLoop == 0)
					{
						DisplayMem();
						cin >> MemOpt;
						if (MemOpt == '1')
						{
							system("CLS");
							if (RMemCount > 0) 
							{
								cout << ".:(Regular Members Display):.\n" << endl;
								cout << "The Format of Display is: Name, ID, Membership Time\n" << endl;
								for (int i = 0; i < RMemCount; i++)
								{
									M[i].ShortDisplay();
								}
								system("pause");
							}
							else
							{
								cout << "No Member Data Found." << endl << endl;
								system("pause");
							}
						}
						else if (MemOpt == '2')
						{
							system("CLS");
							if (PMemCount > 0)
							{
								cout << ".:(Premium Members Display):.\n" << endl;
								cout << "The Format of Display is: Name, ID, Membership Time, Treadmill Time\n" << endl;
								for (int i = 0; i < PMemCount; i++)
								{
									PM[i].ShortDisplay();
								}
								system("pause");
							}
							else
							{
								cout << "No Member Data Found." << endl << endl;
								system("pause");
							}
						}
						else if (MemOpt=='3')
						{
							MemLoop = 1;
						}
						else
						{
							cout << endl << "Invalid Entry. Please Try Again." << endl << endl;
							system("pause");
						}
					}
				}
				else if (SMOpt=='6')
				{
					system("CLS");
					cout << ".:(Member Count):." << endl;
					cout << "Regular Members: " << RMemCount << endl;
					cout << "Premium Members: " << PMemCount << endl << endl;
					system("pause");
				}
				else if (SMOpt == '7')
				{
					SMLoop = 1;
				}
				else 
				{
					cout << "Invalid Option. Please Try Again." << endl;
				}
			}
		}
		else if (MMOpt == '2')
		{
			while (SMLoop == 0) 
			{
			MemshipMenu();
			cin >> SMOpt;
			cout << endl;
			if(SMOpt=='1')
			{
				RegPlan();
				system("pause");
			}
			else if (SMOpt == '2')
			{
				PremPlan();
				system("pause");
			}
			else if (SMOpt == '3')
			{
				SMLoop = 1;
			}
			else 
			{
				cout << "Invalid Entry. Please Try Again." << endl;
				system("pause");
			}
			}
		}
		else if (MMOpt == '3')
		{
			while (SMLoop == 0) {
				MusMenu();
				MusMLoop = 0;
				cin >> SMOpt;
				if(SMOpt=='1')
				{
					TrainingPlans();
				}
				if(SMOpt=='2')
				{
					while (MusMLoop == 0)
					{
						ExercisesMenu();
						cin >> MusMOpt;
						if (MusMOpt == '1') 
						{
							ChestEx();
							system("pause");
						}
						else if (MusMOpt == '2') 
						{
							BackEx();
							system("pause");
						}
						else if (MusMOpt == '3') 
						{
							BicepEx();
							system("pause");
						}
						else if (MusMOpt == '4') 
						{
							TricepEx();
							system("pause");
						}
						else if (MusMOpt == '5') 
						{
							ShoulderEx();
							system("pause");
						}
						else if (MusMOpt == '6')
						{
							LegEx();
							system("pause");
						}
						else if(MusMOpt=='7')
						{
							MusMLoop = 1;
						}
						else {
							cout << "Invalid Entry. Please Try Again." << endl;
							system("pause");
						}
					}
				}
				else if(SMOpt=='3')
				{
					SMLoop = 1;
				}
				else 
				{
					cout << "Invalid Entry. Please Try Again." << endl;
					system("pause");
				}
			}
		}
		else if (MMOpt == '4')
		{
			while (SMLoop == 0) 
			{
				ContactMenu();
				cin >> SMOpt;
				cout << endl;
				if(SMOpt=='1')
				{
					system("CLS");
					cout << ".:(Gym Contact Information):." << endl;
					cout << "The Gym is Located At: " << Address << endl;
					cout << "The Gym Phone Number is: " << GNumber << endl << endl;
					system("pause");
				}
				else if(SMOpt=='2')
				{
					system("CLS");
					cout << ".:(Owner Contact Information):." << endl;
					cout << "The Owner's Phone Number is: " << ONumber << endl << endl;
					system("pause");
				}
				else if(SMOpt=='3')
				{
					SMLoop = 1;
				}
				else
				{
					cout << "Invalid Entry. Please Try Again." << endl;
					system("pause");
				}
			}
		}
		else if (MMOpt == '5')
		{
			while (SMLoop == 0)
			{
				FAQ();
				cin >> FAQOpt;
				if (FAQOpt == 1) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "Does bodybuilding stunt growth?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "This has been proven to be a myth. Bodybuilding has no effect on your growth." << endl;
					cout << "It will neither stunt your growth nor accelerate it." << endl;
					cout << "This is also the case for younger kids.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 2) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "Can I build muscle and lose fat at the same time?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "Yes, it indeed is possible. You can lose fat and gain muscle at the same time." << endl;
					cout << "This process is called body recomposition and it is the most popular approach." << endl;
					cout << "A lot of celebrities also use this tactic while preparing for roles in their shows.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 3) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "I spend hours at the gym without results. Why?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "This can come down to a lot of factors." << endl;
					cout << "1. Lack of Sleep: Muscle Repair is a process that happens during sleep and insufficient sleep means incomplete muscle repair." << endl;
					cout << "2. Lack of Proper Diet: Not having the proper diet means your muscles do not get the nutrition needed to grow." << endl;
					cout << "3. Overtraining: Training a muscle beyond its limit will not cause growth and will instead become a burden.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 4) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "How much protein intake is optimal for muscle growth?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "For muscle growth, 1.3g to 1.7g of protein per kg of your weight is recommended." << endl;
					cout << "In terms of pounds, 0.5g to 0.8g of protein per pound of your weight." << endl;
					cout << "These amounts have been found to be optimal after being experimented in many studies.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 5) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "How frequently should I train a muscle?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "Each muscle needs an adequate amount of rest after each workout." << endl;
					cout << "It is suggested that each muscle should be rested for at least a day before training it again." << endl;
					cout << "It is based on this that many workout splits are designed.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 6) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "Does the 2-hour Anabolic Window exist?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "The 2-hour Anabolic Window is a term often used by fitness celebrities." << endl;
					cout << "It has largely been proven to be a myth as the muscles repair during sleep." << endl;
					cout << "Protein should be taken at any time of the day so it can be synthesized and broken down by the body." << endl;
					cout << "It is then used to build muscle when you are sleeping.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 7) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "Should I use pre-workouts?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "Pre-Workouts are used as an energy boost by a lot of people before a workout session." << endl;
					cout << "They can be used every once in a while as they can enhance performance in the gym." << endl;
					cout << "Using them on a regular basis will create a dependency on them." << endl;
					cout << "Having a dependency will see a major decrease in performance without them.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 8) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "Are supplements necessary?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "Supplements are by no means necessary if you have a proper diet." << endl;
					cout << "As the word suggests, supplements are meant to complete your deficiency of some nutrient." << endl;
					cout << "If your diet does not provide adequate amounts of some nutrient, its supplement can be used." << endl;
					cout << "But you can avoid unnecessary spending on them if your diet is well rounded.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 9) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "How heavy should I lift?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "The weight you lift should neither be too heavy nor too light." << endl;
					cout << "You should be able to perform 8-12 repetitions and reach exhaustion." << endl;
					cout << "Anything more or less means you should switch weights.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 10) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "How often should I increase the weights I lift?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "When you can easily lift the weight you are using, you can try increasing it." << endl;
					cout << "You can also try lifting a heavier weight if you are confident enough." << endl;
					cout << "If you can easily do 12 repetitions, increase the load.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 11) 
				{
					system("CLS");
					cout << ".:(Question):." << endl;
					cout << "Should I workout even if I am above 40 years of age?" << endl << endl;
					cout << ".:(Answer):." << endl;
					cout << "There is no age limit for working out and it is never late to get fit." << endl;
					cout << "Although your body will have different peak fitness levels with age, it is never to late to get fit." << endl;
					cout << "Icons such as Arnold Schwarzenegger and Sylvester Stallone still workout despite being 74 and 75 respectively.\n" << endl;
					system("pause");
				}
				else if (FAQOpt == 12) 
				{
					SMLoop = 1;
				}
				else
				{
					cout << "Invalid Entry. Please Try Again." << endl;
					system("pause");
				}
			}
		}
		else if (MMOpt == '6')
		{
			if (Auth == 1)
			{
				while (SMLoop == 0) {
					EqMenu();
					cin >> SMOpt;
					cout << endl;
					if (SMOpt == '1')
					{
						if (PNum > 9)
						{
							cout << "Memory Limit Reached. More Purchases Cannot be Added." << endl;

						}
						else {
							system("CLS");
							cout << ".:(Purchase Creation):." << endl;
							cout << "Enter the Name of Equipment: ";
							cin.ignore();
							getline(cin, PName);
							cout << "Enter the Cost: ";
							cin >> PCost;
							cout << "Enter the Date of Purchase" << endl;
							cout << "Day: ";
							cin >> Pdd;
							while (Pdd < 1 || Pdd>31)
							{
								cout << "Invalid Entry. Please Try Again." << endl;
								cout << "Day: ";
								cin >> Pdd;
							}
							cout << "Month: ";
							cin >> Pmm;
							while (Pmm < 1 || Pmm>12)
							{
								cout << "Invalid Entry. Please Try Again." << endl;
								cout << "Month: ";
								cin >> Pmm;
							}
							cout << "Year: ";
							cin >> Pyy;
							while (Pyy > 2022 || Pyy < 2000)
							{
								cout << "Invalid Entry. Please Try Again." << endl;
								cout << "Year: ";
								cin >> Pyy;
							}
							P[PNum].Edit(PCost, PName, Pdd, Pmm, Pyy);
							PNum++;
							cout << "Purchase Added Successfully." << endl;
							system("pause");
						}
					}
					else if (SMOpt == '2')
					{
						if (PNum == 0)
						{
							cout << "There is no Purchase History." << endl << endl;
						}
						else
						{
							system("CLS");
							cout << ".:(Last Purchase Display):." << endl;
							P[PNum - 1].Display();
							cout << endl;
						}
						system("pause");
					}
					else if (SMOpt == '3')
					{
						if (PNum == 0)
						{
							cout << "There is no Purchase History." << endl << endl;
						}
						else
						{
							system("CLS");
							cout << ".:(All Purchases):." << endl;
							for (PurLoop = 0; PurLoop < PNum; PurLoop++)
							{
								P[PurLoop].Display();
								cout << endl;
							}
						}
						system("pause");
					}
					else if (SMOpt == '4')
					{
						if (PNum == 0)
						{
							cout << "There is no Purchase History." << endl << endl;
							system("pause");
						}
						else 
						{
							system("CLS");
							cout << ".:(Purchase Modification):." << endl;
							cout << "Enter the Number of Purchase to Modify: ";
							cin >> PIn;
							if (PIn <= 0 || PIn > PNum)
							{
								cout << "Invalid Entry. Please Try Again." << endl;
								system("pause");
							}
							else
							{
								cout << "Enter the New Name of Equipment: ";
								cin.ignore();
								getline(cin, PName);
								cout << "Enter the New Cost: ";
								cin >> PCost;
								cout << "Enter the New Date of Purchase" << endl;
								cout << "Day: ";
								cin >> Pdd;
								while (Pdd < 1 || Pdd>31)
								{
									cout << "Invalid Entry. Please Try Again." << endl;
									cout << "Day: ";
									cin >> Pdd;
								}
								cout << "Month: ";
								cin >> Pmm;
								while (Pmm < 1 || Pmm>12)
								{
									cout << "Invalid Entry. Please Try Again." << endl;
									cout << "Month: ";
									cin >> Pmm;
								}
								cout << "Year: ";
								cin >> Pyy;
								while (Pyy > 2022 || Pyy < 2000)
								{
									cout << "Invalid Entry. Please Try Again." << endl;
									cout << "Year: ";
									cin >> Pyy;
								}
								P[PIn-1].Edit(PCost, PName, Pdd, Pmm, Pyy);
								cout << "Purchase Data Modified Successfully." << endl;
								system("pause");
							}
						}
					}
					else if (SMOpt == '5')
					{
						SMLoop = 1;
					}
					else
					{
						cout << "Invalid Entry. Please Try Again." << endl;
						system("pause");
					}
				}
			}
			else
			{
				system("CLS");
				cout << ".:(Access Denied):." << endl;
				cout << "You Do Not Have Permission to Access This Menu.\n" << endl;
				system("pause");
			}
		}
		else if (MMOpt == '7')
		{
			return 0;
		}
		else
		{
			cout << "Invalid Entry. Please Try Again." << endl;
			system("pause");
		}
	}
}