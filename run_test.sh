#!/bin/bash
set -e

PROJECT_ROOT="$PWD"
while [[ "$PROJECT_ROOT" != "/" && "$(basename "$PROJECT_ROOT")" != "Ostendo" ]]; do
  PROJECT_ROOT="$(dirname "$PROJECT_ROOT")"
done

if [[ "$(basename "$PROJECT_ROOT")" != "Ostendo" ]]; then
  PROJECT_ROOT="$(find "$HOME" -maxdepth 3 -type d -name "Ostendo" 2>/dev/null | head -n 1)"
fi

TARGET_DIR="$PROJECT_ROOT/test"
SOURCE_FILE="$PROJECT_ROOT/hailstone/hailstone.cpp"
FILE_NAME="${1:-main_test}"

cd "$TARGET_DIR"
g++ -O0 "${FILE_NAME}.cpp" "$SOURCE_FILE" -o "$FILE_NAME"

"./$FILE_NAME"
rm "$FILE_NAME"
