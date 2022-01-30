#!/bin/python3
def read_file(path):
    text_file = open(path, "r")
    data = text_file.read()
    text_file.close()
    return (data)

sequences = {}
path="/home/alpha/42/push_swap/7_elems_combined.txt"
resolvings = read_file(path).split("--------------------------------\n");
for resolving in resolvings:
    resolving = resolving.split("\n")
    for len_seq in range(1, len(resolving)):
        for i in range(len(resolving) - len_seq):
            seq = str(resolving[i:i+len_seq])
            if seq in sequences:
                sequences[seq] += 1
            else:
                sequences[seq] = 1

for k, v in sorted( ((k,v) for v,k in sequences.items()), reverse=True):
    print(k, "=>", v)
