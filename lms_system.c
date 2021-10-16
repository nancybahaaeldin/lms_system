#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


class studentCourse
{
private:
	string name;
	int mark;
	string grade;
	float normalizationNumber;
	float GPA;

public:
	void setName(string name)
	{
		this->name = name;
		return;

	}
	void setMark(int mark)
	{
		this->mark = mark;
		return;
	}
	void setNormalizationNumber(float SD, float mean)
	{
		normalizationNumber = (mark - mean) / SD;
		return;
	}
	void calculateGrade()
	{

			if (mark >= 90)
			{
				grade = "A";
				return;
			}
			else if (mark < 90 && mark >= 85)
			{
				grade = "B+";
				return;
			}
			else if (mark < 85 && mark >= 80)
			{
				grade = "B";
				return;
			}
			else if (mark < 80 && mark >= 75)
			{
				grade = "C+";
				return;
			}
			else if (mark < 75 && mark >= 70)
			{

				grade = "C";
				return;
			}
			else if (mark < 70 && mark >= 65)
			{

				grade = "D+";
				return;
			}
			else if (mark < 65 && mark >= 60)
			{
				grade = "D";
				return;
			}
			else
			{

				grade = "F";
				return;
			}


		
	}
	

	void setGPA(float GPA)
	{
		this->GPA = GPA;
	}

	float getGPA()
	{
		return GPA;
	}
	string getName()
	{
		return name;
	}
	int getMark()
	{
		return mark;
	}
	string getGrade()
	{
		return grade;
	}
	float getNormalizationNumber()
	{
		return normalizationNumber;
	}
};


class student
{
private:
	string name;
	string id;
	int age;
	string gender;
	float GPA;
public:
	studentCourse courses[5];

public:

	void setGPA(float GPA)
	{
		this->GPA = GPA;
	}

	float getGPA()
	{
		return GPA;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setID(string id)
	{
		this->id = id;
	}
	void setAge(int age)
	{
		this->age = age;
	}void setGender(string gender)
	{
		this->gender = gender;
	}


	string getName()
	{
		return name;
	}
	string getID()
	{
		return id;
	}
	int getAge()
	{
		return age;
	}
	string getGender()
	{
		return gender;
	}


	void insertGrades(string header[])
	{
		int courseMark;
		int flag;
		cout << endl;
		cout << "Inserting courses of this students and his/her marks in each course" << endl;
		for (int i = 1; i < 6; i++)
		{
			flag = true;
			courses[i - 1].setName(header[i]);
			cout << "insert student mark in " << "'" << header[i] << "'" << " course" << endl;
			cout << endl;
			while (flag)
			{
				cin >> courseMark;
				if (courseMark <= 100 && courseMark >= 0)
				{
					flag = false;
				}
				else
				{
					cout << endl;
					cout << "The entered mark is out of range" << endl;
					cout << "The range is between 0 to 100" << endl;
					cout << "Enter the mark again" << endl;
				}
			}
			courses[i - 1].setMark(courseMark);

		}
		cout << "courses and his/her marks inserted successfully" << endl;
		cout << endl;
		return;
	}
	void setAllCoursesName(string arr[])
	{
		for (int i = 0; i < 5; i++)
		{
			courses[i].setName(arr[i]);
		}
		return;
	}
	void calculateCourseGrade()
	{
		for (int i = 0; i < 5; i++)
		{
			courses[i].calculateGrade();
		}

	}
	void getDetails(void)
	{
		cout << "Student data :" << endl<<endl;
		cout << "Name: " << name << endl;
		cout << "ID: " << id << endl;
		cout << "Age: " << age << endl;
		cout<< "Gender: " << gender << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << courses[i].getName() << "  " << courses[i].getGrade() << endl;
		}
	}


};

class CourseStatistics
{
private:

	string courseName;
	int A_numbers = 0;
	int Bplus_numbers = 0;
	int B_numbers = 0;
	int Cplus_numbers = 0;
	int C_numbers = 0;
	int Dplus_numbers = 0;
	int D_numbers = 0;
	int F_numbers = 0;

public:
	void setCourseName(string name)
	{
		courseName = name;
	}

