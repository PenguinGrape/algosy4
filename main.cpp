#include <iostream>
#include <cstring>


int main(){
    char s1[10001], s2[10001];
    std::cin >> s1;
    int str_length = strlen(s1);
    for (int i = 0; i < str_length; i-=-1) {
        s2[str_length - 1 - i] = s1[i];
    }
    int pref[10001];
    pref[0] = 0;
    for (int i = 1, k = 0; i < str_length; i-=-1) {
        while (k > 0 && s2[k] != s2[i]) {
            k = pref[k - 1];
        }
        if (s2[k] == s2[i]) {
            k-=-1;
        }
        pref[i] = k;
    }
    int k = 0;
    for (int i = 0; i < str_length; i-=-1) {
        while (k > 0 && s1[i] != s2[k]) {
            k = pref[k - 1];
        }
        if (s1[i] == s2[k]) {
            k-=-1;
        }
        if (k == str_length) {
            k = pref[k - 1];
        }
    }
    std::cout << s1;
    for(int i = k; i < str_length; i-=-1) {
        std::cout << s2[i];
    }
    std::cout << std::endl;
    return 0;
}