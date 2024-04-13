#include <iostream>
using namespace std;

const int students_possible_number = 10;
int students_current_number = 0;
int sportics_current_number = 0;
const int max_string = 21;

struct Students {
	char name[max_string];
	char surname[max_string];
	char patronymic[max_string];
	bool sex;
	int group_number;
	int list_number;
	int grades[8];
	float average_grade = 0;
};


Students students[students_possible_number];


void _1_new_list() {
	
	cout << "Entering the information about a new one..." << endl << endl;

	cin.ignore();
	cout << "Name (up to 20 characters): ";
	cin.getline(students[students_current_number].name, max_string);

	cout << "Surname (up to 20 characters): ";
	cin.getline(students[students_current_number].surname, max_string);

	cout << "Patronymic (up to 20 characters): ";
	cin.getline(students[students_current_number].patronymic, max_string);

	cout << "Sex (1 - male, 0 - female): ";
	cin >> students[students_current_number].sex;

	cout << "Group number: ";
	cin >> students[students_current_number].group_number;

	cout << "List number: ";
	cin >> students[students_current_number].list_number;

	cout << "Grades (press 'Space' after each grade, 8 grades total): ";

	cin >> students[students_current_number].grades[0]
		>> students[students_current_number].grades[1]
		>> students[students_current_number].grades[2]
		>> students[students_current_number].grades[3]
		>> students[students_current_number].grades[4]
		>> students[students_current_number].grades[5]
		>> students[students_current_number].grades[6]
		>> students[students_current_number].grades[7];

	students_current_number++;
}

int _2_change_list() {
	int st_num, st_change, st_grade_change(0);
	cout << "What number of student will be changed? ";
	cin >> st_num;
	if (st_num > students_current_number) {
		cout << "Error: this student does not exist";
		return 0;
	}
	st_num--;
	cout << '\n' << "What will be changed? \n"
		"1 - name, \n"
		"2 - surname, \n"
		"3 - patronymic, \n"
		"4 - sex, \n"
		"5 - group number, \n"
		"6 - list number, \n"
		"7 - grades, \n"
		"0 - nothing." << endl;
	cin >> st_change;
	if (st_change == 7) {
		cout << "Enter a number of grade: ";
		cin >> st_grade_change;
	}
	cout << "\n" "Enter a new value: ";
	switch (st_change) {

	case 1:
		cin >> students[st_num].name;
		break;
	case 2:
		cin >> students[st_num].surname;
		break;
	case 3:
		cin >> students[st_num].patronymic;
		break;
	case 4:
		cin >> students[st_num].sex;
		break;
	case 5:
		cin >> students[st_num].group_number;
		break;
	case 6:
		cin >> students[st_num].list_number;
		break;
	case 7:
		cin >> students[st_num].grades[st_grade_change - 1];
		break;
	case 0:
		return 0;
	default:
		cout << "Error: wrong number" << endl;
		return 0;
	}
}

void student_inf(int i) {
	cout << "Student " << i + 1 << ":" << endl;

	cout << "\tName: " << students[i].name << endl;

	cout << "\tSurname: " << students[i].surname << endl;

	cout << "\tPatronymic: " << students[i].patronymic << endl;

	cout << "\tSex: ";
	if (students[i].sex) cout << "male" << endl;
	else cout << "female" << endl;

	cout << "\tGroup number: " << students[i].group_number << endl;

	cout << "\tList number: " << students[i].list_number << endl;

	cout << "\tGrades: ";
	for (int g = 0; g < 8; g++) cout << students[i].grades[g] << ' ';
	cout << endl << endl;
}


int _3_all_data() {
	for (int i = 0; i < students_current_number; i++) {

		student_inf(i);

	}
	return 0;
}

int _4_group_data() {

	int group;
	cout << "Enter a group number: ";
	cin >> group;
	for (int i = 0; i < students_current_number; i++) {
		if (students[i].group_number == group) {
			student_inf(i);
		}
	}

	return 0;
}

void insert_sort(float* p, int n) {
	float* Pos = p;
	for (int i = 1; i <= n; i++) {
		p = Pos;
		while (*p < *(p - 1)) {
			if (*p < *(p - 1)) {
				swap(*p, *(p - 1));
				p--;
			}
		}
		Pos++;
	}
}

