#ifndef GODOTHUB_IO_SINGLETON_H
#define GODOTHUB_IO_SINGLETON_H

#include <bits/stdc++.h>
#include "abstract_IO.h"

class SingletonIO {
public:
	
	static SingletonIO &getInstance() {
		static SingletonIO instance;
		return instance;
	}
	
	// Disable copy constructor and assignment operator
	SingletonIO(const SingletonIO &) = delete;
	
	SingletonIO &operator=(const SingletonIO &) = delete;
	
	AbstractInput *get_input() {
		return input;
	}
	
	void set_input(AbstractInput *inputIO) {
		input = inputIO;
	}
	
	RequestResponseCallback get_request_response_callback() {
		return request_response_callback;
	}
	
	void set_request_response_callback(RequestResponseCallback request_response_callbackIO) {
		request_response_callback = request_response_callbackIO;
	}


private:
	SingletonIO() {}
	
	~SingletonIO() {}
	
	AbstractInput *input;
	RequestResponseCallback request_response_callback;
};


#endif
