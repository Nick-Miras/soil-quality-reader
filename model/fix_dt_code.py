import re

file_path = 'saved/dt.C'

with open(file_path, 'r') as f:
    content = f.read()

# Pattern: memcpy(var0, (double[]){...}, 2 * sizeof(double));
# Replacement: { const double tmp[] = {...}; memcpy(var0, tmp, 2 * sizeof(double)); }

pattern = re.compile(r'memcpy\(var0, \(double\[\]\)\{(.*?)\}, 2 \* sizeof\(double\)\);')

def replacement(match):
    inner = match.group(1)
    return f'{{ const double tmp[] = {{{inner}}}; memcpy(var0, tmp, 2 * sizeof(double)); }}'

new_content = pattern.sub(replacement, content)

with open(file_path, 'w') as f:
    f.write(new_content)

print(f"Processed {file_path}")
