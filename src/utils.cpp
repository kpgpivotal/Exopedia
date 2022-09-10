#include "utils.hpp"

void message(string message){
    cout <<  message << endl;
}

void error_message(string message){
    cout <<  "\n>>>>\t" << message << endl;
}

void print_line() {
    cout << "-----------------------------------------" << endl;
}


int get_input_int(string prompt){
    string input{};
    int int_val{-1};
  
    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    try{ 
        int_val = stoi(input);
    }
    catch (...){}

    return int_val;
}

long get_input_long(string prompt){
    string input{};
    long long_val{-1};
  
    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    try{ 
        long_val = stol(input);
    }
    catch (...){}

    return long_val;
}


string capitalize_first_letter(string text) {

	for (string::size_type x = 0; x < text.length(); x++)
	{
		if (x == 0)
		{
			text[x] = toupper(text[x]);
		}
		else if (text[x - 1] == ' ')
		{
			text[x] = toupper(text[x]);
		}
	}

	return text;
}


string get_input_string(string prompt){
    string input{};

    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    
    return input;
}

string get_input_email(string prompt){
    string email{};
    int retry{0};

    while (retry++ < INPUT_RETRY_COUNT) {
        cout <<  prompt << " : " ;
        std::getline(std::cin, email);
        if ( is_valid_email(email) ) {
            break;
        }
        
        message("Invalid email. Please try again.");
    }

    if (INPUT_RETRY_COUNT == retry  ) {
        message("You have reached the limit of number of retires.");
        return "";
    }
        
    return email;
}

bool is_valid_email(string email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {
  
        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    string::size_type at = -1, dot = -1;
  
    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (string::size_type i = 0;
         i < email.length(); i++) {
  
        // If the character is '@'
        if (email[i] == '@') {
  
            at = i;
        }
  
        // If character is '.'
        else if (email[i] == '.') {
  
            dot = i;
        }
    }
  
    // If At or Dot is not present
    if (at == -1 || dot == -1)
        return 0;
  
    // If Dot is present before At
    if (at > dot)
        return 0;
  
    // If Dot is present at the end
    return !(dot >= (email.length() - 1));
}


// Function to check the character
// is an alphabet or not
bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}
  
// Function to check the character
// is an digit or not
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}


bool  get_y_n_confirmation(string prompt) {
    string input_str;
    char input;
 
    input_str = get_input_string(prompt); 
    if (0 == input_str.size()){
        return false;
    }

    input = input_str.at(0);
    if ( isalpha(input) == 0 ) {
        return false;;
    }

    input = toupper(input);
    if ( input ==  toupper('Y')) {
        return true;
    }

    return false;
}
    
void debug(string debug_message) {
    if (  DEBUG_MODE) {
        message("\n>>>>>\t" + debug_message);
    }
    
}


int read_num_range(int low, int high, bool cancel_choice_allowed ) {	
    int value{};

	if (!cancel_choice_allowed)
		cout << "\nEnter number in range " << low << " - " << high << ": ";
	else
		cout << "\nEnter -1 to cancel or number in range " << low << " - " << high << ": ";

	value = get_input_int("");

	if (cancel_choice_allowed && value == -1)
		return value;

	if (low <= value && value <= high)
		return value;

	cout << "ERROR: invalid number...Try again\n";
	return read_num_range(low, high);
}

int show_read_menu_choice(const vector<string> &choices, string header ) {	
	int choice{};

    cout << "\n\t" << header << endl;
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << endl;
	}
    choice = read_num_range(1, choices.size());
	return choice;
}

void clear_console() {
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}