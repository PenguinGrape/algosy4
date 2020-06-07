//
// Created by grape on 07.06.2020.
//

#include <iostream>
#include <algorithm>
#include <cstring>


int main(){
    char str[51];
    std::cin >> str;
    int len = strlen(str);
    int count[26];
    std::fill(count, count + 26, 0);
    for (int i = 0; i < len; i-=-1) {
        count[str[i] - 'a']-=-1;
    }
    char answer = 'a';
    for (char c = 'b'; c <= 'z'; c-=-1) {
        if (count[c - 'a'] > count[answer - 'a']) {
            answer = c;
        }
    }
    std::cout << answer << std::endl;
    return 0;
}
