#include <iostream>
#include <iomanip>  // for setfill and setwidth
#include <vector>
#include <string>
using namespace std;

// defines class student
class student {
public:
    int ID;
    string name;
    long int telephone;
    
    // default constructor
    student(){
        ID = 0;
        telephone = 0;
    }
    
    // constructor with parameters
    student(int ID, string name, long int telephone){
        this -> ID = ID;
        this -> name = name;
        this -> telephone = telephone;
    }
};


// prototypes
void insert(student s, vector <student> &v1);
void delete_contact(int id, vector <student> &v1);
void print(const vector <student> v1);
void edit_contactID(int old_id, int new_id, vector <student> &v1);
void edit_contactNAME(string old_name, string new_name, vector <student> &v1);
void edit_contactPHONE(long int old_phone, long int new_phone, vector <student> &v1);
void search(int id, vector<student> &v1);
void main_screen(vector<student> &v1);

int main() {
    vector <student> v1;
    int exit_mainmenu;
    
    do {
    main_screen(v1);
    
    cout << "If you would like to exit click -1. To continue click 1."<< endl;
    cin >> exit_mainmenu;
    
    }while (exit_mainmenu != -1);
    
    cout << endl;
    
    return 0;
}

// add student to vector
void insert(student s, vector <student> &v1){
    v1.push_back(s);
}

// deletes student
void delete_contact(int id, vector <student> &v1){
    for (int i = 0; i < v1.size(); i++){
        if (v1[i].ID == id){
            v1.erase(v1.begin()+i);
        }
    }
}

// print directory
void print(const vector <student> v1){
    cout << "ID \t\t Name \t\t Telephone" << endl;
    
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i].ID << "\t\t" << v1[i].name << "\t\t" << v1[i].telephone << endl;
    }
    
    if (v1.size() == 0){
        cout << "Vector is empty" << endl;
    }
}

void edit_contactID(int old_id, int new_id, vector <student> &v1){
    for (int i = 0; i < v1.size(); i++){
        if (v1[i].ID == old_id){
            v1[i].ID = new_id;
        }
    }
}

void edit_contactNAME(string old_name, string new_name, vector <student> &v1){
    for (int i = 0; i < v1.size(); i++){
        if (v1[i].name == old_name){
            v1[i].name = new_name;
        }
    }
}

void edit_contactPHONE(long int old_phone, long int new_phone, vector <student> &v1){
    for (int i = 0; i < v1.size(); i++){
        if (v1[i].telephone == old_phone){
            v1[i].telephone = new_phone;
        }
    }
}

// searches if student ID exists
void search(int id, vector<student> &v1){
    bool x = true;
    if (v1.size() == 0) cout << "Vector is empty" << endl;
    
    for (int i = 0; i < v1.size(); i++){
        if (v1[i].ID == id){
            x = false;
            cout << "Student ID: " << id << " is in the database." << endl;
            cout << v1[i].ID << "\t\t" << v1[i].name << "\t\t" << v1[i].telephone << endl;
        }
    }
    if (x == true){
        cout << "Student does not exist" << endl;
    }
}

// main menu
void main_screen(vector<student> &v1){
    cout << "Welcome to the Student Database" << endl << setfill('-') << setw(35) << '-' << endl;
    
    char user_input;
    int ID;
    string name;
    long int telephone;
    
    cout << "1. To Add student click 'A'" << endl << "2. To Delete Student click 'B'" << endl << "3. To Print student directory click 'C'" << endl << "4. To edit a student contact click 'D'" << endl << "5. To Search for a student by ID click 'E'" << endl;
    
    cout << setfill('-') << setw(35) << '-' << endl;
    
    cout << "Input: ";
    cin >> user_input;
    
    // insert a student
    if (user_input == 'A' || user_input == 'a'){
        
        cout << "ID: ";
        cin >> ID;
        cin.ignore();
        
        cout << "Name: ";
        getline(cin,name);
        cout << endl;
        
        cout << "Telephone: ";
        cin >> telephone;
        
        student s(ID, name, telephone);
        
        insert(s, v1);
    }
    
    // delete student
    else if (user_input == 'B' || user_input == 'b'){
        cout << "Enter the ID of the student you would like to remove from the directory: ";
        cin >> ID;
        
        delete_contact(ID, v1);
    }
    
    // print directory
    else if (user_input == 'C' || user_input == 'c'){
        print(v1);
    }
    
    //to edit either ID, name, or phone number
    else if (user_input == 'D' || user_input == 'D'){
        string user_input2;
        int old_id;
        int new_id;
        
        string old_name;
        string new_name;
        
        int old_telephone;
        int new_telephone;
        
        cout << "What would you like to edit, ID, Name, or Telephone? " << endl;
        cin >> user_input2;
        
        if (user_input2 == "ID" || user_input2 == "id"){
            cout << "Enter old ID and New ID" << endl;
            cout << "Old ID: ";
            cin >> old_id;
            
            cout << "New ID: ";
            cin >> new_id;
            
            edit_contactID(old_id, new_id, v1);
            
            cout << "Student ID updated" << endl;
        }
        else if (user_input2 == "Name" || user_input2 == "name"){
            cout << "Enter old and new Name" << endl;
            cin.ignore();
            cout << "Old name: ";
            getline(cin, old_name);
            
            cout << "New name:";
            getline(cin, new_name);
            
            edit_contactNAME(old_name, new_name, v1);
            
            cout << "Student name is updated" << endl;
        }
        else if (user_input2 == "Telephone" || user_input2 == "telehone" || user_input2 == "phone number" || user_input2 == "Phone number" || user_input2 == "Phone Number"){
            
            cout << "Enter old Telephone and New Telephone" << endl;
            cout << "Old Telephone: ";
            cin >> old_telephone;
            
            cout << "New Telephone: ";
            cin >> new_telephone;
            
            edit_contactPHONE(old_telephone, new_telephone, v1);
            
            cout << "Student telephone is updated" << endl;
        }
        else {
            cout << "Error! Please enter ID, Name, or Telephone" << endl;
        }
        
    }
    else if (user_input == 'E' || user_input == 'e'){
        cout << "Enter student ID: ";
        cin >> ID;
        
        search(ID,v1);
    }
    else {
        cout << "Input doesn't match. Please type 'A', 'B','C', 'D', or 'E'" << endl;
        main_screen(v1);
    }
    
}
