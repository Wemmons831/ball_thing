import os
import re
import sys

def generate_header(src_dir, inc_dir, src_file):
    base_name = os.path.splitext(src_file)[0]
    header_file = os.path.join(inc_dir, f"{base_name}.h")
    src_file_path = os.path.join(src_dir, src_file)

    # Create the output directory if it doesn't exist
    os.makedirs(inc_dir, exist_ok=True)

    # Read the source file and extract function declarations
    with open(src_file_path, "r") as src:
        lines = src.readlines()

    # Regex to match function declarations
    func_regex = re.compile(r"^[a-zA-Z_][a-zA-Z0-9_]* [a-zA-Z_][a-zA-Z0-9_]*\(.*\)\s*\{")

    # Extract function declarations and remove the body
    declarations = [func_regex.match(line).group(0).rstrip("{").strip() + ";" for line in lines if func_regex.match(line)]

    # Write to the header file
    with open(header_file, "w") as header:
        header.write(f"#ifndef {base_name.upper()}_H\n")
        header.write(f"#define {base_name.upper()}_H\n\n")
        header.write("\n".join(declarations) + "\n\n")
        header.write(f"#endif // {base_name.upper()}_H\n")

    print(f"Generated: {header_file}")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python generate_header.py <src_dir> <inc_dir> <src_file>")
        sys.exit(1)

    src_dir, inc_dir, src_file = sys.argv[1], sys.argv[2], sys.argv[3]
    generate_header(src_dir, inc_dir, src_file)