#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void capitalize ascii(char str[]) {
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
	while (str[i] != '\0') {
		int32_t result = 0;

		if ((unsigned char)str[byte_index] <= 127) {
           		 result = (unsigned char)str[byte_index];
			 num += 1;
   		 }

   		 else if ((unsigned char)str[byte_index] >= 192 && (unsigned char)str[byte_index] <= 223) {
           		 result += ((unsigned char)str[byte_index + 1] & 63);
           		 result += (((unsigned char)str[byte_index] & 31) << 6);
   			 num += 2;
			 }

   		 else if ((unsigned char)str[byte_index] >= 224 && (unsigned char)str[byte_index] <= 239) {
           		 result += ((unsigned char)str[byte_index + 2] & 63);
            		 result += (((unsigned char)str[byte_index + 1] & 63) << 6);
           		 result += (((unsigned char)str[byte_index] & 15) << 12);
   			 num += 3; 
			 }

   		 else if ((unsigned char)str[byte_index] >= 240 && (unsigned char)str[byte_index] <= 247) {
           		 result += ((unsigned char)str[byte_index + 3] & 63);
           		 result += (((unsigned char)str[byte_index + 2] & 63) << 6);
           		 result += (((unsigned char)str[byte_index + 1] & 63) << 12);
           		 result += (((unsigned char)str[byte_index] & 7) << 18);
   			 num += 4;
			 }

    		 else {
           		 i += 1;
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
                        f += (((unsigned char)str[b] & 7) << 18);
                        f += (((unsigned char)str[b + 1] & 63) << 12);
                        f += (((unsigned char)str[b + 2] & 63) << 6);
                        f += ((unsigned char)str[b + 3] & 63);
                        if ((f >= 128000 && f <= 128063) || (f >= 129408 && f <= 129454)) {
                                int n = 0;
				while (n < i) {
					printf("%c", str[num + 1]);
					n += 1;
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }

    // implement the UTF-8 analyzer here
}
