#include <iostream>
#include <string> // Using the string header file to enable us use the string function 
#include <cstdlib>
#include <ctime>
//Using MYSQL to create the database
#include <mysql_connection.h>    
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;
using namespace sql;













class Vehicle {
	
	protected:
    	string registration_number;
	public:
    	string get_registration_number() { return registration_number; }
    
    void renewReg(string expiry_date_str){
    	expiry_date_str = expiry_date_str;
    	cout << "Registration renewed. New expiry date: " << expiry_date << endl;
	}
	
	void display_menu() {    // Menu display for the type of car
    	cout<< "1.Type Cruiser"<< endl;
    	cout<< "2.Type Sedan, Minibuses, and Cross-country Vehicles"<< endl;
    	cout<< "3.Type Transport,and Medium Product Vehicles"<< endl;
    	cout<< "4.Type Transport, Mentors, and Hefty Product Vehicles"<< endl;
		cout<< "5.Type Heavy Type Machinery"<< endl;
    	cout<< "6.Type Trailers and Trucks"<< endl;
}
	
    virtual void generate_number_plate() = 0;  // using a virtual function since it is implemented differently with different parameters
};

class TypeA : public Vehicle {  // first sub-class that uses an array of letters and random numbers to generate it's unique number plate 
	private:
    	static const char letters[];
	public:
    	void generate_number_plate() override {
        	char first_letter = letters[rand() % 3];
        	char second_letter = letters[rand() % 3];
        	int number = rand() % 10000;
        	registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeA::letters[] = {'A', 'B', 'C'}; //  Using an array with specific members to help generate the license plate

class TypeB : public Vehicle {
	private:
    	static const char letters[];
	public:
    	void generate_number_plate() override {
        	char first_letter = letters[rand() % 3];     //Randomly selecting a member of the array for the license plate
        	char second_letter = letters[rand() % 3];
        	int number = rand() % 10000;      // Randomy selecting a number to add to the number plate
        	registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number); //Presentation and storing of license plate
    }
};
const char TypeB::letters[] = {'D', 'E', 'F'};

class TypeC : public Vehicle {
	private:
    	static const char letters[];
	public:
    	void generate_number_plate() override {
        	char first_letter = letters[rand() % 3];
        	char second_letter = letters[rand() % 3];
        	int number = rand() % 10000;
        	registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeC::letters[] = {'G', 'H', 'I'};

class TypeD : public Vehicle {
	private:
    	static const char letters[];
	public:
    	void generate_number_plate() override {
        	char first_letter = letters[rand() % 3];
        	char second_letter = letters[rand() % 3];
        	int number = rand() % 10000;
        	registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeD::letters[] = {'J', 'K', 'L'};

class TypeE : public Vehicle {
	private:
    	static const char letters[];
	public:
    	void generate_number_plate() override {
        	char first_letter = letters[rand() % 3];
        	char second_letter = letters[rand() % 3];
        	int number = rand() % 10000;
        	registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeE::letters[] = {'M', 'N', 'O'};

class TypeF : public Vehicle {
	private:
    	static const char letters[];
	public:
    	void generate_number_plate() override {
        	char first_letter = letters[rand() % 3];
        	char second_letter = letters[rand() % 3];
        	int number = rand() % 10000;
        	registration_number = string(1, first_letter) + string(1, second_letter) + to_string(number);
    }
};
const char TypeF::letters[] = {'P', 'Q', 'R'};

void display_info(ResultSet* res) {  // MYSQL database that stores and displays the information of the users input
    while (res->next()) {
        cout << "Name: " << res->getString("name") << endl;
        cout << "Age: " << res->getInt("age") << endl;
        cout << "Gender: " << res->getString("gender") << endl;
        cout << "Phone Number 1: " << res->getString("phone_number_1") << endl;
        cout << "Phone Number 2: " << res->getString("phone_number_2") << endl;
        cout << "ID Number: " << res->getString("id_number") << endl;
        cout << "Driver's License Number: " << res->getString("drivers_license_number") << endl;
        cout << "Email: " << res->getString("email") << endl;
        cout << "Make: " << res->getString("make") << endl;
        cout << "Model: " << res->getString("model") << endl;
        cout << "Year: " << res->getInt("year") << endl;
        cout << "License Plate: " << res->getString("license_plate") << endl << endl;
    }
}






class Driver{
	private:
		string license_number;
		string date_issued;
		string date_expiry;
		string license_type;
		
	public:
		void display_menu() {    // Menu display for the type of car
    cout<< "1.Type Cruiser"<< endl;
    cout<< "2.Type Sedan, Minibuses, and Cross-country Vehicles"<< endl;
    cout<< "3.Type Transport,and Medium Product Vehicles"<< endl;
    cout<< "4.Type Transport, Mentors, and Hefty Product Vehicles"<< endl;
    cout<< "5.Type Heavy Type Machinery"<< endl;
    cout<< "6.Type Trailers and Trucks"<< endl;
}
	
		void d_license(){
			try {
            // Prompt user for information
            string name, gender, phone_number_1, phone_number_2, id_number, drivers_license_number, email, license_number;
            int age, type;

            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter your age: ";
            cin >> age;
            cout << "Enter your gender(M/F): ";
            cin.ignore();
            getline(cin, gender);
            cout << "Enter your phone number 1: ";
            cin.ignore();
            getline(cin, phone_number_1);
            cout << "Enter your phone number 2 (if any): ";
            cin.ignore();
            getline(cin, phone_number_2);
            cout << "Enter your ID number: ";
            cin.ignore();
            getline(cin, id_number);
            cout << "Enter your email: ";
            cin.ignore();
            getline(cin, email);
            display_menu();
            cout << "Enter the vehicle type: ";
            cin >> type;
            // Generate License number, date issued and expiry date
            drivers_license_number = generate_license_number();
            date_issued = generate_date();
            date_expiry = generate_expiry_date();

            // Insert values into MySQL table
            sql::Driver *driver = get_driver_instance();
            unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "username", "password")); // Replace with your MySQL username and password
            con->setSchema("mydatabase"); // Replace with your database name
            unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("INSERT INTO mytable (name, age, gender, phone_number_1, phone_number_2, id_number, email, license_number, date_issued, date_expiry, vehicle_type) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));
            pstmt->setString(1, name);
            pstmt->setInt(2, age);
            pstmt->setString(3, gender);
            pstmt->setString(4, phone_number_1);
            pstmt->setString(5, phone_number_2);
            pstmt->setString(6, id_number);
            pstmt->setString(7, email);
            pstmt->setString(8, drivers_license_number);
            pstmt->setString(9, date_issued);
            pstmt->setString(10, date_expiry);
            pstmt->setInt(11, type);
            pstmt->executeUpdate();

            cout << "Driver's license successfully added to the database." << endl;
        } catch (const sql::SQLException &e) {
            cout << "Error: " << e.what() << endl;
        }
        
	}
	// Generate License number, date issued and expiry date
	string generate_license_number() {
		string license_num = "";
        for (int i = 0; i < 7; i++) {
            int random_num = rand() % 10;
            license_num += to_string(random_num);
        }
        return license_num;
    }

    string generate_date() {
        time_t now = time(0);
        tm *date = localtime(&now);
        string date_str = to_string(date->tm_mday) + "/" + to_string(1 + date->tm_mon) + "/" + to_string(1900 + date->tm_year);
        return date_str;
    
	}
	
	string generate_expiry_date() {
        time_t now = time(0);
        tm *date = localtime(&now);
        date->tm_year += 7; // License is valid for 7 years
        mktime(date);
        string expiry_date_str = to_string(date->tm_mday) + "/" + to_string(1 + date->tm_mon) + "/" + to_string(1900 + date->tm_year);
        return expiry_date_str;
    }
    
    void renewLic( string expiry_date_str){
		expiry_date = expiry_date_str;
        cout << "Registration renewed. New expiry date: " << expiry_date << endl;

	}
	
	void display_information() {
        try {
            // Retrieve data from MySQL table
            sql::Driver *driver = get_driver_instance();
            unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "username", "password")); // Replace with your MySQL username and password
            con->setSchema("mydatabase"); // Replace with your database name
            unique_ptr<sql::Statement> stmt(con->createStatement());
            unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM mytable")); // Replace with your table name

            // Loop through the result set and display information
            while (res->next()) {
                cout << "Name: " << res->getString("name") << endl;
                cout << "Age: " << res->getInt("age") << endl;
                cout << "Gender: " << res->getString("gender") << endl;
                cout << "Phone Number 1: " << res->getString("phone_number_1") << endl;
                cout << "Phone Number 2: " << res->getString("phone_number_2") << endl;
                cout << "ID Number: " << res->getString("id_number") << endl;
                cout << "Email: " << res->getString("email") << endl;
                cout << "License Number: " << res->getString("license_number") << endl;
                cout << "Date Issued: " << res->getString("date_issued") << endl;
                cout << "Date Expiry: " << res->getString("date_expiry") << endl;
                cout << "Vehicle Type: " << res->getInt("vehicle_type") << endl;
            }
        } catch (const sql::SQLException &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
};












void V_license(){
	 try {
        // Prompt user for information
                string name, gender, phone_number_1, phone_number_2, id_number, drivers_license_number, email, model,make;
        int age, year,decide;
        vehicle cars;
        
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age<< endl;
        cout << "Enter your gender: ";
        cin >> gender<<endl;
        cout << "Enter your phone number 1: ";
        cin >> phone_number_1<<endl;
        cout << "Enter your phone number 2 (if any): ";
        cin >> phone_number_2<<endl;
        cout << "Enter your ID number: ";
        cin >> id_number<<endl;
        cout << "Enter your Driver's License number: ";
        cin >> drivers_license_number<<endl;
        cout << "Enter your email: ";
        cin >> email<<endl;
        cout << "Enter the model of your vehicle: ";
        cin >> model<<endl;
        cout << "Enter the make of your vehicle: ";
        cin >> make<<endl;
        cout << "Enter the year of your vehicle: ";
        cin >> year<<endl;
        cout << "Enter the type of your vehicle by selecting it's corresponding number: ";
        
        cars.display_menu();
        cin >> decide<<endl;// making a decision on the car  using an integer type to generate the unique number plate
        switch(decide){
        	case 1:
        		vehicle_ptr = new TypeA();
        		break;
        	case 2:
        		vehicle_ptr = new TypeB();
        		break;
        	case 3:
        		vehicle_ptr = new TypeC();
        		break;
        	case 4:
        		vehicle_ptr = new TypeD();
        		break;
        	case 5:
        		vehicle_ptr = new TypeE();
        		break;
        	case 6:
        		vehicle_ptr = new TypeF();
        		break;
        	default:
        		cerr<<"Invalid decision"<< endl;
        		return 1;


		}
        
        
        display info(); // Function call to use the MYSQL database
    }
        
}




int main() {
	Driver a;
	Vehicle b;
	int opt;
	cout <<"Welcome to DVLA"<< endl;
	cout <<"Please enter your Option"<< endl;
	cout <<"1. Register Your Vehicle"<< endl;
	cout <<"2.Regiter for a drivers license"<< endl;
	cout <<"3.Renew your Vehicle registration"<< endl;
	cout <<"4.Renew your drivers license"<< endl;
	cin >> opt;
	
	switch(opt){
        	case 1:
        	 	V_license() ;
        		break;
        	case 2:
        		a.d_license();
        		break;
        	case 3:
        		b.renewReg();
        		break;
        	case 4:
        		a.renewLic();
        		break;
        	default:
        		cerr<<"Invalid decision"<< endl;
        		return 1;
	
    
        
        return 0;
    }
    
    
 
