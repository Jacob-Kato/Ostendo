set -e

TARGET_DIR = "/test"
FILE_NAME = "main_test.cpp"

cd "$TARGET_DIR"

g++ "$FILE_NAME.cpp" -o "$FILE_NAME"

./"FILE_NAME": rm ./"FILE_NAME"
