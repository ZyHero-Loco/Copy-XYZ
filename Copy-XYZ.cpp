#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void file_copy(istream& in, ostream& out);

string input;

int main( void )
{
    ifstream from_file;
    ofstream to_file;
    string file_one_name, file_two_name;
    cout << "\t\tWelcome to the People Data Copying Program!!!" << endl;
    // get the data file name
    cout << "\nPlease enter the name of your data file: ";
    do {
        input.clear();
        getline(cin, input);
        file_one_name = input;
        from_file.open(file_one_name);
        if (!from_file) {
            from_file.close();
            from_file.clear();
            cout << "\nInvalid file name.\n\nPlease enter another name: ";
        } else {
            cout << "\nFile '" << file_one_name << "' opened successfully!" << endl;
        }
    } while (!from_file);
    // get the copy file name
    cout << "\nPlease enter the name of the copy file: ";
    do {
        input.clear();
        getline(cin, input);
        file_two_name = input;
        to_file.open(file_two_name);
        if (!to_file) {
            to_file.close();
            to_file.clear();
            cout << "\nInvalid file name.\n\nPlease enter another name: ";
        } else {
            cout << "\nFile '" << file_two_name << "' opened successfully!" << endl;
        }
    } while (!to_file);

    cout << "Copying data from '" << file_one_name << "' to '" << file_two_name << "'..." << endl;
    //function that copies data file to copy file.
    file_copy(from_file, to_file);
    cout << "Done copying data!" << endl;
    
    from_file.close();
    to_file.close();
    from_file.clear();
    to_file.clear();

    cout << "\nThank you for using the PCP!!\n\nEndeavor to have a tremendous day!" << endl;
	return 0;
}

void file_copy(istream& in, ostream& out) {
    in.peek();
    while (!in.eof())
    {
        input.clear();
        getline(in, input);
        out << input;
        input.clear();
        if (!in.eof()) {
            out << '\n';
        }
        in.peek();
    }
    return;
}