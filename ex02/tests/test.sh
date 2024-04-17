#!/bin/bash

# Colors
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
PINK='\033[0;35m'
BLUE='\033[0;34m'
RESET='\033[0m'

# Determine the script's directory
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Set the path to the executable
EXECUTABLE="$SCRIPT_DIR/../a.out"
MAKEFILE_LOCATION="$SCRIPT_DIR/.."

# Set valgrind
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"

# Set the paths to files
EXPECTED="$SCRIPT_DIR/expected.txt"
OUTPUT="$SCRIPT_DIR/output.txt"
VALGRIND_OUTPUT="$SCRIPT_DIR/valgrind_output.txt"

#Function to compare files and print the differences
function compare_files
{
	print_info "Comparing output with expected" "-"
	if diff "$1" "$2" >/dev/null; then
		echo -e "${GREEN}Success${RESET}"
	else
	{
		echo -e "${RED}Fail${RESET}"
		awk -v yellow="$YELLOW" -v green="$GREEN" -v red="$RED" -v reset="$RESET" '
			{
				if (FILENAME == ARGV[1]) {
					# Process the first file to store expected lines
					expected_lines[FNR] = $0
					length_file_1 = FNR
				} else {
					# Process the second file to compare expected and actual lines
					if (FNR <= length_file_1 && expected_lines[FNR] != $0) {
						print yellow "Difference at line", reset, FNR
						print green "Expected:", reset, expected_lines[FNR]
						print red "Actual  :", reset, $0
					} else if ((FNR == length_file_1 && expected_lines[FNR] != $0) || FNR > length_file_1) {
						# Print extra lines in the output
						print yellow "Difference at line", reset, FNR
						print green "Expected:", reset
						print red "Actual  :", reset, $0
					}
					length_file_2 = FNR  # Store the length of file 2
				}
			}
			END {
					if (length_file_2 < length_file_1) {
						#Print lines that are missing in the output
						for (i = length_file_2 + 1; i <= length_file_1; i++) {
							print yellow "Difference at line", reset, i
							print green "Expected:", reset, expected_lines[i]
							print red "Actual  :", reset
						}
				}
			}
			' "$1" "$2"
	}
	fi
	print_info "End of comparison" "-"
}

# Function to print number of characters (num, sign, color)
function print_signs
{
  local width="$1"
	local sign="$2"
	local color="$3"

	for ((i = 0; i < width; i++)); do
		echo -n -e "${color}$sign${RESET}"
	done
	echo
}

# Function to print info between a line of signs (text, sign)
function print_info
{
	print_signs "40" "$2" "$BLUE"
	echo -e "${YELLOW}$1${RESET}"
	print_signs "40" "$2" "$BLUE"
}

# Build the executable and check for relinking
print_info "make re" "-"
make re -C $MAKEFILE_LOCATION
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed${RESET}"
    exit 1
fi
print_info "make - relinking?" "-"
make -C $MAKEFILE_LOCATION
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed${RESET}"
    exit 1
fi


# Prompt the user if he wants to run Valgrind
echo -e -n "${PINK}Run Valgrind? [y/N]: ${RESET}"
read run_valgrind

# Run the test
if [ "$run_valgrind" = "y" ] || [ "$run_valgrind" = "Y" ]; then
    # With Valgrind
    print_info "Running test with Valgrind" "-"
    $VALGRIND "$EXECUTABLE" 1> "$OUTPUT" 2> "$VALGRIND_OUTPUT"
    cat "$OUTPUT"
    compare_files "$EXPECTED" "$OUTPUT"

    echo -e "\n${PINK}$VALGRIND${RESET}"
    cat "$VALGRIND_OUTPUT"
else
    # Without Valgrind
    print_info "Running test without Valgrind" "-"
    "$EXECUTABLE" > "$OUTPUT"
    cat "$OUTPUT"
    compare_files "$EXPECTED" "$OUTPUT"
fi

# Clean the output files
rm "$OUTPUT"
if [ "$run_valgrind" = "y" ] || [ "$run_valgrind" = "Y" ]; then
	rm "$VALGRIND_OUTPUT"
fi