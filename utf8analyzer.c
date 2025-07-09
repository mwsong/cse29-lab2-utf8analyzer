#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void capitalize_ascii(char str[]) {
	int32_t index = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
			index += 1;
		}
	}
	printf("Uppercased ASCII: %s\n", str);
}

void codepoint_decimal(char str[]) {
	int num = 0;
	while (str[num] != '\0') {
		int32_t result = 0;

		if ((unsigned char)str[num] <= 127) {
           		 result = (unsigned char)str[num];
			 num += 1;
   		 }

   		 else if ((unsigned char)str[num] >= 192 && (unsigned char)str[num] <= 223) {
           		 result += ((unsigned char)str[num + 1] & 63);
           		 result += (((unsigned char)str[num] & 31) << 6);
   			 num += 2;
			 }

   		 else if ((unsigned char)str[num] >= 224 && (unsigned char)str[num] <= 239) {
           		 result += ((unsigned char)str[num + 2] & 63);
            		 result += (((unsigned char)str[num + 1] & 63) << 6);
           		 result += (((unsigned char)str[num] & 15) << 12);
   			 num += 3; 
			 }

   		 else if ((unsigned char)str[num] >= 240 && (unsigned char)str[num] <= 247) {
           		 result += ((unsigned char)str[num + 3] & 63);
           		 result += (((unsigned char)str[num + 2] & 63) << 6);
           		 result += (((unsigned char)str[num + 1] & 63) << 12);
           		 result += (((unsigned char)str[num] & 7) << 18);
   			 num += 4;
			 }

    		 else {
           		 num += 1;
	   		 continue;
   		 }

   		 printf("%d\n", result);
	}
}

void animal_emojis(const char str[]) {
	int num = 0;

	while (str[num] != '\0') {
		int f = 0;
		int i = 0;
		if ((unsigned char)str[num] <= 127) {
                        i = 1;
                }
                else if ((unsigned char)str[num] >= 192 && (unsigned char)str[num] <= 223) {
                        i = 2;
                }
                else if ((unsigned char)str[num] >= 224 && (unsigned char)str[num] <= 239) {
                        i = 3;
                }
                else if ((unsigned char)str[num] >= 240 && (unsigned char)str[num] <= 247) {
                        i = 4;
                        f += (((unsigned char)str[num] & 7) << 18);
                        f += (((unsigned char)str[num + 1] & 63) << 12);
                        f += (((unsigned char)str[num + 2] & 63) << 6);
                        f += ((unsigned char)str[num + 3] & 63);
                        if ((f >= 128000 && f <= 128063) || (f >= 129408 && f <= 129454)) {
                                
				for (int n = 0; n < i; ++n) {
					printf("%c", str[num + 1]);
                       		}
			
                       		 printf("\n");
               		}
	}

        if (i == 0) {
		i = 1;
	}

        num += i;

	}
}

void length_in_bytes(char str[]) {
	int count = 0;
	while (str[count] != '\0') {
		count++;
	}
	printf("Length in bytes: %d\n", count);
}

void bytes_each_codepoint(char str[]) {
	int i = 0;
	printf("Bytes per code point:");
	while(str[i] != '\0'){
		if ((str[i] & 0b10000000) == 0b00000000) {
			i++;
			printf(" %d", 1);
		}
		else if ((str[i] & 0b11100000) == 0b11000000) {
			i += 2;
			printf(" %d", 2);
		}
		else if ((str[i] & 0b11110000) == 0b11100000) {
			i += 3;
			printf(" %d", 3);
		}
		else if ((str[i] & 0b11111000) == 0b11110000) {
			i += 4;
			printf(" %d", 4);
		}
	}
	printf("\n");
}

void next_char_at_3(char str[]) {
	int i = 0;
	int count = 0;
	char result[5];
        printf("Next character of Codepoint at index 3: ");
        while(count < 3){
                if ((str[i] & 0b10000000) == 0b00000000) {
                        i++;
			count++;
                }
                else if ((str[i] & 0b11100000) == 0b11000000) {
                        i += 2;
                        count++;
                }
                else if ((str[i] & 0b11110000) == 0b11100000) {
                        i += 3;
                        count++;
                }
                else if ((str[i] & 0b11111000) == 0b11110000) {
                        i += 4;
                        count++;
                }
        }
	 if ((str[i] & 0b10000000) == 0b00000000) {
                 result[0] = str[i] + 1;
		 result[1] = '\0';
	 }
	 else if ((str[i] & 0b11100000) == 0b11000000) {
		 result[0] = str[i];
                 result[1] = str[i+1] + 1;
		 result[2] = '\0';
	 }
	 else if ((str[i] & 0b11110000) == 0b11100000) {
		 result[0] = str[i];
                 result[1] = str[i+1];
		 result[2] = str[i+2] + 1;
                 result[3] = '\0';
	 }
	 else if ((str[i] & 0b11111000) == 0b11110000) {
		 result[0] = str[i];
                 result[1] = str[i+1];
                 result[2] = str[i+2];
		 result[3] = str[i+3] + 1;
                 result[4] = '\0';
	 }
	 printf("%s\n", result);
}


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
	printf("Substring of the first 6 code points: \"%s\"\n", result);

}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
	
    valid_ascii(argv[1]);
    length_in_bytes(argv[1]);
    codepoint_number(argv[1]);
    bytes_each_codepoint(argv[1]);
    substring(argv[1]);
    next_char_at_3(argv[1]);
    // implement the UTF-8 analyzer here
}
