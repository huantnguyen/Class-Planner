import json
import re
from flask import Flask, escape, request, jsonify
from flask_cors import CORS

# parse json
with open("courses.json") as file:
    json_data = file.read()
data = json.loads(json_data)

# class categories
# lowerdiv = []
# upperdiv = []
major = []
ge = []

# list of classes taken
class_taken = []
# TODO: add list of taken classes into list
dup_classes = { "STATS 10", "STATS 12", "STATS 13", "ECON 41", "PSYCH 100A"}

# list of major requirements
major_reqs = { "STATS 10", "STATS 12", "STATS 13", "STATS 20", "ECON 41", "PSYCH 100A", "MATH 31A", "MATH 31B",
    "MATH 32A", "MATH 32B", "MATH 33A", "STATS 100A", "STATS 100B", "STATS 100C", "STATS 101A", "STATS 101B",
    "STATS 101C",  "STATS 102A", "STATS 102B", "STATS 102C", "STATS 140SL", "STATS 141SL" }
# list of non GE majors
# other_majors = { "COM SCI", "STATS", "MATH" }

isMajor = False

for i in data[:]:
        for j in major_reqs:
            if j == i["courseNum"][0:len(i["courseNum"])-2]:
                isMajor = True
        if isMajor:
            major.append(i)
        else:
            if i["courseNum"].split('-')[0] not in ge:
                ge.append(i["courseNum"].split('-')[0])
        isMajor = False

app = Flask(__name__)
CORS(app)

@app.route('/')
def hello_world():
    print(request.args.get("name"))
    return '1'

@app.route('/taken')
def course_taken():
    dup_taken = False
    class_taken.append(request.args.get("course_taken"))
    for i in class_taken:
        if i in dup_classes:
            dup_taken = True

    class_to_be_taken = []
    for i in major_reqs:
        if i not in class_taken:
            if i in dup_classes:
                if dup_taken:
                    continue
                else:
                    class_to_be_taken.append(i)
            else:
                class_to_be_taken.append(i)
    return jsonify({"data": class_to_be_taken})

@app.route('/schedule')
def recommend_schedule():
    schedule = [["" for x in range(4)] for y in range(12)]
    dup_taken = False
    for i in class_taken:
        if i in dup_classes:
            dup_taken = True

    class_to_be_taken = []
    for i in major_reqs:
        if i not in class_taken:
            if i in dup_classes:
                if dup_taken:
                    continue
                else:
                    class_to_be_taken.append(i)
            else:
                class_to_be_taken.append(i)

#    yr = 17
    class_to_be_taken.sort()
    majorDone = False
    count = 0
    for i in range(12):
        if not majorDone:
            for j in range(3):
                if count < len(class_to_be_taken):
                    schedule[i][j] = class_to_be_taken[count]
                    count += 1
                else:
                    majorDone = True
                    count = 0
                    break
        else:
            for j in range(3):
                if count < 10:
                    schedule[i][j] = ge[count]
                    count += 1
                else:
                    break
    return jsonify({"data": schedule})


# implement if possible
'''
        remainder = i % 3
        if remainder == 0:
            szn = 'F'
        elif remainder == 1:
            szn = 'W'
        else:
            szn = 'S'
        quarter = str(yr) + szn
        for j in lowerdiv:
            course_title = j["courseNum"]
            course_title = course_title.split('-')[0]
'''

    
    



'''
print("LOWERDIVS")
for i in lowerdiv:
    print(i)
print("UPPERDIVS")
for i in upperdiv:
    print(i)

print("GES")
for i in ge:
    print(i)
'''

if __name__ == '__main__':
    app.run(debug=True)