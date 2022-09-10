#ifndef INCLUDE_UTILS_H
#define INCLUDE_UTILS_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <string_view>
#include <bits/stdc++.h>

using namespace std;
using namespace std::literals;

#define  DEBUG_MODE  true


const int INPUT_RETRY_COUNT = 10;
void print_line();
void message(string message);
void debug(string message);
void error_message(string message);
int get_input_int(string prompt);
void clear_console();
string capitalize_first_letter(string text);
bool is_valid_email(string email);
string get_input_email(string prompt);
string get_input_string(string prompt);
bool isChar(char c);
bool isDigit(const char c);
long get_input_long(string prompt);
bool  get_y_n_confirmation(string prompt="Are you sure ( Y/N )?");
int read_num_range(int low, int high, bool cancel_choice_allowed = true);
int show_read_menu_choice(const vector<string> &choices, string header = "Menu");



#endif

