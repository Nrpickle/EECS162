/*****************
 * Buggy program #1
 ****************/
#include <iostream>
#include <string.h>

int main(int argc, char** argv){
	int i;
	char* str;
	char ch;
	bool found = false;

	if( argc != 3 ) {
		std::cout << "Usage: search <string> <character>" << std::endl;
		return(-1);
	}
	str = argv[1];
	ch = argv[2][0];

	for(i = 0; i < strlen(str); i++ ) {
		if( str[i] == ch ) {
			found = true;
		} else {
			//found = false;
		}
	}

	if( found ) {
		std::cout << ch << " found in " << str << std::endl;
	} else {
		std::cout << ch << " not found in " << str << std::endl;
	}
	return 0;
}




