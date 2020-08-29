FILE_NAME=$1

echo building $FILE_NAME

cc -std=c99 -Wall -ledit $FILE_NAME.c -o out/$FILE_NAME

echo done building!