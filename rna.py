#!/usr/bin/python3
import os

path = input("file path:")

if os.path.exists(path):
	f = open(path, "r")
	str = f.read()
	if str:
		print(str.replace("T", "U"))
