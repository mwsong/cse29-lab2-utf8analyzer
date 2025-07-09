#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void valid_ascii(char str[]){
	bool valid = true;
	for(int i = 0; str[i] != 0; i++){
		if (str[i] >  127){
			valid = false;
		}
	}
	printf("Valid ASCII: %s\n", valid ? "true" : "false");
}

void codepoint_number(char str[]){
	int count = 0; 
	for(int i = 0; str[i] != 0; i++){
		if((str[i] & 0b11000000) != 0b10000000){
			count += 1;
		}
	}
	printf("Number of code points: %d\n", count);
}

int codepoint_size(char c){
	int bytes = 1;
	if ((c & 0b11100000) == 0b11000000){
                bytes = 2;
        } 
	else if ((c & 0b11110000) == 0b11100000){
                bytes = 3;
        }
	else if ((c & 0b11111000) == 0b11110000){
        	bytes = 4;
        }
	return bytes;
}

void substring(char str[]){
	char result[strlen(str) + 1];
	int count = 0;
	int src_index = 0;
	int dst_index = 0;

	while(count < 6 && str[src_index] != 0){
		char c = str[src_index];
		int bytes = codepoint_size(c);
		for(int i = 0; i < bytes; i++){
			result[dst_index++] = str[src_index++];
		}
		count++;
	}

	result[dst_index] = 0;
	printf("Substring of the first 6 code points: %s\n", result);

}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
	
    // implement the UTF-8 analyzer here
}
