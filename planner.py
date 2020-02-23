import json

with open("courses.json") as file:
    json_data = file.read()
data = json.loads(json_data)

print(data[0]["major"])

print("hello world")