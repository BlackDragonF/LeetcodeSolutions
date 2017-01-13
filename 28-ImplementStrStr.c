int kmp (const char * s, const char * w) {
    int s_idx = 0;
    int w_idx = 0;
    int s_len = strlen(s);
    int w_len = strlen(w);
    int next[w_len];
    generate_next(w, next);
    while (s_idx < s_len && w_idx < w_len) {
        if (w_idx == -1 || s[s_idx] == w[w_idx]) {
            s_idx++;
            w_idx++;
        } else {
             w_idx = next[w_idx];
        }
    }
    if (w_idx == w_len) {
         return (s_idx - w_idx);
    } else {
         return -1;
    }
}

void generate_next(const char * w, int * next) {
     int index = 0, k = -1;
     int w_len = strlen(w);
     next[0] = -1;
     while (index < w_len -1) {
         if (k == -1 || w[index] == w[k]) {
             ++k;
             ++index;
             next[index] = k;
         } else {
             k = next[k];
         }
     }
}

int strStr(char* haystack, char* needle) {
    return kmp(haystack, needle);
}﻿
