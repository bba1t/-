#!/bin/bash

echo '
diff <(grep int main.c) <(./s21_grep int main.c)'
echo '--------------------------------------------------------'
diff <(grep int main.c) <(./s21_grep int main.c)

echo '
diff <(grep int main.c grep_test2.txt) <(./s21_grep int main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep int main.c grep_test2.txt) <(./s21_grep int main.c grep_test2.txt)

echo '
diff <(grep -f grep_test2.txt main.c) <(./s21_grep -f grep_test2.txt main.c)'
echo '--------------------------------------------------------'
diff <(grep -f grep_test2.txt main.c) <(./s21_grep -f grep_test2.txt main.c)

echo '
diff <(grep -e pattern -fgrep_test2.txt main.c) <(./s21_grep -e pattern -fgrep_test2.txt main.c)'
echo '--------------------------------------------------------'
diff <(grep -e pattern -fgrep_test2.txt main.c) <(./s21_grep -e pattern -fgrep_test2.txt main.c)

echo '
diff <(grep -f grep_test.txt -f kek main.c) <(./s21_grep -f grep_test.txt -f kek main.c)'
echo '--------------------------------------------------------'
diff <(grep -f grep_test.txt -f kek main.c) <(./s21_grep -f grep_test.txt -f kek main.c)

echo '
diff <(grep -afs int main.c) <(./s21_grep -afs int main.c)'
echo '--------------------------------------------------------'
diff <(grep -afs int main.c) <(./s21_grep -afs int main.c)

echo '
diff <(grep -ak int main.c) <(./s21_grep -ak int main.c)'
echo '--------------------------------------------------------'
diff <(grep -ak int main.c) <(./s21_grep -ak int main.c)

echo '
diff <(grep -l main main.c grep_test2.txt) <(./s21_grep -l main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -l main main.c grep_test2.txt) <(./s21_grep -l main main.c grep_test2.txt)

echo '
diff <(grep -li MaIn main.c grep_test2.txt) <(./s21_grep -li MaIn main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -li MaIn main.c grep_test2.txt) <(./s21_grep -li MaIn main.c grep_test2.txt)


echo '
diff <(grep -n main main.c) <(./s21_grep -n main main.c)'
echo '--------------------------------------------------------'
diff <(grep -n main main.c) <(./s21_grep -n main main.c)

echo '
diff <(grep -n main main.c grep_test2.txt) <(./s21_grep -n main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -n main main.c grep_test2.txt) <(./s21_grep -n main main.c grep_test2.txt)

echo '
diff <(grep -ni Main main.c) <(./s21_grep -ni Main main.c)'
echo '--------------------------------------------------------'
diff <(grep -ni Main main.c) <(./s21_grep -ni Main main.c)

echo '
diff <(grep -ni Main main.c grep_test2.txt) <(./s21_grep -ni Main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -ni Main main.c grep_test2.txt) <(./s21_grep -ni Main main.c grep_test2.txt)


echo '
diff <(grep -lni Main main.c grep_test2.txt) <(./s21_grep -lni Main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -lni Main main.c grep_test2.txt) <(./s21_grep -lni Main main.c grep_test2.txt)

echo '
diff <(grep -o main main.c) <(./s21_grep -o main main.c)'
echo '--------------------------------------------------------'
diff <(grep -o main main.c) <(./s21_grep -o main main.c)

echo '
diff <(grep -no main main.c) <(./s21_grep -no main main.c)'
echo '--------------------------------------------------------'
diff <(grep -no main main.c) <(./s21_grep -no main main.c)

echo '
diff <(grep -o main main.c grep_test2.txt) <(./s21_grep -o main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -o main main.c grep_test2.txt) <(./s21_grep -o main main.c grep_test2.txt)

echo '
diff <(grep -oni maIn main.c) <(./s21_grep -oni maIn main.c)'
echo '--------------------------------------------------------'
diff <(grep -oni maIn main.c) <(./s21_grep -oni maIn main.c)

echo '
diff <(grep -oni maIn main.c grep_test2.txt) <(./s21_grep -oni maIn main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -oni maIn main.c grep_test2.txt) <(./s21_grep -oni maIn main.c grep_test2.txt)

echo '
diff <(grep -oni -e maIn main.c grep_test2.txt) <(./s21_grep -oni -e maIn main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -oni -e maIn main.c grep_test2.txt) <(./s21_grep -oni -e maIn main.c grep_test2.txt)

echo '
diff <(grep -lni -e maIn main.c grep_test2.txt) <(./s21_grep -lni -e maIn main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -lni -e maIn main.c grep_test2.txt) <(./s21_grep -lni -e maIn main.c grep_test2.txt)

echo '
diff <(grep -lni -f patterns.txt main.c grep_test2.txt) <(./s21_grep -lni -f patterns.txt main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -lni -f patterns.txt main.c grep_test2.txt) <(./s21_grep -lni -f patterns.txt main.c grep_test2.txt)

echo '
diff <(grep -ov main main.c) <(./s21_grep -ov main main.c)'
echo '--------------------------------------------------------'
diff <(grep -ov main main.c) <(./s21_grep -ov main main.c)

echo '
diff <(grep -lv main main.c) <(./s21_grep -lv main main.c)'
echo '--------------------------------------------------------'
diff <(grep -lv main main.c) <(./s21_grep -lv main main.c)

echo '
diff <(grep -v main grep_test2.txt) <(./s21_grep -v main grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -v main grep_test2.txt) <(./s21_grep -v main grep_test2.txt)

echo '
diff <(grep -v main main.c grep_test2.txt) <(./s21_grep -v main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -v main main.c grep_test2.txt) <(./s21_grep -v main main.c grep_test2.txt)

echo '
diff <(grep -ovi main main.c grep_test2.txt) <(./s21_grep -ovi main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -ovi main main.c grep_test2.txt) <(./s21_grep -ovi main main.c grep_test2.txt)

echo '
diff <(grep -lvi -e main main main.c grep_test2.txt) <(./s21_grep -lvi -e main main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -lvi -e main main main.c grep_test2.txt) <(./s21_grep -lvi -e main main main.c grep_test2.txt)

echo '
diff <(grep -lvi -f patterns.txt main main.c grep_test2.txt) <(./s21_grep -lvi -f patterns.txt main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -lvi -f patterns.txt main main.c grep_test2.txt) <(./s21_grep -lvi -f patterns.txt main main.c grep_test2.txt)

echo '
diff <(grep -lvi -f pattens.txt main main.c grep_test2.txt) <(./s21_grep -lvi -f pattens.txt main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -lvi -f pattens.txt main main.c grep_test2.txt) <(./s21_grep -lvi -f pattens.txt main main.c grep_test2.txt)

echo '
diff <(grep -lvis -f pattens.txt main main.c grep_test2.txt) <(./s21_grep -lvis -f pattens.txt main main.c grep_test2.txt)'
echo '--------------------------------------------------------'
diff <(grep -lvis -f pattens.txt main main.c grep_test2.txt) <(./s21_grep -lvis -f pattens.txt main main.c grep_test2.txt)

