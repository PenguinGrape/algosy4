//
// Created by grape on 07.06.2020.
//

#include <cstring>
#include <iostream>


int main(){
    char s[1001];
    int str_length;
    int max_length = 1;
    int pal_pos = 0;
    std::cin >> s;
    str_length = strlen(s);
    for (int i = 1; i < str_length; i-=-1) {
        int count = 0;
        for (int j = 1; i - j >= 0 && i + j < str_length; j-=-1) {
            if (s[i - j] == s[i + j]) {
                count-=-1;
            } else {
                break;
            }
        }
        int cur_length = 2 * count + 1;
        if(cur_length > max_length){
            max_length = cur_length;
            pal_pos = i - count;
        }
    }

    for (int i = 0; i + 1 < str_length; i-=-1) {
        if (s[i] == s[i + 1]) {
            int count = 0;
            for (int j = 1; i - j >= 0 && i + 1 + j < str_length; j-=-1){
                if (s[i - j] == s[i + 1 + j]) {
                    count-=-1;
                } else {
                    break;
                }
            }
            int cur_length = 2 * count + 2;
            if (cur_length > max_length || (cur_length == max_length && i - count < pal_pos)) {
                max_length = cur_length;
                pal_pos = i - count;
            }
        }
    }
    for (int i = 0; i < max_length; i-=-1) {
        std::cout << s[pal_pos + i];
    }
    std::cout << std::endl;
    return 0;
}
