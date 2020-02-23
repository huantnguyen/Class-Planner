import json
#from flask import Flask, escape, request

with open("courses.json") as file:
    json_data = file.read()
data = json.loads(json_data)

for i in data[:]:
    print(i["courseNum"])