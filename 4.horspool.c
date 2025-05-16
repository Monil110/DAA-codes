#include <stdio.h>
#include <string.h>
#include <sys/time.h>

const int MAX = 256;

void st(char p[], int t[]) {
    int m, i, j;
    m = strlen(p);
    for(i = 0; i < MAX; i++) t[i] = m;
    for(j = 0; j < m - 1; j++) {
        t[(unsigned char)p[j]] = m - 1 - j;
    }
}

int Hp(char s[], char p[], int t[]) {
    int i, n, m, k;
    n = strlen(s);
    m = strlen(p);
    i = m - 1;
    while(i < n) {
        k = 0;
        while((k < m) && (p[m - 1 - k] == s[i - k])) k++;
        if (k == m) return i - m + 1;
        else i = i + t[(unsigned char)s[i]];
    }
    return -1;
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

int main(void) {
    char text[MAX];
    char patt[MAX];
    int shift[MAX];
    int found;
    struct timeval start, end;

    puts("Enter the source string : ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = '\0';
    puts("Enter the pattern string : ");
    fgets(patt, MAX, stdin);
    patt[strcspn(patt, "\n")] = '\0';
    
    st(patt, shift);

    gettimeofday(&start, NULL);
    found = Hp(text, patt, shift);
    gettimeofday(&end, NULL);

    if(found == -1) 
        puts("\nMatching Substring not found.\n");
    else 
        printf("\nMatching Substring found at position: %d\n", found + 1);

    printf("Time taken for search: %.6f seconds\n", get_time_diff(start, end));

    return 0;
}