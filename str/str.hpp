#ifndef STR_H
#define STR_H

#include <string>

class string {
	private:
		char* str;
	public:
		char* getStr() const;
		int get_size() const;
		char* append(char* new_str);
		const string& swap(string& s);
		bool find_first_of(const string& s);
	public:
		string();
		string(char* new_str);
		string(const string& value);
		const string& operator=(const string& s);
		const string& operator+(const string& s);
		const string& operator+=(const string& s);
		char operator[](int i);
		bool operator<(const string& s);
		~string();
};

#endif
