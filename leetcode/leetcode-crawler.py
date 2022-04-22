#!/bin/env python3
# note that burp proxy was in use when this was written
# you may need to change the cookies next time
# to refer to the problem page go to "https://leetcode.com/problems/{title}" where title is the name of the file
import requests
import time
import json


burp0_cookies = {"NEW_PROBLEMLIST_PAGE": "1", "c_a_u": "c2g0ZG93cjRuZ2Vy:1nHO8W:8Unye4DjCg8BoKstHoG9Vza1zmc", "csrftoken": "VxdMIZ7rn6av9A9w4vjTkRmOi9kE5WlDy7hqFns5ndfQXIzK4ljGHryALgYLLZZL", "messages": "\"d7a376f606696e810ceb6f4dcaa5cda0d2dece38$[[\\\"__json_message\\\"\\0540\\05425\\054\\\"Successfully signed in as sh4dowr4nger.\\\"]\\054[\\\"__json_message\\\"\\0540\\05425\\054\\\"Successfully signed in as sh4dowr4nger.\\\"]]\"", "LEETCODE_SESSION": "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjMzNTQ2NiIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjY4ODI2NmYyYzczNDIzZTcxYjZiNWM2NmM3ZGY2NmNjMjkyZDk4NjUiLCJpZCI6MjMzNTQ2NiwiZW1haWwiOiJkZXNhaWFkaXR5YWNjQGdtYWlsLmNvbSIsInVzZXJuYW1lIjoic2g0ZG93cjRuZ2VyIiwidXNlcl9zbHVnIjoic2g0ZG93cjRuZ2VyIiwiYXZhdGFyIjoiaHR0cHM6Ly9zMy11cy13ZXN0LTEuYW1hem9uYXdzLmNvbS9zMy1sYy11cGxvYWQvYXNzZXRzL2RlZmF1bHRfYXZhdGFyLmpwZyIsInJlZnJlc2hlZF9hdCI6MTY1MDYxODE4MCwiaXAiOiIyMTkuOTEuMTgxLjE3NiIsImlkZW50aXR5IjoiNmM0OTk0MWU4NTQ0NzNiODNkYjJkODQyMjgyNWRjNTEiLCJzZXNzaW9uX2lkIjoyMDc2NjAzOSwiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwfQ.67PV9h7_RzR-1axPq38l6PEGXoPjxmMpP2MpShaP1CA"}
burp0_headers = {"Accept": "*/*", "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36", "X-Requested-With": "XMLHttpRequest", "Sec-Gpc": "1", "Sec-Fetch-Site": "same-origin", "Sec-Fetch-Mode": "cors", "Sec-Fetch-Dest": "empty", "Referer": "https://leetcode.com/submissions/", "Accept-Encoding": "gzip, deflate", "Accept-Language": "en-GB,en-US;q=0.9,en;q=0.8"}

def write_to_file(title,lang,code):
    filename = title+"."+lang
    print(filename)
    f = open(filename,"w")
    f.write(code)
    f.close()

session = requests.session()
offset= 0
count = 0
check_map = {}
retry = 0
while True:
    burp0_url = "https://leetcode.com:443/api/submissions/?offset="+str(offset)+"&limit=20&lastkey="
    r=session.get(burp0_url, headers=burp0_headers, cookies=burp0_cookies,verify=False)
    data=json.loads(r.text)
    if 'submissions_dump' not in data.keys():
        if retry >= 5:
            break
        else:
            print("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ retry = " + str(retry))
            retry +=1
            time.sleep(5)
            continue

    for datael in data['submissions_dump']:
        if datael['status_display'] == 'Accepted':
            title = datael['title'].lower().replace(" ","-").replace(")","").replace("(","")
            if title not in check_map.keys():
                check_map[title]=1
                count += 1
                code=datael['code']
                lang=datael['lang']
                write_to_file(title,lang,code)
            #print(datael.keys())
    offset+=20
    time.sleep(1)
f = open("problems-accepted.list","w")
f.write(str(count)+"\n")
for key in check_map.keys():
    f.write(key+"\n")
f.close()    
#print(check_map)
print(count)
print(offset)
