#!/usr/bin/python3
path = input("file path:")

if path:
	f = open(path, "r")
	str = f.read()
	if str:
		print(str.replace("T", "U"))
