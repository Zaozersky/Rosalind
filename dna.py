#!/usr/bin/python3
def getCountACGT(strin):
	acgt = {"A": 0, "C": 0, "G": 0, "T": 0}

	for it in strin:
		acgt[it] += 1;

	return acgt


path = input("file path: ")

if path:
	f = open(path, "r")
	text = f.read()
	result = getCountACGT(text) 

	print(str(result["A"]) + " " + str(result["C"]) + " " + str(result["G"]) + " " + str(result["T"]))