	void incrementA_numbers()
	{
		A_numbers++;
	}
	void incrementBplus_numbers()
	{
		Bplus_numbers++;
	}
	void incrementB_numbers()
	{
		B_numbers++;
	}
	void incrementCplus_numbers()
	{
		Cplus_numbers++;

	}
	void incrementC_numbers()
	{
		C_numbers++;

	}
	void incrementDplus_numbers()
	{
		Dplus_numbers++;

	}
	void incrementD_numbers()
	{
		D_numbers++;

	}
	void incrementF_numbers()
	{
		F_numbers++;

	}
	string getCourseName()
	{
		return courseName;
	}
	int getA_numbers()
	{
		return A_numbers;
	}
	int getBplus_numbers()
	{
		return Bplus_numbers;
	}
	int getB_numbers()
	{
		return B_numbers;
	}
	int getCplus_numbers()
	{
		return Cplus_numbers;
	}
	int getC_numbers()
	{
		return C_numbers;
	}
	int getDplus_numbers()
	{
		return Dplus_numbers;
	}
	int getD_numbers()
	{
		return D_numbers;
	}
	int getF_numbers()
	{
		return F_numbers;
	}

	void displayStatistics(int currentStudentNumber)
	{
		cout << courseName << endl << endl;
		cout << "A     " << ((float)A_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << "B+     " << ((float)Bplus_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << "B     " << ((float)B_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << "C+     " << ((float)Cplus_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << "C     " << ((float)C_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << "D+     " << ((float)Dplus_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << "D     " << ((float)D_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << "F     " << ((float)F_numbers / (float)currentStudentNumber) * 100 << " %" << endl;
		cout << endl << endl << endl;;
	}
};

class System
{
private:
	int currentStudentsNumber = 0;
	int CourseStatisticsNumber = 0;
	float SD[5];
	float theMean[5];
public:
	student students[100];
	CourseStatistics courses[5];
	float grade;


	void getFileDetailsForStudent(ifstream& fileData)
	{
		string ID;
		string name;
		string ageString;
		int age;
		string gender;

		getline(fileData, ID, ',');
		getline(fileData, name, ',');
		getline(fileData, ageString, ',');
		getline(fileData, gender, '\n');

		if (ageString.size() != 0)
		{
			age = stoi(ageString);
		}
		students[currentStudentsNumber].setID(ID);
		students[currentStudentsNumber].setName(name);
		if (ageString.size() != 0)
		{
			students[currentStudentsNumber].setAge(age);
		}
		students[currentStudentsNumber].setGender(gender);

		if (ageString.size() != 0)
		{
			currentStudentsNumber++;
		}

		return;
	}

	void displayStudentsData(string arr[])
	{

		cout << arr[0] << "\t\t" << arr[1] << "\t\t\t" << arr[2] << "\t\t" << arr[3] << endl;
		for (int i = 0; i < currentStudentsNumber; i++)
		{
			cout << students[i].getID() << "\t\t" << students[i].getName() << "\t\t" << students[i].getAge() << "\t\t" << students[i].getGender() << endl;
		}
		return;
	}


	void calculateGPA()
	{
		float totalPoints;
		for (int k = 0; k < currentStudentsNumber; k++)
		{
			totalPoints = 0;
			for (int i = 0; i < 5; i++)
			{
				grade = students[k].courses[i].getMark();

				if (grade < 100 && grade >= 93)
				{
					students[k].courses[i].setGPA(4.00);
				}
				else if (grade < 92 && grade >= 90)
				{
					students[k].courses[i].setGPA(3.7);
				}
				else if (grade < 89 && grade >= 87)
				{
					students[k].courses[i].setGPA(3.3);
				}
				else if (grade < 86 && grade >= 83)
				{
					students[k].courses[i].setGPA(3.0);
				}
				else if (grade < 82 && grade >= 80)
				{

					students[k].courses[i].setGPA(2.7);
				}
				else if (grade < 79 && grade >= 77)
				{

					students[k].courses[i].setGPA(2.3);
				}
				else if (grade < 76 && grade >= 73)
				{
					students[k].courses[i].setGPA(2.00);
				}
				else if (grade < 72 && grade >= 70)
				{
					students[k].courses[i].setGPA(1.7);
				}
				else if (grade < 69 && grade >= 67)
				{
					students[k].courses[i].setGPA(1.3);
				}
				else if (grade < 66 && grade >= 65)
				{
					students[k].courses[i].setGPA(1.00);
				}
				else
				{

					students[k].courses[i].setGPA(0.00);
				}

				totalPoints = totalPoints + (students[k].courses[i].getGPA() * 3);
			}

			students[k].setGPA(totalPoints / 15);
		}
	}


	void getFilegradesForStudent(ifstream& filegrade, string headers[])
	{
		string studentcode;
		string course_[5];

		getline(filegrade, studentcode, ',');
		getline(filegrade, course_[0], ',');
		getline(filegrade, course_[1], ',');
		getline(filegrade, course_[2], ',');
		getline(filegrade, course_[3], ',');
		getline(filegrade, course_[4], '\n');



		for (int i = 0; i < currentStudentsNumber; i++)  //students loop
		{
			if (students[i].getID() == studentcode)
			{
				for (int k = 1; k < 6; k++)  //headers loop
				{
					students[i].courses[k - 1].setName(headers[k]);
					students[i].courses[k - 1].setMark(stof(course_[k - 1]));
				}
			}
		}


		return;
	}


	void displayStudentsgrade(string arr1[])
	{

		cout << arr1[0] << "\t  " << arr1[1] << "\t    " << arr1[2] << "\t    " << arr1[3] << "\t    " << arr1[4]<<"\t    " << arr1[5] << endl;
		for (int i = 0; i < currentStudentsNumber; i++)
		{
			cout << students[i].getID() << "\t\t  ";
			for (int j = 0; j < 5; j++)
			{
				cout << students[i].courses[j].getMark() << "\t\t";
			}
			cout << endl;
		}
		return;
	}


	void calculateSD()
	{
		float sum, mean, standardDeviation;

		int i;

		for (int j = 0; j < 5; j++)
		{
			sum = 0;
			standardDeviation = 0;
			for (i = 0; i < currentStudentsNumber; ++i)
			{
				sum += students[i].courses[j].getMark();
			}

			mean = sum / (float)currentStudentsNumber;

			for (i = 0; i < currentStudentsNumber; ++i)
			{
				standardDeviation += pow(students[i].courses[j].getMark() - mean, 2);
			}

			SD[j] = sqrt(standardDeviation / (float)currentStudentsNumber);
			theMean[j] = mean;

		}
		return;

	}

	void calculateNormalizationNumber()
	{
		for (int i = 0; i < currentStudentsNumber; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				students[i].courses[j].setNormalizationNumber(SD[j], theMean[j]);
			}

		}

	}

	void getIDdetails(string id) /* get ID details */
	{

		for (int i = 0; i < currentStudentsNumber; i++)
		{
			if (students[i].getID() == id)
			{
				students[i].getDetails();

				return;
			}
		}

		cout << "No student existed with this ID" << endl;
	}
	void calculateAllStudentsGrades()
	{
		for (int i = 0; i < currentStudentsNumber; i++)
		{
			students[i].calculateCourseGrade();
		}
		return;
	}

	void insertDetails(void)
	{
		string name;
		string id;
		string gender;
		int age;


		cout << "Enter student name: " << endl;
		cin.ignore();
		getline(cin, name);
		students[currentStudentsNumber].setName(name);
		cout << "Enter student id: " << endl;
		cin >> id;
		students[currentStudentsNumber].setID(id);
		cout << "Enter student age: " << endl;
		cin >> age;
		students[currentStudentsNumber].setAge(age);
		cout << "Enter student gender:" << endl;
		cin >> gender;
		students[currentStudentsNumber].setGender(gender);

		currentStudentsNumber++;
		cout << endl;
		cout << "Details inserted successfully for this student" << endl;
		cout << endl;
	}

	void calculateCourseStatistics(string course)
	{
		courses[CourseStatisticsNumber].setCourseName(course); /* setting course statsticis name */

		int i = 0;
		int j = 0;

		for (j; j < currentStudentsNumber; j++)
		{
			for (i; i < 5; i++)
			{
				if (students[j].courses[i].getName() == course)
					break;
			}

			if (students[j].courses[i].getGrade() == "A")
			{
				courses[CourseStatisticsNumber].incrementA_numbers();
			}
			else if (students[j].courses[i].getGrade() == "B+")
			{
				courses[CourseStatisticsNumber].incrementBplus_numbers();
			}
			else if (students[j].courses[i].getGrade() == "B")
			{
				courses[CourseStatisticsNumber].incrementB_numbers();
			}
			else if (students[j].courses[i].getGrade() == "C+")
			{
				courses[CourseStatisticsNumber].incrementCplus_numbers();
			}
			else if (students[j].courses[i].getGrade() == "C")
			{
				courses[CourseStatisticsNumber].incrementC_numbers();
			}
			else if (students[j].courses[i].getGrade() == "D+")
			{
				courses[CourseStatisticsNumber].incrementDplus_numbers();
			}
			else if (students[j].courses[i].getGrade() == "D")
			{
				courses[CourseStatisticsNumber].incrementD_numbers();
			}
			else
			{
				courses[CourseStatisticsNumber].incrementF_numbers();
			}


		}

		if (CourseStatisticsNumber != 4)
		{
			CourseStatisticsNumber++;
		}
		else
		{
			CourseStatisticsNumber = 0;
		}


	}

	int getCurrentStudentsNumber()
	{
		return currentStudentsNumber;
	}

};








int main()
{
	System LMS;

	/*reading students details*/
	string headers[4];
	ifstream fileData("studentsData.csv");

	getline(fileData, headers[0], ',');
	getline(fileData, headers[1], ',');
	getline(fileData, headers[2], ',');
	getline(fileData, headers[3], '\n');
	headers[0] = headers[0].substr(3);


	while (fileData.good())
	{
		LMS.getFileDetailsForStudent(fileData);

	}
	fileData.close();
	/****************************/


	/*reading students grades*/
	string header[6];
	ifstream filegrade("studentsGrade.csv");

	getline(filegrade, header[0], ',');
	getline(filegrade, header[1], ',');
	getline(filegrade, header[2], ',');
	getline(filegrade, header[3], ',');
	getline(filegrade, header[4], ',');
	getline(filegrade, header[5], '\n');
	header[0] = header[0].substr(3);

	while (filegrade.good())
	{

		LMS.getFilegradesForStudent(filegrade, header);

	}
	filegrade.close();
	/****************************/


	/*calculate student grades*/
	for (int j = 0; j < LMS.getCurrentStudentsNumber(); j++) /*for each students*/
	{
		for (int k = 0; k < 5; k++)/*for each course*/
		{
			LMS.students[j].courses[k].calculateGrade(); /*calculate grades*/
		}
	}
	/***************************/



	int operationNumber;
	cout << "Welcome to LMS" << endl;
	cout << endl;
	bool flag = true;
	bool operate = true;
	while (operate)
	{
		cout << "Available operations :" << endl;
		cout << "1 - Insert new student to the system through the console" << endl;
		cout << "2 - Display students data from the file" << endl;
		cout << "3 - Display Students grades from the file" << endl;
		cout << "4 - Get details of a certain student using ID" << endl;
		cout << "5 - Update students grades, data and GPA to a csv file" << endl;
		cout << "6 - Display the normalized result for each student and export them to the file" << endl;
		cout << "7 - Display The statistics of each course" << endl;
		cout << endl;
		cout << "Choose the operation number you want to do:" << endl;
		cout << endl;
		cin >> operationNumber;
		cout << endl;
		switch (operationNumber) {
		case 1:
		{
			int StudentNumbers;
			cout << "Enter number of students to be inserted: ";
			cin >> StudentNumbers;
			cout << endl;

			for (int i = 0; i < StudentNumbers; i++)
			{
				cout << "insert the details of student " << i + 1 << " : " << endl;
				LMS.insertDetails();
				LMS.students[(LMS.getCurrentStudentsNumber()) - 1].insertGrades(header);
				for (int k = 0; k < 5; k++)
				{
					LMS.students[LMS.getCurrentStudentsNumber() - 1].courses[k].calculateGrade();
				}
				/***Export the  student to the file**/
			}

			cout << endl;
			cout << endl;
			break;
		}

		case 2:

			LMS.displayStudentsData(headers);
			cout << endl;
			cout << endl;
			break;

		case 3:
			LMS.displayStudentsgrade(header);
			cout << endl;
			cout << endl;
			break;

		case 4:
		{
			string code;
			cout << "enter the code to print the details" << endl;
			cin >> code;
			LMS.getIDdetails(code);
			cout << endl;
			cout << endl;
			break;
		}

		case 5:
		{

			/*calculate student GPA*/
			for (int j = 0; j < LMS.getCurrentStudentsNumber(); j++) /*for each students*/
			{
				LMS.calculateGPA();
			}
			/**********************/


			ofstream updatedFile;
			updatedFile.open("updatedData.csv");

			for (int i = 0; i < 4; i++)
			{
				updatedFile << headers[i] << ",";
			}
			for (int i = 1; i < 6; i++)
			{

				updatedFile << header[i] << ",";

			}

			updatedFile << "GPA" << "\n";


			for (int i = 0; i < LMS.getCurrentStudentsNumber(); i++)
			{
				updatedFile << LMS.students[i].getID() << ",";
				updatedFile << LMS.students[i].getName() << ",";
				updatedFile << LMS.students[i].getAge() << ",";
				updatedFile << LMS.students[i].getGender() << ",";

				for (int j = 0; j < 5; j++)
				{
					updatedFile << LMS.students[i].courses[j].getGrade() << ",";
				}

				updatedFile << LMS.students[i].getGPA() << "\n";

			}

			updatedFile.close();

			cout << "Your data has been updated and exported to 'updatedData.csv' successfully" << endl;
			cout << "This file has been created automatically, you can find it in the project folder" << endl;
			cout << endl;
			cout << endl;
			break;
		}
		case 6:
			LMS.calculateSD();
			LMS.calculateNormalizationNumber();
			for (int i = 0; i < LMS.getCurrentStudentsNumber(); i++)
			{
				cout << "Student Name: " << LMS.students[i].getName() << endl << endl;
				for (int j = 0; j < 5; j++)
				{
					cout << j + 1 << "-	Course Name: " << LMS.students[i].courses[j].getName() << "		Normalization Number:" << LMS.students[i].courses[j].getNormalizationNumber() << endl;

				}

				cout << endl;
				cout << endl;
			}
			break;

		case 7:

			for (int i = 1; i < 6; i++)
			{
				LMS.calculateCourseStatistics(header[i]);
				cout << "Here is the statistics of ";
				LMS.courses[i - 1].displayStatistics(LMS.getCurrentStudentsNumber());
			}

			cout << endl;
			cout << endl;

			break;


		default:
			cout << "Please enter number within range" << endl;
			cout << endl;
		}


		cout << "Need another operation?" << endl;
		cout << "Answer with 'yes' or 'no'" << endl;
		cout << endl;
		string answer;

		flag = true;
		while (flag)
		{
			cin >> answer;
			if (answer == "yes")
			{
				operate = true;
				flag = false;
				cout << endl;
			}
			else if (answer == "no")
			{
				operate = false;
				flag = false;
				cout << endl;
				cout << endl;
				cout << "Thank you for using the system" << endl;

			}
			else {
				cout << endl;
				cout << "Error answer please enter either 'yes' or 'no'" << endl;
				flag = true;
			}
		}

	}


	return 0;
}