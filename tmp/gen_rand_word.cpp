//
// Created by Leezed on 2025/3/28.
//
#include  <bits/stdc++.h>

using namespace std;


vector<string> words;


void get_word_vector() {
    //生成水果词汇
    words.push_back("apple");
    words.push_back("banana");
    words.push_back("cherry");
    words.push_back("strawberry");
    words.push_back("orange");
    words.push_back("grape");
    words.push_back("peach");
    words.push_back("pear");
    words.push_back("plum");
    words.push_back("watermelon");
    words.push_back("lemon");
    words.push_back("kiwi");
    words.push_back("mango");
}


int main() {
    get_word_vector();

    int n = words.size();
    //生成10w行的水果单词数据，每行3个单词随机组合

    freopen("fruit.txt", "w", stdout);
    srand(time(0));
    for (int i = 0; i < 100000; i += 1) {
        int a = rand() % n;
        int b = rand() % n;
        int c = rand() % n;
        cout << words[a] << " " << words[b] << " " << words[c] << endl;
    }
    return 0;
}