int _5_best_students() {

	int len = 8;
	for (int i = 0; i < students_current_number; i++) {
		for (int students_current_grade = 0; students_current_grade < len; students_current_grade++) {
			students[i].average_grade += students[i].grades[students_current_grade];
		}
		students[i].average_grade /= len;
	}

	float arr[students_possible_number];
	for (int i = 0; i < students_current_number; i++) {
		arr[i] = students[i].average_grade;
	}

	insert_sort(arr, students_current_number);

	for (int i = students_current_number - 1; i >= 0; i--) {
		cout << "Average grade: " << (arr[i]) << "\nStudents : \n";
		for (int j = 0; j < students_current_number; j++) {
			if (students[j].average_grade == arr[i]) {
				cout << students[j].name << ' ' << students[j].surname << endl;
			}
		}
	}
	return 0;
}

int _6_male_and_female() {

	int s_male = 0, s_female = 0;

	for (int i = 0; i < students_current_number; i++) {
		if (students[i].sex) { s_male++; }
		else { s_female++; }
	}

	cout << "Male students: " << s_male << endl;
	cout << "Female students: " << s_female << endl;

	return 0;
}

int _7_statistics() {


	int only_5(0);
	bool s23[students_possible_number], s45[students_possible_number], s5[students_possible_number];
	bool is_3 = false;

	for (int i = 0; i < students_possible_number; i++) {
		s23[i] = s45[i] = s5[i] = false;
	}

	for (int i = 0; i < students_current_number; i++) {
		only_5 = 0;
		for (int grade = 0; grade < 8; grade++) {
			if ((students[i].grades[grade] == 2) || (students[i].grades[grade] == 3)) {
				s23[i] = true;
				is_3 = true;
				break;
			}
			if (students[i].grades[grade] == 5) { only_5++; }
		}
		if (is_3) break;
		if (only_5 == 8) { s5[i] = true; }
		else { s45[i] = true; }
	}

	cout << "Only 5 marks:" << endl;
	for (int i = 0; i < students_current_number; i++) {
		if (s5[i]) student_inf(i);
	}
	cout << "Marks like 4 and 5:" << endl;
	for (int i = 0; i < students_current_number; i++) {
		if (s45[i]) student_inf(i);
	}
	cout << "Without scholarship:" << endl;
	int gg = 0;
	for (int i = 0; i < students_current_number; i++) {
		if (s23[i]) {
			student_inf(i);
			gg++;
		}
		if (!gg) cout << "None";

		return 0;
	}
}

int _8_listnumber() {

	int s_list_number;
	cout << "Enter a list number: ";
	cin >> s_list_number;
	for (int i = 0; i < students_current_number; i++) {
		if (students[i].list_number == s_list_number) {
			cout << "Student " << i + 1 << ":" << endl;
			cout << "\tName: " << students[i].name << endl;
			cout << "\tSurname: " << students[i].surname << endl;
			cout << "\tPatronymic: " << students[i].patronymic << endl;
			cout << "\tSex: ";
			if (students[i].sex) cout << "male" << endl;
			else cout << "female" << endl;
			cout << "\tGroup number: " << students[i].group_number << endl;
			cout << "\tList number: " << students[i].list_number << endl;
			cout << "\tGrades: ";
			for (int g = 0; g < 8; g++) cout << students[i].grades[g] << ' ';
			cout << endl << endl;
		}
	}
	return 0;
}



int main() {


	int task;
	do {
		cout << "Commands:" << '\n'
			<< "1 - create a new student," << '\n'
			<< "2 - correct student's data," << '\n'
			<< "3 - print all data," << '\n'
			<< "4 - print all data of students of current group," << '\n'
			<< "5 - print last week's best students," << '\n'
			<< "6 - print a number of male and female students," << '\n'
			<< "7 - print cool and not cool students," << '\n'
			<< "8 - print all data of students with current list number," << '\n'
			<< "0 - exit." << "\n"
			<< "Your choice: ";

		cin >> task;
		switch (task) {

		case 1:
			_1_new_list();
			break;
		case 2:
			_2_change_list();
			break;
		case 3:
			_3_all_data();
			break;
		case 4:
			_4_group_data();
			break;
		case 5:
			_5_best_students();

			break;
		case 6:
			_6_male_and_female();
			break;
		case 7:
			_7_statistics();
			break;
		case 8:
			_8_listnumber();
			break;
		case 0:
			break;
		default:
			cout << "Error: wrong task" << endl;
			break;
		}
	} while (task);

	return 0;
}