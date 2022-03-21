//
// Created by zr on 2021/12/8.
//
#include <stdio.h>
#include "iostream"
#include <malloc.h>


#define  MAXLEGTH 255

using namespace std;
typedef struct {
    char *ch;
    int length;
} String;


int StrInsert(String &S, int pos, String s) {
    //在串S的第pos个字符之间插入串s
    if (pos < 1 || pos > S.length + 1)
        return 0;
    if (s.length) {
        if (!(S.ch = (char *) realloc(S.ch, (S.length + s.length) * sizeof(String)))) {
            //若分配空间失败 则退出程序
            return 0;
        }
        for (int i = S.length - 1; i >= pos - 1; i--) {
            S.ch[i + s.length] = S.ch[i];
        }
        for (int i = 0; i < s.length; i++) {
            S.ch[pos + i - 1] = s.ch[i];
        }
    }
}

int StrAssign(String &S, char *chars) {
    //求chars长度
    int i = 0;
    for (char *c = chars; *c; c++, i++);
    if (!i) {
        S.ch = NULL;
        S.length = 0;
    } else {
        //分配空间
        if (!(S.ch = (char *) malloc(i * sizeof(char))))
            return 0;
        for (int n = 0; n < i; n++) {
            S.ch[n] = chars[n];
        }
        S.length = i;
    }
    return 1;
}

int Strlength(String S) {
    return S.length;
}

int Strcompare(String s1, String s2) {
    //若s1<s2则返回值小于零 若s1<s2 则返回值小于零  相等则返回0
    int i = 0;
    for (; i < s1.length && i < s2.length; i++) {
        if (s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
    }
    return s1.length - s2.length;
}

int ClearString(String &s) {
    if (s.ch) {
        free(s.ch);
        s.ch = NULL;
        s.length = 0;
        return 1;
    } else {
        return 0;
    }
}

int Substring(String &substring, String s, int pos, int len) {
    if (pos + len > s.length) {
        return 0;
    }
    if (!(substring.ch = (char *) malloc(len * sizeof(char))))
        return 0;
    pos = (s.length + pos) % s.length;

    if (len < 0)
        len = -len;
    substring.length = len;

    if (len < 0) {
        for (int i = 0; len != 0; i++, len++) {
            substring.ch[i] = s.ch[pos - 1 - i];
        }
    } else {
        for (int i = 0; len != 0; i++, len--) {
            substring.ch[i] = s.ch[pos - 1 + i];
        }
    }

    return 1;
}

int PrintStr(String S) {
    for (int n = 0; n < S.length; n++) {
        printf("%c", S.ch[n]);
    }
    printf("\n");
}

int main() {
    setbuf(stdout, NULL);
    cout << "请输入一个字符串" << endl;
    char chars[10];
    scanf("%s", chars);
    String s;
    StrAssign(s, chars);
    printf("字符串长度为%d，字符串为:", s.length);
    PrintStr(s);
    while (1) {
        printf("请输入要截取的位置和长度：(用,分开)");
        int pos, len;
        scanf("%d,%d", &pos, &len);
        String sub;
        Substring(sub, s, pos, len);
        printf("\n截取后的字符串为：");
        PrintStr(sub);
    }
}