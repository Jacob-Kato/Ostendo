set -e

TARGET_DIR="/home/kato/Ostendo/test"
FILE_NAME="main_test"

cd "$TARGET_DIR"

g++ "$FILE_NAME.cpp" /home/kato/Ostendo/hailstone/hailstone.cpp -o "$FILE_NAME"

./"$FILE_NAME"
rm ./"$FILE_NAME"
