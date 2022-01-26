#ifndef STR_H
#define STR_H

class string {
	private:
		char* str;
	public:
		char* getStr() const;
		int get_size() const;
		const string& append(const string& new_str);
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
