cat words.txt | grep -v [gkmqvwxzio] | awk '{print length(), $0}' | sort -n | tail -n 10
